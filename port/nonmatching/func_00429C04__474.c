#include "o04_types.h"
#include "o05_types.h"
#include "q03_types.h"
typedef struct { u8 pad0[0x14]; u16 w14; u16 w16; u16 w18; } Q03U;
extern Q03F60 *D_800E4F60;
extern Q03Ent D_80146398[];
extern s32 D_80154024;
extern f32 D_800E1AA0;
extern f32 D_800E1AA4;
extern f32 D_800E1AA8;
extern f32 D_800E1AAC;
extern f32 D_800E1AB0;
extern f32 D_800E1AB4;
extern f32 D_800E1AB8;
void *func_00252FFC(s32 a);
s32 func_0041B690(s32 a, s32 b);
void func_0041B768(s32 a, s32 b, s32 c);
void *func_0040ECB0(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void *func_00419ED4(s32 a, s32 b);
void func_0042B260(void);
void func_0042AB70(void);
void func_0042B1C0(void);
void func_002A338C(void);
void func_002A33BC(s32 a);
void func_00439D3C(void *o, s32 n, O05Vec3 a, O05Vec3 b);
void func_00439DC0(void *o, O05Vec3 v);
void func_00439E10(void *o, O05Vec3 v);
void func_0025DF54(s32 a);
void func_004221A0(void);
s32 func_00429C04(s32 a) {
    Q03U *w1;
    Q03U *w2;
    Q03H14 *h;
    void *p;
    s32 t;
    s32 s0;
    s32 s1;
    s32 s3;
    s32 off;
    f32 fz;
    s32 *q;
    O05Vec3 va;
    O05Vec3 vb;
    O05Vec3 vc;
    O05Vec3 vd;
    D_800E4F60 = func_00252FFC(0x470);
    *(s32 *)D_800E4F60 = a;
    *(s32 *)((u8 *)D_800E4F60 + 0x3C8) = func_0041B690(a, 4);
    func_0041B768(a, 0, 0x2FF);
    func_0041B768(a, 1, 0x2FF);
    func_0041B768(a, 2, 0x2FF);
    func_0041B768(a, 3, 0x2FF);
    D_800E4F60->state = 1;
    D_800E4F60->unk45C = 0;
    D_800E4F60->unk3E0 = 4;
    w1 = func_0040ECB0(a, 0x306);
    D_800E4F60->unk3CC = (Q03H14 *)w1;
    w1->w14 = w1->w14 - w1->w18;
    t = D_800E4F60->unk3CC->unk18 / 4;
    D_800E4F60->u3D0.w = t;
    s1 = D_800E4F60->unk3CC->unk18 - (t << 2);
    D_800E4F60->unk3CC->unk14 = D_800E4F60->unk3CC->unk14 + s1;
    w2 = func_0040ECB0(a, 0x30F);
    D_800E4F60->unk3D4 = (Q03H14 *)w2;
    w2->w14 = w2->w14 + w2->w18;
    t = D_800E4F60->unk3D4->unk18 / 4;
    D_800E4F60->u3D8.w = t;
    s1 = D_800E4F60->unk3D4->unk18 - (t << 2);
    D_800E4F60->unk3D4->unk14 = D_800E4F60->unk3D4->unk14 - s1;
    s0 = 0x6E;
    ((Q03H14 *)func_0040ECB0(a, 0x30A))->unk10 = s0;
    h = func_0040ECB0(a, 0x35D);
    D_800E4F60->unk448 = h;
    h->unk10 = 0x41;
    func_0040E958(D_800E4F60->unk448, 0);
    D_800E4F60->unk3E4 = func_00419ED4(0x303, 0x6E);
    p = func_0040ECB0(a, 0x301);
    D_800E4F60->unk3E8 = p;
    func_0040E958(p, 0);
    D_800E4F60->unk3EC = func_0040ECB0(a, 0x30E);
    D_800E4F60->unk3F0 = func_0040ECB0(a, 0x310);
    func_0042B260();
    D_800E4F60->unk438 = 0;
    D_800E4F60->unk434 = 0;
    func_0042AB70();
    s1 = -1;
    func_0042B1C0();
    q = &D_80154024;
    q[0] = 0;
    q[-1] = s1;
    D_800E4F60->unk454 = func_0040ECB0(a, 0x308);
    ((Q03H14 *)func_0040ECB0(a, 0x309))->unk10 = s0;
    D_800E4F60->unk46C = 0;
    h = func_0040ECB0(a, 0x30B);
    D_800E4F60->unk440 = h;
    s0 = 0x8C;
    h->unk10 = s0;
    func_0040E958(D_800E4F60->unk440, 1);
    h = func_0040ECB0(a, 0x30D);
    D_800E4F60->unk444 = h;
    h->unk10 = s0;
    s0 = 0;
    func_0040E958(D_800E4F60->unk444, s0);
    h = func_0040ECB0(a, 0x30C);
    D_800E4F60->unk44C = h;
    h->unk10 = 0xFF;
    D_800E4F60->unk450 = func_0040ECB0(a, 0x2FE);
    p = func_0040ECB0(a, 0x300);
    D_800E4F60->unk458 = p;
    func_0040E958(p, 1);
    func_002A338C();
    D_800E4F60->unk460 = 0;
    D_800E4F60->unk464 = 0;
    D_800E4F60->unk468 = s1;
    for (; s0 < 8; s0++) {
        if (D_80146398[s0].f91 == 1) {
            D_80146398[s0].f78 = 0;
            D_80146398[s0].f91 = 0;
        }
    }
    func_002A33BC(1);
    s1 = 0;
    s3 = 0;
    s0 = 0;
    va.x = D_800E1AA0;
    va.y = D_800E1AA0;
    va.z = D_800E1AA0;
    vc.x = 0;
    vc.y = 0;
    vc.z = 0;
    vd.x = 0;
    vd.y = D_800E1AA4;
    vd.z = 0;
    off = 8;
    for (; s0 < 4; s0++) {
        switch (s0) {
        case 0:
            s1 = 0;
            s3 = 0xEA6;
            break;
        case 1:
            s1 = -6;
            s3 = 0xEA7;
            break;
        case 2:
            s1 = -0xD;
            s3 = 0xEA8;
            break;
        case 3:
            s1 = -0x13;
            s3 = 0xEA9;
            break;
        }
        fz = D_800E1AAC;
        vb.x = (f32)s1;
        vb.y = D_800E1AA8;
        vb.z = fz;
        func_00439D3C((u8 *)D_800E4F60 + off, s3, va, vb);
        func_00439DC0((u8 *)D_800E4F60 + off, vc);
        func_00439E10((u8 *)D_800E4F60 + off, vd);
        off += 0xC0;
    }
    vb.z = fz;
    va.x = D_800E1AB0;
    va.y = D_800E1AB0;
    va.z = D_800E1AB0;
    vb.x = D_800E1AB4;
    vb.y = D_800E1AB8;
    func_00439D3C(D_800E4F60->unk308, 0xEA6, va, vb);
    func_00439DC0(D_800E4F60->unk308, vc);
    func_00439E10(D_800E4F60->unk308, vd);
    func_0025DF54(0xE78);
    func_004221A0();
    return 0;
}
