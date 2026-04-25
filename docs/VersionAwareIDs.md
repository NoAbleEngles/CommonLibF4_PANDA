# Version-Aware ID System for CommonLibF4

## Overview

This system provides compile-time selection of game-specific IDs (RTTI, VTABLE, function addresses) for different Fallout 4 versions (VR and AE/Standard).

## Features

- **Zero runtime overhead** - all resolved at compile time using `constexpr`
- **Type-safe** - automatic conversion to `REL::ID`
- **Clean syntax** - simple macro for defining version-specific IDs
- **Compatible** - works with existing `REL::Relocation<>` system

## Setup

### 1. Define Game Version in CMakeLists.txt or Project Settings

```cmake
# For VR version
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)

# For AE/Standard version
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
```

Or in Visual Studio Project Properties:
```
C/C++ > Preprocessor > Preprocessor Definitions: F4_GAME_VERSION_VR
```

### 2. Include the Version Header

```cpp
#include "REL/Version.h"
#include "RE/RTTI_IDs_Versioned.h"
#include "RE/VTABLE_IDs_Versioned.h"
```

## Usage

### Defining Version-Aware IDs

In your ID header files:

```cpp
namespace RE::RTTI
{
    // Define with VR and AE IDs
    inline constexpr auto IMemoryStoreBase = REL_ID_VER(123456, 789012);
    inline constexpr auto IMemoryStore = REL_ID_VER(123457, 789013);
}
```

### Using Version-Aware IDs

```cpp
// Direct usage - automatically selects correct ID
class MyClass
{
public:
    static constexpr auto RTTI = RE::RTTI::IMemoryStoreBase;
    static constexpr auto VTABLE = RE::VTABLE::IMemoryStoreBase;
};

// With REL::Relocation
void MyFunction()
{
    REL::Relocation<void**> vtbl{ RE::VTABLE::IMemoryStoreBase };
    // Automatically uses correct ID based on compile-time version
}

// Check version at compile time
if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) {
    // VR-specific code
} else {
    // AE-specific code
}
```

### Migration Strategy

1. **Start with critical classes** - migrate RTTI/VTABLE IDs that differ between versions
2. **Use versioned files** - create `*_Versioned.h` alongside existing ID files
3. **Gradual migration** - keep old IDs working while migrating
4. **Document ID sources** - comment where each ID was found

```cpp
// Example:
namespace RE::RTTI
{
    // VR ID from RTTI dump 1.2.72.0, AE ID from 1.10.163.0
    inline constexpr auto IMemoryStoreBase = REL_ID_VER(892595, 923456);
}
```

## Benefits Over Preprocessor

1. **Type Safety** - constexpr ensures type checking
2. **Better IDE Support** - IntelliSense works properly
3. **Cleaner Code** - no `#ifdef` pollution
4. **Easier Debugging** - can inspect constexpr values
5. **Modern C++** - uses C++20 features properly

## Implementation Details

The system uses C++20 `constexpr` and `if constexpr` to select the correct ID at compile time. The `VersionID` template automatically converts to `REL::ID` type, making it compatible with all existing CommonLibF4 code.

```cpp
template <std::uint64_t VR_ID, std::uint64_t AE_ID>
struct VersionID
{
    static constexpr std::uint64_t get() noexcept
    {
        if constexpr (GAME_VERSION == GameVersion::VR) {
            return VR_ID;
        } else {
            return AE_ID;
        }
    }

    constexpr operator REL::ID() const noexcept
    {
        return REL::ID(get());
    }
};
```

## Finding IDs

### Method 1: Using RTTIDump
```cpp
// Run RTTIDump on both versions and compare
```

### Method 2: Binary Search
- Use IDA Pro / Ghidra on both executables
- Search for RTTI structures
- Compare addresses

### Method 3: Signature Scanning
- Use existing known patterns
- Scan both versions
- Record offsets

## Example Project Structure

```
YourProject/
├── CMakeLists.txt (defines F4_GAME_VERSION_VR or F4_GAME_VERSION_AE)
├── src/
│   └── main.cpp (uses version-aware IDs)
└── CommonLibF4/
    └── include/
        ├── REL/
        │   └── Version.h (version detection)
        └── RE/
            ├── RTTI_IDs_Versioned.h (versioned RTTI)
            └── VTABLE_IDs_Versioned.h (versioned VTABLE)
```

## FAQ

**Q: What if I don't define a version?**  
A: Defaults to AE version for compatibility.

**Q: Can I mix versioned and non-versioned IDs?**  
A: Yes! They're fully compatible.

**Q: Runtime overhead?**  
A: Zero! Everything is resolved at compile time.

**Q: Can I add more versions (e.g., GOG)?**  
A: Yes, extend the `GameVersion` enum and add more template parameters.
