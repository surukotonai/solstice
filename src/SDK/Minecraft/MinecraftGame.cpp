//
// Created by vastrakai on 6/24/2024.
//

#include "MinecraftGame.hpp"
#include <map>
#include <memory>
#include <libhat/Access.hpp>
#include <SDK/OffsetProvider.hpp>
#include <Utils/MemUtils.hpp>

#include "UWP/BedrockPlatformUWP.hpp"
#include "UWP/MainView.hpp"

#include "ClientInstance.hpp"

MinecraftGame* MinecraftGame::getInstance(){
    static auto minecraftgame = reinterpret_cast<MinecraftGame**>(SigManager::MinecraftGame_instance);
    return *minecraftgame;
    /* // raped
    if (!MainView::getInstance() || !MainView::getInstance()->getBedrockPlatform() || !MainView::getInstance()->getBedrockPlatform()->getMinecraftGame())
        return nullptr;
    return MainView::getInstance()->getBedrockPlatform()->getMinecraftGame();*/
}

ClientInstance* MinecraftGame::getPrimaryClientInstance()
{ 
    using getprimclient = void (*)(void*, void* );

    auto* v = *(void***)((uint8_t*)this + 0x30);
    uint8_t out[24]{};
    reinterpret_cast<getprimclient>(v[7])((uint8_t*)this + 0x30, out);

    auto* ci = *reinterpret_cast<ClientInstance**>(out + 0x10);
    return ci;
    /* i think it was fucked by clang :ultra_retard:
    auto helpme = hat::member_at<std::map<unsigned char, std::shared_ptr<class ClientInstance>>, MinecraftGame>(this, OffsetProvider::MinecraftGame_mClientInstances);

    for (auto& clientInstance : helpme)
    {
        return clientInstance.second.get();
    }

    return nullptr;*/
}

UIProfanityContext* MinecraftGame::getProfanityContext()
{
    return hat::member_at<UIProfanityContext*>(this, OffsetProvider::MinecraftGame_mProfanityContext);
}

bool MinecraftGame::getMouseGrabbed()
{
    return hat::member_at<bool>(this, OffsetProvider::MinecraftGame_mMouseGrabbed);
}

void MinecraftGame::setMouseGrabbed(bool grabbed)
{
    hat::member_at<bool>(this, OffsetProvider::MinecraftGame_mMouseGrabbed) = grabbed;
}
std::string MinecraftGame::getxuid()
{ // why c :retard:
    auto* c = hat::member_at<const char*>(this, OffsetProvider::MinecraftGame_mXuid);
    if (!c) {
        return {};
    }
    auto n = strnlen(c, 64);
    if (n == 0 || n == 64) {
        return {};
    }
    return std::string(c, n);
}

void MinecraftGame::playUi(const std::string& soundName, float volume, float pitch)
{
    ClientInstance::get()->playUi(soundName, volume, pitch);
    /*
    int index = OffsetProvider::MinecraftGame_playUi;
    MemUtils::callVirtualFunc<void, const std::string&, float, float>(index, this, soundName, volume, pitch);*/
}
