# Quick rebuild after editing glue/shim files:  .\port\rebuild.ps1   (re-links with the generated symbol/stub files)
Set-Location (Split-Path $PSScriptRoot -Parent)
powershell -NoProfile -File port\linkgame.ps1
