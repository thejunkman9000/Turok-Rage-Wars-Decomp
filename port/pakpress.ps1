# Scripted input for the Controller Pak tests: a copy of pressfile.ps1 that
#  - works on the exe named in port\build\latest_exe.txt only (find / screenshot / kill by that exact process name, never by the turok_* pattern, so it cannot
#    disturb other people's game instances and their kill loops cannot disturb this one: name the exe pakw_<time>.exe, see tools\linkpak.ps1),
#  - does NOT set TUROK_SKIPMENU (the pak screen has to be played now) unless -SkipMenu is given,
#  - takes extra environment variables as a hashtable (-EnvVars @{ TUROK_PAK = '0'; TUROK_SAVEDIR = 'x' }),
#  - has extra steps:  pak:<command>   writes port_pak.txt (insert 2 memory | remove 1 | flush | reload 1 | format 1 | status),
#                      waitlog:<text>:<game seconds>   waits until <text> shows up in NEW log lines,
#                      sleep:<ms>      wall-clock pause (write-back debounce),
#                      logmark         remembers the log length for the next waitlog.
# usage: .\port\pakpress.ps1 -Prefix pk -Speed 10 -Seq 'wait:2','shot','C:0.3' -EnvVars @{ TUROK_SAVEDIR = 'port\build\s1' }
param([string]$Prefix = 'pk', [string[]]$Seq = @(), [double]$Menu = 100, [string]$Gate = '-> 3 ', [double]$Boot = 16, [int]$Speed = 0,
      [hashtable]$EnvVars = @{}, [switch]$SkipMenu, [switch]$NoKill, [string]$Log = 'port\build\pak_run.log', [switch]$NoTap, [string]$Exe = '')
Set-Location (Split-Path $PSScriptRoot -Parent)
$btn = @{ 'A' = 0x8000; 'C' = 0x8000; 'B' = 0x4000; 'X' = 0x4000; 'Z' = 0x2000; 'Start' = 0x1000; 'Enter' = 0x1000; 'DUp' = 0x0800; 'DDown' = 0x0400; 'DLeft' = 0x0200; 'DRight' = 0x0100; 'L' = 0x0020; 'R' = 0x0010; 'CUp' = 0x0008; 'CDown' = 0x0004; 'CLeft' = 0x0002; 'CRight' = 0x0001 }
$exe = if ($Exe) { $Exe } else { (Get-Content port\build\latest_exe.txt).Trim() }; $name = [IO.Path]::GetFileNameWithoutExtension($exe)
if ($name -like 'turok_*') { Write-Warning "exe '$name' matches the turok_* kill pattern of the old test scripts; rename it (tools\linkpak.ps1)" }
$logFull = Join-Path (Get-Location) $Log
if ($SkipMenu) { $env:TUROK_SKIPMENU = '1' } else { Remove-Item Env:TUROK_SKIPMENU -ErrorAction SilentlyContinue }
$env:TUROK_LOG = $logFull
$setEnv = @('TUROK_LOG')
foreach ($k in $EnvVars.Keys) { Set-Item -Path ("Env:" + $k) -Value ([string]$EnvVars[$k]); $setEnv += $k }
if ($Speed -lt 1) { $Speed = 1; if ($env:TUROK_SPEED) { $Speed = [Math]::Max(1, [int]$env:TUROK_SPEED) } }
if ($Speed -gt 50) { $Speed = 50 }
if ($Speed -gt 1) { $env:TUROK_SPEED = [string]$Speed; $setEnv += 'TUROK_SPEED'; if ($Boot -eq 16) { $Boot = [Math]::Max(2, 16 / $Speed) }; $Menu = $Menu / $Speed + 5 }
function T($sec) { if ($Speed -gt 1) { [Math]::Max(0.12, $sec / $Speed) } else { $sec } }
function Frame() { for ($r = 0; $r -lt 20; $r++) { try { return [long]([IO.File]::ReadAllText((Join-Path (Get-Location).Path 'port_frame.txt')).Trim()) } catch { Start-Sleep -Milliseconds 5 } }; return -1 }
function WaitFrames($sec) {
    $f0 = Frame; if ($f0 -lt 0) { Start-Sleep -Milliseconds ([int]((T $sec) * 1000)); return }
    $target = $f0 + [long]($sec * 60); $limit = (T $sec) * 4 + 2; $t1 = Get-Date
    while ((Frame) -lt $target -and ((Get-Date) - $t1).TotalSeconds -lt $limit) { Start-Sleep -Milliseconds 8 }
}
$inputs = @('port_input.txt', 'port_input2.txt', 'port_input3.txt', 'port_input4.txt', 'port_frame.txt', 'port_frame.tmp', 'port_pak.txt')
Remove-Item $inputs -ErrorAction SilentlyContinue
Remove-Item $logFull -ErrorAction SilentlyContinue
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0; $mark = 0
function Remove-Input($f) { for ($r = 0; $r -lt 40; $r++) { Remove-Item $f -ErrorAction SilentlyContinue; if (-not (Test-Path $f)) { return }; Start-Sleep -Milliseconds 5 } }
function Hold($f, $b, $x, $y, $sec) { $v = ('{0:X} {1} {2} {3}' -f $b, $x, $y, [Math]::Max(1, [int]($sec * 60))); for ($r = 0; $r -lt 40; $r++) { try { Set-Content -Path $f -Value $v -Encoding ascii -ErrorAction Stop; break } catch { Start-Sleep -Milliseconds 5 } }; WaitFrames $sec; Remove-Input $f }
function LogLines() { @(Get-Content $logFull -ErrorAction SilentlyContinue).Count }
# phase 1: tap Start until the gate screen shows up in the log
while (-not $NoTap -and ((Get-Date) - $t0).TotalSeconds -lt $Menu) {
    Start-Sleep -Milliseconds ([int]((T 1) * 1000))
    if (((Get-Date) - $t0).TotalSeconds -lt $Boot) { continue }
    if (Select-String -Path $logFull -Pattern $Gate -SimpleMatch -ErrorAction SilentlyContinue) { break }
    Hold 'port_input.txt' 0x1000 0 0 0.4
}
WaitFrames 3
foreach ($step in $Seq) {
    $p = $step.Split(':')
    if ($p[0] -eq 'wait') { WaitFrames ([double]$p[1]) }
    elseif ($p[0] -eq 'shot') { $n++; & "$PSScriptRoot\..\tools\pak_shot.ps1" -ProcName $name -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
    elseif ($p[0] -eq 'sleep') { Start-Sleep -Milliseconds ([int]$p[1]) }
    elseif ($p[0] -eq 'pak') { Set-Content -Path port_pak.txt -Value $step.Substring(4) -Encoding ascii; for ($r = 0; $r -lt 100 -and (Test-Path port_pak.txt); $r++) { Start-Sleep -Milliseconds 20 } }
    elseif ($p[0] -eq 'logmark') { $mark = LogLines }
    elseif ($p[0] -eq 'waitlog') {    # waitlog:<text>:<game seconds>  (text may not contain ':'; use logmark first to ignore older lines)
        $pat = ($p[1..($p.Count - 2)] -join ':'); $lim = [double]$p[$p.Count - 1]; $t1 = Get-Date; $hit = $false
        while (((Get-Date) - $t1).TotalSeconds -lt (T $lim)) {
            if (Select-String -Path $logFull -SimpleMatch $pat -ErrorAction SilentlyContinue | Where-Object { $_.LineNumber -gt $mark }) { $hit = $true; break }
            Start-Sleep -Milliseconds 50
        }
        if (-not $hit) { "waitlog: '$pat' not seen within $lim s" }
    }
    elseif ($p[0] -match '^until(?:p([2-4]))?$') {
        $f = if ($Matches[1]) { 'port_input{0}.txt' -f $Matches[1] } else { 'port_input.txt' }; $b = $btn[$p[1]]; $pat = $p[2]; $lim = [double]$p[3]
        $skip = [Math]::Max(0, (LogLines) - 100); $t1 = Get-Date; $hits = 0
        while (((Get-Date) - $t1).TotalSeconds -lt (T $lim)) {
            if (Select-String -Path $logFull -SimpleMatch $pat -ErrorAction SilentlyContinue | Where-Object { $_.LineNumber -gt $skip }) { $hits = 1; break }
            Hold $f $b 0 0 0.3; WaitFrames 1.2
        }
        if (-not $hits) { "until: '$pat' not seen within $lim s" }
    }
    elseif ($p[0] -eq 'stick') { Hold 'port_input.txt' 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }
    elseif ($p[0] -eq 'mix') { Hold 'port_input.txt' $btn[$p[1]] ([int]$p[2]) ([int]$p[3]) ([double]$p[4]) }
    elseif ($p[0] -match '^p([2-4])stick$') { Hold ('port_input{0}.txt' -f $Matches[1]) 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) }
    elseif ($p[0] -match '^p([2-4])(.+)$') { Hold ('port_input{0}.txt' -f $Matches[1]) $btn[$Matches[2]] 0 0 ([double]$p[1]) }
    else { Hold 'port_input.txt' $btn[$p[0]] 0 0 ([double]$p[1]) }
}
if (-not $NoKill) { Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} } }
Remove-Item $inputs -ErrorAction SilentlyContinue
foreach ($k in $setEnv) { Remove-Item ("Env:" + $k) -ErrorAction SilentlyContinue }
Remove-Item Env:TUROK_SKIPMENU -ErrorAction SilentlyContinue
"shots: $n"
