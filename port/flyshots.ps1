# level-start fly-through capture: .\port\flyshots.ps1 [-Range 300-700] [-Step 4] [-Div 4] [-Extra 'TUROK_PICKAT=520:175:150']
# runs the pickplay navigation to the level and lets the renderer write port\build\fs_<frame>.bmp for every <Step>th renderer frame in <Range> (TUROK_SHOTS);
# python tools\sheet.py port\build\fs_*.bmp builds contact sheets of them
param([string]$Range = '300-700', [int]$Step = 4, [int]$Div = 4, [string]$Extra = '', [int]$Speed = 1, [double]$Tail = 25)
Set-Location (Split-Path $PSScriptRoot -Parent)
Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
$env:PF_ENV = "TUROK_SHOTS=${Range}:${Step}:${Div}" + $(if ($Extra) { ",$Extra" } else { '' })
$seq = @('wait:2','stick:0:-80:0.25','wait:1','C:0.3','wait:5','stick:80:0:0.25','wait:1','C:0.3','wait:5','stick:-80:0:0.25','wait:1','C:0.3','wait:5','until:C:type 2:120','wait:4','C:0.3',"wait:$Tail")      # 'type 2' = the prompt screen's preview arena exists; one more A starts the match, then no more presses (a press skips the fly-through camera)
& .\port\pressfile.ps1 -Prefix fly -Speed $Speed -Seq $seq | Out-Null
Remove-Item Env:PF_ENV -ErrorAction SilentlyContinue
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
"shots: " + @(Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue).Count
