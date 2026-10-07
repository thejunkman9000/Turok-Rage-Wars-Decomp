#include "o05_types.h"

typedef struct { s32 v9C; s32 a0; s32 a4; s32 a8; void *ac; } O05E30;
typedef struct {
    u8 pad0[0x20];
    void *f20;
    u8 pad24[0x9C - 0x24];
    O05E30 ent[2];
    u8 padC4[4];
    u8 obj[0x188 - 0xC8];
    s32 f188;
} O05M30;
extern O05M30 *D_800E5830;
O05ItemWd *func_0040ECB0(void *w, s32 id);
void func_0040E958(void *w, s32 a);
void func_00439D3C(void *o, s32 n, O05Vec3 a, O05Vec3 b);
void func_00439DC0(void *o, O05Vec3 v);
void func_00439E10(void *o, O05Vec3 v);
void func_00439E60(void *o, s32 n);

void func_004387F4(void) {
    O05Vec3 a;
    O05Vec3 b;
    O05Vec3 c;
    O05Vec3 d;
    O05ItemWd *w;
    s32 sel = D_800E5830->f188;
    s32 v = D_800E5830->ent[sel].v9C;
    if (v >= 0) {
        w = func_0040ECB0(D_800E5830->f20, 0x282);
        func_0040E958(w, 1);
        w->b10 = 0xAF;
        w->f38 = D_800E5830->ent[sel].ac;
        if (v == 0x1389 || v == 0x138A || v == 0x139F || v == 0x13A0 || v == 0x13C1 || v == 0x1398 || v == 0x13BD) {
            a.z = a.y = a.x = 0.3f;
        } else {
            a.z = a.y = a.x = 0.009f;
        }
        c.x = 0;
        c.y = 0;
        c.z = 0;
        d.x = 0;
        d.y = 3.0f;
        d.z = 0;
        b.x = 0;
        b.y = -5.0f;
        b.z = -100.0f;
        if (v == 0x1390 || v == 0x1392) {
            b.x = 0;
            b.y = -30.0f;
            b.z = -100.0f;
            a.z = a.y = a.x = 0.3f;
        }
        func_00439D3C(D_800E5830->obj, 0, a, b);
        func_00439DC0(D_800E5830->obj, c);
        func_00439E10(D_800E5830->obj, d);
        func_00439E60(D_800E5830->obj, v);
        D_800E5830->ent[sel].a0 = 0;
        D_800E5830->ent[sel].a4 = 10;
    }
}
