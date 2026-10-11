for p in sched greg sched2; do
  echo "=== $p"
  python3 /mnt/d/Projects/ws/s905/tools/rtlc.py ~/dd905/a.i.$p 0 100000 | cut -c1-150 | grep -v NOTE_INSN | grep -n -E "D_8011FE80|call_insn" | head -8
done
