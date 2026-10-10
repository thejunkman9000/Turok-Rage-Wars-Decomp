#include "span_1000/code_802A8A94.h"
#include "types.h"

extern f32 D_800CB3A8;
extern f32 D_800CB3B0;
extern f32 D_800C6214_de;
extern f32 D_800C621C_de;
extern f32 D_800C6224_de;



/** Return the floating parameter selected by the current global mode. */
f32 func_802AA864_de(void) {
    {
        s32 sw_mode_value = D_80147150;
        if ((unsigned int)sw_mode_value > 6) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_3;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_4;
        case 6: goto sw_mode_2;
        }
    }
    do {
    sw_mode_0:
        return D_800C6214_de;
    sw_mode_1:
        return D_800CB3A8;
    sw_mode_2:
    sw_mode_6:
        return D_800C621C_de;
    sw_mode_3:
        return D_800CB3B0;
    sw_mode_4:
    sw_mode_5:
        return D_800C6224_de;
    sw_mode_default:
        return D_800C6228_de;
    
    } while (0);
}
