#include "b23_types.h"
typedef struct Obj7588 {
    u8 pad0[0x7588];
    u8 sub[1];
} Obj7588;
typedef struct Ent6B74 {
    u8 pad0[8];
    s32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Ent6B74;
Ent6B74 *func_002796AC(void *p);
void func_002A6B74(Obj7588 *o, s32 a, s32 b, s32 c, f32 d) {
    Ent6B74 *e = func_002796AC(o->sub);
    if (e != 0) {
        e->unk18 = a;
        e->unk14 = b;
        e->unk8 = 0;
        e->unkC = d;
        e->unk10 = c;
    }

}
