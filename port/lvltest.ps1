# Scripted boot -> 1 player trial level -> screenshots; prints the largest share of non-black pixels over several shots (a rendered 3D scene is > 0.3).  usage: .\port\lvltest.ps1 [-Prefix lvlt]
param([string]$Prefix = 'lvlt')
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4','shot','wait:3','shot','wait:3','shot','wait:3','shot','wait:3','shot')
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
$best = 0.0; $n = 0
Get-ChildItem "port\build\${Prefix}_*.png" | ForEach-Object { $v = [double](python port\imgstat.py $_.FullName 2>$null | Select-Object -Last 1); $n++; if ($v -gt $best) { $best = $v } }
"shots: $n, best share of non-black pixels: $best"
