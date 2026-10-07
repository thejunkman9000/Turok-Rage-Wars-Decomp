#include "o05_types.h"

typedef struct { u32 w0; u32 w1; } O05Gfx;
typedef struct { f32 m[4][4]; } O05Mtx;
typedef struct {
    u8 pad0[4];
    f32 f4;
    f32 f8;
    f32 fC;
    O05Vec3 v10;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    s32 f34;
    u8 pad38[0x38 - 0x38];
    u8 mtx38[0xB8 - 0x38];
    s32 fB8;
} O05Obj;
extern O05Gfx *D_80110634;
extern s32 D_800D15D0;
extern s32 D_800D297C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
typedef struct {
    u8 pad0[0x160];
    u8 view[0x29C - 0x160];
    f32 f29C;
    f32 f2A0;
    u8 pad2A4[0x380 - 0x2A4];
    O05Mtx mtx[4];
} O05Cam;
extern O05Cam D_801450C8[];
extern u8 D_8011FE88[];
extern void *D_800D0EF8;
void func_004171B8(s32 a);
void func_0026D844(void);
void func_00272908(void *m, O05Vec3 *in, O05Vec3 *out);
void func_00272CD0(void *m, O05Vec3 v);
s32 func_002A2934(void);
void func_00273860(void *m, f32 a);
void func_00273A34(void *m, f32 a);
void func_00273C08(void *m, f32 a);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_00273DDC(void *m);
void func_002702EC(void *m, void *dst);
s32 func_0028C174(void *a, s32 b);
s32 func_0026D980();
void func_0026DF30(s32 a, void *b, void *c, s32 d, s32 e);
void func_0026D9D0(void);

void func_004399D0(O05Obj *o) {
    O05Mtx m;
    O05Vec3 v58;
    O05Vec3 v68;
    f32 v78[3];
    O05Gfx *g;
    s32 saved = D_800D15D0;
    f32 t;
    f32 sc;
    s32 h;
    D_800D15D0 = 0;
    if (o->f34 != -1) {
        func_004171B8(0x33335);
        g = D_80110634++;
        g->w0 = 0xE7000000;
        g->w1 = 0;
        g = D_80110634++;
        g->w0 = 0xE3000A01;
        g->w1 = 0x100000;
        g = D_80110634++;
        g->w0 = 0xE3000C00;
        g->w1 = 0x80000;
        g = D_80110634++;
        g->w0 = 0xE3001201;
        g->w1 = 0x2000;
        func_0026D844();
        g = D_80110634++;
        g->w0 = 0xDA380007;
        g->w1 = (u32)&D_801450C8->mtx[D_800D297C];
        v58 = o->v10;
        func_00272908(D_801450C8->view, &v58, &v68);
        func_00272CD0(&m, v68);
        t = (f32)func_002A2934();
        if (o->f28 != 0.0f) {
            func_00273860(&m, t * o->f28 * 0.017453294f);
        }
        if (o->f2C != 0.0f) {
            func_00273A34(&m, t * o->f2C * 0.017453294f);
        }
        if (o->f30 != 0.0f) {
            func_00273C08(&m, t * o->f30 * 0.017453294f);
        }
        if (o->f1C != 0.0f) {
            func_00273860(&m, o->f1C * 0.017453294f);
        }
        if (o->f20 != 0.0f) {
            func_00273A34(&m, o->f20 * 0.017453294f);
        }
        if (o->f24 != 0.0f) {
            func_00273C08(&m, o->f24 * 0.017453294f);
        }
        sc = D_801450C8->f29C / (f32)D_800E28D0;
        v78[0] = o->f4 * sc;
        v78[2] = o->fC * sc;
        v78[1] = o->f8 * (D_801450C8->f2A0 / (f32)D_800E28D4);
        func_002734EC(&m, v78[0], v78[1], v78[2]);
        func_00273DDC(&m);
        func_002702EC(&m, (u8 *)o + D_800D297C * 64 + 0x38);
        func_0028C174(D_8011FE88, o->f34);
        h = func_0026D980();
        func_0026DF30(h, (u8 *)o + D_800D297C * 64 + 0x38, D_800D0EF8, 0, o->fB8);
        func_0026D9D0();
    }
    D_800D15D0 = saved;
}
