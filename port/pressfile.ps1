# drive the game through port_input.txt: .\port\pressfile.ps1 -Prefix nav -Seq 'wait:4','C:0.3','wait:2','shot','Down:0.3','shot'
param([string]$Prefix = 'nav', [string[]]$Seq = @(), [double]$Menu = 100, [string]$Gate = '-> 3 ')
Set-Location (Split-Path $PSScriptRoot -Parent)
$btn = @{ 'A' = 0x8000; 'C' = 0x8000; 'B' = 0x4000; 'X' = 0x4000; 'Z' = 0x2000; 'Start' = 0x1000; 'Enter' = 0x1000; 'DUp' = 0x0800; 'DDown' = 0x0400; 'DLeft' = 0x0200; 'DRight' = 0x0100; 'L' = 0x0020; 'R' = 0x0010; 'CUp' = 0x0008; 'CDown' = 0x0004; 'CLeft' = 0x0002; 'CRight' = 0x0001 }
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$env:TUROK_SKIPMENU = '1'; $env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
if ($env:PF_ENV) { foreach ($kv in $env:PF_ENV.Split(',')) { $p = $kv.Split('='); Set-Item -Path ("Env:" + $p[0]) -Value $p[1] } }
Remove-Item port_input.txt -ErrorAction SilentlyContinue
$null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0
function Hold($b, $x, $y, $sec) { Set-Content -Path port_input.txt -Value ('{0:X} {1} {2}' -f $b, $x, $y) -Encoding ascii; Start-Sleep -Milliseconds ([int]($sec * 1000)); Remove-Item port_input.txt -ErrorAction SilentlyContinue }
# phase 1: get to the gate screen by tapping Start
while (((Get-Date) - $t0).TotalSeconds -lt $Menu) {
    Start-Sleep -Milliseconds 1000
    if (((Get-Date) - $t0).TotalSeconds -lt 16) { continue }
    if (Select-String -Path port\build\run.log -Pattern $Gate -ErrorAction SilentlyContinue) { break }
    Hold 0x1000 0 0 0.4
}
Start-Sleep 3
foreach ($step in $Seq) {
    $p = $step.Split(':')
    if ($p[0] -eq 'wait') { Start-Sleep -Milliseconds ([int]([double]$p[1] * 1000)) }
    elseif ($p[0] -eq 'shot') { $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
    elseif ($p[0] -eq 'stick') { Hold 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }
    else { Hold $btn[$p[0]] 0 0 ([double]$p[1]) }
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item port_input.txt -ErrorAction SilentlyContinue
Remove-Item Env:TUROK_SKIPMENU, Env:TUROK_LOG -ErrorAction SilentlyContinue
"shots: $n"
