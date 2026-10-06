#include "b08_types.h"

typedef struct ObjRGB {
    u8 pad0[0x520];
    u8 r;
    u8 g;
    u8 b;
} ObjRGB;

extern s32 D_801462C8;

void func_002391E8(ObjRGB *o, u8 *r, u8 *g, u8 *b) {
    if (D_801462C8 & 0x4000) {
        *r = 0;
        *g = 0;
        *b = 0;
        return;
    }
    *r = o->r & 0xF8;
    *g = o->g & 0xF8;
    *b = o->b & 0xF8;
}
