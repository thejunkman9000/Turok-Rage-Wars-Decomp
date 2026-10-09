#include "b05_types.h"

typedef struct B05P13 {
    u8 pad0[0xE4];
    /* 0x0E4 */ u16 unkE4;
    u8 padE6[0x3A6];
    /* 0x48C */ s8 b48C;
    u8 pad48D[0x96];
    /* 0x523 */ s8 b523;
    u8 pad524[0x70];
    /* 0x594 */ s32 mode;
    u8 pad598[0x8];
    /* 0x5A0 */ f32 f5A0;
    u8 pad5A4[0x34];
    /* 0x5D8 */ void* stats;
    u8 pad5DC[0x52];
    /* 0x62E */ s16 s62E;
    u8 pad630[0x20];
    /* 0x650 */ s16 state;
    u8 pad652[0x136];
    /* 0x788 */ s32 unk788;
    u8 pad78C[0xC];
    /* 0x798 */ s32 id798;
    /* 0x79C */ Vec3f v79C;
    u8 pad7A8[0x10];
    /* 0x7B8 */ s32 id7B8;
    /* 0x7BC */ f32 f7BC;
    /* 0x7C0 */ Vec3f v7C0;
} B05P13;

typedef struct B05Sta13 { u8 pad0[0x8F]; u8 b8F; } B05Sta13;

extern s32 D_800CE474[];
extern f32 D_800C74D0;
extern f32 D_800C74D4;
extern f32 D_800C74D8;
extern f32 D_800C74DC;
extern f32 D_800C74E0;
extern f32 D_800C7678;
extern f32 D_800C767C;
extern f32 D_800C7680;
extern f32 D_800C7684;
extern f32 D_800C7688;
extern f32 D_800D2988;
extern u8 D_801462E5;
extern u8 D_801462F3;
extern s32 D_801468F4;

s32 func_002A33AC();
void func_002AA224(s32);
void func_0021E068(void *, Vec3f *, s32, f32, f32, f32);

void func_0021E27C(B05P13 *p, void *s) {
    f32 val;
    s32 flag;
    s32 id;
    s32 b;

    p->f7BC = p->f7BC + D_800D2988;
    if (p->unk788 == 0) {
        return;
    }
    if (((B05Sta13 *)p->stats)->b8F == 1 && D_801468F4 != 0) {
        return;
    }
    if (p->state == 0x27) {
        return;
    }
    if (p->mode == 2 && p->s62E == 3) {
        return;
    }
    if (func_002A33AC() != 0) {
        return;
    }
    if (p->id798 == 0x2DA) {
        if (p->mode == 1) {
            if (p->unkE4 != D_800CE474[0] && p->unkE4 != D_800CE474[1]) {
                p->id798 = 0x2EF;
                if ((u32)((u8)p->b48C - 2) < 2) {
                    p->f7BC = 0;
                } else if (p->b523 != 0) {
                    p->f7BC = 0;
                } else {
                    p->f7BC = D_800C74D0;
                }
            }
        } else {
            if (p->unkE4 != D_800CE474[0]) {
                if (p->unkE4 != D_800CE474[1]) {
                    p->id798 = 0x2F1;
                    if (p->s62E == 9 && p->f5A0 > 0.0f) {
                        p->f7BC = D_800C74D0;
                    } else {
                        b = p->b48C;
                        if (b == 0xB || b == 3) {
                            p->f7BC = 0;
                        } else if (b == 2) {
                            p->f7BC = 0;
                        } else if (p->b523 != 0) {
                            p->f7BC = 0;
                        } else {
                            p->f7BC = D_800C74D0;
                        }
                    }
                } else {
                    p->id798 = 0x302;
                    p->f7BC = 0;
                }
            } else {
                p->id798 = 0x302;
                p->f7BC = 0;
            }
        }
    }
    func_002AA224(0xFF);
    id = p->id7B8;
    flag = 1;
    if (id == 0x2DA && D_801462E5 != 0) {
        flag = D_801462F3;
    }
    if (id != -1) {
        switch (id) {
        case 0x2DA:
        case 0x2EF:
        case 0x2F0:
            val = D_800C74D4;
            break;
        case 0x2BC:
        case 0x2E4:
        case 0x2F1:
        case 0x2F2:
        case 0x302:
        case 0x320:
        case 0x32A:
        case 0x32B:
        case 0x35C:
        case 0x35D:
            val = D_800C74D8;
            break;
        default:
            val = D_800C74DC;
            break;
        }
        if (flag != 0) {
            func_0021E068(s, &p->v7C0, id, p->f7BC, val, D_800C74E0);
        }
    }
    id = p->id798;
    flag = 1;
    if (id == 0x2DA && D_801462E5 != 0) {
        flag = D_801462F3;
    }
    if (id != -1) {
        switch (id) {
        case 0x2DA:
        case 0x2EF:
        case 0x2F0:
            val = D_800C767C;
            break;
        case 0x2BC:
        case 0x2E4:
        case 0x2F1:
        case 0x2F2:
        case 0x302:
        case 0x320:
            val = D_800C7680;
            break;
        case 0x2C0:
        case 0x2C1:
        default:
            val = D_800C7684;
            break;
        }
        if (flag != 0) {
            func_0021E068(s, &p->v79C, id, p->f7BC, val, D_800C7688);
        }
    }
}
