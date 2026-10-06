# Diff libultra functions against the ROM. usage: .\tools\lu_batch_diff.ps1 [name ...]   (edit $jobs)
param([string[]]$Only)
Set-Location D:\Projects\TurokRageWars
$jobs = @(
  @{f='osSetThreadPri.c';       n='osSetThreadPri';       r='0xC12E0'},
  @{f='osSpTaskLoadGo.c';       n='_VirtualToPhysicalTask'; r='0xBFA84'},
  @{f='osSpTaskLoadGo.c';       n='osSpTaskLoad';         r='0xBFB90'},
  @{f='osStartThread.c';        n='osStartThread';        r='0xC1444'},
  @{f='osGetThreadPri.c';       n='osGetThreadPri';       r='0xC0A70'}
)
foreach ($j in $jobs) {
  if ($Only -and ($Only -notcontains $j.n)) { continue }
  wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh $j.f "$($j.n)=$($j.r)"
  .\.venv\Scripts\python.exe tools\lu_ud.py build_ud.json $j.n
}
