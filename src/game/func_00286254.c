#include "b19_types.h"
extern f32 D_800D2988;
extern u8 D_80145040[];
void func_0024BE2C(B19Obj *);
void func_00246E34(B19Obj *);
s32 func_002934DC(void);
void func_00226A10(void *);
s32 func_0022A67C(void *);
void func_0025E2F4(s32);
void func_42D190(void);
void func_438BA4(void);
void *func_0025CC8C(void);
void func_0025CBA8(void *);
void func_00286254(B19Owner *owner) {
    s32 i = 0;
    u32 t34;
    s32 n = owner->nobj;
    B19Obj *o;
    B19Obj *o2;
    B19Obj **arr = owner->arr;
    f32 sv;
    while (i < n) {
        o = arr[i];
        if (((B19Info18 *)o->info)->type != 2) break;
        i++;
        o2 = o;
        sv = D_800D2988;
        if (!(o2->flags100 & 0x40000000)) func_0024BE2C(o2);
        if ((o2->flags100 & 0x40002000) == 0x2000) func_00246E34(o);
        D_800D2988 = sv;
    }
    if (func_002934DC()) func_00226A10(D_80145040);
    if (func_0022A67C(D_80145040)) {
        func_0025E2F4(t34 = 0x34);
        switch (D_80145040[0x1295]) {
        case 0:
        case 2:
            func_42D190();
            break;
        case 1:
        case 3:
        case 4:
            func_438BA4();
            break;
        }
    }
    while (i < n) {
        o = arr[i];
        o2 = o;
        i++;
        sv = D_800D2988;
        func_0024BE2C(o2);
        if (o2->flags100 & 0x2000) func_00246E34(o2);
        D_800D2988 = sv;
    }
    func_0025CBA8(func_0025CC8C());
}
