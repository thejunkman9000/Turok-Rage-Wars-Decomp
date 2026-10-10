# Run the scripted 1-player flow N times and report per run: crash, last game state, picture share.  usage: .\port\soak.ps1 [-N 6] [-Tag soak]
param([int]$N = 6, [string]$Tag = 'soak')
Set-Location (Split-Path $PSScriptRoot -Parent)
$pass = 0
for ($i = 1; $i -le $N; $i++) {
    $before = (Get-Item port\build\run.log -ErrorAction SilentlyContinue).LastWriteTime
    $out = & .\port\lvltest.ps1 -Prefix "$Tag$i" 2>&1 | Out-String
    $m = [regex]::Match($out, 'best share of non-black pixels: ([0-9.]+)')
    $share = if ($m.Success) { $m.Groups[1].Value } else { 'n/a' }
    $log = Get-Content port\build\run.log -ErrorAction SilentlyContinue
    $fresh = ((Get-Item port\build\run.log).LastWriteTime -gt $before)
    $crash = @($log | Select-String 'CRASH\(raw').Count
    $st = ($log | Select-String 'game state: g=\w+ st=(\d+)' | Select-Object -Last 1).Matches.Groups[1].Value
    $reached = [bool]($log | Select-String 'game state: g=\w+ st=13')
    $ok = ($crash -eq 0) -and $reached -and ([double]($share -replace 'n/a', '0') -gt 0.3)
    if ($ok) { $pass++ }
    "run$i fresh=$fresh crash=$crash laststate=$st st13=$reached share=$share -> $(if ($ok) { 'PASS' } else { 'fail' })"
}
"SOAK $pass/$N passed"
