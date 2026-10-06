#include "common.h"

typedef struct { u32 pad0; u32 flags4; u32 flags8; void *buf; s32 mode; } VSwap;

s32 func_0028F9EC(s32 unused, VSwap *s) {
    if ((s->flags4 & 3) != 0) {
        return 0;
    }
    if (s->mode == 1 && (s->flags8 & 0x60) == 0x60) {
        osViSwapBuffer(s->buf);
    }
    return 1;
}
