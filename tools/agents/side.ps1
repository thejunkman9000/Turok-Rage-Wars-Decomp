Set-Location D:\Projects\ws\s705
wsl -d Ubuntu-24.04 -- bash -c "rsync -a /mnt/d/Projects/ws/s705/wip/ ~/trw_s705/wip/ --exclude='_v_*' && rsync -a /mnt/d/Projects/ws/s705/include/ ~/trw_s705/include/ && cd /mnt/d/Projects/ws/s705 && python3 tools/side.py $args"
