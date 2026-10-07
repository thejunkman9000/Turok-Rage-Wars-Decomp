#include "m01_types.h"
#include "r01_types.h"

typedef struct R1Ctl {
    /* 0x00 */ u32 flags;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[0x2C];
    /* 0x34 */ s8 b34;
    /* 0x35 */ u8 pad35[0x33];
    /* 0x68 */ M1Actor *unk68;
    /* 0x6C */ u8 pad6C[0xC];
    /* 0x78 */ s32 unk78;
    /* 0x7C */ u8 pad7C[0x4];
    /* 0x80 */ M1Actor *unk80;
    /* 0x84 */ u8 pad84[0x4];
    /* 0x88 */ M1Actor *unk88;
    /* 0x8C */ u8 pad8C[0x8];
    /* 0x94 */ s8 b94;
    /* 0x95 */ u8 pad95[0x7];
    /* 0x9C */ f32 f9C;
    /* 0xA0 */ u8 padA0[0x10];
    /* 0xB0 */ Vec3f vB0;
    /* 0xBC */ u8 padBC[0x12];
    /* 0xCE */ s8 bCE;
} R1Ctl;

extern s32 D_80120DE0;
extern s32 D_8013B290;
extern f32 D_800C7268[];
M1Actor *func_002149C0(M1Actor *a, R1Ctl *c, s32 x, s32 y);
f32 func_00216F44(M1Actor *a, Vec3f p);
M1CamRec *func_00219408(void *h);
void func_00274090(f32 *v);
void func_00271FD8(f32 *dst, Vec3f *a, Vec3f *b);

static inline s32 r1_class(M1Actor *actor, R1Ctl *ctl, M1Actor *t) {
    s32 c;

    if (ctl->unk4 != 0) {
        if (t != NULL) {
            if (t != ctl->unk68) {
                if (t->def->kind != 5) {
                    if (t->unkE4 != 0x64F) {
                        if (D_8013B290 == 0) {
                            if ((t->flags & 0x300000) && t->owner->unk794 == actor && t->owner->unk788 == 2) {
                                c = 1;
                            } else if ((actor->unk2E0 & 2) && actor->unkE4 != 0xCA) {
                                c = 1;
                            } else {
                                c = 0;
                            }
                        } else {
                            c = 0;
                        }
                    } else {
                        c = 7;
                    }
                } else {
                    c = 5;
                }
            } else {
                c = 2;
            }
        } else {
            c = 3;
            if (ctl->b94 != 0) {
                c = 4;
            }
        }
    } else {
        c = 6;
    }
    return c;
}

void func_00215410(M1Actor *actor, R1Ctl *ctl, s32 unused, R1Sel *out) {
    Vec3f P;
    Vec3f D;
    f32 ang;
    M1Actor *tgt;
    s32 cls;
    M1CamRec *rec;

    if (ctl->bCE == D_80120DE0 && !(actor->def->unk4 & 0x400) && (!(ctl->flags & 0x80000) || ctl->unk78 != 0)) {
        ctl->unk80 = func_002149C0(actor, ctl, 1, 0);
    }
    if (actor->def->kind == 1 && ctl->b34 == 0xB && r1_class(actor, ctl, ctl->unk88) == 4) {
        cls = 4;
        tgt = ctl->unk88;
    } else {
        tgt = ctl->unk80;
        cls = r1_class(actor, ctl, tgt);
    }
    if (tgt != NULL) {
        P = tgt->pos;
        ang = func_00216F44(actor, P);
    } else {
        switch (cls) {
        case 4:
            rec = func_00219408((u8 *)ctl + 0x94);
            P = rec->pos;
            if (rec->fw.u & 1) {
                ang = rec->f10 * D_800C7268[1] - actor->f6C;
            } else {
                ang = func_00216F44(actor, P);
            }
            break;
        case 3:
            P = ctl->vB0;
            ang = ctl->f9C - actor->f6C;
            break;
        case 6:
            P = actor->pos;
            ang = 0.0f;
            break;
        }
    }
    func_00274090(&ang);
    func_00271FD8((f32 *)&D, &P, &actor->pos);
    out->cls = cls;
    out->tgt = tgt;
    out->ang = ang;
    out->p = P;
    out->d = D;
    out->len = sqrtf(D.x * D.x + D.y * D.y + D.z * D.z);
    D.y = 0.0f;
    P.y = 0;
    out->p2 = P;
    out->d2 = D;
    out->len2 = sqrtf(D.x * D.x + D.y * D.y + D.z * D.z);
}
