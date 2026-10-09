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
function T($sec) { if ($Speed -gt 1) { [Math]::Max(0.12, $sec / $Speed) } else { $sec } }   # game seconds -> wall seconds (safety limits only)
# the game publishes its frame counter in port_frame.txt every 6 frames; waits are in game frames so a loaded host (below n x 60 fps) does not desynchronise the sequence
function Frame() { for ($r = 0; $r -lt 20; $r++) { try { return [long]([IO.File]::ReadAllText((Join-Path (Get-Location).Path 'port_frame.txt')).Trim()) } catch { Start-Sleep -Milliseconds 5 } }; return -1 }
function WaitFrames($sec) {
    $f0 = Frame; if ($f0 -lt 0) { Start-Sleep -Milliseconds ([int]((T $sec) * 1000)); return }
    $target = $f0 + [long]($sec * 60); $limit = (T $sec) * 4 + 2; $t1 = Get-Date
    while ((Frame) -lt $target -and ((Get-Date) - $t1).TotalSeconds -lt $limit) { Start-Sleep -Milliseconds 8 }
}
$inputs = @('port_input.txt', 'port_input2.txt', 'port_input3.txt', 'port_input4.txt', 'port_frame.txt', 'port_frame.tmp')
Remove-Item $inputs -ErrorAction SilentlyContinue
$null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0
# 'rm' is a built-in alias of Remove-Item and aliases win over functions, so this helper must not be called Rm
function Remove-Input($f) { for ($r = 0; $r -lt 40; $r++) { Remove-Item $f -ErrorAction SilentlyContinue; if (-not (Test-Path $f)) { return }; Start-Sleep -Milliseconds 5 } }
# the 4th field of the input file is the hold length in game frames ($sec is game seconds, so a press is the same length at any -Speed);
# the game deletes the file itself when the hold ends, the Remove-Input only catches a file the game never picked up
function Hold($f, $b, $x, $y, $sec) { $v = ('{0:X} {1} {2} {3}' -f $b, $x, $y, [Math]::Max(1, [int]($sec * 60))); for ($r = 0; $r -lt 40; $r++) { try { Set-Content -Path $f -Value $v -Encoding ascii -ErrorAction Stop; break } catch { Start-Sleep -Milliseconds 5 } }; WaitFrames $sec; Remove-Input $f }
# phase 1: get to the gate screen by tapping Start (one tap per ~1.4 game seconds)
while (((Get-Date) - $t0).TotalSeconds -lt $Menu) {
    Start-Sleep -Milliseconds ([int]((T 1) * 1000))
    if (((Get-Date) - $t0).TotalSeconds -lt $Boot) { continue }
    if (Select-String -Path port\build\run.log -Pattern $Gate -ErrorAction SilentlyContinue) { break }
    Hold 'port_input.txt' 0x1000 0 0 0.4
}
WaitFrames 3
foreach ($step in $Seq) {
    $p = $step.Split(':')
    if ($p[0] -eq 'wait') { WaitFrames ([double]$p[1]) }
    elseif ($p[0] -eq 'shot') { $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
    elseif ($p[0] -eq 'mapdump') { Set-Content port_mapdump.txt $p[1] -Encoding ascii; WaitFrames 3 }      # TUROK_MAPDUMP=1: write mapdump/<name>/map.obj (static triangles seen so far)
    elseif ($p[0] -eq 'ramdump') { Remove-Item port_ram.bin -ErrorAction SilentlyContinue; Copy-Item port_cam.txt ("port\build\ram_{0}.cam" -f $p[1]) -ErrorAction SilentlyContinue; New-Item port_ramdump.txt -ItemType File -Force | Out-Null; WaitFrames 3; Start-Sleep -Milliseconds 800; Move-Item port_ram.bin ("port\build\ram_{0}.bin" -f $p[1]) -Force -ErrorAction SilentlyContinue }   # full 8 MB guest RAM + camera position (TUROK_MAPDUMP=1)
    elseif ($p[0] -eq 'mapreset') { New-Item port_mapreset.txt -ItemType File -Force | Out-Null; WaitFrames 1 }
    elseif ($p[0] -eq 'dump') { New-Item port_dumpnow.txt -ItemType File -Force | Out-Null; WaitFrames 2 }
    elseif ($p[0] -match '^until(?:p([2-4]))?$') {   # until:C:-> 2 (top=0):30  = press A every 1.2 game-s until the pattern appears in NEW log lines (30 game-s limit); untilp2:... for pad 2
        $f = if ($Matches[1]) { 'port_input{0}.txt' -f $Matches[1] } else { 'port_input.txt' }; $b = $btn[$p[1]]; $pat = $p[2]; $lim = [double]$p[3]
        $skip = [Math]::Max(0, @(Get-Content port/build/run.log -ErrorAction SilentlyContinue).Count - 100); $t1 = Get-Date; $hits = 0   # 100-line lookback: the target may already be up
        while (((Get-Date) - $t1).TotalSeconds -lt (T $lim)) {
            if (Select-String -Path port/build/run.log -SimpleMatch $pat -ErrorAction SilentlyContinue | Where-Object { $_.LineNumber -gt $skip }) { $hits = 1; break }
            Hold $f $b 0 0 0.3; WaitFrames 1.2
        }
        if (-not $hits) { "until: '$pat' not seen within $lim s (skip $skip, log now " + @(Get-Content port/build/run.log -ErrorAction SilentlyContinue).Count + " lines, matches anywhere " + @(Select-String -Path port/build/run.log -SimpleMatch $pat -ErrorAction SilentlyContinue).Count + ')' }
    }
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
