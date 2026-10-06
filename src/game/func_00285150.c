

#include "common.h"
typedef struct { u32 magic; s32 unpacked; s32 packed; u8 pad[0xC]; } B19Rnc;
typedef struct { B19Rnc *data; s32 size; } B19Src2;
void *memcpy(void *, const void *, u32);
void rncUnpackMethod1(void *, s32, s32, s32);
void rncUnpackMethod2(void *, s32, s32, s32);
s32 *func_002545A0(s32, B19Src2 **, s32);
s32 *func_00254420(s32, B19Src2 **, s32);
void func_00253CB0(s32, B19Src2 **, s32 *);
s32 func_00285150(B19Src2 **a, s32 pre) {
    B19Src2 *src = *a;
    B19Rnc *r = src->data;
    s32 *dst;
    s32 ok;
    if ((r->magic & ~0xFF) == 0x524E4300) {
        if (pre != 0) dst = func_002545A0(0, a, r->unpacked);
        else dst = func_00254420(0, a, r->unpacked);
        if (dst == 0) goto bad;
        switch (((u8 *)r)[3]) {
        case 1:
            rncUnpackMethod1((u8 *)r + 0x12, *dst, r->packed, r->unpacked);
            break;
        case 2:
            rncUnpackMethod2(r, *dst, r->packed, r->unpacked);
            break;
        }
        ok = 1;
        goto tail;
    }
    ok = 1;
    if (pre == 0) {
        dst = func_00254420(0, a, src->size);
        if (dst == 0) {
            ok = 0;
            do {
                goto tail;
            } while (0);
        }
        memcpy((void *)*dst, (*a)->data, (*a)->size);
        ok = 1;
        goto tail;
bad:
        ok = 0;
tail:
        func_00253CB0(0, a, dst);
    }
    return ok;
}
