//
// Created by vastrakai on 6/28/2024.
//

#include "TestModule.hpp"

#include <Features/Events/BaseTickEvent.hpp>
#include <Features/Events/LookInputEvent.hpp>
#include <Features/Events/PacketInEvent.hpp>
#include <Features/Events/PacketOutEvent.hpp>
#include <Features/Events/RenderEvent.hpp>
#include <Hook/Hooks/RenderHooks/D3DHook.hpp>
#include <SDK/Minecraft/Actor/Actor.hpp>
#include <SDK/Minecraft/Actor/Components/ActorOwnerComponent.hpp>
#include <SDK/Minecraft/Actor/Components/ComponentHashes.hpp>
#include <SDK/Minecraft/Actor/Components/ItemUseSlowdownModifierComponent.hpp>
#include <SDK/Minecraft/Actor/GameMode.hpp>
#include <SDK/Minecraft/Actor/SyncedPlayerMovementSettings.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Inventory/PlayerInventory.hpp>
#include <SDK/Minecraft/KeyboardRemappingLayout.hpp>
#include <SDK/Minecraft/Network/LoopbackPacketSender.hpp>
#include <SDK/Minecraft/Network/MinecraftPackets.hpp>
#include <SDK/Minecraft/Network/Packets/ItemStackRequestPacket.hpp>
#include <SDK/Minecraft/Network/Packets/ModalFormResponsePacket.hpp>
#include <SDK/Minecraft/Network/Packets/MovePlayerPacket.hpp>
#include <SDK/Minecraft/Network/Packets/Packet.hpp>
#include <SDK/Minecraft/Network/Packets/PlayerAuthInputPacket.hpp>
#include <SDK/Minecraft/Options.hpp>
#include <SDK/Minecraft/Rendering/LevelRenderer.hpp>
#include <SDK/Minecraft/World/Block.hpp>
#include <SDK/Minecraft/World/BlockLegacy.hpp>
#include <SDK/Minecraft/World/BlockSource.hpp>
#include <SDK/Minecraft/World/Chunk/LevelChunk.hpp>
#include <SDK/Minecraft/World/Chunk/SubChunkBlockStorage.hpp>
#include <SDK/Minecraft/World/HitResult.hpp>
#include <SDK/Minecraft/World/Level.hpp>
#include <Utils/FileUtils.hpp>
#include <Utils/FontHelper.hpp>
#include <Utils/GameUtils/ItemUtils.hpp>
#include <Utils/MiscUtils/BlockUtils.hpp>
#include <Utils/MiscUtils/ImRenderUtils.hpp>

void TestModule::onEnable()
{
	gFeatureManager->mDispatcher->listen<BaseTickEvent, &TestModule::onBaseTickEvent>(this);
	gFeatureManager->mDispatcher->listen<RenderEvent, &TestModule::onRenderEvent>(this);
	gFeatureManager->mDispatcher->listen<PacketInEvent, &TestModule::onPacketInEvent>(this);
	gFeatureManager->mDispatcher->listen<PacketOutEvent, &TestModule::onPacketOutEvent, nes::event_priority::VERY_LAST>(this);
	gFeatureManager->mDispatcher->listen<LookInputEvent, &TestModule::onLookInputEvent>(this);

	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player) return;


	if (mMode.mValue == Mode::DebugCameraTest)
	{
		for (auto&& [id, cameraComponent] : player->mContext.mRegistry->view<CameraComponent>().each())
		{
			player->mContext.mRegistry->set_flag<PlayerStateAffectsRenderingComponent>(id, false);

			auto* camera = player->mContext.mRegistry->try_get<DebugCameraComponent>(id);
			if (!camera)
			{
				continue;
			}

			/*player->mContext.mRegistry->set_flag<RenderCameraComponent>(id, true);
			player->mContext.mRegistry->set_flag<CameraAlignWithTargetForwardComponent>(id, true);

			spdlog::info("CameraComponent: {:X}, DebugCameraComponent: {:X}", reinterpret_cast<uintptr_t>(&cameraComponent), reinterpret_cast<uintptr_t>(camera));
			spdlog::info("Identified DebugCamera as id {}", id);*/
		}
	}

}

void TestModule::onDisable()
{
	gFeatureManager->mDispatcher->deafen<BaseTickEvent, &TestModule::onBaseTickEvent>(this);
	gFeatureManager->mDispatcher->deafen<RenderEvent, &TestModule::onRenderEvent>(this);
	gFeatureManager->mDispatcher->deafen<PacketInEvent, &TestModule::onPacketInEvent>(this);
	gFeatureManager->mDispatcher->deafen<PacketOutEvent, &TestModule::onPacketOutEvent>(this);
	gFeatureManager->mDispatcher->deafen<LookInputEvent, &TestModule::onLookInputEvent>(this);

	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player) return;

	if (mMode.mValue == Mode::DebugCameraTest)
	{
		for (auto&& [id, cameraComponent] : player->mContext.mRegistry->view<CameraComponent>().each())
		{
			auto* camera = player->mContext.mRegistry->try_get<DebugCameraComponent>(id);
			if (!camera)
			{
				// if (player->mContext.mRegistry->has_flag<ActiveCameraComponent>(id))
				//     player->mContext.mRegistry->set_flag<CurrentInputCameraComponent>(id, true);
				continue;
			}

			/*player->mContext.mRegistry->set_flag<CurrentInputCameraComponent>(id, false);
			player->mContext.mRegistry->set_flag<RenderCameraComponent>(id, false);*/
		}
	}
}


Block* gDaBlock = nullptr;

int lastFormId = 0;
bool formOpen = false;
AABB lastBlockAABB = AABB();
ItemStack conStack = ItemStack();


void TestModule::onBaseTickEvent(BaseTickEvent& event)
{
	return;
	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player) return;
	glm::vec2 fov = ClientInstance::get()->getFov();



	if (mMode.mValue == Mode::DebugCameraTest)
	{
		player->setFlag<MobIsJumpingFlagComponent>(false);
	}

	if (mMode.mValue == Mode::Regen) {
		static bool wasRotating = false;
		if (player->isDestroying()) {
			if (mProgress.mValue <= player->getGameMode()->mBreakProgress) {
				mRotatePos = player->getLevel()->getHitResult()->mBlockPos;
				mShouldRotate = true;
				wasRotating = true;
			}
		}
		if (wasRotating && !mShouldRotate) {
			mShouldRotate = true;
			wasRotating = false;
		}
	}

	ItemStack* stack = player->getSupplies()->getContainer()->getItem(0);
	auto networkDescriptor = NetworkItemStackDescriptor(*stack);
	spdlog::info("constructed NetworkItemStackDescriptor");
	//conStack = ItemStack::fromDescriptor(networkDescriptor);
	spdlog::info("constructed ItemStack from NetworkItemStackDescriptor");

	gDaBlock = ClientInstance::get()->getBlockSource()->getBlock(*player->getPos());

	if (mMode.mValue != Mode::PathTest) return;

	if (NOW - mLastLagback < 3000)
	{
		return;
	}

	float blocksPerTeleport = 5.f;

	auto actors = ActorUtils::getActorList(false, true);
	static std::unordered_map<Actor*, int64_t> lastAttacks = {};

	std::ranges::sort(actors, [&](Actor* a, Actor* b) -> bool
		{
			return a->distanceTo(player) < b->distanceTo(player);
		});

	Actor* target = nullptr;
	for (auto actor : actors)
	{
		if (actor == player) continue;
		if (!actor) continue;
		if (!actor->isValid()) continue;
		if (!actor->isPlayer()) continue;

		target = actor;
		break;
	}

	if (!target) return;

	float distance = player->distanceTo(target);





	/*glm::vec3 currentPos = from;

	std::vector<std::shared_ptr<MovePlayerPacket>> packetsToSend;

	for (int i = 0; i < packets; i++)
	{
		glm::vec3 step = to - from;
		step = glm::normalize(step) * blocksPerPacket;
		currentPos += step;

		auto packet = MinecraftPackets::createPacket<MovePlayerPacket>();
		packet->mPos = currentPos;
		packet->mPlayerID = player->getRuntimeID();
		packet->mRot = { mRots.x, mRots.y };
		packet->mYHeadRot = mRots.z;
		packet->mResetPosition = PositionMode::Teleport;
		packet->mOnGround = true;
		packet->mRidingID = -1;
		packet->mCause = TeleportationCause::Unknown;
		packet->mSourceEntityType = ActorType::Player;
		packet->mTick = 0;

		packetsToSend.push_back(packet);
	}*/

	// get the next step and setPosition to it
	glm::vec3 from = *player->getPos();
	glm::vec3 to = *target->getPos();
	glm::vec2 targetRots = { target->getActorRotationComponent()->mPitch, target->getActorRotationComponent()->mYaw };
	glm::vec3 offset = { 0.f, 0.f, -3.f }; // X blocks behind the target's head

	float blocksPerPacket = 5.f;

	glm::vec3 step = to - from;
	step = glm::normalize(step) * blocksPerPacket;
	from += step;

	player->setPosition(from);
}

void TestModule::onPacketOutEvent(PacketOutEvent& event)
{

	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player)
		return;
	if (mMode.mValue == Mode::Regen) {
		if (event.mPacket->getId() == PacketID::PlayerAuthInput) {
			auto packet = event.getPacket<PlayerAuthInputPacket>();
			packet->mPos.y = -256;
			this->setEnabled(false);
			return;
		}
	}

	if (event.mPacket->getId() == PacketID::InventoryTransaction)
	{
		if (const auto it = event.getPacket<InventoryTransactionPacket>(); it->mTransaction->type ==
			ComplexInventoryTransaction::Type::ItemUseTransaction)
		{
			const auto transac = reinterpret_cast<ItemUseInventoryTransaction*>(it->mTransaction.get());
			if (transac->mActionType == ItemUseInventoryTransaction::ActionType::Place)
			{
				auto block = ClientInstance::get()->getBlockSource()->getBlock(transac->mBlockPos);
				//ChatUtils::displayClientMessage("BlockName:" + block->mLegacy->mTileName);
				ChatUtils::displayClientMessage("IsSolid:" + std::to_string(block->mLegacy->mMaterial.mIsSolid));
			}
		}
	}
}

void TestModule::onPacketInEvent(PacketInEvent& event)
{
	return;

	if (mMode.mValue == Mode::PathTest && event.mPacket->getId() == PacketID::MovePlayer)
	{
		auto player = ClientInstance::get()->getLocalPlayer();
		if (!player) return;

		auto mpp = event.getPacket<MovePlayerPacket>();
		if (mpp->mPlayerID == player->getRuntimeID())
		{
			mLastLagback = NOW;
			ChatUtils::displayClientMessage("waiting for 3s for lagback");
		}
	}
}

void displayCopyableAddress(const std::string& name, void* address)
{
	std::string addressHex = "0x" + fmt::format("{:X}", reinterpret_cast<uintptr_t>(address));
	ImGui::Text(addressHex.c_str());
	ImGui::SameLine();
	if (ImGui::Button(("Copy " + name + " address").c_str()))
	{
		ImGui::SetClipboardText(addressHex.c_str());
	}


}

void TestModule::onLookInputEvent(LookInputEvent& event)
{

	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player) return;

	if (mMode.mValue == Mode::DebugCameraTest)
	{
		for (auto&& [id, cameraComponent] : player->mContext.mRegistry->view<CameraComponent>().each())
		{
			player->mContext.mRegistry->set_flag<PlayerStateAffectsRenderingComponent>(id, false);
			player->mContext.mRegistry->set_flag<AllowInsideBlockRenderComponent>(id, false);
		};

		/*CameraComponent* cameraDebug = nullptr;
		DebugCameraComponent* debugCameraComponent = nullptr;

		for (auto&& [id, cameraComponent] : player->mContext.mRegistry->view<CameraComponent>().each())
		{
			auto* camera = player->mContext.mRegistry->try_get<DebugCameraComponent>(id);
			if (!camera)
			{
				continue;
			}

			cameraDebug = &cameraComponent;
			debugCameraComponent = camera;
		}

		if (!cameraDebug || !debugCameraComponent) return;

		CameraComponen`t* firstPersonCamera = event.mFirstPersonCamera;
		CameraDirectLookComponent* firstPersonLook = event.mCameraDirectLookComponent;*/
	}
}

enum class Tab
{
	ClickGui,
	HudEditor,
	Scripting
};

void TestModule::onRenderEvent(RenderEvent& event)
{


	auto player = ClientInstance::get()->getLocalPlayer();
	if (!player)
	{
		gDaBlock = nullptr;
		return;
	}
#ifdef __DEBUG__
	if (!mShowDebugUi.mValue) return;

	FontHelper::pushPrefFont(false, false);

	ImGui::Begin("TestModule");
	ImGui::Text("TestModule");

	if (ClientInstance* ci = ClientInstance::get())
	{
		ImGui::Text("ScreenName: %s", ci->getScreenName().c_str());

		if (ImGui::CollapsingHeader("ClientInstance"))
		{
			displayCopyableAddress("ClientInstance", ci);
			if (auto options = ci->getOptions())
			{
				displayCopyableAddress("Options", options);
				displayCopyableAddress("GfxGamma", options->mGfxGamma);
			}
			if (ci->getLevelRenderer() && ImGui::CollapsingHeader("LevelRenderer"))
			{
				displayCopyableAddress("LevelRenderer", ci->getLevelRenderer());
				displayCopyableAddress("LevelRendererPlayer", ci->getLevelRenderer()->getRendererPlayer());
			}

			displayCopyableAddress("MinecraftGame", ci->getMinecraftGame());
			displayCopyableAddress("MinecraftSimulation", ci->getMinecraftSim());
			displayCopyableAddress("PacketSender", ci->getPacketSender());
		}

		if (auto blockSource = ci->getBlockSource(); blockSource && ImGui::CollapsingHeader("BlockSource"))
		{
			displayCopyableAddress("BlockSource", blockSource);
		}

		if (player)
		{
			if (ImGui::CollapsingHeader("Player"))
			{
				ImGui::Text("isOnGround: %d", player->getFlag<OnGroundFlagComponent>());
				ImGui::Text("wasOnGround: %d", player->getFlag<WasOnGroundFlagComponent>());
				ImGui::Text("isDead: %d", player->getFlag<IsDeadFlagComponent>());
				ImGui::Text("renderCameraFlag: %d", player->getFlag<RenderCameraComponent>());
				ImGui::Text("gameCameraFlag: %d", player->getFlag<GameCameraComponent>());
				ImGui::Text("cameraRenderPlayerModel: %d", player->getFlag<CameraRenderPlayerModelComponent>());
				ImGui::Text("isOnFire: %d", player->getFlag<OnFireComponent>());
				ImGui::Text("moveRequestComponent: %d", player->getFlag<MoveRequestComponent>());
				ImGui::Text("gameType: %d", player->getGameType());
				displayCopyableAddress("LocalPlayer", player);


				if (auto supplies = player->getSupplies())
				{
					displayCopyableAddress("PlayerInventory", supplies);
					displayCopyableAddress("GameMode", player->getGameMode());
					displayCopyableAddress("Level", player->getLevel());
				}

				auto lpid = player->mContext.mEntityId;

				if (ImGui::CollapsingHeader("All EntityId Components"))
				{
					// Filter text box
					static char filter[128] = "";
					ImGui::InputText("Filter", filter, IM_ARRAYSIZE(filter));

					bool doFilter = strlen(filter) > 0;
					bool filterByAddress = false;
					void* filterAddress = nullptr;
					// parse the filter text
					if (doFilter)
					{
						if (filter[0] == '0' && filter[1] == 'x')
						{
							try
							{
								filterByAddress = true;
								filterAddress = reinterpret_cast<void*>(std::stoull(filter, nullptr, 16));
							}
							catch (std::exception& e)
							{
								filterByAddress = false;
								memset(filter, 0, IM_ARRAYSIZE(filter));
							}
						}
					}

					static bool showTypeHashes = false;
					ImGui::Checkbox("Show TypeHashes", &showTypeHashes);

					std::unordered_map<EntityId, std::map<std::uint32_t, void*>> unsortedMap = player->mContext.mRegistry->get_all_entity_components();

					std::erase_if(unsortedMap, [&](const auto& kv) {
						const EntityId ent = kv.first;
						return ent != lpid && player->mContext.mRegistry->has_flag<ActorOwnerComponent>(ent);
						});

					std::unordered_map<EntityId, std::map<std::uint32_t, void*>> flagMap = {};

					// For each entity in unsortedMap, if they have a 0x0 address component in their map, add it to the flagMap and remove it from the unsortedMap
					for (auto& [ent, typehashes] : unsortedMap)
					{
						if (typehashes.empty()) continue;

						std::map<std::uint32_t, void*> flagComponents = {};
						for (auto& [typehash, address] : typehashes)
						{
							if (address == nullptr)
							{
								flagComponents[typehash] = nullptr;
							}
						}

						if (!flagComponents.empty())
						{
							flagMap[ent] = flagComponents;
							for (auto& [typehash, address] : flagComponents)
							{
								typehashes.erase(typehash);
							}
						}
					}

					auto local = player->mContext.mEntityId;

					static std::map<EntityId, std::set<std::uint32_t>> entityComponentMap = {};
					static std::map<EntityId, std::set<std::uint32_t>> entityFlagMap = {};

					for (auto& [ent, typehashes] : flagMap)
					{
						if (typehashes.empty()) continue;

						std::string id = "-- Flags for EntityId: " + std::to_string(static_cast<uint32_t>(ent)) + (ent == local ? " (LocalPlayer)" : "");
						if (doFilter) ImGui::Text(id.c_str());
						if (!doFilter && ImGui::CollapsingHeader(id.c_str()) || doFilter)
						{
							auto componentSet = std::set<std::uint32_t>();

							for (auto& [typehash, address] : typehashes)
							{
								componentSet.insert(typehash);
								std::string name = "Unknown";
								if (Component::hashes.contains(typehash))
								{
									name = Component::hashes[typehash];
								}
								if (doFilter && !filterByAddress && !StringUtils::containsIgnoreCase(name, filter)) continue;
								if (filterByAddress && address != filterAddress) continue;
								/*ImGui::Text("TypeHash: %s, Name: %s, State: TRUE",
									fmt::format("0x{:X}", typehash).c_str(), name.c_str());*/
								if (showTypeHashes)
									ImGui::Text("TypeHash: %s, Name: %s, State: TRUE", fmt::format("0x{:X}", typehash).c_str(), name.c_str());
								else
									ImGui::Text("Name: %s, State: TRUE", name.c_str());
							}

							for (auto& typehash : entityFlagMap[ent])
							{
								std::string name = Component::hashes.contains(typehash) ? Component::hashes[typehash] : "Unknown";
								if (doFilter && !StringUtils::containsIgnoreCase(name, filter)) continue;
								if (!componentSet.contains(typehash))
								{
									if (showTypeHashes)
										ImGui::Text("TypeHash: %s, Name: %s, State: FALSE", fmt::format("0x{:X}", typehash).c_str(), name.c_str());
									else
										ImGui::Text("Name: %s, State: FALSE", name.c_str());
								}
							}

							for (auto& [typehash, address] : typehashes)
							{
								entityFlagMap[ent].insert(typehash);
							}
						}
					}

					for (auto& [ent, typehashes] : unsortedMap)
					{
						if (typehashes.empty()) continue;

						std::string id = "-- Components for EntityId: " + std::to_string(static_cast<uint32_t>(ent)) + (ent == local ? " (LocalPlayer)" : "");
						if (doFilter) ImGui::Text(id.c_str());
						if (!doFilter && ImGui::CollapsingHeader(id.c_str()) || doFilter)
						{
							auto componentSet = std::set<std::uint32_t>();

							for (auto& [typehash, address] : typehashes)
							{
								componentSet.insert(typehash);
								std::string name = "Unknown";
								if (Component::hashes.contains(typehash))
								{
									name = Component::hashes[typehash];
								}
								if (doFilter && !filterByAddress && !StringUtils::containsIgnoreCase(name, filter)) continue;
								if (filterByAddress && address != filterAddress) continue;
								if (showTypeHashes)
									ImGui::Text("TypeHash: %s, Name: %s, Address: %s",
										fmt::format("0x{:X}", typehash).c_str(), name.c_str(), fmt::format("0x{:X}", reinterpret_cast<uintptr_t>(address)).c_str());
								else
									ImGui::Text("Name: %s, Address: %s", name.c_str(), fmt::format("0x{:X}", reinterpret_cast<uintptr_t>(address)).c_str());
								ImGui::SameLine();
								std::string buttonText = "Copy##" + std::to_string(typehash) + std::to_string(reinterpret_cast<uintptr_t>(address));
								if (ImGui::Button(buttonText.c_str()))
								{
									ImGui::SetClipboardText(fmt::format("0x{:X}", reinterpret_cast<uintptr_t>(address)).c_str());
								}
							}

							for (auto& typehash : entityComponentMap[ent])
							{
								std::string name = Component::hashes.contains(typehash) ? Component::hashes[typehash] : "Unknown";
								if (doFilter && !filterByAddress && !StringUtils::containsIgnoreCase(name, filter)) continue;
								if (filterByAddress) continue;
								if (!componentSet.contains(typehash))
								{
									if (showTypeHashes)
										ImGui::Text("TypeHash: %s, Name: %s, Address: %s",
											fmt::format("0x{:X}", typehash).c_str(), name.c_str(), "NULL");
									else
										ImGui::Text("Name: %s, Address: %s", name.c_str(), "NULL");
								}
							}

							for (auto& [typehash, address] : typehashes)
							{
								entityComponentMap[ent].insert(typehash);
							}
						}
					}
				}
			}

			if (ImGui::CollapsingHeader("Movement Settings"))
			{
				if (auto keyMouseSettings = ci->getKeyboardSettings())
				{
					int forward = (*keyMouseSettings)["key.forward"];
					int back = (*keyMouseSettings)["key.back"];
					int left = (*keyMouseSettings)["key.left"];
					int right = (*keyMouseSettings)["key.right"];

					bool isForward = Keyboard::mPressedKeys[forward];
					bool isBack = Keyboard::mPressedKeys[back];
					bool isLeft = Keyboard::mPressedKeys[left];
					bool isRight = Keyboard::mPressedKeys[right];

					ImGui::Text("Forward: %s", isForward ? "true" : "false");
					ImGui::Text("Back: %s", isBack ? "true" : "false");
					ImGui::Text("Left: %s", isLeft ? "true" : "false");
					ImGui::Text("Right: %s", isRight ? "true" : "false");
				}
			}

			if (auto supplies = player->getSupplies(); supplies && ImGui::CollapsingHeader("Inventory"))
			{
				int selectedSlot = supplies->mSelectedSlot;
				ImGui::Text("SelectedSlot: %d", selectedSlot);
				ItemStack* stack = supplies->getContainer()->getItem(selectedSlot);

				if (stack && stack->getItem())
				{
					if (!TRY_CALL([&]()
						{
							if (!conStack.getItem()) ImGui::Text("Item: NULL");
							else ImGui::Text("Item: %s", conStack.getItem()->mName.c_str());
						}))
					{
						ImGui::Text("Failed to call ItemStack::fromDescriptor");
					}


					ImGui::Text("Item: %s", stack->getItem()->mName.c_str());
					ImGui::Text("Item Value: %d", ItemUtils::getItemValue(stack));
					ImGui::Text("Item Type: %s", magic_enum::enum_name(stack->getItem()->getItemType()).data());
					ImGui::Text("Item Tier: %d", stack->getItem()->getItemTier());
					ImGui::Text("Armor Slot: %d", stack->getItem()->getArmorSlot());
					displayCopyableAddress("Item", stack->getItem());
				}

				displayCopyableAddress("Item1", supplies->getContainer()->getItem(0));
				displayCopyableAddress("Item2", supplies->getContainer()->getItem(1));
				ImGui::Text("ItemAddress Diff: %d", reinterpret_cast<uintptr_t>(supplies->getContainer()->getItem(1)) - reinterpret_cast<uintptr_t>(supplies->getContainer()->getItem(0)));
			}

			if (gDaBlock && ImGui::CollapsingHeader("Block"))
			{
				displayCopyableAddress("Block", gDaBlock);

				if (auto leg = gDaBlock->toLegacy())
				{
					displayCopyableAddress("BlockLegacy", leg);
					ImGui::Text("BlockName: %s", leg->mName.c_str());

					auto mat = leg->mMaterial;
					displayCopyableAddress("Material", &mat);
					ImGui::Text("Material Type: %d", mat.mType);
					//ImGui::Text("Material Flammable: %s", mat->mIsFlammable ? "true" : "false"); removed
					ImGui::Text("Material Never Buildable: %s", mat.mIsNeverBuildable ? "true" : "false");
					ImGui::Text("Material Liquid: %s", mat.mIsLiquid ? "true" : "false");
					ImGui::Text("Material Blocking Motion: %s", mat.mIsBlockingMotion ? "true" : "false");
					ImGui::Text("Material Super Hot: %s", mat.mIsSuperHot ? "true" : "false");
				}
			}

			if (ImGui::CollapsingHeader("Components"))
			{
				displayCopyableAddress("MaxAutoStepComponent", player->getMaxAutoStepComponent());
				displayCopyableAddress("ActorWalkAnimationComponent", player->getWalkAnimationComponent());
				displayCopyableAddress("MoveInputComponent", player->mContext.getComponent<MoveInputComponent>());
				displayCopyableAddress("RawMoveInputComponent", player->mContext.getComponent<RawMoveInputComponent>());
				displayCopyableAddress("MobHurtTimeComponent", player->mContext.getComponent<MobHurtTimeComponent>());
				//displayCopyableAddress("ShadowOffsetComponent", player->mContext.getComponent<ShadowOffsetComponent>()); //alt = RelativeShadowOffsetComponent
				displayCopyableAddress("SubBBsComponent", player->mContext.getComponent<SubBBsComponent>());
				displayCopyableAddress("NameableComponent", player->mContext.getComponent<NameableComponent>());
				displayCopyableAddress("ActorStateVectorComponent", player->getStateVectorComponent());
				displayCopyableAddress("ItemUseSlowdownModifierComponent", player->mContext.getComponent<ItemUseSlowdownModifierComponent>());

				if (ImGui::Button("Dump Component Size Funcs"))
				{
					struct _SizeComponent
					{
						std::string sizeFunc;
						std::string componentName;
						unsigned int typeHash;

						nlohmann::json toJson()
						{
							return {
								{"SizeFunc", sizeFunc},
								{"ComponentName", componentName},
								{"TypeHash", fmt::format("{:X}", typeHash)}
							};
						}
					};
					static std::vector<_SizeComponent> sizeComponents = {};
					if (sizeComponents.empty())
					{
						for (auto& [typeHash, componentName] : Component::hashes)
						{
							entt::basic_storage<void*, EntityId>* storage = player->mContext.assureWithHash(typeHash);
							if (!storage)
							{
								spdlog::warn("Failed to assure component: {}", componentName);
								continue;
							}
							int index = 1;

							void** vtable = *reinterpret_cast<void***>(storage);
							uintptr_t func = reinterpret_cast<uintptr_t>(vtable[index]);

							// TODO: Figure out how to properly dump size from this function

							spdlog::info("TypeHash: 0x{:X}, Name: {}, VTable: {:X} Func: {:X}", typeHash, componentName, reinterpret_cast<uintptr_t>(vtable), func);
							std::string funcStr = MemUtils::getMbMemoryString(func);
							sizeComponents.emplace_back(_SizeComponent{ funcStr, componentName, typeHash });
						}
					}

					nlohmann::json j;
					for (auto& sizeComponent : sizeComponents)
					{
						j.push_back(sizeComponent.toJson());
					}

					std::string path = FileUtils::getSolsticeDir() + "\\component_sizes.json";
					std::ofstream file(path);
					file << j.dump(4);
					file.close();
					// Copy path to clipboard
					ImGui::SetClipboardText(path.c_str());
					NotifyUtils::notify("Copied file path to clipboard!", 7.5f, Notification::Type::Info);
				}
			}


			if (auto settings = player->getLevel() ? player->getLevel()->getPlayerMovementSettings() : nullptr; settings && ImGui::CollapsingHeader("Player Movement Settings"))
			{
//				std::string authority = std::string(magic_enum::enum_name(settings->AuthorityMode)) + " (" + std::to_string(static_cast<int>(settings->AuthorityMode)) + ")";
	//			ImGui::Text("Authority Movement: %s", authority.c_str());
				ImGui::Text("Rewind History Size: %d", static_cast<int>(settings->mRewindHistorySize));
				ImGui::Text("Server Auth Block Breaking: %s", settings->ServerAuthBlockBreaking ? "true" : "false");
				displayCopyableAddress("SyncedPlayerMovementSettings", settings);
			}
		}
	}

	if (ImGui::Button("Force Fallback"))
	{
		D3DHook::forceFallback = true;
	}

	FontHelper::popPrefFont();
	ImGui::End();
#endif
}