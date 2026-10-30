//
// Created by vastrakai on 6/25/2024.
//

#include "Actor.hpp"

#include "SerializedSkin.hpp"
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/MinecraftSim.hpp>
#include <SDK/Minecraft/MinecraftGame.hpp>
#include <SDK/Minecraft/Network/LoopbackPacketSender.hpp>
#include <SDK/Minecraft/Network/MinecraftPackets.hpp>
#include <SDK/Minecraft/Network/Packets/MovePlayerPacket.hpp>
#include <SDK/Minecraft/Network/Packets/AnimatePacket.hpp>
#include <SDK/Minecraft/World/Level.hpp>
#include <SDK/OffsetProvider.hpp>
#include <SDK/SigManager.hpp>
#include <Utils/MiscUtils/RenderUtils.hpp>

#include <Features/Modules/Movement/NoJumpDelay.hpp>

#include "ActorType.hpp"
#include "Components/ActorGameTypeComponent.hpp"
#include "Components/ActorTypeComponent.hpp"
#include "Components/FallDistanceComponent.hpp"
#include "Components/FlagComponent.hpp"
#include "Components/RuntimeIDComponent.hpp"
#include "Components/MobJumpComponent.hpp"
#include <SDK/Minecraft/Network/Packets/SetPlayerGameTypePacket.hpp>


/*FUCK YOU CLANG*/
#define COMPONENT_GET_FUNC(funcName, componentType) \
componentType* Actor::funcName() \
{ \
    if (!isValid()) \
    { \
        spdlog::critical("Actor::{}: isValid() failed", #funcName); \
        return nullptr; \
    } \
    auto component = mContext.getComponent<componentType>(); \
    if (!component) \
    { \
        spdlog::critical("Actor::{}: No {} found", #funcName, #componentType); \
    } \
    /*if (!MemUtils::isValidPtr(reinterpret_cast<uintptr_t>(component))) \
    { \
        spdlog::critical("Actor::{}: {} is not a valid ptr", #funcName, #componentType); \
        return nullptr; \
    } \*/\
    return component; \
}

COMPONENT_GET_FUNC(getWalkAnimationComponent, ActorWalkAnimationComponent)
COMPONENT_GET_FUNC(getActorTypeComponent, ActorTypeComponent)
COMPONENT_GET_FUNC(getRenderPositionComponent, RenderPositionComponent)
COMPONENT_GET_FUNC(getStateVectorComponent, StateVectorComponent)
COMPONENT_GET_FUNC(getMoveInputComponent, MoveInputComponent)
COMPONENT_GET_FUNC(getRawMoveInputComponent, RawMoveInputComponent)
COMPONENT_GET_FUNC(getActorRotationComponent, ActorRotationComponent)
COMPONENT_GET_FUNC(getAABBShapeComponent, AABBShapeComponent)
COMPONENT_GET_FUNC(getBlockMovementSlowdownMultiplierComponent, BlockMovementSlowdownMultiplierComponent)
COMPONENT_GET_FUNC(getActorUniqueIDComponent, ActorUniqueIDComponent)
COMPONENT_GET_FUNC(getActorHeadRotationComponent, ActorHeadRotationComponent)
COMPONENT_GET_FUNC(getMobBodyRotationComponent, MobBodyRotationComponent)
COMPONENT_GET_FUNC(getCameraDirectLookComponent, CameraDirectLookComponent)
COMPONENT_GET_FUNC(getMaxAutoStepComponent, MaxAutoStepComponent)
COMPONENT_GET_FUNC(getAttributesComponent, AttributesComponent)
COMPONENT_GET_FUNC(getCameraComponent, CameraComponent)
COMPONENT_GET_FUNC(getActorDataFlagComponent, ActorDataFlagComponent)

void Actor::swing(ActorSwingSource swingsource)
{

	MemUtils::callVirtualFunc<bool, unsigned char, unsigned char>(OffsetProvider::Actor_swing, this, (unsigned char)swingsource/* msvc meme*/, 0/*HAND SLOT*/);
}

bool Actor::isDestroying()
{
	//return hat::member_at<bool>(this, 0xAED);
	return hat::member_at<bool>(this, OffsetProvider::Actor_mDestroying);
}

bool Actor::isSwinging()
{
	return hat::member_at<bool>(this, OffsetProvider::Actor_mSwinging);
}

void Actor::setSwinging(bool swinging)
{
	hat::member_at<bool>(this, OffsetProvider::Actor_mSwinging) = swinging;
}

int Actor::getGameType()
{
	return mContext.getComponent<ActorGameTypeComponent>()->mGameType;
}

void Actor::setGameType(int type)
{
	auto pkt = MinecraftPackets::createPacket<SetPlayerGameTypePacket>();
	pkt->mPlayerGameType = static_cast<GameType>(type);
	PacketUtils::sendToSelf(pkt);
	ClientInstance::get()->getPacketSender()->sendToServer(pkt.get()); // on some servers this can server-side set the gamemode
}

bool Actor::isDebugCameraActive()
{
	// use da flag component
	auto storage = mContext.mRegistry->assure_t<DebugCameraIsActiveComponent>(0x25D8BF40u);
	return storage->contains(this->mContext.mEntityId);
}

void Actor::setDebugCameraActive(bool active)
{
	auto storage = mContext.mRegistry->assure_t<DebugCameraIsActiveComponent>(0x25D8BF40u);
	bool wasActive = isDebugCameraActive();
	if (active && !wasActive)
	{
		storage->emplace(this->mContext.mEntityId);
	}
	else if (!active && wasActive)
	{
		storage->remove(this->mContext.mEntityId);
	}
}


int Actor::getSwingProgress()
{
	return hat::member_at<int>(this, OffsetProvider::Actor_mSwingProgress);
}

int Actor::getOldSwingProgress()
{
	return hat::member_at<int>(this, OffsetProvider::Actor_mSwinging + 0x8);
}

void Actor::setSwingProgress(int progress)
{
	hat::member_at<int>(this, OffsetProvider::Actor_mSwingProgress) = progress;
}

AABB Actor::getAABB(bool normal)
{
	if (normal)
	{
		return AABB(this->getAABBShapeComponent()->mMin, this->getAABBShapeComponent()->mMax);
	}
	// Get all components
	auto renderPositionComponent = getRenderPositionComponent();
	if (!renderPositionComponent) return AABB();
	auto aabbShapeComponent = getAABBShapeComponent();
	if (!aabbShapeComponent) return AABB();

	glm::vec3 renderPos = renderPositionComponent->mPosition - glm::vec3(0, PLAYER_HEIGHT, 0);
	if (!isPlayer()) renderPos = renderPositionComponent->mPosition;

	glm::vec2 size = { aabbShapeComponent->mWidth, aabbShapeComponent->mHeight };
	auto localPlayer = ClientInstance::get()->getLocalPlayer();
	if (this == localPlayer)
	{
		renderPos = RenderUtils::transform.mPlayerPos - glm::vec3(0, PLAYER_HEIGHT, 0);
	}

	float hitboxWidth = size.x;
	float hitboxHeight = size.y;
	glm::vec3 aabbMin = renderPos - glm::vec3(hitboxWidth / 2, 0, hitboxWidth / 2);
	glm::vec3 aabbMax = renderPos + glm::vec3(hitboxWidth / 2, hitboxHeight, hitboxWidth / 2);
	aabbMin = aabbMin - glm::vec3(0.1f, 0.1f, 0.1f);
	aabbMax = aabbMax + glm::vec3(0.1f, 0.1f, 0.1f);
	return AABB(aabbMin, aabbMax, true);
}

void Actor::setAABB(AABB& aabb)
{
	AABBShapeComponent* aabbShapeComponent = getAABBShapeComponent();
	if (!aabbShapeComponent) return;
	aabbShapeComponent->mMin = aabb.mMin;
	aabbShapeComponent->mMax = aabb.mMax;
}


bool Actor::isPlayer()
{
	auto actorType = getActorTypeComponent();
	if (!actorType) return false;
	return actorType->mType == ActorType::Player;
}

ChunkPos Actor::getChunkPos()
{
	glm::vec3 pos = *getPos();
	pos.x = static_cast<int>(floor(pos.x));
	pos.y = static_cast<int>(floor(pos.y - (float)2.0f));
	pos.z = static_cast<int>(floor(pos.z));
	return ChunkPos(pos);
}

glm::vec3* Actor::getPos()
{
	return &getStateVectorComponent()->mPos;
}

glm::vec3* Actor::getPosPrev()
{
	return &getStateVectorComponent()->mPosOld;
}

GameMode* Actor::getGameMode()
{
	return hat::member_at<GameMode*>(this, OffsetProvider::Actor_mGameMode);
}


DebugCameraComponent* Actor::getDebugCameraComponent()
{
	return mContext.try_get<DebugCameraComponent>();
}

CameraPresetComponent* Actor::getCameraPresetComponent()
{
	return mContext.try_get<CameraPresetComponent>();
}

ContainerManagerModel* Actor::getContainerManagerModel()
{
	return hat::member_at<ContainerManagerModel*>(this, OffsetProvider::Actor_mContainerManagerModel);
}

JumpControlComponent* Actor::getJumpControlComponent()
{
	return nullptr; // useless now , localplayer doesnt it now :joy: 
}

MobHurtTimeComponent* Actor::getMobHurtTimeComponent()
{
	return mContext.try_get<MobHurtTimeComponent>();
}

SimpleContainer* Actor::getArmorContainer()
{
	return mContext.getComponent<ActorEquipmentComponent>()->mArmorContainer;
}

PlayerInventory* Actor::getSupplies()
{
	return hat::member_at<PlayerInventory*>(this, OffsetProvider::Actor_mSupplies);
}

Level* Actor::getLevel()
{
	return hat::member_at<Level*>(this, OffsetProvider::Actor_mLevel);
}



SerializedSkinImpl* Actor::getSkin() // only work 1.21.92 -100
{
	auto playerList = getLevel()->getPlayerList();
	if (!playerList) return nullptr;
	for (const auto& [UUID, Entry] : *playerList)
	{
		auto cmp = getActorUniqueIDComponent();
		if (!cmp) {
			return nullptr;
		}
		if (Entry.mId == getActorUniqueIDComponent()->mUniqueID)
		{
			auto Skin = &Entry.mSkin;
			return &Skin->impl->Object;
		}
	}
	return nullptr;
}

int64_t Actor::getRuntimeID()
{
	auto runtimeIDComponent = mContext.getComponent<RuntimeIDComponent>();
	return runtimeIDComponent ? runtimeIDComponent->mRuntimeID : -1;
}

void Actor::setPosition(glm::vec3 pos)
{
	// stupid fix
	/*static uintptr_t func = SigManager::Actor_setPosition;
	MemUtils::callFastcall<void, void*, glm::vec3*>(func, this, &pos);*/
	auto mpp = MinecraftPackets::createPacket<MovePlayerPacket>();
	mpp->mPlayerID = this->getRuntimeID();
	auto rotComp = this->getActorRotationComponent();
	mpp->mRot = { rotComp->mPitch, rotComp->mYaw };
	mpp->mYHeadRot = this->getActorHeadRotationComponent()->mHeadRot;
	mpp->mPos = pos;
	mpp->mResetPosition = PositionMode::Teleport;
	mpp->mRidingID = -1;
	mpp->mCause = TeleportationCause::Unknown;
	mpp->mSourceEntityType = ActorType::Player;
	mpp->mTick = 0;
	PacketUtils::sendToSelf(mpp);
}

void Actor::setPos(float x, float y, float z)
{
	setPosition({ x, y, z });
}

float Actor::distanceTo(Actor* actor)
{
	glm::vec3* actorPos = actor->getPos();
	if (!actorPos) return -1;
	glm::vec3 closestPoint = getAABB().getClosestPoint(*actorPos);
	return distance(closestPoint, *actorPos);
}

float Actor::distanceTo(const glm::vec3& pos)
{
	glm::vec3 closestPoint = getAABB().getClosestPoint(pos);
	return distance(closestPoint, pos);
}

bool Actor::wasOnGround()
{
	return getFlag<WasOnGroundFlagComponent>();
}

bool Actor::isOnGround()
{
	return getFlag<OnGroundFlagComponent>();
}

void Actor::setOnGround(bool flag)
{
	setFlag<OnGroundFlagComponent>(flag);
}

bool Actor::isCollidingHorizontal()
{
	return getFlag<HorizontalCollisionFlagComponent>();
}

bool Actor::isDead()
{
	return getFlag<IsDeadFlagComponent>();
}

void Actor::jumpFromGround()
{
	NoJumpDelay::PatchNoJumpDelay(true);
	static auto func = reinterpret_cast<void*>(SigManager::SimulatedPlayer_simulateJump);
	MemUtils::callFastcall<void>(func, this);
	NoJumpDelay::PatchNoJumpDelay(false);
}

float Actor::getFallDistance()
{
	return mContext.getComponent<FallDistanceComponent>()->mFallDistance;
}

void Actor::setFallDistance(float distance)
{
	mContext.getComponent<FallDistanceComponent>()->mFallDistance = distance;
}

std::string Actor::getRawName()
{
	auto actorType = getActorTypeComponent();
	if (!actorType)
	{
		spdlog::warn("Actor::getRawName: No ActorTypeComponent found");
		return "Unknown?";
	}
	auto actorUniqueID = getActorUniqueIDComponent();
	if (!actorUniqueID)
	{
		spdlog::warn("Actor::getRawName: No ActorUniqueIDComponent found");
		return "What?";
	}

	if (actorType->mType != ActorType::Player)
	{
		// mEntityIdentifier will be used as fallback
		return mEntityIdentifier;
	}
	auto player = ClientInstance::get()->getLocalPlayer();
	uint64_t uniqueId = actorUniqueID->mUniqueID;

	for (auto& [id, entry] : *player->getLevel()->getPlayerList())
	{
		if (entry.mId == uniqueId)
		{
			return entry.mName;
		}
	}

	std::string name = getNameTag();
	name = name.substr(0, name.find('\n'));
	name = ColorUtils::removeColorCodes(name);
	return name;
}

const std::string& Actor::getNameTag()
{
	static auto func = SigManager::Actor_getNameTag;
	return *MemUtils::callFastcall<std::string*>(func, this);
}

void Actor::setNametag(const std::string& name)
{
	static auto func = SigManager::Actor_setNameTag;
	MemUtils::callFastcall<void, void*, std::string>(func, this, name);
}

float Actor::getMaxHealth()
{
	auto health = getAttribute(Health);
	if (!health) return 0;
	return health->mCurrentMaxValue;
}

float Actor::getHealth()
{
	auto health = getAttribute(Health);
	if (!health) return 0;
	return health->mCurrentValue;
}

float Actor::getAbsorption()
{
	auto absorption = getAttribute(Absorption);
	if (!absorption) return 0;
	return absorption->mCurrentValue;
}

float Actor::getMaxAbsorption()
{
	auto absorption = getAttribute(Absorption);
	if (!absorption) return 0;
	return absorption->mCurrentMaxValue;
}

AttributeInstance* Actor::getAttribute(AttributeId id)
{
	return getAttribute(static_cast<int>(id));
}

AttributeInstance* Actor::getAttribute(int id)
{
	auto component = getAttributesComponent();
	if (!component) {
		spdlog::critical("Actor::getAttribute: No AttributesComponent found");
		return nullptr;
	}
	return component->mBaseAttributeMap.getInstance(id);
}

bool Actor::isOnFire()
{
	return getFlag<OnFireComponent>();
}

std::string Actor::getLocalName()
{
	auto result = hat::member_at<std::string>(this, OffsetProvider::Actor_mLocalName);
	return result.empty() ? getRawName() : result;
}

void Actor::setLocalName(std::string newLocalName)
{
	auto& localName = hat::member_at<std::string>(this, OffsetProvider::Actor_mLocalName);
	localName = newLocalName;
}

std::string Actor::getXuid()
{
	return ClientInstance::get()->getMinecraftGame()->getxuid();
}

bool Actor::isValid()
{
	if (this == nullptr) return false;
	// Make sure mRegistry is a valid ptr
	if (!mContext.mRegistry) return false;

	auto player = ClientInstance::get()->getLocalPlayer();
	return player->mContext.mRegistry->valid(mContext.mEntityId);
}

bool Actor::canSee(Actor* actor)
{
	glm::vec3 buf{};
	MemUtils::callFastcall<glm::vec3*, Actor*, glm::vec3*, ActorLocation,float>(SigManager::GetCollisionShapeActorProxy_getFeetAttachPos, actor ,&buf, ActorLocation::Body, 0.f);
	return MemUtils::callFastcall<bool,Actor*,glm::vec3&, ShapeType>(SigManager::Actor_canSee, this, buf, ShapeType::Collision);
}
