# Version-Aware ID System - Quick Start

## TL;DR

```cpp
// 1. In CMakeLists.txt
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)  # or F4_GAME_VERSION_AE

// 2. Define IDs
inline constexpr auto MyRTTI = REL_ID_VER(123456, 789012);  // VR, AE

// 3. Use them
REL::Relocation<void*> ptr{ MyRTTI };  // Automatically selects correct ID
```

## What Problem Does This Solve?

Fallout 4 VR and AE/Standard have **different memory addresses** for the same functions/RTTI/VTABLE. Previously, you had to:
- Maintain separate builds
- Use `#ifdef` everywhere
- Manually manage two versions

Now: **One codebase, compile-time selection, zero runtime cost.**

## Setup (3 steps)

### Step 1: Add to CMakeLists.txt

```cmake
# Choose one:
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
# OR
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
```

### Step 2: Include headers

```cpp
#include "REL/Version.h"
```

### Step 3: Define your IDs

```cpp
namespace RE::RTTI
{
    inline constexpr auto MyClass = REL_ID_VER(123456, 789012);
}
```

## How to Find IDs?

### Method 1: Use RTTIDump
```bash
# Dump VR version
RTTIDump.exe "Fallout4VR.exe" > vr_dump.txt

# Dump AE version  
RTTIDump.exe "Fallout4.exe" > ae_dump.txt

# Compare and find your IDs
```

### Method 2: IDA Pro / Ghidra
1. Open both executables
2. Search for RTTI/VTABLE structures
3. Note the IDs from CommonLibF4's database

## Real-World Example

```cpp
// Before (messy):
#ifdef F4_VR
    inline constexpr REL::ID IMemoryStore{ 123456 };
#else
    inline constexpr REL::ID IMemoryStore{ 789012 };
#endif

// After (clean):
inline constexpr auto IMemoryStore = REL_ID_VER(123456, 789012);
```

## FAQ

**Q: What if I don't know the VR ID yet?**  
A: Use `0` as placeholder: `REL_ID_VER(0, 789012)` and document it

**Q: Performance impact?**  
A: **ZERO**. Everything is `constexpr` - resolved at compile time.

**Q: Can I check version at runtime?**  
A: No need! But if you want: `if constexpr (REL::GAME_VERSION == REL::GameVersion::VR)`

**Q: Works with existing code?**  
A: Yes! `VersionID` automatically converts to `REL::ID`.

## Migration Checklist

- [ ] Add compile definition to CMakeLists.txt
- [ ] Include `REL/Version.h` in your PCH
- [ ] Find IDs that differ between versions
- [ ] Replace them with `REL_ID_VER(vr, ae)`
- [ ] Build and test both versions
- [ ] Document ID sources in comments

## Complete Example

See `examples/example_usage.cpp` for full working code including:
- Class definitions with version-aware RTTI/VTABLE
- Function hooking
- Conditional compilation
- Memory allocation

## Benefits

✅ **One codebase** - no more `#ifdef` spaghetti  
✅ **Type safe** - compiler catches errors  
✅ **Zero cost** - no runtime overhead  
✅ **Git friendly** - no build artifacts  
✅ **IDE friendly** - IntelliSense works perfectly  
✅ **Future proof** - easy to add more versions  

## Support

For detailed documentation, see `docs/VersionAwareIDs.md`
