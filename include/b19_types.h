#ifndef B19_TYPES_H
#define B19_TYPES_H

#include "common.h"

typedef struct B19Dl { u32 w0; u32 w1; } B19Dl;

/* Types recovered in batch 19 (game code 0x00282A18-0x0028B...).  Padding explicit; names provisional. */

typedef struct B19Cam B19Cam;
typedef struct B19Hand B19Hand;
typedef struct B19Def B19Def;
typedef struct B19Sort B19Sort;
typedef struct B19Draw B19Draw;
typedef struct B19Cell B19Cell;
typedef struct B19Cells B19Cells;
typedef struct B19Tri B19Tri;
typedef struct B19Inp B19Inp;
typedef struct B19Glo B19Glo;
typedef struct B19Scene B19Scene;
typedef struct B19DlItem B19DlItem;
typedef struct B19Rng B19Rng;
typedef struct B19Ent12 B19Ent12;
typedef struct B19Aabb B19Aabb;
typedef struct B19Item B19Item;
typedef struct B19Set B19Set;
typedef struct B19PoolF B19PoolF;
typedef struct B19Big B19Big;
typedef struct B19Box B19Box;
typedef struct B19Info18 B19Info18;
typedef struct B19PF B19PF;
typedef struct B19Q2 B19Q2;
typedef struct B19Plr B19Plr;
typedef struct B19Lim B19Lim;
typedef struct B19Vec4 B19Vec4;
typedef struct B19Q B19Q;
typedef struct B19Mtx B19Mtx;
typedef struct B19Glob B19Glob;
typedef struct B19GObj B19GObj;
typedef struct B19Rec8 B19Rec8;
typedef struct B19Tbl B19Tbl;
typedef struct B19RecIn B19RecIn;
typedef struct B19RecOut B19RecOut;
typedef struct B19Spawn B19Spawn;
typedef struct B19Spec B19Spec;
typedef struct B19Pair B19Pair;
typedef struct B19Ent B19Ent;
typedef struct B19Row B19Row;
typedef struct B19Info38 B19Info38;
typedef struct B19List B19List;
typedef struct B19Owner B19Owner;
typedef struct B19Handle B19Handle;
typedef struct B19PNode B19PNode;
typedef struct B19Pool B19Pool;
typedef struct B19Slot B19Slot;
typedef struct B19Vec3 B19Vec3;
typedef struct B19Src B19Src;
typedef struct B19Parent B19Parent;
typedef struct B19Obj B19Obj;

struct B19Cam {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ B19Cam * next;
    /* 0x8 */ u8 pad8[0x120];
    /* 0x128 */ f32 x;
    /* 0x12C */ u8 pad12C[0x4];
    /* 0x130 */ f32 z;
    /* 0x134 */ u8 pad134[0x234];
    /* 0x368 */ f32 a;
    /* 0x36C */ u8 pad36C[0x4];
    /* 0x370 */ f32 b;
    /* 0x374 */ f32 c;
    /* 0x378 */ u8 pad378[0x4];
    /* 0x37C */ f32 d;
};

struct B19Hand {
    /* 0x0 */ s32 * p;
};

struct B19Def {
    /* 0x0 */ u8 pad0[0x6];
    /* 0x6 */ s8 b6;
    /* 0x7 */ s8 b7;
    /* 0x8 */ u8 pad8[0x4];
    /* 0xC */ s16 sC;
};

struct B19Sort {
    /* 0x0 */ u8 * obj;
    /* 0x4 */ f32 key;
};

struct B19Draw {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 pad1[0x7];
    /* 0x8 */ f32 a8;
    /* 0xC */ f32 aC;
    /* 0x10 */ f32 a10;
    /* 0x14 */ u8 pad14[0xA4];
    /* 0xB8 */ f32 aB8;
    /* 0xBC */ f32 aBC;
    /* 0xC0 */ f32 aC0;
    /* 0xC4 */ f32 aC4;
    /* 0xC8 */ f32 aC8;
    /* 0xCC */ f32 aCC;
};

struct B19Cell {
    /* 0x0 */ f32 x0;
    /* 0x4 */ f32 z0;
    /* 0x8 */ f32 x1;
    /* 0xC */ f32 z1;
    /* 0x10 */ u32 n;
};

struct B19Cells {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ s32 cnt;
    /* 0x8 */ B19Cell c[1];
};

struct B19Tri {
    /* 0x0 */ u8 pad0[0x2];
    /* 0x2 */ u16 fl;
    /* 0x4 */ u8 pad4[0x1C];
};

struct B19Inp {
    /* 0x0 */ u32 flags;
    /* 0x4 */ u8 pad4[0xC];
    /* 0x10 */ s32 val;
};

struct B19Glo {
    /* 0x0 */ u8 pad0[0x180C];
    /* 0x180C */ s32 f180C;
};

struct B19Scene {
    /* 0x0 */ u8 pad0[0x88];
    /* 0x88 */ s32 f88;
    /* 0x8C */ u8 pad8C[0x6C];
    /* 0xF8 */ s32 fF8;
    /* 0xFC */ u8 padFC[0x24];
    /* 0x120 */ B19Dl * dlp[2];
};

struct B19DlItem {
    /* 0x0 */ u8 pad0[0xD8];
    /* 0xD8 */ u16 fD8;
};

struct B19Rng {
    /* 0x0 */ f32 x0;
    /* 0x4 */ f32 z0;
    /* 0x8 */ f32 x1;
    /* 0xC */ f32 z1;
};

struct B19Ent12 {
    /* 0x0 */ s32 ** pp;
    /* 0x4 */ B19Rng * box;
    /* 0x8 */ s16 a;
    /* 0xA */ s16 b;
};

struct B19Aabb {
    /* 0x0 */ f32 mn[3];
    /* 0xC */ f32 mx[3];
};

struct B19Item {
    /* 0x0 */ u8 pad0[0xA0];
    /* 0xA0 */ B19Aabb bb;
    /* 0xB8 */ u8 padB8[0x8];
};

struct B19Set {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ s32 cnt;
    /* 0x8 */ B19Item it[1];
};

struct B19PoolF {
    /* 0x0 */ u8 pad0[0x14];
    /* 0x14 */ B19Spawn * head;
    /* 0x18 */ u8 pad18[0x10];
    /* 0x28 */ f32 total;
};

struct B19Big {
    /* 0x0 */ u8 pad0[0x18];
    /* 0x18 */ B19Info18 * info;
    /* 0x1C */ u8 pad1C[0x2CC];
};

struct B19Info18 {
    /* 0x0 */ s32 type;
    /* 0x4 */ u32 f4;
    /* 0x8 */ u8 pad8[0x4];
    /* 0xC */ s16 sC;
    /* 0xE */ u8 padE[0x12];
    /* 0x20 */ s32 f20;
};

struct B19PF {
    /* 0x0 */ u8 pad0[0x1C];
    /* 0x1C */ f32 a;
    /* 0x20 */ f32 b;
};

struct B19Q2 {
    /* 0x0 */ u8 pad0[0x6C];
    /* 0x6C */ f32 f6C;
};

struct B19Lim {
    /* 0x0 */ u8 pad0[0x10];
    /* 0x10 */ u16 a;
    /* 0x12 */ u16 b;
};

struct B19Vec4 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
    /* 0xC */ f32 w;
};

struct B19Mtx {
    /* 0x0 */ f32 m[16];
};

struct B19Glob {
    /* 0x0 */ void * g;
    /* 0x4 */ u8 pad4[0x10];
    /* 0x14 */ s32 idx;
};

struct B19GObj {
    /* 0x0 */ u8 pad0[0xB4];
    /* 0xB4 */ B19Mtx * mtx;
};

struct B19Rec8 {
    /* 0x0 */ s32 a;
    /* 0x4 */ s32 b;
};

struct B19Tbl {
    /* 0x0 */ B19Rec8 rec[14];
    /* 0x70 */ u16 w70[14];
    /* 0x8C */ u16 w8C[14];
    /* 0xA8 */ u16 wA8[14];
};

struct B19RecIn {
    /* 0x0 */ s32 f0;
    /* 0x4 */ u32 f4;
    /* 0x8 */ u16 f8;
    /* 0xA */ u8 fA;
    /* 0xB */ u8 padB[0x1];
    /* 0xC */ u8 b[8];
    /* 0x14 */ u16 h14;
    /* 0x16 */ u16 h16;
};

struct B19RecOut {
    /* 0x0 */ u32 f0;
    /* 0x4 */ u16 f4;
    /* 0x6 */ u8 f6;
    /* 0x7 */ u8 pad7[0x1];
    /* 0x8 */ s32 f8;
    /* 0xC */ u8 padC[0x4];
    /* 0x10 */ u8 b[8];
    /* 0x18 */ u16 h18;
    /* 0x1A */ u16 h1A;
};

struct B19Spec {
    /* 0x0 */ s16 a;
    /* 0x2 */ s16 b;
};

struct B19Pair {
    /* 0x0 */ u16 a;
    /* 0x2 */ u16 b;
};

struct B19Ent {
    /* 0x0 */ s16 kind;
    /* 0x2 */ u8 pad2[0x2];
    /* 0x4 */ s16 id;
};

struct B19Row {
    /* 0x0 */ u8 pad0[0x20];
    /* 0x20 */ B19Ent * a[3];
    /* 0x2C */ B19Ent * b[3];
};

struct B19Info38 {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s8 idx;
    /* 0x9 */ u8 pad9[0x3];
    /* 0xC */ s8 n;
};

struct B19List {
    /* 0x0 */ B19Obj * head;
    /* 0x4 */ B19Obj * tail;
    /* 0x8 */ u8 pad8[0xC];
};

struct B19Owner {
    /* 0x0 */ s32 mode;
    /* 0x4 */ u8 pad4[0x2C];
    /* 0x30 */ s32 f30;
    /* 0x34 */ u8 pad34[0xC];
    /* 0x40 */ s32 f40;
    /* 0x44 */ u8 pad44[0x20];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ s32 f6C;
    /* 0x70 */ u8 pad70[0x10];
    /* 0x80 */ s32 root;
    /* 0x84 */ u8 pad84[0x8];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ u8 pad90[0x58];
    /* 0xE8 */ s32 fE8;
    /* 0xEC */ u8 padEC[0x34];
    /* 0x120 */ s32 f120;
    /* 0x124 */ s32 f124;
    /* 0x128 */ u8 pad128[0x10];
    /* 0x138 */ u8 * base;
    /* 0x13C */ u8 pad13C[0x4];
    /* 0x140 */ s32 cnt;
    /* 0x144 */ u8 pad144[0xB0C];
    /* 0xC50 */ B19Obj * arr[128];
    /* 0xE50 */ s32 nobj;
    /* 0xE54 */ u8 padE54[0x268];
    /* 0x10BC */ s32 ndraw;
    /* 0x10C0 */ B19Draw * draw[1];
    /* 0x10C4 */ u8 pad10C4[0x43C];
    /* 0x1500 */ s32 ncount;
    /* 0x1504 */ s32 nent;
    /* 0x1508 */ B19Ent12 ent[1];
    /* 0x1514 */ u8 pad1514[0xE6EC];
    /* 0xFC00 */ B19List la;
    /* 0xFC14 */ B19List lb;
    /* 0xFC28 */ B19List slot[8];
    /* 0xFCC8 */ u8 padFCC8[0xB640];
    /* 0x1B308 */ f32 f1B308;
    /* 0x1B30C */ u8 pad1B30C[0x100];
    /* 0x1B40C */ s32 key;
    /* 0x1B410 */ u8 pad1B410[0x4];
    /* 0x1B414 */ s32 f1B414;
    /* 0x1B418 */ u8 pad1B418[0x208];
    /* 0x1B620 */ B19Obj * list[16];
    /* 0x1B660 */ s32 listcnt;
    /* 0x1B664 */ u8 pad1B664[0x4C];
    /* 0x1B6B0 */ s32 * f1B6B0;
    /* 0x1B6B4 */ u8 pad1B6B4[0x25C];
    /* 0x1B910 */ f32 f1B910;
    /* 0x1B914 */ f32 f1B914;
    /* 0x1B918 */ f32 f1B918;
    /* 0x1B91C */ f32 f1B91C;
    /* 0x1B920 */ u8 pad1B920[0x8];
    /* 0x1B928 */ s32 f1B928;
    /* 0x1B92C */ s32 f1B92C;
};

struct B19Handle {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ s32 f8;
    /* 0xC */ s32 fC;
};

struct B19PNode {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ B19PNode * next;
};

struct B19Pool {
    /* 0x0 */ u8 pad0[0x14];
    /* 0x14 */ B19PNode * head;
    /* 0x18 */ u8 pad18[0x10];
    /* 0x28 */ s32 count;
};

struct B19Slot {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ B19Obj * obj;
    /* 0x8 */ u8 pad8[0xC];
};

struct B19Vec3 {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
};

struct B19Box {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ B19Vec3 pos;
    /* 0x14 */ u8 pad14[0x3C];
};

struct B19Plr {
    /* 0x0 */ u8 pad0[0x8];
    /* 0x8 */ B19Vec3 pos;
    /* 0x14 */ u8 pad14[0x684];
    /* 0x698 */ u8 * f698;
    /* 0x69C */ u8 pad69C[0xB50];
    /* 0x11EC */ f32 f11EC;
    /* 0x11F0 */ u8 pad11F0[0x4F0];
    /* 0x16E0 */ B19Plr * next;
};

struct B19Q {
    /* 0x0 */ B19Vec3 v;
    /* 0xC */ s32 k;
};

struct B19Spawn {
    /* 0x0 */ u8 pad0[0x4];
    /* 0x4 */ B19Spawn * next;
    /* 0x8 */ void * src;
    /* 0xC */ B19Vec3 pos;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ s32 h20;
    /* 0x24 */ u8 pad24[0x8];
    /* 0x2C */ s32 h2C;
    /* 0x30 */ u8 pad30[0x8];
    /* 0x38 */ B19Spawn ** link;
};

struct B19Src {
    /* 0x0 */ B19Vec3 a;
    /* 0xC */ u8 padC[0x3];
    /* 0xF */ u8 fF;
    /* 0x10 */ u8 pad10[0xC0];
    /* 0xD0 */ B19Vec3 b;
};

struct B19Parent {
    /* 0x0 */ u32 flags;
    /* 0x4 */ u8 pad4[0xC];
    /* 0x10 */ s16 s10;
    /* 0x12 */ u8 pad12[0x2];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ B19Tbl * tbl;
    /* 0x1C */ u8 pad1C[0x8];
    /* 0x24 */ B19PF * pf;
    /* 0x28 */ u8 pad28[0x8];
    /* 0x30 */ B19Lim * lim;
    /* 0x34 */ u8 pad34[0x4];
    /* 0x38 */ B19Info38 * info38;
};

struct B19Obj {
    /* 0x0 */ s8 kind;
    /* 0x1 */ u8 pad1[0x3];
    /* 0x4 */ u16 id;
    /* 0x6 */ u8 pad6[0x2];
    /* 0x8 */ B19Vec3 pos;
    /* 0x14 */ u8 pad14[0x4];
    /* 0x18 */ void * info;
    /* 0x1C */ B19Vec3 pos2;
    /* 0x28 */ u8 pad28[0x34];
    /* 0x5C */ u32 flags;
    /* 0x60 */ u8 pad60[0xA0];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0x14];
    /* 0x118 */ B19Parent * parent;
    /* 0x11C */ u8 pad11C[0x8];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ s32 unk128;
    /* 0x12C */ s32 unk12C;
    /* 0x130 */ s32 * unk130;
    /* 0x134 */ void * unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ u8 pad13C[0x10];
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 pad14E[0x26];
    /* 0x174 */ B19Vec3 vel;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
    /* 0x188 */ u8 pad188[0x48];
    /* 0x1D0 */ s8 unk1D0;
    /* 0x1D1 */ u8 unk1D1;
    /* 0x1D2 */ u8 pad1D2[0x7];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[0x2];
    /* 0x1DC */ B19Handle * unk1DC;
    /* 0x1E0 */ u8 pad1E0[0x4];
    /* 0x1E4 */ B19List * slotp;
    /* 0x1E8 */ u8 pad1E8[0x4];
    /* 0x1EC */ B19Obj * next;
    /* 0x1F0 */ s32 unk1F0;
    /* 0x1F4 */ B19Obj * next2;
};

#endif
