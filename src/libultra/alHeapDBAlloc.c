#include "libaudio.h"

typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} ALHeap;

void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size) {
    void *ptr = 0;
    s32 bytes = (num * size + 0xF) & ~0xF;
    if (hp->cur + bytes <= hp->base + hp->len) {
        ptr = hp->cur;
        hp->cur += bytes;
    }
    return ptr;
}
