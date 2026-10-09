




#include "b24_types.h"

typedef struct Pad24 {
    u8 pad0[0x6AC];
    u32 unk6AC;
    u32 unk6B0;
} Pad24;

typedef s32 (*SlotFn)(Pad24 *, AnimSlot *);

s32 func_002A8088(AnimCtl *);
s32 func_002A80C4(AnimCtl *, s32);

static inline void func_002A8170(AnimSlot *s, AnimCtl *c) {
    s->unk4 = (s->unk4 == 0);
    if (s->unk4 != 0) {
        s->unk18 = 5;
        s->unk1C = c->unkE8;
        s->unk20 = s->unk28;
        s->unk24 = s->unk2C;
    } else {
        s->unk18 = -5;
    }
}

void func_002A75D0(AnimCtl *c, Pad24 *p) {
    u8 st;
    s32 off;
    u8 *sp;
    u8 *q;
    SlotFn fn;
    register u16 v asm("$3");
    register u16 a asm("$4");
    register u16 v2 asm("$2");
    s32 o;
    s32 iv, ia, w32;
    s16 sv;
    register s32 t asm("$2");
    register s32 k3 asm("$4");
    register s32 k3b asm("$4");

    c->unkE8 = c->unkE8 + 1;
    if (func_002A8088(c) == 0) {
        return;
    }
    st = c->unk0;
    if (st < 2) {
        if (p->unk6AC & 0x20) {
            if (st != 1) {
                c->unk0 = 1;
                goto A;
            }
            off = 4;
            goto B;
        }
        goto A;
    }
    if (p->unk6AC & 0x20) {
        off = 4;
        goto B;
    }
    sp = (u8 *)c;
    k3 = 3;
    if (st == k3) {
        off = 4;
        goto C;
    }
    c->unk0 = k3;
    o = ((c->cur << k3) - c->cur) << k3;
    q = (u8 *)c + o;
    if (*(s32 *)(q + 4) == 0) {
        off = 4;
        goto C;
    }
    fn = *(SlotFn *)(q + 0x34);
    if (fn != NULL) {
        if (fn(p, (AnimSlot *)((u8 *)c + (o + 4))) != 1) {
            off = 4;
            goto B;
        }
        func_002A8170(&c->slot[c->cur], c);
    } else {
        func_002A8170((AnimSlot *)(q + 4), c);
    }
A:
    off = 4;
B:
    sp = (u8 *)c;
    do {
C:
        v = *(u16 *)(sp + 0x1C);
        sv = v;
        a = v;
        if ((f32)sv < 0.0f) {
            a = -v;
        }
        t = (s16)a;
        if (t != 0) {
            if (t == sv) {
                v2 = v - 1;
            } else {
                v2 = v + 1;
            }
            *(u16 *)(sp + 0x1C) = v2;
        }
        if (*(s32 *)(sp + 4) != 0 && *(s32 *)(sp + 8) != 0) {
            fn = *(SlotFn *)(sp + 0x38);
            if (fn != NULL && fn(p, (AnimSlot *)((u8 *)c + off)) == 0) {
                func_002A8170(&c->slot[c->cur], c);
            }
        }
        sp += 0x38;
        off += 0x38;
    } while ((s32)sp < (s32)c + 0xE0);
    k3b = 3;
    c->unkE6++;
    if (c->unkE6 >= 5) {
        c->unkE6 = -5;
    }
    c->unkE6++;
    if (c->unkE6 >= 5) {
        c->unkE6 = -5;
    }
    st = c->unk0;
    if (st == 1) {
        c->unk1++;
        if (c->unk1 >= 5) {
            c->unk0 = 2;
        }
    } else if (st == k3b) {
        c->unk1--;
        if (c->unk1 == 0) {
            c->unk0 = 0;
        }
    } else {
        if (p->unk6B0 & 0x100) {
            func_002A80C4(c, 0);
        } else if (p->unk6B0 & 0x200) {
            func_002A80C4(c, 1);
        }
    }
}








