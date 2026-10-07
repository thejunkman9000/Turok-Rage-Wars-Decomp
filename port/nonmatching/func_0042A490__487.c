#include "o04_types.h"
#include "q03_types.h"
extern Q03F60 *D_800E4F60;
extern s32 D_80154024;
extern s32 D_80154020[];
extern f32 D_800E1AF4;
extern f32 D_800E1AF8;
extern f32 D_800E1AFC;
extern f32 D_800E1B04;
extern f32 D_800E1B08;
extern f32 D_800E1B0C;
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0040E958(void *p, s32 a);
void func_0025DF54(s32 a);
void func_00419FD8(void *p, s32 a);
s32 func_00419FB8(void *p);
void func_00419FA4(void *p);
void func_002A3358(void);
void func_0042A994(s32 a);
void func_0042B4C4(void);
void *func_0040ECB0(s32 a, s32 b);
void func_0042EB68(s32 a);
f32 cosf(f32 x);
s32 func_0042A490(s32 a, s32 b, s32 c) {
    s32 *p = &D_80154024;
    s32 s0;
    s32 t;
    f32 f;
    if (p[0] == 1) {
        p[0] = 0;
        if (p[-1] != -1) {
            D_800E4F60->unk44C->unk10 = 0x5A;
            func_0029A73C();
            func_00299368(p[-1]);
            return 0;
        }
        D_800E4F60->unk44C->unk10 = 0xFF;
        D_800E4F60->state = 9;
        if (D_800E4F60->unk438 == 0) {
            func_0040E958(D_800E4F60->unk440, 1);
            func_0040E958(D_800E4F60->unk448, 1);
        } else {
            func_0040E958(D_800E4F60->unk444, 1);
        }
        func_0040E958(D_800E4F60->unk3EC, 1);
        func_0040E958(D_800E4F60->unk3F0, 1);
    }
    switch (D_800E4F60->state) {
    case 9:
    case 8:
        break;
    case 1:
        D_800E4F60->unk3CC->unk14 = D_800E4F60->unk3CC->unk14 + D_800E4F60->u3D0.h.h1;
        D_800E4F60->unk3D4->unk14 = D_800E4F60->unk3D4->unk14 - D_800E4F60->u3D8.h.h1;
        D_800E4F60->unk3E0 = D_800E4F60->unk3E0 - 1;
        if (D_800E4F60->unk3E0 <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E4F60->unk3E8, 1);
            func_00419FD8(D_800E4F60->unk3E4, 4);
            D_800E4F60->state = 4;
            D_800E4F60->unk3E0 = 4;
        }
        break;
    case 2:
        D_800E4F60->unk3CC->unk14 = D_800E4F60->unk3CC->unk14 - D_800E4F60->u3D0.h.h1;
        D_800E4F60->unk3D4->unk14 = D_800E4F60->unk3D4->unk14 + D_800E4F60->u3D8.h.h1;
        D_800E4F60->unk3E0 = D_800E4F60->unk3E0 - 1;
        if (D_800E4F60->unk3E0 <= 0) {
            D_800E4F60->state = 3;
            func_0029A73C();
            func_00299368(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk460 == 0) {
            func_002A3358();
            D_800E4F60->unk460 = 1;
            func_0040E958(D_800E4F60->unk458, 0);
        }
        break;
    case 4:
        {
            Q03F60 *q = D_800E4F60;
            s32 y = q->unk3E0;
            s32 x = y - 1;
            s32 z = x >= 0 ? y - (y >= x) : 0;
            q->unk3E0 = z;
        }
        if (D_800E4F60->unk3E0 <= 0) {
            if (func_00419FB8(D_800E4F60->unk3E4)) {
                func_00419FA4(D_800E4F60->unk3E4);
                func_0042A994(10);
                D_800E4F60->state = 9;
            }
        }
        break;
    case 5:
        func_0040E958(D_800E4F60->unk458, 1);
        func_0040E958(D_800E4F60->unk3E8, 0);
        func_0042B4C4();
        func_0042A994(0);
        D_800E4F60->state = 2;
        D_800E4F60->unk3E0 = 4;
        func_0040E958(D_800E4F60->unk448, 0);
        func_0025DF54(0xE78);
        break;
    case 6:
        {
            s32 u = ((Q03H14 *)func_0040ECB0(a, 0x316))->unk10;
            s0 = u >> 1;
        }
        func_0042A994(s0);
        if (s0 < 10) {
            D_800E4F60->state = 3;
            func_0042EB68(0xB);
            return 0;
        }
        break;
    case 7:
        s0 = ((Q03H14 *)func_0040ECB0(a, 0x316))->unk10;
        s0 = (s0 + 1) << 1;
        if (s0 >= 0x42) {
            s0 = 0x41;
            D_800E4F60->state = 3;
        }
        func_0042A994(s0);
        if (D_800E4F60->unk438 == 0) {
            func_0040E958(D_800E4F60->unk448, 1);
        }
        break;
    }
    if (D_800E4F60->state != 3) {
        return 0;
    }
    t = D_800E4F60->unk45C + c;
    D_800E4F60->unk45C = t;
    if (D_80154020[0] != -1) {
        return 0;
    }
    if (D_800E4F60->unk438 == 0) {
        f = cosf((f32)t * D_800E1AF4) * D_800E1AF8 + D_800E1AFC;
        D_800E4F60->unk448->unk10 = (u32)f;
    } else {
        f = cosf((f32)t * D_800E1B04) * D_800E1B08 + D_800E1B0C;
        D_800E4F60->unk43C->unk10 = (u32)f;
    }
    return 0;
}
