#include "common.h"

typedef struct EuScreen { u8 pad0[0x14]; s32 unk14; } EuScreen;
typedef struct EuTextEntry { s32 id; char **text; } EuTextEntry;
typedef struct EuRequest { s32 id; s32 variant; s32 unk8; s32 variantC; char name[12]; } EuRequest;

extern u8 D_auto_80152789;
extern EuScreen *D_auto_800EFFE0;
extern EuTextEntry D_auto_800EFE3C[][17];
extern EuRequest D_auto_8015DCF0[];
extern void func_0029A73C();
extern s32 func_0029A9A0(s32);
extern s32 func_auto_0041F0F8(s32, s32);
extern void func_002A125C(char *, char *);
extern void func_auto_0041E878(s32);
extern void func_0025DF54(s32);

s32 func_auto_0041E550(void *arg0, void *arg1, void *arg2, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) {
        return 0;
    }
    func_0029A73C();
    if (func_0029A9A0(0) == 0x16) {
        return 0;
    }
    variant = D_auto_8015DCF0[D_auto_800EFFE0->unk14].variant;
    model = func_auto_0041F0F8(variant, D_auto_8015DCF0[D_auto_800EFFE0->unk14].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) {
                model = 16;
            }
        }
        id = D_auto_800EFE3C[variant][model].id;
    } while (id == -1);
    D_auto_8015DCF0[D_auto_800EFFE0->unk14].variant = variant;
    D_auto_8015DCF0[D_auto_800EFFE0->unk14].id = id;
    func_002A125C(D_auto_8015DCF0[D_auto_800EFFE0->unk14].name,
        D_auto_800EFE3C[variant][id].text[D_auto_80152789]
    );
    D_auto_8015DCF0[D_auto_800EFFE0->unk14].variantC = variant;
    func_auto_0041E878(D_auto_800EFFE0->unk14);
    func_0025DF54(0xE81);
    return 0;
}
