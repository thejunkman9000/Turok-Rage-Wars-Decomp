# timed screenshots without input: .\port\shots.ps1 -Prefix ti -From 10 -To 50 -Step 2.5 [-Env TUROK_AUTOPRESS]
param([string]$Prefix = 'ti', [double]$From = 10, [double]$To = 50, [double]$Step = 2.5, [string[]]$EnvOn = @('TUROK_SKIPMENU'))
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
foreach ($k in $EnvOn) { Set-Item -Path "Env:$k" -Value '1' }
$env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
Get-ChildItem port\build -Filter "$Prefix`_*.png" | Remove-Item -ErrorAction SilentlyContinue
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0; $next = $From
while (((Get-Date) - $t0).TotalSeconds -lt $To) {
    Start-Sleep -Milliseconds 300
    if (((Get-Date) - $t0).TotalSeconds -ge $next) { $n++; $next += $Step; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
foreach ($k in $EnvOn) { Remove-Item "Env:$k" -ErrorAction SilentlyContinue }
Remove-Item Env:TUROK_LOG -ErrorAction SilentlyContinue
"$n shots"
