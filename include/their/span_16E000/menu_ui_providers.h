#ifndef MENU_UI_PROVIDERS_H
#define MENU_UI_PROVIDERS_H
#include "../types.h"
typedef struct MenuOption {
    u8 unobserved0[8];
    s32 flags;
    u8 unobservedC[8];
    s32 resource;
} MenuOption;
typedef struct MenuOptionBox {
    s32 field0;
    s32 width;
    s32 height;
    f32 scaleX;
    f32 scaleY;
    s32 left;
    s32 field18;
    s32 top;
} MenuOptionBox;
typedef struct MenuOptionFade {
    u8 unobserved0[0x30];
    f32 fade;
    f32 alpha;
    s32 field38;
    s32 highlighted;
} MenuOptionFade;
/* The retained match-state consumers identify the same resident root:
 * US-rev1 D_80145088, input byte +0x125D, status word +0x180C.
 * These are persistent state fields, with the actual root storage between. */
typedef struct MenuMatchGlobals {
    u8 unobserved0[0x125D];
    u8 menuInput;
    u8 unobserved125E[0x17F0 - 0x125E];
    s32 status[8];
} MenuMatchGlobals;
extern MenuMatchGlobals D_80145088;
#define D_801462E5 D_80145088.menuInput
#define D_80146894 D_80145088.status[7]
extern s32 D_800E1E20;
extern f32 D_800DE47C_de;
extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
#endif
