#include "b03_types.h"

extern f32 D_800D2988;
s32 func_00265898(s32 cb);
s32 func_002657A4(s32 cb);
s32 func_0024B728(ActorB *a, s32 cb, s32 id);
s8 func_002469F8(ActorB *a, s32 anim, s32 id);
void func_0024B6E4(ActorB *a, s32 id, u32 loop);

void func_00213ED4(ActorB *a, StateB *s) {
    StateEntry *e;
    f32 f;
    f32 sp;
    s32 v;
    s32 d;

    e = s->cur;
    if (e == NULL) {
        return;
    }
    if (s->unk35 != s->id) {
        f = e->speed;
        if (f >= 0.0f) {
            s->unkC4 = f;
        }
        s->unk38 = s->unk3C;
        s->unk3C = e->flags;
        a->unk10E = 0;
        v = (s32)e->anim;
        if (v != 0) {
            if (func_00265898(v) != 0) {
                v = ((s32 (*)(ActorB *, StateB *))v)(a, s);
            } else if (func_002657A4(v) != 0) {
                v = func_0024B728(a, v, s->unkCA);
            }
            if (v != 0) {
                if (v != -1) {
                    s->unkCA = func_002469F8(a, v, s->unkCA);
                    s->unkC8 = v;
                    if (a->unk108 == s->unkCA) {
                        a->unk104 = 0.0f;
                    }
                }
                s->unkCB = 0;
                s->flags &= ~1;
            }
        }
        s->unk35 = s->id;
    } else {
        if (s->unkCA == -1 || s->unkC8 == -1) {
            s->unkCB = s->unkCB + 1;
            s->flags |= 1;
        } else if (a->unk108 == s->unkCA) {
            if (!(s->flags & 1)) {
                d = a->unk10C - e->len;
                if ((f32)(u32)d <= a->unk104) {
                    s->unkCB = s->unkCB + 1;
                    s->flags |= 1;
                }
            }
            if (a->unk10E != 0) {
                a->unk10E = 0;
                if (!(s->flags & 1)) {
                    s->unkCB = s->unkCB + 1;
                }
                s->flags &= ~1;
            }
        }
    }
    if (s->unk3C & 0x10) {
        sp = s->unkC4;
    } else {
        sp = s->unkC0 * s->unkC4;
    }
    D_800D2988 *= sp;
    func_0024B6E4(a, s->unkCA, (s->unk3C >> 5) & 1);
    if (s->unkCA != -1 && a->unk10A != s->unkCA) {
        s->unkCB = 0;
        s->flags &= ~1;
        a->unk10E = 0;
    }
    if (a->flags & 0x8000000) {
        s->unkCB = s->unkCB + 1;
    }
}
