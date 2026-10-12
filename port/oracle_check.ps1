# Determinism check for oracle mode: run the newest build headless several times with the same input and compare the traces.
#   .\port\oracle_check.ps1 [-Frames 300] [-Runs 3] [-Replay input.txt] [-Pages]
param([int]$Frames = 300, [int]$Runs = 3, [string]$Replay = '', [switch]$Pages)
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = (Get-Content port\build\latest_exe.txt).Trim()
$out = Join-Path $env:TEMP 'oracle_check'; New-Item -ItemType Directory -Force $out | Out-Null
$env:TUROK_FRAMES = "$Frames"
if ($Replay) { $env:TUROK_REPLAY = (Resolve-Path $Replay).Path }
if ($Pages) { $env:TUROK_TRACE_PAGES = '1' }
$good = @()
for ($i = 1; $i -le $Runs; $i++) {
    $env:TUROK_TRACE = "$out\trace$i.txt"; Remove-Item $env:TUROK_TRACE -ErrorAction SilentlyContinue
    $env:TUROK_SCRIPT = '1'; $p = Start-Process $exe -WorkingDirectory (Get-Location).Path -PassThru
    if (-not $p.WaitForExit(180000)) { $p.Kill(); "run ${i}: timed out"; continue }
    if ($p.ExitCode -ne 0) { "run ${i}: exit code $($p.ExitCode)"; continue }
    $good += "$out\trace$i.txt"
}
Remove-Item Env:TUROK_FRAMES, Env:TUROK_TRACE, Env:TUROK_REPLAY, Env:TUROK_TRACE_PAGES -ErrorAction SilentlyContinue
"$($good.Count) of $Runs runs completed"
for ($k = 1; $k -lt $good.Count; $k++) {
    $a = Get-Content $good[0]; $b = Get-Content $good[$k]; $div = -1
    for ($i = 0; $i -lt [Math]::Min($a.Count, $b.Count); $i++) { if ($a[$i] -ne $b[$i]) { $div = $i; break } }
    if ($div -lt 0) { "run 1 vs run $($k + 1): identical over $($a.Count) frames" } else { "run 1 vs run $($k + 1): first divergence at frame $div" }
}
