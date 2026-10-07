#ifndef R06_TYPES_H
#define R06_TYPES_H
#include "common.h"

typedef struct R06Vec3 { f32 x, y, z; } R06Vec3;

/* sorted draw-bucket node (0x20 bytes): BST via l/r plus a doubly linked order list via nxt/prv */
typedef struct R06Sub {
    /* 0x00 */ void *data;
    /* 0x04 */ s32 a, b, c;
    /* 0x10 */ u16 h10, h12;
    /* 0x14 */ s32 w14;
    /* 0x18 */ s32 pad18;
    /* 0x1C */ struct R06Sub *next;
} R06Sub;

typedef struct R06Node {
    /* 0x00 */ u32 key;
    /* 0x04 */ void *rec;
    /* 0x08 */ R06Sub *head;
    /* 0x0C */ R06Sub *tail;
    /* 0x10 */ struct R06Node *nxt;
    /* 0x14 */ struct R06Node *prv;
    /* 0x18 */ struct R06Node *l;
    /* 0x1C */ struct R06Node *r;
} R06Node;

typedef struct R06Rec {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u16 id;
    /* 0x06 */ u8 pad6[0x11];
    /* 0x17 */ u8 b17;
    /* 0x18 */ u16 h18;
    /* 0x1A */ u16 h1A;
} R06Rec;

typedef struct R06Src { s32 a, b, c, d; } R06Src;
typedef struct R06Dl { u32 w0, w1; } R06Dl;

/* player-like object used by the model draw code (only the words touched) */
typedef struct R06PBlk {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s8 kind;
    /* 0x81 */ s8 sub;
    /* 0x82 */ u8 pad82[0xD];
    /* 0x8F */ u8 b8F;
    /* 0x90 */ u8 pad90[4];
    /* 0x94 */ u8 b94;
} R06PBlk;

typedef struct R06Player {
    /* 0x000 */ u8 pad0[0x5D8];
    /* 0x5D8 */ R06PBlk *blk;
    /* 0x5DC */ u8 pad5DC[0xC10];
    /* 0x11EC */ f32 f11EC;
    /* 0x11F0 */ u8 pad11F0[0x3C];
    /* 0x122C */ u32 flags122C;
} R06Player;

typedef struct R06G468A0 {
    /* 0x00 */ u8 pad0[0x98];
    /* 0x98 */ s32 w98;
    /* 0x9C */ s32 w9C;
    /* 0xA0 */ s32 wA0;
} R06G468A0;

/* world table at D_8011FE88: entry count at +0x1500, entries 0xC apart from +0x1508 (first word = handle pointer) */
typedef struct R06WEnt { u8 pad0[8]; s32 **h; } R06WEnt;
typedef struct R06WTab { u8 pad0[0x1500]; s32 n; s32 pad1504; s32 pad1508; } R06WTab;
typedef struct R06V3 { f32 x, y, z; } R06V3;
typedef struct R06Vtx { u8 pad0[0xC]; u8 col[4]; } R06Vtx;
typedef struct R06VBlk { u32 pad0; s32 count; R06Vtx v[1]; } R06VBlk;
#endif
