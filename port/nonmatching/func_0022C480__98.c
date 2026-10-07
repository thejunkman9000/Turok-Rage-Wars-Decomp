#include "b07_types.h"
extern f32 D_800C7E30;
extern f32 D_800C7E34;
extern s32 D_80145080;
extern s32 D_800D297C;
void func_00226DAC(Actor *actor, void *out);
void func_00273340(void *a, void *b);
void func_00272848(void *m);
void func_00273744(void *m, f32 a);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002702EC(void *m, void *dst);
void func_0022C480(Actor *actor)
{
    u8 m[0x40];
    Vec3f v50;
    Vec3f v60;
    u8 unused[0x30];
    Actor *pawn = AT(Actor *, actor, 0x5DC);
    if (pawn != NULL) {
        v50 = AT(Vec3f, pawn, 0x128);
    } else {
        func_00226DAC(actor, &v60);
        func_00273340(&v60, &v50);
    }
    func_00272848(m);
    func_00273744(m, (f32)D_80145080 * D_800C7E30);
    func_002734B8(m, v50.x, v50.y + D_800C7E34, v50.z);
    func_002702EC(m, (u8 *)actor + D_800D297C * 64 + 0x1640);
}
