# Build the port (port\linkgame.ps1) and give the exe a name the other agents' test scripts cannot match:  port\build\pakw_<HHMMSS>.exe
# (lvltest.ps1, soak.ps1, menutour.ps1, demotest.ps1 ... kill every process called turok_* - that would also kill games of other people on this machine.)
# usage: powershell -NoProfile -File tools\linkpak.ps1
Set-Location (Split-Path $PSScriptRoot -Parent)
& powershell -NoProfile -File port\linkgame.ps1
$orig = (Get-Content port\build\latest_exe.txt).Trim()
if ($orig -like '*turok_*') {
    $new = 'port\build\pakw_' + (Get-Date -Format 'HHmmss') + '.exe'
    Copy-Item $orig $new -Force
    Remove-Item $orig -Force -ErrorAction SilentlyContinue
    $new | Out-File port\build\latest_exe.txt -Encoding ascii
    "exe: $new"
} else { "exe: $orig" }
