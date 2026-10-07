#include "p1_types.h"

typedef struct VInfo {
    u8 pad0[0x18];
    s16 x;
    s16 y;
    s16 z;
} VInfo;

typedef struct VNode VNode;
struct VNode {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ VNode *next;
    /* 0x08 */ VInfo info;
};

typedef struct VList {
    VNode *head;
    u8 pad4[0x10];
} VList;

typedef struct VCtx {
    /* 0x0000 */ u8 pad0[0x94E0];
    /* 0x94E0 */ VList lists[10];
    /* 0x95A8 */ u8 pad95A8[0x10];
    /* 0x95B8 */ s32 mode;
} VCtx;

typedef struct Vec3fv { f32 x, y, z; } Vec3fv;

extern DlCmd *D_80110634;
extern u8 D_800D14B0[];
extern u8 D_800D2E60[];
extern u8 D_801469A0[];
extern f32 D_801031F0[6];
void func_0026D8F8(void);
void func_00296FF8(void);
void func_00255E78(VList *, VNode *);
void func_00255CB4(void *, VNode *);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002A6170(VCtx *c) {
    s32 i;
    VList *l;
    VNode *n, *next;
    Vec3fv v;
    VInfo *p;

    if (c->mode == 100) {
        return;
    }
    GFX(0xE7000000, 0)
    GFX(0xE3000A01, 0x100000)
    GFX(0xFD900000, (u32)D_800D14B0)
    GFX(0xF5900000, 0x07080200)
    GFX(0xE6000000, 0)
    GFX(0xF3000000, 0x0707F400)
    GFX(0xE7000000, 0)
    GFX(0xF5880400, 0x00080200)
    GFX(0xF2000000, 0x0003C03C)
    GFX(0xFA000000, -0x38)
    GFX(0xDE000000, (u32)D_800D2E60)
    for (i = 0; i < 10; i++) {
        l = &c->lists[i];
        for (n = l->head; n != NULL; n = next) {
            next = n->next;
            p = &n->info;
            v.x = p->x;
            v.y = p->y;
            v.z = p->z;
            if (!(v.x < D_801031F0[3] && v.y < D_801031F0[4] && v.z < D_801031F0[5] && D_801031F0[0] <= v.x && D_801031F0[1] <= v.y && D_801031F0[2] <= v.z)) {
                func_00255E78(l, n);
                func_00255CB4((u8 *)c + 0x95A8, n);
            } else {
                GFX(0xDA380003, (u32)p)
                GFX(0x01004008, (u32)D_801469A0)
                GFX(0x06000204, 0x00040600)
            }
        }
    }
    func_0026D8F8();
    func_00296FF8();
}

