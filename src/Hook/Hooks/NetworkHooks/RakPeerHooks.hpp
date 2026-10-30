#pragma once
//
// Created by vastrakai on 7/10/2024.
//

#include <Hook/Hook.hpp>

class RakPeerHooks : public Hook {
public:
    RakPeerHooks() : Hook()
    {
        mName = "RakPeerHooks";
    }

    static std::unique_ptr<Detour> RunUpdateCycleDetour;
    static std::unique_ptr<Detour> GetLastPingDetour;
    static std::unique_ptr<Detour> SendImmediateDetour;

    inline static bool israknetalive = false;

    static float LastPing;

    static bool runUpdateCycle(void* _this, void* a2);
    static __int64 getLastPing(void* _this, void* a2);
    static uint64_t sendImmediate(uint64_t a1, char* send, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5, uint64_t a6, uint64_t a7, uint64_t a8, uint64_t a9, uint64_t a10);
    static void init(uintptr_t addr);

    void init() override;
    void shutdown();
};

