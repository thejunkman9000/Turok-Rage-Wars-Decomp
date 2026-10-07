# Compile the behaviour-level (non-matching) drafts in port\nonmatching into port\build\obj_nm.  usage: .\port\buildnm.ps1
$ErrorActionPreference = 'Continue'
Set-Location (Split-Path $PSScriptRoot -Parent)
cmd /c '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars32.bat" >nul 2>&1 && set' |
  ForEach-Object { if ($_ -match '^([^=]+)=(.*)$') { Set-Item -Path "env:$($Matches[1])" -Value $Matches[2] } }
$obj = 'port\build\obj_nm'; Remove-Item -Recurse -Force $obj -ErrorAction SilentlyContinue; New-Item -ItemType Directory -Force $obj | Out-Null
$ok = 0; $bad = @()
foreach ($f in Get-ChildItem port\nonmatching\*.c) {
    $o = cl /nologo /O1 /w /TC /Iinclude /D_LANGUAGE_C /DTARGET_PC "/FI$((Get-Location).Path)\port\compat.h" /c "/Fo$obj\$($f.BaseName).obj" $f.FullName 2>&1
    if ($LASTEXITCODE -eq 0) { $ok++ } else { $bad += $f.Name; Remove-Item "$obj\$($f.BaseName).obj" -ErrorAction SilentlyContinue }
}
"compiled: $ok  failed: $($bad.Count)"
$bad | Out-File port\build\nm_failed.txt
