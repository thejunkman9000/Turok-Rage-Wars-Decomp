#include "o03_types.h"
extern O3Pk *D_800E3590;
void func_002A33BC(s32 a);
void func_00439D3C(void *o, s32 a, O3Vec3 p, O3Vec3 q);
void func_00439DC0(void *o, O3Vec3 v);
void func_00439E10(void *o, O3Vec3 v);
void func_0025DF54(s32 a);
s32 func_0041DC3C(void) {
    O3Vec3 a, b, c, d;
    func_002A33BC(1);
    c.x = 0;
    c.y = 0;
    c.z = 0;
    d.x = 0;
    d.z = 0;
    a.x = 0.14f;
    a.y = 0.14f;
    a.z = 0.14f;
    d.y = 5.0f;
    b.x = 17.0f;
    b.y = -10.0f;
    b.z = -50.0f;
    func_00439D3C(D_800E3590->sub, 0, a, b);
    func_00439DC0(D_800E3590->sub, c);
    func_00439E10(D_800E3590->sub, d);
    func_0025DF54(0xE78);
    return 0;
}
