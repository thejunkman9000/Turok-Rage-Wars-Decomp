#include "p2_types.h"

extern u8 D_800CE7E4[];
extern u8 D_800CE79C[];
void func_002748E0(f32 *cur, f32 target, f32 rate);
void func_002231B0(Player *p, ObjDef *o, void *a);
void func_002233CC(Player *p, ObjDef *o, void *a);
s32 func_0024E61C(ObjDef *o);
void func_002227D0(Player *p, ObjDef *o, s32 a);

void func_0022CE68(Player *p, ObjDef *o) {
    func_002748E0(&p->f72C, 0.0f, 0.25f);
    func_002231B0(p, o, D_800CE7E4);
    func_002233CC(p, o, D_800CE79C);
    if (o->f20 <= 0.0f) {
        if (func_0024E61C(o)) {
            func_002227D0(p, o, 2);
        }
    }
}