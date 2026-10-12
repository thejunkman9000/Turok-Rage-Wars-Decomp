@echo off
rem Builds the Turok: Rage Wars PC port: double-click this file.  It checks the tools (and offers to install them), asks for your ROM,
rem and builds the game.  The log is build.log.  Options: build.cmd -Rebuild  (from scratch)
cd /d "%~dp0"
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0port\setup_build.ps1" %*
