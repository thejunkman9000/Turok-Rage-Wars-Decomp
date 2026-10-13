#include "o05_types.h"

typedef struct { s32 id; s32 f4; s32 f8; s32 fC; s32 f10; } O05Ent;
typedef struct { u8 pad0[0x20]; void *f20; u8 pad24[0x9C - 0x24]; O05Ent ent[11]; u8 pad178[0x10]; s32 f188; } O05M5830;
typedef struct { u8 pad[0x10]; u8 b10; u8 pad11[0x38 - 0x11]; s32 f38; } O05Wd;
extern O05M5830 *D_800E5830;
O05Wd *func_0040ECB0(void *p, s32 id);
void func_0040E958(void *w, s32 a);
void func_00439D3C(void *o, s32 n, O05Vec3 a, O05Vec3 b);
void func_00439DC0(void *o, O05Vec3 v);
void func_00439E10(void *o, O05Vec3 v);
void func_00439E60(void *o, s32 n);

void func_auto_00438614(void) {
    O05Vec3 a;
    O05Vec3 b;
    O05Vec3 c;
    O05Vec3 d;
    s32 idx = D_800E5830->f188;
    s32 id = D_800E5830->ent[idx].id;
    O05Wd *w;
    if (id >= 0) {
        w = func_0040ECB0(D_800E5830->f20, 0x27E);
        func_0040E958(w, 1);
        w->b10 = 0xAF;
        w->f38 = D_800E5830->ent[idx].f10;
        if ((u32)(id - 0x1389) < 2 || id == 0x139F || id == 0x13A0 || id == 0x13C1 || id == 0x1398 || id == 0x13BD) {
            a.z = a.y = a.x = 0.3f;
        } else {
            a.z = a.y = a.x = 0.009f;
        }
        d.y = 3.0f;
        b.y = -5.0f;
        b.z = -100.0f;
        c.x = 0;
        c.y = 0;
        c.z = 0;
        d.x = 0;
        d.z = 0;
        b.x = 0;
        if (id == 0x1390 || id == 0x1392) {
            b.x = 0;
            b.z = -100.0f;
            b.y = -30.0f;
            a.z = a.y = a.x = 0.3f;
        }
        func_00439D3C((u8 *)D_800E5830 + 0xC8, 0, a, b);
        func_00439DC0((u8 *)D_800E5830 + 0xC8, c);
        func_00439E10((u8 *)D_800E5830 + 0xC8, d);
        func_00439E60((u8 *)D_800E5830 + 0xC8, id);
        D_800E5830->ent[idx].f4 = 0;
        D_800E5830->ent[idx].f8 = 10;
    }
}
