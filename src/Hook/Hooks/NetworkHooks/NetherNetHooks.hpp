#pragma once
//
// Created by surukotonai on 2026
//

#include <Hook/Hook.hpp>

class NetherNetHooks : public Hook {
public:
    NetherNetHooks() : Hook()
    {
        mName = "NetherNetHooks";
    }

    static std::unique_ptr<Detour> mDetour;
    //NetherNetConnector::runEvents
    static void runEvents(void* _this);

    void init() override;
};

