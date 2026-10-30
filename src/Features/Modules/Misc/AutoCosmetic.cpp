//
// Created by vastrakai on 8/23/2024.
//

#include "AutoCosmetic.hpp"

#include <Features/Events/BaseTickEvent.hpp>
#include <Features/Events/PacketInEvent.hpp>
#include <Features/Events/PacketOutEvent.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Inventory/PlayerInventory.hpp>
#include <SDK/Minecraft/Network/LoopbackPacketSender.hpp>
#include <SDK/Minecraft/Network/MinecraftPackets.hpp>
#include <SDK/Minecraft/Network/Packets/ModalFormResponsePacket.hpp>
#include <SDK/Minecraft/Network/Packets/PlaySoundPacket.hpp>
#include <Features/Modules/Misc/AutoVote.hpp>

void AutoCosmetic::onEnable()
{
    gFeatureManager->mDispatcher->listen<PacketInEvent, &AutoCosmetic::onPacketInEvent>(this);
    gFeatureManager->mDispatcher->listen<PacketOutEvent, &AutoCosmetic::onPacketOutEvent>(this);
    gFeatureManager->mDispatcher->listen<BaseTickEvent, &AutoCosmetic::onBaseTickEvent>(this);
}

void AutoCosmetic::onDisable()
{
    gFeatureManager->mDispatcher->deafen<PacketInEvent, &AutoCosmetic::onPacketInEvent>(this);
    gFeatureManager->mDispatcher->deafen<PacketOutEvent, &AutoCosmetic::onPacketOutEvent>(this);
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &AutoCosmetic::onBaseTickEvent>(this);
}

void AutoCosmetic::submitForm(int buttonId)
{
    auto packet = MinecraftPackets::createPacket<ModalFormResponsePacket>();
    packet->mFormId = mLastFormId;
    MinecraftJson::Value json;
    json.mType = MinecraftJson::ValueType::Int;
    json.mValue.mInt = buttonId;
    packet->mJSONResponse = json;

    // Get the assoc button text
    auto jsonObj = nlohmann::json::parse(mJson);
    try
    {
        std::string buttonText = jsonObj["buttons"][buttonId]["text"];
        spdlog::info("Submitting form with button {}", buttonText);
    } catch (std::exception& e)
    {
        spdlog::error("Failed to get button text: {}", e.what());
    }

    ClientInstance::get()->getPacketSender()->send(packet.get());
}

void AutoCosmetic::closeForm()
{
    auto packet = MinecraftPackets::createPacket<ModalFormResponsePacket>();
    packet->mFormId = mLastFormId;
    packet->mFormCancelReason = ModalFormCancelReason::UserClosed;
    ClientInstance::get()->getPacketSender()->send(packet.get());
}

void AutoCosmetic::onBaseTickEvent(BaseTickEvent& event)
{
    auto player = event.mActor;
    int lockerItem = -1;
    for (int i = 0; i < 9; i++) {
        auto item = player->getSupplies()->getContainer()->getItem(i);
        if (!item->getItem()) continue;
        if (StringUtils::containsIgnoreCase(ColorUtils::removeColorCodes(item->getCustomName()), "Your Locker [Use]")) {
            lockerItem = i;
            break;
        }
    }
    return;
    if (lockerItem == -1)
    {
        if (!mFinishedApplying)
        {
            mFinishedApplying = true;
            spdlog::info("[AutoCosmetic] Locker item not found, finished applying cosmetics");
        }

        return;
    }

    uint64_t timeSinceLastForm = NOW - mLastFormTime;
    if (timeSinceLastForm < mUiDelay.mValue && !mHasFormOpen) return;
    if (!mHasFormOpen && !mFinishedApplying && !mInteractedWithItem)
    {
        // Interact with the locker item
        player->getSupplies()->getContainer()->startUsingItem(lockerItem);
        player->getSupplies()->getContainer()->releaseUsingItem(lockerItem);
        spdlog::info("[AutoCosmetic] Interacting with locker item");
        mInteractedWithItem = true;
    }

    auto autoVote = gFeatureManager->mModuleManager->getModule<AutoVote>();
    if (!mHasFormOpen || mFinishedApplying || !mIsCosmeticMenu || !autoVote->mVotedThisDimension) return;

    auto jsonObj = nlohmann::json::parse(mJson);
    if (!jsonObj.contains("buttons")) return;

    std::string content = jsonObj.contains("content") ? jsonObj["content"] : "";
    bool isMainMenu = StringUtils::containsIgnoreCase(content, "Welcome to your locker!");

    if (isMainMenu)
    {
        int maxCosmeticIndex = jsonObj["buttons"].size() - 1;
        if (mCosmeticIndex > maxCosmeticIndex) {
            mCosmeticIndex = 0;
            mFinishedApplying = true;
            closeForm();
            spdlog::info("[AutoCosmetic] Finished applying cosmetics");
            ChatUtils::displayClientMessage("Finished applying cosmetics");
            return;
        }

        submitForm(mCosmeticIndex);
        spdlog::info("[AutoCosmetic] Opening cosmetic {}", mCosmeticIndex);
        mCosmeticIndex++;
        return;
    }

    std::vector<int> unlockedCosmeticButtons;

    for (int i = 0; i < jsonObj["buttons"].size(); i++) {
        std::string buttonText = jsonObj["buttons"][i]["text"];

        if (StringUtils::containsIgnoreCase(buttonText, "§8§l")) continue;
        if (StringUtils::containsIgnoreCase(buttonText, "Back to Locker")) continue;
        unlockedCosmeticButtons.push_back(i);
    }

    // get the highest unlocked cosmetic and apply it
    if (!unlockedCosmeticButtons.empty()) {
        int highestUnlockedCosmetic = unlockedCosmeticButtons[unlockedCosmeticButtons.size() - 1];
        submitForm(highestUnlockedCosmetic);
        std::string buttonText = ColorUtils::removeColorCodes(jsonObj["buttons"][highestUnlockedCosmetic]["text"]);
        // if a newline is present, only display the first line
        if (buttonText.find("\n") != std::string::npos) buttonText = buttonText.substr(0, buttonText.find("\n"));
        spdlog::info("[AutoCosmetic] Applying cosmetic: {}, title: {}", buttonText, mLastFormTitle);
        std::string title = ColorUtils::removeColorCodes(mLastFormTitle);
        if (title.find("\n") != std::string::npos) title = title.substr(0, title.find("\n"));
        if (mDebug.mValue) ChatUtils::displayClientMessage("[" + std::to_string(mCosmeticIndex) + "] Applying cosmetic: " + buttonText + " for " + title);
    } else
    {
        closeForm();
        std::string title = ColorUtils::removeColorCodes(mLastFormTitle);
        if (title.find("\n") != std::string::npos) title = title.substr(0, title.find("\n"));
        spdlog::info("[AutoCosmetic] No cosmetics to apply for {}", title);
        if (mDebug.mValue) ChatUtils::displayClientMessage("No cosmetics to apply for " + title);
    }
}

void AutoCosmetic::onPacketInEvent(PacketInEvent& event)
{
    return;
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return;

    if (event.mPacket->getId() == PacketID::PlaySound)
    {
        auto packet = event.getPacket<PlaySoundPacket>();
        if (packet->mName == "random.pop2")
        {
            // cancel if a form was open in the last second
            if (NOW - mLastFormTime < 1000)
            {
                event.cancel();
            }
        }
    };

    if (event.mPacket->getId() == PacketID::ModalFormRequest) {
        int lockerItem = -1;
        for (int i = 0; i < 9; i++) {
            auto item = player->getSupplies()->getContainer()->getItem(i);
            if (!item->getItem()) continue;
            if (StringUtils::containsIgnoreCase(ColorUtils::removeColorCodes(item->getCustomName()), "Your Locker [Use]")) {
                lockerItem = i;
                break;
            }
        }

        // If the locker item is not in the hotbar, don't cancel the form
        if (lockerItem == -1 || mFinishedApplying) return;

        auto packet = event.getPacket<ModalFormRequestPacket>();
        nlohmann::json json = nlohmann::json::parse(packet->mJSON);
        std::string jsonStr = json.dump(4);
        mJson = packet->mJSON;
        mLastFormTime = NOW;
        mLastFormId = packet->mFormId;
        mHasFormOpen = true;

        std::string type = json.contains("type") ? json["type"] : "";
        std::string title = json.contains("title") ? json["title"] : "";

        if (type == "form" && StringUtils::containsIgnoreCase(title, "your") && StringUtils::containsIgnoreCase(title, "locker")) {
            mIsCosmeticMenu = true;
            event.cancel();
        } else
        {
            // if the form contains a Back to Locker button, cancel it
            if (json.contains("buttons")) {
                for (const auto& button : json["buttons"]) {
                    if (button.contains("text") && StringUtils::containsIgnoreCase(button["text"], "Back to Locker")) {
                        event.cancel();
                        mIsCosmeticMenu = true;
                        break;
                    }
                }
            }
        }

        if (json.contains("title")) {
            mLastFormTitle = json["title"];
        } else {
            mLastFormTitle = "Unknown";
        }

        spdlog::info("Form ID {} with title {} was opened", mLastFormId, mLastFormTitle);
    }

    if (event.mPacket->getId() == PacketID::ChangeDimension)
    {
        mFinishedApplying = false;
    }
}

void AutoCosmetic::onPacketOutEvent(PacketOutEvent& event)
{
    return;
    if (event.mPacket->getId() == PacketID::ModalFormResponse) {
        auto packet = event.getPacket<ModalFormResponsePacket>();
        mLastFormTime = NOW;
        if (packet->mFormId == mLastFormId) {
            mHasFormOpen = false;
            int buttonId = -1;
            if (packet->mJSONResponse.has_value() && packet->mJSONResponse.value().mType == MinecraftJson::ValueType::Int) {
                buttonId = packet->mJSONResponse.value().mValue.mInt;
            }
            spdlog::info("Form ID {} was closed [button {}]", mLastFormId, buttonId);
        }
        mInteractedWithItem = false;
    }

}

