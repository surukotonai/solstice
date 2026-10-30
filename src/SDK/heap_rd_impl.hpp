#pragma once
#include <cstddef>

inline void* al(std::size_t n) {
    if (mr::ensure()) {
        return mr::mallocp(n ? n : 1);
    }
    else {
        return HeapAlloc(GetProcessHeap(), 0, n ? n : 1);
    }
}
inline void delc(void* p) {
    if (!p) {
        return;
    }
    if (mr::ensure()) {
        mr::freep(p);
    }
    else {
        HeapFree(GetProcessHeap(), 0, p);
    }
}

void* operator new(std::size_t n) { return al(n); }
void* operator new[](std::size_t n) { return al(n); }
void operator delete(void* p) noexcept { delc(p); }
void operator delete[](void* p) noexcept { delc(p); }
void operator delete(void* p, std::size_t) noexcept { delc(p); }
void operator delete[](void* p, std::size_t) noexcept { delc(p); }