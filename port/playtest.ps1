# Scripted boot -> 1 player trial level -> 40 game seconds of walking / turning / firing with screenshots; reports crashes (run.log) and the picture shares.  usage: .\port\playtest.ps1 [-Prefix ply]
param([string]$Prefix = 'ply')
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4','shot')
for ($i = 0; $i -lt 6; $i++) { $seq += @('CUp:3','Z:0.3','wait:1','stick:60:0:1','Z:0.3','CUp:2','wait:2','stick:-60:30:1','Z:0.3','CUp:3','shot') }
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
$vals = @(); Get-ChildItem "port\build\${Prefix}_*.png" | Sort-Object Name | ForEach-Object { $vals += [double](python port\imgstat.py $_.FullName 2>$null | Select-Object -Last 1) }
"shots: $($vals.Count), shares: " + (($vals | ForEach-Object { '{0:N2}' -f $_ }) -join ' ') + ", crashes: " + (@(Select-String -Path port\build\run.log -Pattern 'CRASH\(raw' -ErrorAction SilentlyContinue).Count)
