# fog A/B: the same scene with fog on (even renderer frames) and off (odd ones), one pair per arena: .\port\fogab.ps1 -Arenas 7,9,10,22,28  -> port\build\fogab_<arena>_on.bmp / _off.bmp (+ a side-by-side sheet fogab_<arena>_00.png)
param([int[]]$Arenas = @(7, 9, 10, 22, 28), [string]$Range = '562-563', [int]$Div = 2)
Set-Location (Split-Path $PSScriptRoot -Parent)
foreach ($a in $Arenas) {
    & .\port\flyshots.ps1 -Range $Range -Step 1 -Div $Div -Speed 10 -Tail 20 -Extra "TUROK_ARENA=$a,TUROK_FOGAB=1" | Out-Null
    $f = @(Get-ChildItem port\build\fs_*.bmp | Sort-Object Name)
    if ($f.Count -ge 2) {
        Copy-Item $f[0].FullName "port\build\fogab_${a}_on.bmp" -Force; Copy-Item $f[1].FullName "port\build\fogab_${a}_off.bmp" -Force
        python tools\sheet.py "port\build\fogab_${a}_on.bmp" "port\build\fogab_${a}_off.bmp" --cols 2 --per 2 --scale 0.9 --out ("port/build/fogab_{0}" -f $a) | Out-Null
        "arena ${a}: pair captured ($($f[0].Name) on, $($f[1].Name) off)"
    } else { "arena ${a}: only $($f.Count) frames" }
}
