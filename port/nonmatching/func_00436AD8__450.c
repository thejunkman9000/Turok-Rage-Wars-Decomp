#include "o05_types.h"

typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; } O05M94;
extern O05M94 *D_800E5694;
extern O05R150 D_80146410[];
extern O05Rec D_80102B00[];
void func_0041AD90(void *w, s32 v);
void func_0041A76C(void *w, s32 v);

void func_00436AD8(s32 i) {
    D_80146410[i].b7 = i;
    func_0041AD90(D_800E5694->fC, D_80102B00[i].b189);
    func_0041AD90(D_800E5694->f8, D_80102B00[i].b18A);
    func_0041A76C(D_800E5694->f0, D_80102B00[i].b18B);
    func_0041A76C(D_800E5694->f4, D_80102B00[i].b18C);
    func_0041AD90(D_800E5694->f10, D_80102B00[i].b18D);
}
