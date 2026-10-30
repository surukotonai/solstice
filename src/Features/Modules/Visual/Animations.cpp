//
// Created by vastrakai on 7/18/2024.
//

#include "Animations.hpp"

#include <Features/Events/BaseTickEvent.hpp>
#include <Features/Events/BobHurtEvent.hpp>
#include <Features/Events/BoneRenderEvent.hpp>
#include <Features/Events/SwingDurationEvent.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/MinecraftSim.hpp>
#include <SDK/Minecraft/Actor/ActorPartModel.hpp>
#include <SDK/Minecraft/Inventory/PlayerInventory.hpp>

std::vector<unsigned char> gNoSwitchAnimation = {
    0x0F, 0x57, 0xC0, // xorps xmm0, xmm0
    0x90, 0x90, 0x90, 0x90, 0x90 // nop
};

std::vector<unsigned char> gFluxSwing = {
    0xEB, 0x03, 0x90, 0x90, 0x90
};

DEFINE_PATCH_FUNC(patchNoSwitchAnimation, SigManager::ItemInHandRenderer_render_bytepatch, gNoSwitchAnimation);
DEFINE_PATCH_FUNC(patchFluxSwing, SigManager::FluxSwing, gFluxSwing); //inliend by FUCKING CLANG
//DEFINE_NOP_PATCH_FUNC(patchFluxSwing, SigManager::FluxSwing, 0x5);

void Animations::onEnable()
{
    gFeatureManager->mDispatcher->listen<SwingDurationEvent, &Animations::onSwingDurationEvent>(this);
    gFeatureManager->mDispatcher->listen<BaseTickEvent, &Animations::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->listen<BoneRenderEvent, &Animations::onBoneRenderEvent>(this);
    gFeatureManager->mDispatcher->listen<BobHurtEvent, &Animations::onBobHurtEvent>(this);

    if (!mSwingAngle)
    {
        mSwingAngle = reinterpret_cast<float*>(SigManager::TapSwingAnim);
        MemUtils::setProtection(reinterpret_cast<uintptr_t>(mSwingAngle), sizeof(float), PAGE_READWRITE);
    }

    patchNoSwitchAnimation(mNoSwitchAnimation.mValue);
    patchFluxSwing(mFluxSwing.mValue);
}

void Animations::onDisable()
{
    gFeatureManager->mDispatcher->deafen<SwingDurationEvent, &Animations::onSwingDurationEvent>(this);
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &Animations::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->deafen<BoneRenderEvent, &Animations::onBoneRenderEvent>(this);
    gFeatureManager->mDispatcher->deafen<BobHurtEvent, &Animations::onBobHurtEvent>(this);
    patchNoSwitchAnimation(false);
    patchFluxSwing(false);

    if (mSwingAngle) *mSwingAngle = -80.f; // by rawvalue :joy:
}


void Animations::onBaseTickEvent(BaseTickEvent& event)
{
    auto player = event.mActor;

    patchNoSwitchAnimation(mNoSwitchAnimation.mValue);
    patchFluxSwing(mFluxSwing.mValue);

    if (mOnlyOnBlock.mValue && mSwingAngle)
    {
        if (mShouldBlock)
        {
            *mSwingAngle = mCustomSwingAngle.mValue ? glm::radians(mSwingAngleSetting.as<float>()) : -80.f;
        } else
        {
            *mSwingAngle = -80.f;
        }
    } else if (mSwingAngle)
    {
        *mSwingAngle = mCustomSwingAngle.mValue ? glm::radians(mSwingAngleSetting.as<float>()) : -80.f;
    }


    mOldSwingDuration = mSwingDuration;
    mSwingDuration = player->getSwingProgress();

}

void Animations::onSwingDurationEvent(SwingDurationEvent& event)
{
    event.mSwingDuration = mSwingTime.as<int>();
}

void Animations::onBoneRenderEvent(BoneRenderEvent& event)
{
    if (!mThirdPersonBlock.mValue) return;
    auto ent = event.mActor;
    auto player = ClientInstance::get()->getLocalPlayer();
    if (ent != ClientInstance::get()->getLocalPlayer()) return;

    auto& bones = *event.mBones;
    Bone* bone = nullptr;

    for (auto it = bones.begin(); it != bones.end(); it++) {
        if (it->second.size() == 26) {
            bone = &it->second[19];
        }
    }
    if (!bone) return;
    /*
    for (auto& [a,b] : bones) {
        spdlog::info(b.size());
        for (auto& c : b) {
            spdlog::info(c.mBoneStr);
        }
    }*/
   // auto bone = &firstit->second[19];
    auto partModel = bone->getActorPartModel();

    if (bone->mBoneStr == "rightarm")
    {
        auto heldItem = player->getSupplies()->getContainer()->getItem(player->getSupplies()->mInHandSlot);
        bool isHoldingSword = heldItem && heldItem->getItem() && heldItem->getItem()->isSword();
        if ((!ClientInstance::get()->getMouseGrabbed() && ImGui::IsMouseDown(ImGuiMouseButton_Right) && isHoldingSword || event.mDoBlockAnimation && isHoldingSword) && mAnimation.mValue != Animation::Default)
        {
            float xRot = mXRot.mValue;
            float yRot = mYRot.mValue;
            float zRot = mZRot.mValue;

            Actor* player = ClientInstance::get()->getLocalPlayer();

            if (player->getSwingProgress() > 0) {
                xRot = MathUtils::animate(-30, xRot, ImRenderUtils::getDeltaTime() * 3.f);
                yRot = MathUtils::animate(0, yRot, ImRenderUtils::getDeltaTime() * 3.f);
            }
            else {
                xRot = MathUtils::animate(-65, xRot, ImRenderUtils::getDeltaTime() * 3.f);
                yRot = MathUtils::animate(-17, yRot, ImRenderUtils::getDeltaTime() * 3.f);
            }

            partModel->mRot.x = xRot;
            partModel->mRot.y = yRot;
            partModel->mRot.z = zRot;
            partModel->mSize.z = 0.9177761;
        }
    }
}

void Animations::onBobHurtEvent(BobHurtEvent& event)
{
    auto matrix = event.mMatrix;
    if (mSmallItems.mValue) *matrix = glm::translate(*matrix, glm::vec3(0.5f, -0.2f, -0.6f));

    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return;

    auto heldItem = player->getSupplies()->getContainer()->getItem(player->getSupplies()->mInHandSlot);
    bool isHoldingSword = heldItem && heldItem->getItem() && heldItem->getItem()->isSword();
    if ((!ClientInstance::get()->getMouseGrabbed() && ImGui::IsMouseDown(ImGuiMouseButton_Right) && isHoldingSword || event.mDoBlockAnimation && isHoldingSword) && mAnimation.mValue != Animation::Default)
    {
        mShouldBlock = true;

        *matrix = glm::translate(*matrix, glm::vec3(0.4, 0.0, -0.15));
        *matrix = glm::translate(*matrix, glm::vec3(-0.1f, 0.15f, -0.2f));
        *matrix = glm::translate(*matrix, glm::vec3(-0.24F, 0.25f, -0.20F));
        *matrix = glm::rotate(*matrix, -1.98F, glm::vec3(0.0F, 1.0F, 0.0F));
        *matrix = glm::rotate(*matrix, 1.30F, glm::vec3(4.0F, 0.0F, 0.0F));
        *matrix = glm::rotate(*matrix, 59.9F, glm::vec3(0.0F, 1.0F, 0.0F));
        *matrix = glm::translate(*matrix, glm::vec3(0.0f, -0.1f, 0.15f));
        *matrix = glm::translate(*matrix, glm::vec3(0.08f, 0.0f, 0.0f));
        *matrix = glm::scale(*matrix, glm::vec3(1.05f, 1.05f, 1.05f));
    } else
    {
        mShouldBlock = false;
    }


    if (mAnimation.mValue != Animation::Test) return;

    int swingTime = mSwingTime.as<int>();
    int swingProgress = mSwingDuration;
    int oldSwingProgress = mOldSwingDuration;
    float lerpedSwingProgress = MathUtils::lerp(oldSwingProgress, swingProgress, ClientInstance::get()->getMinecraftSim()->getGameSim()->mDeltaTime);
    float percent = lerpedSwingProgress / swingTime;
    // spdlog::info("swingProgress: {} oldSwingProgress: {} lerpedSwingProgress: {} percent: {}", swingProgress, oldSwingProgress, lerpedSwingProgress, percent);

    // TODO: Take transforms from Java Edition that swing and apply them here (they should work fine for bedrock?)
};