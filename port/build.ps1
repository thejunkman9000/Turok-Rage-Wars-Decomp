# Build the Windows port (32-bit x86, MSVC).  usage: powershell -NoProfile -File port\build.ps1 [-Game]
param([switch]$Game)
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path $PSScriptRoot -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
New-Item -ItemType Directory -Force port\build | Out-Null
cl /nologo /EHsc /O2 /W3 /c /Foport\build\win32_main.obj port\win32_main.cpp
cl /nologo /O2 /W3 /TC /c /Foport\build\game_glue.obj port\game_glue.c
link /nologo /SUBSYSTEM:WINDOWS /LARGEADDRESSAWARE /OUT:port\build\turok.exe port\build\win32_main.obj port\build\game_glue.obj
