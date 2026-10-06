#include "b05_types.h"

typedef struct B05P2 {
    u8 pad0[0x38];
    u32 flags;
    u8 pad3C[0x614];
    s16 state;
} B05P2;

typedef struct B05In {
    u8 pad0[0x20];
    f32 unk20;
    u8 pad24[0x14];
    u32 flags;
} B05In;

extern f32 D_800C7948;
extern f32 D_800C794C;
s32 func_002227D0(B05P2 *p, B05In *in, s32 st);

static inline s32 isAlt(s32 s) {
    if (s == 0x15 || s == 0x13 || s == 0x14) {
        return 1;
    }
    return 0;
}

s32 func_00222E80(B05P2 *p, B05In *in) {
    s32 st;
    s32 cur;
    f32 f;

    if (in->flags & 0x1000) {
        cur = p->state;
        if (cur == 0xB) goto part2;
        if (cur == 0xC) goto part2;
        if (cur == 9) goto part2;
        if (cur == 0xA) goto part2;
        if (cur == 0x26) goto part2;
        if (isAlt(cur)) {
            p->flags |= 0x1000;
            return 0;
        }
        st = 0xC;
        goto call;
    }
part2:
    if (isAlt(p->state)) {
        return 0;
    }
    if ((in->flags & 0x2003) != 0x2000) {
        return 0;
    }
    f = in->unk20;
    if (f <= 0.0f) {
        if (D_800C794C < f) {
            cur = p->state;
            if (cur == 0xB) goto no;
            if (cur == 0xC) goto no;
            if (cur == 9) goto no;
            if (cur == 0xA) goto no;
            if (cur == 0x26) goto no;
            st = 0xA;
call:
            func_002227D0(p, in, st);
            return 1;
        }
    }
no:
    return 0;
}
