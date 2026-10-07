#include "b07_types.h"

extern u8 D_800C7CB0[];

void *func_002518DC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, void *a7, s32 a8);
void *func_0028FD94(void *node, s32 idx);
void func_0024B4E4(Actor *actor, void *p);
void func_0024ADC0(Actor *actor, Vec3f *d, s32 a2);
void func_002536F4(s32 a0, void *p);

void func_0022BC84(Actor *actor, s32 arg1)
{
    void *p;
    Actor *owner;
    Vec3f d;

    if (actor->flags & 0x40000) {
        p = func_002518DC(0, AT(s32, actor, 0xC4), AT(s32, actor, 0xC4), AT(s32, actor, 0xD0),
                          4, 0, 0, D_800C7CB0, 1);
        if (p != NULL) {
            owner = actor->owner;
            func_0024B4E4(actor, func_0028FD94(AT(void *, p, 0), 0));
            if (arg1 != 0) {
                if (AT(Actor *, owner, 0x5DC) != NULL) {
                    d.x = AT(f32, AT(Actor *, owner, 0x5DC), 0x128) - AT(f32, actor, 0x8);
                    d.y = 0;
                    d.z = AT(f32, AT(Actor *, owner, 0x5DC), 0x130) - AT(f32, actor, 0x10);
                    func_0024ADC0(actor, &d, arg1);
                }
            }
            func_002536F4(0, p);
        }
    }
}
