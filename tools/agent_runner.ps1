# Agent runner: executes the job scripts that Claude drops into wip\runner\queue (one at a time, oldest name first) and keeps their output in wip\runner\done.
# Start it once in a PowerShell window from the project folder and leave the window open:
#     powershell -NoProfile -ExecutionPolicy Bypass -File tools\agent_runner.ps1
# Every job is printed here before it runs.  Stop with Ctrl+C (or create the file wip\runner\STOP).  Jobs run in this folder with your user rights, so only
# you and Claude should be able to write to wip\runner\queue.
param([int]$TimeoutMin = 45)
Set-Location (Split-Path $PSScriptRoot -Parent)
$q = 'wip\runner\queue'; $d = 'wip\runner\done'
New-Item -ItemType Directory -Force $q, $d | Out-Null
Write-Host "Agent runner started in $((Get-Location).Path): waiting for jobs in $q  (Ctrl+C stops it)" -ForegroundColor Cyan
Set-Content "$d\runner_alive.txt" (Get-Date -Format o)
while ($true) {
    if (Test-Path 'wip\runner\STOP') { Remove-Item 'wip\runner\STOP'; Write-Host 'stop requested'; break }
    $job = Get-ChildItem "$q\*.ps1" -ErrorAction SilentlyContinue | Sort-Object Name | Select-Object -First 1
    if (-not $job) { Start-Sleep -Seconds 2; Set-Content "$d\runner_alive.txt" (Get-Date -Format o); continue }
    $name = $job.BaseName; $script = "$d\$name.ps1"
    Move-Item $job.FullName $script -Force
    Write-Host "$(Get-Date -Format HH:mm:ss)  running $name" -ForegroundColor Yellow
    Get-Content $script | Where-Object { $_ -match '^#' } | Select-Object -First 3 | ForEach-Object { Write-Host "    $_" }
    Set-Content "$d\$name.running" (Get-Date -Format o)
    $env:TUROK_SCRIPT = '1'; $p = Start-Process powershell -ArgumentList '-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $script -RedirectStandardOutput "$d\$name.log" -RedirectStandardError "$d\$name.err" -PassThru -NoNewWindow -WorkingDirectory (Get-Location).Path
    if (-not $p.WaitForExit($TimeoutMin * 60000)) { try { $p.Kill() } catch {}; Add-Content "$d\$name.log" 'RUNNER: timeout, job killed' }
    $p.WaitForExit()
    $rc = $p.ExitCode
    Remove-Item "$d\$name.running" -ErrorAction SilentlyContinue
    Set-Content "$d\$name.done" "exit $rc"
    Write-Host "$(Get-Date -Format HH:mm:ss)  finished $name (exit $rc)" -ForegroundColor Green
}
