#pragma once

// Example: How to update your MemoryManager.h to use version-aware IDs

// 1. Include version system
#include "REL/Version.h"
#include "RE/RTTI_IDs_Versioned.h"
#include "RE/VTABLE_IDs_Versioned.h"

namespace RE
{
    // First, define version-aware IDs in RTTI_IDs_Versioned.h:
    /*
    namespace RTTI
    {
        // Source: RTTI dump VR 1.2.72.0 / AE 1.10.163.0
        inline constexpr auto IMemoryStoreBase = REL_ID_VER(892595, 923456);
        inline constexpr auto IMemoryStore = REL_ID_VER(892596, 923457);
        inline constexpr auto IMemoryHeap = REL_ID_VER(892597, 923458);
        inline constexpr auto ScrapHeap = REL_ID_VER(892598, 923459);
    }

    namespace VTABLE
    {
        // Source: VTABLE dump VR 1.2.72.0 / AE 1.10.163.0
        inline constexpr auto IMemoryStoreBase = REL_ID_VER(892595, 923456);
        inline constexpr auto IMemoryStore = REL_ID_VER(892596, 923457);
        inline constexpr auto IMemoryHeap = REL_ID_VER(892597, 923458);
        inline constexpr auto ScrapHeap = REL_ID_VER(892598, 923459);
    }
    */

    // Then use them in your classes:
    class __declspec(novtable) IMemoryStoreBase
    {
    public:
        // OLD WAY (version-specific at compile time, but unclear):
        // static constexpr auto RTTI{ RTTI::IMemoryStoreBase };
        // static constexpr auto VTABLE{ VTABLE::IMemoryStoreBase };

        // NEW WAY (explicit version awareness):
        static constexpr auto RTTI = RE::RTTI::IMemoryStoreBase;
        static constexpr auto VTABLE = RE::VTABLE::IMemoryStoreBase;

        virtual ~IMemoryStoreBase() = default;

        virtual std::size_t Size(void const* a_mem) const = 0;
        virtual void GetMemoryStats(MemoryStats* a_stats) = 0;
        virtual bool ContainsBlockImpl(const void* a_block) const = 0;
    };
    static_assert(sizeof(IMemoryStoreBase) == 0x8);

    class __declspec(novtable) IMemoryStore :
        public IMemoryStoreBase
    {
    public:
        static constexpr auto RTTI = RE::RTTI::IMemoryStore;
        static constexpr auto VTABLE = RE::VTABLE::IMemoryStore;

        virtual ~IMemoryStore() = default;

        virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;
        virtual void DeallocateAlignImpl(void*& a_block) = 0;
        virtual void* TryAllocateImpl([[maybe_unused]] std::size_t a_size, 
                                      [[maybe_unused]] std::uint32_t a_alignment) { 
            return nullptr; 
        }
    };
    static_assert(sizeof(IMemoryStore) == 0x8);

    class __declspec(novtable) IMemoryHeap :
        public IMemoryStore
    {
    public:
        static constexpr auto RTTI = RE::RTTI::IMemoryHeap;
        static constexpr auto VTABLE = RE::VTABLE::IMemoryHeap;

        virtual ~IMemoryHeap() = default;

        bool ContainsBlockImpl(const void* a_block) const override { 
            return PointerInHeap(a_block); 
        }

        void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override { 
            return Allocate(a_size, a_alignment); 
        }

        void DeallocateAlignImpl(void*& a_block) override { 
            Deallocate(a_block, 0); 
        }

        virtual const char* GetName() const = 0;
        virtual void* Allocate(std::size_t a_size, std::uint32_t a_alignment) = 0;
        virtual void Deallocate(void* a_mem, std::uint32_t) = 0;
        virtual bool PointerInHeap(const void* a_pointer) const = 0;
        virtual std::size_t TotalSize(const void* a_pointer) const = 0;
        virtual void GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) = 0;
        virtual bool ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) = 0;
        virtual std::uint32_t GetPageSize() const = 0;
    };
    static_assert(sizeof(IMemoryHeap) == 0x8);

    class __declspec(novtable) ScrapHeap :
        public IMemoryStore
    {
    public:
        static constexpr auto RTTI = RE::RTTI::ScrapHeap;
        static constexpr auto VTABLE = RE::VTABLE::ScrapHeap;

        // ... rest of implementation
    };

    // Example: Version-specific function IDs
    class MemoryManager
    {
    public:
        [[nodiscard]] static MemoryManager& GetSingleton()
        {
            using func_t = decltype(&MemoryManager::GetSingleton);

            // Version-aware function ID
            const REL::Relocation<func_t> func{ 
                REL_ID_VER(343176, 398765)  // VR ID, AE ID
            };
            return func();
        }

        [[nodiscard]] void* Allocate(std::size_t a_size, 
                                      std::uint32_t a_alignment, 
                                      bool a_alignmentRequired)
        {
            using func_t = decltype(&MemoryManager::Allocate);
            const REL::Relocation<func_t> func{ 
                REL_ID_VER(652767, 701234)  // VR ID, AE ID
            };
            return func(this, a_size, a_alignment, a_alignmentRequired);
        }

        void Deallocate(void* a_mem, bool a_alignmentRequired)
        {
            using func_t = decltype(&MemoryManager::Deallocate);
            const REL::Relocation<func_t> func{ 
                REL_ID_VER(1582181, 1623456)  // VR ID, AE ID
            };
            return func(this, a_mem, a_alignmentRequired);
        }

        // ... rest of implementation
    };

    // Benefits:
    // 1. One header file for both versions
    // 2. Compile-time selection (zero runtime cost)
    // 3. Clear which IDs are version-specific
    // 4. Easy to maintain - IDs in one place
    // 5. Type-safe - compiler checks everything
    // 6. Git-friendly - no generated code
}

// Usage in your plugin:
/*
void MyPlugin::Initialize()
{
    // This automatically works for both VR and AE!
    auto& memManager = RE::MemoryManager::GetSingleton();

    void* ptr = memManager.Allocate(1024, 16, true);

    // Version-specific code (if needed):
    if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) {
        // VR-specific initialization
        F4SE::log::info("Running on Fallout 4 VR");
    } else {
        // AE-specific initialization
        F4SE::log::info("Running on Fallout 4 AE");
    }

    memManager.Deallocate(ptr, true);
}
*/
