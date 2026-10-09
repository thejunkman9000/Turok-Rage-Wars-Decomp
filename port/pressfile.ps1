# drive the game through port_input.txt: .\port\pressfile.ps1 -Prefix nav -Seq 'wait:4','C:0.3','wait:2','shot','Down:0.3','shot'
# -Speed n (integer 1..50, or TUROK_SPEED=n via PF_ENV / the environment): the game runs n game frames per presented frame (TUROK_SPEED, 60 Hz paced,
# frame-based clock). Every wait/hold in -Seq is in GAME seconds: holds are written as a frame count, waits are divided by n on the wall clock.
# 'shot' is synchronous (~0.3 s wall) and the game keeps running meanwhile, so at -Speed n a screenshot costs ~0.3*n game seconds.
param([string]$Prefix = 'nav', [string[]]$Seq = @(), [double]$Menu = 100, [string]$Gate = '-> 3 ', [double]$Boot = 16, [int]$Speed = 0)
Set-Location (Split-Path $PSScriptRoot -Parent)
$btn = @{ 'A' = 0x8000; 'C' = 0x8000; 'B' = 0x4000; 'X' = 0x4000; 'Z' = 0x2000; 'Start' = 0x1000; 'Enter' = 0x1000; 'DUp' = 0x0800; 'DDown' = 0x0400; 'DLeft' = 0x0200; 'DRight' = 0x0100; 'L' = 0x0020; 'R' = 0x0010; 'CUp' = 0x0008; 'CDown' = 0x0004; 'CLeft' = 0x0002; 'CRight' = 0x0001 }
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$env:TUROK_SKIPMENU = '1'; $env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
if ($env:PF_ENV) { foreach ($kv in $env:PF_ENV.Split(',')) { $p = $kv.Split('='); Set-Item -Path ("Env:" + $p[0]) -Value $p[1] } }
if ($Speed -lt 1) { $Speed = 1; if ($env:TUROK_SPEED) { $Speed = [Math]::Max(1, [int]$env:TUROK_SPEED) } }   # the game clamps TUROK_SPEED to 1..50; the script must scale by the same value
if ($Speed -gt 50) { $Speed = 50 }
if ($env:TUROK_FF -and $Boot -eq 16) { $Boot = 2 }
if ($Speed -gt 1) { $env:TUROK_SPEED = [string]$Speed; if ($Boot -eq 16) { $Boot = [Math]::Max(2, 16 / $Speed) }; $Menu = $Menu / $Speed + 5 }
function T($sec) { if ($Speed -gt 1) { [Math]::Max(0.12, $sec / $Speed) } else { $sec } }   # game seconds -> wall seconds
$inputs = @('port_input.txt', 'port_input2.txt', 'port_input3.txt', 'port_input4.txt')
Remove-Item $inputs -ErrorAction SilentlyContinue
$null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0
# 'rm' is a built-in alias of Remove-Item and aliases win over functions, so this helper must not be called Rm
function Remove-Input($f) { for ($r = 0; $r -lt 40; $r++) { Remove-Item $f -ErrorAction SilentlyContinue; if (-not (Test-Path $f)) { return }; Start-Sleep -Milliseconds 5 } }
# the 4th field of the input file is the hold length in game frames ($sec is game seconds, so a press is the same length at any -Speed);
# the game deletes the file itself when the hold ends, the Remove-Input only catches a file the game never picked up
function Hold($f, $b, $x, $y, $sec) { $v = ('{0:X} {1} {2} {3}' -f $b, $x, $y, [Math]::Max(1, [int]($sec * 60))); for ($r = 0; $r -lt 40; $r++) { try { Set-Content -Path $f -Value $v -Encoding ascii -ErrorAction Stop; break } catch { Start-Sleep -Milliseconds 5 } }; Start-Sleep -Milliseconds ([int]((T $sec) * 1000)); Remove-Input $f }
# phase 1: get to the gate screen by tapping Start (one tap per ~1.4 game seconds)
while (((Get-Date) - $t0).TotalSeconds -lt $Menu) {
    Start-Sleep -Milliseconds ([int]((T 1) * 1000))
    if (((Get-Date) - $t0).TotalSeconds -lt $Boot) { continue }
    if (Select-String -Path port\build\run.log -Pattern $Gate -ErrorAction SilentlyContinue) { break }
    Hold 'port_input.txt' 0x1000 0 0 0.4
}
Start-Sleep -Milliseconds ([int]((T 3) * 1000))
foreach ($step in $Seq) {
    $p = $step.Split(':')
    if ($p[0] -eq 'wait') { Start-Sleep -Milliseconds ([int]((T ([double]$p[1])) * 1000)) }
    elseif ($p[0] -eq 'shot') { $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
    elseif ($p[0] -eq 'dump') { New-Item port_dumpnow.txt -ItemType File -Force | Out-Null; Start-Sleep -Milliseconds ([int]((T 2) * 1000)) }
    elseif ($p[0] -eq 'stick') { Hold 'port_input.txt' 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }
    elseif ($p[0] -match '^p([2-4])stick$') { Hold ('port_input{0}.txt' -f $Matches[1]) 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }   # pads 2..4: p2stick:x:y:sec (PF_ENV='TUROK_PADS=4')
    elseif ($p[0] -match '^p([2-4])(.+)$') { Hold ('port_input{0}.txt' -f $Matches[1]) $btn[$Matches[2]] 0 0 ([double]$p[1]) }          # p2C, p3Start, ...
    else { Hold 'port_input.txt' $btn[$p[0]] 0 0 ([double]$p[1]) }
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item $inputs -ErrorAction SilentlyContinue
Remove-Item Env:TUROK_SKIPMENU, Env:TUROK_LOG, Env:TUROK_SPEED -ErrorAction SilentlyContinue
"shots: $n"
Copy-Item port\build\run.log ("port\build\run_{0}.log" -f $Prefix) -ErrorAction SilentlyContinue
