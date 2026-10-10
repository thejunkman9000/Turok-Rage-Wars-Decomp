#ifndef S407_TYPES_H
#define S407_TYPES_H

#include "common.h"

/* Types recovered in workspace s407 (hard leftover functions, ROM 0x60054-0x77920). */

typedef struct S407Vec3 {
    f32 x, y, z;
} S407Vec3;

/* animation playback state (20 bytes, see M04Anim): f0 is the float time */
typedef struct S407Anim {
    /* 0x00 */ f32 t;
    /* 0x04 */ s16 cur;
    /* 0x06 */ s16 next;
    /* 0x08 */ s16 n;
    /* 0x0A */ u8 fA;
    /* 0x0B */ u8 fB;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
} S407Anim;

/* animation segment record (read through func_0028FD94) */
typedef struct S407Seg {
    /* 0x00 */ u16 w0;
    /* 0x02 */ u16 end;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ f32 speed;
} S407Seg;

/* object whose flag word is at 0x100 */
typedef struct S407Obj {
    /* 0x000 */ u8 pad0[0x100];
    /* 0x100 */ u32 flags;
} S407Obj;

#endif
