#include "b12_types.h"

typedef struct B12Elem { u8 pad[0xE8]; } B12Elem;
typedef struct B12Tbl {
    u8 pad0[4];
    s32 count;
    B12Elem elem[1];
} B12Tbl;

B12Tbl *func_0028FD94(s32 key, s32 flag);

s32 func_002508E0(B12Elem *elem, s32 key) {
    B12Tbl *t;
    s32 idx = -1;
    s32 i;
    s32 off;
    u8 *base;
    s32 n;
    t = func_0028FD94(key, 0);
    i = 0;
    base = (u8 *)t->elem;
    n = t->count;
    off = i;
    for (; i < n; i++, off += 0xE8) {
        if (base + off == (u8 *)elem) {
            idx = i;
            break;
        }
    }
    return idx;
}
