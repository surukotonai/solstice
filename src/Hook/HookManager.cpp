//
// Created by vastrakai on 6/25/2024.
//

#include "HookManager.hpp"

#include <MinHook.h>

#include "Hooks/ActorHooks/ActorModelHook.hpp"
#include "Hooks/ActorHooks/AnimationHooks.hpp"
#include "Hooks/ActorHooks/NametagRenderHook.hpp"
#include "Hooks/ContainerHooks/ContainerScreenControllerHook.hpp"
#include "Hooks/MiscHooks/FireBlockChangedHook.hpp"
#include "Hooks/MiscHooks/KeyHook.hpp"
#include "Hooks/MiscHooks/MouseHook.hpp"
#include "Hooks/MiscHooks/PreGameHook.hpp"
#include "Hooks/NetworkHooks/ConnectionRequestHook.hpp"
#include "Hooks/NetworkHooks/PacketReceiveHook.hpp"
#include "Hooks/NetworkHooks/PacketSendHook.hpp"
#include "Hooks/NetworkHooks/RakPeerHooks.hpp"
#include "Hooks/NetworkHooks/NetherNetHooks.hpp"
#include "Hooks/RenderHooks/ActorRenderDispatcherHook.hpp"
#include "Hooks/RenderHooks/D3DHook.hpp"
#include "Hooks/RenderHooks/HoverTextRendererHook.hpp"
#include "Hooks/RenderHooks/ItemRendererHook.hpp"
#include "Hooks/RenderHooks/LookInputHook.hpp"
#include "Hooks/RenderHooks/RenderItemInHandHook.hpp"
#include "Hooks/RenderHooks/SetupShaderParameterHook.hpp"
#include "Hooks/RenderHooks/SetupAndRenderHook.hpp"
#include "Hooks/RenderHooks/LevelRendererHook.hpp"
#include "Hooks/WindowsAPIHooks/WndProcHook.hpp"
#include "Hooks/ClientInstanceHooks/GrabMouseHook.hpp"


#define ADD_HOOK(hook) hooks.emplace_back(std::make_shared<hook>())

void HookManager::init(bool initLp)
{
	if (initLp)
	{
		std::vector<std::shared_ptr<Hook>> hooks;
		ADD_HOOK(BaseTickHook);
		for (auto& hook : hooks)
		{
			hook->init();
			mHooks.emplace_back(hook);
		}
	}
	else
	{
		std::vector<std::shared_ptr<Hook>> hooks;
		//ADD_HOOK(KeyHook);
		ADD_HOOK(SetupAndRenderHook);
		ADD_HOOK(D3DHook);
		ADD_HOOK(ContainerScreenControllerHook);
		ADD_HOOK(MouseHook);
		ADD_HOOK(ConnectionRequestHook);
		ADD_HOOK(PacketReceiveHook);
		ADD_HOOK(PacketSendHook);
		ADD_HOOK(RakPeerHooks);
		//ADD_HOOK(NetherNetHooks); //fucking test
		//ADD_HOOK(ActorRenderDispatcherHook); //die
		ADD_HOOK(AnimationHooks);
		ADD_HOOK(HoverTextRendererHook);
		ADD_HOOK(LookInputHook);
		ADD_HOOK(ActorModelHook);
		ADD_HOOK(ItemRendererHook);
		ADD_HOOK(FireBlockChangedHook);
		//ADD_HOOK(RenderItemInHandHook); //inlined?
		ADD_HOOK(SetupShaderParameterHook);
		ADD_HOOK(PreGameHook);
		ADD_HOOK(NametagRenderHook);
		ADD_HOOK(WndProcHook);
		ADD_HOOK(GrabMouseHook);
		ADD_HOOK(LevelRendererHook);

		

		for (auto& hook : hooks)
		{
			hook->init();
			mHooks.emplace_back(hook);
		}

		MH_EnableHook(MH_ALL_HOOKS);
	}
}

void HookManager::shutdown()
{
	for (auto& hook : mHooks)
	{
		hook->shutdown();
	}

	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	mHooks.clear();
}

