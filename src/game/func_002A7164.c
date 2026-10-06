#include "b24_types.h"

extern f32 D_800CB048;
extern f32 D_800CB04C;
extern s32 D_800D297C;
void func_002702EC(void *, void *);
void func_00270980(void *, void *);
void func_00272898(void *);
void func_00273340(void *, void *);
void func_0027335C(void *, void *);
void func_002734EC(void *, f32, f32, f32);

void func_002A7164(Emit *e, EmitNode *n) {
    u8 m[0x40];
    EmitOwner *o;
    f32 s;
    o = n->unkB0;
    if (o != NULL) {
        if (o == (EmitOwner *)-1) {
            n->mtx[D_800D297C] = n->mtx[D_800D297C ^ 1];
            n->unkB0 = NULL;
        } else {
            func_00270980(m, (u8 *)o + ((D_800D297C << 6) + 0x60));
            s = D_800CB048;
            if (o->info->unk14 != 0) {
                s = D_800CB04C;
            }
            func_002734EC(m, s, s, s);
            func_00272898(m);
            func_00273340(m, n->v10);
            if (e->flags & 4) {
                func_0027335C(m, n->v1C);
            } else {
                func_002702EC(m, &n->mtx[D_800D297C]);
            }
        }
        n->unk8 = *(f32 *)((u8 *)e->def + 8);
    }
}
