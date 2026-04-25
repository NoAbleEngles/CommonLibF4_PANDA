# Version-Aware ID System - Шпаргалка

## 🚀 Быстрый старт (3 шага)

### 1️⃣ CMakeLists.txt
```cmake
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)
if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
endif()
```

### 2️⃣ Определить ID
```cpp
// RE/RTTI_IDs_Versioned.h
inline constexpr auto MyClass = REL_ID_VER(vr_id, ae_id);
```

### 3️⃣ Использовать
```cpp
class MyClass
{
    static constexpr auto RTTI = RE::RTTI::MyClass;
};
```

---

## 📝 Основные макросы и типы

```cpp
// Определить версионный ID
REL_ID_VER(vr_id, ae_id)

// Проверить версию
if constexpr (REL::GAME_VERSION == REL::GameVersion::VR) { }

// Информация о версии
REL::VersionInfo::GetVersionName()     // "Fallout 4 VR" или "Fallout 4 AE/Standard"
REL::VersionInfo::GetVersionShort()    // "VR" или "AE"
REL::VersionInfo::IsVR()               // true/false
REL::VersionInfo::IsAE()               // true/false

// Compile-time assertions
REQUIRE_VR()  // Ошибка если не VR
REQUIRE_AE()  // Ошибка если не AE
```

---

## 💻 Примеры кода

### Определение RTTI/VTABLE ID
```cpp
namespace RE::RTTI
{
    // Документируйте источник!
    // Source: RTTI dump VR 1.2.72.0 / AE 1.10.163.0
    inline constexpr auto IMemoryStore = REL_ID_VER(892595, 923456);
}

namespace RE::VTABLE
{
    inline constexpr auto IMemoryStore = REL_ID_VER(892595, 923456);
}
```

### Использование в классах
```cpp
class IMemoryStore
{
public:
    static constexpr auto RTTI = RE::RTTI::IMemoryStore;
    static constexpr auto VTABLE = RE::VTABLE::IMemoryStore;
};
```

### Function hooking
```cpp
void InstallHook()
{
    REL::Relocation<decltype(&MyFunc)> target{
        REL_ID_VER(652767, 698123)  // VR, AE
    };

    auto& trampoline = F4SE::GetTrampoline();
    _original = trampoline.write_call<5>(target.address(), &MyFunc);
}
```

### Версионно-зависимый код
```cpp
void Initialize()
{
    if constexpr (REL::VersionInfo::IsVR()) {
        // VR-specific
        InitVR();
    } else {
        // AE-specific
        InitAE();
    }
}
```

---

## 🔍 Как найти ID

### RTTIDump (рекомендуется)
```bash
RTTIDump.exe "Fallout4VR.exe" > vr_dump.txt
RTTIDump.exe "Fallout4.exe" > ae_dump.txt
# Сравните файлы
```

### IDA Pro / Ghidra
1. Откройте обе версии
2. Найдите RTTI структуры
3. Запишите ID

---

## 📁 Структура файлов

```
CommonLibF4/include/
├── REL/
│   ├── Version.h          ⭐ Основная система
│   └── VersionInfo.h      🛠️ Утилиты
└── RE/
    ├── RTTI_IDs_Versioned.h    📝 Версионные RTTI
    ├── VTABLE_IDs_Versioned.h  📝 Версионные VTABLE
    ├── RTTI_IDs_Template.h     📋 Шаблон
    └── VTABLE_IDs_Template.h   📋 Шаблон
```

---

## ✅ Чек-лист внедрения

- [ ] Добавить `#include "REL/Version.h"` в PCH
- [ ] Настроить CMakeLists.txt
- [ ] Найти ID для VR и AE
- [ ] Заполнить `*_Versioned.h` файлы
- [ ] Обновить классы
- [ ] Тестировать обе версии

---

## 🐛 Отладка

### Проверка выбранной версии
```cpp
#pragma message("Building for: " \
    #ifdef F4_GAME_VERSION_VR \
        "VR" \
    #else \
        "AE" \
    #endif \
)
```

### Вывод ID в лог
```cpp
F4SE::log::info("Version: {}", REL::VersionInfo::GetVersionName());
F4SE::log::info("Selected ID: {}", REL_ID_VER(100, 200).get());
```

---

## ⚡ Ключевые преимущества

| Фича | Статус |
|------|--------|
| Runtime Cost | ✅ Zero |
| Type Safety | ✅ Full |
| IDE Support | ✅ Perfect |
| Git Friendly | ✅ Yes |
| Clean Code | ✅ Yes |

---

## 📚 Документация

- `README_VersionSystem.md` - Полное описание
- `docs/QuickStart.md` - Быстрое введение
- `docs/VersionAwareIDs.md` - Детальная документация
- `IMPLEMENTATION_SUMMARY.md` - Итоги реализации
- `examples/` - Рабочие примеры

---

## 🎯 Шаблон для копирования

```cpp
// ========================================
// В RTTI_IDs_Versioned.h или VTABLE_IDs_Versioned.h
// ========================================

namespace RE::RTTI  // или VTABLE
{
    // Source: [где нашли ID]
    inline constexpr auto MyClassName = REL_ID_VER(vr_id, ae_id);
}

// ========================================
// В вашем .h файле
// ========================================

#include "REL/Version.h"
#include "RE/RTTI_IDs_Versioned.h"

class MyClassName
{
public:
    static constexpr auto RTTI = RE::RTTI::MyClassName;
    // ... ваш код
};

// ========================================
// В CMakeLists.txt
// ========================================

option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)

if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
    message(STATUS "Building for Fallout 4 VR")
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
    message(STATUS "Building for Fallout 4 AE")
endif()
```

---

**Сохраните эту шпаргалку для быстрого доступа!** 📌
