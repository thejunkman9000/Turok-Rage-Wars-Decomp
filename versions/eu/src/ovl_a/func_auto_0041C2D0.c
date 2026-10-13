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

extern u8 D_auto_80152789;
extern s32 D_auto_800E25A4[];
extern s32 func_00264634(s32);
extern void func_00299368(s32);
extern void func_0029A1D4(s32);
extern void func_0029A73C(void);
extern void func_002A3358(void);
extern s32 func_002A1C08(void *, const char *, ...);
extern s32 func_auto_00404BF8(s32, s32, s32 *);
extern s32 func_auto_00404F14(s32);
extern s32 func_auto_004360B0(s32, u32 *);
extern void func_auto_00404E38(s32);
extern void func_auto_0040ED18(s32, s32);
extern void func_auto_0041C694(void);
extern void func_auto_00435CE0(s32);
extern void func_auto_0041C5EC(void);
extern EuLabel *func_auto_0040F070(s32, s32);
extern s32 D_auto_800EEEEC, D_auto_800EFB30, D_auto_8011B190, D_auto_80152CA0, D_auto_80156CD4;
extern char D_auto_800EDAD0[];
extern s32 D_auto_800EFB34;
extern EuSlotDialog *D_auto_800EFB38;

void func_auto_0041C2D0(void) {
    s32 sp10;
    u32 sp14;
    s32 var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    EuLabel *temp_s0;

    func_0029A1D4(962);
    func_auto_0040ED18(D_auto_800EFB38->absent, 0);
    var_s2 = 0;
    func_auto_0040ED18(D_auto_800EFB38->unavailable, 0);
    var_s1 = 1;
    func_auto_0040ED18(D_auto_800EFB38->prompt, 0);
    temp_v0 = func_00264634(0);
    if (temp_v0 == 1) {
        func_auto_0041C5EC();
        if (D_auto_800EFB38->ready == 1) {
            func_auto_00404E38(D_auto_800EFB30);
            temp_v0_2 = func_auto_00404F14(D_auto_800EFB30);
            switch (temp_v0_2) {
            case 0:
                if ((func_auto_00404BF8(((D_auto_800E25A4)[D_auto_80152789]), D_auto_800EFB30, &sp10) == 0) && (func_auto_004360B0(D_auto_800EFB30, &sp14) == 0)) {
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
        D_auto_800EFB38->state = 1;
        D_auto_800EFB38->elapsed = 0;
        func_auto_0040ED18(D_auto_800EFB38->main, 0);
        func_auto_0040ED18(D_auto_800EFB38->unavailable, 1);
        goto block_25;
    }
    if (D_auto_800EFB38->ready == 0) {
        D_auto_800EFB38->state = 2;
        D_auto_800EFB38->elapsed = 0;
        func_auto_0040ED18(D_auto_800EFB38->main, 0);
        func_auto_0040ED18(D_auto_800EFB38->absent, 1);
        var_a0 = 971;
        goto block_24;
    }
    if ((var_s2 == 1) || (D_auto_8011B190 & 0x1000)) {
        func_0029A73C();
        D_auto_80152CA0 = 1;
        D_auto_800EEEEC = 1;
        D_auto_80156CD4 = 0;
        if (var_s2 == 0) {
            D_auto_800EFB34 = 0;
        } else {
            D_auto_800EFB34 = 2;
        }
        func_auto_00435CE0(6);
        func_00299368(0x13);
        return;
    }
    if (var_s1 == 1) {
        func_auto_0041C694();
        return;
    }
    temp_s0 = func_auto_0040F070(D_auto_800EFB38->root, 968);
    func_002A1C08(D_auto_800EFB38->text, D_auto_800EDAD0, D_auto_800EFB30 + 1);
    temp_s0->text = D_auto_800EFB38->text;
    D_auto_800EFB38->state = 3;
    D_auto_800EFB38->elapsed = 0;
    func_auto_0040ED18(D_auto_800EFB38->main, 0);
    func_auto_0040ED18(D_auto_800EFB38->prompt, 1);
    var_a0 = 966;
block_24:
    func_0029A1D4(var_a0);
block_25:
    func_002A3358();
}
