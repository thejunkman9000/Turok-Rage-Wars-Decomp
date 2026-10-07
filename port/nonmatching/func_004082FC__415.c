#include "q01_types.h"
typedef struct Q01Sub { u8 pad0[4]; s8 unk4; } Q01Sub;
typedef struct Q01Obj { u8 pad0[0x1C]; s32 unk1C; Q01Sub *unk20; } Q01Obj;
extern s32 D_80153750;
extern s32 D_8015375C;
extern s32 D_8015377C;
extern s32 D_80153784;
extern s32 D_8015378C;
extern s32 D_800E28C8;
extern s32 D_800D7704;
extern s32 D_8014ADA0;
extern u8 D_8014561C[];
extern u8 D_0044FB44[];
extern u8 D_0044F124[];
s32 func_002A137C(u8 *a, s32 b);
void func_00404E28(s32 a);
s32 func_00404F04(s32 a);
void func_00405338(s32 a, s32 b, s32 *c);
void func_00405648(s32 a, u8 *b, s32 c);
void func_00405F48(Q01Obj *o);
s32 func_00406178(Q01Obj *o, s32 a, s32 b);
void func_00407290(s32 a, Q01Obj *o, s32 c);
void func_00407578(s32 a, Q01Obj *o, s32 c);
void func_004426E4(void *a, void *b, s32 c, Q01Sub *d, void *e);

s32 func_004082FC(s32 a0, Q01Obj *o, s32 a2) {
    u8 buf[16];
    struct { s32 pad; s32 v; } L;
    s32 s0, s1, s2, found;
    L.pad = 0;
    if (D_80153750 != 0) {
        if (D_8015375C != 0) {
            L.pad = D_800E28C8;
        } else {
            L.pad = o->unk20->unk4;
        }
    }
    if (D_8015375C != 0) {
        s1 = D_800E28C8;
    } else {
        s1 = L.pad;
    }
    if (func_00406178(o, s1, 0) != 0) goto done;
    if (D_8015377C != 0) {
        if (D_80153750 != 0) {
            func_00407290(a0, o, a2);
            return 1;
        }
    } else if (D_80153750 != 0) {
        s32 t;
        s0 = 0;
        t = D_800D7704;
        D_8015378C = -1;
        do {
            func_00405338(s1, s0, &L.v);
            func_00405648(L.v, buf, 0x10);
            if (func_002A137C(buf, t) == 0) {
                found = 1;
                if (&D_8015378C != 0) D_8015378C = s0;
                goto after;
            }
            s0++;
        } while (s0 < 0x10);
        found = 0;
after:
        if (found != 0 && D_8015378C >= 0 && D_8015378C < 0x10) {
            func_004426E4(D_8014561C, D_0044FB44, o->unk1C, o->unk20, D_0044F124);
            return 1;
        }
        func_00407578(a0, o, a2);
        return 1;
    }
    if (D_8015375C != 0) {
        s32 r = D_800E28C8;
        s0 = 0;
        if (r != -1) {
            s0 = r + 1;
            if (s0 >= 4) s0 = 0;
        }
        s1 = 0;
        do {
            func_00404E28(s0);
            if (func_00404F04(s0) != -2) break;
            s0++;
            if (s0 >= 4) s0 = 0;
            s1++;
        } while (s1 < 4);
        if (s1 == 4) s0 = -1;
        D_800E28C8 = s0;
        if (s0 == -1) {
            D_8014ADA0 = D_80153784 = 1;
            return 1;
        }
        {
            s32 a1 = s0;
            if (D_8015375C == 0) a1 = o->unk20->unk4;
            L.pad = a1;
            if (func_00406178(o, a1, 0) != 0) {
done:
                D_80153784 = 1;
                return 1;
            }
            func_00405F48(o);
        }
    }
    return 0;
}
