#include "b12_types.h"
typedef struct B12Elem { u8 pad[0xE8]; } B12Elem;
typedef struct B12Tbl {
    u8 pad0[4];
    s32 count;
    B12Elem elem[1];
} B12Tbl;
B12Tbl *func_0028FD94(s32 key, s32 flag);
