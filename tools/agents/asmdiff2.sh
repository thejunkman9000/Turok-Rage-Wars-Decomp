#!/bin/bash
# asmdiff2.sh a.c b.c [n] : compile both with sa2.sh and diff the disassembly
bash /mnt/d/Projects/ws/s905/tools/sa2.sh $1 > /tmp/ad_a.txt
bash /mnt/d/Projects/ws/s905/tools/sa2.sh $2 > /tmp/ad_b.txt
diff /tmp/ad_a.txt /tmp/ad_b.txt | head -${3:-40}
echo "lines: $(wc -l < /tmp/ad_a.txt) $(wc -l < /tmp/ad_b.txt)"
