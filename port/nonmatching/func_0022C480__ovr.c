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
    f32 v60[16];           /* port: func_00226DAC writes a whole 4x4 matrix through this pointer (0x40 bytes); the matching source declares a Vec3f followed by 0x30 bytes of padding, which only the MIPS frame layout keeps behind it - on the host the write ran over the saved registers and the actor argument */
    Actor *pawn = AT(Actor *, actor, 0x5DC);
    if (pawn != NULL) {
        v50 = AT(Vec3f, pawn, 0x128);
    } else {
        if (D_800D297C != 0) {
            func_00226DAC(actor, v60);
        } else {
            func_00226DAC(actor, v60);
        }
        func_00273340(v60, &v50);
    }
    func_00272848(m);
    func_00273744(m, (f32)D_80145080 * D_800C7E30);
    func_002734B8(m, v50.x, v50.y + D_800C7E34, v50.z);
    func_002702EC(m, (u8 *)actor + (D_800D297C * 64 + 0x1640));
}
