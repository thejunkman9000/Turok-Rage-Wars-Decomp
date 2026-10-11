# lvltest sequence with a pixel pick before every screenshot: .\port\picktest.ps1 'x:y;x:y;...' [-Prefix pk]   (PICK lines in port\build\run.log)
param([string]$Pixels = '205:184;276:184;240:120;356:265;330:300;400:330', [string]$Prefix = 'pk')
Set-Location (Split-Path $PSScriptRoot -Parent)
$pick = 'pick:' + $Pixels
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','C:0.3','wait:6','wait:4',$pick,'shot','wait:3',$pick,'shot','wait:3',$pick,'shot','wait:3',$pick,'shot','wait:3',$pick,'shot')
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
"picks in run.log: " + @(Select-String -Path port\build\run.log -Pattern '^PICK ').Count
