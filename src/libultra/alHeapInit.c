#include "libaudio.h"

typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} ALHeap;

void alHeapInit(ALHeap *hp, u8 *base, s32 len) {
    s32 offset;
    offset = 16 - ((u32)base & 0xF);
    if (offset != 16) {
        hp->base = base + offset;
    } else {
        hp->base = base;
    }
    hp->cur = hp->base;
    hp->len = len;
    hp->count = 0;
}
