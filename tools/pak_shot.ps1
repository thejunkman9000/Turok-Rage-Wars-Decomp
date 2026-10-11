# Capture the window of ONE game process to a PNG, selected by exact process name (or id):
#   powershell -File tools\pak_shot.ps1 -ProcName pakw_221500 -Out port\build\x.png      |      -ProcId 1234
# (port\screenshot.ps1 picks the newest process called turok* - with several agents testing at once that can be somebody else's game.)
param([string]$ProcName = '', [int]$ProcId = 0, [string]$Out = 'port\build\shot.png')
Add-Type -Namespace W32 -Name Dpi -MemberDefinition '[DllImport("user32.dll")] public static extern bool SetProcessDPIAware();' -ErrorAction SilentlyContinue; [void][W32.Dpi]::SetProcessDPIAware()      # the port is DPI aware: its window rectangles are in physical pixels, so this script must be too
Add-Type -AssemblyName System.Drawing
Add-Type @"
using System; using System.Runtime.InteropServices;
public class W2 { [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr dc, uint f);
  public struct RECT { public int L, T, R, B; } }
"@
$p = $null
if ($ProcId -gt 0) { $p = Get-Process -Id $ProcId -ErrorAction SilentlyContinue }
elseif ($ProcName) { $p = Get-Process -Name $ProcName -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Sort-Object StartTime -Descending | Select-Object -First 1 }
if (-not $p -or $p.MainWindowHandle -eq 0) { 'no window'; exit 1 }
$r = New-Object W2+RECT; [W2]::GetWindowRect($p.MainWindowHandle, [ref]$r) | Out-Null
$w = $r.R - $r.L; $h = $r.B - $r.T
$bmp = New-Object System.Drawing.Bitmap $w, $h
$g = [System.Drawing.Graphics]::FromImage($bmp); $dc = $g.GetHdc()
[W2]::PrintWindow($p.MainWindowHandle, $dc, 2) | Out-Null
$g.ReleaseHdc($dc); $g.Dispose()
$full = if ([IO.Path]::IsPathRooted($Out)) { $Out } else { Join-Path (Get-Location) $Out }
$bmp.Save($full, [System.Drawing.Imaging.ImageFormat]::Png); $bmp.Dispose()
"saved $Out ${w}x$h"
