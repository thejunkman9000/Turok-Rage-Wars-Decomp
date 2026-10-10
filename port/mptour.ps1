# Walk the multiplayer menus with N players (main menu -> how many players -> character select -> loadout -> options) taking a screenshot on every screen:
# .\port\mptour.ps1 [-Players 2] [-Prefix mp]    -> port\build\mp_01.png ...       (pads 2..4 join with p2C ... p4C, TUROK_PADS=N)
param([int]$Players = 2, [string]$Prefix = 'mp')
Set-Location (Split-Path $PSScriptRoot -Parent)
$seq = @('wait:2', 'shot', 'C:0.3', 'wait:3', 'shot')                                                  # MULTIPLAYER -> how many players
for ($i = 2; $i -le $Players; $i++) { $seq += @('stick:80:0:0.25', 'wait:1') }                         # D-right per extra player
$seq += @('shot', 'C:0.3', 'wait:4', 'shot')                                                           # character select
for ($p = 2; $p -le $Players; $p++) { $seq += @("p${p}C:0.3", 'wait:1') }                              # the other pads join
$seq += @('C:0.3', 'wait:4', 'shot')                                                                   # pad 1 picks a character
for ($p = 2; $p -le $Players; $p++) { $seq += @("p${p}C:0.3", 'wait:2') }
$seq += @('shot', 'wait:4', 'shot')                                                                    # loadout
for ($p = 1; $p -le $Players; $p++) { $seq += @($(if ($p -eq 1) { 'C:0.3' } else { "p${p}C:0.3" }), 'wait:3', 'shot') }
$seq += @('C:0.3', 'wait:5', 'shot', 'C:0.3', 'wait:5', 'shot', 'C:0.3', 'wait:5', 'shot')
Get-ChildItem "port\build\${Prefix}_*.png" -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
if ($Players -gt 1) { $env:PF_ENV = "TUROK_PADS=$Players" }
& .\port\pressfile.ps1 -Prefix $Prefix -Speed 10 -Seq $seq | Out-Null
Remove-Item Env:PF_ENV -ErrorAction SilentlyContinue
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
Get-ChildItem "port\build\${Prefix}_*.png" | ForEach-Object { $_.Name }
