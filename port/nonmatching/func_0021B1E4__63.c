#include "b04_types.h"
extern f32 D_800C7430;
extern u8 D_8011FE88[];
extern s32 D_8013B294;
extern u8 D_8013B364[];
extern B04Act *D_80145060;
extern u8 D_801462E5;
void func_449E38(B04Act *);
void func_44ACCC();
s32 func_44DE70(u8 *, s32, s32, B04Spawn *, s32);
void func_44E178(u8 *, s32, s32);
s32 func_0020CB3C(u8 *, Vec3f *);
void func_00264808(void *, s32);
f32 func_00272768(B04Spawn *, Vec3f *);
s32 func_002866F8(u8 *, Vec3f *);
s32 func_0028B370(u8 *, s32);
void func_0021B1E4(B04Act *a, s32 a1, s32 a2, s32 a3) {
    B04Spawn one;
    B04Spawn arr[32];
    s32 n, i, best, r;
    f32 bestd, cur, d;
    B04Act *l;
    u8 *t;
    func_44ACCC();
    func_00264808(a->wpn, 0);
    t = D_8011FE88;
    if (a3 != 0) {
        a->unk864 = 0;
        a->unk868 = 0;
    }
    if (D_801462E5 != 0) {
        n = func_44DE70(t, -1, a1, arr, 0x20);
        best = -1;
        bestd = 0.0f;
        for (i = 0; i < n; i++) {
            cur = D_800C7430;
            for (l = D_80145060; l != NULL; l = l->next) {
                d = func_00272768(&arr[i], &l->pos);
                if (d < cur)
                    cur = d;
            }
            if (bestd <= cur) {
                bestd = cur;
                best = i;
            }
        }
        if (best != -1) {
            a->v2F0 = arr[best].pos;
            a->pos = a->v2F0;
            a->unk354 = arr[best].w;
            a->unk6C = arr[best].w;
            r = func_002866F8(t, &a->pos);
            goto blk18;
        }
        goto blk19;
    }
    if (func_44DE70(t, -1, a1, &one, 1) != 0) {
        if (one.kind == D_8013B294) {
            a->v2F0 = one.pos;
            a->pos = a->v2F0;
            a->unk354 = one.w;
            a->unk6C = one.w;
            r = func_0028B370(t, one.idx);
blk18:
            a->unk2FC = r;
            a->unk14 = r;
            func_449E38(a);
        } else {
            goto blk19;
        }
    } else {
blk19:
        func_44E178(t, a1, a2);
    }
    a->brain->unk4 = func_0020CB3C(D_8013B364, &a->pos);
}
