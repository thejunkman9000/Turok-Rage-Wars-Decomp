#include "b15_types.h"

typedef struct B15Cam {
    u8 pad0[0xE4];
    Vec3f posE4;
    Vec3f vecF0;
} B15Cam;

typedef struct B15Fx {
    u8 pad0[0x6C];
    f32 unk6C;
    u8 pad70[0x168];
    s32 unk1D8;
    u8 pad1DC[0xC4];
    Vec3f vec2A0;
} B15Fx;

typedef struct B15Own {
    u8 pad0[0x6C];
    f32 unk6C;
    u8 pad70[0x1178];
    B15Fx *unk11E8;
} B15Own;

typedef struct B15Spawner {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ Vec3f vel;
} B15Spawner;

typedef struct B15Tgt {
    u8 type;
    u8 pad1[0xFF];
    u32 flags;
    u8 pad104[0xD4];
    B15Own *owner;
} B15Tgt;

B15Fx *func_002627C0(void *tab, s32 type, s32 a, Vec3f pos, s32 b, Vec3f vel, Vec3f scale, s32 c);
void func_00262CA8(B15Fx *fx);
s32 func_002833A4(B15Tgt *t);
extern B15Cam *D_80103FCC;
extern u8 D_80135210[];

void func_auto_0026851C(B15Spawner *src, B15Tgt *tgt, s32 c, Vec3f pos, B15PairF k) {
    Vec3f sc;
    Vec3f vel;
    B15Fx *fx;
    B15Own *o;

    if (k.a == 0x321) {
        return;
    }

    if (src->type == 0) {
        vel.x = 0;
        vel.y = 0;
        vel.z = 0;
    } else {
        vel = src->vel;
    }
    pos = src->pos;
    sc.x = k.b;
    sc.y = k.b;
    sc.z = k.b;
    if (k.a == 0x40C) {
        pos = D_80103FCC->posE4;
        vel.x = 0;
        vel.y = 0;
        vel.z = 0;
    }
    fx = func_002627C0(D_80135210, k.a, src->unk14, pos, 0, vel, sc, 0);
    if (fx != NULL) {
        if (k.a == 0x40C) {
            fx->unk1D8 = func_002833A4(tgt);
            fx->vec2A0.x = D_80103FCC->vecF0.x;
            fx->vec2A0.y = D_80103FCC->vecF0.y;
            fx->vec2A0.z = D_80103FCC->vecF0.z;
        } else if ((u32)(k.a - 0x474) < 4) {
            if (tgt->type == 1 && (tgt->flags & 0x300000)) {
                o = tgt->owner;
                if (o != NULL) {
                    o->unk11E8 = fx;
                    fx->unk6C = o->unk6C;
                }
            } else {
                func_00262CA8(fx);
            }
        }
    }
}
