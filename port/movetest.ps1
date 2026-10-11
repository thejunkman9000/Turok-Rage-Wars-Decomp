# Scripted boot -> 1-player trial level, then walk forward (C-up), turn (stick) and look for actor movement in the log (move-dbg lines of
# port/overrides/func_002231B0.c).  usage: .\port\movetest.ps1 [-Prefix mvt] [-Speed 4]
param([string]$Prefix = 'mvt', [int]$Speed = 4)
Set-Location (Split-Path $PSScriptRoot -Parent)
$boot = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4')
$act = @('shot','CUp:3','shot','wait:1','stick:80:0:2','shot','wait:1','CUp:3','shot')
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed $Speed -Seq ($boot + $act) | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
Copy-Item port\build\run.log "port\build\${Prefix}_run.log" -Force
$m = Select-String -Path port\build\run.log -Pattern 'move-dbg2' | ForEach-Object { $_.Line }
"move-dbg2 lines: $($m.Count)"
$m | Select-Object -First 4
'...'
$m | Select-Object -Last 4
