@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64
set VCPKG_FORCE_SYSTEM_BINARIES=
cd /d C:\cpp\vcpkg
vcpkg install args boost-stl-interfaces catch2 fmt frozen nowide robin-hood-hashing rsm-mmio spdlog srell xbyak --triplet x64-windows-static-md-v143
