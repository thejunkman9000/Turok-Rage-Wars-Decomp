#include "o04_types.h"
#include "q03_types.h"
typedef struct { u8 pad0[0x190]; } Q03Row190v;
extern Q03Cfg D_801462C8[];
extern O04GFlags D_801468A0[];
extern Q03Row190v D_80102B00[];
extern u8 *D_800E4680;
extern u8 D_80102C89[];
extern u8 D_80102C8A[];
extern u8 D_80102C8B[];
extern u8 D_80102C8C[];
extern u8 D_80102C8D[];
extern s32 D_8015402C;
extern s32 D_80154028;
extern s32 D_80146948;
void func_0029A73C(void);
void func_00299368(s32 a);
void func_002A3304(void);
u8 *func_00425E50(s32 a, s32 b, s32 c);
void func_0042E3D0(void);
void func_0042ED84(void);
void func_0042ECF0(void);
void func_0042EEB8(void);
void func_0042EE18(void);
void func_002A125C(char *dst, char *src);
void func_0040C4A8(s32 a);
s32 func_0025E2E4(void);
s32 func_00274544(void);
void func_0025E2F4(s32 a);
void func_0042E080(void) {
    Q03Ent *e;
    Q03Cfg *g;
    s32 s6;
    s32 i;
    s32 k;
    s32 fp;
    func_0029A73C();
    func_00299368(2);
    func_002A3304();
    s6 = 0;
    g = D_801462C8;
    for (i = 0; i < 8; i++) {
        e = &g->ent[i];
        e->f94 = 0;
        e->f95 = 0;
        if (e->f91 == 0) {
            e->f92 = 0xFF;
        }
        if (e->f91 == 0 && e->f78 == 1) {
            s6++;
        }
    }
    D_801468A0->unk98 = 0;
    D_801468A0->unk90 = 0;
    D_800E4680 = 0;
    if (g->unkD != 0) {
        k = 0;
        while (g->ent[k].f78 == 0) {
            k++;
        }
        e = &g->ent[k];
        switch (g->unkD) {
        case 1:
            D_800E4680 = func_00425E50(D_8015402C, 0, e->f80);
            break;
        case 2:
            D_800E4680 = func_00425E50(D_8015402C, 1, 0);
            break;
        case 3:
            D_800E4680 = func_00425E50(D_8015402C, 3, 0);
            break;
        case 4:
            D_800E4680 = func_00425E50(D_8015402C, 2, 0);
            break;
        }
        D_80146948 = 0;
        func_0042E3D0();
    }
    switch (D_80154028) {
    case 0:
        func_0042ED84();
        break;
    case 1:
        func_0042ECF0();
        break;
    case 2:
        func_0042EEB8();
        break;
    case 3:
        func_0042EE18();
        break;
    }
    i = 0;
    fp = 1;
    for (; i < 4; i++) {
        e = &g->ent[i];
        if (e->f78 == fp && e->f91 == 0) {
            func_002A125C(e->name, (char *)&D_80102B00[i]);
            if (g->unkD != 0) {
                e->f92 = 0;
            } else {
                e->f92 = 0xFF;
            }
            e->f7B = D_80102C89[i * 0x190];
            e->f7D = D_80102C8A[i * 0x190];
            e->f79 = D_80102C8B[i * 0x190];
            e->f7A = D_80102C8C[i * 0x190];
            e->f82 = D_80102C8D[i * 0x190];
        }
    }
    if (D_801462C8->unk580 == 2) {
        if (s6 >= 2) {
            func_0040C4A8(1);
        } else {
            func_0040C4A8(D_801462C8->unk580);
        }
    } else {
        func_0040C4A8(D_801462C8->unk580);
    }
    if (func_0025E2E4()) {
        func_0025E2F4(func_00274544() % 4 + 0x38);
    }
}
