#include "o02_types.h"
typedef struct { u8 pad0[0x484]; void **p484; void **p488; u8 pad48C[0x49C - 0x48C]; } S_obj;
typedef struct { s32 id; s16 cnt; s16 pad; } S_e;
typedef struct { u8 pad[4]; s32 flags; u8 pad2[0x1C-8]; } S_o;
typedef struct { s16 n; u8 pad[0x46]; s32 mode; } S_v;
typedef struct {
    s32 h;                      /* 0x000 */
    u8 pad4[0x260 - 4];
    void *p260, *p264, *p268, *p26C;
    s16 n20; u8 pad272[2];
    void *p274, *p278, *p27C, *p280, *p284, *p288, *p28C, *p290, *p294, *p298, *p29C, *p2A0, *p2A4;
} S_G;
extern S_G D_801539B0;
extern S_obj *D_80153C28;
extern S_e *D_80153C18;
extern S_o *D_80153C10;
extern s16 D_80153C0C;
extern s16 D_80153C20;
void func_00411B70(s32 i);
void func_0040F600(void);
void func_002A1EB0(s32 h);
void func_00411964(s32 a);
void func_00410E9C(s32 a);
void func_00254784(void *p);
void func_00411D98(void);
void func_002A1748(void *p, s32 v, s32 n);
void func_0041023C(void) {
    s32 i, j;
    S_e *q;
    for (i = 0; i < D_80153C0C; i++) {
        if (D_80153C10[i].flags & 1) {
            S_e *e = D_80153C18 + i;
            if (e->id != -1 && e->cnt == 0) {
                func_00411B70(i);
            }
        }
    }
    func_0040F600();
    if (D_801539B0.h) func_002A1EB0(D_801539B0.h);
    func_00411964(1);
    func_00410E9C(1);
    if (D_801539B0.p260) func_00254784(D_801539B0.p260);
    func_00411D98();
    for (j = 0; j < D_801539B0.n20; j++) {
        if (D_80153C28[j].p488) {
            func_00254784(*D_80153C28[j].p488);
            func_00254784(D_80153C28[j].p488);
        }
        func_00254784(*D_80153C28[j].p484);
        func_00254784(D_80153C28[j].p484);
    }
    if (D_801539B0.p26C) func_00254784(D_801539B0.p26C);
    if (D_801539B0.p278) func_00254784(D_801539B0.p278);
    if (D_801539B0.p274) func_00254784(D_801539B0.p274);
    if (D_801539B0.p2A0) func_00254784(D_801539B0.p2A0);
    if (D_801539B0.p268) func_00254784(D_801539B0.p268);
    if (D_801539B0.p294) func_00254784(D_801539B0.p294);
    if (D_801539B0.p298) func_00254784(D_801539B0.p298);
    if (D_801539B0.p264) func_00254784(D_801539B0.p264);
    if (D_801539B0.p29C) func_00254784(D_801539B0.p29C);
    if (D_801539B0.p288) func_00254784(D_801539B0.p288);
    if (D_801539B0.p28C) func_00254784(D_801539B0.p28C);
    if (D_801539B0.p280) func_00254784(D_801539B0.p280);
    func_002A1748(&D_801539B0, 0, 0x2A8);
}
