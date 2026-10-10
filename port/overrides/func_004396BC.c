#include "o05_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);

typedef struct { void *f0; s32 f4; } O05M50;
extern O05M50 *D_800E5950;
extern u8 D_80145088[];
extern u8 D_8011FE88[];
typedef struct { u8 pad[0x24]; u8 f24; u8 f25; } O05GX;
extern O05GX D_801462C8[];
extern O05Rec D_80102B00[];
void *func_00252FFC(s32 n);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_0040C4A8(s32 a);
void func_002A338C(void);
void *func_0040ECB0(void *cfg, s32 id);
void func_0022EF20(void *p);
void func_002A33F8(f32 x);

s32 func_004396BC(void *cfg) {
    { static int n; if (n++ < 3) fprintf(__acrt_iob_func(2), "HANDLER 004396BC called\n"); }
    s32 i;
    u8 *p;
    D_800E5950 = func_00252FFC(8);
    func_0044AFC0(D_80145088, 0);
    func_0044A600(D_80145088 - 0x48, 0, 0);
    { extern char *getenv(const char *); extern int atoi(const char *); char *e = getenv("TUROK_LEVEL"); func_00286A78(D_8011FE88, e ? atoi(e) : 0, 0); }   /* TUROK_LEVEL=<map index 0..35>: start the custom match on that map (docs/ROM_MAPS.md) */
    if (func_0025471C() == 0) {
        func_0025470C(1);
    }
    func_0040C4A8(0);
    func_002A338C();
    i = 7;
    p = D_80145088 + 0x172A;
    for (; i >= 0; i--) {
        p[0x78] = 0;
        p -= 0x96;
    }
    D_800E5950->f0 = func_0040ECB0(cfg, 0x397);
    D_800E5950->f4 = 0;
    D_801462C8->f24 = 10;
    D_801462C8->f25 = 10;
    {   /* port: TUROK_TIMELIMIT=<minutes> / TUROK_FRAGLIMIT=<n> override the 10/10 defaults of a custom match (end-of-match tests) */
        extern char *getenv(const char *); extern int atoi(const char *); const char *e;
        if ((e = getenv("TUROK_TIMELIMIT")) != 0) D_801462C8->f24 = (u8)atoi(e);
        if ((e = getenv("TUROK_FRAGLIMIT")) != 0) D_801462C8->f25 = (u8)atoi(e);
    }
    for (i = 0; i < 4; i++) {
        func_0022EF20(&D_80102B00[i]);
    }
    func_002A33F8(0.0f);
    return 0;
}
