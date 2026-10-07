#include "b04_types.h"
extern DlCmd *D_80110634;
extern u8 D_8011FAC0[];
extern f32 D_800C73C0;
extern s32 D_800CE72C;
extern u8 D_800D0EE0[];
extern s32 D_800D297C;
extern s32 D_800E28D8;
typedef struct { f32 m[16]; } B04Mtx;
typedef struct { u8 pad0[8]; s32 unk8; u8 pad0C[0x84]; f32 unk90; f32 unk94; f32 unk98; f32 unk9C; f32 unkA0; u8 padA4[4]; Vec3f posA8; s32 unkB4; } B04O5;
typedef struct { u8 pad0[0x29C]; f32 f29C; f32 f2A0; f32 f2A4; f32 f2A8; } B04C5;
void func_0026D8F8(void *);
void func_0026D914(s32);
void func_0026E378(s32, s32);
void func_0026D980();
void func_0026D9D0();
void func_00291BF8(u8 *, s32, s32, s32, s32, s32);
void func_00272D20(B04Mtx *, f32, f32, f32);
void func_00273B08(B04Mtx *, f32);
void func_00273930(B04Mtx *, f32);
void func_002734B8(B04Mtx *, f32, f32, f32);
void func_00273DDC(B04Mtx *);
void func_0027302C(B04Mtx *, B04Mtx *);
void func_00273618(B04Mtx *, s32, f32, f32);
void func_002702EC(B04Mtx *, void *);
void func_00272908(B04Mtx *, Vec3f *, Vec3f *);
void func_0026DF30(s32, void *, u8 *, s32, s32);
void func_00219490(B04O5 *o, B04C5 *c) {
    B04Mtx m;
    B04Mtx m2;
    Vec3f v;
    DlCmd *g;
    B04Mtx *mp;
    func_0026D8F8(o);
    if (o->unk8 != 0 && o->unkB4 != 0) {
        func_0026D914(0xC0);
        func_0026E378(1, 0x20);
        g = D_80110634++;
        g->w0 = 0xE3000C00;
        g->w1 = 0x80000;
        g = D_80110634++;
        g->w0 = 0xE3001201;
        g->w1 = 0x2000;
        func_0026D980();
        func_00291BF8(D_8011FAC0, c->f2A4, c->f29C + c->f2A4, c->f2A8, c->f2A0 + c->f2A8, 0);
        func_00272D20(&m, o->unk90, o->unk94, o->unk98);
        func_00273B08(&m, o->unkA0);
        func_00273930(&m, o->unk9C);
        func_002734B8(&m, o->posA8.x, o->posA8.y, o->posA8.z);
        func_00273DDC(&m);
        mp = &m2;
        func_0027302C(mp, &m);
        if (D_800E28D8 == 2)
            func_00273618(mp, D_800CE72C, D_800C73C0, D_800C73C0);
        func_002702EC(mp, (u8 *)o + ((D_800D297C << 6) + 0x10));
        func_00272908(&m, &o->posA8, &v);
        func_0026DF30(o->unk8, (u8 *)o + ((D_800D297C << 6) + 0x10), D_800D0EE0, 0, -1);
        func_0026D9D0();
        func_0026D914(0);
        func_0026E378(0, 0x20);
    }
}
