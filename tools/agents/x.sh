grep -n -E "^;; (ready list at|launching|blocking|insn .* has a greater)" /tmp/dd3_w2/a.i.sched2 | sed -n 1,200p | cut -c1-200 | sed -n 1,75p
