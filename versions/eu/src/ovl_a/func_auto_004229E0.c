#include "o03_types.h"

typedef struct EuCfg2 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ s32 f10;
    /* 0x014 */ u8 pad14[7];
    /* 0x01B */ u8 f1B;
    /* 0x01C */ u8 pad1C[3];
    /* 0x01F */ u8 f1F;
    /* 0x020 */ u8 pad20[0x560];
    /* 0x580 */ u8 f580;
    /* 0x581 */ u8 lang;
} EuCfg2;
extern O3Words *D_auto_800F0B30;
extern EuCfg2 D_801462C8;
extern char *D_auto_800E1C14[];
extern char *D_auto_800E1C34[];
extern char *D_auto_800E1C44[];
extern char *D_auto_800E1C54[];
extern char *D_auto_800E1C64[];
extern char *D_auto_800E1C74[];
extern char *D_auto_800E1C84[];
extern char *D_auto_800E1C94[];
void *func_00252FFC(s32 size);
s32 func_00265370();
s32 func_auto_0041A294(s32 a, s32 b);
s32 func_auto_0041A6C0(s32 a, s32 b);
s32 func_auto_0041A9C0(s32 a, s32 b, s32 c);
s32 func_auto_0041B000(s32 a, s32 b);
void func_auto_0041AB2C(s32 o, s32 v);
void func_auto_0041B150(s32 o, s32 i);
void func_auto_0041B174(s32 o, char *s);
void func_auto_0041B550(s32 id);
s32 func_auto_004229E0(void) {
    EuCfg2 *g;
    s32 t;
    D_auto_800F0B30 = func_00252FFC(0x28);
    D_auto_800F0B30->w[0] = func_auto_0041A6C0(0x4D, 0x4E);
    func_auto_0041B550(0x57);
    func_auto_0041B550(0x58);
    D_auto_800F0B30->w[3] = func_auto_0041B000(0x59, 0x5A);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0B30->w[3], D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0B30->w[3], D_auto_800E1C34[g->lang]);
    func_auto_0041B174(D_auto_800F0B30->w[3], D_auto_800E1C44[g->lang]);
    func_auto_0041B150(D_auto_800F0B30->w[3], g->f1B);
    D_auto_800F0B30->w[4] = func_auto_0041B000(0x55, 0x56);
    func_auto_0041B174(D_auto_800F0B30->w[4], D_auto_800E1C54[g->lang]);
    func_auto_0041B174(D_auto_800F0B30->w[4], D_auto_800E1C64[g->lang]);
    func_auto_0041B150(D_auto_800F0B30->w[4], g->f1F);
    D_auto_800F0B30->w[5] = func_auto_0041B000(0x51, 0x52);
    func_auto_0041B174(D_auto_800F0B30->w[5], D_auto_800E1C74[g->lang]);
    if (func_00265370() != 0x400000) {
        func_auto_0041B174(D_auto_800F0B30->w[5], D_auto_800E1C84[g->lang]);
        func_auto_0041B174(D_auto_800F0B30->w[5], D_auto_800E1C94[g->lang]);
    }
    func_auto_0041B150(D_auto_800F0B30->w[5], g->f580);
    D_auto_800F0B30->w[2] = func_auto_0041A9C0(0x53, 0x54, 0x80);
    func_auto_0041AB2C(D_auto_800F0B30->w[2], g->f10);
    func_auto_0041B550(0x50);
    t = func_auto_0041A294(0x4F, 0x6E);
    D_auto_800F0B30->w[9] = 3;
    D_auto_800F0B30->w[1] = t;
    D_auto_800F0B30->w[8] = -1;
    return 0;
}
