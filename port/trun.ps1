# test run helper: .\port\trun.ps1 -Seconds 60 -Env @{TUROK_SKIPMENU='1'} -Log port\build\run.log [-Shots 4]
param([int]$Seconds = 60, [hashtable]$Env = @{}, [string]$Log = 'port\build\run.log', [int]$Shots = 0)
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = (Get-Content port\build\latest_exe.txt).Trim()
foreach ($k in $Env.Keys) { Set-Item -Path "Env:$k" -Value $Env[$k] }
$env:TUROK_LOG = (Join-Path (Get-Location) $Log)
Remove-Item $env:TUROK_LOG -ErrorAction SilentlyContinue
$null = Start-Process $exe -WorkingDirectory (Get-Location).Path -PassThru; $name = [IO.Path]::GetFileNameWithoutExtension($exe)   # the exe may relaunch itself (new ASLR layout): track the process by name
$t0 = Get-Date; $n = 0; $gone = 0
while (((Get-Date) - $t0).TotalSeconds -lt $Seconds) {
    Start-Sleep -Milliseconds 500
    if ($Shots -gt 0 -and ((Get-Date) - $t0).TotalSeconds -ge ($n + 1) * ($Seconds / ($Shots + 1))) { $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\shot_run_$n.png") | Out-Null }
    if (-not (Get-Process -Name $name -ErrorAction SilentlyContinue)) { $gone++; if ($gone -ge 8 -and ((Get-Date) - $t0).TotalSeconds -gt 10) { break } } else { $gone = 0 }   # the exe relaunches itself: tolerate a short gap
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
foreach ($k in $Env.Keys) { Remove-Item "Env:$k" -ErrorAction SilentlyContinue }
Remove-Item Env:TUROK_LOG -ErrorAction SilentlyContinue
"still running at end: $(@(Get-Process -Name $name -ErrorAction SilentlyContinue).Count)"
