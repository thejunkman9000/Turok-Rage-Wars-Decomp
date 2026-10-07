#include "o03_types.h"
extern O3Pj *D_800E42D0;
typedef struct { O3Id a[3]; O3Id b[3]; O3Id c[3]; } Q2IdRow;
extern Q2IdRow D_800E42D4[];
typedef struct { u8 pad0[0x78]; u8 f78; u8 pad79[6]; u8 f7F; u8 f80; u8 f81; u8 pad82[0x91 - 0x82]; u8 f91; u8 pad92[4]; } Q2Ent96;
extern Q2Ent96 D_80146398[];
extern u8 D_801462D5;
extern u8 D_80102B0F[];
void func_0040E958(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, u16 id);
void func_0041B834();
void func_0041CE80(void *p, s32 v);
s32 func_0041F1FC(s32 key);
s32 func_0041F248(s32 key);
void func_00299368(s32 a);
static inline O3Pj *pj(s32 i) { return &D_800E42D0[i]; }
void func_00420688(s32 idx, s32 val) {
    s32 i, j, n, a;
    s8 r;
    Q2Ent96 *e;
    u8 *c;
    pj(idx)->state = 3;
    func_0041B834(D_800E42D0->menu, idx, 1);
    *(s32 *)((u8 *)pj(idx) + 0x4C8) = 1;
    i = 0;
    do {
        func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].c[i].id), 1);
        i++;
    } while (i < 3);
    pj(idx)->f10 = val;
    func_0041F1FC(val);
    func_0041CE80(D_800E42D0[idx].sub, 0);
    n = 0;
    for (j = 0; j < 4; j++) {
        if ((u32)(D_800E42D0[j].state - 1) < 2) {
            n++;
        }
    }
    if (n == 0) {
        e = D_80146398;
        c = (u8 *)D_80146398 - 0xD0;
        for (i = 0; i < 8; i++) {
            e = &D_80146398[i];
            e->f78 = 0;
            if (pj(i)->state == 3) {
                e->f91 = 0;
                e->f78 = 1;
                e->f7F = i;
                r = func_0041F248(pj(i)->f10);
                e->f80 = r;
                if (c[0xD] == 1) {
                    D_80102B0F[i * 0x190] = r;
                }
                e->f81 = *((u8 *)pj(i) + 0x1B);
            }
        }
        a = 8;
        if (D_801462D5 == 1) {
            a = 0xA;
        }
        func_00299368(a);
    }
}
