# Wall-collision test: scripted boot -> 1-player trial level, then walk forward (C-up) in steps and record the camera position after each step
# (port_cam.txt via TUROK_MAPDUMP=1).  With working collision the player ends up pressed against a wall: the position stops changing.
# usage: .\port\walltest.ps1 [-Prefix wt] [-Speed 4] [-Steps 10] [-Hold 4]
param([string]$Prefix = 'wt', [int]$Speed = 4, [int]$Steps = 10, [double]$Hold = 4, [string]$ExtraEnv = '')
Set-Location (Split-Path $PSScriptRoot -Parent)
$boot = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4')
$act = @('campos:0','shot')
for ($i = 1; $i -le $Steps; $i++) { $act += @("CUp:$Hold", 'wait:0.5', "campos:$i") }
$act += 'shot'
Get-ChildItem "port\build\${Prefix}_*.png", 'port\build\cam_*.txt' -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
$old = $env:PF_ENV; $env:PF_ENV = 'TUROK_MAPDUMP=1' + $(if ($ExtraEnv) { ',' + $ExtraEnv } else { '' })
& .\port\pressfile.ps1 -Prefix $Prefix -Speed $Speed -Seq ($boot + $act) | Out-Null
$env:PF_ENV = $old
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
Copy-Item port\build\run.log "port\build\${Prefix}_run.log" -Force
for ($i = 0; $i -le $Steps; $i++) { $f = "port\build\cam_$i.txt"; if (Test-Path $f) { "$i " + (Get-Content $f -TotalCount 1) } else { "$i (no campos)" } }
