#ifndef P2_TYPES_H
#define P2_TYPES_H

#include "common.h"

/* Types recovered for Turok: Rage Wars game code (pilot batch 2).  Offsets are from the asm; padding is explicit. */

typedef struct { f32 x, y, z; } P2Vec3;

typedef struct DNode DNode;
typedef struct DList DList;
typedef struct PNode PNode;
typedef struct List List;
typedef struct MemBlk MemBlk;
typedef struct Game Game;
typedef struct Pawn Pawn;
typedef struct PlayerDef PlayerDef;
typedef struct WeaponInfo WeaponInfo;
typedef struct EvtSrc EvtSrc;
typedef struct PlayerEvt PlayerEvt;
typedef struct PlayerCtl PlayerCtl;
typedef struct P2Obj P2Obj;
typedef struct ObjDef ObjDef;
typedef struct ActorInfo ActorInfo;
typedef struct P2Seg P2Seg;
typedef struct P2Mtx P2Mtx;
typedef struct ActorCmd ActorCmd;
typedef struct Actor Actor;
typedef struct Obj74 Obj74;
typedef struct Ctx256 Ctx256;
typedef struct Player Player;
typedef struct PoolMgr PoolMgr;
typedef struct WeaponReq WeaponReq;
typedef struct WeaponInfo2 WeaponInfo2;
typedef struct Obj2F0 Obj2F0;
typedef struct SlotCnt SlotCnt;
typedef struct BlkNode BlkNode;
typedef struct BlkStats BlkStats;
typedef struct Obj0C Obj0C;
typedef struct AllocHdr AllocHdr;
typedef struct AllocMsg AllocMsg;

struct DNode {
    /* 0x0 */ DNode* next;
    /* 0x4 */ DNode* prev;
};

struct DList {
    /* 0x0 */ DNode* head;
    /* 0x4 */ DNode* tail;
};

struct PNode {
    /* 0x0 */ u32 key;
    /* 0x4 */ u8 pad_4[0x4];
    /* 0x8 */ s32 f8;
    /* 0xC */ u32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ u8 pad_18[0x8];
    /* 0x20 */ PNode* prev;
    /* 0x24 */ PNode* next;
};

struct List {
    /* 0x0 */ PNode* head;
    /* 0x4 */ PNode* tail;
    /* 0x8 */ u8 pad_8[0xC];
};

struct MemBlk {
    /* 0x0 */ void* data;
};

struct Game {
    /* 0x0 */ u8 pad_0[0x20];
    /* 0x20 */ Player* players;
};

struct Pawn {
    /* 0x0 */ u8 pad_0[0x564];
    /* 0x564 */ s32 f564;
};

struct PlayerDef {
    /* 0x0 */ u8 pad_0[0x90];
    /* 0x90 */ u8 f90;
};

struct WeaponInfo {
    /* 0x0 */ u8 pad_0[0x18];
    /* 0x18 */ f32 f18;
};

struct EvtSrc {
    /* 0x0 */ u8 pad_0[0x294];
    /* 0x294 */ s32 f294;
    /* 0x298 */ u8 pad_298[0x4];
    /* 0x29C */ f32 f29C;
    /* 0x2A0 */ f32 f2A0;
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
};

struct PlayerEvt {
    /* 0x0 */ u8 pad_0[0x4];
    /* 0x4 */ s32 f4;
    /* 0x8 */ EvtSrc* f8;
    /* 0xC */ u8 pad_C[0xBF];
    /* 0xCB */ s8 fCB;
    /* 0xCC */ u8 pad_CC[0x64];
    /* 0x130 */ f32 f130;
    /* 0x134 */ u8 pad_134[0x8];
    /* 0x13C */ s32 f13C;
};

struct PlayerCtl {
    /* 0x0 */ u8 pad_0[0x1D8];
    /* 0x1D8 */ Player* player;
};

struct P2Obj {
    /* 0x0 */ u8 pad_0[0x8];
    /* 0x8 */ f32 f8;
    /* 0xC */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ f32 f18;
};

struct ObjDef {
    /* 0x0 */ u8 kind;
    /* 0x1 */ u8 pad_1[0xB];
    /* 0xC */ f32 fC;
    /* 0x10 */ u8 pad_10[0x10];
    /* 0x20 */ f32 f20;
    /* 0x24 */ u8 pad_24[0x14];
    /* 0x38 */ u32 f38;
    /* 0x3C */ u8 pad_3C[0x4];
    /* 0x40 */ f32 f40;
};

struct ActorInfo {
    /* 0x0 */ s32 kind;
    /* 0x4 */ u8 pad_4[0x48];
    /* 0x4C */ u32 f4C;
};

struct P2Seg {
    /* 0x0 */ s32 w[6];
};

struct P2Mtx {
    /* 0x0 */ f32 m[16];
};

struct ActorCmd {
    /* 0x0 */ s32 f0;
    /* 0x4 */ s32 f4;
    /* 0x8 */ u8 pad_8[0x4];
    /* 0xC */ void* fC;
};

struct Actor {
    /* 0x0 */ u8 pad_0[0x1];
    /* 0x1 */ s8 f1;
    /* 0x2 */ u8 pad_2[0x1];
    /* 0x3 */ s8 f3;
    /* 0x4 */ u8 pad_4[0x4];
    /* 0x8 */ P2Vec3 pos;
    /* 0x14 */ u8 pad_14[0x4];
    /* 0x18 */ ActorInfo* info;
    /* 0x1C */ u8 pad_1C[0x4C];
    /* 0x68 */ P2Mtx mtx[1];
    /* 0xA8 */ u8 pad_A8[0xC];
    /* 0xB4 */ s32 fB4;
    /* 0xB8 */ u8 pad_B8[0x88];
    /* 0x140 */ P2Seg seg[2];
    /* 0x170 */ u8 pad_170[0x4];
    /* 0x174 */ s32 f174;
    /* 0x178 */ u8 pad_178[0x4];
    /* 0x17C */ u32 f17C;
    /* 0x180 */ u8 pad_180[0x14];
    /* 0x194 */ f32 f194;
    /* 0x198 */ f32 f198;
};

struct Obj74 {
    /* 0x0 */ u8 pad_0[0x74];
    /* 0x74 */ u32 f74;
};

struct Ctx256 {
    /* 0x0 */ u8 inited;
    /* 0x1 */ u8 pad_1[0x3];
    /* 0x4 */ s32 f4;
    /* 0x8 */ void* f8;
};

struct Player {
    /* 0x0 */ u8 pad_0[0x8];
    /* 0x8 */ P2Vec3 pos;
    /* 0x14 */ u8 pad_14[0x15C];
    /* 0x170 */ f32 f170;
    /* 0x174 */ u8* f174;
    /* 0x178 */ u8 pad_178[0x458];
    /* 0x5D0 */ s32 f5D0;
    /* 0x5D4 */ u8 pad_5D4[0x4];
    /* 0x5D8 */ PlayerDef* def;
    /* 0x5DC */ Pawn* pawn;
    /* 0x5E0 */ u8 pad_5E0[0x14];
    /* 0x5F4 */ s16 s5F4[12];
    /* 0x60C */ u8 pad_60C[0x22];
    /* 0x62E */ s16 weapon;
    /* 0x630 */ u8 pad_630[0x20];
    /* 0x650 */ s16 state;
    /* 0x652 */ u8 pad_652[0x6];
    /* 0x658 */ f32 f658;
    /* 0x65C */ u8 pad_65C[0x8];
    /* 0x664 */ u32 f664;
    /* 0x668 */ u8 pad_668[0xB8];
    /* 0x720 */ f32 f720;
    /* 0x724 */ u8 pad_724[0x8];
    /* 0x72C */ f32 f72C;
    /* 0x730 */ u8 pad_730[0x8C];
    /* 0x7BC */ f32 f7BC;
    /* 0x7C0 */ u8 pad_7C0[0x90];
    /* 0x850 */ s32 f850;
    /* 0x854 */ u8 pad_854[0x18];
    /* 0x86C */ s32 f86C;
    /* 0x870 */ u8 pad_870[0x30];
    /* 0x8A0 */ List listA;
    /* 0x8B4 */ List listB;
    /* 0x8C8 */ u8 pad_8C8[0x650];
    /* 0xF18 */ MemBlk* f_F18;
    /* 0xF1C */ void* f_F1C;
    /* 0xF20 */ s32 f_F20;
    /* 0xF24 */ u8 pad_F24[0x29C];
    /* 0x11C0 */ s32 f11C0;
    /* 0x11C4 */ u8 pad_11C4[0x18];
    /* 0x11DC */ f32 f11DC;
    /* 0x11E0 */ u8 pad_11E0[0x1C];
    /* 0x11FC */ f32 f11FC;
    /* 0x1200 */ u8 pad_1200[0x2C];
    /* 0x122C */ u32 f122C;
    /* 0x1230 */ u8 pad_1230[0x90];
    /* 0x12C0 */ f32 f12C0;
    /* 0x12C4 */ u8 pad_12C4[0x41C];
    /* 0x16E0 */ Player* next;
};

struct PoolMgr {
    /* 0x0 */ u8 pad_0[0x600];
    /* 0x600 */ u8 list[0xBCC];
    /* 0x11CC */ s32 cnt;
    /* 0x11D0 */ u8 pad_11D0[0x40];
    /* 0x1210 */ s32 f10;
};

struct WeaponReq {
    /* 0x0 */ s16 idx;
    /* 0x2 */ u8 pad_2[0x4];
    /* 0x6 */ s16 min;
};

struct WeaponInfo2 {
    /* 0x0 */ u8 pad_0[0x20];
    /* 0x20 */ WeaponReq* req;
};

struct Obj2F0 {
    /* 0x0 */ u8 pad_0[0x2F0];
    /* 0x2F0 */ u8 f2F0;
};

struct SlotCnt {
    /* 0x0 */ u32 cnt;
    /* 0x4 */ u8 pad_4[0xC];
};

struct BlkNode {
    /* 0x0 */ BlkNode* next;
    /* 0x4 */ u8 pad_4[0x2];
    /* 0x6 */ u16 pages;
};

struct BlkStats {
    /* 0x0 */ u32 max;
    /* 0x4 */ u32 min;
    /* 0x8 */ s32 f8;
    /* 0xC */ u32 total;
};

struct Obj0C {
    /* 0x0 */ u8 pad_0[0xC];
    /* 0xC */ s32 fC;
};

struct AllocHdr {
    /* 0x0 */ u8 pad_0[0x8];
    /* 0x8 */ s32 f8;
    /* 0xC */ MemBlk* blk;
};

struct AllocMsg {
    /* 0x0 */ s16 type;
    /* 0x2 */ u8 pad_2[0x2];
    /* 0x4 */ u32 size;
    /* 0x8 */ AllocHdr* hdr;
    /* 0xC */ OSMesgQueue* mq;
};

#endif
