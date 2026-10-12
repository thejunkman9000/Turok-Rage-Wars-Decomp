# run the game and trigger a 3-frame display-list dump once the log shows a pattern: .\port\dumpwhen.ps1 -Pattern '-> 20 ' -Delay 6 [-EnvOn TUROK_AUTOPRESS]
param([string]$Pattern = '-> 20 ', [double]$Delay = 6, [double]$Max = 90, [string[]]$EnvOn = @('TUROK_SKIPMENU', 'TUROK_AUTOPRESS'))
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
foreach ($k in $EnvOn) { Set-Item -Path "Env:$k" -Value '1' }
$env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $done = $false
while (((Get-Date) - $t0).TotalSeconds -lt $Max) {
    Start-Sleep -Milliseconds 1000
    if (-not $done -and (Select-String -Path port\build\run.log -Pattern $Pattern -ErrorAction SilentlyContinue)) { Start-Sleep $Delay; New-Item port_dumpnow.txt -ItemType File | Out-Null; $done = $true; Start-Sleep 3; break }
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
foreach ($k in $EnvOn) { Remove-Item "Env:$k" -ErrorAction SilentlyContinue }
Remove-Item Env:TUROK_LOG -ErrorAction SilentlyContinue
"triggered: $done"
