Set-Location (Split-Path $PSScriptRoot -Parent)
Add-Type -Namespace W -Name KT -MemberDefinition '[DllImport("user32.dll")] public static extern void keybd_event(byte vk, byte sc, uint fl, UIntPtr ex);' -ErrorAction SilentlyContinue
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$env:TUROK_SKIPMENU = '1'; $env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $menu = $false; $k = 0; $sent = 0
while (((Get-Date) - $t0).TotalSeconds -lt 100) {
    Start-Sleep -Milliseconds 1000
    if (((Get-Date) - $t0).TotalSeconds -lt 18) { continue }
    if (-not $menu -and (Select-String -Path port\build\run.log -Pattern '-> 3 ' -ErrorAction SilentlyContinue)) { $menu = $true; $tm = Get-Date }
    if ($menu -and ((Get-Date) - $tm).TotalSeconds -gt 8) { break }
    $k++; $vk = 0x0D; if ($menu) { $vk = 0x43 }
    [W.KT]::keybd_event([byte]$vk, 0, 0, [UIntPtr]::Zero); Start-Sleep -Milliseconds 700; [W.KT]::keybd_event([byte]$vk, 0, 2, [UIntPtr]::Zero); $sent++
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item Env:TUROK_SKIPMENU, Env:TUROK_LOG -ErrorAction SilentlyContinue
"menu seen: $menu, taps sent: $sent"
