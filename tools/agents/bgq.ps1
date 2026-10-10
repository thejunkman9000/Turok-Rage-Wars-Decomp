# usage: tools/bgq.ps1 <bash script rel to ws> args...   (launches the script in WSL detached)
Set-Location D:\Projects\ws\s705
$a = @("-d","Ubuntu-24.04","--","bash","/mnt/d/Projects/ws/s705/$($args[0])") + $args[1..($args.Length-1)]
Start-Process -WindowStyle Hidden -FilePath wsl -ArgumentList $a
