# Build the controls mapping tool (turok_controls.exe) and run the input unit tests.
#   .\port\build_config.ps1            -> port\build\turok_controls.exe, after the unit tests of the input core passed
#   .\port\build_config.ps1 -Test      -> only build + run the unit tests (port\build\input_test.exe)
#   .\port\build_config.ps1 -NoTests   -> only build the tool
# Needs the Visual Studio Build Tools (same as linkgame.ps1); 32-bit like the port; no external libraries (system DLLs only).
param([switch]$Test, [switch]$NoTests)
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
$obj = 'port\build\cfg_obj'
New-Item -ItemType Directory -Force port\build, $obj | Out-Null
function Show-Errors($out) { $out | Where-Object { $_ -match 'error|warning C4(013|047|133|700|701|703|715)|LNK' } | ForEach-Object { $_ } }

# 1. unit tests of the platform independent core: names, config parser / writer, defaults, mapping engine with fake device states
if (-not $NoTests) {
    Remove-Item port\build\input_test.exe -ErrorAction SilentlyContinue      # never run a stale test exe
    $o = cl /nologo /O2 /W3 /TC /DINPUT_TEST_MAIN "/Fo$obj\\" /Fe:port\build\input_test.exe port\config\input_test.c port\input_core.c port\input_dev.c /link user32.lib 2>&1
    Show-Errors $o
    if (-not (Test-Path port\build\input_test.exe)) { 'input_test.exe was not built'; exit 1 }
    & port\build\input_test.exe
    if ($LASTEXITCODE -ne 0) { "UNIT TESTS FAILED ($LASTEXITCODE)"; exit 1 }
    if ($Test) { 'UNIT TESTS PASSED'; exit 0 }
}

# 2. the tool: port\config\*.cpp (Win32 + common controls + GDI) + the shared core and device layer
$srcs = @(Get-ChildItem port\config\*.cpp | ForEach-Object { $_.FullName })
if ($srcs.Count -eq 0) { 'no tool sources yet'; exit 0 }
$out = 'port\build\turok_controls.exe'
Remove-Item $out -ErrorAction SilentlyContinue      # never report a stale exe as built
$o = cl /nologo /O2 /MT /W3 /EHsc /DUNICODE /D_UNICODE /DINPUT_TOOL "/Fo$obj\\" /Fe:$out $srcs /Tc port\input_core.c /Tc port\input_dev.c /Tc port\config\input_test.c /link /SUBSYSTEM:WINDOWS 2>&1      # static CRT: nothing but system DLLs at run time
Show-Errors $o
if (Test-Path $out) { "built $out" } else { 'turok_controls.exe was not built'; exit 1 }
