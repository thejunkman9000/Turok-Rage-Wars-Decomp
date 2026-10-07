#include "b14_types.h"
u32 func_002606E4(u32 addr, u32 n);
void func_0025FD94(B14Trk *t);
extern f32 D_800C9248;
extern f64 D_800C9250;
typedef struct { f32 c0, c1, c2, c3; u32 span; } B14Cubic;
f32 func_00260158(B14Trk *t, f32 x) {
    u32 tbl[64];
    u32 frame;
    u32 start;
    s32 rec;
    s32 lt;
    s32 idx;
    u32 s4, s0, addr, data;
    B14Cubic l;
    f32 d, dt;
    f64 dd;
    if (!(D_800C9248 <= x)) {
        frame = (s32)x;
    } else {
        frame = (s32)(x - D_800C9248) | 0x80000000;
    }
    start = t->start;
    rec = t->bits * 4 + 6;
    lt = frame < start;
    if (lt || frame >= start + t->span) {
        idx = t->cur;
        s4 = start;
        data = t->data;
        s0 = s4 + t->span;
        addr = data + idx * rec;
        if (lt) {
            addr = data;
            idx = 0;
            s4 = 0;
            s0 = func_002606E4(addr, 6);
        }
        for (;;) {
            addr += rec;
            if (!(frame < s4) && frame < s0) {
                break;
            }
            idx++;
            s4 = s0;
            tbl[idx] = func_002606E4(addr, 6);
            s0 += tbl[idx];
        }
        if (idx != t->cur) {
            t->start = s4;
            t->cur = idx;
            func_0025FD94(t);
        }
    }
    dd = (f64)t->start;
    if ((s32)t->start < 0) {
        dd += D_800C9250;
    }
    d = (f32)dd;
    l = *(B14Cubic *)&t->c0;
    dt = x - d;
    return l.c0 + l.c1 * dt + l.c2 * dt * dt + l.c3 * dt * dt * dt;
}
