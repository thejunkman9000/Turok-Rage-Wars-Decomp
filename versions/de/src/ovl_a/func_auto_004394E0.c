#include "o05_types.h"

typedef struct { void *f0; s32 f4; } O05M5950;
typedef struct { u8 pad78[0x78]; u8 b78; u8 pad79[0x96 - 0x79]; } O05R150B;
typedef struct { u8 pad0[0x1310]; O05R150B rec[8]; } O05Big;
extern O05Big D_80145088;
extern O05GameState D_801462C8;
extern u8 D_80102B00[];
extern u8 D_8011FE88[];
extern O05M5950 *D_800E5950;
void *func_00252FFC(s32 n);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_0040C4A8(s32 a);
void func_002A338C(void);
void *func_0040ECB0(void *a, s32 b);
void func_0022EF20(void *p);
void func_002A33F8(f32 f);

s32 func_auto_004394E0(void *w) {
    s32 i;
    O05Big *b;
    O05GameState *g;
    O05R150B *r;
    D_800E5950 = func_00252FFC(8);
    b = &D_80145088;
    func_0044AFC0(b, 0);
    func_0044A600((u8 *)b - 0x48, 0, 0);
    func_00286A78(D_8011FE88, 0, 0);
    if (func_0025471C() == 0) {
        func_0025470C(1);
    }
    func_0040C4A8(0);
    func_002A338C();
    r = b->rec;
    for (i = 7; i >= 0; i--) {
        r[i].b78 = 0;
    }
    D_800E5950->f0 = func_0040ECB0(w, 0x391);
    D_800E5950->f4 = 0;
    g = &D_801462C8;
    g->f24 = 10;
    g->f25 = 10;
    for (i = 0; i < 4; i++) {
        func_0022EF20(D_80102B00 + i * 0x190);
    }
    func_002A33F8(0.0f);
    return 0;
}
