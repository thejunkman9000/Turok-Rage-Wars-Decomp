# repeat the level-start fly-through capture until the match starts in the mostly-green central room (the spawn room varies from run to run):
#   .\port\flygreen.ps1 [-Max 6] [-Range 380-680] [-Step 2]      -> port\build\fs_<frame>.bmp of the first green run, then python tools\sheet.py 'port\build\fs_*.bmp'
param([int]$Max = 6, [string]$Range = '380-680', [int]$Step = 2, [int]$Speed = 10)
Set-Location (Split-Path $PSScriptRoot -Parent)
for ($i = 1; $i -le $Max; $i++) {
    & .\port\flyshots.ps1 -Range $Range -Step $Step -Div 4 -Speed $Speed | Out-Null
    $last = Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue | Sort-Object Name | Select-Object -Last 1
    if (-not $last) { "attempt ${i}: no shots"; continue }
    $cls = python tools\roomcolor.py $last.FullName
    "attempt ${i}: $cls"
    if ($cls -match '-> green') { "green spawn on attempt $i"; break }
}
