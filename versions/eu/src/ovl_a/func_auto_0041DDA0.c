#include "common.h"

typedef struct EuLabel { u8 pad0[0x38]; char *text; } EuLabel;
typedef struct EuFocus { u8 pad0[0xC]; s16 unkC; } EuFocus;
typedef struct EuMenu {
    u8 pad0[0xEC];
    EuFocus *focus;
    EuLabel *label;
    u8 padF4[0x18];
    s32 player;
} EuMenu;
typedef struct EuTextEntry { s32 id; char **text; } EuTextEntry;
typedef struct EuPlayerRecord { u8 data[0x190]; } EuPlayerRecord;
typedef struct EuGame { u8 pad0[0x17C1]; u8 language; } EuGame;

extern EuGame D_80145088;
extern EuMenu *D_auto_800EFBB0;
extern EuTextEntry D_auto_800EFBB4[];
extern EuPlayerRecord D_auto_8010EB4A[];
extern char D_auto_800EDB48[];
extern s32 func_00265670(EuPlayerRecord *bits, s32 bit);

void func_auto_0041DDA0(void) {
    s32 i;
    if (D_auto_800EFBB0->focus == 0) {
        D_auto_800EFBB0->label->text = D_auto_800EDB48 + 4;
        return;
    }
    for (i = 0; i < 50; i++) {
        if (D_auto_800EFBB4[i].id == D_auto_800EFBB0->focus->unkC) {
            if (func_00265670(&D_auto_8010EB4A[D_auto_800EFBB0->player], i) == 1) {
                D_auto_800EFBB0->label->text = D_auto_800EFBB4[i].text[D_80145088.language];
            } else {
                D_auto_800EFBB0->label->text = D_auto_800EDB48 + 4;
            }
            return;
        }
    }
}
