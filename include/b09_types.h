#ifndef B09_TYPES_H
#define B09_TYPES_H

#include "common.h"
#include "p1_types.h"

/* object sorted by a float key at +0x210 (qsort comparators 0023B93C/0023B968) */
typedef struct B09SortObj {
    /* 0x000 */ u8 pad0[0x210];
    /* 0x210 */ f32 key;
} B09SortObj;

/* definition/constants block pointed to by B09Emitter.def (first halfword is an id) */
typedef struct B09EDef {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ f32 f8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
    /* 0x24 */ u8 pad24[5];
    /* 0x29 */ u8 flags29;
} B09EDef;

/* emitter-like object initialised by func_0023B684, updated by func_0023B708 */
typedef struct B09Emitter B09Emitter;
struct B09Emitter {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ B09Emitter *next;
    /* 0x008 */ u8 pad8[4];
    /* 0x00C */ B09EDef *def;
    /* 0x010 */ u16 mask;
    /* 0x012 */ u8 pad12[2];
    /* 0x014 */ u8 pad14[8];
    /* 0x01C */ f32 f1C;
    /* 0x020 */ f32 f20;
    /* 0x024 */ u8 pad24[0x1E4];
    /* 0x208 */ f32 f208;
    /* 0x20C */ f32 f20C;
    /* 0x210 */ f32 key;
    /* 0x214 */ f32 f214;
    /* 0x218 */ f32 f218;
    /* 0x21C */ f32 f21C;
    /* 0x220 */ f32 f220;
};

typedef struct B09V3 { f32 x, y, z; } B09V3;

typedef struct B09Obj {
    /* 0x000 */ u8 pad0[0x48];
    /* 0x048 */ B09V3 v48;
    /* 0x054 */ u8 pad54[0x138];
    /* 0x18C */ B09V3 v18C;
} B09Obj;

typedef struct B09Vec3 { f32 x, y, z; } B09Vec3;

/* block of 0x70 bytes copied as a unit */
typedef struct B09Blk70 {
    s32 w[28];
} B09Blk70;

/* scratch record the pointer D_80103FCC points to (only touched words are named) */
typedef struct B09Obj2 {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ B09V3 v8;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ B09Blk70 blk18;
    /* 0x088 */ s32 unk88;
    /* 0x08C */ s32 unk8C;
    /* 0x090 */ B09V3 v90;
    /* 0x09C */ s32 unk9C;
    /* 0x0A0 */ u8 padA0[0x10];
    /* 0x0B0 */ s32 unkB0;
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ u8 padB8[0xC];
    /* 0x0C4 */ s32 unkC4;
    /* 0x0C8 */ B09V3 vC8;
    /* 0x0D4 */ s32 unkD4;
    /* 0x0D8 */ u8 padD8[0xC];
    /* 0x0E4 */ B09V3 vE4;
    /* 0x0F0 */ B09V3 vF0;
    /* 0x0FC */ s32 unkFC;
    /* 0x100 */ s32 unk100;
} B09Obj2;

/* doubly linked list (func_0023CB50 push back, func_0023CBF8 unlink); head/tail globals D_80103E20/D_80103E24 */
typedef struct B09LNode B09LNode;
struct B09LNode {
    /* 0x00 */ B09LNode *next;
    /* 0x04 */ B09LNode *prev;
    /* 0x08 */ u16 slot;
    /* 0x0A */ u8 id;
    /* 0x0B */ u8 tlb;
    /* 0x0C */ s32 unkC;
};

typedef struct B09List {
    /* 0x00 */ B09LNode *head;
    /* 0x04 */ B09LNode *tail;
} B09List;

/* region table entry (list head D_80103F88) */
typedef struct B09Region B09Region;
struct B09Region {
    /* 0x00 */ B09Region *next;
    /* 0x04 */ u16 base;
    /* 0x06 */ u16 size;
    /* 0x08 */ u8 pad8[8];
    /* 0x10 */ u8 *data;
    /* 0x14 */ u8 pad14[4];
};

/* request block of func_0023CDC4 */
typedef struct B09RegReq {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 bytes;
    /* 0x08 */ B09Region *node;
    /* 0x0C */ OSMesgQueue *reply;
} B09RegReq;

/* request block of func_0023CCC4 (free a region by its address) */
typedef struct B09FreeReq {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 addr;
    /* 0x08 */ OSMesgQueue *reply;
} B09FreeReq;

/* object with a flag word at +0x3C (0023EBEC / 0023EC44) */
typedef struct B09FlagObj {
    /* 0x00 */ u8 pad0[0x3C];
    /* 0x3C */ u32 flags;
} B09FlagObj;

/* event/input record read by 0023EBEC (+0x10 bit mask) and 0023EC44 (+0xC kind) */
typedef struct B09Evt {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 kind;
    /* 0x10 */ u32 mask;
} B09Evt;

/* range record set by func_0023E680 */
typedef struct B09Range {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ f32 a;
    /* 0x0C */ s32 id;
    /* 0x10 */ f32 b;
    /* 0x14 */ f32 c;
    /* 0x18 */ f32 hi;
} B09Range;

/* TLB slot tables: D_80103F28 (4 bytes/entry, B09SlotA) and D_80103B50 (B09LNode, 16 bytes/entry), 24 entries each */
typedef struct B09SlotA {
    /* 0 */ u16 key;
    /* 2 */ u8 a;
    /* 3 */ u8 b;
} B09SlotA;

typedef struct B09SlotCtl {
    /* 0 */ u16 cur;
    /* 2 */ u16 start;
} B09SlotCtl;

/* record returned by func_0028B2D4 and tested by func_0023ECAC */
typedef struct B09Seat {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ u32 flags44;
    /* 0x48 */ u8 pad48[8];
    /* 0x50 */ u8 pad50[2];
    /* 0x52 */ u16 h52;
} B09Seat;

/* two objects compared by func_0023ED54 */




/* eight corner points (func_00240D10 .. func_00241170 take a box and build one face) */
typedef struct B09Box {
    /* 0x00 */ B09V3 p[8];
} B09Box;

/* quad face record: 4 corner points at +0x18, plane data at +0x48 */
typedef struct B09Quad {
    /* 0x00 */ s32 type0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[8];
    /* 0x14 */ s32 kind;
    /* 0x18 */ B09V3 v[4];
    /* 0x48 */ f32 nx;
    /* 0x4C */ f32 ny;
    /* 0x50 */ f32 nz;
    /* 0x54 */ u8 pad54[0x78];
    /* 0xCC */ f32 t;
    /* 0xD0 */ B09V3 hit;
} B09Quad;

/* constants block pointed to by B09Body.def */
typedef struct B09BodyDef {
    /* 0x00 */ u32 flags;
    /* 0x04 */ s8 b4;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ f32 f8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
} B09BodyDef;

/* collision body (func_0023F634, func_0023E6DC) */
typedef struct B09Body {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ u8 pad18[0x28];
    /* 0x40 */ B09BodyDef *def;
    /* 0x44 */ f32 f44;
    /* 0x48 */ f32 f48;
    /* 0x4C */ f32 f4C;
    /* 0x50 */ f32 f50;
    /* 0x54 */ f32 f54;
    /* 0x58 */ f32 f58;
    /* 0x5C */ u8 pad5C[0x18];
    /* 0x74 */ B09V3 v74;
} B09Body;

/* bounds computed by func_0023F634 */
typedef struct B09Bounds {
    /* 0x00 */ f32 r;
    /* 0x04 */ f32 c4;
    /* 0x08 */ f32 c8;
    /* 0x0C */ f32 cC;
    /* 0x10 */ f32 c10;
    /* 0x14 */ f32 c14;
    /* 0x18 */ f32 c18;
    /* 0x1C */ f32 c1C;
    /* 0x20 */ f32 c20;
    /* 0x24 */ f32 c24;
    /* 0x28 */ f32 c28;
    /* 0x2C */ u32 flag;
} B09Bounds;

/* axis aligned box (min x, min z, max x, max z) */
typedef struct B09Box2 {
    /* 0x00 */ f32 minx;
    /* 0x04 */ f32 minz;
    /* 0x08 */ f32 maxx;
    /* 0x0C */ f32 maxz;
} B09Box2;





/* world object table at D_8011FE88: up to 0x200 entity pointers at +0x144, count at +0x944 */
typedef struct B09Ent2 B09Ent2;

typedef struct B09Ent {
    /* 0x000 */ u8 kind;
    /* 0x001 */ u8 pad1[7];
    /* 0x008 */ B09V3 v8;
    /* 0x014 */ u8 pad14[0x104];
    /* 0x118 */ u32 *unk118;
    /* 0x11C */ u8 pad11C[0x10];
    /* 0x12C */ B09Ent2 *unk12C;
    /* 0x130 */ u8 pad130[0x44];
    /* 0x174 */ s32 unk174;
} B09Ent;

/* second kind of world entity (static geometry etc.), bounds at +0xE8 */
struct B09Ent2 {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ s32 *def;
    /* 0x01C */ u8 pad1C[0xC8];
    /* 0x0E4 */ u16 uE4;
    /* 0x0E6 */ u8 padE6[2];
    /* 0x0E8 */ f32 fE8;
    /* 0x0EC */ f32 fEC;
    /* 0x0F0 */ f32 fF0;
    /* 0x0F4 */ f32 fF4;
    /* 0x0F8 */ f32 fF8;
    /* 0x0FC */ f32 fFC;
    /* 0x100 */ u32 flags100;
};

typedef struct B09World {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ B09Ent *ents[0x200];
    /* 0x944 */ s32 count;
    /* 0x948 */ B09Ent2 *ents2[0x80];
    /* 0xB48 */ s32 count2;
} B09World;

/* async load request handled by func_0023CE8C */
typedef struct B09TaskBlk {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u16 state;
    /* 0x14 */ u8 pad14[3];
    /* 0x17 */ u8 b17;
} B09TaskBlk;

typedef struct B09LoadReq {
    /* 0x00 */ s16 type;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ s32 src;
    /* 0x08 */ s32 len;
    /* 0x0C */ s16 slot;
    /* 0x0E */ u8 padE[2];
    /* 0x10 */ B09LNode *node;
    /* 0x14 */ B09TaskBlk *task;
    /* 0x18 */ u8 *data;
} B09LoadReq;

/* loader thread control block at D_80103720: thread, then a 0x200 byte stack at +0x230 (D_80103950) */
typedef struct B09LoaderCtl {
    /* 0x000 */ OSThread thr;
    /* ..... */ u8 pad[0x230 - sizeof(OSThread)];
    /* 0x230 */ u8 stack[0x200];
} B09LoaderCtl;

/* loader message queues: load request queue at +0 (D_80103254), DMA thread queue at +0xAB4 (D_80103D08) */
typedef struct B09IoQ {
    /* 0x000 */ OSMesgQueue loadq;
    /* ..... */ u8 pad[0xAB4 - sizeof(OSMesgQueue)];
    /* 0xAB4 */ OSMesgQueue dmaq;
} B09IoQ;

/* object read by func_0023E44C (type at +0xB0 selects what is copied into *D_80103FCC) */
typedef struct B09RefW {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 w14;
} B09RefW;

typedef struct B09SrcObj {
    /* 0x000 */ u8 pad0[0xB0];
    /* 0x0B0 */ s32 type;
    /* 0x0B4 */ u8 padB4[8];
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ u8 padC4[0x34];
    /* 0x0F8 */ B09V3 vF8;
    /* 0x104 */ B09RefW *ref;
    /* 0x108 */ s32 unk108;
    /* 0x10C */ B09Blk70 blk10C;
    /* 0x17C */ u8 pad17C[4];
    /* 0x180 */ B09V3 v180;
} B09SrcObj;

typedef struct B09Hit2 {
    B09Ent2 *e;
    f32 t;
} B09Hit2;

/* 3d axis aligned box */
typedef struct B09Box3 {
    /* 0x00 */ f32 minx;
    /* 0x04 */ f32 miny;
    /* 0x08 */ f32 minz;
    /* 0x0C */ f32 maxx;
    /* 0x10 */ f32 maxy;
    /* 0x14 */ f32 maxz;
} B09Box3;

/* mover object: position-ish vectors at +0x44/+0x50, latest quad hit copied to +0xB0 */
typedef struct B09Mover {
    /* 0x000 */ B09Ent *owner;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x20];
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ u8 pad30[0x10];
    /* 0x040 */ B09BodyDef *def;
    /* 0x044 */ B09V3 v44;
    /* 0x050 */ B09V3 v50;
    /* 0x05C */ B09V3 v5C;
    /* 0x068 */ B09V3 v68;
    /* 0x074 */ B09V3 v74;
    /* 0x080 */ f32 f80;
    /* 0x084 */ f32 f84;
    /* 0x088 */ f32 f88;
    /* 0x08C */ f32 f8C;
    /* 0x090 */ f32 f90;
    /* 0x094 */ f32 f94;
    /* 0x098 */ f32 f98;
    /* 0x09C */ B09Box2 box;
    /* 0x0AC */ u8 padAC[4];
    /* 0x0B0 */ B09Quad qcopy;
    /* 0x18C */ u8 pad18C[0x1C];
} B09Mover;

/* misc global flags block at D_801462C8 */
typedef struct B09Misc {
    u8 pad0[0x1D];
    u8 b1D;
} B09Misc;

/* scene object holding the emitter list (+0x8B4) and a draw flag (+0x8C4) */
typedef struct B09Scene {
    /* 0x000 */ u8 pad0[0x8B4];
    /* 0x8B4 */ B09Emitter *emitters;
    /* 0x8B8 */ u8 pad8B8[0xC];
    /* 0x8C4 */ s32 unk8C4;
} B09Scene;

/* camera / view object read by func_0023B3E8 */
typedef struct B09Cam {
    /* 0x000 */ u8 pad0[0x120];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[8];
    /* 0x12C */ f32 depth;
} B09Cam;

/* definition block (at Obj.def18 + 0x14) used by func_00241940 */
typedef struct B09XDef {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u16 mode;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
} B09XDef;

typedef struct B09XObj {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ s32 w8;
    /* 0x00C */ s32 wC;
    /* 0x010 */ s32 w10;
    /* 0x014 */ u8 pad14[4];
    /* 0x018 */ u8 *def18;
    /* 0x01C */ u8 pad1C[0x40];
    /* 0x05C */ u8 v5C[0x10];
    /* 0x06C */ f32 f6C;
    /* 0x070 */ u8 pad70[0x100];
    /* 0x170 */ u8 w170[0x134];
    /* 0x2A4 */ s32 pad2A4;
} B09XObj;

typedef struct B09YObj {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ f32 f10;
    /* 0x14 */ u8 pad14[0x40];
    /* 0x54 */ f32 f54;
} B09YObj;

#endif
