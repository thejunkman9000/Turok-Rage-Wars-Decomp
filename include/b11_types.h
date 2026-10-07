#ifndef B11_TYPES_H
#define B11_TYPES_H

#include "common.h"
#include "p1_types.h"

typedef struct ObjDef ObjDef;
typedef struct Mtx4f Mtx4f;
typedef struct Vec3b Vec3b;
typedef struct B11Pt B11Pt;
typedef struct B11Box B11Box;
typedef struct B11Node B11Node;
typedef struct B11Res B11Res;
typedef struct B11Own B11Own;
typedef struct B11Obj1A0 B11Obj1A0;
typedef struct B11Y B11Y;
typedef struct B11X B11X;
typedef struct B11Desc B11Desc;
typedef struct B11Seg B11Seg;
typedef struct Obj Obj;
typedef struct ObjM ObjM;
typedef struct ObjFx ObjFx;
typedef struct B11PlayerList B11PlayerList;
typedef struct B11Pair B11Pair;
typedef struct B11Rec B11Rec;
typedef struct B11Key B11Key;
typedef struct B11Val B11Val;
typedef struct B11Trk B11Trk;
typedef struct B11Spawn B11Spawn;
typedef struct ObjH ObjH;
typedef struct B11Q B11Q;
typedef struct B11Fx B11Fx;
typedef struct B11P B11P;
typedef struct B11R B11R;
typedef struct ObjE8 ObjE8;
typedef struct B11Sp2 B11Sp2;
typedef struct ObjI ObjI;
typedef struct ObjR ObjR;

typedef union { u16 h; f32 f; } B11U32;
typedef union { s32 i; f32 f; } B11UIF;
typedef struct { f32 x, y, z, w; } Quat4;
/* class constants block of Obj.def (ActorDef of p1_types.h) */
struct ObjDef {
    /* 0x000 */ s32 type;
    /* 0x004 */ u32 flags4;
    /* 0x008 */ u8 pad8[0x6];
    /* 0x00E */ s8 unkE;
    /* 0x00F */ u8 padF[0x5];
    /* 0x014 */ u32 flags14;
    /* 0x018 */ B11U32 u18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x4];
    /* 0x028 */ f32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ u8 pad38[0x4];
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ u8 pad40[0xC];
    /* 0x04C */ u32 flags4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ u8 pad54[0x98];
    /* 0x0EC */ f32 unkEC;
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ f32 unkF4;
    /* 0x0F8 */ f32 unkF8;
};

/* 4x4 f32 row-major */
struct Mtx4f {
    /* 0x000 */ f32 m[16];
};

/* 3 bytes + index */
struct Vec3b {
    /* 0x000 */ u8 b0;
    /* 0x001 */ u8 b1;
    /* 0x002 */ u8 b2;
    /* 0x003 */ s8 b3;
};

struct B11Pt {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
};

struct B11Box {
    /* 0x000 */ u16 unk0;
    /* 0x002 */ u16 flags2;
    /* 0x004 */ B11Pt * p4;
    /* 0x008 */ B11Pt * p8;
    /* 0x00C */ B11Pt * pC;
    /* 0x010 */ u8 pad10[0xC];
    /* 0x01C */ s32 unk1C;
};

/* property node returned by func_0028FD94 */
struct B11Node {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8[1];
    /* 0x00C */ u8 padC[0x12];
    /* 0x01E */ u16 unk1E;
    /* 0x020 */ u8 pad20[0x4E];
    /* 0x06E */ u8 unk6E;
};

/* result block of func_002165F8 (0x3C bytes) */
struct B11Res {
    /* 0x000 */ Vec3f v;
    /* 0x00C */ u8 padC[0x2C];
    /* 0x038 */ f32 f38;
    /* 0x03C */ u8 end[0];
};

struct B11Own {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 * unk5DC;
    /* 0x5E0 */ u8 pad5E0[0x114];
    /* 0x6F4 */ f32 unk6F4;
    /* 0x6F8 */ u8 pad6F8[0x114];
    /* 0x80C */ Obj * unk80C;
    /* 0x810 */ u8 pad810[0x4C];
    /* 0x85C */ s32 unk85C;
};

struct B11Obj1A0 {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ u32 flags1C;
};

struct B11Y {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ u16 unk14;
};

struct B11X {
    /* 0x000 */ u8 pad0[0x30];
    /* 0x030 */ B11Y * unk30;
};

/* descriptor (table entry D_800D0680[type]) */
struct B11Desc {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ void (*cb)();
};

/* 24-byte segment record (Obj.seg[side]) */
struct B11Seg {
    /* 0x000 */ s32 w0;
    /* 0x004 */ u8 pad4[0x14];
};

/* generic game object (Actor of p1_types.h seen through other fields) */
struct Obj {
    /* 0x000 */ u8 type;
    /* 0x001 */ s8 unk1;
    /* 0x002 */ u8 pad2[0x1];
    /* 0x003 */ s8 unk3;
    /* 0x004 */ u16 unk4;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ B11Box * unk14;
    /* 0x018 */ ObjDef * def;
    /* 0x01C */ Vec3f v1C;
    /* 0x028 */ u8 pad28[0xC];
    /* 0x034 */ s32 unk34;
    /* 0x038 */ u32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0xC];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ Quat4 q5C;
    /* 0x06C */ B11UIF unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 unk74[4];
    /* 0x078 */ u8 pad78[0x3C];
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ s32 unkB8;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ s32 unkC4;
    /* 0x0C8 */ u8 padC8[0x4];
    /* 0x0CC */ s32 unkCC;
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ s32 unkD4;
    /* 0x0D8 */ s32 unkD8;
    /* 0x0DC */ s32 unkDC;
    /* 0x0E0 */ s32 unkE0;
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x2];
    /* 0x0E8 */ u8 unkE8[4];
    /* 0x0EC */ u8 padEC[0x14];
    /* 0x100 */ u32 flags;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s16 unk108;
    /* 0x10A */ s16 unk10A;
    /* 0x10C */ u8 pad10C[0x2];
    /* 0x10E */ u8 unk10E;
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 pad110[0x8];
    /* 0x118 */ B11X * unk118;
    /* 0x11C */ u8 pad11C[0x24];
    /* 0x140 */ B11Seg seg[2];
    /* 0x170 */ u8 unk170[4];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ u8 pad178[0x4];
    /* 0x17C */ u32 unk17C;
    /* 0x180 */ u8 pad180[0x14];
    /* 0x194 */ f32 unk194;
    /* 0x198 */ u8 pad198[0x4];
    /* 0x19C */ u16 unk19C;
    /* 0x19E */ u8 pad19E[0x2];
    /* 0x1A0 */ B11Obj1A0 * unk1A0;
    /* 0x1A4 */ f32 unk1A4;
    /* 0x1A8 */ u8 pad1A8[0x1C];
    /* 0x1C4 */ s32 unk1C4;
    /* 0x1C8 */ u8 pad1C8[0x10];
    /* 0x1D8 */ B11Own * unk1D8;
    /* 0x1DC */ u8 pad1DC[0x5F];
    /* 0x23B */ u8 unk23B;
    /* 0x23C */ u8 pad23C[0x50];
    /* 0x28C */ void (*unk28C)();
    /* 0x290 */ u8 pad290[0x50];
    /* 0x2E0 */ u32 unk2E0;
};

/* view of an object with 64-byte matrices at +0x68 (indexed by the side index D_800D297C) */
struct ObjM {
    /* 0x000 */ u8 pad0[0x60];
    /* 0x060 */ void * unk60;
    /* 0x064 */ u8 pad64[0x4];
    /* 0x068 */ Mtx4f mtx[2];
    /* 0x0E8 */ u8 padE8[0x94];
    /* 0x17C */ u32 unk17C;
};

/* view of an object whose +0x194..0x1A4 are an f32 ramp (timer) block */
struct ObjFx {
    /* 0x000 */ u8 pad0[0x1];
    /* 0x001 */ s8 unk1;
    /* 0x002 */ u8 pad2[0x1];
    /* 0x003 */ u8 unk3;
    /* 0x004 */ u8 pad4[0x10];
    /* 0x014 */ B11Box * unk14;
    /* 0x018 */ ObjDef * def;
    /* 0x01C */ u8 pad1C[0x178];
    /* 0x194 */ f32 unk194;
    /* 0x198 */ u8 pad198[0x4];
    /* 0x19C */ u16 unk19C;
    /* 0x19E */ u8 pad19E[0x2];
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ f32 unk1A4;
    /* 0x1A8 */ u8 pad1A8[0x18];
    /* 0x1C0 */ s32 unk1C0;
};

/* global player list header at D_80145040 */
struct B11PlayerList {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ u8 * head;
    /* 0x008 */ s32 count;
};

struct B11Pair {
    /* 0x000 */ s32 a;
    /* 0x004 */ s32 b;
};

/* 0x1C-byte record (list element) */
struct B11Rec {
    /* 0x000 */ u8 pad0[0x2];
    /* 0x002 */ u16 type;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ B11Pair unk14;
};

/* 4-byte key entry */
struct B11Key {
    /* 0x000 */ s16 a;
    /* 0x002 */ s16 b;
};

/* 20-byte value record */
struct B11Val {
    /* 0x000 */ Vec3f v;
    /* 0x00C */ s16 q[4];
};

/* animation track header */
struct B11Trk {
    /* 0x000 */ B11Key * keys;
    /* 0x004 */ B11Val * vals;
    /* 0x008 */ s32 node8;
    /* 0x00C */ s32 nodeC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ f32 t;
};

/* spawn descriptor (arg1 of func_0024B398) */
struct B11Spawn {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ Vec3f v4;
    /* 0x010 */ Vec3f v10;
    /* 0x01C */ u16 u1C;
    /* 0x01E */ u16 u1E;
    /* 0x020 */ u16 u20;
    /* 0x022 */ u16 u22;
    /* 0x024 */ s16 s24;
    /* 0x026 */ u8 u26;
    /* 0x027 */ u8 u27;
};

/* view: handle cache fields at +0x50..0x5C */
struct ObjH {
    /* 0x000 */ u8 pad0[0x1];
    /* 0x001 */ s8 unk1;
    /* 0x002 */ u8 pad2[0x4E];
    /* 0x050 */ s32 h50;
    /* 0x054 */ s32 h54;
    /* 0x058 */ s32 h58;
    /* 0x05C */ s32 h5C;
    /* 0x060 */ s32 h60;
};

/* arg1 of func_0024C444 */
struct B11Q {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ s32 * unkC;
};

/* effect instance returned by func_0028308C */
struct B11Fx {
    /* 0x000 */ u8 pad0[0x150];
    /* 0x150 */ f32 f150;
    /* 0x154 */ f32 f154;
};

/* arg1 of func_0024C6D8 */
struct B11P {
    /* 0x000 */ u8 pad0[0x12];
    /* 0x012 */ u8 u12;
    /* 0x013 */ u8 pad13[0x1];
    /* 0x014 */ s8 s14;
    /* 0x015 */ u8 pad15[0x3];
    /* 0x018 */ Vec3f v18;
};

/* arg2 of func_0024A1C0 (weapon fx request) */
struct B11R {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00C */ s32 * unkC;
};

/* view: matrices at +0xE8 (stride 0x40) indexed by the side index */
struct ObjE8 {
    /* 0x000 */ u8 pad0[0xE8];
    /* 0x0E8 */ Mtx4f mtx[2];
};

/* spawn record (arg1 of func_0024E980 / func_0024EB80) */
struct B11Sp2 {
    /* 0x000 */ s32 w0;
    /* 0x004 */ Vec3f pos;
    /* 0x010 */ f32 r;
    /* 0x014 */ u16 u14;
    /* 0x016 */ u16 u16_;
    /* 0x018 */ u16 u18;
    /* 0x01A */ u16 u1A;
    /* 0x01C */ u16 u1C;
    /* 0x01E */ s8 s1E;
};

/* view: freshly spawned object (initializer targets) */
struct ObjI {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ u16 id;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 p14;
    /* 0x018 */ s32 p18;
    /* 0x01C */ u8 pad1C[0x34];
    /* 0x050 */ s32 h50;
    /* 0x054 */ s32 h54;
    /* 0x058 */ s32 h58;
    /* 0x05C */ s32 h5C;
    /* 0x060 */ u8 pad60[0x114];
    /* 0x174 */ f32 f174;
    /* 0x178 */ u8 pad178[0x4];
    /* 0x17C */ Vec3f bmin;
    /* 0x188 */ Vec3f bmax;
    /* 0x194 */ f32 f194;
    /* 0x198 */ s32 w198;
    /* 0x19C */ u16 flags;
    /* 0x19E */ u16 u19E;
    /* 0x1A0 */ s32 w1A0;
    /* 0x1A4 */ s32 w1A4;
    /* 0x1A8 */ Vec3f v1A8;
    /* 0x1B4 */ Vec3f v1B4;
    /* 0x1C0 */ s32 w1C0;
    /* 0x1C4 */ s32 w1C4;
};

/* view: renderable fx object (display list builder func_0024EB80) */
struct ObjR {
    /* 0x000 */ u8 pad0[0x1];
    /* 0x001 */ s8 unk1;
    /* 0x002 */ u8 pad2[0x1];
    /* 0x003 */ s8 unk3;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ ObjDef * def;
    /* 0x01C */ u8 pad1C[0x4C];
    /* 0x068 */ Mtx4f mtx[2];
    /* 0x0E8 */ u8 padE8[0x8C];
    /* 0x174 */ s32 w174;
    /* 0x178 */ u8 pad178[0x1C];
    /* 0x194 */ f32 f194;
    /* 0x198 */ f32 f198;
    /* 0x19C */ u8 pad19C[0xC];
    /* 0x1A8 */ Vec3f v1A8;
    /* 0x1B4 */ u8 pad1B4[0x10];
    /* 0x1C4 */ DlCmd * dl;
};

#endif
