# usage: tools/pbg.ps1 <fn> <seconds> <jobs>
Set-Location D:\Projects\ws\s705
Start-Process -WindowStyle Hidden -FilePath wsl -ArgumentList "-d","Ubuntu-24.04","--","bash","/mnt/d/Projects/ws/s705/tools/prun.sh",$args[0],$args[1],$args[2]
