#ifndef B17_TYPES_H
#define B17_TYPES_H

#include "p1_types.h"

/* Types recovered in batch 17 (main image 0x7518C-0x7C390: rng/float helpers, vector/matrix code, actor handlers).
   GENERATED from wip/types_spec.py: padding arrays keep the offsets seen in the asm; names are provisional. */

typedef struct VelObj {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ Vec3f vel;
    /* 0x024 */ Vec3f dir;
} VelObj;

typedef struct RayObj {
    /* 0x000 */ Vec3f pos;
    /* 0x00C */ u8 padC[0x24];
    /* 0x030 */ Vec3f dir;
} RayObj;

typedef struct PlaneObj {
    /* 0x000 */ Vec3f pos;
    /* 0x00C */ u8 padC[0xC];
    /* 0x018 */ Vec3f nrm;
} PlaneObj;

typedef struct DefC {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ u16 w10;
    /* 0x012 */ u16 w12;
} DefC;

typedef struct DefB {
    /* 0x000 */ u8 pad0[0xBE];
    /* 0x0BE */ u16 wBE;
    /* 0x0C0 */ u8 padC0[0x2];
    /* 0x0C2 */ u16 wC2;
} DefB;

typedef struct Def2C {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s8 b18;
} Def2C;

typedef struct ChildB {
    /* 0x000 */ u32 w0;
    /* 0x004 */ u8 pad4[0x10];
    /* 0x014 */ s32 w14;
    /* 0x018 */ DefB *def;
    /* 0x01C */ u8 pad1C[0x10];
    /* 0x02C */ Def2C *p2C;
    /* 0x030 */ DefC *p30;
} ChildB;

typedef struct ActorX {
    /* 0x000 */ u8 kind;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ ActorDef *def;
    /* 0x01C */ Vec3f vel;
    /* 0x028 */ u8 pad28[0x10];
    /* 0x038 */ u32 flags38;
    /* 0x03C */ u8 pad3C[0x20];
    /* 0x05C */ u32 u5C;
    /* 0x060 */ u8 pad60[0xC];
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x74];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x1A];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x14];
    /* 0x118 */ ChildB *ch118;
    /* 0x11C */ u8 pad11C[0x10];
    /* 0x12C */ struct ActorX *tgt;
    /* 0x130 */ s32 u130;
    /* 0x134 */ u8 *p134;
    /* 0x138 */ u8 pad138[0x8];
    /* 0x140 */ f32 f140;
    /* 0x144 */ u8 pad144[0x30];
    /* 0x174 */ Vec3f v174;
    /* 0x180 */ f32 f180;
    /* 0x184 */ f32 f184;
    /* 0x188 */ f32 f188;
    /* 0x18C */ u8 pad18C[0x10];
    /* 0x19C */ f32 f19C;
    /* 0x1A0 */ f32 f1A0;
    /* 0x1A4 */ f32 f1A4;
    /* 0x1A8 */ f32 f1A8;
    /* 0x1AC */ f32 f1AC;
    /* 0x1B0 */ f32 f1B0;
    /* 0x1B4 */ u8 pad1B4[0x4];
    /* 0x1B8 */ s8 s1B8;
    /* 0x1B9 */ s8 s1B9;
    /* 0x1BA */ s8 s1BA;
    /* 0x1BB */ u8 pad1BB[0x1D];
    /* 0x1D8 */ Actor *owner;
    /* 0x1DC */ u8 pad1DC[0x110];
    /* 0x2EC */ Actor *next2EC;
    /* 0x2F0 */ u8 pad2F0[0x2AC];
    /* 0x59C */ s32 u59C;
    /* 0x5A0 */ u8 pad5A0[0x4];
    /* 0x5A4 */ s32 u5A4;
    /* 0x5A8 */ s32 u5A8;
    /* 0x5AC */ u8 pad5AC[0x28];
    /* 0x5D4 */ s32 unk5D4;
    /* 0x5D8 */ ActorStats *stats;
    /* 0x5DC */ u8 pad5DC[0x8];
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ u8 pad5E8[0x88];
    /* 0x670 */ f32 unk670;
    /* 0x674 */ u8 pad674[0x1CC];
    /* 0x840 */ f32 unk840;
    /* 0x844 */ u8 pad844[0x4];
    /* 0x848 */ s32 unk848;
    /* 0x84C */ u8 pad84C[0x974];
    /* 0x11C0 */ s32 unk11C0;
    /* 0x11C4 */ u8 pad11C4[0x28C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ Brain *brain;
    /* 0x1458 */ u8 pad1458[0x280];
    /* 0x16D8 */ u16 unk16D8;
    /* 0x16DA */ u8 pad16DA[0x6];
    /* 0x16E0 */ Actor *next;
} ActorX;

typedef struct SessEnt {
    /* 0x000 */ s32 *p;
    /* 0x004 */ u8 pad4[0x8];
} SessEnt;

typedef struct SessMgr {
    /* 0x000 */ s32 mode;
    /* 0x004 */ u8 pad4[0x14FC];
    /* 0x1500 */ s32 count;
    /* 0x1504 */ u8 pad1504[0x4];
    /* 0x1508 */ SessEnt ent[1];
} SessMgr;

typedef struct Rec14 {
    /* 0x000 */ s32 w0;
    /* 0x004 */ u16 w4;
    /* 0x006 */ u8 pad6[0x2];
    /* 0x008 */ u16 w8;
    /* 0x00A */ u16 wA;
    /* 0x00C */ u16 wC;
    /* 0x00E */ u8 flagsE;
    /* 0x00F */ u8 b0F;
    /* 0x010 */ u8 b10;
    /* 0x011 */ u8 b11;
    /* 0x012 */ u8 b12;
    /* 0x013 */ u8 pad13[0x1];
} Rec14;

typedef struct B17Vtx {
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u16 flag;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00C */ u8 col[4];
} B17Vtx;

typedef struct VtxBlk {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 count;
    /* 0x008 */ B17Vtx v[1];
} VtxBlk;

typedef struct IdObj {
    /* 0x000 */ u8 pad0[0xBC];
    /* 0x0BC */ u8 id;
} IdObj;

typedef struct SumNode {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 val;
} SumNode;

typedef struct Rect4 {
    /* 0x000 */ f32 x0;
    /* 0x004 */ f32 z0;
    /* 0x008 */ f32 x1;
    /* 0x00C */ f32 z1;
} Rect4;

typedef struct Hnd {
    /* 0x000 */ u16 id;
    /* 0x002 */ u16 fl;
} Hnd;

typedef struct Rec5A {
    /* 0x000 */ u8 pad0[0x58];
    /* 0x058 */ u8 b58;
    /* 0x059 */ u8 b59;
} Rec5A;

typedef struct FSlot {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 v;
} FSlot;

typedef struct TNode {
    /* 0x000 */ u16 id;
    /* 0x002 */ u16 fl;
    /* 0x004 */ FSlot *s0;
    /* 0x008 */ FSlot *s1;
    /* 0x00C */ FSlot *s2;
    /* 0x010 */ struct TNode *c0;
    /* 0x014 */ struct TNode *c1;
    /* 0x018 */ struct TNode *c2;
} TNode;

typedef struct Ent2E8 {
    /* 0x000 */ u8 pad0[0x170];
    /* 0x170 */ u8 f170;
    /* 0x171 */ u8 pad171[0x177];
} Ent2E8;

typedef struct DLNode {
    /* 0x000 */ struct DLNode *prev;
    /* 0x004 */ struct DLNode *next;
} DLNode;

typedef struct DLList {
    /* 0x000 */ DLNode *head;
    /* 0x004 */ DLNode *tail;
    /* 0x008 */ s32 count;
} DLList;

typedef struct NodePool {
    /* 0x000 */ DLList freel;
    /* 0x00C */ DLList usedl;
} NodePool;

typedef struct Mtx64 {
    /* 0x000 */ u8 b[64];
} Mtx64;

typedef struct MtxStack {
    /* 0x000 */ Mtx64 *base;
    /* 0x004 */ s32 n;
    /* 0x008 */ s32 left;
    /* 0x00C */ Mtx64 *cur;
} MtxStack;

typedef struct WEnt {
    /* 0x000 */ s16 id;
    /* 0x002 */ s16 w;
} WEnt;

typedef struct Pair16 {
    /* 0x000 */ s16 a;
    /* 0x002 */ s16 b;
} Pair16;

typedef struct FnEnt {
    /* 0x000 */ void (*fn0)();
    /* 0x004 */ void (*fn1)();
} FnEnt;

typedef struct PtrVal {
    /* 0x000 */ s32 *p;
    /* 0x004 */ s32 v;
} PtrVal;

typedef struct GBlk {
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ void *u20;
    /* 0x024 */ u8 pad24[0x1C];
    /* 0x040 */ u8 u40;
    /* 0x041 */ u8 pad41[0x121C];
    /* 0x125D */ u8 f125D;
    /* 0x125E */ u8 pad125E[0x2];
} GBlk;

typedef struct Rec16 {
    /* 0x000 */ u8 pad0[0x10];
} Rec16;

typedef struct Rec32 {
    /* 0x000 */ u8 pad0[0x20];
} Rec32;

typedef struct TriSrc {
    /* 0x000 */ u16 w0;
    /* 0x002 */ u16 w2;
    /* 0x004 */ u16 vi[3];
    /* 0x00A */ u16 ei[3];
    /* 0x010 */ s32 p10;
} TriSrc;

typedef struct TriDst {
    /* 0x000 */ u16 w0;
    /* 0x002 */ u16 w2;
    /* 0x004 */ Rec16 *v[3];
    /* 0x010 */ Rec32 *e[3];
    /* 0x01C */ s32 p1C;
} TriDst;

typedef struct Pt3 {
    /* 0x000 */ f32 x;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f32 z;
} Pt3;

typedef struct Poly3 {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ Pt3 *v[3];
} Poly3;

typedef struct Box3 {
    /* 0x000 */ Vec3f mn;
    /* 0x00C */ Vec3f mx;
} Box3;

typedef struct Tri3 {
    /* 0x000 */ u8 pad0[0x2];
    /* 0x002 */ u16 fl;
    /* 0x004 */ Vec3f *v[3];
} Tri3;

typedef struct RecW {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 u4;
    /* 0x008 */ s32 w[1];
} RecW;

typedef struct Pt4 {
    /* 0x000 */ f32 x;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 y;
} Pt4;

typedef struct Tri4 {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ Pt4 *v[3];
} Tri4;

typedef struct Quat {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 w;
} Quat;

typedef struct Mat4F {
    /* 0x000 */ f32 m[16];
} Mat4F;

typedef struct Probe {
    /* 0x000 */ f32 f0;
    /* 0x004 */ f32 f4;
    /* 0x008 */ Vec3f v8;
    /* 0x014 */ Vec3f v14;
    /* 0x020 */ u8 pad20[0x98];
    /* 0x0B8 */ u8 bB8;
    /* 0x0B9 */ u8 bB9;
    /* 0x0BA */ u8 padBA[0x1];
    /* 0x0BB */ u8 bBB;
} Probe;

typedef struct LightB {
    /* 0x000 */ u8 pad0[0x11];
    /* 0x011 */ s8 x;
    /* 0x012 */ s8 y;
    /* 0x013 */ s8 z;
} LightB;

typedef struct WRec {
    /* 0x000 */ u8 pad0[0xA0];
    /* 0x0A0 */ Box3 box;
    /* 0x0B8 */ u8 padB8[0x2];
    /* 0x0BA */ u8 bBA;
    /* 0x0BB */ u8 padBB[0x2];
    /* 0x0BD */ u8 bBD;
    /* 0x0BE */ u8 padBE[0x2];
} WRec;

typedef struct WTab {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 count;
    /* 0x008 */ WRec r[1];
} WTab;

typedef struct IdList {
    /* 0x000 */ s16 n;
    /* 0x002 */ s16 id[1];
} IdList;

typedef struct Evt {
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u16 id;
} Evt;

#endif
