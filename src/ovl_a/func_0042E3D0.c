#include "o04_types.h"
#include "q03_types.h"
extern O04GFlags D_801468A0[];
extern Q03Cfg D_801462C8[];
extern u8 *D_800E4680;
s32 func_0042E640(u8 *a);

#define F94(ix) (((Q03Cfg *)((ix) * 150 + (u32)D_801462C8))->ent[0].f94)
#define F95(ix) (((Q03Cfg *)((ix) * 150 + (u32)D_801462C8))->ent[0].f95)
void func_0042E3D0(void) {
    s32 s7 = 0;
    s32 s6 = 0;
    s32 i = 0;
    s32 idx;
    s32 k4;
    u8 t;
    Q03Ent *e;
    Q03Cfg *g;
    O04GFlags *G;
    G = D_801468A0;
    e = (Q03Ent *)((u8 *)G - 0x508);
    for (; i < 8; i++) {
        Q03Ent *q = e + i;
        if (q->f78 == 1 && q->f91 == q->f78) {
            q->f78 = 0;
            q->f91 = 0;
        }
    }
    for (i = 0; i < 7; i++) {
        k4 = i * 4;
        if (*(D_800E4680 + k4 + 5) == 0) {
            continue;
        }
        switch (*(D_800E4680 + k4 + 5) - 0xC) {
        case 0:
            G->unk98 = 1;
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            F94(idx) = 2;
            G->unkA0 = 0x64;
            G->unkA4 = -1;
            break;
        case 1:
            G->unk98 = 1;
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            F94(idx) = 1;
            break;
        case 4:
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            F94(idx) = 2;
            break;
        case 2:
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            if (s7 == 0) {
                G->unk98 = 1;
                F94(idx) = 1;
                s7 = 1;
            } else {
                F94(idx) = 0;
            }
            break;
        case 3:
            G->unk98 = 1;
            G->unk9C = 0;
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            F94(idx) = 1;
            s6 = 1;
            break;
        default:
            idx = func_0042E640(&D_800E4680[i * 4 + 5]);
            F94(idx) = 0;
            if (s6 != 0) {
                D_801462C8->ent[idx].f95 = 1;
            }
            break;
        }
    }
}
