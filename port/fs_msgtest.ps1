# Full screen toggle without keyboard injection (works on a locked desktop): the port window gets the same messages the keys produce.
#   .\port\fs_msgtest.ps1
# Checks: WM_APP+0x46 and Alt+Enter (WM_SYSKEYDOWN with the Alt context bit) toggle the borderless full screen, the window covers the monitor without a title bar and
# goes back to its old size, the choice is saved in <data folder>\settings.ini and used by the next start, TUROK_FULLSCREEN / -windowed override it.
# The real Ctrl+Enter path (GetKeyState) is covered by  .\port\input_inject.ps1 -Scenario fullscreen  (needs an unlocked desktop).
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
Add-Type -Namespace W32 -Name Dpi -MemberDefinition '[DllImport("user32.dll")] public static extern bool SetProcessDPIAware();' -ErrorAction SilentlyContinue; [void][W32.Dpi]::SetProcessDPIAware()      # the port is DPI aware: its window rectangles are in physical pixels, so this script must be too
Add-Type -AssemblyName System.Windows.Forms
Add-Type -Namespace W -Name F -MemberDefinition '[StructLayout(LayoutKind.Sequential)] public struct RECT { public int L, T, R, B; } [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r); [DllImport("user32.dll")] public static extern int GetWindowLongA(IntPtr h, int i); [DllImport("user32.dll")] public static extern bool PostMessageA(IntPtr h, uint m, IntPtr w, IntPtr l);'
$exe = Join-Path $root (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$data = Join-Path $env:TEMP ('fsmsg_' + [guid]::NewGuid().ToString('N').Substring(0, 8)); $fail = 0
function Check($ok, $what) { if ($ok) { "  ok   $what" } else { "  FAIL $what"; $script:fail++ } }
function Start-Port($env_, $args_ = '') {
    $env:TUROK_DATADIR = $data; $env:TUROK_PAK = '0'; Remove-Item Env:\TUROK_FULLSCREEN -ErrorAction SilentlyContinue
    foreach ($k in $env_.Keys) { Set-Item "env:$k" $env_[$k] }
    if ($args_) { $env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory $root -ArgumentList $args_ } else { $null = Start-Process $exe -WorkingDirectory $root }
    foreach ($k in $env_.Keys) { Remove-Item "env:$k" -ErrorAction SilentlyContinue }
    $t = Get-Date; $script:p = $null
    while (((Get-Date) - $t).TotalSeconds -lt 30 -and -not $script:p) { Start-Sleep -Milliseconds 200; $script:p = Get-Process -Name $name -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Select-Object -First 1 }
    Start-Sleep -Seconds 2
    if ($script:p) { $script:p.Refresh(); $script:h = $script:p.MainWindowHandle }
}
function Stop-Port { Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill(); $_.WaitForExit(3000) | Out-Null } catch {} }; Start-Sleep -Milliseconds 400 }
function State {
    $r = New-Object W.F+RECT; [void][W.F]::GetWindowRect($script:h, [ref]$r); $st = [W.F]::GetWindowLongA($script:h, -16)
    $b = [Windows.Forms.Screen]::FromHandle($script:h).Bounds
    return @{ Covers = (($r.L -le $b.Left + 1) -and ($r.T -le $b.Top + 1) -and ($r.R -ge $b.Right - 1) -and ($r.B -ge $b.Bottom - 1)); Caption = (($st -band 0xC00000) -eq 0xC00000); W = $r.R - $r.L; H = $r.B - $r.T }
}
function Settle { Start-Sleep -Milliseconds 1500 }
try {
    "== toggling with messages"
    Start-Port @{}
    Check ($script:p -ne $null) 'game window appears'
    $s = State; Check ((-not $s.Covers) -and $s.Caption) "starts windowed ($($s.W)x$($s.H) with title bar)"; $w0 = $s.W; $h0 = $s.H
    [void][W.F]::PostMessageA($script:h, 0x8000 + 0x46, [IntPtr]::Zero, [IntPtr]::Zero); Settle
    $s = State; Check ($s.Covers -and -not $s.Caption) "toggle message: covers the monitor without a title bar ($($s.W)x$($s.H))"
    Check ((Get-Content (Join-Path $data 'settings.ini') -Raw -ErrorAction SilentlyContinue) -match 'fullscreen=1') 'saved: fullscreen=1'
    [void][W.F]::PostMessageA($script:h, 0x8000 + 0x46, [IntPtr]::Zero, [IntPtr]::Zero); Settle
    $s = State; Check ((-not $s.Covers) -and $s.Caption -and $s.W -eq $w0 -and $s.H -eq $h0) "toggle again: back to the old window ($($s.W)x$($s.H))"
    Check ((Get-Content (Join-Path $data 'settings.ini') -Raw -ErrorAction SilentlyContinue) -match 'fullscreen=0') 'saved: fullscreen=0'
    [void][W.F]::PostMessageA($script:h, 0x0104, [IntPtr]0x0D, [IntPtr]0x201C0001); Settle      # WM_SYSKEYDOWN, VK_RETURN, scancode 1C, Alt context bit (29)
    $s = State; Check ($s.Covers -and -not $s.Caption) 'Alt+Enter message: full screen'
    [void][W.F]::PostMessageA($script:h, 0x0104, [IntPtr]0x0D, [IntPtr]0x601C0001); Settle      # same key again, previous-state bit set (auto repeat): ignored
    $s = State; Check ($s.Covers -and -not $s.Caption) 'a repeated Alt+Enter (key held down) does not toggle again'
    Check ($script:p.HasExited -eq $false) 'process alive'
    Stop-Port
    "== next start"
    Start-Port @{}
    $s = State; Check ($s.Covers -and -not $s.Caption) 'the saved full screen choice is used'
    Stop-Port
    Start-Port @{ TUROK_FULLSCREEN = '0' }
    $s = State; Check ((-not $s.Covers) -and $s.Caption) 'TUROK_FULLSCREEN=0 overrides it'
    Stop-Port
    Start-Port @{} '-windowed'
    $s = State; Check ((-not $s.Covers) -and $s.Caption) '-windowed overrides it'
    Stop-Port
    Remove-Item (Join-Path $data 'settings.ini') -ErrorAction SilentlyContinue
    Start-Port @{} '-fullscreen'
    $s = State; Check ($s.Covers -and -not $s.Caption) '-fullscreen starts in full screen'
    $log = Join-Path $root 'port_log.txt'
} finally { Stop-Port; Remove-Item $data -Recurse -Force -ErrorAction SilentlyContinue }
if ($fail) { "FULL SCREEN TEST: $fail check(s) FAILED"; exit 1 } else { 'FULL SCREEN TEST: all checks passed' }
