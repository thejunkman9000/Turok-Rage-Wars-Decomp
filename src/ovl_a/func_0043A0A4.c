#include "q04_types.h"

typedef struct O3Vec3 { f32 x, y, z; } O3Vec3;
typedef struct O3V3i { s32 x, y, z; } O3V3i;
typedef struct O3Row {
    s32 f0; s32 f4; s32 f8;
    f32 fC[4];
    f32 f1C[4];
    O3V3i v2C[4];
    s32 f5C[4];
    s32 pad6C;
} O3Row;
typedef struct { u8 pad[0x10]; u8 b10; u8 pad11[3]; u16 h14; u16 h16; s16 h18; } Q4Wd;
typedef struct { u8 pad[0x78]; u8 b78; u8 pad79[7]; s8 b80; u8 pad81[0x96 - 0x81]; } Q4Rec;
typedef struct { u16 w[38]; } O05Row;
extern Q04L2 *D_800E59E0;
extern Q4Rec D_80146398[];
extern O05Row D_800E59E6[];
extern O05Row D_800E59EA[];
extern O3Row D_800E3A50[];
void *func_00252FFC(s32 n);
s32 func_0041B690(s32 a, s32 b);
void func_0041B768(s32 a, s32 b, s32 c);
Q4Wd *func_0040ECB0(void *p, s32 id);
void func_0040E958(void *w, s32 a);
s32 func_0041F1B0(s32 a);
void func_0041CB48(void *o, s32 a, s32 b, s32 c, s32 d, O3Vec3 v, O3V3i w, f32 f, s32 g);
void *func_00419ED4(s32 a, s32 b);
void func_0043BB4C(void);
void func_0043B2AC(s32 i);
void func_002A338C(void);

s32 func_0043A0A4(s32 a, void *b) {
    s32 i;
    s32 j;
    Q4Wd *w;
    O3Vec3 v;
    Q4Rec *e;
    Q04L2 *p;
    s32 s;
    s32 t;
    p = func_00252FFC(0x1670);
    D_800E59E0 = p;
    p->f0 = (void *)a;
    D_800E59E0->f4 = (void *)func_0041B690(a, 4);
    func_0041B768(a, 0, 0xC8);
    func_0041B768(a, 1, 0xC8);
    func_0041B768(a, 2, 0xC8);
    func_0041B768(a, 3, 0xC8);
    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    i = 0;
    do {
        D_800E59E0->row[i].f4A8 = 0;
        D_800E59E0->row[i].f4AC = 5;
        w = func_0040ECB0(D_800E59E0->f0, D_800E59EA[i].w[0]);
        D_800E59E0->row[i].f4C8 = w;
        w->b10 = 0x64;
        func_0040E958(w, 0);
        func_0040ECB0(D_800E59E0->f0, D_800E59E6[i].w[0])->b10 = 0x6E;
        e = &D_80146398[i];
        if (e->b78 == 1) {
            s = func_0041F1B0(e->b80);
            v.x = D_800E3A50[s].fC[i];
            v.y = D_800E3A50[s].fC[i];
            v.z = D_800E3A50[s].fC[i];
            func_0041CB48(&D_800E59E0->row[i], 9, e->b80 + 0x38F, 0x4B, 0x5DC0, v, D_800E3A50[s].v2C[i], D_800E3A50[s].f1C[i], D_800E3A50[s].f5C[i]);
        }
        i++;
    } while (i < 4);
    D_800E59E0->f1358 = 1;
    D_800E59E0->f135C = 4;
    D_800E59E0->f1348 = func_0040ECB0((void *)a, 0xCE);
    ((Q4Wd *)D_800E59E0->f1348)->h14 = ((Q4Wd *)D_800E59E0->f1348)->h14 - ((Q4Wd *)D_800E59E0->f1348)->h18;
    D_800E59E0->f134C = ((Q4Wd *)D_800E59E0->f1348)->h18 / 4;
    t = ((Q4Wd *)D_800E59E0->f1348)->h18 - D_800E59E0->f134C * 4;
    ((Q4Wd *)D_800E59E0->f1348)->h14 = ((Q4Wd *)D_800E59E0->f1348)->h14 + t;
    D_800E59E0->f1350 = func_0040ECB0((void *)a, 0xF6);
    ((Q4Wd *)D_800E59E0->f1350)->h14 = ((Q4Wd *)D_800E59E0->f1350)->h14 + ((Q4Wd *)D_800E59E0->f1350)->h18;
    D_800E59E0->f1354 = ((Q4Wd *)D_800E59E0->f1350)->h18 / 4;
    t = ((Q4Wd *)D_800E59E0->f1350)->h18 - D_800E59E0->f1354 * 4;
    ((Q4Wd *)D_800E59E0->f1350)->h14 = ((Q4Wd *)D_800E59E0->f1350)->h14 - t;
    func_0040ECB0((void *)a, 0xCB)->b10 = 0x6E;
    D_800E59E0->f1360 = func_00419ED4(0xC9, 0xFF);
    w = func_0040ECB0((void *)a, 0xC9);
    D_800E59E0->f1364 = w;
    func_0040E958(w, 0);
    p = D_800E59E0;
    for (i = 0; i < 4; i++) {
        e = &D_80146398[i];
        if (e->b78 == 1) {
            s = e->b80;
            switch (s) {
            case 14:
            case 17:
            case 18:
                p->row[i].f4CC = 0;
                break;
            default:
                p->row[i].f4CC = 2;
                break;
            }
        }
    }
    func_0043BB4C();
    for (i = 0; i < 4; i++) {
        e = &D_80146398[i];
        if (e->b78 == 1) {
            func_0043B2AC(i);
        }
    }
    D_800E59E0->f1368 = -1;
    func_002A338C();
    return 0;
}
