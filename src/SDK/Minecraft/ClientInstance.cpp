//
// Created by vastrakai on 6/24/2024.
//
#define HR

#include "ClientInstance.hpp"

#include <SDK/heap_rd_impl.hpp>

#include <libhat/Access.hpp>
#include <SDK/OffsetProvider.hpp>
#include <SDK/SigManager.hpp>

#include "MinecraftGame.hpp"

#include <Utils/Structs.hpp>

#include "Actor/Actor.hpp"

#include "KeyboardRemappingLayout.hpp"
#include "Rendering/LevelRenderer.hpp"

ClientInstance* ClientInstance::get()
{
	static MinecraftGame* game = MinecraftGame::getInstance();
	if (game == nullptr)
	{
		game = MinecraftGame::getInstance();
		return nullptr;
	}
	static ClientInstance* instance = game->getPrimaryClientInstance();
	if (instance == nullptr) instance = game->getPrimaryClientInstance();
	return instance;
}

glmatrixf ClientInstance::getViewMatrix()
{
	return hat::member_at<glmatrixf>(this, OffsetProvider::ClientInstance_mViewMatrix);
}

glm::vec2 ClientInstance::getFov()
{
	/*
	float x = hat::member_at<float>(this, OffsetProvider::ClientInstance_mFovX); // 0x6F0
	float y = hat::member_at<float>(this, OffsetProvider::ClientInstance_mFovY); // 0x704
	return { x, y };*/
	if (!getLevelRenderer() || !getLevelRenderer()->getRendererPlayer()) {
		return {};
	}

	float* x = getLevelRenderer()->getRendererPlayer()->getFovX();
	float* y = getLevelRenderer()->getRendererPlayer()->getFovY();
	return { *x, *y };
}

MinecraftSim* ClientInstance::getMinecraftSim()
{
	return hat::member_at<MinecraftSim*>(this, OffsetProvider::ClientInstance_mMinecraftSim);
}

LevelRenderer* ClientInstance::getLevelRenderer()
{
	return MemUtils::callVirtualFunc<LevelRenderer*>(OffsetProvider::ClientInstance_getLevelRenderer, this);
	//return hat::member_at<LevelRenderer*>(this, OffsetProvider::ClientInstance_mLevelRenderer);
}

LoopbackPacketSender* ClientInstance::getPacketSender()
{
	return hat::member_at<LoopbackPacketSender*>(this, OffsetProvider::ClientInstance_mPacketSender);
}

GuiData* ClientInstance::getGuiData()
{
	return hat::member_at<GuiData*>(this, OffsetProvider::ClientInstance_mGuiData);
}

bgfx_context* ClientInstance::getBGFX()
{
	return nullptr;
	//return *reinterpret_cast<bgfx_context**>(SigManager::ClientInstance_mBgfx);
}

ClientInputHandler* ClientInstance::getInputHandler()
{
	return MemUtils::callVirtualFunc<ClientInputHandler*>(OffsetProvider::ClientInstance_getInputHandler, this);
}

KeyboardRemappingLayout* ClientInstance::getKeyboardSettings()
{
	return getInputHandler()->getMappingFactory()->getKeyboardRemappingLayout();
}

MinecraftGame* ClientInstance::getMinecraftGame()
{
	return MinecraftGame::getInstance();

}

Actor* ClientInstance::getLocalPlayer()
{
	return MemUtils::callVirtualFunc<Actor*>(OffsetProvider::ClientInstance_getLocalPlayer, this);
}

BlockSource* ClientInstance::getBlockSource()
{
	return MemUtils::callVirtualFunc<BlockSource*>(OffsetProvider::ClientInstance_getBlockSource, this);
}

Options* ClientInstance::getOptions()
{
	return MemUtils::callVirtualFunc<Options*>(OffsetProvider::ClientInstance_getOptions, this);
}

std::string ClientInstance::getPlatformOnlineId()
{
	//return MemUtils::callVirtualFunc<std::string>(144, this);
	using GetPlatformOnlineId_t = void(__fastcall*)(void* clientInstance, std::string* out);
	std::string out;
	auto vf = *reinterpret_cast<uintptr_t**>(this);
	((GetPlatformOnlineId_t)vf[144])(this, &out);
	return out;
}

std::string ClientInstance::getScreenName()
{
	std::string buf{};
	MemUtils::callVirtualFunc<std::string*>(OffsetProvider::ClientInstance_getScreenName, this, &buf);
	return buf;

	/* //fucking abi issue :joy: // im idiot :sob:
	std::string screen = "no_screen";
	MemUtils::callVirtualFunc<std::string*>(OffsetProvider::ClientInstance_getScreenName, this, &screen);
	spdlog::info("size={} cap={} ptr={}", screen.size(), screen.capacity(), screen.data());
	return screen;*/
	/* //shit methot
	std::string screen = "no_screen";
	//sig is better
	static auto sig = SigManager::ClientInstance_getScreenName;
	auto fn = reinterpret_cast<std::string & (__thiscall*)(ClientInstance*, std::string&)>(sig);
	screen = fn(this, screen);
	return screen;*/
}


void ClientInstance::setDisableInput(bool disable)
{
	MemUtils::callVirtualFunc<void>(OffsetProvider::ClientInstance_setDisableInput, this, disable);
}

bool ClientInstance::getMouseGrabbed()
{
	// idk why but the original virtual func's result was inverted
	// so im just gonna recreate that here because i'm too lazy to refactor everything
	return !getMinecraftGame()->getMouseGrabbed();
}

void ClientInstance::grabMouse()
{
	MemUtils::callVirtualFunc<void>(OffsetProvider::ClientInstance_grabMouse, this);
}

void ClientInstance::releaseMouse()
{
	MemUtils::callVirtualFunc<void>(OffsetProvider::ClientInstance_releaseMouse, this);
	getMinecraftGame()->setMouseGrabbed(false);
}

void ClientInstance::playUi(const std::string& soundName, float volume, float pitch)
{   // this is exactly what the game does
	//getMinecraftGame()->playUi(soundName, volume, pitch); // daga kotowaru

	int index = OffsetProvider::ClientInstance_playUi;
	MemUtils::callVirtualFunc<void, const std::string&, float, float>(index, this, soundName, volume, pitch);
}
