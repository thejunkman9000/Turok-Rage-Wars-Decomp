#include "b08_types.h"

typedef struct Obj538 {
    u8 pad0[0x538];
    s32 unk538;
    u8 pad53C[8];
    s32 unk544;
    u8 pad548[2];
    s8 unk54A;
    s8 unk54B;
    s8 unk54C;
    s8 unk54D;
    s8 unk54E;
    s8 unk54F;
    s8 unk550;
    s8 unk551;
} Obj538;

void func_0023919C(Obj538 *o, s8 a, s8 b, s8 c, s8 d, s8 e, s8 f, s8 g) {
    if (o != NULL) {
        o->unk550 = d;
        o->unk54A = a;
        o->unk54E = b;
        o->unk54F = c;
        o->unk551 = 0;
        o->unk54B = e;
        o->unk54C = f;
        o->unk54D = g;
        o->unk538 = 0;
        o->unk544 = 1;
    }
}
