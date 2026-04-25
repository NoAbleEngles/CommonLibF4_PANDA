# CommonLibF4 Version-Aware ID System

## 🎯 Overview

Элегантное compile-time решение для поддержки разных версий Fallout 4 (VR и AE/Standard) в одной кодовой базе. Использует современные возможности C++20 (constexpr, if constexpr) для **нулевых runtime затрат**.

## ✨ Особенности

- ✅ **Zero Runtime Cost** - всё решается на этапе компиляции
- ✅ **Type Safe** - полная проверка типов компилятором
- ✅ **Clean Code** - никаких `#ifdef` в коде
- ✅ **Git Friendly** - все файлы за пределами build директории
- ✅ **Universal** - работает во всех ваших проектах
- ✅ **IDE Friendly** - отличная поддержка IntelliSense
- ✅ **Backward Compatible** - совместимо с существующим кодом

## 🚀 Быстрый старт

### 1. Настройте CMakeLists.txt

```cmake
# Выберите версию
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)

if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
endif()
```

### 2. Определите версионные ID

```cpp
// CommonLibF4/include/RE/RTTI_IDs_Versioned.h
namespace RE::RTTI
{
    // VR ID, AE ID
    inline constexpr auto IMemoryStoreBase = REL_ID_VER(892595, 923456);
}
```

### 3. Используйте их в коде

```cpp
#include "REL/Version.h"

class MyClass
{
public:
    static constexpr auto RTTI = RE::RTTI::IMemoryStoreBase;
    // Автоматически выбирается правильный ID
};
```

## 📁 Структура файлов

```
CommonLibF4/
├── include/
│   ├── REL/
│   │   ├── Version.h           # Основная система версий
│   │   └── VersionInfo.h       # Утилиты для работы с версиями
│   └── RE/
│       ├── RTTI_IDs_Versioned.h    # Версионные RTTI ID
│       ├── VTABLE_IDs_Versioned.h  # Версионные VTABLE ID
│       ├── RTTI_IDs_Template.h     # Шаблон для заполнения
│       └── VTABLE_IDs_Template.h   # Шаблон для заполнения
│
docs/
├── QuickStart.md           # Быстрое руководство
└── VersionAwareIDs.md      # Полная документация

examples/
├── CMakeLists.txt          # Пример настройки проекта
└── example_usage.cpp       # Примеры использования
```

## 💡 Примеры использования

### Базовое использование

```cpp
// Определение ID
namespace RE::RTTI
{
    inline constexpr auto Actor = REL_ID_VER(1162828, 1198234);
}

// Использование
REL::Relocation<RE::Actor*> actor{ RE::RTTI::Actor };
```

### Conditional Compilation

```cpp
if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) {
    // VR-специфичный код
} else {
    // AE-специфичный код
}
```

### Function Hooking

```cpp
void InstallHooks()
{
    // ID автоматически выбирается для текущей версии
    REL::Relocation<decltype(&MyHook)> target{
        REL_ID_VER(652767, 698123)
    };

    auto& trampoline = F4SE::GetTrampoline();
    _original = trampoline.write_call<5>(target.address(), &MyHook);
}
```

### Проверка версии

```cpp
#include "REL/VersionInfo.h"

F4SE::log::info("Compiled for: {}", REL::VersionInfo::GetVersionName());
// Output: "Fallout 4 VR" или "Fallout 4 AE/Standard"

// Compile-time проверки
REQUIRE_VR();  // Ошибка компиляции если не VR
REQUIRE_AE();  // Ошибка компиляции если не AE
```

## 🔍 Как найти ID

### Метод 1: RTTIDump (рекомендуется)

```bash
# Дамп VR версии
RTTIDump.exe "Fallout4VR.exe" > vr_rtti.txt

# Дамп AE версии
RTTIDump.exe "Fallout4.exe" > ae_rtti.txt

# Сравните и найдите нужные ID
```

### Метод 2: IDA Pro / Ghidra

1. Откройте оба исполняемых файла
2. Найдите RTTI/VTABLE структуры
3. Запишите ID из базы данных CommonLibF4

### Метод 3: Address Library

```cpp
// Если известны адреса функций
REL::Relocation<void*> vr_addr{ 0x12345678 };    // VR адрес
REL::Relocation<void*> ae_addr{ 0x87654321 };    // AE адрес

// Найдите соответствующие ID в базе
```

## 📝 Шаблон для заполнения ID

```cpp
// В RTTI_IDs_Template.h или VTABLE_IDs_Template.h

// 1. Скопируйте секцию для вашего класса
// 2. Найдите ID для обеих версий
// 3. Заполните:

namespace RE::RTTI
{
    // Source: RTTI dump VR 1.2.72 / AE 1.10.163
    inline constexpr auto MyClassName = REL_ID_VER(vr_id, ae_id);
}
```

## 🎓 Продвинутые техники

### Условная компиляция шаблонов

```cpp
template<typename T>
void* Allocate()
{
    if constexpr (REL::VersionInfo::IsVR()) {
        // VR использует другой аллокатор
        return VRAllocate<T>();
    } else {
        return StandardAllocate<T>();
    }
}
```

### Версионно-зависимые структуры

```cpp
struct GameData
{
    int commonField;

    // Только для VR
    [[no_unique_address]] std::conditional_t<
        REL::VersionInfo::IsVR(),
        VRSpecificData,
        std::monostate
    > vrData;
};
```

### Static Assertions

```cpp
// Убедиться что ID определён
static_assert(
    REL::VersionInfo::IsIDDefined<
        REL_ID_VER(123456, 789012)
    >(),
    "ID must be defined"
);
```

## ⚙️ Настройка проекта

### Visual Studio

**Project Properties → C/C++ → Preprocessor → Preprocessor Definitions:**
```
F4_GAME_VERSION_VR    # для VR
или
F4_GAME_VERSION_AE    # для AE
```

### CMake

```cmake
# В корневом CMakeLists.txt
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)

if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
    message(STATUS "Building for Fallout 4 VR")
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
    message(STATUS "Building for Fallout 4 AE")
endif()
```

### xmake

```lua
-- xmake.lua
option("vr")
    set_default(false)
    set_showmenu(true)
    set_description("Build for Fallout 4 VR")

if has_config("vr") then
    add_defines("F4_GAME_VERSION_VR")
else
    add_defines("F4_GAME_VERSION_AE")
end
```

## 🧪 Тестирование

```cpp
// Проверьте компиляцию для обеих версий
#include "REL/VersionInfo.h"

void TestVersionSystem()
{
    // Проверка выбора ID
    constexpr auto test_id = REL_ID_VER(100, 200);

    if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) {
        static_assert(test_id == 100);
    } else {
        static_assert(test_id == 200);
    }

    // Проверка информации о версии
    F4SE::log::info("Version: {}", REL::VersionInfo::GetVersionName());
    F4SE::log::info("Short: {}", REL::VersionInfo::GetVersionShort());
}
```

## 📊 Сравнение подходов

| Подход | Runtime Cost | Код | IDE Support | Тестирование |
|--------|--------------|-----|-------------|--------------|
| `#ifdef` | ❌ Нет | ⚠️ Загрязнение | ⚠️ Среднее | ❌ Сложно |
| Dynamic | ❌ Есть | ✅ Чистый | ✅ Хорошее | ✅ Легко |
| **constexpr** | ✅ **Нет** | ✅ **Чистый** | ✅ **Отличное** | ✅ **Легко** |

## 🐛 Отладка

### Проверка выбранной версии

```cpp
#pragma message("Compiling for: " \
    #if defined(F4_GAME_VERSION_VR) \
        "VR" \
    #elif defined(F4_GAME_VERSION_AE) \
        "AE" \
    #else \
        "DEFAULT (AE)" \
    #endif \
)
```

### Вывод выбранных ID

```cpp
template<std::uint64_t VR, std::uint64_t AE>
void PrintSelectedID()
{
    constexpr auto selected = REL::VersionID<VR, AE>::get();
    F4SE::log::info("Selected ID: {}", selected);
}
```

## 📚 Дополнительные ресурсы

- **Quick Start**: `docs/QuickStart.md` - быстрое введение
- **Full Docs**: `docs/VersionAwareIDs.md` - полная документация
- **Examples**: `examples/example_usage.cpp` - рабочие примеры
- **Templates**: `RE/RTTI_IDs_Template.h` - шаблоны для ID

## 🤝 Contributing

При добавлении новых версионных ID:

1. Используйте шаблоны из `*_Template.h`
2. Документируйте источник ID в комментариях
3. Указывайте версии игры
4. Проверяйте компиляцию для обеих версий

```cpp
// ✅ Хороший пример
// Source: RTTI dump VR 1.2.72.0 / AE 1.10.163.0
inline constexpr auto MyClass = REL_ID_VER(123456, 789012);

// ❌ Плохой пример
inline constexpr auto MyClass = REL_ID_VER(123456, 789012);  // Нет источника
```

## ⚡ Performance

```cpp
// Традиционный подход с runtime проверкой
void* ptr = IsVR() ? GetVRAddress() : GetAEAddress();  // ❌ Runtime cost

// constexpr подход
constexpr auto id = REL_ID_VER(vr, ae);
void* ptr = REL::Relocation<void*>{ id }.get();  // ✅ Compile-time, zero cost
```

**Результат**: Идентичный assembly код, как если бы вы захардкодили ID напрямую.

## 📄 License

Следует лицензии CommonLibF4.

---

**Создано с ❤️ для сообщества Fallout 4 modding**
