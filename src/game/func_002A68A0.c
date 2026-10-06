#include "b23_types.h"

typedef struct Slot68A0 Slot68A0;
struct Slot68A0 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ Slot68A0 *next;
    /* 0x08 */ u8 pad8[0x14];
    /* 0x1C */ void *owner;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 unk24;
};

typedef struct Inner14 {
    u8 pad0[0x14];
    s32 unk14;
} Inner14;

typedef struct Actor68A0 {
    u8 pad0[0x118];
    Inner14 *unk118;
} Actor68A0;

extern f32 D_800CB028;
extern f32 D_800CB02C;

void func_00270980(void *m, void *src);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
void func_00272898(void *m);
void func_002A35C0(u8 *o, Slot68A0 *s, void *m);

void func_002A68A0(u8 *o, Actor68A0 *who, void *src) {
    u8 m[0x40];
    Slot68A0 *s;
    f32 zero, k;

    s = *(Slot68A0 **)(o + 0x7528);
    if (s != 0) {
        zero = 0.0f;
        do {
            if (s->owner == who) {
                if (zero < s->unk24) {
                    if (zero < s->unk24) {
                    func_00270980(m, src);
                    k = D_800CB028;
                    if (who->unk118->unk14 != 0) {
                        k = D_800CB02C;
                    }
                    func_002734EC(m, k, k, k);
                    func_00272898(m);
                    func_002A35C0(o, s, m);
                    }
                }
            }
            s = s->next;
        } while (s != 0);
    }
}

