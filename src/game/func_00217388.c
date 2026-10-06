#include "b04_types.h"
void func_0025E1E4(void *);
s32 func_0025CC8C(void);
void func_0025CA44(s32, void *);
typedef struct { u8 type; u8 pad1[0xCF]; void *unkD0; u8 padD4[0x28]; void *unkFC; } B04Src;
typedef struct { u8 pad0[0xFC]; void *unkFC; } B04Dst;
void func_00217388(B04Src *src, B04Dst *d) {
    void *p = NULL;
    switch (src->type) {
    case 1: case 2: p = src; break;
    case 0: p = src->unkD0; break;
    }
    if (d->unkFC != 0) {
        func_0025E1E4(p);
        if (d->unkFC != 0) {
            func_0025CA44(func_0025CC8C(), d->unkFC);
            d->unkFC = 0;
        }
    }
}
