#pragma once
//
// Created by vastrakai on 6/24/2024.
//

#include <cstdint>
#include <future>
#include <include/libhat/include/libhat.hpp>
#include <include/libhat/include/libhat/Scanner.hpp>
#include <include/libhat/include/libhat/Signature.hpp>
#include <Utils/SysUtils/xorstr.hpp>

enum class SigType {
	Sig,
	RefSig
};

#define DEFINE_SIG(name, str, sig_type, offset) \
public: \
static inline uintptr_t name; \
private: \
static void name##_initializer() { \
    auto result = scanSig(hat::compile_signature<str>(), xorstr_(#name), offset); \
    if (!result.has_result()) { \
        name = 0; \
        return; \
    } \
    if (sig_type == SigType::Sig) name = reinterpret_cast<uintptr_t>(result.get()); \
    else name = reinterpret_cast<uintptr_t>(result.rel(offset)); \
} \
static inline std::function<void()> name##_function = (mSigInitializers.emplace_back(name##_initializer), std::function<void()>()); \
public:



class SigManager {
	static hat::scan_result scanSig(hat::signature_view sig, const std::string& name, int offset = 0);

	static inline std::vector<std::function<void()>> mSigInitializers;
	static inline int mSigScanCount;
public:
	static inline bool mIsInitialized = false;
	static inline std::unordered_map<std::string, uintptr_t> mSigs;

	//DEFINE_SIG(Actor_setPosition, "48 89 5C 24 ? 57 48 83 EC ? 48 8B 59 ? 48 8B FA 48 8B 8B ? ? ? ? 48 85 C9", SigType::Sig, 0);
	DEFINE_SIG(Actor_getNameTag, "56 48 83 EC ? 48 8B 81 ? ? ? ? 48 85 C0 74 ? 8B 50 ? ? ? ? 29 CA 81 E2 ? ? ? ? 48 8D 05", SigType::Sig, 0); // 26.51
	DEFINE_SIG(Actor_setNameTag, "56 57 48 83 EC ? 48 89 CE 48 8B 89 ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 48 89 D7", SigType::Sig, 0); //26.51
	//DEFINE_SIG(ClientInstance_getScreenName, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F2 33 ED 48 8B 01 48 8D 54 24 ? 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 90 48 8B 48 ? 48 8B 01 48 8B D6 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 90 48 89 6C 24 ? 48 8B 5C 24 ? 48 89 6C 24 ? BF ? ? ? ? 48 85 DB 74 ? 8B C7 F0 0F C1 43 ? 83 F8 ? 75 ? 48 8B 03 48 8B CB 48 8B 00 FF 15 ? ? ? ? 8B C7 F0 0F C1 43 ? 83 F8 ? 75 ? 48 8B 03 48 8B CB 48 8B 40 ? FF 15 ? ? ? ? 48 89 6C 24 ? 48 8B 5C 24 ? 48 85 DB 74 ? 8B C7 F0 0F C1 43 ? 83 F8 ? 75 ? 48 8B 03 48 8B CB 48 8B 00 FF 15 ? ? ? ? F0 0F C1 7B ? 83 FF ? 75 ? 48 8B 03 48 8B CB 48 8B 40 ? FF 15 ? ? ? ? 48 8B C6 48 8B 5C 24 ? 48 8B 6C 24 ? 48 8B 74 24 ? 48 83 C4 ? 5F C3 CC CC CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 6C 24", SigType::Sig, 0);
	//DEFINE_SIG(ActorRenderDispatcher_render, "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 0F 29 B4 24 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 F7 4C 89 4C 24 ?", SigType::Sig, 0); // 1.21.51
	DEFINE_SIG(ClientInstance_mBgfx, "4C 8B 35 ? ? ? ? 49 8D 8E", SigType::RefSig, 3); //maybe
	//vtable better :ultra_retard:
	//DEFINE_SIG(ClientInstance_grabMouse, "40 ? 48 83 EC ? 48 8B ? 48 8B ? 48 8B ? ? ? ? ? FF 15 ? ? ? ? 84 C0 74 ? 48 8B ? ? ? ? ? 48 8B ? 48 8B ? ? ? ? ? 48 83 C4 ? 5B 48 FF ? ? ? ? ? 48 83 C4 ? 5B C3 40", SigType::Sig, 0); // 1.21.51
	//DEFINE_SIG(ClientInstance_releaseMouse, "40 ? 48 83 EC ? 48 8B ? 48 8B ? 48 8B ? ? ? ? ? FF 15 ? ? ? ? 84 C0 74 ? 48 8B ? ? ? ? ? 48 8B ? 48 8B ? ? ? ? ? 48 83 C4 ? 5B 48 FF ? ? ? ? ? 48 83 C4 ? 5B C3 48 89", SigType::Sig, 0); // 1.21.51
	DEFINE_SIG(ContainerScreenController_tick, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 0F 29 75 ? 48 C7 45 ? ? ? ? ? 48 89 CE 48 8D B9 ? ? ? ? C6 45", SigType::Sig, 0); // 26.51
	DEFINE_SIG(ContainerScreenController_handleAutoPlace, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 44 89 CE 4C 89 C7 41 89 D6", SigType::Sig, 0); // 26.51
	DEFINE_SIG(ComplexInventoryTransaction_vtable, "48 8D 05 ? ? ? ? ? ? ? 48 83 C1 ? E8 ? ? ? ? 40 F6 C7 ? 74 ? BA ? ? ? ? 48 89 F1 E8 ? ? ? ? 48 89 F0 48 83 C4 ? 5F 5E C3 ? ? ? ? ? 56 57 48 83 EC ? 89 D7 48 89 CE E8 ? ? ? ? 40 F6 C7 ? 74 ? BA ? ? ? ? 48 89 F1 E8 ? ? ? ? 48 89 F0 48 83 C4 ? 5F 5E C3 ? ? ? 56 48 83 EC", SigType::RefSig, 3); //26.51
	DEFINE_SIG(EnchantUtils_getEnchantLevel, "56 57 53 48 81 EC ? ? ? ? 89 CB 48 8B 4A ? 31 F6", SigType::Sig, 0); // 1.26.51
	DEFINE_SIG(GameMode_getDestroyRate, "56 57 48 83 EC ? 0F 29 74 24 ? 48 89 CE 48 8B 49 ? E8 ? ? ? ? 0F 28 F0", SigType::Sig, 0); // 26.51
	DEFINE_SIG(HoverTextRenderer_render, "55 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 48 83 79 ? 00", SigType::Sig, 0); // 1.21.51
	DEFINE_SIG(GameMode_baseUseItem, "55 41 57 41 56 41 54 56 57 53 48 81 EC 50 01 00 00 48 8D AC 24 ? ? ? ? 48 C7 85 ? ? ? ? FE FF FF FF 44 89 C3", SigType::Sig, 0); // 1.21.51
	DEFINE_SIG(GuiData_displayClientMessage, "55 56 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 44 88 CB", SigType::Sig, 0); // 21.51 need check
	DEFINE_SIG(InventoryTransaction_addAction, "55 41 57 41 56 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 48 89 D7 48 89 CE ? ? 41 89 C7", SigType::Sig, 0);
	DEFINE_SIG(ItemStack_vTable, "48 8D 05 ? ? ? ? ? ? ? 0F B6 81 ? ? ? ? FE C8 3C ? 77 ? 48 8D 91 ? ? ? ? 48 8B 81 ? ? ? ? ? ? ? 48 89 CE 48 89 D1 31 D2 FF 15 ? ? ? ? 48 89 F1 48 83 C4 ? 5E E9 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 48 8B 80", SigType::RefSig, 3); // ?$dtor@ItemStack@@QEAAXXZ is inlined :joy:
	DEFINE_SIG(ItemStack_getCustomName, "56 57 48 83 EC 28 48 89 D6 48 8B 41 ? 48 85 C0 74 ? 48 89 CF", SigType::Sig, 0); // 1.26.0
	DEFINE_SIG(ItemUseInventoryTransaction_vtable, "48 89 85 ? ? ? ? 8B 45 ? 89 85 ? ? ? ? C6 85 ? ? ? ? ? 0F B6 45", SigType::RefSig, 3);
	DEFINE_SIG(ItemUseOnActorInventoryTransaction_vtable, "48 8D 05 ? ? ? ? ? ? ? 0F 10 43 ? 0F 11 47", SigType::RefSig, 3);
	DEFINE_SIG(ItemReleaseInventoryTransaction_vtable, "4C 8D 3D ? ? ? ? 4C 8D A6", SigType::RefSig, 3); // 26.51 need check
	//DEFINE_SIG(Keyboard_feed, "E8 ? ? ? ? E9 ? ? ? ? 41 0F ? ? ? 45 0F ? ? ? 45 0F", SigType::RefSig, 1);
	//DEFINE_SIG(MainView_instance, "48 8B 05 ? ? ? ? C6 40 ? ? 0F 95 C0", SigType::RefSig, 3);
	DEFINE_SIG(MinecraftGame_instance, "48 89 15 ? ? ? ? 49 8B 40", SigType::RefSig, 3);
	DEFINE_SIG(MinecraftPackets_createPacket, "56 48 83 EC ? 48 89 CE 81 FA", SigType::Sig, 0); // 1.26.51
	//hate ms
	//DEFINE_SIG(Mob_getJumpControlComponent, "E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? ? ? ? E9 ? ? ? ? F3 0F 10 43", SigType::RefSig, 1); //iguess
	DEFINE_SIG(Mob_JumpFromGroundRequestComponentPatch, "C7 46 ? ? ? ? ? 48 83 C4 ? 5E C3 ? ? ? ? ? ? ? ? ? ? ? ? ? ? 41 57", SigType::Sig, 0); // guess name :joy:
	DEFINE_SIG(Mob_getCurrentSwingDuration, "55 56 48 83 EC ? 48 8D 6C 24 ? 48 C7 45 ? ? ? ? ? 48 89 CE 8B 05 ? ? ? ? 8B 0D ? ? ? ? 65 48 8B 14 25 ? ? ? ? ? ? ? ? 3B 81 ? ? ? ? 7F ? ? ? ? 48 8B 80 ? ? ? ? 48 8D 15 ? ? ? ? 48 89 F1 FF 15 ? ? ? ? 48 85 C0 74 ? F3 0F 10 40 ? F3 0F 59 05 ? ? ? ? F3 48 0F 2C C0", SigType::Sig, 0); // some anotherone class
	DEFINE_SIG(MouseDevice_feed, "41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC ? 44 89 CF 44 89 C3 89 D5 48 89 CE 44 0F B7 A4 24", SigType::Sig, 0);
	DEFINE_SIG(NetworkStackItemDescriptor_ctor, "55 56 57 53 48 83 EC ? 48 8D 6C 24 ? 48 C7 45 ? ? ? ? ? 48 89 D6 48 89 CB 0F B6 7A ? 48 8D 55 ? 48 89 F1 E8 ? ? ? ? 48 8D 05 ? ? ? ? ? ? ? 48 8B 4D ? 48 85 C9 74 ? 48 8D 53 ? ? ? ? ? ? ? 48 89 4D ? FF 15 ? ? ? ? 90 48 8D 05 ? ? ? ? ? ? ? 66 89 7B ? 48 8B 4D ? ? ? ? 48 8B 80 ? ? ? ? BA ? ? ? ? FF 15 ? ? ? ? EB ? 48 C7 43 ? 00 00 00 00 48 8D 05 ? ? ? ? ? ? ? 66 89 7B ? 48 8D 05 ? ? ? ? ? ? ? C6 43 ? 00", SigType::Sig, 0);
	DEFINE_SIG(PlayerMovement_clearInputStateInlined, "75 ? 4C 89 6C 24 ? 8B 4C 24", SigType::Sig, 0);
	DEFINE_SIG(PlayerMovement_clearInputStateInlined2, "E9 ? ? ? ? 48 8D 0D ? ? ? ? 4C 89 CB 49 89 D6", SigType::Sig, 0);
	DEFINE_SIG(PlayerMovement_clearInputStateInlined3, "0F 84 ? ? ? ? 48 89 7C 24 ? 0F 10 45", SigType::Sig, 0);

	DEFINE_SIG(NetherNetConnector_runEvents, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 48 89 CE 0F 57 C0 0F 29 45 ? 48 C7 45 ? 00 00 00 00 48 81 C1", SigType::Sig, 0);
	DEFINE_SIG(RakNet_RakPeer_runUpdateCycle, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 66 0F 7F B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 48 89 95", SigType::Sig, 0);
	DEFINE_SIG(RakNet_RakPeer_sendImmediate, "41 57 41 56 41 55 41 54 56 57 55 53 48 81 EC ? ? ? ? 44 89 CD 44 89 C6", SigType::Sig, 0);
	DEFINE_SIG(ScreenView_setupAndRender, "55 41 57 41 56 41 55 41 54 56 57 53 B8 ? ? ? ? E8 ? ? ? ? 48 29 C4 48 8D AC 24 ? ? ? ? 44 0F 29 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 48 89 95 ? ? ? ? 48 89 CF", SigType::Sig, 0); // 26.51
	DEFINE_SIG(SimulatedPlayer_simulateJump, "56 57 48 83 EC ? 48 89 CE 48 8B 01 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 84 C0 0F 84", SigType::Sig, 0);
	DEFINE_SIG(ItemInHandRenderer_render_bytepatch, "F3 0F 59 05 ? ? ? ? 0F 57 C9 ? ? ? ? 41 0F 10 5F", SigType::Sig, 0);
	DEFINE_SIG(SneakMovementSystem_tickSneakMovementSystem, "83 E1 ? 88 48", SigType::Sig, 0);
	DEFINE_SIG(SneakMovementSystem_tickSneakMovementSystem2, "? ? ? 83 E1 ? 41 89 CA ? ? ? 44 88 50", SigType::Sig, 0);
	DEFINE_SIG(ConnectionRequest_create, "55 41 56 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 4C 89 CB 4C 89 C7 48 89 95", SigType::Sig, 0);
	//DEFINE_SIG(ConnectionRequest_getdeviceos, "48 83 ec ? 48 8b 01 48 8b 80 ? ? ? ? ff 15 ? ? ? ? 83 e8", SigType::Sig, 0);
	DEFINE_SIG(CameraDirectLookSystemUtil_handleLookInput, "56 48 83 EC 30 0F 29 74 24 ? 4C 89 C6 F3 0F 10 05", SigType::Sig, 0); // 26.51 maybe
	DEFINE_SIG(ItemRenderer_render, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 95 ? ? ? ? 44 0F 29 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? ? ? ? 48 85 F6", SigType::Sig, 0);
	//DEFINE_SIG(ItemPositionConst, "F3 0F ? ? ? ? ? ? F3 0F ? ? F3 0F ? ? F3 0F ? ? ? ? ? ? F3 0F ? ? 0F B7", SigType::Sig, 0);
	/*DEFINE_SIG(glm_rotate, "40 53 48 83 EC ? F3 0F 59 0D ? ? ? ? 4C 8D 4C 24", SigType::Sig, 0);
	DEFINE_SIG(glm_rotateRef, "E8 ? ? ? ? 0F 28 ? ? ? ? ? 48 8B ? C6 40 38", SigType::Sig, 0);
	DEFINE_SIG(glm_translateRef, "E8 ? ? ? ? E9 ? ? ? ? 40 84 ? 0F 84 ? ? ? ? 83 FF", SigType::Sig, 0);
	DEFINE_SIG(glm_translateRef2, "E8 ? ? ? ? C6 46 ? ? F3 0F 11 74 24 ? F3 0F 10 1D", SigType::Sig, 0);*/
	DEFINE_SIG(BlockSource_fireBlockChanged, "41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC ? 48 8B 81 ? ? ? ? 48 39 81 ? ? ? ? 0F 84 ? ? ? ? 4C 89 CE", SigType::Sig, 0);
	DEFINE_SIG(ActorAnimationControllerPlayer_applyToPose, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 9D ? ? ? ? 44 0F 29 95 ? ? ? ? 44 0F 29 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 4D 89 C5 48 89 D6", SigType::Sig, 0); // 1.21.80
	DEFINE_SIG(JSON_parse, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 48 83 7A", SigType::Sig, 0);
	// who using this
	// DEFINE_SIG(Actor_getStatusFlag, "48 83 EC ? 8B 41 ? 48 8B 49 ? 4C 63 DA", SigType::Sig, 1); // 8
	//DEFINE_SIG(Level_getRuntimeActorList, "48 89 ? ? ? 55 56 57 48 83 EC ? 48 8B ? 48 89 ? ? ? 33 D2", SigType::Sig, 0); // 1.21.51
	DEFINE_SIG(ConcreteBlockLegacy_getCollisionShapeForCamera, "41 56 56 57 53 48 83 EC ? 0F 29 7C 24 ? 0F 29 74 24 ? 48 89 D6 48 8B BC 24", SigType::Sig, 0); 
	DEFINE_SIG(WaterBlockLegacy_getCollisionShapeForCamera, "48 89 D0 0F 57 C0 ? ? ? 48 C7 42 ? 00 00 00 00 C3", SigType::Sig, 0); //who name this fucking
	DEFINE_SIG(ActorShaderManager_setupShaderParameters, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 BD ? ? ? ? 44 0F 29 B5 ? ? ? ? 44 0F 29 AD ? ? ? ? 44 0F 29 A5 ? ? ? ? 44 0F 29 9D ? ? ? ? 44 0F 29 95 ? ? ? ? 66 44 0F 7F 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD", SigType::Sig, 0);
	//DEFINE_SIG(mce_framebuilder_RenderItemInHandDescription_ctor, "48 89 5C 24 ? 48 89 4C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 83 EC ? 4D 8B E1 4D 8B E8 4C 8B FA 48 8B F9", SigType::Sig, 0);

	//41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC ? 4D 89 CC 4D 89 C6 48 89 D6 need check latter
	DEFINE_SIG(ResourcePackManager_composeFullStackBp, "0F 85 ? ? ? ? 48 83 BD ? ? ? ? ? 75 ? 48 83 BD", SigType::Sig, 0);
	DEFINE_SIG(ClientInstance_isPreGame, "48 83 EC ? ? ? ? 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 48 85 C0 0F 94 C0", SigType::Sig, 0);
	// "minecraft:use_modifiers" - > ComponentItem::getMovementModifier xref
	DEFINE_SIG(tickEntity_ItemUseSlowdownModifierComponent, "56 57 53 48 83 EC 40 0F 29 74 24 ? 4C 89 C6 48 89 CF", SigType::Sig, 0); 

	DEFINE_SIG(checkBlocks, "48 8D 1D ? ? ? ? 48 89 5C 24 ? C6 44 24 ? 00 48 C7 44 24 ? 00 00 00 00", SigType::Sig, 0);
	//DEFINE_SIG(JSON_toStyledString, "E8 ? ? ? ? 90 0F B7 ? ? ? ? ? 66 89 ? ? ? ? ? 48 8D ? ? ? ? ? 48 8D ? ? ? ? ? E8 ? ? ? ? 0F 57 ? 0F 11 ? ? ? ? ? 48 8D ? ? ? ? ? 48 89 ? ? ? ? ? 8B 85 ? ? ? ? 89 85 ? ? ? ? 4C 8B ? ? ? ? ? 49 8B ? 48 8D ? ? ? ? ? E8 ? ? ? ? 48 8B ? ? ? ? ? 48 8D ? ? ? ? ? E8 ? ? ? ? 48 8B ? 48 8D ? ? ? ? ? E8 ? ? ? ? 90 48 8D ? ? ? ? ? 48 8D ? ? ? ? ? E8 ? ? ? ? 90 0F 57 ? 33 C0 0F 11 ? ? ? ? ? 48 89 ? ? ? ? ? 48 8D ? ? ? ? ? E8 ? ? ? ? 90 48 8D", SigType::RefSig, 1);

	// TODO: Identify proper function names for these and refactor them accordingly
	// need check this
	DEFINE_SIG(Unknown_renderBlockOverlay, "0F 84 ? ? ? ? 48 8D 45 ? 48 89 44 24 ? 48 8D 4D ? 48 8B 55", SigType::Sig, 0);
	//DEFINE_SIG(FastEat, "41 B6 ? 48 8D 4F", SigType::Sig, 0); //8
	DEFINE_SIG(Unknown_renderNametag, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 95 ? ? ? ? 44 0F 29 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD ? ? ? ? 0F 29 B5 ? ? ? ? 48 C7 85 ? ? ? ? ? ? ? ? 4C 89 8D ? ? ? ? 4D 89 C7", SigType::Sig, 0);
	DEFINE_SIG(Reach, "F3 0F 10 3D ? ? ? ? EB ? F3 0F 10 3D ? ? ? ? ? ? ? 48 8B 80", SigType::Sig, 0);
	DEFINE_SIG(BlockReach, "F3 0F 10 05 ? ? ? ? EB ? 48 8B 79", SigType::Sig, 0);
	DEFINE_SIG(GetSpeedInAirWithSprint, "41 C7 40 ? ? ? ? ? 31 C0", SigType::Sig, 0);
	DEFINE_SIG(ConnectionRequest_create_DeviceModel, "? ? ? 48 83 C2 ? 48 8D 8D ? ? ? ? E8 ? ? ? ? 90 48 8D 15", SigType::Sig, 0);
	DEFINE_SIG(ConnectionRequest_create_DeviceOS, "FF 15 ? ? ? ? 90 89 C2 48 8D 8D ? ? ? ? E8 ? ? ? ? 90 48 8D 15 ? ? ? ? 48 8D 8D ? ? ? ? E8 ? ? ? ? 90 48 89 C1", SigType::Sig, 0); //maybe
	DEFINE_SIG(ConnectionRequest_create_DefaultInputMode, "? ? ? 48 8B 80 ? ? ? ? FF 15 ? ? ? ? 31 C9 83 F8 ? 0F 94 C1 8D 0C 4D", SigType::Sig, 0);
	//DEFINE_SIG(ConnectionRequest_create_CurrentInputMode, "48 8D 4C 24 ? E8 ? ? ? ? 90 48 8D 15 ? ? ? ? 48 8D 8D ? ? ? ? E8 ? ? ? ? 48 8B C8 48 8D 54 24 ? E8 ? ? ? ? 90 48 8D 4C 24 ? E8 ? ? ? ? 8B 54 24 ? 48 8D 4C 24 ? E8 ? ? ? ? 90 48 8D 15 ? ? ? ? 48 8D 8D ? ? ? ? E8 ? ? ? ? 48 8B C8 48 8D 54 24 ? E8 ? ? ? ? 90 48 8D 4C 24 ? E8 ? ? ? ? 48 8B 55", SigType::Sig, 0); // its shit lawl gg xd
	//func = 48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4D 8B E0 4C 8B EA//  but mov edx, 1 no need to make patch(default by mouse input) thanks shit shit clang
	//DEFINE_SIG(InputModeBypass, "48 8B 82 ? ? ? ? 8B D3 FF 15 ? ? ? ? 49 8B 0C 24", SigType::Sig, 0);
	//DEFINE_SIG(InputModeBypassFix, "8B D3 49 8B CC FF 15 ? ? ? ? 49 8B 04 24", SigType::Sig, 0); // fixes gui bugs, withot it ur inv will works like on mobile
	DEFINE_SIG(TapSwingAnim, "F3 44 0F 59 05 ? ? ? ? F3 0F 10 05 ? ? ? ? 0F 13 85", SigType::RefSig, 5);
	DEFINE_SIG(Unknown_updatePlayerFromCamera, "41 57 41 56 41 55 41 54 56 57 55 53 48 81 EC ? ? ? ? 44 0F 29 94 24 ? ? ? ? 44 0F 29 8C 24 ? ? ? ? 44 0F 29 84 24 ? ? ? ? 0F 29 BC 24 ? ? ? ? 0F 29 B4 24 ? ? ? ? 4C 89 C6", SigType::Sig, 0);

	DEFINE_SIG(FluxSwing, "41 0F 11 47 ? E9 ? ? ? ? 48 89 9E", SigType::Sig, 0);
	DEFINE_SIG(BobHurt, "56 57 55 53 48 81 EC ? ? ? ? 44 0F 29 8C 24 ? ? ? ? 44 0F 29 84 24 ? ? ? ? 0F 29 BC 24 ? ? ? ? 0F 29 B4 24 ? ? ? ? 0F 28 F2", SigType::Sig, 0); // 26.51
	DEFINE_SIG(CameraComponent_applyRotation, "7E ? 0F 57 FF F3 0F 2A F8", SigType::Sig, 0); // Guessed func name
	DEFINE_SIG(GetCollisionShapeActorProxy_getFeetAttachPos, "41 57 41 56 41 55 41 54 56 57 55 53 48 83 EC ? 0F 29 74 24 ? 48 89 D6 41 8D 40", SigType::Sig, 0); //getFeetAttachPosY@GetCollisionShapeActorProxy@@QEBAMXZ BUT GETTING VEC3 WHY Y = VEC3?
	DEFINE_SIG(Actor_canSee, "41 57 41 56 56 57 53 48 81 EC ? ? ? ? 44 89 C3 48 89 D6 48 89 CF 48 8B 89 ? ? ? ? 8B 41 ? 66 66 66 66 66 66 2E 0F 1F 84 00 ? ? ? ? 8D 50 ? F0 0F B1 51 ? 75 ? 4C 8B B7 ? ? ? ? 4C 8B BF ? ? ? ? 4D 85 FF 74 ? F0 41 FF 4F ? 75 ? ? ? ? ? ? ? 4C 89 F9 FF 15 ? ? ? ? F0 41 FF 4F ? 75 ? ? ? ? 48 8B 40 ? 4C 89 F9 FF 15 ? ? ? ? ? ? ? 48 8B 40 ? 4C 89 F1 FF 15 ? ? ? ? 49 89 C6", SigType::Sig, 0);
	//INLINED BY FUCKING CLANG but its just vector :joy:
	//DEFINE_SIG(BaseAttributeMap_getInstance, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 83 EC ? 48 8B 2A 4D 8B D8 4C 8B 72 ? 48 8B F2 4D 8B C6 48 8B F9 4C 2B C5 4C 8B D5 49 C1 F8 ? 4D 85 C0 7E ? 45 8B 1B 66 0F 1F 84 00 ? ? ? ? 49 8B C8 48 D1 E9 48 8D 14 8D ? ? ? ? 46 39 1C 12 4A 8D 1C 12 73", SigType::Sig, 0);

	//DEFINE_SIG(ItemInHandRenderer_renderItem_bytepatch, "F3 0F ? ? ? ? ? ? 0F 57 ? F3 0F ? ? ? ? ? ? F3 0F ? ? 0F 2F ? 73 ? F3 41", SigType::Sig, 0);
	// caller = ?onTick@ClientInstance@@QEAAXHH@Z
	DEFINE_SIG(ItemInHandRenderer_renderItem_bytepatch2, "8B 40 ? 89 86 ? ? ? ? 48 8D BE", SigType::Sig, 0); //8
	//DEFINE_SIG(GammaSig, "48 83 EC ? 80 B9 ? ? ? ? ? 48 8D 54 24 ? 48 8B 01 48 8B 40 ? 74 ? 41 B8 ? ? ? ? FF 15 ? ? ? ? 48 8B 10 48 85 D2 74 ? 48 8B 42 ? 48 8B 88 ? ? ? ? 48 85 C9 74 ? E8 ? ? ? ? 48 83 C4 ? C3 F3 0F 10 42 ? 48 83 C4 ? C3 41 B8 ? ? ? ? FF 15 ? ? ? ? 48 8B 10 48 85 D2 75 ? E8 ? ? ? ? CC E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24", SigType::Sig, 0); //8
	//DEFINE_SIG(ZoomSig, "48 8B C4 48 89 58 ? 48 89 70 ? 57 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 44 0F 29 40 ? 44 0F 29 48 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 41 0F B6 F0", SigType::Sig, 0); //8
	///**/DEFINE_SIG(Fistpr, "48 83 EC 28 48 8B 01 48 8D 54 24 30 41 B8 03 00 00 00", SigType::Sig, 0); //its super long i usaing no wl sig
	//DEFINE_SIG(FovHk, "48 8b c4 48 89 58 ? 48 89 70 ? 57 48 81 ec ? ? ? ? 0f 29 70 ? 0f 29 78 ? 44 0f 29 40 ? 44 0f 29 48 ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 44 24 ? 41 0f b6 f0", SigType::Sig, 0);
	//DEFINE_SIG(Try, "48 8B C4 48 89 58 ? 48 89 70 ? 57 48 83 EC ? F3 41 0F 10 40", SigType::Sig, 0);

	DEFINE_SIG(LevelRenderer_renderLevel, "55 41 57 41 56 41 55 41 54 56 57 53 48 81 EC ? ? ? ? 48 8D AC 24 ? ? ? ? 44 0F 29 9D ? ? ? ? 44 0F 29 95 ? ? ? ? 66 44 0F 7F 8D ? ? ? ? 44 0F 29 85 ? ? ? ? 0F 29 BD", SigType::Sig, 0);


	static void initialize();
	static void deinitialize();
};

