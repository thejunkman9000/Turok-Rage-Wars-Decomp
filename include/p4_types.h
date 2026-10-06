#ifndef P4_TYPES_H
#define P4_TYPES_H
#include "common.h"

/* node of a doubly linked list embedded in game objects (offsets 0x1D0..0x1DC) */
typedef struct P4Node {
    /* 0x000 */ u8 pad0[0x1D0];
    /* 0x1D0 */ s32 flags;
    /* 0x1D4 */ s32 *counter;
    /* 0x1D8 */ struct P4Node *prev;
    /* 0x1DC */ struct P4Node *next;
} P4Node;

/* 64-entry table pointed to by D_8014D080: header of 0x1C bytes, then entries of 0x14 bytes */
typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
} P4SlotEnt;
typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ P4SlotEnt ent[64];
} P4SlotTbl;

/* RDP/F3D display list command, as in the N64 SDK gbi.h (two words) */
typedef union {
    struct { u32 w0; u32 w1; } words;
    u64 force_structure_alignment;
} P4Gfx;
#endif
