# Diff several libultra functions against the ROM. usage: .\tools\lu_batch_diff.ps1  (edit $jobs)
Set-Location D:\Projects\TurokRageWars
$jobs = @(
  @{f='osSetEventMesg.c';     n='osSetEventMesg';     r='0xC1240'},
  @{f='osGetThreadPri.c';     n='osGetThreadPri';     r='0xC0A70'},
  @{f='osVirtualToPhysical.c';n='osVirtualToPhysical';r='0xC18B8'},
  @{f='osDestroyThread.c';    n='osDestroyThread';    r='0xC2B10'},
  @{f='osGetTime.c';          n='osGetTime';          r='0xC0AAC'}
)
foreach ($j in $jobs) {
  wsl -d Ubuntu-24.04 -- bash tools/lu_ud.sh $j.f "$($j.n)=$($j.r)"
  .\.venv\Scripts\python.exe tools\lu_ud.py build_ud.json $j.n
}
