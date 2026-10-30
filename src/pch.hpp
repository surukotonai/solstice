//
// Created by vastrakai on 7/13/2024.
//

#ifndef PCH_HPP
#define PCH_HPP

enum struct EventPriorities {
    ABSOLUTE_FIRST,
    VERY_FIRST,
    FIRST,
    KINDA_FIRST,
    NORMAL,
    KINDA_LAST,
    LAST,
    VERY_LAST,
    ABSOLUTE_LAST,
};
#define NES_PRIORITY_TYPE EventPriorities

#include <corecrt_math_defines.h>
#include <set>
#include <unordered_map>
#include <nes/event_dispatcher.hpp>
#include <Features/FeatureManager.hpp>
#include <future>
#include <iostream>
#include <magic_enum.hpp>
#include <memory>
#include <MinHook.h>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

#include "spdlog/logger.h"
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include <libhat.hpp>

#include <d2d1_3.h>
#include <d3d11.h>
#include <d3d11on12.h>
#include <d3d12.h>
#include <dxgi.h>

#include <dxgi1_4.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

#include <functional>
#include <string>

#include <nlohmann/json.hpp>
#include <Utils/Utils.hpp>
#include <imgui_freetype.h>

#include "SDK/EnttHashs.hpp" //for fucking  entt
#include "SDK/heap_rd.hpp" // for mimalloc

// Luau

#endif //PCH_HPP
