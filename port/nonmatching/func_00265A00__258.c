#include "m04_types.h"

typedef struct M04Gfx {
    u32 w0;
    u32 w1;
} M04Gfx;

typedef struct M04Vtx {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ u8 c6;
    /* 0x07 */ u8 c7;
    /* 0x08 */ u8 c8;
    /* 0x09 */ u8 c9;
    /* 0x0A */ s16 wA;
    /* 0x0C */ s16 wC;
    /* 0x0E */ s16 wE;
} M04Vtx;

typedef struct M04LtDef {
    /* 0x00 */ u16 w0;
    /* 0x02 */ u16 w2;
    /* 0x04 */ u8 b4;
    /* 0x05 */ u8 b5;
    /* 0x06 */ u8 b6;
    /* 0x07 */ u8 b7;
} M04LtDef;

typedef struct M04Lt {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ M04LtDef *def;
    /* 0x0C */ f32 k;
    /* 0x10 */ s16 x;
    /* 0x12 */ s16 y;
    /* 0x14 */ s16 z;
    /* 0x16 */ s16 on;
} M04Lt;

extern M04Vtx D_80110160[];
extern s32 D_80110560;
extern M04Gfx *D_80110634;
extern u8 D_8013B1A8[];
M04Lt *func_00268CBC(void *l);
M04Lt *func_00268CC8(void *l, M04Lt *n, u32 f);
void func_00272908(void *m, M04Vec3 *v, M04Vec3 *o);

void func_00265A00(u8 *mtx) {
    M04Lt *n;
    M04LtDef *def;
    M04Gfx *d;
    M04Vec3 v;
    M04Vec3 o;
    s32 i;
    n = func_00268CBC(D_8013B1A8);
    if (n == 0) {
        d = D_80110634++;
        d->w0 = 0xD9FFFF7F;
        d->w1 = 0;
        D_80110560 += 8;
        return;
    }
    i = 0;
    d = D_80110634++;
    d->w0 = 0xD9FFFFFF;
    d->w1 = 0x80;
    do {
        if (n != 0 && n->on != 0) {
            def = n->def;
            v.x = n->x;
            v.y = n->y;
            v.z = n->z;
            func_00272908(mtx + 0x220, &v, &o);
            D_80110160[i + D_80110560].x = -(s32)o.x;
            D_80110160[i + D_80110560].y = (s32)o.y;
            D_80110160[i + D_80110560].z = -(s32)o.z;
            D_80110160[i + D_80110560].c9 = (u32)((f32)def->b7 * n->k);
            D_80110160[i + D_80110560].c8 = (u32)((f32)def->b4 * n->k);
            D_80110160[i + D_80110560].c7 = (u32)((f32)def->b5 * n->k);
            D_80110160[i + D_80110560].c6 = (u32)((f32)def->b6 * n->k);
            D_80110160[i + D_80110560].wA = def->w0;
            D_80110160[i + D_80110560].wE = 0x7F80;
            D_80110160[i + D_80110560].wC = def->w2;
        } else {
            D_80110160[i + D_80110560].wA = -0x8000;
        }
        if (n != 0) {
            n = func_00268CC8(D_8013B1A8, n, 0xDC080000);
        }
        d = D_80110634++;
        i++;
        d->w0 = (((i * 2 + 0xA) & 0xFF) << 8) | 0xDC08000A;
        d->w1 = (u32)&D_80110160[i - 1 + D_80110560];
    } while (i < 8);
    D_80110560 += 8;
}
