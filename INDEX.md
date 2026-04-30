# CommonLibF4 Version-Aware ID System

## 📖 Документация

Полная система для поддержки разных версий Fallout 4 (VR и AE/Standard) с использованием современного C++20 constexpr подхода.

### 🚀 Начало работы

1. **[CHEATSHEET.md](CHEATSHEET.md)** ⭐ **НАЧНИТЕ ЗДЕСЬ!**
   - Быстрая справка на одной странице
   - Все основные команды и примеры
   - Шаблоны для копирования

2. **[docs/QuickStart.md](docs/QuickStart.md)**
   - Быстрое введение за 5 минут
   - 3 шага для начала работы
   - FAQ

### 📚 Подробная документация

3. **[README_VersionSystem.md](README_VersionSystem.md)**
   - Полное описание системы
   - Все возможности и примеры
   - Продвинутые техники
   - Сравнение подходов

4. **[docs/VersionAwareIDs.md](docs/VersionAwareIDs.md)**
   - Детальная техническая документация
   - Migration guide
   - Best practices

5. **[IMPLEMENTATION_SUMMARY.md](IMPLEMENTATION_SUMMARY.md)**
   - Что было реализовано
   - Технические детали
   - Чек-листы

### 💻 Примеры кода

6. **[examples/example_usage.cpp](examples/example_usage.cpp)**
   - Полные рабочие примеры
   - Function hooking
   - RTTI/VTABLE usage
   - Memory management

7. **[examples/MemoryManager_Example.h](examples/MemoryManager_Example.h)**
   - Реальный пример с MemoryManager
   - Показывает migration path
   - Best practices

8. **[examples/CMakeLists.txt](examples/CMakeLists.txt)**
   - Пример настройки проекта
   - Опции для VR/AE
   - Готово к копированию

## 🗂️ Файлы системы

### Основные компоненты

```
CommonLibF4/include/
├── REL/
│   ├── Version.h          # Основная система версионирования
│   └── VersionInfo.h      # Утилиты и helper функции
└── RE/
    ├── RTTI_IDs_Versioned.h    # Версионные RTTI ID
    ├── VTABLE_IDs_Versioned.h  # Версионные VTABLE ID
    ├── RTTI_IDs_Template.h     # Шаблон для RTTI
    └── VTABLE_IDs_Template.h   # Шаблон для VTABLE
```

## 🎯 Быстрый обзор

### Проблема
Fallout 4 VR и AE имеют разные адреса для одинаковых функций/RTTI/VTABLE.

### Решение
Compile-time выбор правильных ID через constexpr:

```cpp
// 1. Определяем ID для обеих версий
inline constexpr auto MyClass = REL_ID_VER(vr_id, ae_id);

// 2. Используем в коде
static constexpr auto RTTI = RE::RTTI::MyClass;

// 3. Компилируем с правильным флагом
// -DF4_GAME_VERSION_VR или -DF4_GAME_VERSION_AE
```

### Преимущества
- ✅ **Zero runtime cost** - всё compile-time
- ✅ **Type safe** - полная проверка типов
- ✅ **Clean code** - никаких #ifdef
- ✅ **Git friendly** - всё за пределами build/
- ✅ **Universal** - работает во всех проектах

## 📋 Рекомендованный порядок изучения

### Для начинающих
1. [CHEATSHEET.md](CHEATSHEET.md) - быстрый обзор
2. [docs/QuickStart.md](docs/QuickStart.md) - первые шаги
3. [examples/example_usage.cpp](examples/example_usage.cpp) - примеры кода
4. [examples/CMakeLists.txt](examples/CMakeLists.txt) - настройка проекта

### Для опытных разработчиков
1. [README_VersionSystem.md](README_VersionSystem.md) - полное описание
2. [IMPLEMENTATION_SUMMARY.md](IMPLEMENTATION_SUMMARY.md) - технические детали
3. [docs/VersionAwareIDs.md](docs/VersionAwareIDs.md) - продвинутые техники
4. [examples/MemoryManager_Example.h](examples/MemoryManager_Example.h) - реальный кейс

## 🛠️ Использование

### 1. Setup (один раз)
```bash
# Скопируйте файлы из CommonLibF4/include в ваш проект
cp -r CommonLibF4/include/REL/Version* your_project/CommonLibF4/include/REL/
cp -r CommonLibF4/include/RE/*_Versioned.h your_project/CommonLibF4/include/RE/
```

### 2. Configure (в каждом проекте)
```cmake
# В CMakeLists.txt
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)
if(BUILD_FOR_VR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE F4_GAME_VERSION_VR)
endif()
```

### 3. Use (в коде)
```cpp
#include "REL/Version.h"
inline constexpr auto MyID = REL_ID_VER(vr_id, ae_id);
```

## 🔧 Инструменты

### Для поиска ID
- **RTTIDump** - дамп RTTI структур
- **IDA Pro** - дизассемблер
- **Ghidra** - бесплатная альтернатива IDA
- **Address Library** - база адресов

### Для разработки
- **CMake** - система сборки
- **Visual Studio** - IDE
- **Git** - контроль версий

## 📊 Сравнение с альтернативами

| Подход | Runtime Cost | Код | Поддержка | Тестирование |
|--------|--------------|-----|-----------|--------------|
| `#ifdef` | ✅ Нет | ❌ Загрязнён | ⚠️ Среднее | ❌ Сложно |
| Dynamic | ❌ Есть | ✅ Чистый | ✅ Хорошее | ✅ Легко |
| **constexpr** | ✅ **Нет** | ✅ **Чистый** | ✅ **Отличное** | ✅ **Легко** |

## 🤝 Contributing

При добавлении новых ID:
1. Используйте шаблоны из `*_Template.h`
2. Документируйте источник ID
3. Указывайте версии игры
4. Проверяйте компиляцию для обеих версий

## ❓ Поддержка

- **Вопросы**: См. FAQ в [docs/QuickStart.md](docs/QuickStart.md)
- **Примеры**: См. [examples/](examples/)
- **Проблемы**: Проверьте [IMPLEMENTATION_SUMMARY.md](IMPLEMENTATION_SUMMARY.md)

## 📄 Лицензия

Следует лицензии CommonLibF4.

---

## 🗺️ Карта навигации

```
Я хочу...

├─ Быстро начать
│  └─ CHEATSHEET.md ⭐
│
├─ Понять как это работает
│  └─ README_VersionSystem.md
│
├─ Увидеть примеры
│  ├─ examples/example_usage.cpp
│  └─ examples/MemoryManager_Example.h
│
├─ Настроить проект
│  └─ examples/CMakeLists.txt
│
├─ Узнать детали реализации
│  └─ IMPLEMENTATION_SUMMARY.md
│
└─ Изучить продвинутые техники
   └─ docs/VersionAwareIDs.md
```

---

**Начните с [CHEATSHEET.md](CHEATSHEET.md) для быстрого старта! 🚀**
