#include "common.h"

typedef struct EuLabel { u8 pad0[0x38]; char *text; } EuLabel;
typedef struct EuSlotDialog {
    s32 root;
    s32 main;
    s32 absent;
    s32 unavailable;
    s32 prompt;
    s32 elapsed;
    s32 state;
    s32 ready;
    char text[128];
} EuSlotDialog;

extern s32 D_auto_800D36D4;
extern s32 func_00264634(s32);
extern void func_00299368(s32);
extern void func_0029A1D4(s32);
extern void func_0029A73C(void);
extern void func_002A3358(void);
extern s32 func_002A1C08(void *, const char *, ...);
extern s32 func_auto_00404BE8(s32, s32, s32 *);
extern s32 func_auto_00404F04(s32);
extern s32 func_auto_00435384(s32, u32 *);
extern void func_auto_00404E28(s32);
extern void func_auto_0040E8D8(s32, s32);
extern void func_auto_0041C244(void);
extern void func_auto_00434FB4(s32);
extern void func_auto_0041C19C(void);
extern EuLabel *func_auto_0040EC30(s32, s32);
extern s32 D_auto_800DE87C, D_auto_800DF4C0, D_auto_8010B190, D_auto_80142CA0, D_auto_80146CD4;
extern char D_auto_800DD450[];
extern s32 D_auto_800DF4C4;
extern EuSlotDialog *D_auto_800DF4C8;

void func_auto_0041BE90(void) {
    s32 sp10;
    u32 sp14;
    s32 var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    EuLabel *temp_s0;

    func_0029A1D4(956);
    func_auto_0040E8D8(D_auto_800DF4C8->absent, 0);
    var_s2 = 0;
    func_auto_0040E8D8(D_auto_800DF4C8->unavailable, 0);
    var_s1 = 1;
    func_auto_0040E8D8(D_auto_800DF4C8->prompt, 0);
    temp_v0 = func_00264634(0);
    if (temp_v0 == 1) {
        func_auto_0041C19C();
        if (D_auto_800DF4C8->ready == 1) {
            func_auto_00404E28(D_auto_800DF4C0);
            temp_v0_2 = func_auto_00404F04(D_auto_800DF4C0);
            switch (temp_v0_2) {
            case 0:
                if ((func_auto_00404BE8(D_auto_800D36D4, D_auto_800DF4C0, &sp10) == 0) && (func_auto_00435384(D_auto_800DF4C0, &sp14) == 0)) {
                    var_s1 = sp14 > 0U;
                }
                break;
            case -4:
            case -3:
            case -1:
                var_s2 = 1;
                break;
            }
        }
    }
    if (temp_v0 == 0) {
        D_auto_800DF4C8->state = 1;
        D_auto_800DF4C8->elapsed = 0;
        func_auto_0040E8D8(D_auto_800DF4C8->main, 0);
        func_auto_0040E8D8(D_auto_800DF4C8->unavailable, 1);
        goto block_25;
    }
    if (D_auto_800DF4C8->ready == 0) {
        D_auto_800DF4C8->state = 2;
        D_auto_800DF4C8->elapsed = 0;
        func_auto_0040E8D8(D_auto_800DF4C8->main, 0);
        func_auto_0040E8D8(D_auto_800DF4C8->absent, 1);
        var_a0 = 964;
        goto block_24;
    }
    if ((var_s2 == 1) || (D_auto_8010B190 & 0x1000)) {
        func_0029A73C();
        D_auto_80142CA0 = 1;
        D_auto_800DE87C = 1;
        D_auto_80146CD4 = 0;
        if (var_s2 == 0) {
            D_auto_800DF4C4 = 0;
        } else {
            D_auto_800DF4C4 = 2;
        }
        func_auto_00434FB4(6);
        func_00299368(0x13);
        return;
    }
    if (var_s1 == 1) {
        func_auto_0041C244();
        return;
    }
    temp_s0 = func_auto_0040EC30(D_auto_800DF4C8->root, 960);
    func_002A1C08(D_auto_800DF4C8->text, D_auto_800DD450, D_auto_800DF4C0 + 1);
    temp_s0->text = D_auto_800DF4C8->text;
    D_auto_800DF4C8->state = 3;
    D_auto_800DF4C8->elapsed = 0;
    func_auto_0040E8D8(D_auto_800DF4C8->main, 0);
    func_auto_0040E8D8(D_auto_800DF4C8->prompt, 1);
    var_a0 = 961;
block_24:
    func_0029A1D4(var_a0);
block_25:
    func_002A3358();
}
