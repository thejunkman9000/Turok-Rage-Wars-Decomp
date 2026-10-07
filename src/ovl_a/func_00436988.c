#include "o05_types.h"

typedef struct { void *f0; u8 p4[4]; void *f8; void *fC; void *f10; void *f14; void *f18; } O05M90;
typedef struct { u8 pad[0x79]; u8 b79; u8 b7A; u8 b7B; u8 pad7C; u8 b7D; u8 pad7E[4]; u8 b82; u8 pad83[0x96 - 0x83]; } O05R150b;
extern O05M90 *D_800E5690;
extern O05R150b D_80146398[];
extern O05Rec D_80102B00[];
s32 func_0041AD84(void *w);
s32 func_0041A760(void *w);

void func_00436988(s32 k) {
    O05R150b *r = &D_80146398[k];
    D_80102B00[k].b189 = func_0041AD84(D_800E5690->f14);
    D_80102B00[k].b18A = func_0041AD84(D_800E5690->f10);
    D_80102B00[k].b18B = func_0041A760(D_800E5690->f8);
    D_80102B00[k].b18C = func_0041A760(D_800E5690->fC);
    D_80102B00[k].b18D = func_0041AD84(D_800E5690->f18);
    r->b7B = D_80102B00[k].b189;
    r->b7D = D_80102B00[k].b18A;
    r->b79 = D_80102B00[k].b18B;
    r->b7A = D_80102B00[k].b18C;
    r->b82 = D_80102B00[k].b18D;
}
