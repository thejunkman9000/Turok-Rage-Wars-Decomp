param([switch]$Fresh)
# Link the port: window + glue + all game objects (port\build\obj_c, built by port\build_clang.py) + generated symbol/stub files.
# usage: .\port\linkgame.ps1 [-Fresh]
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = 'port\build\turok_' + (Get-Date -Format 'HHmmss') + '.exe'   # a crashed old instance can keep turok.exe locked
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
cl /nologo /EHsc /O2 /w /c /Foport\build\win32_main.obj port\win32_main.cpp | Where-Object { $_ -match 'error' }
cl /nologo /EHsc /O2 /w /c /Foport\build\renderer.obj port\renderer.cpp | Where-Object { $_ -match 'error' }
$portobjs = @('port\build\renderer.obj')
foreach ($f in Get-ChildItem port\*.c) {
    $o = "port\build\$($f.BaseName).obj"
    cl /nologo /O2 /w /TC /Iinclude /D_LANGUAGE_C /DTARGET_PC "/FI$((Get-Location).Path)\port\compat.h" /c "/Fo$o" $f.FullName 2>&1 | Where-Object { $_ -match 'error' }
    $portobjs += $o
}
$extra = @()
ml /nologo /c /coff /Foport\build\mathshim.obj port\mathshim.asm | Out-Null; $extra += 'port\build\mathshim.obj'
if (Test-Path port\gen\fnptrs.c) { cl /nologo /O1 /w /TC /c /Foport\build\fnptrs.obj port\gen\fnptrs.c | Out-Null; $extra += 'port\build\fnptrs.obj' }
if (-not $Fresh -and (Test-Path port\gen\syms.asm)) { ml /nologo /c /coff /Foport\build\syms.obj port\gen\syms.asm | Out-Null; $extra += 'port\build\syms.obj' }
if (-not $Fresh -and (Test-Path port\gen\stubs.c)) { cl /nologo /O1 /w /TC /c /Foport\build\stubs.obj port\gen\stubs.c | Out-Null; $extra += 'port\build\stubs.obj' }
$objs = @(Get-ChildItem port\build\obj_c\*.obj) | ForEach-Object { $_.FullName }
$rsp = 'port\build\link.rsp'; ($objs + $extra) | Out-File $rsp -Encoding ascii
link /nologo /SUBSYSTEM:WINDOWS /LARGEADDRESSAWARE /BASE:0x20000000 /FIXED:NO /ENTRY:port_entry /FORCE:MULTIPLE /MAP:port\build\turok.map "/OUT:$exe" port\build\win32_main.obj $portobjs "@$rsp" user32.lib kernel32.lib winmm.lib d3d11.lib d3dcompiler.lib 2>&1 | Out-File port\build\link.log -Encoding ascii
$n = (Select-String -Path port\build\link.log -Pattern 'LNK2001|LNK2019').Count
"unresolved reports: $n"
if (Test-Path $exe) { $exe | Out-File port\build\latest_exe.txt -Encoding ascii }
