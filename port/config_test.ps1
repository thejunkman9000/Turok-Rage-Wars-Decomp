# UI test of the mapping tool: launches turok_controls.exe on a temporary controls file and drives it with SendInput the way a person would: the "press the input"
# capture (key, wheel), Save, live preview of held keys, the stick presets / Copy from / Import popup menus, the layout lists, Reset to defaults (message box),
# Export / Import (file dialogs, the path is typed), Launch game (+ hot reload of the running game after Save).  Checks the controls file and the texts of the window.
# Pictures of the window: port\build\cfgtest_*.png (the tool renders itself on request, see TUROK_CONTROLS_SHOTREQ).
#   .\port\config_test.ps1 [-NoShots]
# SAFETY as in input_inject.ps1: injects only while a window of the tool is in front and the cursor is over it; restores the foreground window and the cursor at the end.
param([switch]$NoShots, [switch]$HelpersOnly)
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
$Speed = 1
. "$PSScriptRoot\input_inject.ps1" -Lib -Prefix cfgtest
Add-Type @"
using System; using System.Runtime.InteropServices; using System.Text; using System.Collections.Generic;
public class EW2 {
  public delegate bool EnumProc(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] static extern bool EnumChildWindows(IntPtr p, EnumProc cb, IntPtr l);
  [DllImport("user32.dll")] static extern bool GetWindowRect(IntPtr h, out RC r);
  [DllImport("user32.dll", CharSet=CharSet.Unicode)] static extern int GetWindowTextW(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll", CharSet=CharSet.Unicode)] static extern int GetClassNameW(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] public static extern int GetDlgCtrlID(IntPtr h);
  [DllImport("user32.dll")] public static extern IntPtr GetAncestor(IntPtr h, uint f);
  [DllImport("user32.dll")] public static extern bool SetProcessDPIAware();
  [DllImport("user32.dll")] public static extern IntPtr SendMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  [StructLayout(LayoutKind.Sequential)] public struct RC { public int L, T, R, B; }
  public static string TextOf(IntPtr h) { var s = new StringBuilder(1024); GetWindowTextW(h, s, 1024); return s.ToString(); }
  public static IntPtr FindByText(IntPtr parent, string cls, string text) { IntPtr found = IntPtr.Zero; EnumChildWindows(parent, (h, l) => { var c = new StringBuilder(64); GetClassNameW(h, c, 64); if (c.ToString() == cls && TextOf(h) == text && IsWindowVisible(h)) { found = h; return false; } return true; }, IntPtr.Zero); return found; }
  public static IntPtr FindById(IntPtr parent, int id) { IntPtr found = IntPtr.Zero; EnumChildWindows(parent, (h, l) => { if (GetDlgCtrlID(h) == id) { found = h; return false; } return true; }, IntPtr.Zero); return found; }
  [DllImport("user32.dll")] static extern IntPtr GetForegroundWindow();
  [DllImport("user32.dll")] static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  public static string Foreground() { IntPtr h = GetForegroundWindow(); var c = new StringBuilder(80); GetClassNameW(h, c, 80); uint pid; GetWindowThreadProcessId(h, out pid); return "pid " + pid + " class " + c + " title '" + TextOf(h) + "'"; }
  public delegate bool EnumTop(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] static extern bool EnumWindows(EnumTop cb, IntPtr l);
  [DllImport("user32.dll")] static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  // close the dialogs / message boxes the process still has open (WM_CLOSE) and end a popup-menu loop (WM_CANCELMODE to the main window)
  public static int CloseStray(uint pid, IntPtr main) { int n = 0; EnumWindows((h, l) => { uint p; GetWindowThreadProcessId(h, out p); if (p == pid && h != main && IsWindowVisible(h)) { var c = new StringBuilder(64); GetClassNameW(h, c, 64); if (c.ToString() != "#32768") { PostMessage(h, 0x10, IntPtr.Zero, IntPtr.Zero); n++; } } return true; }, IntPtr.Zero); PostMessage(main, 0x1F, IntPtr.Zero, IntPtr.Zero); return n; }
  public static IntPtr FindMain(uint pid) { IntPtr found = IntPtr.Zero; EnumWindows((h, l) => { uint p; GetWindowThreadProcessId(h, out p); if (p == pid && IsWindowVisible(h)) { var c = new StringBuilder(64); GetClassNameW(h, c, 64); if (c.ToString() == "TurokControls") { found = h; return false; } } return true; }, IntPtr.Zero); return found; }  public static int[] RectOf(IntPtr h) { RC r; GetWindowRect(h, out r); return new int[] { r.L, r.T, r.R, r.B }; }
}
"@
[void][EW2]::SetProcessDPIAware()
# control ids of app.cpp (enum order): caption 102, keyboard layout list 115 + its Apply button 116, status line 307, live test text 272
$ID_CAPTION = 102; $ID_KBLAYOUT = 115; $ID_KBAPPLY = 116; $ID_STATUS = 307; $ID_TESTTEXT = 272
# child controls are what WindowFromPoint returns: compare the root window
function NeedMouse() { NeedFocus; $r = ClientScreenRect; $cx = [int](($r[0] + $r[2]) / 2); $cy = [int](($r[1] + $r[3]) / 2); $pt = New-Object Inj+POINT; [void][Inj]::GetCursorPos([ref]$pt)
    if (($pt.X -lt $r[0] + 5) -or ($pt.X -gt $r[2] - 5) -or ($pt.Y -lt $r[1] + 5) -or ($pt.Y -gt $r[3] - 5)) { [void][Inj]::SetCursorPos($cx, $cy); Start-Sleep -Milliseconds 30; [void][Inj]::GetCursorPos([ref]$pt) }
    $w = [Inj]::WindowFromPoint($pt); if ([EW2]::GetAncestor($w, 2) -ne $script:hwnd -and $w -ne $script:hwnd) { throw "the mouse cursor is not over the tool window, not injecting mouse input" } }
$tool = Join-Path $root 'port\build\turok_controls.exe'
$ini = Join-Path $root 'port\build\controls_tooltest.ini'
$req = Join-Path $root 'port\build\cfgtest_shot.req'; $env:TUROK_CONTROLS_SHOTREQ = $req
if (-not (Test-Path $tool)) { 'turok_controls.exe is not built (port\build_config.ps1)'; exit 1 }
$script:toolProc = $null
function ReadIni() { if (Test-Path $ini) { try { $fs = [IO.File]::Open($ini, 'Open', 'Read', 'ReadWrite'); $sr = New-Object IO.StreamReader($fs); $t = $sr.ReadToEnd(); $sr.Close(); return $t } catch { return '' } } return '' }
function WaitFor([scriptblock]$cond, $sec = 3) { $t1 = Get-Date; while (((Get-Date) - $t1).TotalSeconds -lt $sec) { if (& $cond) { return $true }; Start-Sleep -Milliseconds 80 }; return [bool](& $cond) }
function CtlText($id) { $h = [EW2]::FindById($script:hwnd, $id); if ($h -eq [IntPtr]::Zero) { return $null }; return [EW2]::TextOf($h) }
function Launch-Tool($toolArgs) {
    $env:TUROK_SCRIPT = '1'; $script:toolProc = Start-Process $tool -ArgumentList $toolArgs -PassThru
    $t1 = Get-Date; $script:hwnd = [IntPtr]::Zero; while (((Get-Date) - $t1).TotalSeconds -lt 30) { $script:hwnd = [EW2]::FindMain([uint32]$script:toolProc.Id); if ($script:hwnd -ne [IntPtr]::Zero) { break }; Start-Sleep -Milliseconds 100 }
    $general = ($toolArgs -contains 'general')
    [void](WaitFor { $c = CtlText $ID_CAPTION; ($c -ne $null) -and ($general -or $c -ne '') } 15)         # the window is built and filled (slow when the machine is busy)
    Start-Sleep -Milliseconds 300
    return (Activate)
}
function Stop-Tool() { if ($script:toolProc -and -not $script:toolProc.HasExited) { try { $script:toolProc.Kill() } catch {} }; Start-Sleep -Milliseconds 300 }
function ClickButton($text) { $h = [EW2]::FindByText($script:hwnd, 'Button', $text); if ($h -eq [IntPtr]::Zero) { throw "button '$text' not found" }; ClickHandle $h }
function ClickId($id) { $h = [EW2]::FindById($script:hwnd, $id); if ($h -eq [IntPtr]::Zero) { throw "control $id not found" }; ClickHandle $h }
function ClickHandle($h) {
    $r = [EW2]::RectOf($h); $x = [int](($r[0] + $r[2]) / 2); $y = [int](($r[1] + $r[3]) / 2)
    for ($try = 0; $try -lt 4 -and -not (Focused); $try++) { [void](Activate); Start-Sleep -Milliseconds 250 }
    NeedFocus; [void][Inj]::SetCursorPos($x, $y); Start-Sleep -Milliseconds 80
    $pt = New-Object Inj+POINT; [void][Inj]::GetCursorPos([ref]$pt); $w = [Inj]::WindowFromPoint($pt)
    if ($w -ne $h -and [EW2]::GetAncestor($w, 2) -ne $script:hwnd) { throw 'the mouse cursor is not over the tool window, not clicking' }
    if (-not (Focused)) { throw 'the tool lost the foreground, not clicking' }
    [Inj]::Btn(2, 0); Start-Sleep -Milliseconds 60; [Inj]::Btn(4, 0); Start-Sleep -Milliseconds 250
}
# click Save and wait until the controls file matches; the click is repeated once (the button is disabled when nothing changed, so a second click is harmless)
function SaveWait($pattern, $sec = 4) { for ($try = 0; $try -lt 2; $try++) { ClickButton 'Save'; if (WaitFor { (ReadIni) -match $pattern } $sec) { return $true } }; return $false }
# the popup menus, file dialogs and message boxes of the tool take over the foreground: inject only while a window of the tool process is in front
function ToolInFront() { $p2 = [uint32]0; [void][Inj]::GetWindowThreadProcessId([Inj]::GetForegroundWindow(), [ref]$p2); return ($p2 -eq [uint32]$script:toolProc.Id) }
function WaitDialog($sec) { $t1 = Get-Date; while (((Get-Date) - $t1).TotalSeconds -lt $sec) { if ((ToolInFront) -and [Inj]::GetForegroundWindow() -ne $script:hwnd) { Start-Sleep -Milliseconds 500; return $true }; Start-Sleep -Milliseconds 100 }; return $false }
function ToolKey($n, $times = 1) { for ($i = 0; $i -lt $times; $i++) { if (-not (ToolInFront)) { throw 'the tool is not in front, not injecting' }; [Inj]::Key([uint16]$sc[$n][0], [bool]$sc[$n][1], $true); Start-Sleep -Milliseconds 40; [Inj]::Key([uint16]$sc[$n][0], [bool]$sc[$n][1], $false); Start-Sleep -Milliseconds 150 } }
function ToolType($s) { foreach ($c in $s.ToCharArray()) { if (-not (ToolInFront)) { throw 'the tool is not in front, not injecting' }; [Inj]::Char($c); Start-Sleep -Milliseconds 8 } }
function ToolSelectAll() { if (-not (ToolInFront)) { throw 'the tool is not in front, not injecting' }; [Inj]::Key(0x1D, $false, $true); [Inj]::Key(0x1E, $false, $true); [Inj]::Key(0x1E, $false, $false); [Inj]::Key(0x1D, $false, $false); Start-Sleep -Milliseconds 100 }
# one user-visible action with its expected effect; repeated (after taking the foreground back and closing a stray popup / dialog) when the effect does not show up, because on a shared,
# busy desktop another window can take the foreground between two injected events.  Reports PASS / FAIL once.
function Step($what, [scriptblock]$do, [scriptblock]$ok, $sec = 3, $tries = 4) {
    for ($t = 0; $t -lt $tries; $t++) {
        if ($t -gt 0) { [void][EW2]::CloseStray([uint32]$script:toolProc.Id, $script:hwnd); Start-Sleep -Milliseconds 500; [void](Activate) }
        try { & $do } catch { "      (try $($t + 1): $($_.Exception.Message))"; continue }
        if (WaitFor $ok $sec) { Check $true $what; $script:stepOk = $true; return }
        "      (try $($t + 1): no effect yet; foreground: $([EW2]::Foreground()))"
    }
    Check $false $what; $script:stepOk = $false
}
function WaitStatus($pattern, $sec) { [void](WaitFor { (CtlText $ID_STATUS) -match $pattern } $sec); return (CtlText $ID_STATUS) }
function Section($name) { $m = [regex]::Match((ReadIni), "(?ms)^\[$name\][ \t]*\r?\n(.*?)(?=^\[|\z)"); return $m.Groups[1].Value }
function ShotThis($name) {      # picture of the running tool: it renders itself when it finds the request file (TUROK_CONTROLS_SHOTREQ)
    if ($NoShots) { return }
    Add-Type -AssemblyName System.Drawing
    $bmp = Join-Path $root ("port\build\cfgtest_{0}.bmp" -f $name); Remove-Item $bmp -ErrorAction SilentlyContinue
    Set-Content -Path $req -Value $bmp -Encoding ascii
    $t1 = Get-Date; while (((Get-Date) - $t1).TotalSeconds -lt 8 -and ((Test-Path $req) -or -not (Test-Path $bmp))) { Start-Sleep -Milliseconds 100 }
    Start-Sleep -Milliseconds 300
    if (Test-Path $bmp) { $img = [System.Drawing.Image]::FromFile($bmp); $img.Save((Join-Path $root ("port\build\cfgtest_{0}.png" -f $name)), [System.Drawing.Imaging.ImageFormat]::Png); $img.Dispose(); Remove-Item $bmp }
}
if ($HelpersOnly) { return }
if (Desktop-Locked) { "the desktop is locked (LogonUI is running): this UI test needs an unlocked interactive session, nothing was run"; exit 2 }          # helper functions only (for ad-hoc experiments)
function Release-Keys() { foreach ($k in $sc.Keys) { [Inj]::Key([uint16]$sc[$k][0], [bool]$sc[$k][1], $false) } }          # key-up for every key the harness can press (harmless for keys that are not down)
# every section starts and ends with its own tool process and leaves its result in the controls file; a section with a failure is repeated once from its start (a window that takes
# the foreground in the middle of an injected sequence is the typical cause on a shared desktop; a real bug fails both attempts)
function Run-Section($name, [scriptblock]$body, $attempts = 3) {
    for ($a = 1; $a -le $attempts; $a++) {
        $p0 = $script:pass; $f0 = $script:fail; $script:attempt = $a
        "-- $name$(if ($a -gt 1) { " (attempt $a)" })"
        try { & $body } catch { "ERROR: $($_.Exception.Message)"; $script:fail++ }
        Release-Keys; Stop-Tool
        if ($script:fail -eq $f0) { return }
        if ($a -lt $attempts) { "   (failures in this section: trying it once more)"; $script:pass = $p0; $script:fail = $f0 }
    }
}
function Reset-Ini() { Remove-Item $ini -ErrorAction SilentlyContinue; $env:TUROK_SCRIPT = '1'; $null = Start-Process $tool -ArgumentList '--write-default', $ini -Wait }
try {
    Reset-Ini
    Check (Test-Path $ini) '--write-default writes a controls file'
    Check ((ReadIni) -match '(?m)^\[player1\]' -and (ReadIni) -match '(?m)^Z\s*=\s*game:Mouse1') 'the default file has the documented sections and the default Z binding'

    Run-Section '1. capture a key for Z (replace), Save' {
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z', '--capture')) 'tool started and in front (player 1, Z, capture)'
        Check ((CtlText 101) -ne $null) 'diagram control present'
        $cap = CtlText $ID_CAPTION; Check ($cap -match 'BIND\s+Z:') "the banner tells what to press ($($cap.Substring(0, [Math]::Min(40, $cap.Length))))"
        ShotThis 'capture'
        Step 'a key press (Q) replaces the bindings of Z' { if ((CtlText $ID_CAPTION) -notmatch 'BIND\s+Z') { ClickButton 'Bind...'; Start-Sleep -Milliseconds 400 }; KeyDown 'Q'; Start-Sleep -Milliseconds 150; KeyUp 'Q' } { (CtlText $ID_CAPTION) -match '^Z\s+\(primary fire\):\s+Q$' }
        Check (SaveWait '(?m)^Z\s+=\s+Q\s*$') 'Save wrote "Z = Q" into the controls file'
    }

    Run-Section '2. Add... a wheel tick to L, then Bind... L to the key E (not saved)' {
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'L')) 'tool restarted, reads the saved file'
        $cap = CtlText $ID_CAPTION; Check ($cap -match '^L\s+\(') "the caption shows input L ('$cap')"
        Step 'Add... + a wheel tick adds "Wheel Up" to L' { ClickButton 'Add...'; Start-Sleep -Milliseconds 500; NeedMouse; Wheel 2 } { (CtlText $ID_CAPTION) -match '^L\s+\(.*Wheel Up$' }
        Step 'Bind... + the key E replaces the bindings of L' { ClickButton 'Bind...'; Start-Sleep -Milliseconds 500; KeyDown 'E'; Start-Sleep -Milliseconds 150; KeyUp 'E' } { (CtlText $ID_CAPTION) -match '^L\s+\(.*:\s+E$' }
        ShotThis 'edited'
    }

    Run-Section '3. live preview: held keys show up in the diagram and in the test text' {
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')) 'tool started for the live test'
        Step 'Q (= Z) and Left (= stick left) are shown by the live text' { KeyDown 'Q'; KeyDown 'Left' } { ((CtlText $ID_TESTTEXT) -match 'N64 buttons:\s+.*\bZ\b') -and ((CtlText $ID_TESTTEXT) -match 'x\s*=\s*-80') } 4
        "      live text: $(((CtlText $ID_TESTTEXT) -split "`n")[0..1] -join ' / ')"
        ShotThis 'live'
        KeyUp 'Q'; KeyUp 'Left'
        Check (WaitFor { (CtlText $ID_TESTTEXT) -match 'N64 buttons:\s+-' } 4) 'the live text goes back to idle after the keys are released'
    }

    Run-Section '4. general tab and player 2 tab render (screenshots)' {
        Check (Launch-Tool @('--config', $ini, '--player', 'general')) 'general tab opens'
        ShotThis 'general'; Stop-Tool
        Check (Launch-Tool @('--config', $ini, '--player', '2', '--select', 'CUp')) 'player 2 tab opens'
        ShotThis 'player2'
    }

    Run-Section '5. Stick presets... popup (fifth entry = W A S D) on a fresh default file; the clash with the D-pad keys must be reported' {
        Reset-Ini
        Check (Launch-Tool @('--config', $ini, '--player', '1')) 'tool started for the stick presets'
        Step 'Stick presets... > W A S D is applied and the clash with the D-pad keys is reported' { ClickButton 'Stick presets...'; Start-Sleep -Milliseconds 700; ToolKey 'Down' 5; ToolKey 'Enter' } { (CtlText $ID_STATUS) -match 'Warning: [WASD]( \(menus\))? is bound to both' }
        "      status: $(CtlText $ID_STATUS)"
        ShotThis 'conflict'
        Check (SaveWait '(?m)^StickUp\s+=\s+W\s*$') 'Save wrote the preset'
        $p1 = Section 'player1'; $sl = (($p1 -split "`n" | Where-Object { $_ -cmatch '^Stick(Left|Right|Up|Down)' } | ForEach-Object { $_.Trim() }) -join ' | ')
        Check (($p1 -match '(?m)^StickLeft\s+=\s+A\s*$') -and ($p1 -match '(?m)^StickRight\s+=\s+D\s*$') -and ($p1 -match '(?m)^StickUp\s+=\s+W\s*$') -and ($p1 -match '(?m)^StickDown\s+=\s+S\s*$')) "the file has StickLeft = A, StickRight = D, StickUp = W, StickDown = S ($sl)"
    }

    Run-Section '6. keyboard layout list + Apply: the third entry is kb_left (Z = LShift)' {
        Check (Launch-Tool @('--config', $ini, '--player', '1')) 'tool started for the layouts'
        Step 'choosing the left-hand layout in the list and pressing Apply puts kb_left on player 1' { $cb = [EW2]::FindById($script:hwnd, $ID_KBLAYOUT); [void][EW2]::SendMessage($cb, 0x14E, [IntPtr]2, [IntPtr]::Zero); ClickId $ID_KBAPPLY } { (CtlText $ID_STATUS) -match 'Applied the kb_left layout' }
        "      status: $(CtlText $ID_STATUS)"
        Check (SaveWait '(?m)^Z[ \t]*=[^\r\n]*LShift\b') 'Save wrote Z = LShift'
        Check ((Section 'player1') -match '(?m)^StickLeft\s+=\s+[^\r\n]*\bQ\b') 'the layout also moved the stick keys (StickLeft contains Q)'
    }

    Run-Section '7. Copy from... > player 1: player 2 takes over the bindings of player 1' {
        Check (Launch-Tool @('--config', $ini, '--player', '2', '--select', 'Z')) 'tool started on the player 2 tab'
        if ($script:attempt -eq 1) { Check ((Section 'player2') -notmatch '(?m)^Z[ \t]*=[^\r\n]*LShift') 'player 2 does not have Z = LShift yet' }
        Step 'Copy from... > player 1 copies the bindings to player 2' { ClickButton 'Copy from...'; Start-Sleep -Milliseconds 700; ToolKey 'Down' 1; ToolKey 'Enter' } { (CtlText $ID_CAPTION) -match 'LShift' }
        "      status: $(CtlText $ID_STATUS)"
        Check (SaveWait '(?ms)^\[player2\].*?^Z[ \t]*=[^\r\n]*LShift\b') 'Save wrote the copy into the [player2] section'
    }

    Run-Section '8. Reset to defaults (message box: N = no, Y = yes) on player 1' {
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')) 'tool started for the reset'
        Check ((CtlText $ID_CAPTION) -match 'LShift') 'player 1 has Z = LShift'
        Step 'the reset asks for confirmation and N keeps the bindings' { ClickButton 'Reset to defaults'; if (-not (WaitDialog 8)) { throw 'no message box' }; ToolKey 'N' } { (CtlText $ID_STATUS) -notmatch 'Reset to the defaults' -and -not ((ToolInFront) -and ([Inj]::GetForegroundWindow() -ne $script:hwnd)) }
        Check ((CtlText $ID_CAPTION) -match 'LShift') 'answering No keeps the bindings'
        Step 'answering Yes resets player 1 to the default bindings' { ClickButton 'Reset to defaults'; if (-not (WaitDialog 8)) { throw 'no message box' }; ToolKey 'Y' } { (CtlText $ID_CAPTION) -match 'Mouse Left' }
        Check (SaveWait '(?m)^Z\s+=\s+game:Mouse1') 'Save wrote the default Z binding again'
    }

    $exp = Join-Path $root 'port\build\controls_export_test.ini'
    Run-Section '9a. Export... (Save As dialog, the path is typed)' {
        Remove-Item $exp -ErrorAction SilentlyContinue
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')) 'tool started for the export'
        Step 'Export... writes the typed file name' { ClickButton 'Export...'; if (-not (WaitDialog 15)) { throw 'no file dialog' }; ToolSelectAll; ToolType $exp; ToolKey 'Enter' } { Test-Path $exp } 8
        Check ((Test-Path $exp) -and ((Get-Content $exp -Raw) -match '(?m)^Z\s+=\s+game:Mouse1')) 'the exported file holds the current bindings'
    }
    if (Test-Path $exp) { $t = Get-Content $exp -Raw; Set-Content $exp ($t -replace '(?m)^Z\s+=.*$', 'Z = P') -NoNewline -Encoding ascii }         # a "foreign" file with Z = P
    Run-Section '9b. Import... (Open dialog, then "Import everything" in the popup menu)' {
        Check (Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')) 'tool started for the import'
        Step 'Import... > everything takes the bindings of the chosen file' { ClickButton 'Import...'; if (-not (WaitDialog 15)) { throw 'no file dialog' }; ToolSelectAll; ToolType $exp; ToolKey 'Enter'; Start-Sleep -Milliseconds 1000; ToolKey 'Down' 1; ToolKey 'Enter' } { (CtlText $ID_CAPTION) -match ':\s+P$' } 6
        "      status: $(CtlText $ID_STATUS)"
        ShotThis 'imported'
    }
    Remove-Item $exp -ErrorAction SilentlyContinue

    Run-Section '10. Launch game: the tool starts the game with this controls file; Save in the tool is picked up by the running game (hot reload)' {
        $script:exeName = [IO.Path]::GetFileNameWithoutExtension((Get-Content (Join-Path $root 'port\build\latest_exe.txt')).Trim())
        Remove-Item $script:log -ErrorAction SilentlyContinue
        $env:TUROK_LOG = $script:log; $env:TUROK_INPUTLOG = '1'; $env:TUROK_SKIPMENU = '1'          # inherited by the tool and, through it, by the game
        $ok = Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')
        $env:TUROK_LOG = $null; $env:TUROK_INPUTLOG = $null; $env:TUROK_SKIPMENU = $null
        Check $ok 'tool started for the launch test'
        ClickButton 'Launch game'
        $m = Wait-Log 'controls loaded from' 90
        Check ($m -and ($m -match [regex]::Escape($ini))) "the launched game loaded the controls file of the tool ('$m')"
        $n = LogCount
        [void](Activate)
        Step 'Z is rebound to F while the game runs' { ClickButton 'Bind...'; Start-Sleep -Milliseconds 500; KeyDown 'F'; Start-Sleep -Milliseconds 150; KeyUp 'F' } { (CtlText $ID_CAPTION) -match ':\s+F$' }
        Check (SaveWait '(?m)^Z\s+=\s+F\s*$') 'Save wrote the new binding'
        $m = Wait-Log 'controls loaded from' 12 $n
        Check ($m -ne $null) 'the running game reloaded the controls file after Save in the tool (hot reload)'
        Stop-Game
    }

    # gamepad paths of the tool without hardware: TUROK_FAKEPADS=1 makes XInput slot 1 a virtual pad that exists while port_fakepad1.txt exists (see input_dev.c)
    Run-Section '11. gamepad paths of the tool with a virtual XInput pad: hot-plug list, live preview, capture' {
        FakePadOff 1; Reset-Ini
        $env:TUROK_FAKEPADS = '1'
        $ok = Launch-Tool @('--config', $ini, '--player', '1', '--select', 'Z')
        $env:TUROK_FAKEPADS = $null
        Check $ok 'tool started with virtual pads enabled'
        $cb = [EW2]::FindById($script:hwnd, 118)                                                      # the gamepad list of the player page: "Automatic" + one entry per connected pad
        $n0 = [int][EW2]::SendMessage($cb, 0x146, [IntPtr]::Zero, [IntPtr]::Zero)                    # CB_GETCOUNT
        "      gamepad list without a pad: $n0 entries"
        FakePad 1
        Check (WaitFor { [int][EW2]::SendMessage($cb, 0x146, [IntPtr]::Zero, [IntPtr]::Zero) -eq $n0 + 1 } 8) 'plugging in a pad adds it to the gamepad list (hot-plug)'
        Check (WaitFor { (CtlText $ID_TESTTEXT) -match 'LX 0\.00' } 4) 'the live text shows the pad axes'
        FakePad 1 0x1000                                                                              # XINPUT_GAMEPAD_A: R in free play (xbox layout)
        Check (WaitFor { (CtlText $ID_TESTTEXT) -match 'N64 buttons:\s+.*\bR\b' } 4) 'pad A shows as N64 R in the live text (free play)'
        FakePad 1
        FakePad 1 0 0 0 20000 0 0 0                                                                   # right stick x = +0.61 -> stick right
        Check (WaitFor { (CtlText $ID_TESTTEXT) -match 'x\s*=\s*[1-9]\d' } 4) "the right stick moves the N64 stick ('$(((CtlText $ID_TESTTEXT) -split "`n")[0])')"
        FakePad 1
        Step 'Bind... + the right trigger of the pad binds Z to the trigger' { if ((CtlText $ID_CAPTION) -notmatch 'BIND\s+Z') { ClickButton 'Bind...'; Start-Sleep -Milliseconds 700 }; FakePad 1 0 0 0 0 0 0 255 } { (CtlText $ID_CAPTION) -match '^Z\s+\(primary fire\):\s+Pad right trigger$' } 5
        FakePad 1
        Step 'Add... + pad button B adds it to Z' { ClickButton 'Add...'; Start-Sleep -Milliseconds 700; FakePad 1 0x2000 } { (CtlText $ID_CAPTION) -match 'Pad right trigger,\s+Pad B$' } 5
        FakePad 1
        FakePadOff 1
        Check (WaitFor { [int][EW2]::SendMessage($cb, 0x146, [IntPtr]::Zero, [IntPtr]::Zero) -eq $n0 } 8) 'unplugging removes the pad from the list'
    }

    # sliders (ids 200..205 = mouse X, mouse Y, stick dead zone, stick sensitivity, curve, trigger threshold; value labels 240..245) and the invert check boxes (260, 261)
    Run-Section '12. sensitivity / dead zone sliders and the invert check boxes' {
        Reset-Ini
        Check (Launch-Tool @('--config', $ini, '--player', '1')) 'tool started for the sliders'
        $v0 = CtlText 242
        Step 'clicking the dead zone slider and pressing Right raises its value' { ClickId 202; ToolKey 'Right' 3 } { (CtlText 242) -ne $v0 }
        $v1 = CtlText 242; "      dead zone: $v0 -> $v1"
        $inv = [EW2]::FindById($script:hwnd, 260)
        Step 'the "Invert mouse Y" check box turns on' { if ([int][EW2]::SendMessage($inv, 0xF0, [IntPtr]::Zero, [IntPtr]::Zero) -eq 0) { ClickId 260 } } { [int][EW2]::SendMessage($inv, 0xF0, [IntPtr]::Zero, [IntPtr]::Zero) -eq 1 }
        Check (SaveWait '(?m)^mouse_invert_y\s*=\s*on') 'Save wrote mouse_invert_y = on'
        $p1 = Section 'player1'; $m = [regex]::Match($p1, '(?m)^stick_deadzone\s*=\s*([0-9.]+)')
        Check ($m.Success -and [Math]::Abs([double]$m.Groups[1].Value - [double]$v1) -lt 0.006) "the file holds the slider value as stick_deadzone ($($m.Groups[1].Value) for the label $v1)"
        Check ((Section 'player2') -match '(?m)^stick_deadzone\s*=\s*0\.2\b') 'player 2 is unaffected'
        ShotThis 'sliders'
    }
} catch { "ERROR: $($_.Exception.Message)"; $script:fail++ }
finally { $env:TUROK_CONTROLS_SHOTREQ = $null; $env:TUROK_FAKEPADS = $null; FakePadOff 1; Stop-Tool; Release-Keys; if ($script:exeName) { Stop-Game }; [void][Inj]::SetCursorPos($script:origPt.X, $script:origPt.Y); if ($script:origFg -ne [IntPtr]::Zero) { [void][Inj]::SetForegroundWindow($script:origFg) } }
"UI TEST RESULT: $($script:pass) passed, $($script:fail) failed"
