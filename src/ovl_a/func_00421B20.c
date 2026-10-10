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

/* Builds the screen state D_800E4450: allocates it, opens screen 0x39E, registers six resources, opens window 0x3A0 and stores the 0x3A1 label. */
s32 func_80421AE8_de(s32 arg0) {
    s32 screen;
    struct Window_func_80421AE8_de *window;

    D_800E4450 = func_8025305C_de(0x14);
    func_802A2360_de();
    screen = func_8041A280_de(0x39E, 0x39F);
    D_800E4450->screen = screen;
    func_8041A47C_de(screen);
    func_8041B110_de(0x3A5);
    func_8041B110_de(0x3A4);
    func_8041B110_de(0x3A7);
    func_8041B110_de(0x3A3);
    func_8041B110_de(0x3A2);
    func_8041B110_de(0x3A6);
    window = func_8040EC30_de(arg0, 0x3A0);
    D_800E4450->window = window;
    window->unk10 = 0xF;
    D_800E4450->label = func_80419E54_de(0x3A1, 0x6E);
    D_800E4450->state = 3;
    return 0;
}
