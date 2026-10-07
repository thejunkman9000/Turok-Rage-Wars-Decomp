#include "o05_types.h"
typedef struct { void *f0; u8 p4[4]; void *f8; void *fC; void *f10; void *f14; void *f18; } O05M90;
extern O05M90 *D_800E5690;
extern O05R150 D_80146410[];
extern O05Rec D_80102B00[];
void func_0041AD90(void *w, s32 v);
void func_0041A76C(void *w, s32 v);

void func_00436898(s32 i) {
    ((u8 *)D_80146410)[i * 150 + 7] = i;
    func_0041AD90(D_800E5690->f14, D_80102B00[i].b189);
    func_0041AD90(D_800E5690->f10, D_80102B00[i].b18A);
    func_0041A76C(D_800E5690->f8, D_80102B00[i].b18B);
    func_0041A76C(D_800E5690->fC, D_80102B00[i].b18C);
    func_0041AD90(D_800E5690->f18, D_80102B00[i].b18D);
}
