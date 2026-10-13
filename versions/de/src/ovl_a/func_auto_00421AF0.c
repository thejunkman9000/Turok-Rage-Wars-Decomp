#include "common/unused.h"
#include "types.h"

extern void *func_8025305C_de(s32);
extern void func_802A2360_de(void);
extern struct Window_func_80421AE8_de *func_8040EC30_de(s32, s32);
extern s32 func_80419E54_de(s32, s32);
extern s32 func_8041A280_de(s32, s32);
extern void func_8041A47C_de(s32);
extern void func_8041B110_de(s32);
extern struct ScreenState *D_800E4450;

/* Builds the screen state D_800E4450: allocates it, opens screen 0x398, registers six resources, opens window 0x39A and stores the 0x39B label. */
s32 func_auto_00421AF0(s32 arg0) {
    s32 screen;
    struct Window_func_80421AE8_de *window;

    D_800E4450 = func_8025305C_de(0x14);
    func_802A2360_de();
    screen = func_8041A280_de(0x398, 0x399);
    D_800E4450->screen = screen;
    func_8041A47C_de(screen);
    func_8041B110_de(0x39F);
    func_8041B110_de(0x39E);
    func_8041B110_de(0x3A1);
    func_8041B110_de(0x39D);
    func_8041B110_de(0x39C);
    func_8041B110_de(0x3A0);
    window = func_8040EC30_de(arg0, 0x39A);
    D_800E4450->window = window;
    window->unk10 = 0xF;
    D_800E4450->label = func_80419E54_de(0x39B, 0x6E);
    D_800E4450->state = 3;
    return 0;
}
