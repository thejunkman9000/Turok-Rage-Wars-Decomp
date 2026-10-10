# One-command regression check of the port after any rebuild: scripted 1-player flow (-Soak runs), attract demo, 40 s playtest, menu tours (1P and 2P),
# and a screenshot comparison of the tours against the baseline set in wip\base_shots (python port\imgdiff.py).
# usage: .\port\verify.ps1 [-Soak 3] [-Quick]       (-Quick: soak + demo only)
param([int]$Soak = 3, [switch]$Quick)
Set-Location (Split-Path $PSScriptRoot -Parent)
"== soak"; & .\port\soak.ps1 -N $Soak -Tag vsoak 2>&1 | Out-String
"== demo"; & .\port\demotest.ps1 2>&1 | Out-String
"   crashes in demo log: " + @(Select-String -Path port\build\run.log -Pattern 'CRASH\(raw' -ErrorAction SilentlyContinue).Count + ", softfault sites: " + @(Select-String -Path port\build\run.log -Pattern '^SOFTFAULT' -ErrorAction SilentlyContinue).Count
if ($Quick) { return }
"== playtest"; & .\port\playtest.ps1 2>&1 | Out-String
"== tours"
& .\port\menutour.ps1 -Prefix tour 2>&1 | Out-Null
& .\port\mptour.ps1 -Players 2 -Prefix mp 2>&1 | Out-Null
if (Test-Path wip\base_shots) {
    "-- 1P menu tour vs baseline";   python port\imgdiff.py wip\base_shots port\build tour 2>&1 | Out-String
    "-- 2P menu tour vs baseline";   python port\imgdiff.py wip\base_shots port\build mp 2>&1 | Out-String
}
