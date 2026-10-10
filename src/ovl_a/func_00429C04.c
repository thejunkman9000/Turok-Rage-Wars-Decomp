#include "o04_types.h"
#include "o05_types.h"
#include "q03_types.h"
extern Q03F60 *D_800E4F60;
extern Q03Ent D_80146398[];
extern s32 D_80154024;
void *func_00252FFC(s32 a);
void *func_0041B690(s32 a, s32 b);
void func_0041B768(s32 a, s32 b, s32 c);
Q03WdU *func_0040ECB0(s32 a, s32 b);
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
    Q03WdU *t;
    Q03Ent *e;
    Q03WdU *h;
    s32 s0;
    u8 col;
    u8 col2;
    s32 s1;
    s32 s3;
    f32 fz;
    s32 *q;
    O05Vec3 va;
    O05Vec3 vb;
    O05Vec3 vc;
    O05Vec3 vd;
    D_800E4F60 = func_00252FFC(0x470);
    *(s32 *)D_800E4F60 = a;
    D_800E4F60->unk3C8 = func_0041B690(a, 4);
    func_0041B768(a, 0, 0x2FF);
    func_0041B768(a, 1, 0x2FF);
    func_0041B768(a, 2, 0x2FF);
    func_0041B768(a, 3, 0x2FF);
    D_800E4F60->state = 1;
    D_800E4F60->unk45C = 0;
    D_800E4F60->unk3E0 = 4;
    D_800E4F60->unk3CC = (Q03H14 *)func_0040ECB0(a, 0x306);
    ((Q03WdU *)D_800E4F60->unk3CC)->u14 = ((Q03WdU *)D_800E4F60->unk3CC)->u14 - ((Q03WdU *)D_800E4F60->unk3CC)->w18.u;
    D_800E4F60->u3D0.w = ((Q03WdU *)D_800E4F60->unk3CC)->w18.s / 4;
    s1 = ((Q03WdU *)D_800E4F60->unk3CC)->w18.s - D_800E4F60->u3D0.w * 4;
    { s32 r = s1; ((Q03WdU *)D_800E4F60->unk3CC)->u14 = ((Q03WdU *)D_800E4F60->unk3CC)->u14 + r; }
    D_800E4F60->unk3D4 = (Q03H14 *)func_0040ECB0(a, 0x30F);
    ((Q03WdU *)D_800E4F60->unk3D4)->u14 = ((Q03WdU *)D_800E4F60->unk3D4)->u14 + ((Q03WdU *)D_800E4F60->unk3D4)->w18.u;
    D_800E4F60->u3D8.w = ((Q03WdU *)D_800E4F60->unk3D4)->w18.s / 4;
    s1 = ((Q03WdU *)D_800E4F60->unk3D4)->w18.s - D_800E4F60->u3D8.w * 4;
    { s32 r = s1; ((Q03WdU *)D_800E4F60->unk3D4)->u14 = ((Q03WdU *)D_800E4F60->unk3D4)->u14 - r; }
    t = func_0040ECB0(a, 0x30A);
    col = 0x6E;
    t->b10 = col;
    D_800E4F60->unk448 = (Q03H14 *)func_0040ECB0(a, 0x35D);
    D_800E4F60->unk448->unk10 = 0x41;
    func_0040E958(D_800E4F60->unk448, 0);
    D_800E4F60->unk3E4 = func_00419ED4(0x303, 0x6E);
    t = func_0040ECB0(a, 0x301);
    D_800E4F60->unk3E8 = t;
    func_0040E958(t, 0);
    D_800E4F60->unk3EC = func_0040ECB0(a, 0x30E);
    D_800E4F60->unk3F0 = func_0040ECB0(a, 0x310);
    func_0042B260();
    D_800E4F60->unk438 = 0;
    D_800E4F60->unk434 = 0;
    func_0042AB70();
    do { s1 = -1; } while (0);
    func_0042B1C0();
    q = &D_80154024;
    q[0] = 0;
    q[-1] = s1;
    D_800E4F60->unk454 = (Q03H14 *)func_0040ECB0(a, 0x308);
    func_0040ECB0(a, 0x309)->b10 = col;
    D_800E4F60->unk46C = 0;
    D_800E4F60->unk440 = (Q03H14 *)func_0040ECB0(a, 0x30B);
    col2 = 0x8C;
    ((Q03H14 *)D_800E4F60->unk440)->unk10 = col2;
    func_0040E958(D_800E4F60->unk440, 1);
    D_800E4F60->unk444 = func_0040ECB0(a, 0x30D);
    ((Q03WdU *)D_800E4F60->unk444)->b10 = col2;
    s0 = 0;
    func_0040E958(D_800E4F60->unk444, s0);
    D_800E4F60->unk44C = (Q03H14 *)func_0040ECB0(a, 0x30C);
    D_800E4F60->unk44C->unk10 = 0xFF;
    D_800E4F60->unk450 = (Q03H14 *)func_0040ECB0(a, 0x2FE);
    t = func_0040ECB0(a, 0x300);
    D_800E4F60->unk458 = t;
    func_0040E958(t, 1);
    func_002A338C();
    D_800E4F60->unk460 = 0;
    D_800E4F60->unk464 = 0;
    D_800E4F60->unk468 = s1;
    for (; s0 < 8; s0++) {
        e = &D_80146398[s0];
        if (e->f91 == 1) {
            e->f78 = 0;
            e->f91 = 0;
        }
    }
    func_002A33BC(1);
    s1 = 0;
    s3 = 0;
    s0 = 0;
    va.z = va.y = va.x = 0.018f;
    vc.x = 0;
    vc.y = 0;
    vc.z = 0;
    vd.x = 0;
    vd.y = 5.0f;
    vd.z = 0;
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
        vb.x = (f32)s1;
        vb.y = 13.0f;
        fz = -50.0f;
        vb.z = fz;
        func_00439D3C((u8 *)D_800E4F60 + 8 + s0 * 0xC0, s3, va, vb);
        func_00439DC0((u8 *)D_800E4F60 + 8 + s0 * 0xC0, vc);
        func_00439E10((u8 *)D_800E4F60 + 8 + s0 * 0xC0, vd);
    }
    vb.z = fz;
    va.z = va.y = va.x = 0.04f;
    vb.x = 17.0f;
    vb.y = -10.0f;
    func_00439D3C(D_800E4F60->unk308, 0xEA6, va, vb);
    func_00439DC0(D_800E4F60->unk308, vc);
    func_00439E10(D_800E4F60->unk308, vd);
    func_0025DF54(0xE78);
    func_004221A0();
    return 0;
}
