#include "o01_types.h"

typedef struct O01CtxD {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ void *tree;
    /* 0x08 */ u8 pad8[0x14];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ u8 pad20[0x14];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ u8 pad38[0x18];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[4];
    /* 0x58 */ s32 unk58;
} O01CtxD;
typedef struct O01Kind {
    /* 0x00 */ u8 pad0[0xE];
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 padF[2];
    /* 0x11 */ u8 kind;
    /* 0x12 */ u8 val;
} O01Kind;
typedef struct O01EntF {
    /* 0x0 */ f32 time;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} O01EntF;
typedef struct O01G {
    /* 0x0000 */ u8 pad0[0x11D0];
    /* 0x11D0 */ u8 *unk11D0;
    /* 0x11D4 */ u8 *unk11D4;
} O01G;
extern O01CtxD *D_800E2830;
extern O01G D_8011FE88[];
extern f32 D_800E0CA0;
extern f32 D_800E0CA4;
s32 func_00245774(void);
void *func_0028FD94(void *tree, s32 idx);
void func_00402FB4(s32 a, O01Kind *k);
void func_00278EEC(O01Kind *k);
void func_0028BAF8(O01G *g, O01Kind *k, s32 z);

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

void func_00403458(void) {
    f32 now = D_800E2830->unk1C;
    s32 flag = 0;
    O01Node *n;
    O01EntF *e;
    O01EntF *ents;
    O01Kind *k;
    s32 cnt;
    s32 i;
    if (func_00245774() != 0) {
        if (D_800E2830->unk50 != 0) {
            n = func_0028FD94(D_800E2830->tree, 2);
            cnt = n->unk4;
            ents = (O01EntF *)((u8 *)n + 8);
            if (cnt != 0) {
                if (D_800E2830->unk34 <= now) {
                    flag = 1;
                }
                for (i = 0; i < cnt; i++) {
                    e = &ents[i];
                    if (e->time <= D_800E0CA0) {
                        continue;
                    }
                    if (now < e->time) {
                        if (flag == 0) {
                            continue;
                        }
                    }
                    if (e->unk4 == 0) {
                        k = (O01Kind *)(D_8011FE88->unk11D0 + e->unk8 * 20);
                    } else {
                        k = (O01Kind *)(D_8011FE88->unk11D4 + e->unk8 * 20);
                    }
                    if (O01KindOk(k) != 0) {
                        func_00402FB4(0, k);
                        D_800E2830->unk58 = 0;
                    } else {
                        func_00278EEC(k);
                    }
                    e->time = D_800E0CA4;
                    k->unkE = (k->unkE | 1) & 0xEF;
                    func_0028BAF8(D_8011FE88, k, 0);
                }
            }
        }
    }
}
