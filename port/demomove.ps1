# Attract-demo motion test: boot, let the attract demo start (no input), record the camera position (port_cam.txt, TUROK_MAPDUMP=1) every few game seconds.
# In the real game the demo players (bot-driven) run around: the positions change.  usage: .\port\demomove.ps1 [-Prefix dm] [-Samples 8] [-Every 3]
param([string]$Prefix = 'dm', [int]$Samples = 8, [double]$Every = 3, [int]$Speed = 2)
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:30'); for ($i = 0; $i -lt $Samples; $i++) { $seq += "campos:$i"; $seq += "wait:$Every" }
Get-ChildItem 'port\build\cam_*.txt' -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
$old = $env:PF_ENV; $env:PF_ENV = 'TUROK_MAPDUMP=1'
& .\port\pressfile.ps1 -Prefix $Prefix -Speed $Speed -Gate '-> 29' -Seq $seq | Out-Null
$env:PF_ENV = $old
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
$pos = @(); for ($i = 0; $i -lt $Samples; $i++) { $f = "port\build\cam_$i.txt"; if (Test-Path $f) { $pos += (Get-Content $f -TotalCount 1) } }
$pos | ForEach-Object { "  $_" }
"distinct positions: " + (@($pos | Sort-Object -Unique).Count) + " of " + $pos.Count
