# Try several functions at once. usage: .\tools\try_many.ps1 "file:func:rom" ["file:func:rom" ...]   (rom may be empty to auto-find)
param([Parameter(ValueFromRemainingArguments=$true)][string[]]$Specs)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash tools/wsl_sync.sh
foreach ($s in $Specs) {
  $p = $s.Split(':'); $file = $p[0]; $func = $p[1]; $rom = if ($p.Count -gt 2) { $p[2] } else { '' }
  $arg = if ($rom) { "$func=$rom" } else { '' }
  wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh "/home/johns/trw/src/libultra/$file" $arg | Out-Null
  if (-not (Test-Path build_ud.json)) { Write-Output "## $func : COMPILE FAILED"; continue }
  .\.venv\Scripts\python.exe tools\lu_ud.py build_ud.json $func
}
