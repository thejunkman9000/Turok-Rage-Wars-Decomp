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

typedef struct B15Ent {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[7];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[4];
    /* 0x018 */ B15Def *def;
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x44];
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x90];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x6C];
    /* 0x170 */ u32 unk170;
    /* 0x174 */ u8 pad174[0x38];
    /* 0x1AC */ u32 unk1AC;
    /* 0x1B0 */ u8 pad1B0[0x28];
    /* 0x1D8 */ B15Player *owner;
} B15Ent;

typedef struct B15Mode {
    u8 pad0[0x66];
    u8 mode;
} B15Mode;

void func_0022B08C(B15Player *o, Vec3f *v);
void func_00271888(B15Vec4 *q, Vec3f *v);
void func_0024E78C(void *obj, Vec3f pos, Vec3f *out1, s32 *out2, s32 a, s32 b);
void func_00280094(void *tab, void *a, void *b, s32 c, s32 d, s32 e, Vec3f zero, B15Vec4 q, Vec3f pos, s32 f, s32 g, s32 h);
void func_0028CE70(void *a, void *b, s32 c, Vec3f pos, f32 d, f32 e);
void func_00239314(void *p, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f pos);
void func_00271FA4(Vec3f *a, Vec3f *b, Vec3f *c);
void func_00278DE8(void *a, s32 b, void *c);
f32 func_00216F44(void *a, f32 x, f32 y, f32 z);
extern f32 D_800C94B0;
extern f32 D_800C94B4;
extern f32 D_800C94B8;
extern f32 D_800C94BC;
extern f32 D_800C94C0;
extern f32 D_800C94C4;
extern f32 D_800C94C8;
extern f32 D_800C94CC;
extern u8 D_8011FE88[];
extern u8 D_80121990[];

static inline void fx(B15Player *o, B15OwnerRef *obj, Vec3f pos, Vec3f v2, s32 mode) {
    Vec3f tmp;
    Vec3f p;
    Vec3f z;
    B15Vec4 q;
    s32 out2;

    if (*(void **)((u8 *)o + 0x5DC) != NULL) {
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
        p.y = p.y + D_800C94C0;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        func_00280094(D_80121990, obj, obj, 0, 0, 0xE9, z, q, p, 0, -1, mode == 5 ? 3 : 1);
        p.x = 0;
        p.y = 0;
        p.z = 0;
        func_0028CE70(D_8011FE88, o->unk698 + 0x140, 3, p, D_800C94C4, D_800C94C8);
    }
}

void func_0026643C(B15Ent *a0, B15Ent *a1, s32 flag0, Vec3f pos, Vec3f v2, s32 w9, B15Mode *p100, u32 w11) {
    s32 flag = flag0;
    register B15Mode *p10 asm("$19") = p100;
    B15Player *o;
    B15Holder *ho;
    B15Ent *e;
    f32 f;
    f32 g;
    f32 h;

    if (a1->type == 1) {
        a1->unk170 |= 0x8000;
        e = a1;
        if (a0->flags & 0x300000) {
            o = a0->owner;
            if (*(void **)((u8 *)o + 0x5DC) != NULL) {
                if (a1->unk1AC & 0x4000) {
                    func_00239314(*(void **)((u8 *)o + 0x5DC), D_800C94B4, 100.0f, D_800C94B4, D_800C94B0, 1, pos);
                } else if (a1->unk1AC & 0x2000) {
                    func_00239314(*(void **)((u8 *)o + 0x5DC), D_800C94BC, 50.0f, D_800C94BC, D_800C94B8, 1, pos);
                }
            }
        }
        if (flag != 0) {
            if (p10 != NULL && (e->flags & 0x300000) && (p10->mode == 4 || p10->mode == 5)) {
                ho = (B15Holder *)e->owner;
                fx((B15Player *)ho, (B15OwnerRef *)a1, pos, v2, p10->mode);
            }
            v2.x = 0.0f;
            v2.y = 0.0f;
            v2.z = 0.0f;
        }
        if ((e->flags & 0x300000) && (w11 & 0x200)) {
            func_00278DE8(a0, 0x10, e);
        }
    }
    if (a0->def->type == 1 || a0->def->type == 0xB) {
        func_00271FA4(&a0->unk1C, &a0->unk1C, &v2);
        if (w9 != 0) {
            a0->unk6C = a0->unk6C + func_00216F44(a0, a1->pos.x, a1->pos.y, a1->pos.z) * D_800C94CC;
        }
    }
}