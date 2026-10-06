# Regenerate src/*.s hand-written asm sources from the ROM.
# usage: .\tools\regen_hasm.ps1 <spec-file> [-Subdir libultra]
# Temporarily drops the spec's functions from funcs.txt, re-splits the ROM so asm/ contains their code,
# runs tools/mkhasm.py for the spec, appends the funcs.txt lines again and restores a consistent state
# (then run tools\cycle.ps1 to verify the build is still byte-identical).
param([string]$Spec, [string]$Subdir = 'libultra')
Set-Location D:\Projects\TurokRageWars
$names = Get-Content $Spec | ForEach-Object { ($_ -split '#')[0].Trim() } | Where-Object { $_ } | ForEach-Object { ($_ -split '\s+')[0] }
$keep = Get-Content funcs.txt | Where-Object {
    $l = ($_ -split '#')[0].Trim()
    if (-not $l) { return $true }
    $n = ($l -split '\s+')[0]
    return -not ($names -contains $n)
}
Set-Content -Path funcs.txt -Value $keep -Encoding ascii
.\.venv\Scripts\python.exe tools\gen_yaml.py | Out-Null
foreach ($n in $names) { Remove-Item "src\$Subdir\$n.c" -ErrorAction SilentlyContinue }
Remove-Item -Recurse -Force asm -ErrorAction SilentlyContinue
.\.venv\Scripts\python.exe -m splat split turok_ragewars.yaml 2>&1 | Select-String -Pattern 'Traceback' | ForEach-Object { $_.Line }
.\.venv\Scripts\python.exe tools\fix_asm.py | Select-Object -Last 1
$out = .\.venv\Scripts\python.exe tools\mkhasm.py $Spec --subdir $Subdir
$out | Where-Object { $_ -notmatch 'funcs.txt:' }
$out | Where-Object { $_ -match 'funcs.txt:' } | ForEach-Object { ($_ -replace '.*funcs.txt:\s+', '') } | Add-Content -Path funcs.txt -Encoding ascii
