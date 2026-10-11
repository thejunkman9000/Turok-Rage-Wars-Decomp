/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044972C_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"






























/* Starts a player's run: in a multiplayer session (D_801462E5) picks the lap count from the chosen track through func_0022F444 in mode 1 or from the loaded course in mode 4 for a human player, sets the run type at 0x5EA (1, or 3 in single player), clears 0x13C8 and 0x85C around func_0044A17C, then starts its vehicle through func_0021B1E4 with model 0xC1D for a computer player in state 12 during stage 9 and its own model otherwise, doubled when D_80145048 is two or more. */






extern u8 D_801462E5;
extern u8 D_801462D5;
extern char D_80102B00[];
extern Course *D_800E4680;
extern s32 D_8013B294;

extern s32 func_0022F444(char *, s32);
extern void func_0044A17C(SharedPlayer_func_8044972C_de *);
extern void func_0021B1E4(SharedPlayer_func_8044972C_de *, s32, s32, s32);

void func_0044A37C(SharedPlayer_func_8044972C_de *player) {
    s32 scale;

    scale = (D_80145048 >= 2) * 2;
    if (D_801462E5 != 0) {
        if (D_801462D5 == 1 && player->views1450.view1450_1.computer == 0) {
            player->views133C.view133C_1.laps = ((u8)func_0022F444(D_80102B00 + player->views1C.view5D4_46.slot * 0x190, player->views5D8.view5D8_1.record->unk80) >> 1) + 1;
        }
        if (D_801462D5 == 4 && player->views1450.view1450_1.computer == 0 && D_800E4680 != 0) {
            player->views133C.view133C_1.laps = D_800E4680->laps;
        }
        player->views5E8.view5EA_4.runType = 1;
    } else {
        player->views5E8.view5EA_4.runType = 3;
    }
    player->views13C8.view13C8_1.w13C8 = 0;
    func_0044A17C(player);
    player->views5E8.view85C_120.w85C = 0;
    if (player->views5DC.view5E0_9.state == 12 && player->views1450.view1450_1.computer != 0 && D_8013B294 == 9) {
        func_0021B1E4(player, 0xC1D, scale, 1);
    } else {
        func_0021B1E4(player, player->views5E8.view5EC_6.model, scale, 1);
    }
}
