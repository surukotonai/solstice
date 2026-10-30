//
// Created by vastrakai on 8/31/2024.
//

#include "SkinStealer.hpp"

#include <Features/Events/BaseTickEvent.hpp>
#include <SDK/Minecraft/Actor/SerializedSkin.hpp>
#include <SDK/Minecraft/World/HitResult.hpp>
#include <SDK/Minecraft/World/Level.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Network/MinecraftPackets.hpp>
#include <SDK/Minecraft/Network/LoopbackPacketSender.hpp>
#include <SDK/Minecraft/Network/Packets/PlayerSkinPacket.hpp>
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#include <Utils/stb_image_write.h>
#include "stb_image.h"

std::vector<uint8_t> SkinStealer::convToPng(const std::vector<uint8_t>& data, int width, int height)
{
    std::vector<uint8_t> pngData;

    // Callback function to store the PNG data in a vector
    auto writeToVector = [](void* context, void* data, int size) {
        std::vector<uint8_t>* pngData = static_cast<std::vector<uint8_t>*>(context);
        pngData->insert(pngData->end(), (uint8_t*)data, (uint8_t*)data + size);
    };

    // Convert the raw RGBA data to PNG format and store it in the vector
    if (stbi_write_png_to_func(writeToVector, &pngData, width, height, 4, data.data(), width * 4) == 0) {
        // Handle error: PNG conversion failed
        return {};
    }

    return pngData;
}

std::vector<unsigned char> converToRGBA(const std::vector<unsigned char>& data, int& width, int& height, int& depth)
{
    unsigned char* imgData = stbi_load_from_memory(data.data(), data.size(), &width, &height, &depth, 4);
    if (imgData == nullptr)
    {
        spdlog::error("Failed to load image from memory");
        return {};
    }

    std::vector<unsigned char> rgbaData(width * height * 4);
    for (int i = 0; i < width * height; i++)
    {
        rgbaData[i * 4] = imgData[i * 4];
        rgbaData[i * 4 + 1] = imgData[i * 4 + 1];
        rgbaData[i * 4 + 2] = imgData[i * 4 + 2];
        rgbaData[i * 4 + 3] = imgData[i * 4 + 3];
    }

    stbi_image_free(imgData);
    return rgbaData;
}

void SkinStealer::onEnable()
{
    gFeatureManager->mDispatcher->listen<BaseTickEvent, &SkinStealer::onBaseTickEvent>(this);
}

void SkinStealer::onDisable()
{
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &SkinStealer::onBaseTickEvent>(this);
}

void SkinStealer::onBaseTickEvent(BaseTickEvent& event)
{
    auto player = event.mActor;
    if (!player) return;

    EntityId targetId = player->getLevel()->getHitResult()->mEntity.id;

    Actor* targeted = nullptr;
    for (auto actor : ActorUtils::getActorList())
    {
        if (actor->mContext.mEntityId == targetId)
        {
            targeted = actor;
            break;
        }
    }

    bool rightClick = ImGui::IsMouseDown(1);
    static bool lastRightClick = false;

    if (rightClick && !lastRightClick && targeted && targeted->isPlayer())
    {
        saveSkin(targeted);
    }

    lastRightClick = rightClick;
}

void SkinStealer::saveSkin(Actor* actor)
{
    auto skin = actor->getSkin();
    if (!skin) return;

    const uint8_t* skinData = skin->mSkinImage.mImageBytes.data();
    int width = skin->mSkinImage.mWidth;
    int height = skin->mSkinImage.mHeight;
    int bytes = width * height * 4;
    std::vector<uint8_t> pngData = convToPng(std::vector<uint8_t>(skinData, skinData + bytes), width, height);
    if (pngData.empty()) return;

    std::string path = FileUtils::getSolsticeDir() + "Skins\\" + actor->getRawName() + "_skin.png";
    std::ofstream file(path, std::ios::binary);
    file.write((char*)pngData.data(), pngData.size());
    file.close();

    const uint8_t* capeData = skin->mCapeImage.mImageBytes.data();
    int capeWidth = skin->mCapeImage.mWidth;
    int capeHeight = skin->mCapeImage.mHeight;
    int capeBytes = capeWidth * capeHeight * 4;

    std::vector<uint8_t> capePngData;
    if (capeBytes > 0) {
        capePngData = convToPng(std::vector<uint8_t>(capeData, capeData + capeBytes), capeWidth, capeHeight);
        if (!capePngData.empty()) {
            path = FileUtils::getSolsticeDir() + "Skins\\" + actor->getRawName() + "_cape.png";
            std::ofstream capeFile(path, std::ios::binary);
            capeFile.write((char*)capePngData.data(), capePngData.size());
            capeFile.close();
        }
    } else {
        ChatUtils::displayClientMessage("No cape found for " + actor->getRawName());
    }

    ChatUtils::displayClientMessage("Saved skin for " + actor->getRawName() + " to your Solstice\\Skins folder! (copied to clipboard)");
    ImGui::SetClipboardText(std::string(FileUtils::getSolsticeDir() + "Skins\\").c_str());

    std::string resourcePatch = skin->mResourcePatch;
    if (mApplySkin) applySkin(actor, pngData, capePngData, capeWidth, capeHeight, resourcePatch);
}

void SkinStealer::applySkin(Actor* actor, const std::vector<uint8_t>& skinData, const std::vector<uint8_t>& capeData, int capeWidth, int capeHeight, const std::string& resourcePatch)
{
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return;

    auto currentSkin = player->getSkin();
    if (!currentSkin) return;

    auto skinPacket = MinecraftPackets::createPacket<PlayerSkinPacket>();
    auto skin = &skinPacket->mSkin.impl->Object;
    skin->mId = currentSkin->mId;
    skin->mFullId = currentSkin->mFullId;

    std::string defaultGeometry;
    bool isSlim = false;

    if (resourcePatch.empty()) return;

    try {
        nlohmann::json resourcePatchJson = nlohmann::json::parse(resourcePatch);
        if (resourcePatchJson.contains("geometry") && resourcePatchJson["geometry"].contains("default")) {
            defaultGeometry = resourcePatchJson["geometry"]["default"];
            if (defaultGeometry == "geometry.humanoid.customSlim") {
                isSlim = true;
            } else if (defaultGeometry != "geometry.humanoid.custom") {
                ChatUtils::displayClientMessage("§cCannot apply skin due to geometry.");
                return;
            }
        } else {
            return; // Return if no geometry found
        }
    } catch (const std::exception&) {
        return;
    }

    skin->mResourcePatch = std::string("{\"geometry\": {\"default\": \"") + (isSlim ? "geometry.humanoid.customSlim" : "geometry.humanoid.custom") + "\"}}";
    skin->mDefaultGeometryName = isSlim ? "geometry.humanoid.customSlim" : "geometry.humanoid.custom";

    int width, height, depth;
    std::vector<unsigned char> skinImage = converToRGBA(skinData, width, height, depth);
    skin->mSkinImage.mImageBytes = mce::Blob::fromVector(skinImage);
    skin->mSkinImage.mWidth = width;
    skin->mSkinImage.mHeight = height;
    skin->mSkinImage.mDepth = 4;

    if (!capeData.empty()) {
        std::vector<unsigned char> capeImage = converToRGBA(capeData, capeWidth, capeHeight, depth);
        skin->mCapeImage.mImageBytes = mce::Blob::fromVector(capeImage);
        skin->mCapeImage.mWidth = capeWidth;
        skin->mCapeImage.mHeight = capeHeight;
        skin->mCapeImage.mDepth = 4;
    }

    ClientInstance::get()->getPacketSender()->send(skinPacket.get());
    ChatUtils::displayClientMessage("§aSuccessfully applied the stolen skin from §b" + actor->getRawName() + "§a.");
}