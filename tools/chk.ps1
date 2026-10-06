# Batch-check candidate C files against the ROM.  usage: .\tools\chk.ps1 <list-file>
# list line: <src path rel. to src/libultra (or project-relative like wip/x.c)>  <function>  <rom hex>  [gcc flags]
param([string]$List)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash tools/wsl_sync.sh
wsl -d Ubuntu-24.04 -- bash -c "cd /mnt/d/Projects/TurokRageWars && python3 tools/chk.py $List 2>&1"
