# Run the latest build for N seconds from the project root and print the log (+ symbolized crash).  usage: .\port\run.ps1 [-Seconds 8] [-Tail 30]
param([int]$Seconds = 8, [int]$Tail = 30)
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = (Get-Content port\build\latest_exe.txt).Trim()
$p = Start-Process $exe -WorkingDirectory (Get-Location).Path -PassThru
Start-Sleep $Seconds
"alive: $(-not $p.HasExited)"
if (-not $p.HasExited) { try { $p.Kill() } catch { 'could not kill (' + $_.Exception.Message + ')' } }
Get-Content port_log.txt | Select-Object -Last $Tail
python port\where.py | Select-Object -First 14
