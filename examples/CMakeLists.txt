# Example CMakeLists.txt showing how to use version-aware ID system

cmake_minimum_required(VERSION 3.21)

project(
    YourF4Plugin
    VERSION 1.0.0
    LANGUAGES CXX
)

# Option to select game version
option(BUILD_FOR_VR "Build for Fallout 4 VR" OFF)

# C++23 standard required for CommonLibF4
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find CommonLibF4
find_package(CommonLibF4 REQUIRED)

# Your plugin source files
add_library(
    ${PROJECT_NAME}
    SHARED
        src/main.cpp
        # ... your other files
)

# Link CommonLibF4
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        CommonLibF4::CommonLibF4
)

# Define game version based on build option
if(BUILD_FOR_VR)
    target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
            F4_GAME_VERSION_VR
    )
    message(STATUS "Building for Fallout 4 VR")
else()
    target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
            F4_GAME_VERSION_AE
    )
    message(STATUS "Building for Fallout 4 AE/Standard")
endif()

# Usage:
# Build for AE: cmake -B build
# Build for VR: cmake -B build -DBUILD_FOR_VR=ON
