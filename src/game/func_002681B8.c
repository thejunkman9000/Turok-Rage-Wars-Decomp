#include "b15_types.h"
void func_0028CE70(void *a, void *b, s32 c, Vec3f pos, f32 d, f32 e);
extern u8 D_8011FE88[];
extern u8 D_8010EC90[];
extern f32 D_800C954C;
extern f32 D_800C9550;
typedef struct B15Y { s32 a; s16 b; u8 c; } B15Y;
void func_002681B8(Actor *src, Actor *act, s32 c, Vec3f pos, B15Y k) {
    u8 *p;
    if (*(u8 *)src == 1 && (src->flags & 0x300000)) {
        p = *(u8 **)((u8 *)act->owner + 0x698) + 0x140;
        pos.x = 0; pos.y = 0; pos.z = 0;
    } else {
        p = D_8010EC90;
    }
    func_0028CE70(D_8011FE88, p, k.a, pos, k.b * D_800C954C, k.c * D_800C9550);
}
