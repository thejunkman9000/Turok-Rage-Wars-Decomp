# playtest sequence with a pixel pick before every screenshot: .\port\pickplay.ps1 'x:y;x:y;...' [-Prefix pp]   (PICK lines in port\build\run.log, one block per shot)
param([string]$Pixels = '175:150;200:180;215:220;190:240;230:180', [string]$Prefix = 'pp')
Set-Location (Split-Path $PSScriptRoot -Parent)
$pick = 'pick:' + $Pixels
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4',$pick,'shot')
for ($i = 0; $i -lt 6; $i++) { $seq += @('CUp:3','Z:0.3','wait:1','stick:60:0:1','Z:0.3','CUp:2','wait:2','stick:-60:30:1','Z:0.3','CUp:3',$pick,'shot') }
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
"picks in run.log: " + @(Select-String -Path port\build\run.log -Pattern '^PICK ').Count
