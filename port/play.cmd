@echo off
rem Starts the newest build of the PC port (port\build\latest_exe.txt names it; run port\linkgame.ps1 to build one).
rem The game finds the ROM in this folder (baserom.us.v11.z64); without one it asks for it and keeps a copy in %LOCALAPPDATA%\TurokRageWars.
rem Ctrl+Enter (or Alt+Enter) toggles full screen; add -fullscreen / -windowed to force one.
cd /d "%~dp0.."
if not exist "port\build\latest_exe.txt" ( echo No build yet: run  powershell -File port\linkgame.ps1  first. & pause & exit /b 1 )
for /f "usebackq delims=" %%e in ("port\build\latest_exe.txt") do start "" "%%e" %*
