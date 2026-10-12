# Loads the 32-bit MSVC environment (cl, link) into the calling PowerShell session.  Dot-source it:  . "$PSScriptRoot\vcvars.ps1"
# Finds any Visual Studio 2022 / 2026 (Build Tools, Community, Professional, Enterprise) that has the C++ tools, through vswhere;
# TUROK_VCVARS=<path to vcvars32.bat> overrides the search.
$vcvars = $env:TUROK_VCVARS
if (-not $vcvars) {
    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (Test-Path $vswhere) {
        $inst = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath 2>$null | Select-Object -First 1
        if ($inst) { $vcvars = Join-Path $inst 'VC\Auxiliary\Build\vcvars32.bat' }
    }
}
if (-not $vcvars -or -not (Test-Path $vcvars)) { $vcvars = 'C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat' }
if (-not (Test-Path $vcvars)) {
    Write-Host 'Visual Studio C++ build tools not found (vcvars32.bat).  Install "Build Tools for Visual Studio" with the "Desktop development with C++" workload, or set TUROK_VCVARS.' -ForegroundColor Red
    exit 1
}
cmd /c ('"' + $vcvars + '" >nul 2>&1 && set') |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
