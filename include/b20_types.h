#ifndef B20_TYPES_H
#define B20_TYPES_H

#include "p1_types.h"

typedef struct Ent12 { s32 **tblp; s32 b; s32 c; } Ent12;
typedef struct DefC { u8 pad0[0xC]; s16 unkC; } DefC;
typedef struct Qn Qn;
struct Qn { Qn *next; OSMesgQueue *q; };
typedef struct Obj2 { u8 pad0[8]; void *unk8; f32 unkC; } Obj2;
typedef struct Rec14 {
    /* 0x0000 */ u8 pad0[0xE];
    /* 0x000E */ u8 flags;
    /* 0x000F */ u8 key;
    /* 0x0010 */ u8 pad10[0x4];
} Rec14;

typedef struct Node {
    /* 0x0000 */ u8 pad0[0x1C8];
    /* 0x01C8 */ s32 unk1C8;
    /* 0x01CC */ u8 pad1CC[0x4];
    /* 0x01D0 */ u32 flags;
    /* 0x01D4 */ s32 *counter;
    /* 0x01D8 */ struct Node *prev;
    /* 0x01DC */ struct Node *next;
} Node;

typedef struct NodeOwner {
    /* 0x0000 */ u8 pad0[0x3C00];
    /* 0x3C00 */ Node *freeList;
    /* 0x3C04 */ Node *head;
    /* 0x3C08 */ Node *tail;
} NodeOwner;

typedef struct Job {
    /* 0x0000 */ struct Job *next;
    /* 0x0004 */ u32 flags4;
    /* 0x0008 */ u32 flags8;
    /* 0x000C */ void *unkC;
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ u8 pad14[0x24];
    /* 0x0038 */ s32 unk38;
    /* 0x003C */ u64 *unk3C;
} Job;

typedef struct Vid {
    /* 0x0000 */ s16 unk0;
    /* 0x0002 */ u8 pad2[0x1E];
    /* 0x0020 */ s16 unk20;
    /* 0x0022 */ u8 pad22[0x1E];
    /* 0x0040 */ OSMesgQueue q40;
    /* 0x0058 */ OSMesg buf58[8];
    /* 0x0078 */ OSMesgQueue q78;
    /* 0x0090 */ OSMesg buf90[8];
    /* 0x00B0 */ OSThread thread;
    /* 0x0260 */ u8 pad260[0x80];
    /* 0x02E0 */ Qn *unk2E0;
    /* 0x02E4 */ Job *head2E4;
    /* 0x02E8 */ Job *head2E8;
    /* 0x02EC */ Job *tail2EC;
    /* 0x02F0 */ Job *tail2F0;
    /* 0x02F4 */ Job *cur2F4;
    /* 0x02F8 */ Job *next2F8;
    /* 0x02FC */ s32 unk2FC;
    /* 0x0300 */ s32 unk300;
} Vid;

typedef struct Entity {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s16 unk4s;
    /* 0x0006 */ u8 pad6[0x2];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ ActorDef *def;
    /* 0x001C */ Vec3f vel;
    /* 0x0028 */ u8 pad28[0xBC];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x1A];
    /* 0x0100 */ u32 flags;
    /* 0x0104 */ u8 pad104[0x70];
    /* 0x0174 */ s32 unk174;
    /* 0x0178 */ u8 pad178[0x4];
    /* 0x017C */ f32 box[6];
    /* 0x0194 */ u8 pad194[0x8];
    /* 0x019C */ u32 flags19C;
    /* 0x01A0 */ u8 pad1A0[0x4];
    /* 0x01A4 */ s8 unk1A4;
    /* 0x01A5 */ u8 pad1A5[0x23];
    /* 0x01C8 */ f32 unk1C8;
    /* 0x01CC */ u8 pad1CC[0x72];
    /* 0x023E */ s8 unk23E;
    /* 0x023F */ u8 pad23F[0xA9];
} Entity;

typedef struct Level {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ u8 pad4[0x18];
    /* 0x001C */ s32 *unk1C;
    /* 0x0020 */ u8 *unk20;
    /* 0x0024 */ s32 *unk24;
    /* 0x0028 */ u8 *unk28;
    /* 0x002C */ u8 *unk2C;
    /* 0x0030 */ u8 pad30[0x10];
    /* 0x0040 */ u8 unk40;
    /* 0x0041 */ u8 pad41[0xB];
    /* 0x004C */ s32 *unk4C;
    /* 0x0050 */ s32 *unk50;
    /* 0x0054 */ s32 *unk54;
    /* 0x0058 */ s32 *unk58;
    /* 0x005C */ s32 *unk5C;
    /* 0x0060 */ u8 pad60[0xC];
    /* 0x006C */ s32 *unk6C;
    /* 0x0070 */ s32 *unk70;
    /* 0x0074 */ u8 pad74[0x4];
    /* 0x0078 */ s32 *unk78;
    /* 0x007C */ s32 *unk7C;
    /* 0x0080 */ s32 *unk80;
    /* 0x0084 */ s32 *unk84;
    /* 0x0088 */ u8 pad88[0xC];
    /* 0x0094 */ s32 *unk94;
    /* 0x0098 */ s32 *unk98;
    /* 0x009C */ s32 *unk9C;
    /* 0x00A0 */ s32 *unkA0;
    /* 0x00A4 */ s32 *unkA4;
    /* 0x00A8 */ s32 *unkA8;
    /* 0x00AC */ s32 *unkAC;
    /* 0x00B0 */ s32 *unkB0;
    /* 0x00B4 */ u8 padB4[0x84];
    /* 0x0138 */ Entity *entities;
    /* 0x013C */ u8 pad13C[0x4];
    /* 0x0140 */ s32 numEntities;
    /* 0x0144 */ Entity * arr144[512];
    /* 0x0944 */ s32 cnt944;
    /* 0x0948 */ Entity * arr948[128];
    /* 0x0B48 */ s32 cntB48;
    /* 0x0B4C */ s32 * arrB4C[64];
    /* 0x0C4C */ s32 cntC4C;
    /* 0x0C50 */ Actor * actors[128];
    /* 0x0E50 */ s32 numActors;
    /* 0x0E54 */ u8 * list4[64];
    /* 0x0F54 */ s32 cntF54;
    /* 0x0F58 */ u8 padF58[0x4];
    /* 0x0F5C */ Entity * arrF5C[32];
    /* 0x0FDC */ s32 cntFDC;
    /* 0x0FE0 */ Entity * arrFE0[16];
    /* 0x1020 */ s32 cnt1020;
    /* 0x1024 */ Entity * list3[32];
    /* 0x10A4 */ s32 cnt10A4;
    /* 0x10A8 */ Entity * arr10A8[4];
    /* 0x10B8 */ s32 cnt10B8;
    /* 0x10BC */ s32 cnt10BC;
    /* 0x10C0 */ Entity * arr10C0[64];
    /* 0x11C0 */ s32 cnt11C0;
    /* 0x11C4 */ s32 cnt11C4;
    /* 0x11C8 */ s32 unk11C8;
    /* 0x11CC */ s32 unk11CC;
    /* 0x11D0 */ Rec14 *recA;
    /* 0x11D4 */ Rec14 *recB;
    /* 0x11D8 */ s32 unk11D8;
    /* 0x11DC */ Obj2 *unk11DC;
    /* 0x11E0 */ u8 pad11E0[0xC];
    /* 0x11EC */ Obj2 *unk11EC;
    /* 0x11F0 */ u8 pad11F0[0x310];
    /* 0x1500 */ s32 cnt1500;
    /* 0x1504 */ s32 cnt1504;
    /* 0x1508 */ Ent12 ents[16];
    /* 0x15C8 */ u8 pad15C8[0x19D54];
    /* 0x1B31C */ f32 unk1B31C;
    /* 0x1B320 */ u8 pad1B320[0xEC];
    /* 0x1B40C */ s32 unk1B40C;
    /* 0x1B410 */ s32 unk1B410;
    /* 0x1B414 */ s32 unk1B414;
    /* 0x1B418 */ f32 unk1B418;
    /* 0x1B41C */ s32 unk1B41C;
    /* 0x1B420 */ u8 unk1B420[0x10];
    /* 0x1B430 */ s16 unk1B430;
    /* 0x1B432 */ u8 pad1B432[0x2];
    /* 0x1B434 */ s32 unk1B434;
    /* 0x1B438 */ s32 unk1B438;
    /* 0x1B43C */ u8 pad1B43C[0x10];
    /* 0x1B44C */ s32 unk1B44C;
    /* 0x1B450 */ u8 pad1B450[0x1D0];
    /* 0x1B620 */ Entity * list1[16];
    /* 0x1B660 */ s32 n1;
    /* 0x1B664 */ Entity * list2[16];
    /* 0x1B6A4 */ s32 n2;
    /* 0x1B6A8 */ u8 pad1B6A8[0xB6E4];
    /* 0x26D8C */ u8 unk26D8C;
    /* 0x26D8D */ u8 pad26D8D[0x23];
    /* 0x26DB0 */ f32 unk26DB0;
    /* 0x26DB4 */ s32 unk26DB4;
    /* 0x26DB8 */ u8 pad26DB8[0x10];
    /* 0x26DC8 */ s32 unk26DC8;
    /* 0x26DCC */ s32 unk26DCC;
    /* 0x26DD0 */ s32 unk26DD0;
    /* 0x26DD4 */ s32 unk26DD4;
} Level;

#endif
