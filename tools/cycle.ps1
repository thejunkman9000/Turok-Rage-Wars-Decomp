# Full cycle: funcs.txt -> yaml -> splat -> fix asm -> WSL build + verify.  usage: .\tools\cycle.ps1 [-NoSplat]
param([switch]$NoSplat)
Set-Location D:\Projects\TurokRageWars
if (-not $NoSplat) {
  .\.venv\Scripts\python.exe tools\gen_yaml.py
  Remove-Item -Recurse -Force asm -ErrorAction SilentlyContinue
  .\.venv\Scripts\python.exe -m splat split turok_ragewars.yaml 2>&1 | Select-String -Pattern 'rror|Traceback' | ForEach-Object { $_.Line }
  .\.venv\Scripts\python.exe tools\fix_asm.py | Select-Object -Last 1
}
wsl -d Ubuntu-24.04 -- bash -c "bash /mnt/d/Projects/TurokRageWars/tools/wsl_build.sh clean >/dev/null 2>&1; bash /mnt/d/Projects/TurokRageWars/tools/wsl_build.sh > /tmp/build.log 2>&1; echo build-rc=`$?; grep -vE 'Warning: float register|^\s*$' /tmp/build.log | grep -E 'error|Error|undefined|MISMATCH|OK:|built:|original:|differ|multiple' | head -12"
