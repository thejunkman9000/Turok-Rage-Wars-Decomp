#include "b24_types.h"

typedef struct Plr24 Plr24;
struct Plr24 {
    u8 pad0[0x5E4];
    s32 unk5E4;
    u8 pad5E8[0xC3C];
    s32 unk1224;
    s32 unk1228;
    u8 pad122C[0x4B4];
    Plr24 *next;
};

typedef struct Row18 Row18;
struct Row18 {
    s32 pad0;
    s16 id;
    u8 pad6[14];
    s32 (*fn)();
};
typedef struct Row14 Row14;
struct Row14 {
    s32 pad0;
    s16 id;
    u8 pad6[10];
    s32 (*fn)();
};
typedef struct Row10 Row10;
struct Row10 {
    s32 pad0;
    s16 id;
    u8 pad6[6];
    s32 (*fn)();
};
extern Row18 D_800D31D0[];
extern Row14 D_800D3230[];
extern Row18 D_800D32A8[];
extern Row14 D_800D3368[];
extern Row18 D_800D34C0[];
extern Row10 D_800D33C0[];
extern Row10 D_800D3390[];
extern Plr24 *D_80145060;

#define LOOK(row, tbl, n, stride)     row = tbl;     for (i = n; i != -1; i--) {         if (row->id == id) {             goto found_##tbl;         }         row++;     }     row = 0; found_##tbl:

s32 func_002AC6DC(Plr24 *a0, s32 a1, s32 id) {
    s32 r;
    s32 i;
    Plr24 *q;
    Row18 *p18;
    Row14 *p14;
    Row10 *p10;
    r = 0;
    if (a0->unk5E4 == 0) {
        return r;
    }
    LOOK(p18, D_800D31D0, 3, 0x18)
    if (p18 != 0) {
        r = p18->fn(a0, p18);
    }
    if (r != 0) {
        return r;
    }
    LOOK(p14, D_800D3230, 5, 0x14)
    if (p14 != 0) {
        r = p14->fn(a0, p14);
    }
    if (r != 0) {
        return r;
    }
    LOOK(p18, D_800D32A8, 7, 0x18)
    if (p18 != 0) {
        r = p18->fn(a0, p18);
    }
    if (r != 0) {
        return r;
    }
    LOOK(p14, D_800D3368, 1, 0x14)
    if (p14 != 0) {
        r = p14->fn(a0, p14);
    }
    if (r != 0) {
        return r;
    }
    LOOK(p18, D_800D34C0, 15, 0x18)
    if (p18 != 0) {
        r = p18->fn(a0, p18);
    }
    for (q = D_80145060; q != 0; q = q->next) {
        if (q->unk1224 == a1) {
            q->unk1224 = 0;
        } else if (q->unk1228 == a1) {
            q->unk1228 = 0;
        }
    }
    if (r != 0) {
        return r;
    }
    LOOK(p10, D_800D33C0, 15, 0x10)
    if (p10 != 0) {
        r = p10->fn(a0, p10, a1);
    }
    if (r != 0) {
        return r;
    }
    LOOK(p10, D_800D3390, 2, 0x10)
    if (p10 != 0) {
        r = p10->fn(a0, p10);
    }
    return r;
}
