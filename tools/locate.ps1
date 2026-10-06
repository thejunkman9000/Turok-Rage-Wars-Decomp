# Locate libultra functions in the ROM by structure. usage: .\tools\locate.ps1 <libreultra-file.c> <function> [...]
# (compiles libreultra's source; for our own src/ files use try_many.ps1)
param([string]$File, [Parameter(ValueFromRemainingArguments=$true)][string[]]$Funcs)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh $File | Out-Null
if (-not (Test-Path build_ud.json)) { Write-Output "compile failed"; exit 1 }
.\.venv\Scripts\python.exe tools\lu_locate.py build_ud.json @Funcs
