//fuck you mimalloc :joy:


#pragma once
#include <windows.h>
#include <cstddef>
#include <atomic>

namespace mr {
    using mallocf = void* (__cdecl*)(std::size_t);
    using freef = void(__cdecl*)(void*);
    using reallocf = void* (__cdecl*)(void*, std::size_t);
    using callocf = void* (__cdecl*)(std::size_t, std::size_t);
    using _aligned_mallocf = void* (__cdecl*)(std::size_t, std::size_t);
    using _aligned_freef = void(__cdecl*)(void*);
    using _strdupf = char* (__cdecl*)(const char*);
    using malloc_usable_sizef = std::size_t(__cdecl*)(const void*);

    inline mallocf mallocp{};
    inline freef freep{};
    inline reallocf reallocp{};
    inline callocf callocp{};
    inline _aligned_mallocf _aligned_mallocp{};
    inline _aligned_freef _aligned_freep{};
    inline _strdupf _strdupp{};
    inline malloc_usable_sizef malloc_usable_sizep{};
    /*make it threadsafe :retarededededeedddedd:*/
    inline std::atomic<int> st{ 0 };


    inline bool ensure() {
        int s = st.load(std::memory_order_acquire);
        if (s == 2) return true;
        if (s == 3) return false;
        int expected = 0;
        if (st.compare_exchange_strong(expected, 1)) {
            HMODULE h = GetModuleHandleW(L"MallocRedirect.dll");
            if (h) {
                mallocp = reinterpret_cast<mallocf>(GetProcAddress(h, "malloc"));
                freep = reinterpret_cast<freef>(GetProcAddress(h, "free"));
                reallocp = reinterpret_cast<reallocf>(GetProcAddress(h, "realloc"));
                callocp = reinterpret_cast<callocf>(GetProcAddress(h, "calloc"));
                _aligned_mallocp = reinterpret_cast<_aligned_mallocf>(GetProcAddress(h, "_aligned_malloc"));
                _aligned_freep = reinterpret_cast<_aligned_freef>(GetProcAddress(h, "_aligned_free"));
                _strdupp = reinterpret_cast<_strdupf>(GetProcAddress(h, "_strdup"));
                malloc_usable_sizep = reinterpret_cast<malloc_usable_sizef>(GetProcAddress(h, "malloc_usable_size"));
            }
            st.store((mallocp && freep) ? 2 : 3, std::memory_order_release);
            return st.load() == 2;
        }
        while (st.load(std::memory_order_acquire) == 1) YieldProcessor();
        return st.load() == 2;
    }
}