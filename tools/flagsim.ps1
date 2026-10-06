# Sweep compiler flags on one of our functions and print the similarity to the ROM for each.
# usage: .\tools\flagsim.ps1 <file.c> <func> <rom> "<flags1>" "<flags2>" ...
param([string]$File, [string]$Func, [string]$Rom, [Parameter(ValueFromRemainingArguments=$true)][string[]]$Flags)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash tools/wsl_sync.sh
foreach ($fl in $Flags) {
  $env:WSLENV = 'FLAGS'
  $env:FLAGS = $fl
  wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh "/home/johns/trw/src/libultra/$File" "$Func=$Rom" | Out-Null
  if (-not (Test-Path build_ud.json)) { Write-Output ("{0,-70} COMPILE FAILED" -f $fl); continue }
  $line = .\.venv\Scripts\python.exe tools\lu_ud.py build_ud.json $Func | Select-Object -First 1
  Write-Output ("{0,-70} {1}" -f $fl, $line)
}
Remove-Item Env:FLAGS -ErrorAction SilentlyContinue
