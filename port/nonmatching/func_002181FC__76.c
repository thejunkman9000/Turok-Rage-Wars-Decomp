#include "b04_types.h"
extern f32 D_800C7338;
extern f32 D_800CE38C;
extern s32 D_800D052C[];
typedef struct { s8 a; s8 b; } B04PrX;
typedef struct { u8 pad0[0x602]; B04PrX pr[22]; s16 unk62E; } B04Pl2;
s32 func_0022EAFC(B04Pl2 *, s32);
void func_002181FC(B04Roster *o, s32 a1, B04Pl2 *p) {
    s32 i, j, a0, k;
    
    o->w38C = 0;
    o->w384 = a1;
    o->w37C = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 22; j++) {
            if (i == p->pr[j].b) break;
        }
        if (j < 22) {
            k = o->w388;
            if (k == -1)
                a0 = 1;
            else if (k == 3 || k == 7)
                a0 = i == k;
            else if (k == 4)
                a0 = i == 4;
            else {
                a0 = 0;
                if (i == k || i == k + 1)
                    a0 = 1;
            }
        } else
            a0 = 0;
        if (a0 == 0) {
            o->ent[i].idx = -1;
            o->ent[i].on = 0;
        } else {
            o->ent[i].idx = j;
            if (p->unk62E == j)
                o->w37C = i;
            o->ent[i].val = D_800D052C[j];
            if (func_0022EAFC(p, j) != 0)
                o->ent[i].on = 1;
            else
                o->ent[i].on = 0;
            o->ent[i].z2C = 0;
            o->ent[i].f30 = D_800CE38C;
            o->ent[i].f28 = i * D_800C7338;
        }
    }
    o->w380 = 1;
}
