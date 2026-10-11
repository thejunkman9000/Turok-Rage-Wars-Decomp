# Load every arena through the scripted trial flow (TUROK_ARENA=<n> pins the arena, see port\overrides\func_0042EB80.c) and capture the level start of each:
#   .\port\arenatour.ps1 [-From 0] [-To 35] [-Range 380-700] [-Step 8]
# per arena: port\build\arena_<n>_00.png (contact sheet of the captured frames), port\build\arena_<n>.log (game log) and one line in port\build\arenatour.txt
# (fresh = the log was rewritten, crash = CRASH lines, hud = frames with the HUD, fog = draws whose blender uses the fog colour, tex = distinct textures decoded)
param([int]$From = 0, [int]$To = 35, [string]$Range = '380-700', [int]$Step = 8, [int]$Tail = 30)
Set-Location (Split-Path $PSScriptRoot -Parent)
for ($n = $From; $n -le $To; $n++) {
    $t0 = Get-Date
    & .\port\flyshots.ps1 -Range $Range -Step $Step -Div 4 -Speed 10 -Tail $Tail -Extra "TUROK_ARENA=$n" | Out-Null
    $log = 'port\build\run_fly.log'
    $fresh = (Test-Path $log) -and ((Get-Item $log).LastWriteTime -gt $t0)
    $txt = if ($fresh) { Get-Content $log -Raw } else { '' }
    $arena = if ($txt -match 'arena: (\d+) pinned by TUROK_ARENA \(game chose (\d+)\), type (\d+)') { "pinned $($Matches[1]) (game chose $($Matches[2]))" } else { 'no arena line' }
    $crash = ([regex]::Matches($txt, 'CRASH')).Count
    $soft = ([regex]::Matches($txt, 'SOFTFAULT')).Count
    $fog = if ($txt -match '(?s).*fog alpha \(since start\): (\d+)') { $Matches[1] } else { '?' }
    $shots = @(Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue)
    $sheet = ''
    if ($shots.Count) { python tools\sheet.py 'port\build\fs_*.bmp' --cols 8 --per 48 --scale 0.25 --out ("port/build/arena_{0}" -f $n) | Out-Null; $sheet = "arena_${n}_00.png" }
    if ($fresh) { Copy-Item $log ("port\build\arena_{0}.log" -f $n) -Force }
    $hud = 0; if ($shots.Count) { $hud = (python tools\flysel.py 2>$null | Select-String ' hud$').Count }
    $line = "arena {0}: fresh={1} {2} frames={3} hud={4} crash={5} softfault={6} fogdraws={7} {8}" -f $n, $fresh, $arena, $shots.Count, $hud, $crash, $soft, $fog, $sheet
    $line; Add-Content port\build\arenatour.txt $line
    Get-ChildItem port\build\fs_*.bmp -ErrorAction SilentlyContinue | ForEach-Object { $_.Delete() }
}
