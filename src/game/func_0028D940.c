#include "common.h"

typedef struct { u8 pad0[0xC]; s32 unkC; s32 unk10; s32 *unk14; s32 unk18; } Obj;

s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
void func_002537D8(s32 a, s32 *b);
void func_00285130();
void func_0028DA50(Obj *o);
s32 func_0028FE1C(s32 tbl, s32 base, s32 idx, s32 *size);
extern u8 D_800CA380[];
extern u8 D_800CA3AC[];

void func_0028D940(Obj *o, s32 id) {
    s32 size;
    s32 *h;
    s32 *r;
    s32 p;
    if (o->unk14 == 0 || o->unk18 != id) {
        func_0028DA50(o);
        if (o->unkC != 0) {
            h = func_002518DC(0, o->unkC, o->unkC, o->unk10, 0x10, 0, 0, D_800CA380, 1);
            if (h != 0) {
                p = func_0028FE1C(*h, o->unkC, id, &size);
                func_002537D8(0, h);
                r = func_002518DC(0, p, p, size, 0x10, 0, func_00285130, D_800CA3AC, 1);
                o->unk14 = r;
                if (r != 0) {
                    o->unk18 = id;
                }
            }
        }
    }
}
