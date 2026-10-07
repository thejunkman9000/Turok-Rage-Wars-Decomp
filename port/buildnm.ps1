# Compile the behaviour-level (non-matching) drafts in port\nonmatching into port\build\obj_nm.  usage: .\port\buildnm.ps1
# A draft was written against the headers of the worker that produced it; when it does not compile against include\
# the worker workspaces' include dirs are tried in turn (their struct layouts are the same, only names/fields differ).
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
$obj = 'port\build\obj_nm'; Remove-Item -Recurse -Force $obj -ErrorAction SilentlyContinue; New-Item -ItemType Directory -Force $obj | Out-Null
$wsInc = @(Get-ChildItem D:\Projects\ws\*\include -Directory -ErrorAction SilentlyContinue | Sort-Object { $_.Parent.LastWriteTime } -Descending | ForEach-Object { $_.FullName })
$fi = "/FI$((Get-Location).Path)\port\compat.h"
$ok = 0; $viaws = 0; $bad = @()
foreach ($f in Get-ChildItem port\nonmatching\*.c) {
    $out = "/Fo$obj\$($f.BaseName).obj"
    cl /nologo /O1 /Gh /w /TC /Iinclude /D_LANGUAGE_C /DTARGET_PC $fi /c $out $f.FullName 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) { $ok++; continue }
    $done = $false
    foreach ($inc in $wsInc) {
        if (-not (Select-String -Path $f.FullName -Pattern '#include "(\w+)\.h"' | Where-Object { Test-Path (Join-Path $inc ($_.Matches[0].Groups[1].Value + '.h')) })) { continue }
        cl /nologo /O1 /Gh /w /TC "/I$inc" /Iinclude /D_LANGUAGE_C /DTARGET_PC $fi /c $out $f.FullName 2>&1 | Out-Null
        if ($LASTEXITCODE -eq 0) { $done = $true; $viaws++; break }
    }
    if ($done) { $ok++ } else { $bad += $f.Name; Remove-Item "$obj\$($f.BaseName).obj" -ErrorAction SilentlyContinue }
}
"compiled: $ok (of which $viaws with a worker's own headers)  failed: $($bad.Count)"
$bad | Out-File port\build\nm_failed.txt
