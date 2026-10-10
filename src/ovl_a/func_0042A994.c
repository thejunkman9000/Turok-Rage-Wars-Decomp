#include "o04_types.h"
typedef struct { s32 k; u8 pad4[0xC]; } O04E16c;
typedef struct { s32 k; u16 pad4; u16 unk2; u8 pad8[8]; } O04E16d;
typedef struct { O04W a; O04W b; u8 pad8[8]; } O04Ent16;
extern O04ModeF60 *D_800E4F60;
extern s32 D_800E51E4[];
extern s32 D_800E51F8[];
extern s32 D_800E5214[];
extern s32 D_800E5240[];
extern O04Ent16 D_800E4F64[];
s32 func_0042B474(s32 a);
s32 func_0042B334(s32 a);
O04Sub10 *func_0040ECB0(void *a, s32 b);
void func_0040E958(void *p, s32 a);
void func_0042A994(s32 a) {
    s32 s5;
    s32 s7;
    s32 s3;
    s32 s2;
    s32 n;
    s32 found;
    s32 *tbl;
    s32 *p;
    s32 kind;
    O04Sub10 *h;
    s7 = a >= 0xC;
    for (s5 = 0; s5 < 4; s5++) {
        switch (s5) {
        case 3:
            tbl = D_800E51E4;
            kind = 3;
            break;
        case 2:
            tbl = D_800E51F8;
            kind = 2;
            break;
        case 0:
            tbl = D_800E5240;
            kind = 0;
            break;
        case 1:
            tbl = D_800E5214;
            kind = 1;
            break;
        default:
            return;
        }
        s3 = 0;
        do { n = func_0042B334(func_0042B474(kind)); } while (0);
        for (; s3 < n; s3++) {
            found = 0;
            s2 = 0;
            do {
                if (tbl[s3] == D_800E4F64[s2].a.w) {
                    h = func_0040ECB0(D_800E4F60->unk0, D_800E4F64[s2].a.h.h1);
                    func_0040E958(h, s7);
                    h->unk10 = a;
                    if (D_800E4F64[s2].b.w != -1) {
                        h = func_0040ECB0(D_800E4F60->unk0, D_800E4F64[s2].b.h.h1);
                        func_0040E958(h, s7);
                        h->unk10 = a;
                    }
                    found = 1;
                }
                s2++;
            } while (s2 < 0x28 && found == 0);
        }
    }
}
