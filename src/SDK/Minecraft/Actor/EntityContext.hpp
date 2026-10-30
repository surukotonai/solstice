#pragma once
//
// Created by vastrakai on 6/28/2024.
//


#include <iomanip>
#include <sstream>
#include <entity/registry.hpp>
#include <libhat.hpp>
#include <Windows.h>
#include <Utils/MemUtils.hpp>

#include "EntityId.hpp"
#include "Components/FlagComponent.hpp"

class EntityRegistry
{
    entt::basic_registry<EntityId>* mRegistry;
};

// this is very silly but i need this as a backup for assures that can't be found using the original method
class SmartAssureFinder
{
public:
    template<typename component_t>
    static void* get()
    {
        uint64_t start = NOW;
        std::span<std::byte> text = hat::process::get_process_module().get_section_data(".text");
        const uintptr_t textb = (uintptr_t)text.data();
        const uintptr_t texte = textb + text.size();

        // Get the assure signature
        std::string typenameStr = typeid(component_t).name();
        std::string symbol = typenameStr;
        for (const char* p : { "struct ", "class ", "enum " }) {
            if (symbol.rfind(p, 0) == 0) {
                symbol.erase(0, std::strlen(p));
                break;
            }
        }

        // Look for this symbol string in Minecraft
        uintptr_t stringLoc = MemUtils::findString(symbol);
        if (stringLoc == 0)
        {
            spdlog::error("Failed to find symbol: {}", symbol);
            return nullptr;
        }

        spdlog::info("symbol: {} found at {}", symbol, MemUtils::getMbMemoryString(stringLoc));

        uintptr_t assureFunc = MemUtils::findReference(stringLoc);
        assureFunc = MemUtils::getTopOfFunction(assureFunc);
        assureFunc = MemUtils::findReference(assureFunc);
        assureFunc = MemUtils::getTopOfFunction(assureFunc);
        static constexpr uint8_t s[16] = {
            0x55,0x56,0x57,0x53,0x48,0x83,0xEC,0x68,
            0x48,0x8D,0x6C,0x24,0x60,0x48,0xC7,0x45
        };
        if (assureFunc == 0 || (assureFunc < textb || assureFunc + sizeof(s) > texte) || std::memcmp(reinterpret_cast<const void*>(assureFunc), s, sizeof(s)) != 0)
        {
            spdlog::error("Failed to find assure function for component: {}", symbol);
            return nullptr;
        }
        spdlog::warn("Smart assure finder found function for component {} at {} [found in {}ms]", typenameStr, MemUtils::getMbMemoryString(assureFunc), NOW - start);
        //ChatUtils::displayClientMessage("Warning: Smart assure finder was used for component: " + symbol);
        return reinterpret_cast<void*>(assureFunc);
    }

    template<typename component_t>
    static void* getForComponent()
    {
        static auto assure = get<component_t>();
        if (assure == nullptr) {
            assure = get<component_t>();
            return nullptr;
        }
        return assure;
    }
};

class OldAssureFinder
{
public:

    template<typename component_t>
    static hat::signature_view getAssureSignature() {
        static const hat::signature sig = []() {
            uint32_t hash = entt::type_hash<component_t>::value();
            const auto* bytes = reinterpret_cast<uint8_t*>(&hash);

            std::stringstream ss;
            ss << "ba";
            for (int i = 0; i < 4; i++) {
                ss << " " << std::setw(2) << std::setfill('0') << std::hex << (0xFF & bytes[i]);
            }

            spdlog::info("assure sig for {}: {} (hash 0x{:08X})", typeid(component_t).name(), ss.str(), hash);

            return hat::parse_signature(ss.str()).value();
            }();
        return sig;
    }

    static hat::signature getAssureSignatureWithHash(uint32_t hash) {
        const auto* bytes = reinterpret_cast<uint8_t*>(&hash);

        std::stringstream ss;
        ss << "ba"; // mov edx, 0xhash

        //Add the hash bytes
        for (int i = 0; i < 4; i++) {
            ss << " " << std::setw(2) << std::setfill('0') << std::hex << (0xFF & bytes[i]);
        }

        return hat::parse_signature(ss.str()).value();
    }



    template<typename component_t>
    static void* getForComponentSub(void* rv)
    {
        uintptr_t result = reinterpret_cast<uintptr_t>(rv);
        std::string componentName = typeid(component_t).name();
        result += 5; // Add 5 to skip the mov edx, 0xhash instruction
        std::span<std::byte> text = hat::process::get_process_module().get_section_data(".text");
        const uintptr_t textb = (uintptr_t)text.data();
        const uintptr_t texte = textb + text.size();

        // Search for the next call instruction
        uint32_t relCallOffset = 0;
        uint64_t assureAddr = 0;
        for (int walked = 0; walked < 0x30; ++walked, ++result) {
            uint8_t byte = *reinterpret_cast<uint8_t*>(result);
            if (byte == 0xCC) break;
            if (byte != 0xE8) continue;

            relCallOffset = *reinterpret_cast<uint32_t*>(result + 1);
            assureAddr = result + 5 + relCallOffset;
            static constexpr uint8_t s[16] = {
                0x55,0x56,0x57,0x53,0x48,0x83,0xEC,0x68,
                0x48,0x8D,0x6C,0x24,0x60,0x48,0xC7,0x45
            };
            if (assureAddr < textb || assureAddr + sizeof(s) > texte) {
                continue;
            }
            if (std::memcmp(reinterpret_cast<const void*>(assureAddr), s, sizeof(s)) != 0) {
                continue;
            }
            spdlog::info("Resolved address for component: {} at {}", componentName, MemUtils::getMbMemoryString(assureAddr));
            return reinterpret_cast<void*>(assureAddr);
        }
        spdlog::critical("Failed to resolve component: {} [no assure prologue]", componentName);
        return nullptr;
        /*
        while (true) {
            uint8_t byte = *reinterpret_cast<uint8_t*>(result);
            if (byte != 0xE8 && byte != 0xCC)
            {
                result += 1;
                continue;
            }

            // If the bytes is 0xE8 then it is a call, so we need to get the offset
            if (byte == 0xE8)
            {
                //Get the offset
                relCallOffset = *reinterpret_cast<uint32_t*>(result + 1);
                assureAddr = result + 5 + relCallOffset;
                std::span<std::byte> text = hat::process::get_process_module().get_section_data(".text");

                // Check if the assure address is divisible by 16
                if (assureAddr % 16 != 0)
                {
                    result += 1;
                    continue;
                }

                // check if the address is in the .text section
                if (assureAddr >= reinterpret_cast<uintptr_t>(text.data()) && assureAddr < reinterpret_cast<uintptr_t>(text.data()) + text.size())
                {
                    break;
                }

                result += 1;
            }

            if (byte == 0xCC)
            {
                // fail
                spdlog::critical("Failed to resolve component: {} [CC]", componentName);
                return nullptr;
            }
        }

        // Log the resolved address
        spdlog::info("Resolved address for component: {} at {}", componentName, MemUtils::getMbMemoryString(assureAddr));
        return reinterpret_cast<void*>(assureAddr);*/
    }

    static void* getForComponentSub2(void* rv)
    {
        uintptr_t result = reinterpret_cast<uintptr_t>(rv);
        result += 5; // Add 5 to skip the mov edx, 0xhash instruction
        std::span<std::byte> text = hat::process::get_process_module().get_section_data(".text");
        const uintptr_t textb = (uintptr_t)text.data();
        const uintptr_t texte = textb + text.size();
        // Search for the next call instruction
        uint32_t relCallOffset = 0;
        uint64_t assureAddr = 0;
        for (int walked = 0; walked < 0x30; ++walked, ++result) {
            uint8_t byte = *reinterpret_cast<uint8_t*>(result);
            if (byte == 0xCC) break;
            if (byte != 0xE8) continue;

            relCallOffset = *reinterpret_cast<uint32_t*>(result + 1);
            assureAddr = result + 5 + relCallOffset;
            static constexpr uint8_t s[16] = {
                0x55,0x56,0x57,0x53,0x48,0x83,0xEC,0x68,
                0x48,0x8D,0x6C,0x24,0x60,0x48,0xC7,0x45
            };
            if (assureAddr < textb || assureAddr + sizeof(s) > texte) {
                continue;
            }
            if (std::memcmp(reinterpret_cast<const void*>(assureAddr), s, sizeof(s)) != 0) {
                continue;
            }
            spdlog::info("Resolved address: at {}", MemUtils::getMbMemoryString(assureAddr));
            return reinterpret_cast<void*>(assureAddr);
        }
        spdlog::critical("Failed to resolve component");
        return nullptr;
        /*
        while (true) {
            uint8_t byte = *reinterpret_cast<uint8_t*>(result);
            if (byte != 0xE8 && byte != 0xCC)
            {
                result += 1;
                continue;
            }

            // If the bytes is 0xE8 then it is a call, so we need to get the offset
            if (byte == 0xE8)
            {
                //Get the offset
                relCallOffset = *reinterpret_cast<uint32_t*>(result + 1);
                assureAddr = result + 5 + relCallOffset;
                std::span<std::byte> text = hat::process::get_process_module().get_section_data(".text");

                // Check if the assure address is divisible by 16
                if (assureAddr % 16 != 0)
                {
                    result += 1;
                    continue;
                }

                // check if the address is in the .text section
                if (assureAddr >= reinterpret_cast<uintptr_t>(text.data()) && assureAddr < reinterpret_cast<uintptr_t>(text.data()) + text.size())
                {
                    break;
                }

                result += 1;
            }

            if (byte == 0xCC)
            {
                // fail
                return nullptr;
            }
        }

        // Log the resolved address
        spdlog::info("Resolved address for component: {} at {}", "unknown", MemUtils::getMbMemoryString(assureAddr));
        return reinterpret_cast<void*>(assureAddr);*/
    }




    template<typename component_t>
    static void* getForComponent()
    {
        hat::signature_view assureSig = getAssureSignature<component_t>();
        std::span<std::byte> modData = hat::process::get_process_module().get_section_data(".text");

        std::string name = "";
#ifdef __DEBUG__
        name = typeid(component_t).name();
#endif

        auto results = hat::find_all_pattern(modData.begin(), modData.end(), assureSig);
        if (results.empty()) {
            spdlog::error("Failed to find assure function for component: {}", name);
            return nullptr;
        }

        spdlog::info("Found {} assure functions for component: {}", results.size(), name);

        void* result = nullptr;
        for (auto& res : results)
        {
            void* prresult = res.get();
            result = getForComponentSub<component_t>(prresult);
            if (result != nullptr) break;
        }


        if (result == nullptr)
        {
            spdlog::error("Failed to resolve component: {}", name);
            return nullptr;
        }
        else {
            spdlog::info("Resolved assure function for component: {} at {}", name, MemUtils::getMbMemoryString(reinterpret_cast<uintptr_t>(result)));
        }
        return result;
    }

    static void* getForComponentWithHash(uint32_t hash)
    {
        hat::signature_view assureSig = getAssureSignatureWithHash(hash);
        std::span<std::byte> modData = hat::process::get_process_module().get_section_data(".text");

        auto results = hat::find_all_pattern(modData.begin(), modData.end(), assureSig);
        if (results.empty()) {
            spdlog::error("Failed to find assure function for component with hash: {}", hash);
            return nullptr;
        }

        spdlog::info("Found {} assure functions for component with hash: {}", results.size(), hash);

        void* result = nullptr;
        for (auto& res : results)
        {
            void* prresult = res.get();
            result = getForComponentSub2(prresult);
            if (result != nullptr) break;
        }

        if (result == nullptr)
        {
            spdlog::error("Failed to resolve component with hash: {}", hash);
            return nullptr;
        }
        else {
            spdlog::info("Resolved assure function for component with hash: {} at {}", hash, MemUtils::getMbMemoryString(reinterpret_cast<uintptr_t>(result)));
        }
        return result;
    }
};

struct EntityContext {
    EntityRegistry* mEntityRegistry;
    entt::basic_registry<EntityId>* mRegistry;
    EntityId mEntityId;

    template <typename T>
    T* getComponent() {
        if (!this->mRegistry) return nullptr;
        if (!this->mRegistry->valid(mEntityId)) return nullptr;
        return const_cast<T*>(mRegistry->try_get<T>(mEntityId));
    }

    template<typename component_t>
    void* resolveAssure() {
        auto result = OldAssureFinder::getForComponent<component_t>();
        if (result == 0) result = SmartAssureFinder::getForComponent<component_t>();

        if (result == 0) {
            spdlog::critical("Failed to resolve component: {}", typeid(component_t).name());
            //MessageBoxA(nullptr, ("Failed to resolve component: " + std::string(typeid(component_t).name()) + ".").c_str(), "Error", MB_OK | MB_ICONERROR);
            return nullptr;
        }

        return reinterpret_cast<void*>(result);
    }

    void* resolveWithHash(uint32_t hash) {
        auto result = OldAssureFinder::getForComponentWithHash(hash);

        if (result == 0) {
            spdlog::critical("Failed to resolve component with hash: {}", hash);
            MessageBoxA(nullptr, ("Failed to resolve component with hash: " + std::to_string(hash) + ".").c_str(), "Error", MB_OK | MB_ICONERROR);
            return nullptr;
        }

        return reinterpret_cast<void*>(result);
    }

    template<typename component_t>
    entt::basic_storage<component_t, EntityId>* assure()
    {
        using assure_t = entt::basic_storage<component_t, EntityId>* (__fastcall*)(entt::basic_registry<EntityId>*, uint32_t);
        static auto assure = reinterpret_cast<assure_t>(resolveAssure<component_t>());
        if (assure == nullptr) {
            assure = reinterpret_cast<assure_t>(resolveAssure<component_t>());
            return nullptr;
        }

        return assure(mRegistry, entt::type_hash<component_t>::value());
    }

    entt::basic_storage<void*, EntityId>* assureWithHash(uint32_t hash)
    {
        using assure_t = entt::basic_storage<void*, EntityId>* (__fastcall*)(entt::basic_registry<EntityId>*, uint32_t);
        static auto assure = reinterpret_cast<assure_t>(resolveWithHash(hash));
        if (assure == nullptr) {
            assure = reinterpret_cast<assure_t>(resolveWithHash(hash));
            return nullptr;
        }

        return assure(mRegistry, hash);
    }

    template<typename component_t>
    auto* assure2(entt::basic_registry<EntityId>* registry)
    {
        using assure_t = entt::basic_storage<component_t, EntityId>* (__fastcall*)(entt::basic_registry<EntityId>*, uint32_t);
        static auto assureFunc = reinterpret_cast<assure_t>(resolveAssure<component_t>());

        return assureFunc(registry, entt::type_hash<component_t>::value());
    }

    template<typename... type_t>
    [[nodiscard]] auto try_get() {
        if constexpr (sizeof...(type_t) == 1u) {
            auto* pool = assure<std::remove_const_t<type_t>...>();
            return (pool && pool->contains(mEntityId)) ? std::addressof(pool->get(mEntityId)) : nullptr;
        }
        else {
            return std::make_tuple(try_get<type_t>(mEntityId)...);
        }
    }
};
