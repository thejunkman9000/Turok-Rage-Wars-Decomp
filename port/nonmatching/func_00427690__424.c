#include "o04_types.h"
typedef struct { s32 id; u8 pad[0x18]; } O04Ent1Cz;
typedef struct { O04W a; O04W b; O04W c; } O04Ent12z;
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96l3;
extern O04ModeS4690 *D_800E4690;
extern O04Cfg D_801462C8[];
extern O04Ent1Cz D_800E4694[];
extern u8 D_800E4A84[];
#define W(o) (*(s32 *)(D_800E4A84 + off + (o)))
#define H(o) (*(u16 *)(D_800E4A84 + off + (o)))
u8 *func_00425E50(s32 a, s32 b, s32 c);
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_004275B4(void);
O04Sub10 *func_0040ECB0(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void func_00427F50(s32 a);
static inline s32 o04_find(s32 id) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (D_800E4694[i].id == id) {
            return i;
        }
    }
    return 0;
}
void func_00427690(void) {
    u8 sp10[8];
    s32 i;
    s32 j;
    s32 cnt;
    s32 off;
    s32 idx;
    s32 idx2;
    s32 c;
    s32 t;
    u8 *r;
    O04Sub10 *h;
    func_004275B4();
    for (i = 0; i < 0x24; i++) {
        func_002656A8(sp10, i, 0);
    }
    func_002656A8(sp10, 0, 1);
    i = 0;
    if (D_801462C8->unkD == 1) {
        do {
            r = func_00425E50(i, 0, ((O04Ent96l3 *)((u8 *)D_801462C8 + 0xD0))[D_800E4690->unkA5C].unk80);
            t = r[1];
            if (t > 0) {
                func_002656A8(sp10, t - 1, 1);
            }
            for (j = 0; j < 3; j++) {
                t = (r + j)[2];
                if (t > 0) {
                    func_002656A8(sp10, t - 1, 1);
                }
            }
            i++;
        } while (i < 0x24);
    } else {
        do {
            func_002656A8(sp10, i, 1);
            i++;
        } while (i < 0x24);
    }
    cnt = 0;
    off = 0;
    do {
        idx = o04_find(W(0));
        if (func_00265670(sp10, idx) != 1) {
            cnt++;
        } else {
            h = func_0040ECB0(D_800E4690->unk970, H(2));
            func_0040E958(h, 1);
            h->unk10 = 0x14;
            idx2 = o04_find(W(4));
            if (func_00265670(sp10, idx2) != 1) {
                cnt++;
            } else {
                h = func_0040ECB0(D_800E4690->unk970, H(6));
                func_0040E958(h, 1);
                h->unk10 = 0x14;
                cnt++;
                if (W(8) != -1) {
                    h = func_0040ECB0(D_800E4690->unk970, H(10));
                    func_0040E958(h, 1);
                    h->unk10 = 0x14;
                }
            }
        }
        off += 0xC;
    } while (cnt < 0x40);
    i = 0;
    do {
        if (func_00265670(D_800E4690->unkA74, i) == 1) {
            func_00427F50(i);
        }
        i++;
    } while (i < 0x24);
    i = 0;
    do {
        if (func_00265670(D_800E4690->unkA79, i) == 1) {
            func_002656A8(D_800E4690->unkA74, i, 1);
        }
        i++;
    } while (i < 0x24);
    cnt = 0;
    off = 0;
    do {
        c = 0xAA;
        idx = o04_find(W(0));
        if (func_00265670(D_800E4690->unkA74, idx) != 1) {
            cnt++;
        } else {
            h = func_0040ECB0(D_800E4690->unk970, H(2));
            if (func_00265670(D_800E4690->unkA79, idx) != 1) {
                h->unk10 = 0xAA;
            } else {
                h->unk10 = 0x46;
                c = 0x46;
            }
            idx2 = o04_find(W(4));
            if (func_00265670(D_800E4690->unkA74, idx2) != 1) {
                cnt++;
            } else {
                h = func_0040ECB0(D_800E4690->unk970, H(6));
                if (func_00265670(D_800E4690->unkA79, idx2) != 1) {
                    h->unk10 = 0xAA;
                } else {
                    h->unk10 = 0x46;
                    c = 0x46;
                }
                cnt++;
                if (W(8) != -1) {
                    func_0040ECB0(D_800E4690->unk970, H(10))->unk10 = c;
                }
            }
        }
        off += 0xC;
    } while (cnt < 0x40);
}
