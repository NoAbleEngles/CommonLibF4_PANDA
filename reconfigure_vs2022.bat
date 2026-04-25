@echo off
echo ====================================
echo Reconfiguring project for VS2022
echo ====================================
echo.

echo [1/3] Cleaning build cache...
if exist "build" (
    rmdir /s /q "build" 2>nul
    echo     Build folder cleared
) else (
    echo     No build folder found
)

echo.
echo [2/3] Configuring CMake with VS2022 preset...
cmake --preset vs2022-windows-vcpkg
if %errorlevel% neq 0 (
    echo     ERROR: CMake configuration failed!
    pause
    exit /b 1
)

echo.
echo [3/3] Building project (Debug)...
cmake --build build --config Debug
if %errorlevel% neq 0 (
    echo     WARNING: Build completed with errors
) else (
    echo     SUCCESS: Build completed successfully!
)

echo.
echo ====================================
echo Done!
echo ====================================
pause
