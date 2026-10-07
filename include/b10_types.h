#ifndef B10_TYPES_H
#define B10_TYPES_H

#include "p1_types.h"

typedef struct B10Dc B10Dc;
typedef struct B10Ent B10Ent;
typedef struct B10Ctl B10Ctl;
typedef struct B10A B10A;
typedef struct B10Sc B10Sc;
typedef struct B10Vec B10Vec;
typedef struct B10Pair B10Pair;
typedef struct B10X B10X;
typedef struct B10Q4 B10Q4;
typedef struct B10Pq B10Pq;
typedef struct B10Ow B10Ow;
typedef struct B10Le B10Le;
typedef struct B10Mt B10Mt;
typedef struct B10B24 B10B24;
typedef struct B10Cv B10Cv;
typedef struct B10An B10An;
typedef struct B10Fx B10Fx;
typedef struct B10Obj B10Obj;
typedef struct B10Blk B10Blk;
typedef struct B10Q B10Q;
typedef struct B10G B10G;
typedef struct B10Pl B10Pl;
typedef struct B10Tgt B10Tgt;
typedef struct B10U B10U;
typedef struct B10T B10T;
typedef struct B10S B10S;
typedef struct B10H B10H;
typedef struct B10Pt B10Pt;
typedef struct B10Tri B10Tri;
typedef struct B10Fl B10Fl;
typedef struct B10Nd B10Nd;
typedef struct B10Ev B10Ev;
typedef struct B10Z B10Z;
typedef struct B10C B10C;
typedef struct B10Pu B10Pu;
typedef struct B10Hh B10Hh;
typedef struct B10Mkk B10Mkk;
typedef struct B10Mk B10Mk;
typedef struct B10Mo B10Mo;
typedef struct B10Mv B10Mv;
typedef struct B10Buf B10Buf;
typedef struct B10T2 B10T2;
typedef struct B10Pa B10Pa;
typedef struct B10Pb B10Pb;
typedef struct B10Pc B10Pc;
typedef struct B10Ent2 B10Ent2;
typedef struct B10Lst B10Lst;
typedef struct B10Nd2 B10Nd2;
typedef struct B10Cx B10Cx;
typedef struct B10R B10R;
typedef struct B10Bx B10Bx;
typedef struct B10Ie B10Ie;
typedef struct B10Te B10Te;
typedef struct B10Sq B10Sq;
typedef struct B10Qc B10Qc;
typedef struct B10Hit B10Hit;
typedef struct B10Sn B10Sn;
typedef struct B10Bn B10Bn;

struct B10Dc {
    /* 0x000 */ s32 w[55];
};

struct B10Ent {
    /* 0x000 */ u8 c0;
    u8 pad1[0x27];
};

struct B10Ctl {
    /* 0x000 */ void* p0;
    /* 0x004 */ s32 f4;
    s32 unk8;
    /* 0x00C */ void* fn0C;
    /* 0x010 */ void* fn10;
    s32 unk14;
    s32 unk18;
    /* 0x01C */ f32 f1C;
    /* 0x020 */ f32 f20;
    s32 unk24;
    s32 unk28;
    /* 0x02C */ f32 f2C;
    /* 0x030 */ f32 f30;
    /* 0x034 */ f32 f34;
    /* 0x038 */ s32 f38;
    /* 0x03C */ s32 f3C;
    /* 0x040 */ s32 f40;
    /* 0x044 */ s32 f44;
    /* 0x048 */ s32 f48;
    s32 unk4C;
    /* 0x050 */ s32 f50;
    /* 0x054 */ s32 f54;
    s32 unk58;
    /* 0x05C */ s32 f5C;
    /* 0x060 */ s32 f60;
    /* 0x064 */ f32 f64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    /* 0x0A0 */ f32 fA0;
    s32 unkA4;
    /* 0x0A8 */ s32 fA8;
    /* 0x0AC */ s32 fAC;
    /* 0x0B0 */ s32 fB0;
    /* 0x0B4 */ s32 fB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    /* 0x0D8 */ s32 fD8;
    /* 0x0DC */ s32 fDC;
    /* 0x0E0 */ s32 fE0;
    /* 0x0E4 */ void* fE4;
    /* 0x0E8 */ void* fE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    /* 0x100 */ f32 f100;
    /* 0x104 */ s32 f104;
    /* 0x108 */ s32 f108;
    /* 0x10C */ s32 f10C;
    /* 0x110 */ s32 f110;
    /* 0x114 */ s32 f114;
    /* 0x118 */ B10Ent ent[5];
    /* 0x1E0 */ s32 f1E0;
};

struct B10A {
    u8 pad0[0x1C];
    /* 0x01C */ f32 v1C[3];
    u8 pad28[0x10];
    /* 0x038 */ u32 f38;
    /* 0x03C */ u32 f3C;
    u8 pad40[0x1C];
    /* 0x05C */ f32 f5C;
    /* 0x060 */ f32 f60;
    /* 0x064 */ f32 f64;
    u8 pad68[0x48];
    /* 0x0B0 */ B10Dc dc;
};

struct B10Sc {
    /* 0x000 */ s32 w0;
    u8 pad4[0x104];
};

struct B10Vec {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
};

struct B10Pair {
    /* 0x000 */ s32 a;
    /* 0x004 */ s32 b;
};

struct B10X {
    u8 pad0[0x68];
    /* 0x068 */ f32 m68[16];
    u8 padA8[0xC];
    /* 0x0B4 */ s32** pB4;
};

struct B10Q4 {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 w;
};

struct B10Pq {
    u8 pad0[0x140];
    /* 0x140 */ B10Q4 q140;
};

struct B10Ow {
    u8 pad0[0x5DC];
    /* 0x5DC */ B10Pq* p5DC;
};

struct B10Le {
    /* 0x000 */ u16 hu0;
    /* 0x002 */ u16 h2;
    /* 0x004 */ s16 h4;
    u8 pad6[0x2];
    /* 0x008 */ f32 f8;
    /* 0x00C */ f32 fC;
    /* 0x010 */ f32 f10;
    /* 0x014 */ B10Pair pr;
};

struct B10Mt {
    /* 0x000 */ f32 m[16];
};

struct B10B24 {
    /* 0x000 */ s32 w[6];
};

struct B10Cv {
    /* 0x000 */ u16 h0;
    u8 pad2[0x3];
    /* 0x005 */ u8 b5;
    u8 pad6[0x1];
    /* 0x007 */ u8 b7;
};

struct B10An {
    u8 pad0[0x4];
    /* 0x004 */ s16 h4;
    u8 pad6[0x4];
    /* 0x00A */ s8 b122;
    /* 0x00B */ s8 b123;
    u8 padC[0x8];
};

struct B10Fx {
    u8 pad0[0x52];
    /* 0x052 */ u16 h52;
    u8 pad54[0x9];
    /* 0x05D */ u8 u5D;
    u8 pad5E[0x1];
    /* 0x05F */ s8 s5F;
    /* 0x060 */ s8 s60;
    /* 0x061 */ s8 s61;
};

struct B10Obj {
    /* 0x000 */ u8 type;
    /* 0x001 */ s8 b1;
    u8 pad2[0x2];
    /* 0x004 */ u16 h4;
    u8 pad6[0x2];
    /* 0x008 */ s32 u8;
    /* 0x00C */ f32 fC;
    /* 0x010 */ s32 u10;
    /* 0x014 */ B10H* p14;
    /* 0x018 */ s32* p18;
    /* 0x01C */ Vec3f v1C;
    /* 0x028 */ f32 f28;
    /* 0x02C */ f32 f2C;
    /* 0x030 */ f32 f30;
    /* 0x034 */ s32 u34;
    /* 0x038 */ u32 f38;
    u8 pad3C[0x4];
    /* 0x040 */ B10Fl* p40;
    u8 pad44[0x14];
    /* 0x058 */ B10X* p58;
    /* 0x05C */ f32 f5C;
    /* 0x060 */ f32 f60;
    /* 0x064 */ f32 f64;
    u8 pad68[0x4];
    /* 0x06C */ f32 f6C;
    /* 0x070 */ f32 f70;
    /* 0x074 */ u8 b74;
    u8 pad75[0x2F];
    /* 0x0A4 */ s32* pA4;
    u8 padA8[0x4];
    /* 0x0AC */ B10Tri* pAC;
    u8 padB0[0x4];
    /* 0x0B4 */ s32 fB4;
    /* 0x0B8 */ B10Mt* pB8;
    /* 0x0BC */ s32 fBC;
    u8 padC0[0x4];
    /* 0x0C4 */ s32 fC4;
    /* 0x0C8 */ s32 fC8;
    /* 0x0CC */ s32 fCC;
    /* 0x0D0 */ s32 fD0;
    /* 0x0D4 */ s32 fD4;
    /* 0x0D8 */ s32 fD8;
    /* 0x0DC */ s32 fDC;
    /* 0x0E0 */ s32 fE0;
    /* 0x0E4 */ u16 hE4;
    /* 0x0E6 */ s8 bE6;
    /* 0x0E7 */ u8 bE7;
    /* 0x0E8 */ u8 bE8;
    u8 padE9[0x17];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ f32 f104;
    /* 0x108 */ s16 h108;
    /* 0x10A */ s16 h10A;
    u8 pad10C[0x2];
    /* 0x10E */ s8 b10E;
    /* 0x10F */ s8 b10F;
    u8 pad110[0x8];
    /* 0x118 */ B10An an118;
    /* 0x12C */ s16 h12C;
    u8 pad12E[0x2];
    /* 0x130 */ f32 f130;
    /* 0x134 */ f32 f134;
    /* 0x138 */ u8 b138;
    /* 0x139 */ u8 b139;
    u8 pad13A[0x1];
    /* 0x13B */ u8 b13B;
    u8 pad13C[0x4];
    /* 0x140 */ B10B24 s140;
    /* 0x158 */ B10B24 s158;
    /* 0x170 */ u8 b170;
    u8 pad171[0x3];
    /* 0x174 */ s32 f174;
    u8 pad178[0x4];
    /* 0x17C */ s32 f17C;
    u8 pad180[0x20];
    /* 0x1A0 */ B10Z* p1A0;
    u8 pad1A4[0x1];
    /* 0x1A5 */ s8 b1A5;
    u8 pad1A6[0x1E];
    /* 0x1C4 */ f32 f1C4;
    u8 pad1C8[0x10];
    /* 0x1D8 */ B10Ow* p1D8;
    u8 pad1DC[0x18];
    /* 0x1F4 */ void* p1F4;
    u8 pad1F8[0xC];
    /* 0x204 */ u8 b204;
    u8 pad205[0x33];
    /* 0x238 */ u16 h238;
    /* 0x23A */ s8 b23A;
    u8 pad23B[0x41];
    /* 0x27C */ void* fn27C;
    u8 pad280[0x4];
    /* 0x284 */ void* fn284;
    u8 pad288[0x4];
    /* 0x28C */ void* fn28C;
    u8 pad290[0x4];
    /* 0x294 */ f32 f294;
    u8 pad298[0x48];
    /* 0x2E0 */ s32 w2E0;
    /* 0x2E4 */ s32 w2E4;
};

struct B10Blk {
    /* 0x000 */ s32 w[20];
};

struct B10Q {
    /* 0x000 */ s32 w0;
    /* 0x004 */ u8 b4;
    /* 0x005 */ u8 b5;
    u8 pad6[0x16];
};

struct B10G {
    /* 0x000 */ s32 f0;
    u8 pad4[0x98];
    /* 0x09C */ s32 f9C;
};

struct B10Pl {
    u8 pad0[0x57C];
    /* 0x57C */ s32 f57C;
    /* 0x580 */ s32 f580;
    u8 pad584[0xC];
    /* 0x590 */ s32 f590;
};

struct B10Tgt {
    u8 pad0[0x29C];
    /* 0x29C */ f32 f29C;
    /* 0x2A0 */ f32 f2A0;
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
};

struct B10U {
    u8 pad0[0x1C];
    /* 0x01C */ f32 f1C;
};

struct B10T {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x4];
    /* 0x018 */ B10U* p18;
};

struct B10S {
    u8 pad0[0x4];
    /* 0x004 */ f32 f4;
    u8 pad8[0x2C];
    /* 0x034 */ f32 f34;
};

struct B10H {
    u8 pad0[0x2];
    /* 0x002 */ u16 h2;
};

struct B10Pt {
    /* 0x000 */ f32 x;
    u8 pad4[0x4];
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 y;
};

struct B10Tri {
    u8 pad0[0x4];
    /* 0x004 */ B10Pt* pt[3];
};

struct B10Fl {
    /* 0x000 */ u32 flags;
    /* 0x004 */ s8 b4;
    u8 pad5[0x1];
    /* 0x006 */ s8 b6;
    u8 pad7[0x11];
    /* 0x018 */ f32 f18;
};

struct B10Nd {
    u8 pad0[0x44];
    /* 0x044 */ u32 f44;
    u8 pad48[0xA];
    /* 0x052 */ u16 h52;
};

struct B10Ev {
    /* 0x000 */ s32 type;
    /* 0x004 */ f32 f4;
    /* 0x008 */ s32 f8;
    /* 0x00C */ s32 fC;
    /* 0x010 */ s32 f10;
    /* 0x014 */ s32 nv;
    /* 0x018 */ Vec3f v[3];
    u8 pad3C[0x10];
    /* 0x04C */ f32 f4C;
    u8 pad50[0x4];
    /* 0x054 */ s32 f54;
    /* 0x058 */ s32 f58;
    u8 pad5C[0x84];
};

struct B10Z {
    u8 pad0[0xC];
    /* 0x00C */ B10C* pC;
};

struct B10C {
    u8 pad0[0x8];
    /* 0x008 */ f32 f8;
};

struct B10Pu {
    /* 0x000 */ u8 b0;
};

struct B10Hh {
    /* 0x000 */ u16 h0;
};

struct B10Mkk {
    u8 pad0[0x4];
    /* 0x004 */ u16 kind;
    u8 pad6[0x2];
    /* 0x008 */ f32 f8;
};

struct B10Mk {
    u8 pad0[0x14];
    /* 0x014 */ B10Mkk k;
};

struct B10Mo {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x4];
    /* 0x018 */ B10Mk* p18;
};

struct B10Mv {
    /* 0x000 */ B10Mo* p0;
    u8 pad4[0x3C];
    /* 0x040 */ B10Fl* p40;
    /* 0x044 */ Vec3f a;
    /* 0x050 */ Vec3f b;
    /* 0x05C */ f32 f5C;
};

struct B10Buf {
    /* 0x000 */ s32 w0;
    /* 0x004 */ f32 f4;
    u8 pad8[0x2C];
    /* 0x034 */ f32 f34;
    u8 pad38[0x28];
};

struct B10T2 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
};

struct B10Pa {
    u8 pad0[0x1];
    /* 0x001 */ s8 b1;
};

struct B10Pb {
    u8 pad0[0x12];
    /* 0x012 */ s8 b12;
    u8 pad13[0x1];
    /* 0x014 */ s8 b14[4];
    /* 0x018 */ Vec3f v18;
    u8 pad24[0x10];
    /* 0x034 */ s8 b34;
};

struct B10Pc {
    u8 pad0[0x30];
    /* 0x030 */ f32 f30;
    /* 0x034 */ f32 f34;
    /* 0x038 */ f32 f38;
};

struct B10Ent2 {
    u8 pad0[0x64];
    /* 0x064 */ s8 b64;
    /* 0x065 */ u8 b65;
};

struct B10Lst {
    /* 0x000 */ s16 h0;
    u8 pad2[0x66];
};

struct B10Nd2 {
    u8 pad0[0x4];
    /* 0x004 */ s32 cnt;
};

struct B10Cx {
    /* 0x000 */ B10Obj* o;
    /* 0x004 */ s32 f4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    /* 0x01C */ s32 f1C;
    /* 0x020 */ s32 f20;
    /* 0x024 */ s32 f24;
    /* 0x028 */ s32 f28;
    /* 0x02C */ s32 f2C;
    /* 0x030 */ s32 f30;
    /* 0x034 */ s32 f34;
    s32 unk38;
    s32 unk3C;
    /* 0x040 */ s32 f40;
    /* 0x044 */ Vec3f p44;
    /* 0x050 */ Vec3f p50;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    /* 0x074 */ Vec3f p74;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    /* 0x0AC */ s32 fAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    s32 unk110;
    s32 unk114;
    s32 unk118;
    s32 unk11C;
    s32 unk120;
    s32 unk124;
    s32 unk128;
    s32 unk12C;
    s32 unk130;
    s32 unk134;
    s32 unk138;
    s32 unk13C;
    s32 unk140;
    s32 unk144;
    s32 unk148;
    s32 unk14C;
    s32 unk150;
    s32 unk154;
    s32 unk158;
    s32 unk15C;
    s32 unk160;
    s32 unk164;
    s32 unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    /* 0x180 */ Vec3f p180;
    s32 unk18C;
    s32 unk190;
    s32 unk194;
    /* 0x198 */ Vec3f p198;
    /* 0x1A4 */ Vec3f p1A4;
};

struct B10R {
    u8 pad0[0x30];
    /* 0x030 */ Vec3f v30;
};

struct B10Bx {
    /* 0x000 */ f32 f0;
    /* 0x004 */ f32 f4;
    /* 0x008 */ f32 f8;
    /* 0x00C */ f32 fC;
};

struct B10Ie {
    u8 pad0[0xB8];
    /* 0x0B8 */ f32 b0;
    /* 0x0BC */ f32 b1;
    /* 0x0C0 */ f32 b2;
    /* 0x0C4 */ f32 b3;
    /* 0x0C8 */ f32 b4;
    /* 0x0CC */ f32 b5;
    u8 padD0[0x8];
    /* 0x0D8 */ u16 flg;
    u8 padDA[0xE];
};

struct B10Te {
    /* 0x000 */ s32** p0;
    /* 0x004 */ B10Bx* p4;
    u8 pad8[0x4];
};

struct B10Sq {
    u8 pad0[0x8];
    /* 0x008 */ f32 f8;
    u8 padC[0x4];
    /* 0x010 */ f32 f10;
    u8 pad14[0x4];
    /* 0x018 */ f32 f18;
    u8 pad1C[0x28];
    /* 0x044 */ Vec3f v44;
    /* 0x050 */ Vec3f v50;
    u8 pad5C[0x24];
    /* 0x080 */ f32 f80;
    /* 0x084 */ f32 f84;
    /* 0x088 */ f32 f88;
    /* 0x08C */ f32 f8C;
    /* 0x090 */ f32 f90;
    /* 0x094 */ f32 f94;
    /* 0x098 */ f32 f98;
    /* 0x09C */ f32 f9C;
    /* 0x0A0 */ f32 fA0;
    /* 0x0A4 */ f32 fA4;
    /* 0x0A8 */ f32 fA8;
    u8 padAC[0xD0];
    /* 0x17C */ f32 f17C;
};

struct B10Qc {
    /* 0x000 */ B10Sq* self;
    /* 0x004 */ Vec3f* p44;
    /* 0x008 */ Vec3f* p50;
    /* 0x00C */ B10Mt m;
    /* 0x04C */ f32 f4C;
    /* 0x050 */ s32 i50;
    /* 0x054 */ f32 f54;
    /* 0x058 */ void* p58;
    /* 0x05C */ s32 k;
    u8 pad60[0x48];
    /* 0x0A8 */ s32 flag;
    u8 padAC[0x4];
};

struct B10Hit {
    /* 0x000 */ void* ptr;
    /* 0x004 */ f32 t;
};

struct B10Sn {
    u8 pad0[0x4];
    /* 0x004 */ s32 cnt;
    /* 0x008 */ B10Ie ie;
};

struct B10Bn {
    u8 pad0[0xC];
    /* 0x00C */ u16 flg;
};

#endif
