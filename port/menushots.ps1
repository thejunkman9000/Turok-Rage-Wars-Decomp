# tap Enter/C until the main menu (screen 3) shows, then take shots: .\port\menushots.ps1 -Prefix mm -Count 4 [-Taps 'C','Down']
param([string]$Prefix = 'mm', [int]$Count = 4, [string[]]$After = @())
Set-Location (Split-Path $PSScriptRoot -Parent)
Add-Type -Namespace W -Name KK -MemberDefinition '[DllImport("user32.dll")] public static extern void keybd_event(byte vk, byte sc, uint fl, UIntPtr ex);' -ErrorAction SilentlyContinue
function Tap($vk, $ms = 220) { [W.KK]::keybd_event($vk, 0, 0, [UIntPtr]::Zero); Start-Sleep -Milliseconds $ms; [W.KK]::keybd_event($vk, 0, 2, [UIntPtr]::Zero) }
$map = @{ 'Enter' = 0x0D; 'C' = 0x43; 'X' = 0x58; 'Z' = 0x5A; 'Up' = 0x26; 'Down' = 0x28; 'Left' = 0x25; 'Right' = 0x27 }
$exe = (Get-Content port\build\latest_exe.txt).Trim(); $name = [IO.Path]::GetFileNameWithoutExtension($exe)
$env:TUROK_SKIPMENU = '1'; $env:TUROK_TREE = '1'; $env:TUROK_E154 = '1'; if ($env:MM_FTRACE) { $env:TUROK_FTRACE = $env:MM_FTRACE }; $env:TUROK_LOG = (Join-Path (Get-Location) 'port\build\run.log')
$env:TUROK_SCRIPT = '1'; $null = Start-Process $exe -WorkingDirectory (Get-Location).Path
$t0 = Get-Date; $n = 0
while (((Get-Date) - $t0).TotalSeconds -lt 120) {
    Start-Sleep -Milliseconds 1200
    if (((Get-Date) - $t0).TotalSeconds -lt 18) { continue }
    if (Select-String -Path port\build\run.log -Pattern '-> 3 ' -ErrorAction SilentlyContinue) {
        Start-Sleep 3
        & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_00.png" -f $Prefix) | Out-Null
        if ($env:MM_DUMP) { New-Item port_dumpnow.txt -ItemType File | Out-Null; Start-Sleep 2 }
        foreach ($k in $After) { Tap $map[$k] 250; Start-Sleep -Milliseconds 1800; $n++; & "$PSScriptRoot\screenshot.ps1" -Out ("port\build\{0}_{1:D2}.png" -f $Prefix, $n) | Out-Null }
        break
    }
    Tap 0x0D
}
Get-Process -Name $name -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill() } catch {} }
Remove-Item Env:TUROK_SKIPMENU, Env:TUROK_LOG -ErrorAction SilentlyContinue
"shots after taps: $n"
