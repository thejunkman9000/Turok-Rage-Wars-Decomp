# Synthetic keyboard / mouse input into the running port with SendInput, plus checks of the input log (TUROK_INPUTLOG=1) and screenshots.
#   .\port\input_inject.ps1 -Scenario smoke        hotkeys (F3 report, F2 reload, Esc confirmation), focus handling
#   .\port\input_inject.ps1 -Scenario menu         main menu with the keyboard and the mouse buttons (Enter, arrows, E = A, S = D-pad down, clicks), mouse guard
#   .\port\input_inject.ps1 -Scenario level        scripted menu path into a 1-player level (port_input.txt as in lvltest), then keyboard + mouse in the level
#   .\port\input_inject.ps1 -Scenario levelkb      the same, but the menu path itself is typed on the keyboard (Enter, arrows, E) through SendInput
#   .\port\input_inject.ps1 -Scenario split        two players on one keyboard (kb_left / kb_right profiles via a TUROK_CONTROLS test file)
#   .\port\input_inject.ps1 -Scenario pad          virtual XInput pads (TUROK_FAKEPADS): assignment, menus, level, focus gating, hot-plug, rumble
#   .\port\input_inject.ps1 -Scenario fullscreen Ctrl+Enter / Alt+Enter toggle the borderless full screen, the choice is saved and restored
#   .\port\input_inject.ps1 -Scenario all
# SAFETY: the script injects only while the game window is the foreground window (it activates it first and re-checks before every burst), puts the mouse cursor
# into the game window before injecting mouse input, keeps the bursts short, restores the previous foreground window and the mouse position at the end and kills the
# game it started (by its unique exe name).  Needs an interactive desktop; a person using the mouse at the same time disturbs the "no mouse motion" checks.
param([string]$Scenario = 'all', [int]$Speed = 10, [string]$Prefix = 'inj', [switch]$Lib)
Add-Type -Namespace W32 -Name Dpi -MemberDefinition '[DllImport("user32.dll")] public static extern bool SetProcessDPIAware();' -ErrorAction SilentlyContinue; [void][W32.Dpi]::SetProcessDPIAware()      # the port is DPI aware: its window rectangles are in physical pixels, so this script must be too
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
Add-Type @"
using System; using System.Runtime.InteropServices; using System.Text;
public class Inj {
  [StructLayout(LayoutKind.Sequential)] public struct MOUSEINPUT { public int dx, dy; public uint mouseData, dwFlags, time; public IntPtr extra; }
  [StructLayout(LayoutKind.Sequential)] public struct KEYBDINPUT { public ushort wVk, wScan; public uint dwFlags, time; public IntPtr extra; }
  [StructLayout(LayoutKind.Explicit)] public struct IU { [FieldOffset(0)] public MOUSEINPUT mi; [FieldOffset(0)] public KEYBDINPUT ki; }
  [StructLayout(LayoutKind.Sequential)] public struct INPUT { public uint type; public IU u; }
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L, T, R, B; }
  [StructLayout(LayoutKind.Sequential)] public struct POINT { public int X, Y; }
  [StructLayout(LayoutKind.Sequential)] public struct CURSORINFO { public int cbSize, flags; public IntPtr hCursor; public POINT pt; }
  [DllImport("user32.dll")] public static extern uint SendInput(uint n, INPUT[] i, int size);
  [DllImport("user32.dll")] public static extern IntPtr GetForegroundWindow();
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
  [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int cmd);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern bool AttachThreadInput(uint a, uint b, bool attach);
  [DllImport("kernel32.dll")] public static extern uint GetCurrentThreadId();
  [DllImport("user32.dll")] public static extern bool GetClipCursor(out RECT r);
  [DllImport("user32.dll")] public static extern bool GetCursorPos(out POINT p);
  [DllImport("user32.dll")] public static extern bool SetCursorPos(int x, int y);
  [DllImport("user32.dll")] public static extern bool GetCursorInfo(ref CURSORINFO ci);
  [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern int GetWindowLongA(IntPtr h, int idx);
  [DllImport("user32.dll")] public static extern IntPtr WindowFromPoint(POINT p);
  [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref POINT p);
  [DllImport("user32.dll", CharSet=CharSet.Ansi)] public static extern int GetWindowTextA(IntPtr h, StringBuilder s, int n);
  public static void Key(ushort sc, bool ext, bool down) {
    INPUT[] a = new INPUT[1]; a[0].type = 1; a[0].u.ki.wScan = sc; a[0].u.ki.dwFlags = 0x8u | (ext ? 1u : 0u) | (down ? 0u : 2u);
    SendInput(1, a, Marshal.SizeOf(typeof(INPUT)));
  }
  public static void Char(char c) { INPUT[] a = new INPUT[2]; a[0].type = 1; a[0].u.ki.wScan = c; a[0].u.ki.dwFlags = 4u; a[1].type = 1; a[1].u.ki.wScan = c; a[1].u.ki.dwFlags = 6u; SendInput(2, a, Marshal.SizeOf(typeof(INPUT))); }   // one unicode character (typing into dialogs)
  public static void Move(int dx, int dy) { INPUT[] a = new INPUT[1]; a[0].type = 0; a[0].u.mi.dx = dx; a[0].u.mi.dy = dy; a[0].u.mi.dwFlags = 1; SendInput(1, a, Marshal.SizeOf(typeof(INPUT))); }
  public static void Btn(uint flags, uint data) { INPUT[] a = new INPUT[1]; a[0].type = 0; a[0].u.mi.dwFlags = flags; a[0].u.mi.mouseData = data; SendInput(1, a, Marshal.SizeOf(typeof(INPUT))); }
}
"@
# scancode set 1 (second element = extended key)
$sc = @{ Esc = @(0x01, 0); '1' = @(0x02, 0); Q = @(0x10, 0); W = @(0x11, 0); E = @(0x12, 0); R = @(0x13, 0); Enter = @(0x1C, 0); A = @(0x1E, 0); S = @(0x1F, 0); D = @(0x20, 0); F = @(0x21, 0); Z = @(0x2C, 0); X = @(0x2D, 0); C = @(0x2E, 0); Y = @(0x15, 0); N = @(0x31, 0)
         V = @(0x2F, 0); LShift = @(0x2A, 0); LCtrl = @(0x1D, 0); LAlt = @(0x38, 0); Space = @(0x39, 0); F1 = @(0x3B, 0); F2 = @(0x3C, 0); F3 = @(0x3D, 0); Num4 = @(0x4B, 0); Num6 = @(0x4D, 0); Num8 = @(0x48, 0); Num5 = @(0x4C, 0); Num0 = @(0x52, 0)
         Up = @(0x48, 1); Down = @(0x50, 1); Left = @(0x4B, 1); Right = @(0x4D, 1); RCtrl = @(0x1D, 1); NumEnter = @(0x1C, 1) }
$btn = @{ 'C' = 0x8000; 'Start' = 0x1000 }
$script:log = Join-Path $root "port\build\run_$Prefix.log"
$script:pass = 0; $script:fail = 0; $script:proc = $null; $script:exeName = $null; $script:hwnd = [IntPtr]::Zero; $script:origFg = [Inj]::GetForegroundWindow(); $script:origPt = New-Object Inj+POINT; [void][Inj]::GetCursorPos([ref]$script:origPt)

function Desktop-Locked() { return [bool](Get-Process -Name LogonUI -ErrorAction SilentlyContinue) }      # the lock screen / logon UI is up: SendInput would go to it, the tests cannot run
function Check($ok, $what) { if ($ok) { $script:pass++; "  PASS  $what" } else { $script:fail++; "  FAIL  $what" } }
function Frame() { for ($r = 0; $r -lt 20; $r++) { try { return [long]([IO.File]::ReadAllText((Join-Path $root 'port_frame.txt')).Trim()) } catch { Start-Sleep -Milliseconds 5 } }; return -1 }
function WaitFrames($sec) { $f0 = Frame; if ($f0 -lt 0) { Start-Sleep -Milliseconds 300; return }; $target = $f0 + [long]($sec * 60); $limit = $sec * 4 / [Math]::Max(1, $Speed) + 3; $t1 = Get-Date
  while ((Frame) -lt $target -and ((Get-Date) - $t1).TotalSeconds -lt $limit) { Start-Sleep -Milliseconds 8 } }
function LogLines() { try { $fs = [IO.File]::Open($script:log, 'Open', 'Read', 'ReadWrite'); $sr = New-Object IO.StreamReader($fs); $t = $sr.ReadToEnd(); $sr.Close(); $a = @($t -split "`r?`n"); if ($a.Count -gt 0 -and $a[-1] -eq '') { $a = $a[0..($a.Count - 2)] }; return @($a) } catch { return @() } }   # the game still has the log open for writing
function LogCount() { return (LogLines).Count }
function Log-Since($from, $pattern) { $l = LogLines; if ($l.Count -le $from) { return @() }; return @($l[$from..($l.Count - 1)] | Where-Object { $_ -match $pattern }) }
function Wait-Log($pattern, $sec, $fromLine = 0) { $t1 = Get-Date; while (((Get-Date) - $t1).TotalSeconds -lt $sec) { $m = Log-Since $fromLine $pattern | Select-Object -First 1; if ($m) { return $m }; Start-Sleep -Milliseconds 100 }; return $null }
# did the real devices produce a state for player $pl after log line $from with all bits of $mask set and the condition (an expression over $x, $y, $ctx) true?
function SeenCount($from, $mask, $cond = '$true', $pl = 1) {
    $n = 0; foreach ($l in (Log-Since $from "input: P$pl buttons=")) {
        if ($l -match 'input: P\d buttons=([0-9A-F]{4}) stick=(-?\d+),(-?\d+) ctx=(-?\d)') { $b = [Convert]::ToInt32($Matches[1], 16); $x = [int]$Matches[2]; $y = [int]$Matches[3]; $ctx = [int]$Matches[4]
            if ((($b -band $mask) -eq $mask) -and (Invoke-Expression $cond)) { $n++ } } }
    return $n
}
function Seen($from, $mask, $cond = '$true', $pl = 1) { return ((SeenCount $from $mask $cond $pl) -gt 0) }
function Wait-Seen($from, $mask, $cond = '$true', $pl = 1, $sec = 4) { $t1 = Get-Date; while (((Get-Date) - $t1).TotalSeconds -lt $sec) { if (Seen $from $mask $cond $pl) { return $true }; Start-Sleep -Milliseconds 60 }; return $false }

function Focused() { return ([Inj]::GetForegroundWindow() -eq $script:hwnd) }
function Activate() {
    if ($script:hwnd -eq [IntPtr]::Zero) { return $false }
    for ($i = 0; $i -lt 5; $i++) {
        if (Focused) { return $true }
        [void][Inj]::ShowWindow($script:hwnd, 9)
        $pid2 = 0; $fgThread = [Inj]::GetWindowThreadProcessId([Inj]::GetForegroundWindow(), [ref]$pid2); $me = [Inj]::GetCurrentThreadId()
        [void][Inj]::AttachThreadInput($me, $fgThread, $true); [void][Inj]::SetForegroundWindow($script:hwnd); [void][Inj]::AttachThreadInput($me, $fgThread, $false)
        Start-Sleep -Milliseconds 200
    }
    return (Focused)
}
function NeedFocus() { if (-not (Focused)) { if (-not (Activate)) { throw "game window lost the foreground, not injecting" } } }      # something else took the foreground: take it back once, else give up (never inject into another window)
function ClientScreenRect() { $r = New-Object Inj+RECT; [void][Inj]::GetClientRect($script:hwnd, [ref]$r); $a = New-Object Inj+POINT; $a.X = 0; $a.Y = 0; [void][Inj]::ClientToScreen($script:hwnd, [ref]$a); $b = New-Object Inj+POINT; $b.X = $r.R; $b.Y = $r.B; [void][Inj]::ClientToScreen($script:hwnd, [ref]$b); return @($a.X, $a.Y, $b.X, $b.Y) }
# mouse bursts: the cursor must be over the game window, otherwise a click would land in whatever window is under it
function NeedMouse() { NeedFocus; $r = ClientScreenRect; $cx = [int](($r[0] + $r[2]) / 2); $cy = [int](($r[1] + $r[3]) / 2); $pt = New-Object Inj+POINT; [void][Inj]::GetCursorPos([ref]$pt)
    if (($pt.X -lt $r[0] + 5) -or ($pt.X -gt $r[2] - 5) -or ($pt.Y -lt $r[1] + 5) -or ($pt.Y -gt $r[3] - 5)) { [void][Inj]::SetCursorPos($cx, $cy); Start-Sleep -Milliseconds 30; [void][Inj]::GetCursorPos([ref]$pt) }
    if ([Inj]::WindowFromPoint($pt) -ne $script:hwnd) { throw "the mouse cursor is not over the game window, not injecting mouse input" } }
function KeyDown($n) { NeedFocus; [Inj]::Key([uint16]$sc[$n][0], [bool]$sc[$n][1], $true) }
function KeyUp($n) { [Inj]::Key([uint16]$sc[$n][0], [bool]$sc[$n][1], $false) }
function Tap($n, $sec = 0.4) { KeyDown $n; WaitFrames $sec; KeyUp $n; WaitFrames 0.2 }
function MouseBtn($which, $down) { NeedMouse
    $f = @{ L = @(2, 4, 0); R = @(8, 16, 0); M = @(32, 64, 0); X1 = @(128, 256, 1); X2 = @(128, 256, 2) }[$which]; [Inj]::Btn($(if ($down) { [uint32]$f[0] } else { [uint32]$f[1] }), [uint32]$f[2]) }
function Wheel([int]$ticks) { NeedMouse; [Inj]::Btn(0x800, [BitConverter]::ToUInt32([BitConverter]::GetBytes([int]($ticks * 120)), 0)) }
function MouseMove($dx, $dy) { NeedMouse; [Inj]::Move($dx, $dy) }
function Release-All() { foreach ($k in $sc.Keys) { try { KeyUp $k } catch {} }; foreach ($b in 'L', 'R', 'M') { try { [Inj]::Btn($(@{ L = [uint32]4; R = [uint32]16; M = [uint32]64 }[$b]), 0) } catch {} } }
# press a key (or a mouse button / wheel) and keep it down until the log shows the expected state (the game only polls every 1-2 frames), then release it
# (up to 3 attempts: on a shared desktop another program can eat a key now and then; a real bug fails all three)
function Expect-Key($key, $mask, $cond, $what, $pl = 1) { $ok = $false; for ($try = 0; $try -lt 3 -and -not $ok; $try++) { $n = LogCount; KeyDown $key; $ok = Wait-Seen $n $mask $cond $pl 1.5; KeyUp $key; WaitFrames 0.3 }; Check $ok $what }
function Expect-Click($which, $mask, $cond, $what, $pl = 1) { $ok = $false; for ($try = 0; $try -lt 3 -and -not $ok; $try++) { $n = LogCount; MouseBtn $which $true; $ok = Wait-Seen $n $mask $cond $pl 1.5; MouseBtn $which $false; WaitFrames 0.3 }; Check $ok $what }

function Start-Game($extraEnv = @{}) {
    $exe = (Get-Content port\build\latest_exe.txt).Trim()
    Remove-Item $script:log, port_frame.txt, port_frame.tmp, port_input.txt, port_input2.txt -ErrorAction SilentlyContinue
    $env:TUROK_LOG = $script:log; $env:TUROK_SKIPMENU = '1'; $env:TUROK_INPUTLOG = '1'; if ($Speed -gt 1) { $env:TUROK_SPEED = [string]$Speed }
    foreach ($k in $extraEnv.Keys) { Set-Item -Path "env:$k" -Value $extraEnv[$k] }
    $script:exeName = [IO.Path]::GetFileNameWithoutExtension($exe)
    $null = Start-Process (Join-Path $root $exe) -WorkingDirectory $root -PassThru
    $env:TUROK_LOG = $null; $env:TUROK_SKIPMENU = $null; $env:TUROK_INPUTLOG = $null; $env:TUROK_SPEED = $null; foreach ($k in $extraEnv.Keys) { Set-Item -Path "env:$k" -Value $null }
    $t1 = Get-Date; $script:proc = $null
    while (((Get-Date) - $t1).TotalSeconds -lt 30) {      # the exe may relaunch itself (new ASLR layout when a guest address range is taken): look for the window by process name
        $script:proc = Get-Process -Name $script:exeName -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Sort-Object StartTime -Descending | Select-Object -First 1
        if ($script:proc) { break }; Start-Sleep -Milliseconds 100 }
    if (-not $script:proc) { throw "the game window did not appear" }
    $script:hwnd = $script:proc.MainWindowHandle
    "game started: pid $($script:proc.Id), window $($script:hwnd)"
}
function Stop-Game() {
    Release-All
    if ($script:exeName) { Get-Process -Name $script:exeName -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} } }      # only this workspace's build (the name carries the link time)
    Start-Sleep -Milliseconds 400
    [void][Inj]::SetCursorPos($script:origPt.X, $script:origPt.Y)
    if ($script:origFg -ne [IntPtr]::Zero) { [void][Inj]::SetForegroundWindow($script:origFg) }
}
function Shot($name) { & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1}.png" -f $Prefix, $name) | Out-Null }
function Hold-File($f, $b, $x, $y, $sec) { $v = ('{0:X} {1} {2} {3}' -f $b, $x, $y, [Math]::Max(1, [int]($sec * 60))); for ($r = 0; $r -lt 40; $r++) { try { Set-Content -Path $f -Value $v -Encoding ascii -ErrorAction Stop; break } catch { Start-Sleep -Milliseconds 5 } }; WaitFrames $sec; for ($r = 0; $r -lt 40; $r++) { Remove-Item $f -ErrorAction SilentlyContinue; if (-not (Test-Path $f)) { break }; Start-Sleep -Milliseconds 5 } }
function Clip() { $r = New-Object Inj+RECT; [void][Inj]::GetClipCursor([ref]$r); return $r }
function CursorShowing() { $ci = New-Object Inj+CURSORINFO; $ci.cbSize = [Runtime.InteropServices.Marshal]::SizeOf([type]'Inj+CURSORINFO'); [void][Inj]::GetCursorInfo([ref]$ci); return (($ci.flags -band 1) -ne 0) }
function Title() { $sb = New-Object System.Text.StringBuilder 300; [void][Inj]::GetWindowTextA($script:hwnd, $sb, 300); return $sb.ToString() }

# the scripted menu path of lvltest.ps1 (boot -> 1 player trial -> level), through the port_input files
function Go-ToLevel() {
    $t0 = Get-Date
    while (((Get-Date) - $t0).TotalSeconds -lt 60) { Start-Sleep -Milliseconds ([int](1000 / [Math]::Max(1, $Speed))); if (((Get-Date) - $t0).TotalSeconds -lt [Math]::Max(2, 16 / $Speed)) { continue }; if (Select-String -Path $script:log -Pattern '-> 3 ' -ErrorAction SilentlyContinue) { break }; Hold-File 'port_input.txt' 0x1000 0 0 0.4 }
    WaitFrames 3
    $seq = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:-80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'wait:4')
    foreach ($s in $seq) { $p = $s.Split(':'); if ($p[0] -eq 'wait') { WaitFrames ([double]$p[1]) } elseif ($p[0] -eq 'stick') { Hold-File 'port_input.txt' 0 ([int]$p[1]) ([int]$p[2]) ([double]$p[3]) } else { Hold-File 'port_input.txt' $btn[$p[0]] 0 0 ([double]$p[1]) } }
    return [bool](Select-String -Path $script:log -Pattern 'game state: g=\w+ st=13' -ErrorAction SilentlyContinue)
}

function Scenario-Smoke() {
    "== smoke: hotkeys and focus =="
    Start-Game @{}
    WaitFrames 5; Start-Sleep -Seconds 2
    Check (Select-String -Path $script:log -Pattern 'input: attached to the window' -Quiet) 'input system attached (log)'
    Check (Activate) 'game window activated'
    $n = LogCount; Tap 'F3' 0.2; Start-Sleep -Milliseconds 300
    Check ((Log-Since $n 'input: player 1: keyboard=1 mouse=1').Count -ge 1) 'F3 prints the device report (player 1 keyboard + mouse)'
    Check ((Log-Since $n 'input: player 2: keyboard=0 mouse=0 pads=0 connected=0').Count -ge 1) 'player 2 has no device and is reported disconnected'
    $n = LogCount; Tap 'F2' 0.2; Start-Sleep -Milliseconds 400
    Check ((Log-Since $n 'controls (file not found|loaded)').Count -ge 1) 'F2 reloads the controls'
    Check ($script:proc.HasExited -eq $false) 'process alive'
    # Esc: with the mouse not captured the first Esc only arms the quit confirmation
    $n = LogCount; Tap 'Esc' 0.2; Start-Sleep -Milliseconds 500
    Check ((Log-Since $n 'press Esc again to quit').Count -ge 1 -and -not $script:proc.HasExited) 'first Esc does not quit (confirmation)'
    Tap 'Esc' 0.2; Start-Sleep -Milliseconds 1500; $script:proc.Refresh()
    Check ($script:proc.HasExited) 'second Esc quits'
    Stop-Game
}

function Scenario-Menu() {
    "== menu: main menu with the keyboard and the mouse buttons =="
    Start-Game @{}
    if (-not (Activate)) { Check $false 'game window activated'; Stop-Game; return }
    $n = LogCount
    $t0 = Get-Date; $menu = $null      # Start taps until the main menu (screen 3)
    while (((Get-Date) - $t0).TotalSeconds -lt 60 -and -not $menu) { Start-Sleep -Milliseconds 700; if (((Get-Date) - $t0).TotalSeconds -lt [Math]::Max(2, 16 / $Speed)) { continue }; $menu = Select-String -Path $script:log -Pattern '-> 3 ' | Select-Object -First 1; if (-not $menu) { Tap 'Enter' 0.4 } }
    Check ($null -ne $menu) 'main menu reached'
    WaitFrames 3; Shot 'menu0'
    Expect-Key 'Enter' 0x1000 '$true' 'Enter = Start'
    Expect-Key 'Down' 0 '$x -eq 0 -and $y -eq -80' 'Down arrow = stick down (0,-80)'
    Shot 'menu1'
    Expect-Key 'Up' 0 '$x -eq 0 -and $y -eq 80' 'Up arrow = stick up (0,80)'
    Expect-Key 'S' 0x0400 '$ctx -eq 0' 'S in a menu = D-pad down (menu context layer)'
    Expect-Key 'E' 0x8000 '$ctx -eq 0' 'E = A'
    Expect-Click 'L' 0x8000 '$ctx -eq 0' 'left mouse button = A in menus'
    Expect-Click 'R' 0x4000 '$true' 'right mouse button = B'
    $n = LogCount; for ($i = 0; $i -lt 6; $i++) { MouseMove 120 0; WaitFrames 0.1 }; WaitFrames 1
    Check (-not (Seen $n 0 '$x -ge 40')) 'big mouse motion does not move the stick in menus (guard)'
    Stop-Game
}

# the same menu path as Go-ToLevel, typed on the keyboard through SendInput only: Enter = Start, arrow keys = stick, E = A
function Go-ToLevelKeys() {
    $t0 = Get-Date; $act = $false; for ($i = 0; $i -lt 10 -and -not $act; $i++) { $act = Activate; if (-not $act) { Start-Sleep -Milliseconds 500 } }       # another window (the desktop's own tools) may hold the foreground for a moment
    if (-not $act) { return $false }
    while (((Get-Date) - $t0).TotalSeconds -lt 60) { Start-Sleep -Milliseconds ([int](1000 / [Math]::Max(1, $Speed))); if (((Get-Date) - $t0).TotalSeconds -lt [Math]::Max(2, 16 / $Speed)) { continue }; if (Select-String -Path $script:log -Pattern '-> 3 ' -ErrorAction SilentlyContinue) { break }; Tap 'Enter' 0.4 }
    WaitFrames 3
    $seq = @('wait:2', 'stick:0:-80:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'stick:-80:0:0.25', 'wait:1', 'C:0.3', 'wait:5', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'C:0.3', 'wait:6', 'wait:4')
    foreach ($q in $seq) { $p = $q.Split(':'); if ($p[0] -eq 'wait') { WaitFrames ([double]$p[1]) } elseif ($p[0] -eq 'stick') { $k = if ([int]$p[1] -gt 0) { 'Right' } elseif ([int]$p[1] -lt 0) { 'Left' } elseif ([int]$p[2] -lt 0) { 'Down' } else { 'Up' }; Tap $k ([double]$p[3]) } else { Tap 'E' ([double]$p[1]) } }
    return [bool](Select-String -Path $script:log -Pattern 'game state: g=\w+ st=13' -ErrorAction SilentlyContinue)
}

function Scenario-Level() {
    "== level: scripted menu path, then keyboard + mouse in the level =="
    Start-Game @{}
    $in = Go-ToLevel
    Check $in 'level reached (st=13)'
    if (-not $in) { Stop-Game; return }
    Level-Checks
    Stop-Game
}
function Scenario-LevelKeys() {
    "== levelkb: from the title screen into a 1-player level with the keyboard only (SendInput), then keyboard + mouse in the level =="
    Start-Game @{}
    $in = Go-ToLevelKeys
    Check $in 'level reached through the menus with keyboard input only (st=13)'
    if (-not $in) { Stop-Game; return }
    Level-Checks
    Stop-Game
}
function Level-Checks() {
    WaitFrames 4
    Check (Activate) 'game window activated'
    Start-Sleep -Milliseconds 500
    Shot 'lvl0'
    Expect-Key 'W' 0x0008 '$ctx -eq 1' 'W = C-Up (move forward) in game context (ctx=1)'
    Expect-Key 'A' 0x0002 '$ctx -eq 1' 'A = C-Left (strafe left)'
    Expect-Key 'S' 0x0004 '$ctx -eq 1' 'S = C-Down (move back)'
    Expect-Key 'D' 0x0001 '$ctx -eq 1' 'D = C-Right (strafe right)'
    Expect-Key 'Left' 0 '$x -eq -80 -and $ctx -eq 1' 'Left arrow = stick x -80'
    Expect-Key 'Space' 0x0010 '$true' 'Space = R (jump)'
    Expect-Key 'Q' 0x0020 '$true' 'Q = L'
    Expect-Click 'L' 0x2000 '$ctx -eq 1' 'left mouse button = Z (fire) in game context'
    Expect-Click 'R' 0x4000 '$ctx -eq 1' 'right mouse button = B (secondary fire)'
    $n = LogCount; Wheel -1; Check (Wait-Seen $n 0x8000 '$ctx -eq 1' 1 4) 'mouse wheel = A (next weapon) in game context'
    # mouse capture: auto mode captures while the level runs
    $captured = $null -ne (Wait-Log 'mouse captured' 5)
    Check $captured 'mouse captured while the level runs (log)'
    $clip = Clip; $cr = ClientScreenRect
    Check (($clip.L -eq $cr[0]) -and ($clip.T -eq $cr[1]) -and ($clip.R -eq $cr[2]) -and ($clip.B -eq $cr[3])) "mouse clipped to the window client area (clip $($clip.L),$($clip.T),$($clip.R),$($clip.B) client $($cr -join ','))"
    Check (-not (CursorShowing)) 'cursor hidden while captured'
    # mouse look: relative motion -> stick; the bursts are large so that a person touching the mouse meanwhile does not matter
    $n = LogCount; for ($i = 0; $i -lt 4; $i++) { MouseMove 200 0 }; Check (Wait-Seen $n 0 '$x -ge 40 -and $ctx -eq 1' 1 4) 'mouse right -> stick x >= 40'
    WaitFrames 1
    $n = LogCount; for ($i = 0; $i -lt 4; $i++) { MouseMove -200 0 }; Check (Wait-Seen $n 0 '$x -le -40 -and $ctx -eq 1' 1 4) 'mouse left -> stick x <= -40'
    WaitFrames 1
    $n = LogCount; for ($i = 0; $i -lt 4; $i++) { MouseMove 0 -200 }; Check (Wait-Seen $n 0 '$y -ge 40 -and $ctx -eq 1' 1 4) 'mouse up -> stick y >= 40 (look up)'
    WaitFrames 1
    $n = LogCount; for ($i = 0; $i -lt 4; $i++) { MouseMove 0 200 }; Check (Wait-Seen $n 0 '$y -le -40 -and $ctx -eq 1' 1 4) 'mouse down -> stick y <= -40 (look down)'
    Shot 'lvl1'
    # Esc releases the mouse, F1 captures it again
    $n = LogCount; Tap 'Esc' 0.2; Start-Sleep -Milliseconds 400
    $clip2 = Clip
    Check ((Log-Since $n 'mouse released').Count -ge 1 -and ($clip2.R - $clip2.L) -gt ($cr[2] - $cr[0]) + 10) 'Esc releases the mouse (clip rect is no longer the window)'
    Check ((CursorShowing)) 'cursor visible again'
    $n = LogCount; Tap 'F1' 0.2; Start-Sleep -Milliseconds 400
    $clip3 = Clip; Check ((($clip3.R - $clip3.L) -le ($cr[2] - $cr[0]) + 2) -and (Log-Since $n 'mouse captured').Count -ge 1) 'F1 captures the mouse again'
    Release-All
}

function FakePad($n, $buttons = 0, $lx = 0, $ly = 0, $rx = 0, $ry = 0, $lt = 0, $rt = 0) { if ($script:keepFocus) { try { NeedFocus } catch {} }; $v = ('{0:X} {1} {2} {3} {4} {5} {6}' -f $buttons, $lx, $ly, $rx, $ry, $lt, $rt); $tmp = Join-Path $root "port_fakepad$n.tmp"; for ($r = 0; $r -lt 40; $r++) { try { Set-Content -Path $tmp -Value $v -Encoding ascii -ErrorAction Stop; Move-Item $tmp (Join-Path $root "port_fakepad$n.txt") -Force -ErrorAction Stop; break } catch { Start-Sleep -Milliseconds 5 } } }
function FakePadOff($n) { Remove-Item (Join-Path $root "port_fakepad$n.txt") -ErrorAction SilentlyContinue }
function Expect-Pad($pad, $arglist, $mask, $cond, $what, $pl = 1) { $ok = $false; for ($try = 0; $try -lt 2 -and -not $ok; $try++) { $n = LogCount; FakePad $pad @arglist; $ok = Wait-Seen $n $mask $cond $pl 2.5; FakePad $pad; WaitFrames 0.5 }; Check $ok $what }

function Scenario-Pad() {
    "== pad: virtual XInput pads (TUROK_FAKEPADS=1: port_fakepadN.txt) =="
    FakePadOff 2; FakePad 1
    Start-Game @{ TUROK_FAKEPADS = '1'; TUROK_RUMBLETEST = '1' }
    $script:keepFocus = $true
    Check ($null -ne (Wait-Log 'input: XInput controller 1 connected' 15)) 'fake XInput pad 1 detected'
    Check ($null -ne (Wait-Log 'input: player 1 <- gamepad 0' 5)) 'the first pad is assigned to player 1 (pad:auto)'
    Check ($null -ne (Wait-Log 'input: rumble pak found on port 1' 15)) 'osMotorInit answered "rumble pak" for the pad'
    Check ($null -ne (Wait-Log 'input: osMotorStop called for port 1' 5)) 'the game drives the motor (osMotorStop every frame)'
    Check ((Log-Since 0 'input: fake pad 1 rumble [1-9]').Count -ge 1 -and (Log-Since 0 'input: fake pad 1 rumble 0 0').Count -ge 1) 'rumble test pulse: motor speed rises, then returns to 0 (fake XInput log)'
    # menu layer on the title screen (nothing there reacts to the D-pad / stick)
    $t0 = Get-Date; while (((Get-Date) - $t0).TotalSeconds -lt 30 -and -not (Select-String -Path $script:log -Pattern 'screen id -> 29' -Quiet -ErrorAction SilentlyContinue)) { Start-Sleep -Milliseconds 200 }
    Check (Activate) 'game window activated'; WaitFrames 2
    Expect-Pad 1 @(0, 0, -30000) 0x0400 '$ctx -eq 0' 'menus: left stick down = D-pad down'
    Expect-Pad 1 @(0, 0, 30000) 0x0800 '$ctx -eq 0' 'menus: left stick up = D-pad up'
    Expect-Pad 1 @(0, 0, 0, 30000, 0) 0 '$x -ge 60 -and $ctx -eq 0' 'menus: right stick right = N64 stick x >= 60 (dead zone rescaled)'
    Expect-Pad 1 @(0x0002) 0x0400 '$true' 'pad D-pad down = N64 D-down'
    # focus gating: a pad does nothing while the window is not in front
    $script:keepFocus = $false; [void][Inj]::SetForegroundWindow($script:origFg); Start-Sleep -Milliseconds 500
    $n = LogCount; FakePad 1 0x2000; Start-Sleep -Milliseconds 1500; FakePad 1
    Check (-not (Seen $n 0x4000)) 'pad input is ignored while the window is not in front'
    Check (Activate) 'window activated again'; $script:keepFocus = $true; WaitFrames 2
    Expect-Pad 1 @(0x2000) 0x4000 '$true' 'pad works again after the window is in front (pad B = N64 B)'
    $in = Go-ToLevel
    Check $in 'level reached (scripted menu path; the pad stays neutral)'
    if ($in) {
        Check (Activate) 'window active in the level'; WaitFrames 3
        Expect-Pad 1 @(0, 0, 30000) 0x0008 '$ctx -eq 1' 'game: left stick up = C-Up (move forward)'
        Expect-Pad 1 @(0, -30000, 0) 0x0002 '$ctx -eq 1' 'game: left stick left = C-Left (strafe)'
        Expect-Pad 1 @(0x1000) 0x0010 '$ctx -eq 1' 'game: pad A = R (jump)'
        Expect-Pad 1 @(0x4000) 0x8000 '$ctx -eq 1' 'game: pad X = A (weapon)'
        Expect-Pad 1 @(0, 0, 0, 0, 0, 0, 255) 0x2000 '$ctx -eq 1' 'game: right trigger = Z (fire)'
        Expect-Pad 1 @(0, 0, 0, 0, 0, 255, 0) 0x4000 '$ctx -eq 1' 'game: left trigger = B (secondary fire)'
        Expect-Pad 1 @(0, 0, 0, -30000, 0, 0, 0) 0 '$x -le -60 -and $ctx -eq 1' 'game: right stick left = look left (stick x <= -60)'
        Expect-Pad 1 @(0, 0, 0, 0, 30000, 0, 0) 0 '$y -ge 60 -and $ctx -eq 1' 'game: right stick up = look up'
        # hot-plug: pad 2 appears -> player 2
        $n = LogCount; FakePad 2 0x1000
        Check ($null -ne (Wait-Log 'input: XInput controller 2 connected' 6 $n)) 'hot-plug: second pad detected'
        Check ($null -ne (Wait-Log 'input: player 2 <- gamepad 1' 4 $n)) 'hot-plug: the second pad goes to player 2'
        Check (Wait-Seen $n 0x0010 '$true' 2 4) 'player 2 reads its pad (A = R in game): the port is connected'
        $n = LogCount; Tap 'F3' 0.2; Start-Sleep -Milliseconds 300
        Check ((Log-Since $n 'input: player 2: .*connected=1').Count -ge 1) 'player 2 is reported connected while its pad is plugged in'
        $n = LogCount; FakePadOff 2
        Check ($null -ne (Wait-Log 'input: XInput controller 2 disconnected' 6 $n)) 'hot-unplug detected'
        $n = LogCount; Tap 'F3' 0.2; Start-Sleep -Milliseconds 300
        Check ((Log-Since $n 'input: player 2: .*connected=0').Count -ge 1) 'player 2 is reported disconnected again'
    }
    FakePadOff 1
    Stop-Game
}

function Scenario-Split() {
    "== split: two players on one keyboard (test config via TUROK_CONTROLS) =="
    $cfg = Join-Path $root 'port\build\controls_split_test.ini'
    "[player1]`r`ndevices = keyboard`r`nprofile = kb_left`r`n[player2]`r`ndevices = keyboard`r`nprofile = kb_right`r`n" | Set-Content $cfg -Encoding ascii
    Start-Game @{ TUROK_CONTROLS = $cfg }
    Check ($null -ne (Wait-Log 'input: controls loaded' 15)) 'test config loaded'
    $t0 = Get-Date; while (((Get-Date) - $t0).TotalSeconds -lt 40 -and -not (Select-String -Path $script:log -Pattern '-> 3 ' -Quiet -ErrorAction SilentlyContinue)) { Start-Sleep -Milliseconds 300; Hold-File 'port_input.txt' 0x1000 0 0 0.4 }
    Check (Activate) 'game window activated'
    $n = LogCount; KeyDown 'LShift'; KeyDown 'Num0'
    Check ((Wait-Seen $n 0x2000 '$true' 1 4)) 'LShift = Z for player 1 (left hand layout)'
    Check ((Wait-Seen $n 0x2000 '$true' 2 4)) 'Num0 = Z for player 2 (right hand layout); port 2 is connected through the keyboard'
    KeyUp 'LShift'; KeyUp 'Num0'; WaitFrames 0.5
    $n = LogCount; KeyDown 'Q'; KeyDown 'Num6'
    Check ((Wait-Seen $n 0 '$x -eq -80' 1 4) -and (Wait-Seen $n 0 '$x -eq 80' 2 4)) 'Q turns player 1 left while Num6 turns player 2 right (at the same time)'
    KeyUp 'Q'; KeyUp 'Num6'
    Stop-Game
}


function Window-State() {
    Add-Type -AssemblyName System.Windows.Forms
    $r = New-Object Inj+RECT; [void][Inj]::GetWindowRect($script:hwnd, [ref]$r); $st = [Inj]::GetWindowLongA($script:hwnd, -16)
    $b = [Windows.Forms.Screen]::FromHandle($script:hwnd).Bounds
    $covers = ($r.L -le $b.Left + 1) -and ($r.T -le $b.Top + 1) -and ($r.R -ge $b.Right - 1) -and ($r.B -ge $b.Bottom - 1)
    return @{ Covers = $covers; Caption = (($st -band 0xC00000) -eq 0xC00000); W = $r.R - $r.L; H = $r.B - $r.T }
}
function Scenario-Fullscreen() {
    "== fullscreen: Ctrl+Enter / Alt+Enter =="
    $data = Join-Path $env:TEMP ('fs_data_' + [guid]::NewGuid().ToString('N').Substring(0, 8))
    Start-Game @{ TUROK_DATADIR = $data }
    WaitFrames 5; Start-Sleep -Seconds 2
    Check (Activate) 'game window activated'
    $s = Window-State; Check ((-not $s.Covers) -and $s.Caption) "starts windowed ($($s.W)x$($s.H), title bar)"
    $n = LogCount
    KeyDown 'LCtrl'; Start-Sleep -Milliseconds 150; KeyDown 'Enter'; Start-Sleep -Milliseconds 150; KeyUp 'Enter'; Start-Sleep -Milliseconds 100; KeyUp 'LCtrl'; Start-Sleep -Milliseconds 1200
    $s = Window-State; Check ($s.Covers -and -not $s.Caption) "Ctrl+Enter: the window covers the monitor without a title bar ($($s.W)x$($s.H))"
    Check ((Log-Since $n 'input: P1 buttons=[0-9A-F]*[1-9A-F][0-9A-F]{3} ' | Where-Object { $_ -match 'buttons=([0-9A-F]{4})' -and (([Convert]::ToInt32($Matches[1], 16)) -band 0x1000) }).Count -eq 0) 'the Enter of Ctrl+Enter is not game input (Start is not pressed)'
    Check ($script:proc.HasExited -eq $false) 'process alive in full screen'
    Check ((Get-Content (Join-Path $data 'settings.ini') -Raw -ErrorAction SilentlyContinue) -match 'fullscreen=1') 'the choice is saved (settings.ini: fullscreen=1)'
    KeyDown 'LCtrl'; Start-Sleep -Milliseconds 150; KeyDown 'Enter'; Start-Sleep -Milliseconds 150; KeyUp 'Enter'; Start-Sleep -Milliseconds 100; KeyUp 'LCtrl'; Start-Sleep -Milliseconds 1200
    $s = Window-State; Check ((-not $s.Covers) -and $s.Caption) "Ctrl+Enter again: back to the window ($($s.W)x$($s.H))"
    KeyDown 'LAlt'; Start-Sleep -Milliseconds 150; KeyDown 'Enter'; Start-Sleep -Milliseconds 150; KeyUp 'Enter'; Start-Sleep -Milliseconds 100; KeyUp 'LAlt'; Start-Sleep -Milliseconds 1200
    $s = Window-State; Check ($s.Covers -and -not $s.Caption) 'Alt+Enter also goes to full screen'
    Check ((Get-Content (Join-Path $data 'settings.ini') -Raw -ErrorAction SilentlyContinue) -match 'fullscreen=1') 'saved again'
    Check (-not [bool](Select-String -Path $script:log -Pattern 'UNIMPLEMENTED|EARLY CRASH' -Quiet -ErrorAction SilentlyContinue)) 'no crash in the log'
    Stop-Game
    # the saved choice is used by the next start; TUROK_FULLSCREEN=0 overrides it
    Start-Game @{ TUROK_DATADIR = $data }
    WaitFrames 5; Start-Sleep -Seconds 2
    $s = Window-State; Check ($s.Covers -and -not $s.Caption) 'next start: full screen again (saved choice)'
    Stop-Game
    Start-Game @{ TUROK_DATADIR = $data; TUROK_FULLSCREEN = '0' }
    WaitFrames 5; Start-Sleep -Seconds 2
    $s = Window-State; Check ((-not $s.Covers) -and $s.Caption) 'TUROK_FULLSCREEN=0 overrides the saved choice'
    Stop-Game
    Remove-Item $data -Recurse -Force -ErrorAction SilentlyContinue
}

if (-not $Lib) { if (Desktop-Locked) { "the desktop is locked (LogonUI is running): the SendInput scenarios need an unlocked interactive session, nothing was run"; exit 2 }; try {
    $list = if ($Scenario -eq 'all') { @('smoke', 'menu', 'level', 'levelkb', 'split', 'pad', 'fullscreen') } else { @($Scenario) }
    foreach ($s in $list) { switch ($s) { 'smoke' { Scenario-Smoke } 'menu' { Scenario-Menu } 'level' { Scenario-Level } 'levelkb' { Scenario-LevelKeys } 'split' { Scenario-Split } 'pad' { Scenario-Pad } 'fullscreen' { Scenario-Fullscreen } default { "unknown scenario $s" } } }
} catch { "ERROR: $($_.Exception.Message)"; $script:fail++ }
finally { try { Stop-Game } catch {}; Remove-Item port_input.txt, port_input2.txt -ErrorAction SilentlyContinue }
"INJECTION RESULT: $($script:pass) passed, $($script:fail) failed" }
