# End-to-end tests of the virtual Controller Pak through the real game (scripted input, run log, screenshots, tools\pak_tool.py).
#   .\port\paktest.ps1                      all tests (about 10-12 minutes; the optional soak / timing tests run only when named)
#   .\port\paktest.ps1 -Test lvl-pak,create  selected tests;  -List shows the names
# Needs port\build\latest_exe.txt to name an exe that does NOT match turok_* (use tools\linkpak.ps1), baserom.us.v11.z64 in the project root, python.
# Every test uses its own save folder under port\build\paktest\ and kills only its own exe name.  Results: PASS/FAIL lines, exit code = number of failures.
param([string[]]$Test = @('all'), [switch]$List, [int]$Speed = 10, [string]$Exe = '')
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
$W = Join-Path $root 'port\build\paktest'; New-Item -ItemType Directory -Force $W | Out-Null
$Tool = 'tools\pak_tool.py'
$script:fails = 0; $script:passes = 0
$dn = @('stick:0:-80:0.1', 'wait:0.8'); $lf = @('stick:-80:0:0.1', 'wait:0.8'); $rt = @('stick:80:0:0.1', 'wait:0.8')
function Ok($cond, $msg) { if ($cond) { $script:passes++; "  PASS  $msg" } else { $script:fails++; "  FAIL  $msg" } }
function Pak($sd, $n = 1) { Join-Path $sd ("Turok; Rage Wars_Cont_{0}.mpk" -f $n) }
function NewDir($name) { $d = Join-Path $W $name; if (Test-Path $d) { Remove-Item $d -Recurse -Force -ErrorAction SilentlyContinue }; New-Item -ItemType Directory -Force $d | Out-Null; $d }
function Press([string[]]$seq, [hashtable]$ev = @{}, [string]$prefix = 'pt', [int]$speed = $Speed, [switch]$SkipMenu, [string]$log = 'port\build\paktest\run.log') {
    $e = @{ TUROK_PAKSYNC = '1' }; foreach ($k in $ev.Keys) { $e[$k] = $ev[$k] }
    $a = @{ Prefix = $prefix; Seq = $seq; Speed = $speed; EnvVars = $e; Log = $log }
    if ($Exe) { $a.Exe = $Exe }; if ($SkipMenu) { $a.SkipMenu = $true }
    & "$PSScriptRoot\pakpress.ps1" @a | Out-Null
}
function Lines($log = 'port\build\paktest\run.log') { @(Get-Content (Join-Path $root $log) -ErrorAction SilentlyContinue) }
function LogHas($lg, $pat) { if (-not (Test-Path $lg)) { return $false }; [bool](Select-String -Path $lg -Pattern $pat -ErrorAction SilentlyContinue | Select-Object -First 1) }
function Info($file) { (& python $Tool info $file) -join "`n" }
function Verdict($file) { & python $Tool info $file | Out-Null; $LASTEXITCODE }
function Kill-Mine { $n = [IO.Path]::GetFileNameWithoutExtension($(if ($Exe) { $Exe } else { (Get-Content port\build\latest_exe.txt).Trim() })); Get-Process -Name $n -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} } }
function Share($png) { [double](python port\imgstat.py $png 2>$null | Select-Object -Last 1) }
function Shots($prefix) { Get-ChildItem port\build -Filter "${prefix}_*.png" -ErrorAction SilentlyContinue | Sort-Object Name }
function Clean-Shots($prefix) { foreach ($x in Shots $prefix) { Remove-Item $x.FullName -ErrorAction SilentlyContinue } }

# main menu -> 1 PLAYER TRIALS ... -> level.  With a pak: [CREATE PLAYER? NO] -> [UNABLE TO SAVE: OK] -> the usual screens.
$lvlNoPak = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:-80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'wait:4', 'shot', 'wait:3', 'shot', 'wait:3', 'shot')
$lvlPak = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'waitlog:pak: idle:20', 'C:0.3', 'wait:5', 'stick:-80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'wait:4', 'shot', 'wait:3', 'shot', 'wait:3', 'shot')

function Run-Level($tag, $ev, [switch]$NoPak) {
    $pfx = "ptl_$tag"; Clean-Shots $pfx
    $t0 = Get-Date
    if ($NoPak) { Press $lvlNoPak $ev $pfx -SkipMenu } else { Press $lvlPak $ev $pfx }
    $el = ((Get-Date) - $t0).TotalSeconds
    Kill-Mine
    $l = Lines
    $crash = @($l | Select-String 'CRASH\(raw').Count
    $reached = [bool]($l | Select-String 'game state: g=\w+ st=13')
    $best = 0.0; foreach ($s in Shots $pfx) { $v = Share $s.FullName; if ($v -gt $best) { $best = $v } }
    [pscustomobject]@{ Crash = $crash; St13 = $reached; Share = $best; Seconds = [int]$el }
}

$tests = [ordered]@{}
$tests['selftest'] = {
    $out = & "$PSScriptRoot\tests\pak_selftest.ps1" 2>&1 | Where-Object { $_ -notmatch '^pak:' } | Out-String
    $m = [regex]::Match($out, '(\d+) checks passed, (\d+) failed')
    Ok ($m.Success -and $m.Groups[2].Value -eq '0') ("host self test: " + $m.Value)
}
$tests['pytool'] = { $o = & python $Tool selftest 2>&1; Ok ($LASTEXITCODE -eq 0) 'pak_tool.py selftest' }
$tests['lvl-nopak'] = {
    $r = Run-Level 'nopak' @{ TUROK_PAK = '0'; TUROK_SAVEDIR = (NewDir 'lvl-nopak') } -NoPak
    Ok ($r.Crash -eq 0 -and $r.St13 -and $r.Share -gt 0.3) ("1-player level with TUROK_PAK=0 (old behaviour): crash=$($r.Crash) st13=$($r.St13) share=$($r.Share) ($($r.Seconds) s)")
    Ok (-not (Get-ChildItem (Join-Path $W 'lvl-nopak') -Filter *.mpk -ErrorAction SilentlyContinue)) 'TUROK_PAK=0 creates no pak files'
}
$tests['lvl-pak'] = {
    $sd = NewDir 'lvl-pak'
    $r = Run-Level 'pak' @{ TUROK_SAVEDIR = $sd }
    Ok ($r.Crash -eq 0 -and $r.St13 -and $r.Share -gt 0.3) ("1-player level with a virtual pak: crash=$($r.Crash) st13=$($r.St13) share=$($r.Share) ($($r.Seconds) s)")
    $f = Pak $sd; Ok ((Test-Path $f) -and (Verdict $f) -eq 0) 'the pak file exists and validates'
    Ok (-not (Lines | Select-String 'UNIMPLEMENTED')) 'no UNIMPLEMENTED libultra stub was hit'
    Ok ([bool](Lines | Select-String 'screen id -> 19')) 'the pak screen (UI screen 19) was shown and left again'
}
$tests['create'] = {
    $sd = NewDir 'create'
    # 1 PLAYER TRIALS -> CREATE PLAYER? YES -> name 'A' -> DONE -> CREATE NEW PLAYER 'A'? YES -> saved
    Press $createSeq @{ TUROK_SAVEDIR = $sd } 'ptc'; Kill-Mine
    $f = Pak $sd; $i = Info $f
    Ok ($i -match 'game NRWE pub 51' -and $i -match 'RAGE WARS\.A') 'a player note "RAGE WARS.A" (game NRWE, publisher 51) was written'
    Ok ($i -match 'verdict: OK$' -or $i -match 'verdict: OK\r?$' -or (Verdict $f) -eq 0) 'the image validates (ids, index tables, note chain)'
    Ok ($i -match 'status 02') 'note status 0x02 (set by the game after the first data write)'
    Copy-Item $f (Join-Path $sd 'created.mpk')
}
$tests['persist'] = {
    $sd = Join-Path $W 'create'; $f = Pak $sd
    if (-not (Test-Path (Join-Path $sd 'created.mpk'))) { & $tests['create'] }
    Copy-Item (Join-Path $sd 'created.mpk') $f -Force
    # main menu -> 1 PLAYER TRIALS: the pak screen now lists the saved player; A on slot 1 loads it ("LOAD" = reads the note's data pages)
    $seq = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'logmark', 'C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:2', 'shot', 'C:0.3', 'wait:4', 'waitlog:pak: idle:30', 'wait:3', 'shot', 'sleep:800')
    Clean-Shots 'ptp'; Press $seq @{ TUROK_SAVEDIR = $sd; TUROK_PAKLOG = '1' } 'ptp'; Kill-Mine
    $l = Lines
    Ok ([bool]($l | Select-String 'pak: port 1: .*valid: 1 of 4|pak: port 1: .*valid: 4 of 4')) 'second run: the existing image was loaded (no new image created)'
    Ok (-not ($l | Select-String 'new factory-formatted')) 'second run: nothing was re-formatted'
    $reads = @($l | Select-String 'read blk 02[8-9A-F]|read blk 03[0-9A-F]').Count
    Ok ($reads -ge 8) "the saved player was read from the pak ($reads data block reads)"
    Ok ((Verdict $f) -eq 0) 'image still valid after the second run'
    $a = (Get-FileHash $f).Hash; $b = (Get-FileHash (Join-Path $sd 'created.mpk')).Hash
    Ok ($a -eq $b) 'reading and loading the player does not modify the file'
}
$tests['delete'] = {
    $sd = NewDir 'delete'; $f = Pak $sd
    Copy-Item (Join-Path $W 'create\created.mpk') $f
    & python $Tool fake $f --games 3 --seed 11 | Out-Null
    Copy-Item $f (Join-Path $sd 'mixed_before.mpk')
    Ok ((Verdict $f) -eq 0 -and ((Info $f) -match 'notes in use 4 of 16')) 'fixture: a pak with the game note and 3 synthetic notes of other games'
    # CONTROLLER PAK (menu: 2 down) -> DELETE PLAYERS (3 down) -> A (pad 1) -> list: A -> DELETE A? YES
    $seq = @('wait:2') + $dn + $dn + @('C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:2') + $dn + $dn + $dn + @('C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:3', 'C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:4', 'C:0.3', 'wait:4', 'waitlog:pak: idle:30', 'wait:3') + $lf + @('C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:4', 'sleep:1200')
    Press $seq @{ TUROK_SAVEDIR = $sd } 'ptd'; Kill-Mine
    $i = Info $f
    Ok ((Verdict $f) -eq 0) 'image valid after deleting the player'
    Ok (-not ($i -match 'RAGE WARS\.A\b')) 'the player "A" is gone'
    $o = & python $Tool same-notes (Join-Path $sd 'mixed_before.mpk') $f --game NORE; Ok ($LASTEXITCODE -eq 0) 'foreign note NORE untouched'
    $o = & python $Tool same-notes (Join-Path $sd 'mixed_before.mpk') $f --game NOME; Ok ($LASTEXITCODE -eq 0) 'foreign note NOME untouched'
    $o = & python $Tool same-notes (Join-Path $sd 'mixed_before.mpk') $f --game NLSE; Ok ($LASTEXITCODE -eq 0) 'foreign note NLSE untouched'
}



$tests['exit-flush'] = {
    # create a player and close the window right after the save: the write-back (300 ms debounce) must still reach the disk through the exit hook
    foreach ($mode in @('close', 'kill')) {
        $sd = NewDir "exit_$mode"
        $seq = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:1') + $lf + @('C:0.3', 'wait:4', 'C:0.3', 'wait:4') + $lf + @('logmark', 'C:0.3', 'waitlog:pak: idle:30')
        $a = @{ Prefix = 'pte'; Seq = $seq; Speed = $Speed; EnvVars = @{ TUROK_SAVEDIR = $sd; TUROK_PAKSYNC = '1'; TUROK_PAK_DELAY = '1500' }; Log = 'port\build\paktest\exit.log'; NoKill = $true }
        if ($Exe) { $a.Exe = $Exe }
        & "$PSScriptRoot\pakpress.ps1" @a | Out-Null
        $n = [IO.Path]::GetFileNameWithoutExtension($(if ($Exe) { $Exe } else { (Get-Content port\build\latest_exe.txt).Trim() }))
        $f = Pak $sd
        if ($mode -eq 'close') {
            Get-Process -Name $n -ErrorAction SilentlyContinue | ForEach-Object { [void]$_.CloseMainWindow() }
            $deadline = (Get-Date).AddSeconds(8); while ((Get-Process -Name $n -ErrorAction SilentlyContinue) -and (Get-Date) -lt $deadline) { Start-Sleep -Milliseconds 100 }
            Ok (-not (Get-Process -Name $n -ErrorAction SilentlyContinue)) 'the window closed and the process ended by itself'
        } else { Get-Process -Name $n -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} } }
        $i = Info $f
        if ($mode -eq 'close') {
            Ok ($i -match 'RAGE WARS\.A') 'close right after the save (1.5 s write-back delay): the player note is in the file (flushed at exit)'
            Ok ((Verdict $f) -eq 0) 'image valid after the exit flush'
            Ok ([bool](Lines 'port\build\paktest\exit.log' | Select-String 'pak: exit:')) 'exit hook ran (log line "pak: exit")'
        } else {
            $hasNote = $i -match 'RAGE WARS\.A'
            Ok ((Verdict $f) -le 1) ("killed right after the save: the file is still a valid pak (note present: $hasNote - a hard kill may lose the last, not yet written changes)")
        }
        Kill-Mine
    }
}


# main menu -> 1 PLAYER TRIALS = the pak screen (screen 19); the steps wait for the screen id and the "pak: idle" marker of the pak model instead of fixed times (a loaded host stretches the pak scan)
$toPak = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'logmark', 'C:0.3', 'waitlog:screen id -> 19:40', 'waitlog:pak: idle:20', 'wait:3')
# ... CREATE PLAYER? YES -> name "A" -> DONE -> CREATE NEW PLAYER "A"? YES (saved)
$createSeq = $toPak + $lf + @('C:0.3', 'wait:4', 'C:0.3', 'wait:4') + $lf + @('logmark', 'C:0.3', 'waitlog:pak: idle:30', 'wait:6', 'sleep:1200')
$tests['files'] = {
    $name = 'Turok; Rage Wars_Cont_1.mpk'
    # 1. read-only file: the game works on a session copy, the file is not touched
    $sd = NewDir 'files_ro'; $f = Join-Path $sd $name; Copy-Item (Join-Path $W 'create\created.mpk') $f; $h0 = (Get-FileHash $f).Hash; Set-ItemProperty $f -Name IsReadOnly -Value $true
    $lg = 'port\build\paktest\files.log'
    Press ($createSeq) @{ TUROK_SAVEDIR = $sd } 'ptf' -log $lg; Kill-Mine
    Ok ([bool](Lines $lg | Select-String 'read-only')) 'read-only image: the log says changes are kept for this session only'
    Ok ((Get-FileHash $f).Hash -eq $h0) 'read-only image: file unchanged'
    Ok (-not (Lines $lg | Select-String 'CRASH\(raw|STALL')) 'read-only image: no crash'
    Set-ItemProperty $f -Name IsReadOnly -Value $false
    # 2. image locked by another process: session-only pak, the file is not touched, no crash
    $sd = NewDir 'files_lock'; $f = Join-Path $sd $name; Copy-Item (Join-Path $W 'create\created.mpk') $f; $h0 = (Get-FileHash $f).Hash
    $fs = [IO.File]::Open($f, 'Open', 'ReadWrite', 'None')
    try { Press ($createSeq) @{ TUROK_SAVEDIR = $sd } 'ptf' -log $lg; Kill-Mine } finally { $fs.Close() }
    Ok ([bool](Lines $lg | Select-String 'cannot open')) 'locked image: the log says the file cannot be opened (session-only pak)'
    Ok ((Get-FileHash $f).Hash -eq $h0) 'locked image: file unchanged'
    Ok (-not (Lines $lg | Select-String 'CRASH\(raw|STALL')) 'locked image: no crash'
    # 3. the save folder is a file: nothing can be created, the session works in memory
    $sd = Join-Path $W 'files_notdir'; if (Test-Path $sd) { Remove-Item $sd -Recurse -Force }; Set-Content $sd 'x'
    Press ($createSeq) @{ TUROK_SAVEDIR = $sd } 'ptf' -log $lg; Kill-Mine
    Ok ([bool](Lines $lg | Select-String 'cannot create the save folder')) 'save folder is a file: reported, paks kept in memory'
    Ok (-not (Lines $lg | Select-String 'CRASH\(raw|STALL')) 'save folder is a file: no crash'
    Remove-Item $sd -Force
    # 4. a 100-byte file: padded with zeros in memory (the game sees a damaged pak), the file is not rewritten unless the game repairs it
    $sd = NewDir 'files_short'; $f = Join-Path $sd $name; [IO.File]::WriteAllBytes($f, [byte[]](1..100)); $h0 = (Get-FileHash $f).Hash
    Press (@('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'waitlog:pak: idle:30', 'wait:3', 'shot', 'sleep:1200')) @{ TUROK_SAVEDIR = $sd } 'ptf' -log $lg; Kill-Mine
    Ok ([bool](Lines $lg | Select-String 'short file \(100 bytes\)')) 'short file: reported'
    Ok ((Get-FileHash $f).Hash -eq $h0) 'short file: not modified while the game only looks at it'
    Ok (-not (Lines $lg | Select-String 'CRASH\(raw|STALL')) 'short file: no crash'
    # 5. the same through ATTEMPT REPAIR: the 100-byte original is kept as .orig, the file becomes a valid 32 KiB pak
    $sd = NewDir 'files_short2'; $f = Join-Path $sd $name; [IO.File]::WriteAllBytes($f, [byte[]](1..100))
    Press $repairSeq @{ TUROK_SAVEDIR = $sd } 'ptf' -log $lg; Kill-Mine
    $v = Verdict $f; Ok ((Get-Item $f).Length -eq 32768) "short file + ATTEMPT REPAIR: the file is now 32768 bytes (verdict $v)"
    Ok ((Test-Path "$f.orig") -and (Get-Item "$f.orig").Length -eq 100) 'short file + ATTEMPT REPAIR: the 100-byte original was kept as .orig'
}

function New-FuzzSeq([int]$seed, [int]$steps, [int]$pads) {
    $rnd = New-Object System.Random($seed)
    $buttons = @('A', 'A', 'A', 'B', 'Start', 'Z', 'Z', 'CUp', 'CDown', 'CLeft', 'CRight', 'DUp', 'DDown', 'DLeft', 'DRight', 'L', 'R')
    $seq = @()
    for ($i = 0; $i -lt $steps; $i++) {
        $r = $rnd.Next(100)
        if ($r -lt 30) { $seq += ('{0}:{1:N2}' -f $buttons[$rnd.Next($buttons.Count)], (0.1 + 0.3 * $rnd.NextDouble())); $seq += ('wait:{0:N2}' -f (0.2 + 1.3 * $rnd.NextDouble())) }
        elseif ($r -lt 55) { $seq += ('stick:{0}:{1}:{2:N2}' -f ($rnd.Next(-80, 81)), ($rnd.Next(-80, 81)), (0.3 + 2.2 * $rnd.NextDouble())) }
        elseif ($r -lt 80) { $seq += ('mix:{0}:{1}:{2}:{3:N2}' -f $buttons[$rnd.Next($buttons.Count)], ($rnd.Next(-80, 81)), ($rnd.Next(-80, 81)), (0.2 + 2.0 * $rnd.NextDouble())) }
        elseif ($r -lt 90 -and $pads -gt 1) { $seq += ('p{0}{1}:{2:N2}' -f $rnd.Next(2, $pads + 1), $buttons[$rnd.Next($buttons.Count)], (0.1 + 0.3 * $rnd.NextDouble())) }
        else { $seq += ('wait:{0:N2}' -f (0.5 + 2.5 * $rnd.NextDouble())) }
    }
    $seq
}
function Run-Fuzz([int]$seed, [int]$steps, [int]$pads, [string]$tag) {
    $sd = NewDir "fuzz_$tag"
    $log = "port\build\paktest\fuzz_$tag.log"
    $ev = @{ TUROK_SAVEDIR = $sd; TUROK_PAKSYNC = '1' }; if ($pads -gt 1) { $ev['TUROK_PADS'] = "$pads" }
    $t0 = Get-Date; Press (New-FuzzSeq $seed $steps $pads) $ev "fz$tag" -Speed $Speed -log $log; $wall = [int]((Get-Date) - $t0).TotalSeconds
    Start-Sleep -Milliseconds 700; Kill-Mine
    $l = Lines $log
    $bad = @($l | Select-String 'CRASH\(raw|STALL').Count
    $sum = [pscustomobject]@{ Seed = $seed; Pads = $pads; Wall = $wall; Bad = $bad; Dir = $sd; Screens = ((@($l | Select-String 'screen id') | ForEach-Object { ($_.Line -replace 'screen id -> ', '').Split(' ')[0] } | Select-Object -Unique) -join ' ') }
    $sum
}
$tests['fuzz'] = {
    foreach ($cfg in @(@(1, 1), @(2, 2), @(3, 4))) {
        $r = Run-Fuzz $cfg[0] 220 $cfg[1] ("s{0}p{1}" -f $cfg[0], $cfg[1])
        Ok ($r.Bad -eq 0) ("fuzz seed $($r.Seed), $($r.Pads) pad(s), $($r.Wall) s wall: crash/stall=$($r.Bad), screens: $($r.Screens)")
        foreach ($f in Get-ChildItem $r.Dir -Filter '*.mpk') { $v = Verdict $f.FullName; Ok ($v -le 1) ("  $($f.Name) validates after the random session (verdict $v)"); if ($v -gt 1) { & python $Tool info $f.FullName | Select-String 'ERROR|WARN' | Select-Object -First 4 } }
    }
}

# ---- the flow of port\lvltest.ps1 / soak.ps1 (TUROK_SKIPMENU=1) and port\mptour.ps1 with the virtual pak at its defaults -------------------------------------
$tests['skipmenu'] = {
    # what the stock scripts do: the pak screen is skipped (TUROK_SKIPMENU=1) while a memory pak sits in every port (the default now)
    $sd = NewDir 'skipmenu'
    $r = Run-Level 'skip' @{ TUROK_SAVEDIR = $sd } -NoPak
    Ok ($r.Crash -eq 0 -and $r.St13 -and $r.Share -gt 0.3) ("lvltest flow (TUROK_SKIPMENU=1, memory pak in every port): crash=$($r.Crash) st13=$($r.St13) share=$($r.Share) ($($r.Seconds) s)")
    $m = @(Get-ChildItem $sd -Filter *.mpk -ErrorAction SilentlyContinue); foreach ($f in $m) { Ok ((Verdict $f.FullName) -le 1) "  $($f.Name) is a valid pak (the flow only formats / looks at it)" }
}
function MpSeq([int]$Players) {      # the sequence of port\mptour.ps1
    $seq = @('wait:2', 'shot', 'C:0.3', 'wait:3', 'shot')
    for ($i = 2; $i -le $Players; $i++) { $seq += @('stick:80:0:0.25', 'wait:1') }
    $seq += @('shot', 'C:0.3', 'wait:4', 'shot')
    for ($p = 2; $p -le $Players; $p++) { $seq += @("p${p}C:0.3", 'wait:1') }
    $seq += @('C:0.3', 'wait:4', 'shot')
    for ($p = 2; $p -le $Players; $p++) { $seq += @("p${p}C:0.3", 'wait:2') }
    $seq += @('shot', 'wait:4', 'shot')
    for ($p = 1; $p -le $Players; $p++) { $seq += @($(if ($p -eq 1) { 'C:0.3' } else { "p${p}C:0.3" }), 'wait:3', 'shot') }
    $seq += @('C:0.3', 'wait:5', 'shot', 'C:0.3', 'wait:5', 'shot', 'C:0.3', 'wait:5', 'shot')
    $seq
}
$tests['mptour'] = {
    foreach ($n in 2, 4) {
        $sd = NewDir "mptour$n"; $lg = "port\build\paktest\mptour$n.log"; Clean-Shots "ptm$n"
        Press (MpSeq $n) @{ TUROK_SAVEDIR = $sd; TUROK_PADS = "$n" } "ptm$n" -SkipMenu -log $lg; Kill-Mine
        $l = Lines $lg; $bad = @($l | Select-String 'CRASH\(raw|STALL').Count
        $scr = ((@($l | Select-String 'screen id') | ForEach-Object { ($_.Line -replace 'screen id -> ', '').Split(' ')[0] } | Select-Object -Unique) -join ' ')
        $sh = @(Shots "ptm$n"); $best = 0.0; foreach ($s in $sh) { $v = Share $s.FullName; if ($v -gt $best) { $best = $v } }
        Ok ($bad -eq 0 -and $scr -match '\b26\b' -and $scr -match '\b7\b' -and $scr -match '\b8\b') "mptour with $n players (TUROK_SKIPMENU=1, memory paks): crash/stall=$bad, screens $scr, $($sh.Count) shots, best share $best"
        foreach ($f in Get-ChildItem $sd -Filter '*.mpk' -ErrorAction SilentlyContinue) { Ok ((Verdict $f.FullName) -le 1) "  $($f.Name) is a valid pak" }
    }
}

# ---- damaged images: what the game's own checker / repair makes of each kind of damage ------------------------------------------------------------------
$look = $toPak + @('shot', 'sleep:1200')
# ... DAMAGED CONTROLLER PAK: A on ATTEMPT REPAIR, "REPAIR MAY CAUSE PREVIOUS SAVED DATA TO BE LOST" (cursor on CANCEL), up, A on ATTEMPT REPAIR
$repairSeq = $toPak + @('C:0.3', 'wait:3', 'stick:0:80:0.1', 'wait:0.8', 'logmark', 'C:0.3', 'wait:2', 'waitlog:pak: idle:30', 'wait:3', 'shot', 'sleep:1500')
function Foreign-Fixture($file) {      # the game's player note plus three synthetic notes of other games (codes NORE NOME NLSE)
    $c = Join-Path $W 'create\created.mpk'; if (-not (Test-Path $c)) { & $tests['create'] | Out-Null }
    Copy-Item $c $file -Force; & python $Tool fake $file --games 3 --seed 11 | Out-Null
}
$tests['damaged'] = {
    $lg = 'port\build\paktest\dmg.log'
    $kinds = @(
        @{ k = 'id-primary'; keep = $true }, @{ k = 'id-all'; keep = $true }, @{ k = 'fat-primary'; keep = $true }, @{ k = 'fat-sum'; keep = $true }, @{ k = 'fat-both'; keep = $true },
        @{ k = 'note-chain'; keep = $false }, @{ k = 'noteloop'; keep = $false }, @{ k = 'zero-notes'; keep = $false }, @{ k = 'garbage-notes'; keep = $false },
        @{ k = 'crosslink'; keep = $false }, @{ k = 'random'; keep = $false }, @{ k = 'blank'; keep = $false })
    foreach ($e in $kinds) {
        $kind = $e.k; $sd = NewDir "dmg_$kind"; $f = Pak $sd
        if ($kind -eq 'blank') { & python $Tool create $f --blank | Out-Null } else { Foreign-Fixture $f; & python $Tool corrupt $f $kind --seed 5 | Out-Null }
        Copy-Item $f (Join-Path $sd 'corrupted.mpk'); $v0 = Verdict $f
        Press $look @{ TUROK_SAVEDIR = $sd } 'ptm' -log $lg; Kill-Mine
        $v1 = Verdict $f; $phase = 'look'
        $bad = @(Lines $lg | Select-String 'CRASH\(raw|STALL').Count
        if ($v1 -ge 2 -and $kind -ne 'crosslink') { Press $repairSeq @{ TUROK_SAVEDIR = $sd } 'ptm' -log $lg; Kill-Mine; $v1 = Verdict $f; $phase = 'look + ATTEMPT REPAIR'; $bad += @(Lines $lg | Select-String 'CRASH\(raw|STALL').Count }
        $len = (Get-Item $f).Length
        Ok ($bad -eq 0 -and $len -eq 32768) ("damage '$kind': verdict before $v0, after $phase $v1; no crash/stall, file still 32768 bytes ($len)")
        if ($e.keep) {
            Ok ($v1 -le 1) "  '$kind': the game's own code made the image valid again (verdict $v1)"
            foreach ($g in 'NRWE', 'NORE', 'NOME', 'NLSE') { & python $Tool same-notes (Join-Path $sd 'corrupted.mpk') $f --game $g | Out-Null; Ok ($LASTEXITCODE -eq 0 -or $kind -eq 'id-all') "  '$kind': note $g survived the repair unchanged" }
        } else { "  info  '$kind': " + ((Info $f) -split "`n" | Where-Object { $_ -match 'free pages|verdict' }) -join ' / ' }
    }
}

# ---- foreign notes next to the game's note, full paks -----------------------------------------------------------------------------------------------------
$tests['foreign'] = {
    # notes of other games on the pak: the game must create its player next to them and leave them byte-identical.  The game names a new player after
    # the first letter that no note of the pak uses as its extension (the synthetic notes use "A", the second fixture also "B"): so the first player is B, then C.
    $sd = NewDir 'foreign'; $f = Pak $sd
    & python $Tool create $f --formatted --seed 3 | Out-Null; & python $Tool fake $f --games 3 --seed 11 | Out-Null
    Copy-Item $f (Join-Path $sd 'before.mpk')
    Press $createSeq @{ TUROK_SAVEDIR = $sd } 'ptg' -log 'port\build\paktest\foreign.log'; Kill-Mine
    $i = Info $f
    Ok ($i -match 'game NRWE pub 51' -and $i -match 'notes in use 4 of 16') 'the player was created on a pak that already holds three notes of other games'
    Ok ($i -match 'RAGE WARS\.B') '  the player is named B: the game saw the extensions of the foreign notes (A is taken)'
    Ok ((Verdict $f) -eq 0) '  the image validates'
    foreach ($g in 'NORE', 'NOME', 'NLSE') { & python $Tool same-notes (Join-Path $sd 'before.mpk') $f --game $g | Out-Null; Ok ($LASTEXITCODE -eq 0) "  foreign note $g (table entry and data pages) is byte-identical afterwards" }
    $sd = NewDir 'foreign2'; $f = Pak $sd
    & python $Tool create $f --formatted --seed 3 | Out-Null
    & python $Tool insert $f --game NF01 --pub 01 --name 'FIRST GAME' --ext A --size 512 --fill 11 | Out-Null
    & python $Tool insert $f --game NF02 --pub 01 --name 'SECOND GAME' --ext B --size 1024 --fill 22 | Out-Null
    Copy-Item $f (Join-Path $sd 'before.mpk')
    Press $createSeq @{ TUROK_SAVEDIR = $sd } 'ptg' -log 'port\build\paktest\foreign.log'; Kill-Mine
    $i = Info $f
    Ok ($i -match 'RAGE WARS\.C' -and (Verdict $f) -eq 0) 'extensions A and B taken by other games: the player is named C, image valid'
    foreach ($g in 'NF01', 'NF02') { & python $Tool same-notes (Join-Path $sd 'before.mpk') $f --game $g | Out-Null; Ok ($LASTEXITCODE -eq 0) "  foreign note $g byte-identical afterwards" }
}
$tests['full'] = {
    # not enough room for the 7-page player: the game must refuse (or report) and leave everything as it was.  free = pages left for the player.
    foreach ($free in 6, 7, 8) {
        $sd = NewDir "full$free"; $f = Pak $sd
        & python $Tool create $f --formatted --seed 3 | Out-Null
        & python $Tool insert $f --game NFUL --pub 01 --name 'FILLER' --size ((123 - $free) * 256) --fill A5 | Out-Null
        Copy-Item $f (Join-Path $sd 'before.mpk')
        Press $createSeq @{ TUROK_SAVEDIR = $sd } 'ptu' -log 'port\build\paktest\full.log'; Kill-Mine
        $i = Info $f; $made = $i -match 'RAGE WARS\.A'
        Ok ((Verdict $f) -eq 0) "pak with $free free pages: image valid afterwards (player created: $made)"
        & python $Tool same-notes (Join-Path $sd 'before.mpk') $f --game NFUL | Out-Null; Ok ($LASTEXITCODE -eq 0) "  filler note untouched"
        Ok (-not (Lines 'port\build\paktest\full.log' | Select-String 'CRASH\(raw|STALL')) '  no crash'
        if ($free -lt 7) { Ok (-not $made) "  $free free pages: no player written" } elseif ($free -gt 7) { Ok $made "  $free free pages: the player fits and was written" }
    }
    # all 16 note slots used
    $sd = NewDir 'full16'; $f = Pak $sd
    & python $Tool create $f --formatted --seed 3 | Out-Null
    for ($n = 1; $n -le 16; $n++) { & python $Tool insert $f --game ('NF{0:D2}' -f $n) --pub 01 --name ("NOTE {0}" -f $n) --size 256 --fill 3C | Out-Null }
    Copy-Item $f (Join-Path $sd 'before.mpk')
    Press $createSeq @{ TUROK_SAVEDIR = $sd } 'ptu' -log 'port\build\paktest\full.log'; Kill-Mine
    $i = Info $f
    Ok ((Verdict $f) -eq 0 -and -not ($i -match 'RAGE WARS\.A') -and $i -match 'notes in use 16 of 16') 'pak with 16 notes: no player written, image valid'
    & python $Tool same-notes (Join-Path $sd 'before.mpk') $f | Out-Null; Ok ($LASTEXITCODE -eq 0) '  all 16 notes untouched'
}

# ---- other container formats, end to end through the game ------------------------------------------------------------------------------------------------------
function BytesEq([byte[]]$a, [byte[]]$b) { ($a.Length -eq $b.Length) -and [System.Linq.Enumerable]::SequenceEqual($a, $b) }
function SliceOf([byte[]]$d, [int]$off, [int]$len) { $r = New-Object byte[] $len; [Array]::Copy($d, $off, $r, 0, $len); , $r }
$tests['containers'] = {
    $lg = 'port\build\paktest\cont.log'
    # 1. DexDrive .n64 as the pak of port 1: size and header stay, the player lands in the pak part at 0x1040
    $sd = NewDir 'cont_dex'; $f = Join-Path $sd 'my.n64'
    & python $Tool create $f --container dexdrive --formatted --seed 8 | Out-Null
    $before = [IO.File]::ReadAllBytes($f)
    Press $createSeq @{ TUROK_SAVEDIR = $sd; TUROK_PAK1 = $f } 'ptk' -log $lg; Kill-Mine
    $after = [IO.File]::ReadAllBytes($f)
    Ok ($after.Length -eq $before.Length -and (BytesEq (SliceOf $after 0 0x1040) (SliceOf $before 0 0x1040))) 'DexDrive .n64: size and 0x1040-byte header unchanged'
    Ok ((Info $f) -match 'RAGE WARS\.A' -and (Verdict $f) -eq 0) 'DexDrive .n64: the player was saved into the pak part, image valid'
    Ok (-not (Get-ChildItem $sd -Filter '*_Cont_*' -ErrorAction SilentlyContinue)) 'DexDrive .n64: the explicit file replaced the default one (nothing created in the save folder)'
    # 2. 4-in-1 .mpk: port 1 = pak 3 of the file (TUROK_PAK1=file#3); the other three paks, one note each, are carried along untouched
    $sd = NewDir 'cont_4in1'; $f = Join-Path $sd 'four.mpk'
    & python $Tool create $f --container 4in1 --formatted --seed 8 | Out-Null
    & python $Tool insert $f --game NF01 --pub 01 --name 'SLICE ONE' --size 512 --slice 0 | Out-Null
    & python $Tool insert $f --game NF02 --pub 01 --name 'SLICE TWO' --size 768 --slice 1 | Out-Null
    & python $Tool insert $f --game NF04 --pub 01 --name 'SLICE FOUR' --size 1024 --slice 3 | Out-Null
    $before = [IO.File]::ReadAllBytes($f)
    Press $createSeq @{ TUROK_SAVEDIR = $sd; TUROK_PAK1 = "$f#3" } 'ptk' -log $lg; Kill-Mine
    $after = [IO.File]::ReadAllBytes($f)
    Ok ($after.Length -eq 131072) '4-in-1: still 131072 bytes'
    foreach ($k in 0, 1, 3) { Ok (BytesEq (SliceOf $after ($k * 32768) 32768) (SliceOf $before ($k * 32768) 32768)) "4-in-1: pak $($k + 1) of the file is byte-identical" }
    Ok (((& python $Tool info $f --slice 2) -join "`n") -match 'RAGE WARS\.A') '4-in-1: the player is in pak 3 (selected with #3)'
    # 3. a 32 KiB pak with a trailer (MPK Manager comments): kept
    $sd = NewDir 'cont_trailer'; $f = Join-Path $sd 'trail.mpk'
    & python $Tool create $f --formatted --seed 9 | Out-Null
    $tr = [Text.Encoding]::ASCII.GetBytes('trailer: comment text that must survive the write-back'); $fs = [IO.File]::Open($f, 'Append'); $fs.Write($tr, 0, $tr.Length); $fs.Close()
    Press $createSeq @{ TUROK_SAVEDIR = $sd; TUROK_PAK1 = $f } 'ptk' -log $lg; Kill-Mine
    $after = [IO.File]::ReadAllBytes($f)
    Ok ($after.Length -eq 32768 + $tr.Length -and (BytesEq (SliceOf $after 32768 $tr.Length) $tr)) 'pak + trailer: file size and the appended bytes unchanged'
    Ok ((Info $f) -match 'RAGE WARS\.A') 'pak + trailer: the player was saved'
    # 4. a 20 MB file that cannot be a pak: session-only pak, the file is not touched
    $sd = NewDir 'cont_big'; $f = Join-Path $sd 'huge.mpk'; $fs = [IO.File]::Create($f); $fs.SetLength(20MB); $fs.Close(); $h0 = (Get-FileHash $f).Hash
    Press $look @{ TUROK_SAVEDIR = $sd; TUROK_PAK1 = $f } 'ptk' -log $lg; Kill-Mine
    Ok ([bool](Lines $lg | Select-String 'too large')) '20 MB file: reported as too large for a pak, session-only pak'
    Ok ((Get-FileHash $f).Hash -eq $h0) '20 MB file: not touched'
    Ok (-not (Lines $lg | Select-String 'CRASH\(raw|STALL')) '20 MB file: no crash'
    # 5. explicit file in a folder that does not exist yet: the folder is created like the save folder
    $sd = NewDir 'cont_newdir'; $f = Join-Path $sd 'x\y\my.mpk'
    Press $createSeq @{ TUROK_SAVEDIR = $sd; TUROK_PAK1 = $f } 'ptk' -log $lg; Kill-Mine
    Ok ((Test-Path $f) -and ((Info $f) -match 'RAGE WARS\.A') -and (Verdict $f) -eq 0) 'explicit TUROK_PAK1 in a folder that does not exist yet: folder and file were created, the player was saved'
}

# ---- hot insert / remove through the control file ----------------------------------------------------------------------------------------------------------
$tests['hotswap'] = {
    # pak pulled out BEFORE the pak screen opens: NO CONTROLLER PAK FOUND (RETRY / DONE); pak pushed in again + RETRY: the saved player is listed
    $sd = NewDir 'hotswap'; $f = Pak $sd; $lg = 'port\build\paktest\hot.log'
    if (-not (Test-Path (Join-Path $W 'create\created.mpk'))) { & $tests['create'] | Out-Null }
    Copy-Item (Join-Path $W 'create\created.mpk') $f; $h0 = (Get-FileHash $f).Hash; Clean-Shots 'pth'
    $seq = @('wait:2', 'pak:remove 1', 'wait:1', 'stick:0:-80:0.25', 'wait:1', 'logmark', 'C:0.3', 'waitlog:screen id -> 19:40', 'waitlog:pak: idle:20', 'wait:3', 'shot',
             'logmark', 'pak:insert 1 memory', 'wait:1') + $lf + @('C:0.3', 'wait:4', 'waitlog:pak: idle:20', 'wait:3', 'shot', 'pak:status', 'sleep:600')
    Press $seq @{ TUROK_SAVEDIR = $sd; TUROK_PAKLOG = '1' } 'pth' -log $lg; Kill-Mine
    $l = Lines $lg
    Ok ([bool]($l | Select-String 'port 1: empty \(control file\)') -and [bool]($l | Select-String 'port 1: memory pak \(control file\)')) 'remove and insert through port_pak.txt were executed'
    Ok ([bool]($l | Select-String 'identify -> status 2')) 'the game saw the empty port (status 2) while the pak was out'
    Ok ([bool]($l | Select-String 'status 3')) 'the game saw the "new accessory" status (3) after the hot insert'
    Ok ([bool]($l | Select-String 'status port 1: memory')) 'status command works'
    Ok (-not ($l | Select-String 'CRASH\(raw|STALL')) 'no crash across the hot swap'
    Ok ((Verdict $f) -eq 0 -and (Get-FileHash $f).Hash -eq $h0) 'the pak image is unchanged by a remove / insert cycle'
    $sh = @(Shots 'pth'); $d = 0.0; if ($sh.Count -ge 2) { $o = (& python port\imgdiff.py $sh[0].FullName $sh[1].FullName 2>$null | Select-Object -Last 1); if ($o -match '([\d.]+)%') { $d = [double]$Matches[1] } }
    Ok ($sh.Count -ge 2 -and $d -gt 0.5) "the screen changed from NO CONTROLLER PAK FOUND to the player list after the insert + RETRY ($d% of the pixels differ; port\build\pth_01.png / _02.png)"
}

# ---- settings, first run, Project64 folder, format, port isolation ---------------------------------------------------------------------------------------------
function Pak-Header($lg) { (Lines $lg | Select-String 'virtual controller pak' | Select-Object -First 1).Line }
$tests['config'] = {
    # settings: environment variable > ini file > default
    $d = NewDir 'config'; $ini = Join-Path $d 'my.ini'; $sdIni = Join-Path $d 'from_ini'; $sdEnv = Join-Path $d 'from_env'; $lg = 'port\build\paktest\config.log'
    Set-Content $ini -Encoding ascii -Value @("savedir = $sdIni", 'port1 = none', 'port2 = rumble', 'name = My Game', '; a comment', 'writeback_ms = 50')
    Press @('wait:1') @{ TUROK_PAK_INI = $ini } 'ptn' -SkipMenu -log $lg; Kill-Mine
    $h = Pak-Header $lg
    Ok ($h -match 'ports -rmm' -and $h.Contains($sdIni) -and $h -match "name 'My Game'") "ini file only: $($h -replace '^pak: ', '')"
    Press @('wait:1') @{ TUROK_PAK_INI = $ini; TUROK_SAVEDIR = $sdEnv; TUROK_PAK1_TYPE = 'rumble'; TUROK_PAK2_TYPE = 'memory' } 'ptn' -SkipMenu -log $lg; Kill-Mine
    $h = Pak-Header $lg
    Ok ($h -match 'ports rmmm' -and $h.Contains($sdEnv) -and -not $h.Contains($sdIni)) "environment overrides the ini file: $($h -replace '^pak: ', '')"
    Press @('wait:1') @{ TUROK_PAK_INI = $ini; TUROK_PAK = '0' } 'ptn' -SkipMenu -log $lg; Kill-Mine
    $h = Pak-Header $lg
    Ok ($h -match 'DISABLED' -and $h -match 'ports ----') "TUROK_PAK=0 switches everything off: $($h -replace '^pak: ', '')"
    Ok (-not (Get-ChildItem $sdEnv -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*.mpk' })) 'a rumble pak in port 1 needs no file'
    $sdQ = Join-Path $d 'with space'; Press @('wait:1') @{ TUROK_SAVEDIR = ('"' + $sdQ + '"') } 'ptn' -SkipMenu -log $lg; Kill-Mine
    $h = Pak-Header $lg
    Ok ($h.Contains("save folder $sdQ, name") -and (Test-Path (Join-Path $sdQ 'Turok; Rage Wars_Cont_1.mpk'))) 'quotes around a path in an environment variable (cmd: set X="a b") are stripped; the folder with a space works'
}
$tests['firstrun'] = {
    # nothing configured and no saves folder: it is created next to the exe (port\build\saves) with a formatted pak for the connected port
    $exe = (Get-Content port\build\latest_exe.txt).Trim(); if ($Exe) { $exe = $Exe }
    $def = Join-Path (Split-Path (Resolve-Path $exe).Path -Parent) 'saves'; $aside = "$def.paktest_aside"; $had = Test-Path $def
    if ($had) { Rename-Item $def $aside }
    try {
        Press @('wait:1') @{} 'ptn' -SkipMenu -log 'port\build\paktest\first.log'; Kill-Mine
        $f = Join-Path $def 'Turok; Rage Wars_Cont_1.mpk'
        Ok ((Test-Path $f) -and (Get-Item $f).Length -eq 32768 -and (Verdict $f) -eq 0) "first run: $def was created with a valid formatted 32768-byte pak"
        Ok (-not (Test-Path (Join-Path $def 'Turok; Rage Wars_Cont_2.mpk'))) 'first run: no pak for ports without a controller'
    } finally {
        if (Test-Path $def) { Remove-Item $def -Recurse -Force -ErrorAction SilentlyContinue }
        if ($had) { Rename-Item $aside $def }
    }
    $sd = Join-Path $W 'firstrun\a\b\saves'; if (Test-Path (Join-Path $W 'firstrun')) { Remove-Item (Join-Path $W 'firstrun') -Recurse -Force -ErrorAction SilentlyContinue }
    Press @('wait:1') @{ TUROK_SAVEDIR = $sd } 'ptn' -SkipMenu -log 'port\build\paktest\first.log'; Kill-Mine
    Ok ((Test-Path (Join-Path $sd 'Turok; Rage Wars_Cont_1.mpk')) -and (Verdict (Join-Path $sd 'Turok; Rage Wars_Cont_1.mpk')) -eq 0) 'TUROK_SAVEDIR with several missing levels: all created'
}
$tests['pj64'] = {
    # a Project64 Save folder (TUROK_PJ64_SAVE): "<game>_Cont_1.mpk" there, in a per-game "<game>-<md5>" folder, or the older "<game>.mpk" is used for port 1
    if (-not (Test-Path (Join-Path $W 'create\created.mpk'))) { & $tests['create'] | Out-Null }
    $d = NewDir 'pj64'; $save = Join-Path $d 'Save'; $sd = Join-Path $d 'ours'; $uniq = Join-Path $save 'Turok; Rage Wars-0123456789ABCDEF0123456789ABCDEF'; $lg = 'port\build\paktest\pj64.log'
    New-Item -ItemType Directory -Force $save, $sd, $uniq | Out-Null
    foreach ($case in @(@('main folder', (Join-Path $save 'Turok; Rage Wars_Cont_1.mpk')), @('per-game folder (unique save folders)', (Join-Path $uniq 'Turok; Rage Wars_Cont_1.mpk')), @('Project64 1.6 / Jabo style "<game>.mpk"', (Join-Path $save 'Turok; Rage Wars.mpk')))) {
        Get-ChildItem $save -Recurse -File | ForEach-Object { Remove-Item -LiteralPath $_.FullName -Force }
        Copy-Item (Join-Path $W 'create\created.mpk') $case[1]; $h0 = (Get-FileHash $case[1]).Hash
        Press $look @{ TUROK_SAVEDIR = $sd; TUROK_PJ64_SAVE = $save } 'ptj' -log $lg; Kill-Mine
        $l = Lines $lg
        Ok ([bool]($l | Select-String ('port 1: ' + [regex]::Escape($case[1]) + ' \[raw 32 KiB'))) "Project64 $($case[0]): the file is the pak of port 1"
        Ok ((Get-FileHash $case[1]).Hash -eq $h0 -and -not (Get-ChildItem $sd -Filter *.mpk)) '  the file is only read (unchanged), nothing was created in the save folder'
    }
}
$tests['format'] = {
    # "format" through the control file: the pak is wiped and re-formatted with a new serial; the game then finds no players
    if (-not (Test-Path (Join-Path $W 'create\created.mpk'))) { & $tests['create'] | Out-Null }
    $sd = NewDir 'format'; $f = Pak $sd; Copy-Item (Join-Path $W 'create\created.mpk') $f
    $s0 = ((Info $f) -split "`n" | Where-Object { $_ -match 'id block @0x20' }) -replace '.*serial ', ''
    Press (@('wait:2', 'pak:format 1', 'wait:1') + $toPak + @('shot', 'sleep:1200')) @{ TUROK_SAVEDIR = $sd } 'ptx' -log 'port\build\paktest\format.log'; Kill-Mine
    $i = Info $f; $s1 = ($i -split "`n" | Where-Object { $_ -match 'id block @0x20' }) -replace '.*serial ', ''
    Ok ($i -match 'notes in use 0 of 16' -and (Verdict $f) -eq 0) 'format 1: the pak holds no notes and validates'
    Ok ($s0 -ne $s1) "  a new serial was generated ($s0 -> $s1)"
    Ok ([bool](Lines 'port\build\paktest\format.log' | Select-String 'port 1: pak re-formatted')) '  logged'
}
$tests['ports4'] = {
    # four pads, four paks with one distinct synthetic note each: the 4-player menu tour must leave every file valid and byte-identical (no mix-up between ports)
    $sd = NewDir 'ports4'; $lg = 'port\build\paktest\ports4.log'
    for ($n = 1; $n -le 4; $n++) {
        $f = Pak $sd $n; & python $Tool create $f --formatted --seed (30 + $n) | Out-Null
        & python $Tool insert $f --game ('NP0{0}' -f $n) --pub 01 --name ("PORT {0} NOTE" -f $n) --size (256 * $n) --fill ('{0:X2}' -f (0x10 * $n)) | Out-Null
        Copy-Item $f (Join-Path $sd ("before{0}.mpk" -f $n))
    }
    Press (MpSeq 4) @{ TUROK_SAVEDIR = $sd; TUROK_PADS = '4' } 'ptq' -SkipMenu -log $lg; Kill-Mine
    $bad = @(Lines $lg | Select-String 'CRASH\(raw|STALL').Count
    Ok ($bad -eq 0) "4-player menu tour with four paks: crash/stall=$bad"
    for ($n = 1; $n -le 4; $n++) {
        $f = Pak $sd $n; $b = Join-Path $sd ("before{0}.mpk" -f $n)
        Ok ((Verdict $f) -eq 0 -and (Get-FileHash $f).Hash -eq (Get-FileHash $b).Hash) "  port ${n}: pak valid and byte-identical to its fixture (note NP0$n only)"
    }
    Ok (@(Lines $lg | Select-String 'port [1-4]: .*valid: 4 of 4').Count -ge 4) '  the log shows all four ports loading their own file'
}

$tests['crash-flush'] = {
    # a pending change (60 s write-back delay) must reach the disk when the game crashes (vectored exception handler in pak.c), but a hard kill loses it.
    # The pak is re-formatted through the control file, then TUROK_CRASHTEST=1 + TUROK_STRICT=1 fault at frame 300 (about 5 s into the run).
    $exe = if ($Exe) { $Exe } else { (Get-Content port\build\latest_exe.txt).Trim() }
    if (-not (Test-Path (Join-Path $W 'create\created.mpk'))) { & $tests['create'] | Out-Null }
    foreach ($mode in 'crash', 'kill') {
        $sd = NewDir "crash_$mode"; $f = Pak $sd; Copy-Item (Join-Path $W 'create\created.mpk') $f; $h0 = (Get-FileHash $f).Hash
        $lg = Join-Path $W "crash_$mode.log"; Remove-Item $lg -ErrorAction SilentlyContinue; Remove-Item port_pak.txt, port_frame.txt -ErrorAction SilentlyContinue
        $set = @{ TUROK_LOG = $lg; TUROK_SAVEDIR = $sd; TUROK_PAK_DELAY = '60000'; TUROK_PAKSYNC = '1'; TUROK_STRICT = '1' }; if ($mode -eq 'crash') { $set['TUROK_CRASHTEST'] = '1' }
        foreach ($k in $set.Keys) { Set-Item -Path ("Env:" + $k) -Value $set[$k] }
        $p = Start-Process $exe -WorkingDirectory $root -PassThru
        foreach ($k in $set.Keys) { Remove-Item ("Env:" + $k) -ErrorAction SilentlyContinue }
        $t0 = Get-Date
        while (-not $p.HasExited -and ((Get-Date) - $t0).TotalSeconds -lt 40 -and -not (LogHas $lg 'virtual controller pak')) { Start-Sleep -Milliseconds 50 }
        Set-Content -Path port_pak.txt -Value 'format 1' -Encoding ascii
        $t0 = Get-Date
        while (-not $p.HasExited -and ((Get-Date) - $t0).TotalSeconds -lt 15 -and -not (LogHas $lg 're-formatted')) { Start-Sleep -Milliseconds 50 }
        $formatted = LogHas $lg 're-formatted'
        if ($mode -eq 'kill') { Start-Sleep -Milliseconds 1500; if (-not $p.HasExited) { $p.Kill() }; [void]$p.WaitForExit(5000) } else { if (-not $p.WaitForExit(60000)) { $p.Kill() } }
        $code = $p.ExitCode; Remove-Item port_pak.txt, port_frame.txt -ErrorAction SilentlyContinue
        $now = (Get-FileHash $f).Hash; $i = Info $f
        Ok $formatted "$mode`: the format command ran before the end of the process"
        if ($mode -eq 'crash') {
            Ok (LogHas $lg 'CRASH\(raw') "crash: the game crashed on purpose (exit code $code)"
            Ok ($now -ne $h0 -and $i -match 'notes in use 0 of 16' -and (Verdict $f) -eq 0) 'crash: the pending re-format reached the disk before the process died (valid empty pak)'
        } else {
            Ok ($now -eq $h0) 'hard kill within the 60 s write-back delay: the file still has the old content (nothing half-written)'
        }
    }
}

$tests['match'] = {
    # 1-player multiplayer match against a bot (MULTIPLAYER, HOW MANY PLAYERS 1, character, loadout: stick down 5x + A on OK, mission GAUNTLET, START GAME, rumble prompt, intro camera),
    # TUROK_TIMELIMIT=1: through the rumble prompt and a complete 1-minute match, with a memory pak and with a rumble pak in port 1
    $pre = @('wait:2', 'C:0.3', 'wait:3', 'C:0.3', 'wait:4', 'C:0.3', 'wait:6'); $dn5 = @(); for ($i = 0; $i -lt 5; $i++) { $dn5 += @('stick:0:-80:0.3', 'wait:1.5') }
    $seq = $pre + $dn5 + @('C:0.3', 'wait:4', 'C:0.3', 'wait:4', 'C:0.3', 'wait:5', 'until:A:-> 2 (top=0):60', 'wait:4', 'C:0.3', 'wait:3', 'shot', 'wait:75', 'shot', 'sleep:500')
    foreach ($type in 'memory', 'rumble') {
        $sd = NewDir "match_$type"; $lg = "port\build\paktest\match_$type.log"
        Press $seq @{ TUROK_SAVEDIR = $sd; TUROK_PAK1_TYPE = $type; TUROK_PAKLOG = '1'; TUROK_TIMELIMIT = '1' } "ptz$type" -SkipMenu -log $lg; Kill-Mine
        $l = Lines $lg; $bad = @($l | Select-String 'CRASH\(raw|STALL').Count
        $scr = ((@($l | Select-String 'screen id') | ForEach-Object { ($_.Line -replace 'screen id -> ', '').Split(' ')[0] } | Select-Object -Unique) -join ' ')
        $motor = @($l | Select-String 'write blk 600').Count; $st13 = [bool]($l | Select-String 'game state: g=\w+ st=13')
        Ok ($bad -eq 0 -and $st13 -and $scr -match '\b20\b' -and $scr -match '\b21\b' -and $scr -match '\b25\b') "match with a $type pak in port 1: crash/stall=$bad, reached the rumble prompt and the match (screens $scr)"
        if ($type -eq 'rumble') {
            Ok ([bool]($l | Select-String 'rumble pak unlocked') -and $motor -gt 300) "  rumble pak: the game's rumble probe succeeded and it wrote the motor register $motor times (every frame)"
        } else {
            Ok ($motor -eq 0) "  memory pak: no motor-register writes ($motor): the game found no rumble pak"
            foreach ($f in Get-ChildItem $sd -Filter '*.mpk') { Ok ((Verdict $f.FullName) -le 1) "  $($f.Name) valid" }
        }
    }
}

# ---- longer soak (not part of 'all'): several level runs and more random sessions --------------------------------------------------------------------------
$tests['soak'] = {
    $okc = 0; $n = 4
    for ($i = 1; $i -le $n; $i++) { $r = Run-Level "soak$i" @{ TUROK_SAVEDIR = (NewDir "soak$i") }; if ($r.Crash -eq 0 -and $r.St13 -and $r.Share -gt 0.3) { $okc++ }; "  run $i`: crash=$($r.Crash) st13=$($r.St13) share=$($r.Share) ($($r.Seconds) s)" }
    Ok ($okc -eq $n) "lvl-pak flow: $okc of $n runs reached the level"
    foreach ($cfg in @(@(11, 1), @(12, 2), @(13, 4), @(14, 4), @(15, 2))) {
        $r = Run-Fuzz $cfg[0] 300 $cfg[1] ("soak{0}p{1}" -f $cfg[0], $cfg[1])
        Ok ($r.Bad -eq 0) ("fuzz seed $($r.Seed), $($r.Pads) pad(s), $($r.Wall) s wall: crash/stall=$($r.Bad), screens: $($r.Screens)")
        foreach ($f in Get-ChildItem $r.Dir -Filter '*.mpk') { $v = Verdict $f.FullName; Ok ($v -le 1) ("  $($f.Name) validates (verdict $v)") }
    }
}
$tests['timing'] = {
    # real time (speed 1): the level flow with and without the virtual pak; the game logs "speed: N game frames in 5.0 s wall = 1.0x (F fps)" every 5 s
    $med = @{}
    foreach ($mode in 'pak', 'nopak') {
        $sd = NewDir "timing_$mode"; $ev = @{ TUROK_SAVEDIR = $sd }; if ($mode -eq 'nopak') { $ev['TUROK_PAK'] = '0' }
        $lg = "port\build\paktest\timing_$mode.log"
        if ($mode -eq 'nopak') { Press $lvlNoPak $ev "ptt_$mode" -speed 1 -SkipMenu -log $lg } else { Press $lvlPak $ev "ptt_$mode" -speed 1 -log $lg }
        Kill-Mine
        $fps = @(Lines $lg | Select-String 'speed: \d+ game frames in [\d.]+ s wall = [\d.]+x \(([\d.]+) fps\)' | ForEach-Object { [double]$_.Matches[0].Groups[1].Value })
        if ($fps.Count -gt 4) { $fps = $fps[2..($fps.Count - 1)] }                                  # skip the start-up
        $s = @($fps | Sort-Object); $m = if ($s.Count) { $s[[int][Math]::Floor($s.Count / 2)] } else { 0 }; $p10 = if ($s.Count) { $s[[int][Math]::Floor($s.Count / 10)] } else { 0 }
        $med[$mode] = $m
        Ok ($s.Count -ge 5 -and $m -ge 57) ("$mode`: $($s.Count) samples, median $m fps, 10th percentile $p10 fps, min $($s[0])")
    }
    Ok ([Math]::Abs($med['pak'] - $med['nopak']) -le 2) ("frame rate with the virtual pak ($($med['pak'])) equals the one without ($($med['nopak']))")
    $l = Lines "port\build\paktest\timing_pak.log" | Select-String 'pak: exit:' | Select-Object -Last 1; if ($l) { "  info  $($l.Line)" }
}
$optional = @('soak', 'timing')

if ($List) { $tests.Keys; return }
$sel = if ($Test -contains 'all') { @($tests.Keys | Where-Object { $optional -notcontains $_ }) } else { $Test }
foreach ($t in $sel) {
    if (-not $tests.Contains($t)) { "unknown test '$t' (use -List)"; $script:fails++; continue }
    "== $t"
    try { & $tests[$t] } catch { $script:fails++; "  FAIL  $t threw: $($_.Exception.Message)" }
    Kill-Mine
}
"paktest: $($script:passes) passed, $($script:fails) failed"
exit $script:fails
