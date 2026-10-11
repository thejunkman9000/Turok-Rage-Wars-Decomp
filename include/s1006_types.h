#ifndef S1006_TYPES_H
#define S1006_TYPES_H
/* Types recovered by worker s1006 for the overlay A level-loader functions func_0044D024 / func_0044D408.
   They describe views of the large level/world object (about 0x1B450 bytes) that the whole module
   func_0044A100..func_0044EA24 works on; only the fields these two functions touch are named. */

/* 0x10-byte vertex of a loaded surface mesh (func_00275AC8 turns four packed ints into floats) */
typedef struct S6Vtx {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S6Vtx;

/* packed 0x14-byte face record of the mesh resource (upstream name: Packed) */
typedef struct S6Packed {
    u16 unk0;
    u16 unk2;
    u16 first[3];
    u16 second[3];
    s32 unk10;
} S6Packed;

/* decoded 0x20-byte face (upstream name: Header_func_80275AA4_de, filled by func_00275B14) */
typedef struct S6Face {
    s16 unk0;
    u16 flags;
    S6Vtx *vtx[3];
    struct S6Face *adj[3];
    s32 attr;
} S6Face;

/* header of the buffer built by func_0044D024: current section index + the offsets of the 5 sections */
typedef struct S6MeshHdr {
    s32 cur;
    s32 off[5];
} S6MeshHdr;

typedef struct S6V3 {
    f32 x;
    f32 y;
    f32 z;
} S6V3;

/* 0x14-byte spawn-point object returned by func_0044DE70 (upstream: Object_func_8044D220_de) */
typedef struct S6Obj {
    S6V3 pos;
    f32 ang;
    s16 kind;
    u16 unk12;
} S6Obj;

/* 0x28-byte actor placement record of the level resource */
typedef struct S6Rec {
    s32 unk0;
    S6V3 pos;
    char pad10[0x10];
    u16 unk20;
    u16 id;
    s16 angle;
    char pad26[2];
} S6Rec;

/* 0x2E8-byte actor */
typedef struct S6Actor {
    char pad0[8];
    S6V3 pos;
    char pad14[4];
    s32 *def;
    char pad1C[0x1D8 - 0x1C];
    struct S6Actor *nearest;
    char pad1DC[0x2E8 - 0x1DC];
} S6Actor;

/* 0x96-byte per-player configuration record (array D_80146398, member ent[] of the global block D_801462C8 at +0xD0) */
typedef struct S6Cfg {
    u8 pad0[0x80];
    s8 kind;
    u8 pad81[0x15];
} S6Cfg;

/* the level/world object, fields used by func_0044D024 / func_0044D408 */
typedef struct S6World {
    char pad0[0x84];
    void *tree;                          /* 0x84 resource tree (groups / bitmaps) */
    char pad88[0x138 - 0x88];
    S6Actor *actors;                     /* 0x138 */
    s32 nSpawned;                        /* 0x13C */
    s32 nActors;                         /* 0x140 */
    char pad144[0xF58 - 0x144];
    s32 unkF58;                          /* 0xF58 */
    char padF5C[0x1B2FC - 0xF5C];
    f32 minY;                            /* 0x1B2FC lowest vertex height seen so far */
    char pad1B300[0x1B40C - 0x1B300];
    s32 group;                           /* 0x1B40C current group index */
    char pad1B410[0x1B41C - 0x1B410];
    s32 ready;                           /* 0x1B41C */
    char cache[0x14];                    /* 0x1B420 filled by func_0044E038 */
    s32 key;                             /* 0x1B434 */
    char pad1B438[0x1B614 - 0x1B438];
    s32 unk1B614;
    s32 unk1B618;
    s32 unk1B61C;
} S6World;

#endif
