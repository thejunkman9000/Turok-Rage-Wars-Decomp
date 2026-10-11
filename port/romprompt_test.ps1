# Drives the first-run ROM question of the port (port/rom_find.c) through UI Automation.
#   .\port\romprompt_test.ps1            runs every scenario in a scratch folder (TUROK_DATADIR points there, the real data folder is not touched)
# Scenarios: no ROM anywhere -> explanation box -> file dialog -> wrong ROM (Europe) is refused with the release named -> the right one is accepted, copied,
#            the game window opens; second start asks nothing; cancel quits without a window.  Needs the ROMs in the project root and an unlocked desktop.
param([string]$Exe = '')
$ErrorActionPreference = 'Stop'
Set-Location (Split-Path $PSScriptRoot -Parent)
$root = (Get-Location).Path
if (-not $Exe) { $Exe = Join-Path $root (Get-Content port\build\latest_exe.txt).Trim() }
Add-Type -AssemblyName UIAutomationClient, UIAutomationTypes
Add-Type -Namespace W -Name U -MemberDefinition '[DllImport("user32.dll")] public static extern IntPtr GetDlgItem(IntPtr h, int id); [DllImport("user32.dll")] public static extern IntPtr SendMessage(IntPtr h, uint m, IntPtr w, IntPtr l);'
$good = Join-Path $root 'baserom.us.v11.z64'; $eu = Join-Path $root 'baserom.eu.z64'
$scratch = Join-Path $env:TEMP ('romprompt_' + [guid]::NewGuid().ToString('N').Substring(0, 8))
$work = Join-Path $scratch 'work'; $data = Join-Path $scratch 'data'
New-Item -ItemType Directory -Force $work | Out-Null
$fail = 0
function Check($ok, $what) { if ($ok) { "  ok   $what" } else { "  FAIL $what"; $script:fail++ } }

# the port restarts itself when Windows put a DLL into one of the guest address ranges (port_early_init): follow it by image name, not by process id
function Port-Pids { @(Get-Process -Name ([IO.Path]::GetFileNameWithoutExtension($script:Exe)) -ErrorAction SilentlyContinue | ForEach-Object { $_.Id }) }
function Find-Top($pat, $secs) {                      # a top-level window of the started process whose name matches
    $end = (Get-Date).AddSeconds($secs)
    while ((Get-Date) -lt $end) {
        $c = [Windows.Automation.AutomationElement]::RootElement.FindAll([Windows.Automation.TreeScope]::Children, [Windows.Automation.Condition]::TrueCondition)
        foreach ($w in $c) { try { if ((Port-Pids) -contains $w.Current.ProcessId -and $w.Current.Name -match $pat) { return $w } } catch {} }
        Start-Sleep -Milliseconds 200
    }
    return $null
}
function Click-Button($win, $name) {
    $cond = New-Object Windows.Automation.AndCondition((New-Object Windows.Automation.PropertyCondition([Windows.Automation.AutomationElement]::ControlTypeProperty, [Windows.Automation.ControlType]::Button)),
                                                       (New-Object Windows.Automation.PropertyCondition([Windows.Automation.AutomationElement]::NameProperty, $name)))
    $b = $win.FindFirst([Windows.Automation.TreeScope]::Descendants, $cond)
    if (-not $b) { return $false }
    $b.GetCurrentPattern([Windows.Automation.InvokePattern]::Pattern).Invoke(); return $true
}
function Window-Text($win) {
    $t = @(); foreach ($e in $win.FindAll([Windows.Automation.TreeScope]::Descendants, [Windows.Automation.Condition]::TrueCondition)) { try { if ($e.Current.Name) { $t += $e.Current.Name } } catch {} }
    return ($t -join ' | ')
}
function Pick-File($dlg, $path) {                     # types the path into the dialog's file name box and presses Open
    $cond = New-Object Windows.Automation.AndCondition((New-Object Windows.Automation.PropertyCondition([Windows.Automation.AutomationElement]::ControlTypeProperty, [Windows.Automation.ControlType]::Edit)),
                                                       (New-Object Windows.Automation.PropertyCondition([Windows.Automation.AutomationElement]::AutomationIdProperty, '1148')))
    $edit = $dlg.FindFirst([Windows.Automation.TreeScope]::Descendants, $cond)
    if (-not $edit) { return $false }
    $edit.GetCurrentPattern([Windows.Automation.ValuePattern]::Pattern).SetValue($path)
    Start-Sleep -Milliseconds 300
    $h = [IntPtr]$dlg.Current.NativeWindowHandle
    $ok = [W.U]::GetDlgItem($h, 1)      # IDOK: the Explorer-style Open button is a plain Win32 button (UI Automation sees a Pane that does not take Invoke)
    if ($ok -eq [IntPtr]::Zero) { return $false }
    [W.U]::SendMessage($ok, 0xF5, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null      # BM_CLICK
    return $true
}
function Start-Port($cwd) {
    $env:TUROK_DATADIR = $data; $env:TUROK_PAK = '0'
    Remove-Item Env:\TUROK_ROM -ErrorAction SilentlyContinue
    $script:proc = Start-Process -FilePath $Exe -WorkingDirectory $cwd -PassThru
}
function Stop-Port { Get-Process -Name ([IO.Path]::GetFileNameWithoutExtension($script:Exe)) -ErrorAction SilentlyContinue | ForEach-Object { try { $_.Kill(); $_.WaitForExit(3000) | Out-Null } catch {} } }

"== 1. nothing installed: explanation, wrong ROM, right ROM"
Start-Port $work
$msg = Find-Top 'Turok: Rage Wars' 15
Check ($msg -ne $null) 'explanation box appears'
if ($msg) { $txt = Window-Text $msg; Check ($txt -match 'needs the game') 'it says that the ROM is needed'; Check ($txt -match [regex]::Escape($data)) 'it names the data folder'; Check (Click-Button $msg 'OK') 'OK pressed' }
$dlg = Find-Top 'Select the Turok' 15
Check ($dlg -ne $null) 'file dialog opens'
if ($dlg) { Check (Pick-File $dlg $eu) 'Europe ROM chosen' }
$bad = Find-Top 'wrong ROM' 15
Check ($bad -ne $null) 'the wrong ROM is refused'
if ($bad) { $txt = Window-Text $bad; Check ($txt -match 'Europe') 'the box names the release (Europe)'; Check (Click-Button $bad 'OK') 'OK pressed' }
Start-Sleep -Milliseconds 500
$dlg = Find-Top 'Select the Turok' 15
Check ($dlg -ne $null) 'file dialog opens again'
if ($dlg) { Check (Pick-File $dlg $good) 'US v1.1 ROM chosen' }
$game = Find-Top 'Turok: Rage Wars \(port\)' 30
Check ($game -ne $null) 'the game window opens'
Start-Sleep -Seconds 2
$copy = Join-Path $data 'baserom.us.v11.z64'
Check (Test-Path $copy) 'a copy was installed in the data folder'
if (-not (Test-Path $copy)) { '    data folder: ' + ((Get-ChildItem $data -ErrorAction SilentlyContinue | ForEach-Object { $_.Name + ' ' + $_.Length }) -join ', '); '    processes: ' + ((Port-Pids) -join ',') }
if (Test-Path $copy) { Check ((Get-FileHash $copy -Algorithm SHA1).Hash -eq '037FB397CEE2669048ED6B762A64698DE4A4D88A') 'the copy has the right SHA-1' }
Check ((Test-Path (Join-Path $data 'settings.ini')) -and ((Get-Content (Join-Path $data 'settings.ini') -Raw) -match 'lastdir')) 'the folder of the pick is remembered'
Stop-Port

"== 2. second start: nothing is asked"
Start-Port $work
$game = Find-Top 'Turok: Rage Wars \(port\)' 30
Check ($game -ne $null) 'the game window opens without a question'
$q = Find-Top 'Turok: Rage Wars$' 1
Check ($q -eq $null) 'no explanation box'
Stop-Port

"== 3. cancel quits quietly"
Remove-Item (Join-Path $data 'baserom.us.v11.z64') -Force -ErrorAction SilentlyContinue
Start-Port $work
$msg = Find-Top 'Turok: Rage Wars$' 15
Check ($msg -ne $null) 'explanation box appears again'
if ($msg) { Click-Button $msg 'Cancel' | Out-Null }
$end = (Get-Date).AddSeconds(10); while ((Get-Date) -lt $end -and (Port-Pids).Count) { Start-Sleep -Milliseconds 200 }
Check (-not (Port-Pids).Count) 'the program ends without a game window'
Stop-Port

"== 4. a byte-swapped (.v64) image is accepted and stored as .z64"
$v64 = Join-Path $scratch 'turok.v64'
$b = [IO.File]::ReadAllBytes($good); for ($i = 0; $i -lt $b.Length; $i += 2) { $t = $b[$i]; $b[$i] = $b[$i + 1]; $b[$i + 1] = $t }; [IO.File]::WriteAllBytes($v64, $b)
Remove-Item (Join-Path $data 'baserom.us.v11.z64') -ErrorAction SilentlyContinue
Start-Port $work
$msg = Find-Top 'Turok: Rage Wars$' 15
if ($msg) { Click-Button $msg 'OK' | Out-Null }
$dlg = Find-Top 'Select the Turok' 15
if ($dlg) { Pick-File $dlg $v64 | Out-Null }
$game = Find-Top 'Turok: Rage Wars \(port\)' 30
Check ($game -ne $null) 'the game window opens'
Start-Sleep -Seconds 2
Check ((Test-Path $copy) -and (Get-FileHash $copy -Algorithm SHA1).Hash -eq '037FB397CEE2669048ED6B762A64698DE4A4D88A') 'the stored copy is the big-endian image'
Stop-Port

Remove-Item $scratch -Recurse -Force -ErrorAction SilentlyContinue
if ($fail) { "ROM PROMPT TEST: $fail check(s) FAILED"; exit 1 } else { 'ROM PROMPT TEST: all checks passed' }
