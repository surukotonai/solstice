//
// Created by vastrakai on 6/28/2024.
//

#pragma once

#include <vector>
#include "Packet.hpp"
#include <SDK/Minecraft/MinecraftGame.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>

enum class TextPacketType : unsigned char {
    Raw = 0x0,
    Chat = 0x1,
    Translate = 0x2,
    Popup = 0x3,
    JukeboxPopup = 0x4,
    Tip = 0x5,
    SystemMessage = 0x6,
    Whisper = 0x7,
    Announcement = 0x8,
    TextObjectWhisper = 0x9,
    TextObject = 0xA,
    TextObjectAnnouncement = 0xB,
    null = 255
};


class TextPacket : public Packet { // 1.21.131
public:
    static const PacketID ID = PacketID::Text;

    struct AuthorAndMessage {
        TextPacketType mType;
        std::string mAuthor;
        std::string mMessage;
    };

    struct MessageAndParams {
        TextPacketType mType;
        std::string mMessage;
        std::vector<std::string> mParams;
    };

    struct MessageOnly {
        TextPacketType mType;
        std::string mMessage;
    };

    bool mLocalize;
    std::string mXuid;
    std::string mPlatform;
    std::optional<std::string> mFilteredMessage;
    std::variant<MessageOnly, AuthorAndMessage, MessageAndParams> mBody;


    void Messeage(Actor* player,std::string msgs) {
        
        mLocalize = false;
        mXuid = ClientInstance::get()->getMinecraftGame()->getxuid();
        mBody = AuthorAndMessage{ TextPacketType::Chat ,player->getLocalName(), msgs };
        //Type = TextPacketType::Chat;
        //Source = player->getLocalName();
        //msg = msgs;
       
    }
    
    TextPacketType gettype() {
        switch (mBody.index()) {
        case 0: {
            return std::get<0>(mBody).mType;
        }
        case 1: {
            return std::get<1>(mBody).mType;
        }
        case 2: {
            return std::get<2>(mBody).mType;
        }
        }

        return TextPacketType::null;
    }

    std::string getMessage() {
        switch (mBody.index()) {
        case 0: {
            return std::get<0>(mBody).mMessage;
        }
        case 1: {
            return std::get<1>(mBody).mMessage;
        }
        case 2: {
            return std::get<2>(mBody).mMessage;
        }
        }

        return "";
    }
    std::string getSource()
    {
        if (mBody.index() == 1) {
            return std::get<1>(mBody).mAuthor;
        }
    }
};