# Build and run the host-side self test of the virtual Controller Pak (no game, no ROM needed).  usage: .\port\tests\pak_selftest.ps1
Set-Location (Split-Path (Split-Path $PSScriptRoot -Parent) -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' | ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
New-Item -ItemType Directory -Force port\build | Out-Null
$exe = 'port\build\pak_selftest.exe'
cl /nologo /O1 /w /TC /Iport /Iinclude /D_LANGUAGE_C "/Fo:port\build\pak_selftest.obj" "/Fe:$exe" port\tests\pak_selftest.c /link /LARGEADDRESSAWARE user32.lib kernel32.lib 2>&1 | Where-Object { $_ -match 'error|warning C4013' }
if (-not (Test-Path $exe)) { 'build failed'; exit 2 }
& $exe
exit $LASTEXITCODE
