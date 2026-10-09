#include "b14_types.h"
u32 func_002606E4(u32 addr, u32 n);
void func_0025FD94(B14Trk *t);
void func_00261438(B14Trk *t, u32 frame) {
    u32 tbl[64];
    u32 start = t->start;
    s32 rec = t->bits * 4 + 6;
    s32 idx;
    u32 s4, s0, addr, data;
    u32 *p;
    u32 *tb;
    if (frame < start || frame >= start + t->span) {
        idx = t->cur;
        s4 = start;
        addr = t->data;
        data = addr;
        addr += idx * rec;
        s0 = s4 + t->span;
        if (frame < start) {
            addr = data;
            idx = 0;
            s4 = 0;
            s0 = func_002606E4(addr, 6);
        }
        tb = tbl;
        p = (u32 *)(idx * 4 + (u32)tb);
        for (;;) {
            addr += rec;
            if (!(frame < s4 || frame >= s0)) {
                if (idx != t->cur) {
                    t->start = s4;
                    t->cur = idx;
                    func_0025FD94(t);
                }
                return;
            }
            p++;
            idx++;
            s4 = s0;
            *p = func_002606E4(addr, 6);
            s0 += *p;
        }
    }
}