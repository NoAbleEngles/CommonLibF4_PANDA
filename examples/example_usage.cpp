#include <F4SE/F4SE.h>
#include "REL/Version.h"
#include "RE/RTTI_IDs_Versioned.h"
#include "RE/VTABLE_IDs_Versioned.h"
#include "RE/Bethesda/MemoryManager.h"

// Example 1: Using version-aware IDs in class definitions
class MyMemoryStore : public RE::IMemoryStore
{
public:
    // Automatically uses correct RTTI/VTABLE based on compile-time version
    static constexpr auto RTTI = RE::RTTI::IMemoryStore;
    static constexpr auto VTABLE = RE::VTABLE::IMemoryStore;

    // Your implementation...
};

// Example 2: Version-specific logic
void InitializeMemorySystem()
{
    if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) {
        F4SE::log::info("Initializing for Fallout 4 VR");
        // VR-specific initialization
    } else {
        F4SE::log::info("Initializing for Fallout 4 AE");
        // AE-specific initialization
    }

    // Use version-aware ID with Relocation
    REL::Relocation<RE::MemoryManager*> memManager{ RE::RTTI::MemoryManager };

    // All subsequent code works identically regardless of version
    auto& manager = RE::MemoryManager::GetSingleton();
    void* ptr = manager.Allocate(1024, 16, true);
    // ...
}

// Example 3: Conditional compilation for different versions
template<typename T>
void* AllocateTyped()
{
    auto& mem = RE::MemoryManager::GetSingleton();

    if constexpr (alignof(T) > 8) {
        // Use aligned allocation
        return mem.Allocate(sizeof(T), alignof(T), true);
    } else {
        // Regular allocation
        return mem.Allocate(sizeof(T), 0, false);
    }
}

// Example 4: Function hooking with version-aware IDs
class MemoryHooks
{
public:
    static void Install()
    {
        // Hook allocate function - ID automatically selected based on version
        REL::Relocation<decltype(&HookAllocate)> allocateFunc{ 
            REL_ID_VER(652767, 698123)  // VR ID, AE ID
        };

        auto& trampoline = F4SE::GetTrampoline();
        trampoline.write_call<5>(allocateFunc.address(), &HookAllocate);

        F4SE::log::info("Memory hooks installed for game version: {}",
            REL::GAME_VERSION == REL::GameVersion::VR ? "VR" : "AE");
    }

private:
    static void* HookAllocate(RE::MemoryManager* manager, 
                              std::size_t size, 
                              std::uint32_t alignment, 
                              bool required)
    {
        F4SE::log::trace("Allocating {} bytes with alignment {}", size, alignment);

        // Call original
        using func_t = decltype(&HookAllocate);
        REL::Relocation<func_t> func{ REL_ID_VER(652767, 698123) };
        return func(manager, size, alignment, required);
    }
};

// Example 5: RTTI type checking with version-aware IDs
bool IsMemoryHeap(const void* obj)
{
    // RTTI check - works with correct ID for current version
    const auto rtti = RE::RTTI::IMemoryHeap;

    // Your RTTI checking logic here
    // ...

    return false;
}

// Plugin entry point
F4SEPluginLoad(const F4SE::LoadInterface* f4se)
{
    F4SE::Init(f4se);

    // Log which version we're running on
    F4SE::log::info("Plugin compiled for: {}",
        REL::GAME_VERSION == REL::GameVersion::VR ? 
        "Fallout 4 VR" : "Fallout 4 AE/Standard");

    // Initialize hooks
    MemoryHooks::Install();

    return true;
}
