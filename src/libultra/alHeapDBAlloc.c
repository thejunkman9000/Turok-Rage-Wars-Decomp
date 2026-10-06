#include "libaudio.h"

void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size) {
    void *ptr = 0;
    s32 bytes = (num * size + 0xF) & ~0xF;
    if (hp->cur + bytes <= hp->base + hp->len) {
        ptr = hp->cur;
        hp->cur += bytes;
    }
    return ptr;
}
