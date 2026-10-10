# Random-input soak of the port: boots to the main menu, then presses random buttons / stick positions for a number of game seconds
# (TUROK_SPEED runs several game frames per presented frame, so 10 wall-clock minutes at -Speed 10 are ~100 game minutes).
# usage: .\port\fuzz.ps1 -Seed 1 [-Steps 400] [-Speed 10] [-Pads 1]      prints one verdict line + crash summary (port\crashsum.py); the log is kept as port\build\fuzz_<seed>.log
# The same seed gives the same input sequence (the game itself is not deterministic: audio/timer threads), so a crash is re-run by seed only as a hint.
param([int]$Seed = 1, [int]$Steps = 400, [int]$Speed = 10, [int]$Pads = 1, [switch]$Strict)
Set-Location (Split-Path $PSScriptRoot -Parent)
$rnd = New-Object System.Random($Seed)
$buttons = @('A', 'A', 'A', 'B', 'Start', 'Z', 'Z', 'CUp', 'CDown', 'CLeft', 'CRight', 'DUp', 'DDown', 'DLeft', 'DRight', 'L', 'R')
$seq = @()
for ($i = 0; $i -lt $Steps; $i++) {
    $r = $rnd.Next(100)
    if ($r -lt 30) { $seq += ('{0}:{1:N2}' -f $buttons[$rnd.Next($buttons.Count)], (0.1 + 0.3 * $rnd.NextDouble())); $seq += ('wait:{0:N2}' -f (0.2 + 1.3 * $rnd.NextDouble())) }
    elseif ($r -lt 55) { $seq += ('stick:{0}:{1}:{2:N2}' -f ($rnd.Next(-80, 81)), ($rnd.Next(-80, 81)), (0.3 + 2.2 * $rnd.NextDouble())) }
    elseif ($r -lt 80) { $seq += ('mix:{0}:{1}:{2}:{3:N2}' -f $buttons[$rnd.Next($buttons.Count)], ($rnd.Next(-80, 81)), ($rnd.Next(-80, 81)), (0.2 + 2.0 * $rnd.NextDouble())) }
    elseif ($r -lt 90 -and $Pads -gt 1) { $seq += ('p{0}{1}:{2:N2}' -f $rnd.Next(2, $Pads + 1), $buttons[$rnd.Next($buttons.Count)], (0.1 + 0.3 * $rnd.NextDouble())) }
    else { $seq += ('wait:{0:N2}' -f (0.5 + 2.5 * $rnd.NextDouble())) }
}
$pfenv = @(); if ($Pads -gt 1) { $pfenv += "TUROK_PADS=$Pads" }; if ($Strict) { $pfenv += "TUROK_STRICT=1" }      # -Strict: no soft recovery of null-page faults (port/softfault.c): the first fault is the crash
if ($pfenv.Count) { $env:PF_ENV = $pfenv -join "," }
$t0 = Get-Date
& .\port\pressfile.ps1 -Prefix "fz$Seed" -Speed $Speed -Seq $seq | Out-Null
$wall = [int]((Get-Date) - $t0).TotalSeconds
Get-Process | Where-Object { $_.ProcessName -like 'turok_*' } | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item Env:PF_ENV -ErrorAction SilentlyContinue
Copy-Item port\build\run.log ("port\build\fuzz_{0}.log" -f $Seed) -ErrorAction SilentlyContinue
$sum = python port\crashsum.py port\build\run.log 2>&1 | Out-String
$crashed = $LASTEXITCODE -ne 0
"seed $Seed steps $Steps speed $Speed pads $Pads wall ${wall}s -> $(if ($crashed) { 'CRASH' } else { 'ok' })"
$sum.Trim()
