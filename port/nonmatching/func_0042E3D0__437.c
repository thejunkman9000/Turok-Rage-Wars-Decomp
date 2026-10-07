#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96n;
typedef struct { u8 pad0[5]; u8 tbl[0x20]; } O04Pkt;
extern O04GFlags D_801468A0[];
extern O04Cfg D_801462C8[];
extern u8 *D_800E4680;
s32 func_0042E640(u8 *a);
void func_0042E3D0(void) {
    s32 s7 = 0;
    s32 s6 = 0;
    s32 i = 0;
    s32 s0;
    s32 idx;
    O04Ent96n *e;
    u8 *c;
    u8 *rec;
    u8 t;
    e = (O04Ent96n *)((u8 *)D_801468A0 - 0x508);
    for (; i < 8; i++, e++) {
        if (e->unk78 == 1 && e->unk91 == e->unk78) {
            e->unk78 = 0;
            e->unk91 = 0;
        }
    }
    c = (u8 *)D_801462C8;
    s0 = 5;
    for (i = 0; i < 7; i++, s0 += 4) {
        rec = D_800E4680 + s0;
        t = D_800E4680[i * 4 + 5];
        if (t == 0) {
            continue;
        }
        switch (t - 0xC) {
        case 0:
            D_801468A0->unk98 = 1;
            idx = func_0042E640(D_800E4680 + s0);
            c[idx * 0x96 + 0x164] = 2;
            D_801468A0->unkA0 = 0x64;
            D_801468A0->unkA4 = -1;
            break;
        case 1:
            D_801468A0->unk98 = 1;
            idx = func_0042E640(D_800E4680 + s0);
            c[idx * 0x96 + 0x164] = 1;
            break;
        case 4:
            idx = func_0042E640(D_800E4680 + s0);
            c[idx * 0x96 + 0x164] = 2;
            break;
        case 2:
            idx = func_0042E640(D_800E4680 + s0);
            if (s7 == 0) {
                s7 = 1;
                D_801468A0->unk98 = 1;
                c[idx * 0x96 + 0x164] = 1;
            } else {
                c[idx * 0x96 + 0x164] = 0;
            }
            break;
        case 3:
            s6 = 1;
            D_801468A0->unk98 = 1;
            D_801468A0->unk9C = 0;
            idx = func_0042E640(D_800E4680 + s0);
            c[idx * 0x96 + 0x164] = 1;
            break;
        default:
            idx = func_0042E640(D_800E4680 + s0);
            c[idx * 0x96 + 0x164] = 0;
            if (s6 != 0) {
                c[idx * 0x96 + 0x165] = 1;
            }
            break;
        }
    }
}
