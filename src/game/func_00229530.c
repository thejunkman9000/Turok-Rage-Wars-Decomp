#include "b06_types.h"

extern s32 D_800CE3E8[];
extern ActorRow400 D_80102B10[];
extern u8 D_801462D5;
extern char D_800C7D40[];
extern char D_800C7D44[];
void func_002A166C(s32 a, char *b, s32 c);
void func_002A125C(char *a, char *b);
void func_002A12E8(char *a, char *b);
char *func_00232754(s32 i);
void func_0022B74C(Plr *a, char *s, f32 x);

static __inline__ s32 lim(Plr *a, s32 i) {
    s32 v;
    u8 g;
    s32 *d;
    if (i == -1) {
        return 0;
    }
    g = D_801462D5;
    if (g != 1) {
        d = a->unk18->unk108;
        v = d[i];
    } else {
        v = D_800CE3E8[i];
        if (a->unk1450 == 0) {
            if (i == 0) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 5);
            } else if (i == g) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 6);
            } else if (i == 2) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 4);
            }
        }
    }
    return v;
}

void func_00229530(Plr *a, s32 i, s32 n) {
    char b10[8];
    char b18[0x20];
    Plr *q;
    s32 nv;
    if (n != 0) {
        q = (Plr *)((u8 *)a + i * 2);
        nv = q->unk5F4[0] + n;
        if (nv < lim(a, i)) {
            q->unk5F4[0] = a->unk5F4[i] + n;
        } else {
            q->unk5F4[0] = lim(a, i);
        }
        func_002A166C(n, b10, nv);
        func_002A125C(b18, b10);
        func_002A12E8(b18, D_800C7D40);
        func_002A12E8(b18, func_00232754(i));
        if (n >= 2) {
            func_002A12E8(b18, D_800C7D44);
        }
        func_0022B74C(a, b18, 1.0f);
    }
}
