#include "NetherNetHooks.hpp"

#include <Solstice.hpp>
#include <windows.h>
#include <Features/FeatureManager.hpp>
#include <SDK/SigManager.hpp>
#include <Features/Events/RunUpdateCycleEvent.hpp>

#include <SDK/Minecraft/ClientInstance.hpp>

std::unique_ptr<Detour> NetherNetHooks::mDetour;

void NetherNetHooks::runEvents(void* _this)
{
    auto original = mDetour->getOriginal<&runEvents>();
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return original(_this);

    auto holder = nes::make_holder<RunUpdateCycleEvent>();
    gFeatureManager->mDispatcher->trigger(holder);
    if (holder->isCancelled())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return;
    }

    return original(_this);
}


void NetherNetHooks::init()
{
    mDetour = std::make_unique<Detour>("NetherNetConnector::runEvents", reinterpret_cast<void*>(SigManager::NetherNetConnector_runEvents), &runEvents);
}
