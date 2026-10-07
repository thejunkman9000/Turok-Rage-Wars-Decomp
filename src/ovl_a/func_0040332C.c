#include "o01_types.h"

typedef struct O01Kind {
    /* 0x00 */ u8 pad0[0x11];
    /* 0x11 */ u8 kind;
    /* 0x12 */ u8 val;
} O01Kind;
typedef struct O01Ent12 {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} O01Ent12;
typedef struct O01G {
    /* 0x0000 */ u8 pad0[0x11D0];
    /* 0x11D0 */ u8 *unk11D0;
    /* 0x11D4 */ u8 *unk11D4;
} O01G;
extern O01Ctx *D_800E2830;
extern O01G D_8011FE88[];
void *func_0028FD94(void *tree, s32 idx);

static inline s32 O01KindOk(O01Kind *a) {
    s32 r = 0;
    switch (a->kind) {
    case 1:
        if (a->val == 5) r = 1;
        break;
    case 9:
        if (a->val == 4) r = 1;
        break;
    case 10:
        if (a->val == 3) r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

s32 func_0040332C(void) {
    s32 any = 0;
    s32 i;
    O01Node *n = func_0028FD94(D_800E2830->tree, 2);
    s32 cnt = n->unk4;
    O01Ent12 *ents = (O01Ent12 *)((u8 *)n + 8);
    O01Ent12 *e;
    O01Kind *k;
    for (i = 0; i < cnt; i++) {
        e = &ents[i];
        if (e->unk4 == 0) {
            k = (O01Kind *)(D_8011FE88->unk11D0 + e->unk8 * 20);
        } else {
            k = (O01Kind *)(D_8011FE88->unk11D4 + e->unk8 * 20);
        }
        if (O01KindOk(k) != 0) {
            any = 1;
        }
    }
    return any ^ 1;
}
