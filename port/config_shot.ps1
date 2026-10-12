# Screenshot of the mapping tool.  The tool renders its own window with WM_PRINT into a BMP (--shot), so the picture does not depend on the desktop (other windows
# in front, DPI, a window partly off screen).  This script launches it with the given arguments, waits for it to write the picture and converts it to PNG.
#   .\port\config_shot.ps1 -Out port\build\cfg_p1.png -ToolArgs '--player','1','--config','port\build\test.ini'
param([string]$Out = 'port\build\cfg_shot.png', [string[]]$ToolArgs = @(), [int]$DelayMs = 1200, [string]$Exe = 'port\build\turok_controls.exe')
Set-Location (Split-Path $PSScriptRoot -Parent)
Add-Type -AssemblyName System.Drawing
$bmp = [IO.Path]::ChangeExtension((Join-Path (Get-Location) $Out), '.bmp')
Remove-Item $bmp -ErrorAction SilentlyContinue
$env:TUROK_SCRIPT = '1'; $p = Start-Process (Join-Path (Get-Location) $Exe) -ArgumentList ($ToolArgs + @('--shot', $bmp, '--shot-delay', [string]$DelayMs)) -PassThru
if (-not $p.WaitForExit(30000)) { try { $p.Kill() } catch {}; 'the tool did not finish'; exit 1 }
if (-not (Test-Path $bmp)) { 'no picture written'; exit 1 }
$img = [System.Drawing.Image]::FromFile($bmp); $png = Join-Path (Get-Location) $Out; $img.Save($png, [System.Drawing.Imaging.ImageFormat]::Png); $w = $img.Width; $h = $img.Height; $img.Dispose(); Remove-Item $bmp
"saved $Out ${w}x$h"
