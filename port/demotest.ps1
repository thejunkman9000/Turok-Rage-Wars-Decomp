# Attract-mode test: boot, wait (no input) and take screenshots every 20 game seconds; prints the largest share of non-black pixels (a rendered 3D demo arena is > 0.3 while the title / menu screens are mostly dark).  usage: .\port\demotest.ps1 [-Prefix dmt] [-Shots 14]
param([string]$Prefix = 'dmt', [int]$Shots = 14)
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:5'); for ($i = 0; $i -lt $Shots; $i++) { $seq += 'shot'; $seq += 'wait:20' }
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Gate '-> 29' -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
$vals = @(); Get-ChildItem "port\build\${Prefix}_*.png" | Sort-Object Name | ForEach-Object { $vals += [double](python port\imgstat.py $_.FullName 2>$null | Select-Object -Last 1) }
"shots: $($vals.Count), 3D arena frames: " + (@($vals | Where-Object { $_ -gt 0.45 -and $_ -lt 0.70 }).Count) + ", shares: " + (($vals | ForEach-Object { '{0:N2}' -f $_ }) -join ' ')
