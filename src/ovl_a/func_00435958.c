#include "span_16E000/code_80434F4C.h"
/* Enters the selected menu state and resolves the default destination from the game mode. */
#include "types.h"
#include "common/unused.h"


extern State_func_8043577C_de *D_800E54A4;


extern void func_802A2394_de(void);
void func_8043577C_de(s32 arg0) {
    s32 var_v0;

    func_802A2394_de();
    D_800E54A4->unk4C = 5;
    D_800E54A4->unk50 = 4;
    D_800E54A4->unk3470 = arg0;
    if (arg0 == -2) {
        switch(D_801462D5) {
        case 0:D_800E54A4->unk3470=7;break;
        case 2:D_800E54A4->unk3470=7;break;
        case 1:D_800E54A4->unk3470=9;break;
        case 3:D_800E54A4->unk3470=7;break;
        case 4:D_800E54A4->unk3470=10;break;
        }
    }
}
