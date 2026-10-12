param([switch]$Fresh)
# Link the port: window + glue + all game objects (port\build\obj_c, built by port\build_clang.py) + generated symbol/stub files.
# usage: .\port\linkgame.ps1 [-Fresh]
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
$exe = 'port\build\turok_' + (Get-Date -Format 'HHmmss') + '.exe'   # a crashed old instance can keep turok.exe locked
. "$PSScriptRoot\vcvars.ps1"      # MSVC 32-bit environment (any VS 2022 / 2026 with the C++ tools; TUROK_VCVARS overrides)
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
$objdir = if ($env:PORT_OBJ) { $env:PORT_OBJ } else { 'obj_c' }      # PORT_OBJ=obj_ssp: the diagnostic object set built by port\build_clang.py (PORT_OBJ / PORT_LL, PORT_SSP=1)
$objs = @(Get-ChildItem "port\build\$objdir\*.obj") | ForEach-Object { $_.FullName }
$rsp = 'port\build\link.rsp'; $opts = @(); if (-not $Fresh -and (Test-Path port\gen\alias.rsp)) { $opts = @(Get-Content port\gen\alias.rsp) }      # /ALTERNATENAME aliases between our and their symbol names (port\gen_syms.py)
($objs + $extra + $opts) | Out-File $rsp -Encoding ascii
link /nologo /SUBSYSTEM:WINDOWS /LARGEADDRESSAWARE /BASE:0x20000000 /FIXED:NO /ENTRY:port_entry /FORCE:MULTIPLE /MAP:port\build\turok.map "/OUT:$exe" port\build\win32_main.obj $portobjs "@$rsp" user32.lib kernel32.lib winmm.lib d3d11.lib d3dcompiler.lib 2>&1 | Out-File port\build\link.log -Encoding ascii
$n = (Select-String -Path port\build\link.log -Pattern 'LNK2001|LNK2019').Count
"unresolved reports: $n"
if (Test-Path $exe) { $exe | Out-File port\build\latest_exe.txt -Encoding ascii }
