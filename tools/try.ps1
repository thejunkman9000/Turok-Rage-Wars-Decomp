# Compile one of our src/ functions and diff it against the ROM.
# usage: .\tools\try.ps1 <src-file-under-src/libultra> <function> <rom-offset-hex> [-Side | -Align [context]]
param([string]$File, [string]$Func, [string]$Rom, [switch]$Side, [switch]$Align, [int]$Ctx = 3)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash tools/wsl_sync.sh
wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh "/home/johns/trw/src/libultra/$File" "$Func=$Rom"
if ($Side)       { .\.venv\Scripts\python.exe tools\lu_side.py build_ud.json $Func }
elseif ($Align)  { .\.venv\Scripts\python.exe tools\lu_align.py build_ud.json $Func $Ctx }
else             { .\.venv\Scripts\python.exe tools\lu_ud.py   build_ud.json $Func }
