# Walk the 1-player menus (main menu -> player count -> character -> loadout -> options -> level) and take a screenshot on every screen:
# .\port\menutour.ps1 [-Prefix tour]    -> port\build\tour_01.png ...  (the screens that are on the way of lvltest.ps1)
param([string]$Prefix = 'tour')
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:2', 'shot', 'stick:0:-80:0.25', 'wait:1', 'shot', 'C:0.3', 'wait:5', 'shot', 'stick:80:0:0.25', 'wait:1', 'shot', 'C:0.3', 'wait:5', 'shot', 'stick:-80:0:0.25', 'wait:1', 'shot', 'C:0.3', 'wait:5', 'shot',
        'C:0.3', 'wait:6', 'shot', 'C:0.3', 'wait:6', 'shot', 'C:0.3', 'wait:6', 'shot', 'C:0.3', 'wait:6', 'shot', 'C:0.3', 'wait:6', 'shot', 'wait:4', 'shot')
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
Get-ChildItem "port\build\${Prefix}_*.png" | ForEach-Object { $_.Name }
