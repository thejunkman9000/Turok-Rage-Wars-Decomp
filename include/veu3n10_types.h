#ifndef VEU3N10_TYPES_H
#define VEU3N10_TYPES_H
#include "common.h"

/* Europe (PAL) cheat-code entry screen (overlay A, VRAM 0x43DA10..0x43E1F0) and options menu callbacks. */

/* the code editor state at 0x800F22C0: cursor, blink timer, length, up to 23 characters */
typedef struct VeuCheatBuf {
    /* 0x00 */ s32 pos;
    /* 0x04 */ f32 timer;
    /* 0x08 */ s32 len;
    /* 0x0C */ u8 buf[24];
} VeuCheatBuf;

/* table of 12 cheat codes at 0x00450210, stride 0x10 */
typedef struct VeuCheatEnt {
    /* 0x00 */ u8 *code;      /* scrambled code string (char ^ index) */
    /* 0x04 */ void *txt;     /* text shown in the menu */
    /* 0x08 */ u32 flag;      /* bit set in the unlock word */
    /* 0x0C */ s32 snd;       /* low half = sound id (0 = none) */
} VeuCheatEnt;

/* menu item (first argument of the text / flag callbacks) */
typedef struct VeuItem {
    /* 0x00 */ s32 state;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ u32 flags;
    /* 0x0C */ u8 padC[8];
    /* 0x14 */ void *txt;
} VeuItem;

/* menu object whose first halfword is the state and +0x20 the pad/controller id */
typedef struct VeuMenuObj {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 pad2[0x1E];
    /* 0x20 */ s32 pad;
} VeuMenuObj;

/* 0x80152208: option bits, unlocked bits, ... (0x20: float, 0x581: selected line) */
typedef struct VeuGlobals8208 {
    /* 0x000 */ s32 w[8];
    /* 0x020 */ f32 f20;
    /* 0x024 */ u8 pad24[0x581 - 0x24];
    /* 0x581 */ u8 b581;
} VeuGlobals8208;

#endif
