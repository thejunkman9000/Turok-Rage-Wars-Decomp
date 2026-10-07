#include "b05_types.h"

typedef struct B05Quat { f32 x, y, z, w; } B05Quat;

typedef struct B05Tgt {
    /* 0x000 */ u8 type;
    u8 pad1[7];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x5C];
    /* 0x070 */ f32 f70;
    u8 pad74[0x1D4];
    /* 0x248 */ Vec3f v248;
} B05Tgt;

typedef struct B05P19 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x580];
    /* 0x594 */ s32 mode;
    u8 pad598[0x40];
    /* 0x5D8 */ void* stats;
    /* 0x5DC */ void* pawn;
    u8 pad5E0[0x4E];
    /* 0x62E */ s16 s62E;
    u8 pad630[0x158];
    /* 0x788 */ s32 unk788;
    /* 0x78C */ f32 f78C;
    u8 pad790[0x4];
    /* 0x794 */ void* tgt794;
    /* 0x798 */ s32 unk798;
    /* 0x79C */ Vec3f v79C;
    /* 0x7A8 */ Vec3f v7A8;
    /* 0x7B4 */ void* tgt7B4;
    /* 0x7B8 */ s32 unk7B8;
    u8 pad7BC[0x4];
    /* 0x7C0 */ Vec3f v7C0;
    /* 0x7CC */ Vec3f v7CC;
    /* 0x7D8 */ B05Quat q7D8;
    /* 0x7E8 */ s32 unk7E8;
    u8 pad7EC[0xA24];
    /* 0x1210 */ s32 unk1210;
    u8 pad1214[0x244];
    /* 0x1458 */ Vec3f v1458;
    /* 0x1464 */ Vec3f v1464;
    /* 0x1470 */ Vec3f v1470;
    /* 0x147C */ void* p147C;
} B05P19;

typedef struct B05Pawn { u8 pad0[0x24]; s32 unk24; u8 pad28[0x100]; Vec3f v128; u8 pad134[0x2C]; f32 m160[1]; } B05Pawn;
typedef struct B05Hit {
    /* 0x00 */ B05Tgt *tgt;
    u8 pad4[0xE0];
    /* 0xE4 */ Vec3f vE4;
    /* 0xF0 */ Vec3f vF0;
} B05Hit;
typedef struct B05Row19 { u8 pad0[0xE]; s16 sE; s16 s10; } B05Row19;

extern const f32 D_800C74A4;
extern const f32 D_800C74A8;
extern f32 D_800C74AC;
extern f32 D_800C74B0;
extern f32 D_800C74B4;
extern const f32 D_800C74B8;
extern const f32 D_800C74BC;
extern f32 D_800C74C0;
extern B05Row19 *D_800D052C[];
extern f32 D_800D2988;
extern B05Hit *D_80103FCC;
extern u8 D_80103FD0[];
extern u8 D_801040F0[];

f32 sqrtf_(f32) __asm__("sqrtf");
s32 func_0021CD70(B05P19 *, B05Tgt *);
void func_0021CF04(f32 *, B05P19 *, B05Tgt **, Vec3f *);
void func_0021D3E4(B05P19 *, Vec3f *, void *);
void func_00226DAC(B05P19 *, f32 *);
void func_0022B134(B05P19 *, Vec3f *);
s32 func_00244494(B05P19 *, Vec3f, Vec3f, void *);
void func_0024795C(f32 *, B05P19 *);
f32 func_0024D274(B05Tgt *);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_00271FD8(Vec3f *, Vec3f *, Vec3f *);
void func_0027200C(Vec3f *, Vec3f *, f32);
void func_002720EC(Vec3f *);
void func_00272908(f32 *, Vec3f *, Vec3f *);
void func_0027302C(f32 *, void *);

void func_0021D750(B05P19 *p) {
    Vec3f v20;
    Vec3f v30;
    Vec3f v40;
    Vec3f v50;
    f32 m60[16];
    Vec3f vA0;
    B05Quat qB0;
    Vec3f vC0;
    Vec3f vD0;
    Vec3f vE0;
    B05Tgt *tF0;
    B05Tgt *tF4;
    B05Pawn *pw;
    B05Tgt *h;
    Vec3f *va;
    f32 fs1f;
    f32 fs2;
    f32 fs0f;
    f32 fs1;
    f32 fs0;
    f32 len;
    s32 s4;
    s32 s5;
    s32 s0;
    s32 st;

    tF0 = NULL;
    pw = p->pawn;
    fs1f = D_800C74A4;
    fs2 = D_800C74A8;
    if (pw != NULL) {
        if (pw->unk24 == 1) {
            func_00226DAC(p, m60);
            func_0022B134(p, &vA0);
        } else {
            func_0027302C(m60, &pw->m160);
            vA0 = pw->v128;
        }
    } else {
        func_00226DAC(p, m60);
        func_0022B134(p, &vA0);
    }
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = D_800C74AC;
    func_00272908(m60, &v30, &v50);
    if (func_00244494(p, vA0, v50, D_80103FD0) != 0) {
        p->v1458 = D_80103FCC->vE4;
        p->v1470 = D_80103FCC->vF0;
        p->p147C = D_80103FCC->tgt;
    } else {
        p->v1458 = v50;
        p->p147C = NULL;
    }
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = D_800C74B0;
    func_00272908(m60, &v30, &v50);
    if (p->unk1210 != 0) {
        if (func_00244494(p, vA0, v50, D_801040F0) != 0 && (h = D_80103FCC->tgt) != NULL &&
            h->type == 1 && (*(u32 *)((u8 *)h + 0x100) & 0x300000)) {
            func_00271FD8((Vec3f *)&qB0, &h->pos, &p->pos);
            len = sqrtf_(qB0.x * qB0.x + qB0.y * qB0.y + qB0.z * qB0.z);
            vE0 = v30;
            func_002720EC(&vE0);
            func_0027200C(&vC0, &vE0, len);
            func_00272908(m60, &vC0, &vD0);
            p->v1464 = vD0;
            func_0021D3E4(p, &vD0, (u8 *)D_80103FCC + 0xF0);
        } else {
            p->v1464 = p->v1458;
            func_0021D3E4(p, &p->v1458, (u8 *)D_80103FCC + 0xF0);
        }
    } else {
        p->v1464 = v50;
    }
    if (p->s62E == 1 && p->mode == 2) {
        s4 = 0x2C6;
    } else {
        s4 = D_800D052C[p->s62E]->sE;
    }
    s5 = s4 + 0x64;
    s0 = 1;
    if (p->s62E == 1 || p->s62E == 0x12) {
        fs0f = D_800C74B4;
        fs1 = fs0f;
    } else {
        fs0f = 0.0f;
        fs1 = 0.0f;
    }
    switch (p->s62E) {
    case 7:
        if (p->unk7E8 != 0) {
            s4 = 0x2E4;
            s5 = -1;
        }
        break;
    case 2:
        if (p->unk7E8 != 0) {
            s4 = 0x2BC;
            s5 = -1;
        }
        break;
    case 1:
    case 0x12:
        func_0021CF04((f32 *)&qB0, p, &tF0, &v20);
        s0 = 0;
        break;
    default:
        s5 = -1;
        break;
    }
    func_0024795C((f32 *)&qB0, p);
    p->q7D8 = qB0;
    vC0 = p->v1458;
    vC0.x -= D_800C74B8;
    vD0 = p->v1458;
    vD0.x += D_800C74B8;
    vC0 = p->v1458;
    vC0.z -= D_800C74B8;
    vD0 = p->v1458;
    vD0.z += D_800C74B8;
    vC0 = p->v1458;
    vC0.y -= D_800C74B8;
    vD0 = p->v1458;
    vD0.y += D_800C74B8;
    if (tF0 == NULL) {
        v20 = v50;
        if (((u8 *)p->stats)[0x7E] != 0 && s0 != 0) {
            func_0021CF04((f32 *)&vD0, p, &tF4, &vC0);
            if (tF4 != NULL) {
                p->q7D8 = *(B05Quat *)&vD0;
            }
        }
        if (tF0 == NULL) {
            p->tgt794 = NULL;
        }
    }
    if (s4 == -1) {
        p->unk788 = 0;
    } else if (p->unk788 == 0) {
        p->unk788 = 1;
        p->v79C = v50;
        p->v7A8.x = 0.0f;
        p->v7A8.y = 0.0f;
        p->v7A8.z = 0.0f;
        p->v7C0 = v50;
        p->v7CC.x = 0.0f;
        p->v7CC.y = 0.0f;
        p->v7CC.z = 0.0f;
    }
    fs0 = D_800C74BC;
    func_00271FD8(&v40, &v20, &p->v7C0);
    func_0027200C(&v40, &v40, fs1f * fs0);
    func_00271FA4(&p->v7CC, &p->v7CC, &v40);
    func_00271FA4(&p->v7C0, &p->v7C0, &p->v7CC);
    func_0027200C(&p->v7CC, &p->v7CC, fs2 * fs0);
    if (tF0 != NULL) {
        p->unk7B8 = D_800D052C[p->s62E]->s10 + 0x64;
    } else {
        p->unk7B8 = s5;
    }
    switch (p->unk788) {
    case 1:
        if (tF0 == NULL || p->tgt794 != tF0) {
            p->tgt794 = tF0;
            p->f78C = 0.0f;
        }
        p->f78C = p->f78C + D_800D2988;
        if (fs1 <= p->f78C) {
            p->unk788 = 2;
            p->f78C = 0.0f;
        }
        goto L82;
    case 2:
        if (p->tgt7B4 != tF0) {
            p->tgt7B4 = tF0;
            p->f78C = 0.0f;
        } else {
            p->f78C = p->f78C + D_800D2988;
        }
        if (tF0 != NULL && p->tgt794 != tF0 && fs0f <= p->f78C) {
            p->tgt794 = tF0;
            p->f78C = 0.0f;
        }
        tF0 = p->tgt794;
        if (tF0 != NULL) {
            if (func_0021CD70(p, tF0) == 0) {
                p->unk788 = 1;
                p->f78C = 0.0f;
            }
            if (p->s62E == 0x12) {
                v20 = tF0->v248;
            } else {
                v20 = tF0->pos;
                v20.y += tF0->f70;
                v20.y += func_0024D274(tF0) * D_800C74C0;
            }
            if (p->s62E == 1 && p->mode == 2) {
                s4 = 0x2C7;
            } else {
                s4 = D_800D052C[p->s62E]->s10;
            }
        } else {
            goto L82;
        }
        break;
    case 0:
L82:
        v20 = v50;
        break;
    default:
        break;
    }
    va = &v40;
    func_00271FD8(va, &v20, &p->v79C);
    func_0027200C(&v40, &v40, fs1f);
    func_00271FA4(&p->v7A8, &p->v7A8, &v40);
    func_00271FA4(&p->v79C, &p->v79C, &p->v7A8);
    func_0027200C(&p->v7A8, &p->v7A8, fs2);
    p->unk798 = s4;
}
