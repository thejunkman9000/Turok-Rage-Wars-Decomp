# Full relink cycle: link without generated stubs to learn what is missing, regenerate port\gen\*, link for real.
Set-Location (Split-Path $PSScriptRoot -Parent)
powershell -NoProfile -File port\linkgame.ps1 -Fresh | Out-Null
python port\gen_syms.py port\build\link.log | Select-Object -First 1
powershell -NoProfile -File port\linkgame.ps1
Select-String -Path port\build\link.log -Pattern 'LNK2|LNK1|fatal' | Select-Object -First 5 | ForEach-Object { $_.Line }
