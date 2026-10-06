#include "b19_types.h"
extern s32 D_800D2640;
extern s32 D_800D2644;
extern f32 D_800D2988;
extern f32 D_800CA1D4;
extern u8 D_8013BA80[];
extern u8 D_80145040[];
extern B19Glo D_80145088;
extern B19Inp D_801462C8[];
extern s32 D_80146894;
void func_0025470C(s32, s32);
void func_0028A674(B19Owner *);
void func_0028D628(B19Owner *);
void func_00279A00(void *);
void func_00253B5C(s32, s32);
void func_002A66EC(void *);
void func_0022A144(void *);
void func_00287EE8(B19Owner *);
void func_00288440(B19Owner *);
void func_0028D5F8(B19Owner *);
void func_002A6670(void *);
void func_00286254(B19Owner *);
void func_00290218(void *);
void func_0028C5E8(B19Owner *);
void func_00281C74(void *);
void func_002285C4(void *);
void func_00236F0C(void *, B19Owner *);
void func_0028D658(B19Owner *);
void func_0028D864(B19Owner *);
void func_0028D0E4(B19Owner *);
void func_00286050(B19Owner *ow) {
    s32 old = D_800D2640;
    D_800D2640 = D_801462C8->val;
    if (D_801462C8->flags & 0x4000) D_800D2640 = D_801462C8->val | 0x100;
    if (D_801462C8->flags & 0x8000) D_800D2640 |= 0x200;
    if (old != D_800D2640) {
        D_800D2644 = 1;
        func_0025470C(8, old);
    } else {
        D_800D2644 = 0;
    }
    func_0028A674(ow);
    func_0028D628(ow);
    ow->f120 = 0;
    ow->f124 = 0;
    func_00279A00((u8 *)ow + 0x128);
    func_00253B5C(0, ow->fE8);
    func_002A66EC(D_8013BA80);
    func_0022A144(D_80145040);
    func_00287EE8(ow);
    func_00288440(ow);
    func_0028D5F8(ow);
    if (ow->f1B414 == 0 && D_80146894 == 0) {
        func_002A6670(D_8013BA80);
        func_00286254(ow);
        func_00290218((u8 *)ow + 0x11778);
        ow->f1B308 = ow->f1B308 + D_800D2988 * D_800CA1D4;
        func_0028C5E8(ow);
    }
    func_00281C74((u8 *)ow + 0x1B08);
    if (ow->f1B414 == 0) func_002285C4(D_80145040);
    func_00236F0C(&D_80145088, ow);
    if (ow->f1B414 == 0 && D_80145088.f180C == 0) func_0028D658(ow);
    func_0028D864(ow);
    func_0028D0E4(ow);
}
