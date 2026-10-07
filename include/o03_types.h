#ifndef O03_TYPES_H
#define O03_TYPES_H
#include "common.h"

/* display-list word pair appended through D_80110634 */
typedef struct O3Dl {
    u32 w0;
    u32 w1;
} O3Dl;

#define O3_PUSH(a, b) { O3Dl *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }


/* generic overlay "widget" header (shared by the UI object classes) */
typedef struct O3Hdr {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ struct O3Hdr *next;
    /* 0x08 */ struct O3Hdr *child;
    /* 0x0C */ s16 id;
    /* 0x0E */ u16 id2;
    /* 0x10 */ u8 alpha;
    /* 0x11 */ u8 pad11;
    /* 0x12 */ s16 unk12;
} O3Hdr;

/* class A: flickering light effect (0xB62) */
typedef struct O3A {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s16 id;
    /* 0x0E */ s16 id2;
    /* 0x10 */ u8 pad10[2];
    /* 0x12 */ s16 unk12;
    /* 0x14 */ u8 pad14[0x30];
    /* 0x44 */ s32 flag;
    /* 0x48 */ s32 count;
    /* 0x4C */ s32 vals[5];
    /* 0x60 */ s32 cnts[5];
    /* 0x74 */ s32 idx;
    /* 0x78 */ O3Hdr *gobj;
    /* 0x7C */ s32 timer;
    /* 0x80 */ u32 base;
    /* 0x84 */ s32 state;
} O3A;


/* message handler table entry (class dispatchers) */
typedef struct O3Msg {
    s32 msg;
    s32 type;
    s32 (*fn)();
} O3Msg;


/* class 0xB5F menu: cursor / count / flags */
typedef struct O3MenuG {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ s32 col;
} O3MenuG;

typedef struct O3Menu {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ O3MenuG *g;
    /* 0x48 */ s32 *tbl;
    /* 0x4C */ s32 cur;
    /* 0x50 */ s32 cnt;
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 f58;
    /* 0x5C */ s32 flags;
    /* 0x60 */ s32 f60;
} O3Menu;

typedef struct O3BarG {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s16 w;
} O3BarG;

/* generic word blocks used for struct copies */
typedef struct O3Blk11 { s32 w[11]; } O3Blk11;
typedef struct O3Blk5 { s32 w[5]; } O3Blk5;

/* class 0xB63 bar */
typedef struct O3Bar {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x18];
    /* 0x2C */ O3Blk5 col;
    /* 0x40 */ u8 pad40[4];
    /* 0x44 */ O3BarG *g;
    /* 0x48 */ s32 width;
    /* 0x4C */ s32 max;
    /* 0x50 */ s32 val;
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 f58;
    /* 0x5C */ s32 flags;
} O3Bar;

/* class 0xB64 (list of 20-byte entries at 0x48) */
typedef struct O3ListG {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ void *sel;
} O3ListG;

typedef struct O3Ent {
    s32 w[5];
} O3Ent;

typedef struct O3List {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x30];
    /* 0x44 */ O3ListG *g;
    /* 0x48 */ O3Ent ent[1];
} O3List;

/* O3List as seen by the entry-append helper (count at 0x114) */
typedef struct O3List2 {
    /* 0x000 */ O3Hdr h;
    /* 0x014 */ u8 pad14[0x34];
    /* 0x048 */ O3Ent ent[1];
} O3List2;

/* class 0xB64 selector fields (far offsets) */
typedef struct O3ListSel {
    /* 0x000 */ u8 pad0[0x110];
    /* 0x110 */ s32 sel;
    /* 0x114 */ s32 cnt;
} O3ListSel;


/* 32-bit RGBA colour that is also accessed bytewise */
typedef union O3Col {
    u32 w;
    struct { u8 r, g, b, a; } c;
} O3Col;

/* class 0xB60 gfx child (position/alpha floats and two colours) */
typedef struct O3B60G {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0xC];
    /* 0x20 */ f32 fx;
    /* 0x24 */ f32 fy;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ O3Col col[4];
} O3B60G;

/* class 0xB60: fading object */
typedef struct O3B60 {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x30];
    /* 0x44 */ O3B60G *g;
    /* 0x48 */ O3B60G *g2;
    /* 0x4C */ f32 sp1;
    /* 0x50 */ f32 sp2;
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 state;
    /* 0x5C */ s32 flag;
    /* 0x60 */ u32 c[4];
    /* 0x70 */ u32 stepA;
    /* 0x74 */ u32 stepB;
    /* 0x78 */ s32 f78;
} O3B60;


/* 40-byte transform block passed by value to the paint helpers */
typedef struct O3Xf { s32 w[10]; } O3Xf;
typedef struct O3Q4 { s32 w[4]; } O3Q4;
typedef struct O3Q16 { s32 w[4]; } O3Q16;


/* class 0xB61 object: copy of a gfx node (size 0x44) */
typedef struct O3B61 {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x18];
    /* 0x2C */ O3Blk5 col;
    /* 0x40 */ u8 pad40[4];
} O3B61;


/* menu item (navigation neighbours at 0x2C..0x38) */
typedef struct O3Item {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x18];
    /* 0x2C */ struct O3Item *nbr[4];
} O3Item;

/* text item: pointer to the text at 0x38 (aliases nbr[3]) */
typedef struct O3TxtItem {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x24];
    /* 0x38 */ void *txt;
} O3TxtItem;

/* class 0x7D5 object: item set (size 0x70) */
typedef struct O3M7D5 {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x30];
    /* 0x44 */ struct O3Own *own;
    /* 0x48 */ s32 cnt;
    /* 0x4C */ O3Item *item[4];
    /* 0x5C */ s32 flag[4];
    /* 0x6C */ s32 mode;
} O3M7D5;

/* owner of an O3M7D5 object (child list at 0x08) */
typedef struct O3Own {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ O3M7D5 *child;
    /* 0x0C */ u8 padC[0x38];
    /* 0x44 */ O3M7D5 *cur;
} O3Own;


/* controller pak menu page (global D_800E3518, size 0x2C) */
typedef struct O3Pg {
    /* 0x00 */ s32 parent;
    /* 0x04 */ s32 w1;
    /* 0x08 */ s32 w2;
    /* 0x0C */ s32 w3;
    /* 0x10 */ s32 w4;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ char buf[0xC];
} O3Pg;


typedef struct O3Vec3 { f32 x, y, z; } O3Vec3;

/* controller pak slot menu page (global D_800E3590) */
typedef struct O3Pk {
    /* 0x000 */ s32 parent;
    /* 0x004 */ u8 pad4[4];
    /* 0x008 */ u8 sub[0xD0];
    /* 0x0D8 */ s32 fD8;
    /* 0x0DC */ s32 fDC;
    /* 0x0E0 */ u8 padE0[0xC];
    /* 0x0EC */ O3Hdr *cur;
    /* 0x0F0 */ O3TxtItem *tgt;
    /* 0x0F4 */ u8 padF4[0x18];
    /* 0x10C */ s32 slot;
    /* 0x110 */ u8 name[0x32];
    /* 0x142 */ u8 str142[0x32];
    /* 0x174 */ u8 str174[0x32];
    /* 0x1A6 */ u8 str1A6[0x32];
    /* 0x1D8 */ u8 str1D8[0x32];
} O3Pk;

typedef struct O3Tbl { s32 key; s32 *val; } O3Tbl;


/* texture header (width/height/data) used by the byte swapper */
typedef struct O3Tex {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s16 w;
    /* 0x0A */ s16 h;
    /* 0x0C */ u8 padC[0xC];
    /* 0x18 */ u32 *data;
} O3Tex;


/* player/slot record (3 entries of 0x1C bytes at D_80153F80) */
typedef struct O3Plr {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 type;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ u8 name[0xC];
} O3Plr;



/* row of 0x70 bytes at D_800E3A50 */
typedef struct O3V3i { s32 x, y, z; } O3V3i;

typedef struct O3Row {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ f32 fC[4];
    /* 0x1C */ f32 f1C[4];
    /* 0x2C */ O3V3i v2C[4];
    /* 0x5C */ s32 f5C[4];
    /* 0x6C */ s32 pad6C;
} O3Row;

/* generic gfx item (alpha / two words) */
typedef struct O3Obj {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 alpha;
    /* 0x11 */ u8 pad11[0x1B];
    /* 0x2C */ s32 f2C;
    /* 0x30 */ u8 pad30[8];
    /* 0x38 */ void *f38;
} O3Obj;

typedef struct O3P2 { s32 a; s32 b; } O3P2;

/* character table entry (rows of 17 entries at D_800E381C) */
typedef struct O3Chr {
    s32 ch;
    char **s;
} O3Chr;


/* player select page (global D_800E39C0, size 0x20) */
typedef struct O3Ps {
    /* 0x00 */ s32 parent;
    /* 0x04 */ s32 menu;
    /* 0x08 */ s32 w[3];
    /* 0x14 */ s32 sel;
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 cnt;
} O3Ps;


/* 4-player join page (global D_800E42D0): array of 0x4C8-byte records */
typedef struct O3Pj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 menu;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 state;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ u8 sub[0x4A8];
} O3Pj;


typedef struct O3Spr {
    /* 0x00 */ u8 pad0[0x16];
    /* 0x16 */ s16 f16;
    /* 0x18 */ s16 f18;
    /* 0x1A */ s16 f1A;
} O3Spr;

/* page at global D_800E4400 */
typedef struct O3Pm {
    /* 0x00 */ O3B60 *bar;
    /* 0x04 */ s32 f4;
    /* 0x08 */ O3Hdr *w8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ O3Spr *item;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ s32 timer;
    /* 0x30 */ s32 f30;
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
} O3Pm;


typedef struct O3Words { s32 w[0x30]; } O3Words;

/* entries of 0x96 bytes at D_80146398 */
typedef struct O3Pl4 {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ u8 f78;
    /* 0x79 */ u8 pad79[6];
    /* 0x7F */ u8 f7F;
    /* 0x80 */ u8 f80;
    /* 0x81 */ u8 f81;
    /* 0x82 */ u8 pad82[2];
    /* 0x84 */ u8 name[0xD];
    /* 0x91 */ u8 f91;
    /* 0x92 */ u8 f92;
    /* 0x93 */ u8 f93;
    /* 0x94 */ u8 pad94[2];
} O3Pl4;

/* config block at D_801462C8: header, 8 records of 0x96 bytes at +0xD0, then more */
typedef struct O3Cfg {
    /* 0x000 */ u32 flags;
    /* 0x004 */ u8 pad4[9];
    /* 0x00D */ u8 f0D;
    /* 0x00E */ u8 pad0E[2];
    /* 0x010 */ s32 f10;
    /* 0x014 */ u8 pad14[7];
    /* 0x01B */ u8 f1B;
    /* 0x01C */ u8 pad1C[3];
    /* 0x01F */ u8 f1F;
    /* 0x020 */ u8 pad20[0xB0];
    /* 0x0D0 */ O3Pl4 pl[8];
    /* 0x580 */ u8 f580;
} O3Cfg;


/* save slot record (0x190 bytes at D_80102B00) */
typedef struct O3Rec {
    /* 0x000 */ u8 pad0[0x17];
    /* 0x017 */ u8 f17;
    /* 0x018 */ u8 pad18[0x6C - 0x18];
    /* 0x06C */ s32 f6C;
    /* 0x070 */ s32 f70;
    /* 0x074 */ s32 f74;
    /* 0x078 */ u8 pad78[0x190 - 0x78];
} O3Rec;


typedef struct O3Blk6 { s32 w[6]; } O3Blk6;
typedef struct O3Blk98 { s32 w[0x62]; } O3Blk98;

/* embedded body of the actor-like object (at actor + 0x190) */
typedef struct O3Body {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ O3Vec3 pos;
    /* 0x014 */ u8 pad14[0x6C - 0x14];
    /* 0x06C */ f32 f6C;
    /* 0x070 */ u8 pad70[0x10E - 0x70];
    /* 0x10E */ s8 f10E;
    /* 0x10F */ u8 pad10F[0x140 - 0x10F];
    /* 0x140 */ O3Blk6 c140;
    /* 0x158 */ O3Blk6 c158;
    /* 0x170 */ u8 pad170[0x1C4 - 0x170];
    /* 0x1C4 */ O3Vec3 p1C4;
} O3Body;

/* actor-like object used by the overlay (partial) */
typedef struct O3Act {
    /* 0x000 */ u8 pad0[0x190];
    /* 0x190 */ u8 padBody[8];
    /* 0x198 */ O3Vec3 pos198;
    /* 0x1A4 */ u8 pad1A4[0x204 - 0x1A4];
    /* 0x204 */ u8 mtx204[0x150];
    /* 0x354 */ O3Vec3 pos354;
    /* 0x360 */ u8 pad360[0x478 - 0x360];
    /* 0x478 */ s32 f478;
    /* 0x47C */ u8 pad47C[4];
    /* 0x480 */ O3Vec3 v480;
    /* 0x48C */ O3Vec3 v48C;
    /* 0x498 */ f32 f498;
    /* 0x49C */ s32 f49C;
    /* 0x4A0 */ s32 f4A0;
} O3Act;


/* 4-player join page text-id table: rows of 9 {pad, id} pairs at D_800E42D4 */
typedef struct O3Id { u16 pad; s16 id; } O3Id;
typedef struct O3IdRow { O3Id e[9]; } O3IdRow;


/* fade/timer object (421ECC): timer, done flag, direction, target item */
typedef struct O3Fd {
    s32 timer;
    s32 done;
    s32 dir;
    O3Hdr *item;
} O3Fd;

typedef struct O3Cam {
    /* 0x000 */ u8 pad0[0x6C];
    /* 0x06C */ f32 f6C;
    /* 0x070 */ f32 f70;
    /* 0x074 */ u8 pad74[0x29C - 0x74];
    /* 0x29C */ f32 f29C;
    /* 0x2A0 */ f32 f2A0;
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
} O3Cam;

typedef struct O3Gl {
    /* 0x00 */ O3Cam *p;
    /* 0x04 */ u8 pad4[0x88];
    /* 0x8C */ f32 f8C;
    /* 0x90 */ f32 f90;
} O3Gl;

typedef struct O3Scr {
    /* 0x000 */ u8 pad0[0x108];
    /* 0x108 */ s32 w108;
    /* 0x10C */ s32 w10C;
    /* 0x110 */ s32 w110;
    /* 0x114 */ s32 w114;
} O3Scr;


/* table of text pointers at D_800D749C (accessed as one aggregate) */
typedef struct O3Strs {
    char *s00;  /* 749C */
    char *s04;  /* 74A0 */
    char *s08;  /* 74A4 */
    char *s0C;  /* 74A8 */
    char *s10;  /* 74AC */
    char *s14;  /* 74B0 */
    char *s18;  /* 74B4 */
    char *s1C;  /* 74B8 */
    char *s20;  /* 74BC */
} O3Strs;


/* render-state helpers: in the original these are `inline` functions (the standalone copies are func_00419074/144/224);
   an inlined copy compiles to non-base D_80110634 accesses, the out-of-line body to base-register ones. */
extern s32 D_800E32C4;
extern s32 D_800E32D0;
extern s32 D_800E32E4;
extern s32 D_80153F68;
extern O3Dl *D_80110634;

static inline void O3_Sync(void) {
    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        O3_PUSH(0xE7000000, 0);
    }
}

static inline void O3_SetModeA(s32 mode) {
    if (mode != D_800E32C4) {
        D_800E32C4 = mode;
        O3_Sync();
        if (mode == 6) {
            O3_PUSH(0xE3000C00, 0x80000);
        } else if (mode == 7) {
            O3_PUSH(0xE3000C00, 0);
        }
    }
}

static inline void O3_SetModeB(s32 mode) {
    if (D_80153F68 == 0) {
        mode = 0xE;
    }
    if (mode != D_800E32D0) {
        D_800E32D0 = mode;
        O3_Sync();
        if (mode == 0xD) {
            O3_PUSH(0xD7000002, 0x80008000);
        } else if (mode == 0xE) {
            O3_PUSH(0xD7000000, 0x80008000);
        }
    }
}




/* sprite-ish item with u16 scroll offsets (join page) */
typedef struct O3Sp2 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 alpha;
    /* 0x11 */ u8 pad11[3];
    /* 0x14 */ u16 f14;
    /* 0x16 */ u16 f16;
    /* 0x18 */ s16 f18;
} O3Sp2;

/* view of the last record of the join page (D_800E42D0[4]) */
typedef struct O3PjT {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ O3Sp2 *f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ O3Sp2 *f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ O3Hdr *f24;
    /* 0x28 */ O3Hdr *f28;
    /* 0x2C */ s32 f2C;
    /* 0x30 */ s32 f30;
    /* 0x34 */ s32 f34;
} O3PjT;

#endif
