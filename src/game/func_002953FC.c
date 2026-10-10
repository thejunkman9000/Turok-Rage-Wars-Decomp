#include "span_1000/code_80294C64.h"
#include "types.h"

extern s32 D_800D2AE0;
extern s32 D_8014AEC8;
extern s32 D_8014AED0;
extern s32 D_8014AED4;
extern s32 D_8014AED8;





/** Decode a frontend input selector into its current button mask. */
s32 func_802953FC_us_rev1(s32 arg0) {
    if (D_800D2AE0 == 0) {
        goto zero;
    }

    {
        s32 sw_outer_value = arg0;
        sw_outer_value -= (257);
        if ((unsigned int)sw_outer_value > 5) {
            goto sw_outer_default;
        }
        switch (sw_outer_value) {
        case 0: goto sw_outer_0x101;
        case 1: goto sw_outer_0x102;
        case 2: goto sw_outer_0x103;
        case 3: goto sw_outer_0x104;
        case 4: goto sw_outer_0x105;
        case 5: goto sw_outer_0x106;
        }
    }
    do {
    sw_outer_0x101:
        return D_8014AED4;
    sw_outer_0x102:
        return D_8014AED8;
    sw_outer_0x103:
        return 1 << ((func_802953FC_S1 *)(D_8014AED0))->unk2;
    sw_outer_0x104:
        return 1 << ((func_802953FC_S1 *)(D_8014AED0))->unk3;
    sw_outer_0x105:
        {
        s32 sw_inner_value = *(u8 *)D_8014AED0;
        if ((unsigned int)sw_inner_value > 5) {
            goto zero;
        }
        switch (sw_inner_value) {
        case 0: goto sw_inner_0;
        case 1: goto sw_inner_1;
        case 2: goto sw_inner_2;
        case 3: goto sw_inner_1;
        case 4: goto sw_inner_4;
        case 5: goto sw_inner_1;
        }
    }
    do {
        sw_inner_0:
            return 8;
        sw_inner_1:
        sw_inner_3:
        sw_inner_5:
            return 4;
        sw_inner_2:
            return 0x20;
        sw_inner_4:
            return 0x10;
    } while (0);
    sw_outer_0x106:
        D_8014AEC8 = 1;
zero:
        return 0;
    sw_outer_default:
        return 0;
    } while (0);
}
