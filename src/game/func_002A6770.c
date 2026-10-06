#include "b23_types.h"

typedef struct Obj6770 {
    u8 pad0[0x40];
    u8 sub[0xC];
    f32 unk4C;
} Obj6770;

typedef struct ObjAC {
    u8 pad0[0xAC];
    f32 unkAC;
} ObjAC;

typedef struct Big6A90b {
    u8 pad0[0x6A90];
    u8 sub[1];
} Big6A90b;

void func_002795C0(void *a, void *b);
void func_00279578(void *a, void *b);

void func_002A6770(Big6A90b *o, Obj6770 *p, ObjAC *q) {
    p->unk4C = p->unk4C - q->unkAC;
    func_002795C0(p->sub, q);
    func_00279578(o->sub, q);
}
