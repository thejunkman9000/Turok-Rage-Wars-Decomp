# One-step build of the PC port for people who just want to play.  Started by build.cmd in the project folder (double-click it).
# Checks / installs the tools (asks first), prepares Python, asks for your ROM, then builds the game and the controls program.
# Re-running it is safe: finished steps are skipped and only what changed is rebuilt.
# Options: -Rebuild (rebuild everything from scratch)  -Yes (answer every question with yes)  -Rom <file> (use this ROM, no dialog)
param([switch]$Rebuild, [switch]$Yes, [string]$Rom)
$ErrorActionPreference = 'Continue'      # native tools report through exit codes (checked below)
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
$log = Join-Path $root 'build.log'
try { Start-Transcript -Path $log -Force | Out-Null } catch {}

$ROM_SHA1 = '037fb397cee2669048ed6b762a64698de4a4d88a'      # Turok: Rage Wars (USA) v1.1, .z64 byte order
$PIP_PACKAGES = @('splat64[mips]==0.50.0', 'spimdisasm==1.42.4', 'rabbitizer==1.16.2', 'crunch64==0.6.2', 'PyYAML==6.0.3', 'ziglang==0.16.0')

function Say($msg, $color = 'Gray') { Write-Host $msg -ForegroundColor $color }
function Step($n, $msg) { Write-Host ''; Write-Host "[$n] $msg" -ForegroundColor Cyan }
function Fail($msg) {
    Write-Host ''; Write-Host "BUILD STOPPED: $msg" -ForegroundColor Red
    Write-Host "Details are in $log" -ForegroundColor Red
    try { Stop-Transcript | Out-Null } catch {}
    if (-not $Yes) { Read-Host 'Press Enter to close' | Out-Null }
    exit 1
}
function Ask($q) {
    if ($Yes) { return $true }
    $a = Read-Host "$q [Y/n]"
    return ($a -eq '' -or $a -match '^[yY]')
}
function Have($cmd) { return [bool](Get-Command $cmd -ErrorAction SilentlyContinue) }
function Run($exe, [string[]]$argList, $what) {
    & $exe @argList
    if ($LASTEXITCODE -ne 0) { Fail "$what failed (exit code $LASTEXITCODE)." }
}

Say '================================================================' 'White'
Say ' Turok: Rage Wars - PC port build' 'White'
Say ' The first build takes 20-40 minutes; later builds are quicker.' 'White'
Say '================================================================' 'White'

# ---------------------------------------------------------------- 1. Python
Step 1 'Python 3'
$pyExe = $null; $pyArgs = @()
function Try-Py($exe, $pre) {
    if (-not (Have $exe)) { return $false }
    $v = & $exe @pre -c 'import sys; print("%d.%d" % sys.version_info[:2])' 2>$null
    return ($LASTEXITCODE -eq 0 -and $v -and [version]"$v" -ge [version]'3.9')
}
if (Try-Py 'py' @('-3')) { $pyExe = 'py'; $pyArgs = @('-3') } elseif (Try-Py 'python' @()) { $pyExe = 'python'; $pyArgs = @() }
if (-not $pyExe) {
    Say 'Python 3.9 or newer was not found.' 'Yellow'
    if ((Have 'winget') -and (Ask 'Install Python 3.12 now with winget?')) {
        Run 'winget' @('install', '-e', '--id', 'Python.Python.3.12', '--accept-package-agreements', '--accept-source-agreements') 'Installing Python'
        Say 'Python is installed.  Close this window and double-click build.cmd again (Windows needs a new window to find it).' 'Green'
        if (-not $Yes) { Read-Host 'Press Enter to close' | Out-Null }
        exit 0
    }
    Fail 'Python 3 is needed: install it from https://www.python.org/downloads/ (tick "Add python.exe to PATH"), then run build.cmd again.'
}
Say ("found: " + (@($pyExe) + $pyArgs -join ' '))

# ---------------------------------------------------------------- 2. Visual Studio C++ build tools
Step 2 'Visual Studio C++ build tools'
function Find-VC {
    if ($env:TUROK_VCVARS -and (Test-Path $env:TUROK_VCVARS)) { return $env:TUROK_VCVARS }
    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (Test-Path $vswhere) {
        $inst = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath 2>$null | Select-Object -First 1
        if ($inst -and (Test-Path (Join-Path $inst 'VC\Auxiliary\Build\vcvars32.bat'))) { return (Join-Path $inst 'VC\Auxiliary\Build\vcvars32.bat') }
    }
    return $null
}
$vc = Find-VC
if (-not $vc) {
    Say 'The Visual Studio C++ build tools were not found.' 'Yellow'
    if ((Have 'winget') -and (Ask 'Install "Build Tools for Visual Studio 2022" (C++ workload, about 6 GB) now with winget?')) {
        Run 'winget' @('install', '-e', '--id', 'Microsoft.VisualStudio.2022.BuildTools', '--accept-package-agreements', '--accept-source-agreements',
                       '--override', '--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended') 'Installing the build tools'
        $vc = Find-VC
    }
    if (-not $vc) { Fail 'Install "Build Tools for Visual Studio" with the "Desktop development with C++" workload (https://visualstudio.microsoft.com/downloads/), then run build.cmd again.' }
}
Say "found: $vc"

# ---------------------------------------------------------------- 3. Python packages (project venv)
Step 3 'Python packages (in .venv, nothing is installed system-wide)'
$venvPy = Join-Path $root '.venv\Scripts\python.exe'
if (-not (Test-Path $venvPy)) {
    Say 'creating .venv ...'
    Run $pyExe ($pyArgs + @('-m', 'venv', '.venv')) 'Creating the Python environment'
}
$have = & $venvPy -m pip list --format=freeze --disable-pip-version-check 2>$null
$missing = $PIP_PACKAGES | Where-Object { $spec = $_ -replace '\[.*\]', ''; -not ($have -contains $spec) }
if ($missing) {
    Say ('installing: ' + ($missing -join ', '))
    Run $venvPy (@('-m', 'pip', 'install', '--disable-pip-version-check') + $PIP_PACKAGES) 'Installing the Python packages'
} else { Say 'up to date' }
$env:PATH = (Join-Path $root '.venv\Scripts') + ';' + $env:PATH          # "python" in the build scripts = the venv's python (with ziglang)

# ---------------------------------------------------------------- 4. ROM
Step 4 'Your ROM (Turok: Rage Wars, USA, version 1.1)'
function Sha1Of($path) { return (Get-FileHash -Algorithm SHA1 -Path $path).Hash.ToLower() }
$target = Join-Path $root 'baserom.us.v11.z64'
if ((Test-Path $target) -and (Sha1Of $target) -eq $ROM_SHA1) { Say 'baserom.us.v11.z64 is there and correct' }
else {
    if (-not $Rom) {
        Say 'Pick your ROM file in the dialog (.z64, .n64 or .v64).'
        Add-Type -AssemblyName System.Windows.Forms
        $dlg = New-Object System.Windows.Forms.OpenFileDialog
        $dlg.Title = 'Turok: Rage Wars (USA, v1.1) ROM'; $dlg.Filter = 'N64 ROM (*.z64;*.n64;*.v64)|*.z64;*.n64;*.v64|All files (*.*)|*.*'
        if ($dlg.ShowDialog() -ne 'OK') { Fail 'No ROM was chosen.' }
        $Rom = $dlg.FileName
    }
    if (-not (Test-Path $Rom)) { Fail "ROM not found: $Rom" }
    $b = [IO.File]::ReadAllBytes($Rom)
    if ($b.Length -lt 4) { Fail 'That file is not an N64 ROM.' }
    if ($b[0] -eq 0x37 -and $b[1] -eq 0x80) { for ($i = 0; $i -lt $b.Length - 1; $i += 2) { $t = $b[$i]; $b[$i] = $b[$i + 1]; $b[$i + 1] = $t } }          # .v64 (byte-swapped)
    elseif ($b[0] -eq 0x40 -and $b[1] -eq 0x12) { for ($i = 0; $i -lt $b.Length - 3; $i += 4) { [Array]::Reverse($b, $i, 4) } }                           # .n64 (little-endian)
    $sha = ([BitConverter]::ToString((New-Object Security.Cryptography.SHA1Managed).ComputeHash($b)) -replace '-', '').ToLower()
    if ($sha -ne $ROM_SHA1) { Fail "This ROM is not Turok: Rage Wars (USA) version 1.1 (SHA-1 $sha).  Other releases are not supported by the PC port yet." }
    [IO.File]::WriteAllBytes($target, $b)
    Say 'ROM checked and copied to baserom.us.v11.z64' 'Green'
}

# ---------------------------------------------------------------- 5. Disassembly (splat)
Step 5 'Disassembly of the ROM (splat)'
if ($Rebuild -or -not (Test-Path (Join-Path $root 'asm\header.s'))) {
    Run $venvPy @('-m', 'splat', 'split', 'turok_ragewars.yaml') 'splat'
    Run $venvPy @('tools\fix_asm.py') 'fix_asm'
} else { Say 'already done' }

# ---------------------------------------------------------------- 6. The game
Step 6 'Building the game (the first time this takes a while)'
$first = $Rebuild -or -not (Test-Path (Join-Path $root 'port\build\asm_func'))
$regenArgs = @('port\regen.py') + $(if ($first) { @('--asm', '--all') } else { @() })
Run $venvPy $regenArgs 'Building the game'
$latest = Join-Path $root 'port\build\latest_exe.txt'
if (-not (Test-Path $latest)) { Fail 'The game was not linked (port\build\latest_exe.txt is missing).' }
$exe = (Get-Content $latest | Select-Object -First 1).Trim()
if (-not (Test-Path (Join-Path $root $exe))) { Fail "The game was not linked ($exe is missing)." }
Say "game: $exe" 'Green'

# ---------------------------------------------------------------- 7. Controls program
Step 7 'Controls program (turok_controls.exe)'
& powershell -NoProfile -ExecutionPolicy Bypass -File port\build_config.ps1
if ($LASTEXITCODE -ne 0) { Say 'The controls program did not build (the game still works; controls.ini can be edited by hand).' 'Yellow' }

# ---------------------------------------------------------------- done
Write-Host ''
Say '================================================================' 'Green'
Say ' Done!  Double-click port\play.cmd to play.' 'Green'
Say '================================================================' 'Green'
$lnk = Join-Path ([Environment]::GetFolderPath('Desktop')) 'Turok Rage Wars.lnk'
if (-not (Test-Path $lnk) -and -not $Yes -and (Ask 'Put a "Turok Rage Wars" shortcut on the desktop?')) {
    $ws = New-Object -ComObject WScript.Shell; $s = $ws.CreateShortcut($lnk)
    $s.TargetPath = Join-Path $root 'port\play.cmd'; $s.WorkingDirectory = $root; $s.Save()
    Say 'shortcut created' 'Green'
}
try { Stop-Transcript | Out-Null } catch {}
if (-not $Yes) { Read-Host 'Press Enter to close' | Out-Null }
