#include "common.h"

typedef struct EuCfg {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ s32 f10;
    /* 0x014 */ u8 pad14[7];
    /* 0x01B */ u8 f1B;
    /* 0x01C */ u8 pad1C[0x564];
    /* 0x580 */ u8 f580;
    /* 0x581 */ u8 lang;
} EuCfg;
typedef struct EuMenu { s32 w[4]; } EuMenu;

extern EuMenu *D_auto_800F0B34;
extern EuCfg D_801462C8;
extern char *D_auto_800E1C14[];
extern char *D_auto_800E1C34[];
extern char *D_auto_800E1C44[];
extern char *D_auto_800E1C74[];
extern char *D_auto_800E1C84[];
extern char *D_auto_800E1C94[];
void *func_00252FFC(s32 size);
s32 func_00265370();
void func_002A338C(void);
s32 func_auto_0041A9C0(s32 a, s32 b, s32 c);
void func_auto_0041AB2C(s32 o, s32 v);
s32 func_auto_0041B000(s32 a, s32 b);
void func_auto_0041B150(s32 o, s32 i);
void func_auto_0041B174(s32 o, char *s);
void func_auto_0041B550(s32 id);
s32 func_auto_00422C58(void) {
    EuCfg *g;
    D_auto_800F0B34 = func_00252FFC(0x10);
    func_auto_0041B550(0x1BD);
    func_auto_0041B550(0x1C2);
    D_auto_800F0B34->w[1] = func_auto_0041B000(0x1BB, 0x1BC);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0B34->w[1], D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0B34->w[1], D_auto_800E1C34[g->lang]);
    func_auto_0041B174(D_auto_800F0B34->w[1], D_auto_800E1C44[g->lang]);
    func_auto_0041B150(D_auto_800F0B34->w[1], g->f1B);
    D_auto_800F0B34->w[2] = func_auto_0041B000(0x1BE, 0x1BF);
    func_auto_0041B174(D_auto_800F0B34->w[2], D_auto_800E1C74[g->lang]);
    if (func_00265370() != 0x400000) {
        func_auto_0041B174(D_auto_800F0B34->w[2], D_auto_800E1C84[g->lang]);
        func_auto_0041B174(D_auto_800F0B34->w[2], D_auto_800E1C94[g->lang]);
    }
    func_auto_0041B150(D_auto_800F0B34->w[2], g->f580);
    D_auto_800F0B34->w[0] = func_auto_0041A9C0(0x1C0, 0x1C1, 0x80);
    func_auto_0041AB2C(D_auto_800F0B34->w[0], g->f10);
    func_auto_0041B550(0x1C3);
    func_auto_0041B550(0x1C4);
    D_auto_800F0B34->w[3] = 0;
    func_002A338C();
    return 0;
}
