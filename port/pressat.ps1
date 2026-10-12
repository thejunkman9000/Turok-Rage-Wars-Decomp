# wait for a log pattern (after at least -Min seconds) and then run a pressfile-style sequence: .\port\pressat.ps1 -Pattern 'st=13' -Prefix x -Seq 'Start:0.3','wait:3','shot'
param([string]$Pattern = 'st=13', [string]$Prefix = 'pa', [string[]]$Seq = @(), [double]$Max = 200, [string]$Env = '')
Set-Location (Split-Path $PSScriptRoot -Parent)
$btn = @{ 'A' = 0x8000; 'C' = 0x8000; 'B' = 0x4000; 'X' = 0x4000; 'Z' = 0x2000; 'Start' = 0x1000; 'Enter' = 0x1000; 'DUp' = 0x0800; 'DDown' = 0x0400; 'DLeft' = 0x0200; 'DRight' = 0x0100; 'CUp' = 0x0008; 'CDown' = 0x0004; 'CLeft' = 0x0002; 'CRight' = 0x0001 }
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$env:TUROK_SKIPMENU = '1'; $env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
if ($Env) { foreach ($kv in $Env.Split(',')) { $p = $kv.Split('='); Set-Item -Path ("Env:" + $p[0]) -Value $p[1] } }
Remove-Item port_input.txt -ErrorAction SilentlyContinue
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0; $hit = $false
while (((Get-Date) - $t0).TotalSeconds -lt $Max) { Start-Sleep -Milliseconds 700; if (Select-String -Path port\build\run.log -Pattern $Pattern -ErrorAction SilentlyContinue) { $hit = $true; break } }
function Hold($b, $x, $y, $sec) { Set-Content -Path port_input.txt -Value ('{0:X} {1} {2}' -f $b, $x, $y) -Encoding ascii; Start-Sleep -Milliseconds ([int]($sec * 1000)); Remove-Item port_input.txt -ErrorAction SilentlyContinue }
if ($hit) { foreach ($step in $Seq) {
    $p = $step.Split(':')
    if ($p[0] -eq 'wait') { Start-Sleep -Milliseconds ([int]([double]$p[1] * 1000)) }
    elseif ($p[0] -eq 'shot') { $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
    elseif ($p[0] -eq 'stick') { Hold 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }
    else { Hold $btn[$p[0]] 0 0 ([double]$p[1]) } } }
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item port_input.txt -ErrorAction SilentlyContinue
Remove-Item Env:TUROK_SKIPMENU, Env:TUROK_LOG -ErrorAction SilentlyContinue
"hit=$hit shots=$n"
