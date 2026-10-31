//
// Created by vastrakai on 7/18/2024.
//

#include "AnimationHooks.hpp"

#include <Features/Events/SwingDurationEvent.hpp>
#include <Features/Events/BobHurtEvent.hpp>


#include <SDK/Minecraft/ClientInstance.hpp>

std::unique_ptr<Detour> AnimationHooks::mSwingDetour;
std::unique_ptr<Detour> AnimationHooks::mBobHurtDetour;

int AnimationHooks::getCurrentSwingDuration(Actor* actor)
{
    auto original = mSwingDetour->getOriginal<&getCurrentSwingDuration>();
    int result = original(actor);

    auto holder = nes::make_holder<SwingDurationEvent>(result);
    gFeatureManager->mDispatcher->trigger(holder);
    result = holder->mSwingDuration;

    return result;
}

void* AnimationHooks::doBobHurt(void* _this, glm::mat4* matrix)
{
    auto original = mBobHurtDetour->getOriginal<&doBobHurt>();
    // Log the address of the matrix
    auto result = original(_this, matrix);

    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return result;


    auto holder = nes::make_holder<BobHurtEvent>(_this, matrix);
    gFeatureManager->mDispatcher->trigger(holder);

    return result;
}

void AnimationHooks::init()
{
    uintptr_t func = SigManager::Mob_getCurrentSwingDuration;
    mSwingDetour = std::make_unique<Detour>("Mob::getCurrentSwingDuration", reinterpret_cast<void*>(func), &getCurrentSwingDuration);

    // TODO: Replace this with a better method of doing matrix translation
    func = SigManager::BobHurt;
    mBobHurtDetour = std::make_unique<Detour>("bobHurt", reinterpret_cast<void*>(func), &doBobHurt);
}
