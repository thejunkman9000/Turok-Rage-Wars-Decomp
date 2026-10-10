#include "span_1000/code_80294C64.h"
extern void *D_8014AED0;


/** Return the mode mask selected by the global record's leading byte. */
int func_80295B30_us_rev1(void) {
    {
        int sw_mode_value = *(unsigned char *)D_8014AED0;
        if ((unsigned int)sw_mode_value > 5) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_1;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_1;
        }
    }
    do {
    sw_mode_0:
        return 8;
    sw_mode_1:
    sw_mode_3:
    sw_mode_5:
        return 4;
    sw_mode_2:
        return 0x20;
    sw_mode_4:
        return 0x10;
    sw_mode_default:
        return 0;
    
    } while (0);
}
