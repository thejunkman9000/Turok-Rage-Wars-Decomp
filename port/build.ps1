# Build the Windows port (32-bit x86, MSVC).  usage: powershell -NoProfile -File port\build.ps1 [-Game]
param([switch]$Game)
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path $PSScriptRoot -Parent)
. "$PSScriptRoot\vcvars.ps1"      # MSVC 32-bit environment (any VS 2022 / 2026 with the C++ tools; TUROK_VCVARS overrides)
New-Item -ItemType Directory -Force port\build | Out-Null
cl /nologo /EHsc /O2 /W3 /c /Foport\build\win32_main.obj port\win32_main.cpp
cl /nologo /O2 /W3 /TC /c /Foport\build\game_glue.obj port\game_glue.c
link /nologo /SUBSYSTEM:WINDOWS /LARGEADDRESSAWARE /OUT:port\build\turok.exe port\build\win32_main.obj port\build\game_glue.obj
