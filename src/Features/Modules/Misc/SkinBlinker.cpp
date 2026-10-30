//
// Created by Tozic on 9/16/2024.
//

#include "SkinBlinker.hpp"

#include <Features/Events/BaseTickEvent.hpp>
#include <Features/Events/PacketOutEvent.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Actor/SerializedSkin.hpp>
#include <SDK/Minecraft/Network/LoopbackPacketSender.hpp>
#include <SDK/Minecraft/Network/MinecraftPackets.hpp>
#include <SDK/Minecraft/Network/Packets/PlayerSkinPacket.hpp>

#include "stb_image.h"

void SkinBlinker::onEnable()
{
    gFeatureManager->mDispatcher->listen<BaseTickEvent, &SkinBlinker::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->listen<PacketOutEvent, &SkinBlinker::onPacketOutEvent>(this);
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player)
    {
        return;
    }
    auto currentSkin = player->getSkin();
    if (currentSkin) {
        mId = currentSkin->mId;
        mFullId = currentSkin->mFullId;
    }
}

void SkinBlinker::onDisable()
{
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &SkinBlinker::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->deafen<PacketOutEvent, &SkinBlinker::onPacketOutEvent>(this);
}

struct SkinCapePair
{
    std::vector<unsigned char> skinData;
    int skinWidth;
    int skinHeight;
    int skinDepth;
    bool slimSkin;
    // if cape is null, then the player has no cape
    std::vector<unsigned char> capeData;
    int capeWidth;
    int capeHeight;
    int capeDepth;
};

std::vector<unsigned char> convToRGBA(const std::vector<unsigned char>& data, int& width, int& height, int& depth)
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
        /*rgbaData[i * 4] = imgData[i * 4 + 2];
        rgbaData[i * 4 + 1] = imgData[i * 4 + 1];
        rgbaData[i * 4 + 2] = imgData[i * 4];
        rgbaData[i * 4 + 3] = imgData[i * 4 + 3];*/
        // order: RGB -> BGR
        rgbaData[i * 4] = imgData[i * 4];
        rgbaData[i * 4 + 1] = imgData[i * 4 + 1];
        rgbaData[i * 4 + 2] = imgData[i * 4 + 2];
        rgbaData[i * 4 + 3] = imgData[i * 4 + 3];
    }

    stbi_image_free(imgData);
    return rgbaData;
}

std::unique_ptr<SkinCapePair> getRandSkinCapePair()
{
    std::string skinPath = FileUtils::getSolsticeDir() + "BlinkerSkins\\";
    // capes are suffixed with _cape.png, skins are suffixed with _skin.png
    std::vector<std::string> skinFiles;
    for (const auto& entry : std::filesystem::directory_iterator(skinPath))
    {
        if (entry.path().extension() == ".png" && entry.path().filename().string().find("_skin.png") != std::string::npos)
        {
            skinFiles.push_back(entry.path().string());
        }
    }

    bool slimSkin = false;

    if (skinFiles.empty())
    {
        spdlog::error("No skins found in {}", skinPath);
        return nullptr;
    }

    static int skinIndex = 0;

    // Increment the skin index to get a new skin or reset it if it's out of bounds

    skinIndex++;

    if (skinIndex >= skinFiles.size())
    {
        skinIndex = 0;
    }

    spdlog::info("Using skin file: i: {}, {}", skinIndex, skinFiles[skinIndex]);

    std::string skinFile = skinFiles[skinIndex];
    // if the skin file name ends with slim_skin.png
    // then the player has a slim skin
    if (skinFile.find("slim_skin.png") != std::string::npos)
    {
        spdlog::info("Slim skin detected, using slim geometry");
        slimSkin = true;
    }

    std::string capeFile = skinFile.substr(0, skinFile.find("_skin.png")) + "_cape.png";

    auto skinCapePair = std::make_unique<SkinCapePair>();
    skinCapePair->skinData = FileUtils::readFile(skinFile);
    if (FileUtils::fileExists(capeFile))
    {
        skinCapePair->capeData = FileUtils::readFile(capeFile);
    }

    // use stb_image to get the width, height, and depth of the skin and cape
    // and to convert the image to the correct format
    int skinWidth, skinHeight, skinDepth;
    int capeWidth, capeHeight, capeDepth;
    skinCapePair->skinData = convToRGBA(skinCapePair->skinData, skinWidth, skinHeight, skinDepth);
    if (skinCapePair->skinData.empty())
    {
        spdlog::error("Failed to load skin image from {}", skinFile);
        return nullptr;
    }

    skinCapePair->skinWidth = skinWidth;
    skinCapePair->skinHeight = skinHeight;
    skinCapePair->skinDepth = skinDepth;

    if (!skinCapePair->capeData.empty())
    {
        skinCapePair->capeData = convToRGBA(skinCapePair->capeData, capeWidth, capeHeight, capeDepth);
        if (skinCapePair->capeData.empty())
        {
            spdlog::error("Failed to load cape image from {}", capeFile);
            return nullptr;
        }

        skinCapePair->capeWidth = capeWidth;
        skinCapePair->capeHeight = capeHeight;
        skinCapePair->capeDepth = capeDepth;
    }

    spdlog::info("Using skin name: {} (has cape: {})", skinFile, !skinCapePair->capeData.empty());

    skinCapePair->slimSkin = slimSkin;

    return skinCapePair;
}

// I hate you Tozic.
void SkinBlinker::onBaseTickEvent(BaseTickEvent& event)
{
    if (mLastSkinChange + (mDelay.mValue * 1000) > NOW)
        return;
    static std::unique_ptr<SkinCapePair> skinCapePair = nullptr;


    skinCapePair = getRandSkinCapePair();
    if (skinCapePair == nullptr)
    {
        ChatUtils::displayClientMessage("§cFailed to get random skin and cape pair! Please add skins to the BlinkerSkins folder.");
        return;
    }

    auto player = event.mActor;

    auto currentSkin = player->getSkin();
    mId = currentSkin->mId;
    mFullId = currentSkin->mFullId;

    auto skinpacket = MinecraftPackets::createPacket<PlayerSkinPacket>();
    auto skin = &skinpacket->mSkin.impl->Object;

    skin->mId = mId;
    skin->mFullId = mFullId;

    if (skinCapePair->slimSkin)
    {
        skin->mResourcePatch = "{\n   \"geometry\" : {\n      \"default\" : \"geometry.humanoid.customSlim\"\n   }\n}";
        skin->mDefaultGeometryName = "geometry.humanoid.customSlim";
    }
    else
    {
        skin->mResourcePatch = "{\n   \"geometry\" : {\n      \"default\" : \"geometry.humanoid.custom\"\n   }\n}";
        skin->mDefaultGeometryName = "geometry.humanoid.custom";
    }

    skin->mSkinImage.mImageBytes = mce::Blob::fromVector(skinCapePair->skinData);
    skin->mSkinImage.mWidth = skinCapePair->skinWidth;
    skin->mSkinImage.mHeight = skinCapePair->skinHeight;
    skin->mSkinImage.mDepth = skinCapePair->skinDepth;
    skin->mSkinImage.mUsage = currentSkin->mSkinImage.mUsage;
    skin->mSkinImage.imageFormat = currentSkin->mSkinImage.imageFormat;
    skin->mCapeImage.mImageBytes = mce::Blob::fromVector(skinCapePair->capeData);
    skin->mCapeImage.mWidth = skinCapePair->capeWidth;
    skin->mCapeImage.mHeight = skinCapePair->capeHeight;
    skin->mCapeImage.mDepth = skinCapePair->capeDepth;
    skin->mCapeImage.mUsage = currentSkin->mCapeImage.mUsage;
    skin->mCapeImage.imageFormat = currentSkin->mCapeImage.imageFormat;

    ClientInstance::get()->getPacketSender()->send(skinpacket.get());
}

void SkinBlinker::onPacketOutEvent(PacketOutEvent& event)
{
    if (event.mPacket->getId() == PacketID::PlayerSkin)
    {
        auto packet = event.getPacket<PlayerSkinPacket>();
        spdlog::info("Packet: PlayerSkin, Skin: {}", packet->toString());
        mLastSkinChange = NOW;
    }
}