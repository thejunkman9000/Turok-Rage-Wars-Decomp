#include "b02_types.h"

B2Edge *func_0020C9B0(B2Mgr *m, s32 idx);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
f32 func_0027272C(Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
extern B2Mgr D_8013B364;
extern f32 D_800C6EA0;

s32 func_0020D4AC(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    B2Edge *e;
    Vec3f *tp;
    Vec3f sum;
    f32 k;
    f32 f;
    s32 i;
    s32 cnt;

    tp = NULL;
    cnt = 0;
    i = 0;
    for (; i < m->count; i++) {
        e = func_0020C9B0(m, i);
        if (e->a == ctl->unk1C0 && e->kind == 6) {
            tp = func_0020C994(m, e->b);
            ctl->ent[cnt].b = e->a;
            ctl->ent[cnt].a = e->b;
            if (cnt + 1 == ctl->unk1BC) {
                break;
            }
            cnt++;
        }
    }
    k = func_0027272C(tp, func_0020C994(m, ctl->unkC));
    i = 0;
    sum.z = D_800C6EA0;
    sum.y = D_800C6EA0;
    sum.x = D_800C6EA0;
    for (; i < ctl->unk38; i++) {
        if (ctl->a3C[i] == NULL) {
            break;
        }
        ctl->v138[cnt].x = tp->x - ctl->a3C[i]->pos.x;
        ctl->v138[cnt].y = tp->y - ctl->a3C[i]->pos.y;
        ctl->v138[cnt].z = tp->z - ctl->a3C[i]->pos.z;
        func_002720EC(&ctl->v138[cnt]);
        sum.x *= ctl->v138[cnt].x;
        sum.y *= ctl->v138[cnt].y;
        sum.z *= ctl->v138[cnt].z;
    }
    f = sum.x + sum.y + sum.z;
    if (ctl->unk38 == 1 && f < 0.0f) {
        f = -f;
    }
    ctl->ent[cnt].w = f * k;
    ctl->unk1BC++;
    return 0;
}
