#include "b07_types.h"

extern u8 D_8013B1A8[];

void *func_00268C1C(void *tbl, s32 id);
void func_0024BC84(Vec3f *out, Actor *actor, Vec3f dir);
void func_00271FA4(Vec3f *out, Vec3f *a, void *b);
f32 func_0024D274(Actor *actor);

void func_0022E77C(Actor *actor, void **slot, s32 id, f32 z)
{
    void *p;
    Vec3f dir;
    Vec3f out;

    p = *slot;
    if (p == NULL) {
        p = func_00268C1C(D_8013B1A8, id);
        if (p == NULL) {
            return;
        }
    }
    *slot = p;
    dir.x = 0;
    dir.y = 0;
    dir.z = z;
    func_0024BC84(&out, actor, dir);
    func_00271FA4(&out, &out, (u8 *)actor + 8);
    AT(s16, p, 0x16) = 1;
    AT(s16, p, 0x10) = out.x;
    AT(s16, p, 0x12) = out.y + func_0024D274(actor) * 0.5f;
    AT(s16, p, 0x14) = out.z;
    AT(f32, p, 0xC) = 1.0f;
}
