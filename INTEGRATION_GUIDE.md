# Инструкция по интеграции Version-Aware ID System

## ✅ Что было сделано

### 1. Созданы основные файлы системы

#### Core файлы (REL)
- ✅ `CommonLibF4/include/REL/Version.h` - основная система версионирования
- ✅ `CommonLibF4/include/REL/VersionInfo.h` - утилиты и helper функции

#### ID файлы (RE)
- ✅ `CommonLibF4/include/RE/RTTI_IDs_Versioned.h` - версионные RTTI ID
- ✅ `CommonLibF4/include/RE/VTABLE_IDs_Versioned.h` - версионные VTABLE ID
- ✅ `CommonLibF4/include/RE/RTTI_IDs_Template.h` - шаблон для RTTI
- ✅ `CommonLibF4/include/RE/VTABLE_IDs_Template.h` - шаблон для VTABLE

### 2. Добавлены в sourcelist.cmake

Файлы добавлены в `CommonLibF4/cmake/sourcelist.cmake`:
```cmake
# После include/RE/RTTI_IDs.h:
include/RE/RTTI_IDs_Template.h
include/RE/RTTI_IDs_Versioned.h

# После include/RE/VTABLE_IDs.h:
include/RE/VTABLE_IDs_Template.h
include/RE/VTABLE_IDs_Versioned.h

# После include/REL/Relocation.h:
include/REL/Version.h
include/REL/VersionInfo.h
```

## 🔄 Пересборка проекта

### Вариант 1: Через CMake GUI

1. Откройте CMake GUI
2. Нажмите "Configure"
3. Нажмите "Generate"
4. Откройте Visual Studio Solution
5. В Solution Explorer увидите новые файлы в фильтрах:
   - `CommonLibF4 → include → REL → Version.h, VersionInfo.h`
   - `CommonLibF4 → include → RE → RTTI_IDs_Versioned.h, RTTI_IDs_Template.h, VTABLE_IDs_Versioned.h, VTABLE_IDs_Template.h`

### Вариант 2: Через командную строку

```bash
# Из корня проекта
cd build
cmake ..
cmake --build . --config Release
```

### Вариант 3: Пересоздать build директорию

```bash
# Из корня проекта
rm -rf build
mkdir build
cd build
cmake ..
```

## ✅ Проверка интеграции

### 1. Проверить что файлы видны в Visual Studio

После генерации откройте Solution в Visual Studio и проверьте:

```
Solution Explorer
└── CommonLibF4
    └── include
        ├── REL
        │   ├── Relocation.h
        │   ├── Version.h          ← Должен быть виден
        │   └── VersionInfo.h      ← Должен быть виден
        └── RE
            ├── RTTI_IDs.h
            ├── RTTI_IDs_Template.h    ← Должен быть виден
            ├── RTTI_IDs_Versioned.h   ← Должен быть виден
            ├── VTABLE_IDs.h
            ├── VTABLE_IDs_Template.h  ← Должен быть виден
            └── VTABLE_IDs_Versioned.h ← Должен быть виден
```

### 2. Проверить компиляцию

Создайте тестовый файл:

```cpp
#include <F4SE/F4SE.h>
#include "REL/Version.h"
#include "RE/RTTI_IDs_Versioned.h"

void TestVersionSystem()
{
    // Должно компилироваться
    constexpr auto version = REL::GAME_VERSION;
    constexpr auto name = REL::VersionInfo::GetVersionName();

    // Тест ID
    constexpr auto test_id = REL_ID_VER(100, 200);
}
```

Если компилируется без ошибок - интеграция прошла успешно! ✅

### 3. Проверить IntelliSense

В Visual Studio попробуйте:
```cpp
#include "REL/Version.h"

REL::  // ← Должны появиться подсказки: GAME_VERSION, VersionInfo, VersionID
```

## 🎯 Следующие шаги

### 1. Заполнить ID

Откройте `RTTI_IDs_Versioned.h` и `VTABLE_IDs_Versioned.h` и заполните ID:

```cpp
// В RTTI_IDs_Versioned.h
namespace RE::RTTI
{
    // Source: RTTI dump VR 1.2.72.0 / AE 1.10.163.0
    inline constexpr auto IMemoryStoreBase = REL_ID_VER(892595, 923456);
    inline constexpr auto IMemoryStore = REL_ID_VER(892596, 923457);
    // ... и т.д.
}
```

### 2. Обновить существующий код

Замените хардкодные ID на версионные:

```cpp
// Было:
static constexpr auto RTTI{ RTTI::IMemoryStoreBase };

// Стало:
#include "RE/RTTI_IDs_Versioned.h"
static constexpr auto RTTI = RE::RTTI::IMemoryStoreBase;
```

### 3. Настроить проекты

В ваших плагинах добавьте в CMakeLists.txt:

```cmake
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)

if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
endif()
```

## 📚 Документация

Вся документация находится в корне проекта:

- **[INDEX.md](INDEX.md)** - главная точка входа
- **[CHEATSHEET.md](CHEATSHEET.md)** - быстрая шпаргалка
- **[README_VersionSystem.md](README_VersionSystem.md)** - полное описание
- **[docs/QuickStart.md](docs/QuickStart.md)** - быстрый старт
- **[examples/](examples/)** - примеры использования

## 🐛 Возможные проблемы

### Проблема: Файлы не видны в Visual Studio

**Решение:**
1. Удалите build директорию
2. Пересоздайте через CMake
3. Откройте .sln заново

### Проблема: IntelliSense не видит файлы

**Решение:**
1. В Visual Studio: `Project → Rescan Solution`
2. Или перезапустите Visual Studio

### Проблема: Ошибки компиляции при использовании REL_ID_VER

**Решение:**
Убедитесь что в CMakeLists.txt определён флаг:
```cmake
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_AE)
# или
target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
```

## ✨ Готово!

Система интегрирована и готова к использованию. Теперь вы можете:

1. ✅ Использовать версионные ID в коде
2. ✅ Компилировать для VR и AE из одной кодовой базы
3. ✅ Наслаждаться zero runtime cost
4. ✅ Иметь чистый код без #ifdef

**Начните с [CHEATSHEET.md](CHEATSHEET.md) для быстрого старта! 🚀**
