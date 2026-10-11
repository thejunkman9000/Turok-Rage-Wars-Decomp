# one fly-through capture + contact sheet: .\port\flyrun.ps1 -Tag 1 [-Range 410-470] [-Step 2]  -> port\build\flyrun_<Tag>.png (and the frames in port\build\fs_*.bmp)
param([string]$Tag = '1', [string]$Range = '410-470', [int]$Step = 2, [int]$Div = 4, [double]$Tail = 8)
Set-Location (Split-Path $PSScriptRoot -Parent)
& .\port\flyshots.ps1 -Range $Range -Step $Step -Div $Div -Speed 10 -Tail $Tail | Out-Null
python tools\sheet.py 'port\build\fs_*.bmp' --cols 6 --per 30 --scale 0.5 --out ("port/build/flyrun_" + $Tag) | Out-Null
Copy-Item "port\build\flyrun_${Tag}_00.png" "port\build\flyrun_${Tag}.png" -Force -ErrorAction SilentlyContinue
"flyrun ${Tag}: " + @(Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue).Count + ' frames'
