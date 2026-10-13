#include "common.h"

typedef struct { u8 pad[0x80]; s8 b80; } O06Rec;
typedef struct { u8 pad[0x5D8]; O06Rec *f5D8; u8 pad5DC[4]; s32 f5E0; } O06Plr;
typedef struct { u8 pad0[0x1C]; O06Plr *f1C; void *f20; } O06Wd;
typedef struct { s16 h; s16 pad; } O06Hw;
extern O06Hw D_800E5DFA[];
extern u8 D_auto_800C9233[];
extern u8 D_auto_800C9237[];
extern u8 D_00450698[];
s32 func_0026439C(void *p);
s32 func_002643A8(void *p);
s32 func_002643C0(void *p);
void func_0044AD14(void *p, s32 a);
void func_0025DF54(s32 a);
void func_004427C4(s32 a, void *b, void *c);
s32 func_004425F8(void *w, s32 a, s32 b, s32 c, s32 d, s32 e);
void func_004422BC(s32 a, s32 b, s32 c);

s32 func_auto_0043DB50(s32 a0, O06Wd *w, s32 a2) {
    O06Plr *p = w->f1C;
    O06Rec *r = p->f5D8;
    if (func_0026439C(w->f20)) {
        func_0044AD14(p, r->b80);
        func_0025DF54(D_800E5DFA[p->f5E0].h);
        func_004427C4(a2, w, D_00450698);
        return 1;
    }
    r->b80 = func_004425F8(w, r->b80, 1, 0, 0x12, 1);
    if (func_002643A8(w->f20)) {
        r->b80 = D_auto_800C9237[r->b80 * 4];
    }
    if (func_002643C0(w->f20) || func_0026439C(w->f20)) {
        r->b80 = D_auto_800C9233[r->b80 * 4];
    }
    func_0044AD14(p, r->b80);
    func_004422BC(a0, 0xB, r->b80);
    return 0;
}
