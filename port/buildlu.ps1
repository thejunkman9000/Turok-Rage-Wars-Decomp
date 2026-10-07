# Compile the portable parts of the libultra/libaudio/libm sources (src\libultra\*.c) for the port into port\build\obj_lu.
# Hardware-facing os* functions are provided by port\os_shim.c instead (it is linked first, duplicates are ignored).
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
$obj = 'port\build\obj_lu'; Remove-Item -Recurse -Force $obj -ErrorAction SilentlyContinue; New-Item -ItemType Directory -Force $obj | Out-Null
$ok = 0; $bad = @()
foreach ($f in Get-ChildItem src\libultra\*.c) {
    if ($f.BaseName -match '^(__os|os[A-Z]|dbg|__osDev)') { continue }       # hardware layer: replaced by os_shim.c
    $o = cl /nologo /O1 /w /TC /Iinclude /D_LANGUAGE_C /DTARGET_PC "/FI$((Get-Location).Path)\port\compat.h" /c "/Fo$obj\$($f.BaseName).obj" $f.FullName 2>&1
    if ($LASTEXITCODE -eq 0) { $ok++ } else { $bad += $f.BaseName; Remove-Item "$obj\$($f.BaseName).obj" -ErrorAction SilentlyContinue }
}
"libultra objects: $ok ok, $($bad.Count) failed: $($bad -join ' ')"
