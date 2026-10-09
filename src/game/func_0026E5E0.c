#include "b16_types.h"

typedef struct B16Ent {
    Vec3f pos;
    u32 flags;
    u16 bone;
    u16 pad;
} B16Ent;

typedef struct B16Obj B16Obj;
struct B16Obj {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s32 *def;
    /* 0x01C */ u8 pad1C[0x188];
    /* 0x1A4 */ s8 unk1A4;
    /* 0x1A5 */ u8 pad1A5[0xB];
    /* 0x1B0 */ f32 unk1B0;
    /* 0x1B4 */ u8 pad1B4[0x24];
    /* 0x1D8 */ B16Obj *owner;
    /* 0x1DC */ u8 pad1DC[0x6C];
    /* 0x248 */ Vec3f unk248;
    /* 0x254 */ Vec3f unk254;
    /* 0x260 */ Vec3f unk260;
    /* 0x26C */ u8 pad26C[0x74];
    /* 0x2E0 */ u32 unk2E0;
    /* 0x2E4 */ u8 pad2E4[0x36C];
    /* 0x650 */ s16 unk650;
};

typedef struct B16Part {
    s16 a;
    s16 b;
    u8 c[4];
} __attribute__((aligned(4))) B16Part;

extern u8 D_80121990[];

void func_00216288();
void func_0024E78C();
void func_00265E30();
void func_00280094();
f32 func_0024BF14(B16Obj *o);
B16Vec4 func_00271888(Vec3f *v);
void func_00272908(B16Mtx *m, Vec3f *v, Vec3f *dst);
void func_0027200C(Vec3f *dst, Vec3f *a, f32 s);

void func_0026E5E0(B16Ent *ents, s32 n, B16Mtx *mtxs, B16Obj *obj, u8 *tab) {
    s32 i;
    s32 s2;
    s32 flag;
    s32 kind;
    Vec3f pos;
    Vec3f v60;
    Vec3f v70;
    B16Vec4 q;
    B16Part part;
    f32 len;
    s32 v98;

    for (i = n - 1; i != -1; i--) {
        if (ents->flags & obj->unk2E0) {
            flag = (tab[ents->bone * *(s32 *)tab + 0x6E] == 5) * 2;
            func_00272908(&mtxs[ents->bone], &ents->pos, &pos);
            func_0027200C(&pos, &pos, 1.0f / 65536.0f);
            s2 = 0;
            switch (ents->flags) {
        case 0x2:
            func_00216288(obj, 0x51, pos, flag);
            break;
        case 0x8:
            func_00216288(obj, 0x5C, pos, flag);
            break;
        case 0x20:
            break;
        case 0x40:
            obj->unk248 = pos;
            kind = *obj->def;
            if ((kind == 1 && obj->unk1A4 == 0x21) || (kind == 0xB && obj->owner->unk650 == 0x26)) {
                func_0024E78C(obj, pos, &v60, &v98, 0, 1);
                q = func_00271888(&obj->unk254);
                v70.x = 0;
                v70.y = 0;
                v70.z = 0;
                if (obj->unk1B0 < 15.0f) {
                    func_00280094(&D_80121990, obj, obj, 0, 0, 0xE6, v70, q, v60, 0, -1, flag | 1);
                }
                func_00280094(&D_80121990, obj, obj, 0, 0, 0x8A, v70, q, v60, 0, -1, flag | 1);
            }
            break;
        case 0x80:
            func_00216288(obj, 0xAC, pos, flag);
            break;
        case 0x100:
            func_00216288(obj, 0xAD, pos, flag);
            break;
        case 0x200:
            func_00216288(obj, 0xAE, pos, flag);
            break;
        case 0x400:
            func_00216288(obj, 0xAF, pos, flag);
            break;
        case 0x800:
            func_00216288(obj, 0xB0, pos, flag);
            break;
        case 0x1000:
            func_00216288(obj, 0xB1, pos, flag);
            break;
        case 0x2000:
            func_00216288(obj, 0xB2, pos, flag);
            break;
        case 0x4000:
            func_00216288(obj, 0xB3, pos, flag);
            break;
        case 0x8000:
            func_00216288(obj, 0xB4, pos, flag);
            break;
        case 0x10000:
            func_00216288(obj, 0xB5, pos, flag);
            break;
        case 0x20000:
            func_00216288(obj, 0xB6, pos, flag);
            break;
        case 0x40000:
            func_00216288(obj, 0xB7, pos, flag);
            break;
        case 0x80000:
            func_00216288(obj, 0xB8, pos, flag);
            break;
        case 0x100000:
            func_00216288(obj, 0xB9, pos, flag);
            break;
        case 0x200000:
            func_00216288(obj, 0xBA, pos, flag);
            break;
        case 0x400000:
            func_00216288(obj, 0xBB, pos, flag);
            break;
        case 0x20000000:
            func_00216288(obj, 0x1E9, pos, flag);
            break;
        case 0x40000000:
            func_00216288(obj, 0x1EA, pos, flag);
            break;
        case 0x80000000:
            func_00216288(obj, 0x1EB, pos, flag);
            break;
        case 0x8000000:
            func_00216288(obj, 0x11C, pos, flag);
            break;
        case 0x10000000:
            obj->unk260 = pos;
            break;
        case 0x800000:
            s2 = 5;
            break;
        case 0x2000000:
            s2 = 0xF;
            break;
        case 0x1000000:
            s2 = 0xA;
            break;
        case 0x4000000:
            s2 = 0x14;
            break;
        case 0x1:
        case 0x4:
        case 0x10:
        default:
            break;
            }
            if (s2 != 0) {
                len = func_0024BF14(obj);
                part.b = s2 << 8;
                part.c[0] = part.c[1] = part.c[2] = part.c[3] = 0;
                { f32 t = 5.0f; t = t / len; part.a = t * 256.0f; }
                func_00265E30(obj, obj, 3, -1, pos, part);
            }
        }
        ents++;
    }
}
