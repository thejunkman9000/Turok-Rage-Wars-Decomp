#include "o02_types.h"
/* NOTE: D_80153C48 is declared `* volatile` only to reproduce the ROM pointer reloads (see FINDINGS) */
typedef struct { s32 off; s32 cnt; void *p; } S12;
typedef struct {
    s32 h;               /* 0x000 */
    u8 b4[0x23C];        /* 0x004: object handed to func_002A1E8C */
    s32 f240;            /* 0x240 */
} S_G;
extern S_G D_801539B0;
extern S12 *D_80153C44;
extern S12 * volatile D_80153C48;
extern u16 *D_80153C50;
extern s32 D_80153C54;
extern s32 D_800E2AC4;
extern char D_800E10E0[];
void func_002A1724(void *d, void *s, s32 n);
void func_0040F75C(void *a, void *b, s32 n);
f64 func_002A28CC(void);
void *func_00252FFC(s32 n);
s32 func_002A1E8C(void *obj, char *name);
void func_002A1F60(s32 h, s32 off, s32 z);
void func_002A1ED4(void *buf, s32 n, s32 c, s32 h);
void func_002A1EB0(s32 h);
void func_0041174C(s32 i) {
    D_80153C50[i]++;
    if (D_80153C54 == 1) {
        if (D_80153C44[i].p) {
            func_002A1724(D_80153C44[i].p, D_80153C48[i].p, D_80153C44[i].cnt);
            func_0040F75C(D_80153C44[i].p, D_80153C44[i].p, D_80153C44[i].off - D_80153C44[0].off);
        }
    }
    if (D_80153C44[i].p == 0) {
        func_002A28CC();
        D_80153C44[i].p = func_00252FFC(D_80153C44[i].cnt);
        D_801539B0.h = func_002A1E8C(D_801539B0.b4, D_800E10E0);
        func_002A1F60(D_801539B0.h, D_801539B0.f240 + D_80153C44[i].off, 0);
        func_002A1ED4(D_80153C44[i].p, D_80153C44[i].cnt, 1, D_801539B0.h);
        if (D_800E2AC4) {
            *(s32 *)&D_80153C48[i].p = (s32)func_00252FFC(D_80153C44[i].cnt);
            func_002A1724(D_80153C48[i].p, D_80153C44[i].p, D_80153C44[i].cnt);
        }
        func_002A1EB0(D_801539B0.h);
        D_801539B0.h = 0;
        func_0040F75C(D_80153C44[i].p, D_80153C44[i].p, D_80153C44[i].off - D_80153C44[0].off);
        func_002A28CC();
    }
}
