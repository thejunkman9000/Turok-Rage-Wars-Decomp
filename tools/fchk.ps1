# Fast chk (no full sync).  usage: powershell -NoProfile -File tools/fchk.ps1 <listfile>
param([string]$List)
Set-Location D:\Projects\TurokRageWars
wsl -d Ubuntu-24.04 -- bash /mnt/d/Projects/TurokRageWars/tools/fchk.sh $List
