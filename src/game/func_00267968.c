#include "b15_types.h"

typedef struct B15Pawn {
    u8 pad0[0x128];
    Vec3f pos;
} B15Pawn;

typedef struct B15Player {
    u8 pad0[0x5DC];
    B15Pawn *pawn;
    u8 pad5E0[0xB8];
    u8 *unk698;
} B15Player;

typedef struct B15Holder {
    u8 pad0[0x5DC];
    void *unk5DC;
    u8 pad5E0[0xBC00];
} B15Holder;

typedef struct B15OwnerRef {
    u8 pad0[0x1D8];
    B15Player *owner;
} B15OwnerRef;

void func_0022B08C(B15Player *o, Vec3f *v);
void func_00271888(B15Vec4 *q, Vec3f *v);
void func_0024E78C(void *obj, Vec3f pos, Vec3f *out1, s32 *out2, s32 a, s32 b);
void func_00280094(void *tab, void *a, void *b, s32 c, s32 d, s32 e, Vec3f zero, B15Vec4 q, Vec3f pos, s32 f, s32 g, s32 h);
void func_0028CE70(void *a, void *b, s32 c, Vec3f pos, f32 d, f32 e);
extern f32 D_800C9538;
extern f32 D_800C953C;
extern f32 D_800C9540;
extern u8 D_8011FE88[];
extern u8 D_80121990[];

void func_00267968(B15Holder *act, B15OwnerRef *obj, Vec3f pos, Vec3f v2, s32 mode) {
    Vec3f tmp;
    Vec3f p;
    Vec3f z;
    B15Vec4 q;
    s32 out2;
    B15Player *o;

    if (act->unk5DC != NULL) {
        o = obj->owner;
        tmp.x = -v2.x;
        tmp.y = v2.y;
        tmp.z = v2.z;
        func_0022B08C(o, &tmp);
        tmp.x = tmp.x - o->pawn->pos.x;
        tmp.y = tmp.y - o->pawn->pos.y;
        tmp.z = tmp.z - o->pawn->pos.z;
        func_00271888(&q, &tmp);
        func_0024E78C(obj, pos, &p, &out2, 0, 1);
        p = pos;
        p.y = p.y + D_800C9538;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        func_00280094(D_80121990, obj, obj, 0, 0, 0xE9, z, q, p, 0, -1, mode == 5 ? 3 : 1);
        p.x = 0;
        p.y = 0;
        p.z = 0;
        func_0028CE70(D_8011FE88, o->unk698 + 0x140, 3, p, D_800C953C, D_800C9540);
    }
}
