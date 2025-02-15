@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
set WindowsSdkDir=
set Generator="Visual Studio 17 2022"

REM Windows
if not exist build\Windows\x86 mkdir build\Windows\x86
cmake -B build\Windows\x86 -G %Generator% -A Win32
cmake --build build\Windows\x86 --config=Release
if %ERRORLEVEL% neq 0 GOTO :exit

REM Windows x64
if not exist build\Windows\x64 mkdir build\Windows\x64
cmake -B build\Windows\x64 -G %Generator% -A X64
cmake --build build\Windows\x64 --config=Release
if %ERRORLEVEL% neq 0 GOTO :exit

REM Windows ARM64
if not exist build\Windows\arm64 mkdir build\Windows\arm64
cmake -B build\Windows\arm64 -G %Generator% -A ARM64
cmake --build build\Windows\arm64 --config=Release
if %ERRORLEVEL% neq 0 GOTO :exit

:exit 
endlocal
@echo on
