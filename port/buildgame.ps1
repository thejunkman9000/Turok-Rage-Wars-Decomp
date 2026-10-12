# Compile every matched game/overlay C file for the 32-bit port into port\build\obj  (parallel).  usage: .\port\buildgame.ps1
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
. "$PSScriptRoot\vcvars.ps1"      # MSVC 32-bit environment (any VS 2022 / 2026 with the C++ tools; TUROK_VCVARS overrides)
$obj = 'port\build\obj'; New-Item -ItemType Directory -Force $obj | Out-Null
$files = @(Get-ChildItem src\game\*.c) + @(Get-ChildItem src\ovl_a\*.c) | Where-Object { -not (Test-Path (Join-Path 'port\overrides' ($_.BaseName + '.c'))) } | Where-Object {
    $o = Join-Path $obj ($_.BaseName + '.obj'); -not (Test-Path $o) -or (Get-Item $o).LastWriteTime -lt $_.LastWriteTime }
"compiling $($files.Count) files"
$log = 'port\build\compile.log'; Remove-Item $log -ErrorAction SilentlyContinue
for ($i = 0; $i -lt $files.Count; $i += 150) {
    $chunk = $files[$i..([Math]::Min($i + 149, $files.Count - 1))] | ForEach-Object { $_.FullName }
    cl /nologo /MP /O1 /Gh /w /TC /Iinclude /D_LANGUAGE_C /DTARGET_PC "/FI$((Get-Location).Path)\port\compat.h" /c "/Fo$obj\" @chunk 2>&1 | Out-File -Append $log -Encoding ascii
}
$errs = Select-String -Path $log -Pattern 'error C' -ErrorAction SilentlyContinue
"errors: $(($errs | Measure-Object).Count)"
# a file that failed to compile (or crashed the compiler) must not leave an object behind
Select-String -Path $log -Pattern '(src\(?:game|ovl_a)\(func_[0-9A-Fa-f]+|\w+))\.c[^\r\n]*(?:error|fatal error)' | ForEach-Object {
    $n = $_.Matches[0].Groups[2].Value; Remove-Item "$obj\$n.obj" -ErrorAction SilentlyContinue }
Get-ChildItem $obj\*.obj | Where-Object { $_.Length -lt 200 } | Remove-Item
