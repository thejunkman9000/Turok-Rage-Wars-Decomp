#include "o05_types.h"

typedef struct { u8 pad[0x14]; u16 h14; } O05Wh;
typedef struct { u16 w[38]; } O05Row;
extern O05L2 *D_800E59E0;
extern O05Row D_800E5A06[];
void func_0025DF54(s32 a);
void func_0040E958(void *w, s32 a);
void func_00419FD8(void *w, s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_002A3358(void);
s32 func_00419FB8(void *w);
void func_00419FA4(void *w);
void *func_0040ECB0(void *p, s32 id);

s32 func_0043A7D8(void) {
    s32 row;
    s32 col;
    O05L2 *p;
    switch (D_800E59E0->f1358) {
    case 7:
        break;
    case 6:
        break;
    case 1:
        ((O05Wh *)D_800E59E0->f1348)->h14 += D_800E59E0->h134E;
        ((O05Wh *)D_800E59E0->f1350)->h14 -= D_800E59E0->h1356;
        D_800E59E0->f135C--;
        if (D_800E59E0->f135C <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E59E0->f1364, 1);
            func_00419FD8(D_800E59E0->f1360, 4);
            D_800E59E0->f1358 = 4;
            D_800E59E0->f135C = 4;
        }
        break;
    case 2:
        ((O05Wh *)D_800E59E0->f1348)->h14 -= D_800E59E0->h134E;
        ((O05Wh *)D_800E59E0->f1350)->h14 += D_800E59E0->h1356;
        D_800E59E0->f135C--;
        if (D_800E59E0->f135C <= 0) {
            D_800E59E0->f1358 = 3;
            func_0029A73C();
            func_00299368(D_800E59E0->f1368);
            return 0;
        }
        break;
    case 3:
        func_002A3358();
        return 0;
    case 4:
        {
            O05L2 *q = D_800E59E0;
            s32 y = q->f135C;
            s32 x = y - 1;
            s32 t = x >= 0 ? y - (y >= x) : 0;
            q->f135C = t;
        }
        if (D_800E59E0->f135C <= 0) {
            if (func_00419FB8(D_800E59E0->f1360) != 0) {
                func_00419FA4(D_800E59E0->f1360);
                D_800E59E0->f1358 = 3;
            }
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        p = D_800E59E0;
        p->f1358 = 2;
        p->f135C = 4;
        func_0040E958(p->f1364, 0);
        for (row = 0; row < 4; row++) {
            for (col = 0; col < 5; col++) {
                func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E5A06[row].w[col * 2]), 0);
            }
            func_0040E958(D_800E59E0->row[row].f4C8, 0);
        }
        break;
    }
    return 0;
}
