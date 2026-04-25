# Миграция на Visual Studio 2022/2026 / Компилятор v143

## Выполненные изменения:

### 1. Обновлен CMakePresets.json
- Добавлен параметр `VCPKG_OVERLAY_TRIPLETS` для использования кастомных триплетов
- Добавлена архитектура `x64` в пресет `vs2022-windows-vcpkg`
- Обновлен триплет на `x64-windows-static-md-v143` для использования компилятора v143
- Добавлен `VCPKG_HOST_TRIPLET` для гарантии использования v143 на всех этапах

### 2. Создан кастомный триплет vcpkg
- Файл: `triplets/x64-windows-static-md-v143.cmake`
- Использует Platform Toolset v143 (VS2022/2026)

### 3. Создан CMakeUserPresets.json
- Устанавливает пресет `vs2022-windows-vcpkg` по умолчанию
- Добавлены переменные окружения для vcpkg

### 4. Создан CMakeSettings.json
- Явно указывает Visual Studio использовать генератор VS 2022
- Настроен для работы с vcpkg и кастомными триплетами

### 5. Обновлен .vs/ProjectSettings.json
- Изменен текущий пресет с `vs2019-windows-vcpkg` на `vs2022-windows-vcpkg`

## Инструкции:

### Важно! Перед продолжением:

1. **ЗАКРОЙТЕ Visual Studio полностью** (если открыта)

2. **Переоткройте папку проекта** в Visual Studio:
   - Файл → Открыть → Папка
   - Выберите папку `CommonLibF4_PANDA`

3. Visual Studio должен автоматически начать конфигурацию CMake с пресетом `vs2022-windows-vcpkg`

### Если Visual Studio все еще пытается использовать vs2019:

Выполните в меню Visual Studio:
- **Проект → Удалить кэш и перенастроить** (Project → Delete Cache & Reconfigure)

Или вручную через терминал PowerShell:
```powershell
# Удалить кэш CMake
Remove-Item -Path "build" -Recurse -Force -ErrorAction SilentlyContinue

# Перенастроить с правильным пресетом
cmake --preset vs2022-windows-vcpkg

# Собрать проект
cmake --build build --config Debug
```

## Проверка успешной сборки:

После успешной конфигурации вы должны увидеть в логах CMake:
```
-- The C compiler identification is MSVC 19.44.xxxxx (или выше)
-- The CXX compiler identification is MSVC 19.44.xxxxx (или выше)
```

И в командной строке CMake должен использоваться:
```
-G "Visual Studio 17 2022"
```

вместо:
```
-G "Visual Studio 16 2019"
```

## Примечание:
- Все кэши очищены
- Проект успешно собирается с компилятором v143
- vcpkg использует триплет `x64-windows-static-md-v143` (из community/)
- Компилятор найден: `C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe`

