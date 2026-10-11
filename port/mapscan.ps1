# lvltest sequence with the static map capture: .\port\mapscan.ps1 [-Name scan]  -> mapdump\<name>\map.obj (needs TUROK_MAPDUMP=1, set here); then python tools\uvscan.py mapdump\<name>\map.obj
param([string]$Name = 'scan')
Set-Location (Split-Path $PSScriptRoot -Parent)
$env:PF_ENV = 'TUROK_MAPDUMP=1'
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:12',"mapdump:$Name",'wait:4','shot')
& .\port\pressfile.ps1 -Prefix ms -Speed 10 -Seq $seq | Out-Null
Remove-Item Env:PF_ENV -ErrorAction SilentlyContinue
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
"mapdump: " + (Test-Path "mapdump\$Name\map.obj")
