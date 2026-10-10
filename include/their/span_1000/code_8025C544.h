#ifndef UNBAKE_SPAN_1000_CODE_8025C544_H
#define UNBAKE_SPAN_1000_CODE_8025C544_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct SongHeader;
/* unbake published declaration: published_043b96e141a6be98c4d04ef2 */
struct SongHeader {
    u32 tempo;
    u16 volume;
};

struct func_8025CA44_S2;
/* unbake published declaration: published_0b3c9bc1d133c9741d0701b4 */
struct func_8025CA44_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
};

struct func_8025C97C_S2;
/* unbake published declaration: published_0c55a06f278930053ec8225e */
struct func_8025C97C_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    Triple unk10;
    char pad10[0x1C - 0x10 - sizeof(Triple)];
    void * unk1C;
};

struct func_8025D370_S3;
/* unbake published declaration: published_0f098be0e3f8122abfc581bf */
typedef struct func_8025D370_S3 func_8025D370_S3;

/* unbake published declaration: published_1cd34209cc605a8192723a05 */
extern void func_8025D1BC_de(void *arg0);

/* unbake published declaration: published_21cb8ef550f572db10565d2f */
extern void func_8025D350_de(void *arg0, s32 arg1);

struct func_8025C67C_S1;
/* unbake published declaration: published_2294611a6d8d1ccb3a4650aa */
struct func_8025C67C_S1 {
    int unk0;
    char pad0[0x8 - 0x0 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x38 - 0xC - sizeof(int)];
    short unk38;
    char pad38[0x3A - 0x38 - sizeof(short)];
    short unk3A;
    char pad3A[0xA8 - 0x3A - sizeof(short)];
    int unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(int)];
    void * unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(void*)];
    int unkB4;
};

/* unbake published declaration: published_26058ee35c2ae670f0e181e1 */
extern float D_800C3FB0_de;

/* unbake published declaration: published_29f406e3a585884323f5a626 */
extern int D_800CBB18;

struct SlotArray;
/* unbake published declaration: published_2e33b97fd91385d076914547 */
struct SlotArray {
    char pad0[0x60];
    short slot[1];
};

struct IntegerStateB4_2;
/* unbake published declaration: published_2f6de60b677e16e764191fd3 */
typedef struct IntegerStateB4_2 IntegerStateB4_2;

struct Node_func_8025CBEC_de;
/* unbake published declaration: published_5ff6da2ee41d3e5f81a452eb */
struct Node_func_8025CBEC_de {
    s32 unk0;
    struct Node_func_8025CBEC_de *next;
    s32 value;
    s32 state;
};

struct Node_func_8025CBEC_de;
union func_8025CC0C_S1_U14;
/* unbake published declaration: published_375958f34a6d76c55f28c283 */
union func_8025CC0C_S1_U14 {
    struct Node_func_8025CBEC_de * v0;
    char v1;
};

/* unbake published declaration: published_3db178aaa26e5ff0732a8621 */
extern float D_800C3FC0_de;

struct func_8025CBA8_S2;
/* unbake published declaration: published_40655d3c28b4c28f5f77b93c */
struct func_8025CBA8_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
};

struct func_8025D1DC_S1;
/* unbake published declaration: published_4216d9b2f6bfa4369c60735b */
typedef struct func_8025D1DC_S1 func_8025D1DC_S1;

/* unbake published declaration: published_455a5a1fdee66ad996971551 */
extern void func_8025CC7C_de(void);

struct func_8025CBA8_S2;
/* unbake published declaration: published_4848706a70924b68f7dc510d */
typedef struct func_8025CBA8_S2 func_8025CBA8_S2;

struct Track;
/* unbake published declaration: published_4ac0debb65f043532342cd46 */
typedef struct Track Track;

struct SlotArray;
/* unbake published declaration: published_5153c02625d8ac64a0b67958 */
typedef struct SlotArray SlotArray;

struct IntegerStateB4_2;
/* unbake published declaration: published_5159f633513673814f32f0c3 */
struct IntegerStateB4_2 {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x10 - 0x4 - sizeof(s32)];
    s32 unk_10;
    char pad10[0x50 - 0x10 - sizeof(s32)];
    s32 unk_50;
    char pad50[0xAC - 0x50 - sizeof(s32)];
    s32 unk_AC;
    char padAC[0xB0 - 0xAC - sizeof(s32)];
    s32 unk_B0;
};

/* unbake published declaration: published_53f943a5550c7e483c81fd25 */
extern void func_8025C8D0_de(void);

/* unbake published declaration: published_5bc6f7ca73760168c0f311d9 */
extern int D_800CBB14;

struct func_8025C67C_S2;
/* unbake published declaration: published_60b5c31801ded0f34df3656b */
typedef struct func_8025C67C_S2 func_8025C67C_S2;

struct Resource;
/* unbake published declaration: published_62c13b3c4246695ba91bcc0a */
typedef struct Resource Resource;

struct func_8025D370_S2;
/* unbake published declaration: published_63549113d8053d49aa9df9dd */
typedef struct func_8025D370_S2 func_8025D370_S2;

struct Bank_func_8025CED0_de;
/* unbake published declaration: published_6e81fcbb155bc8a03bcec47d */
struct Bank_func_8025CED0_de {
    char pad0[0x2B60];
    s32 table;
    s32 count;
};

struct Bank_func_8025CED0_de;
struct Player_func_8025CED0_de;
/* unbake published declaration: published_6a113a57c2d3f81cd5d60688 */
struct Player_func_8025CED0_de {
    struct Bank_func_8025CED0_de *bank;
    s32 request;
    s32 state;
    s32 group;
    s32 song;
    s32 speed;
    s32 volume;
    char pad1C[2];
    s16 id;
};

union func_8025CC0C_S1_U14;
/* unbake published declaration: published_6a93a2066063e60609636d70 */
typedef union func_8025CC0C_S1_U14 func_8025CC0C_S1_U14;

struct func_8025D258_S1;
/* unbake published declaration: published_6bbe63732732c9debe1d6202 */
typedef struct func_8025D258_S1 func_8025D258_S1;

/* unbake published declaration: published_79e223fe6e4ac978cd4adcb8 */
extern double D_800C3FB8_de;

struct func_8025CAD0_S1;
/* unbake published declaration: published_7bb60f17c8b2c206a3f91b2c */
typedef struct func_8025CAD0_S1 func_8025CAD0_S1;

struct func_8025D258_S1;
/* unbake published declaration: published_7e4bc79fc2bb314cb0f36b18 */
struct func_8025D258_S1 {
    char pad0[0x2B60];
    s32 unk2B60;
    char pad2B60[0x2B64 - 0x2B60 - sizeof(s32)];
    s32 unk2B64;
};

struct ObjectStateB4;
/* unbake published declaration: published_7f2ebdbb49a0de5d45d186cc */
struct ObjectStateB4 {
    char unk_0;
    char pad0[0xB0 - 0x0 - sizeof(char)];
    s32 unk_B0;
};

/* unbake published declaration: published_8e0078d9fb456249962dd617 */
extern void func_8025C5DC_de(void *arg0);

struct Context_func_8025D450_de;
/* unbake published declaration: published_8eec83319086ce44788529a0 */
typedef struct Context_func_8025D450_de Context_func_8025D450_de;

struct func_8025CB2C_S2;
/* unbake published declaration: published_92e722883d928edf300f149e */
typedef struct func_8025CB2C_S2 func_8025CB2C_S2;

struct func_8025CB2C_S2;
/* unbake published declaration: published_94f9ffa8ed3e0c20a0442a31 */
struct func_8025CB2C_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    s32 unk8;
    char pad8[0xE - 0x8 - sizeof(s32)];
    s16 unkE;
    char padE[0x10 - 0xE - sizeof(s16)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
};

/* unbake published declaration: published_954f8215ca4cada474f79d0f */
extern void func_8025C5BC_de(void *arg0);

/* unbake published declaration: published_96d0b2680914270ef48f2b0a */
extern s32 func_8025D238_de(void **arg0, s16 id, s16 avoid);

struct SongHeader;
/* unbake published declaration: published_9942dd2a7fb6979add563e53 */
typedef struct SongHeader SongHeader;

struct Bank;
/* unbake published declaration: published_aaba00d4b3552bc3e978ea6c */
struct Bank {
    char pad0[0x2B50];
    void *songs;
};

struct Bank;
struct Player_func_8025CC90_de;
/* unbake published declaration: published_9aaf53ebe62ee0220d0710f9 */
struct Player_func_8025CC90_de {
    struct Bank *bank;
    char pad4[4];
    u32 state;
    s32 loop;
    s32 song;
    s32 speed;
    char pad18[3];
    u8 priority;
    char pad1C[2];
    s16 id;
    f32 tempoScale;
    f32 volume;
};

/* unbake published declaration: published_9f1533b6cdcb8264e18e983d */
extern int D_800CBB10;

struct Resource;
/* unbake published declaration: published_9ff52b62806a2f3b8a1eb8d4 */
struct Resource {
    s32 unk0;
    u16 unk4;
};

struct Player_func_8025CED0_de;
/* unbake published declaration: published_a0eea15b6830d70eb555b23b */
typedef struct Player_func_8025CED0_de Player_func_8025CED0_de;

struct Context_func_8025D450_de;
/* unbake published declaration: published_a42e1bbf52124571b37b8b50 */
struct Context_func_8025D450_de {
    char pad[0x2B50];
    s32 unk2B50;
    char p54[12];
    s32 unk2B60;
    s32 unk2B64;
    char p68[0x3C];
    f32 unk2BA4;
    char pa8[16];
    s32 unk2BB8;
};

struct Queue_func_8025CC90_de;
/* unbake published declaration: published_a4d5f9de64bac6976e4643b2 */
typedef struct Queue_func_8025CC90_de Queue_func_8025CC90_de;

/* unbake published declaration: published_aaa8554eb9b77f80bc201d0f */
extern void func_8025C8C0_de(void *arg0);

struct Node_func_8025CBEC_de;
/* unbake published declaration: published_ad9ee52aa2eb7717b605f0d5 */
typedef struct Node_func_8025CBEC_de Node_func_8025CBEC_de;

struct Queue_func_8025CC90_de;
/* unbake published declaration: published_af61f48cc060dc5745224e91 */
struct Queue_func_8025CC90_de {
    void *sequence;
    s32 head;
    u8 kind;
    s32 tail;
};

struct Bank_func_8025CED0_de;
/* unbake published declaration: published_af9042877bca02269c46b57e */
typedef struct Bank_func_8025CED0_de Bank_func_8025CED0_de;

struct func_8025D370_S2;
/* unbake published declaration: published_b07eeaa3451c375c69791f56 */
struct func_8025D370_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    u16 unk4;
};

struct func_8025C67C_S2;
/* unbake published declaration: published_b74dffc0c2efe398424567e6 */
struct func_8025C67C_S2 {
    char pad0[0x7C];
    char unk7C;
    char pad7C[0x84 - 0x7C - sizeof(char)];
    char unk84;
};

/* unbake published declaration: published_bc06b5f597f5abbf273e9dbc */
extern void func_8025C578_de(void *arg0);

/* unbake published declaration: published_ca2e553d4c531694bce11763 */
extern int D_800CBB1C;

struct Context_func_8025D450_de;
struct Shape_func_802764D4_de_2;
struct Track;
/* unbake published declaration: published_ce5e9d1e3d51090faf6e6d32 */
struct Track {
    struct Context_func_8025D450_de *unk0;
    s32 unk4;
    struct Shape_func_802764D4_de_2 *unk8;
    void *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s32 unk38;
    f32 unk3C;
};

struct func_8025D1DC_S1;
/* unbake published declaration: published_d8fbcf37015da8d93a0a684c */
struct func_8025D1DC_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x1E - 0x8 - sizeof(s32)];
    s16 unk1E;
};

struct func_8025CC0C_S1;
/* unbake published declaration: published_db96bafe9e4131b8fdb09064 */
typedef struct func_8025CC0C_S1 func_8025CC0C_S1;

struct func_8025C97C_S2;
/* unbake published declaration: published_e0b7cb0feafc3f9763f4af0e */
typedef struct func_8025C97C_S2 func_8025C97C_S2;

struct ObjectStateB4;
/* unbake published declaration: published_e184f00d4e237329b5778843 */
typedef struct ObjectStateB4 ObjectStateB4;

struct func_8025CC0C_S1;
/* unbake published declaration: published_e3fb2044f6695062fe0e3981 */
struct func_8025CC0C_S1 {
    char pad0[0x14];
    func_8025CC0C_S1_U14 unk14;
};

/* unbake published declaration: published_eb696884e840b62470e0a1e7 */
extern void func_8025D3E4_de(void *arg0);

struct func_8025CA44_S2;
/* unbake published declaration: published_ed7340fad73bf47d5944844b */
typedef struct func_8025CA44_S2 func_8025CA44_S2;

/* unbake published declaration: published_f1f473c87992775714b582b7 */
extern void func_8025C524_de(void *arg0, s32 arg1);

struct func_8025D370_S3;
/* unbake published declaration: published_f23b1a650e5cfa5617600702 */
struct func_8025D370_S3 {
    char pad0[0x20];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
};

struct Bank;
/* unbake published declaration: published_f49a263611f026703e5639fd */
typedef struct Bank Bank;

struct Player_func_8025CC90_de;
/* unbake published declaration: published_f578a89afcd2d7d8ee2207ae */
typedef struct Player_func_8025CC90_de Player_func_8025CC90_de;

/* unbake published declaration: published_fc3277cce195d28142a3d4be */
extern void func_8025C65C_de(void *arg0);

struct func_8025C67C_S1;
/* unbake published declaration: published_fcd1e4161c8cbb7dce0a0c53 */
typedef struct func_8025C67C_S1 func_8025C67C_S1;

struct func_8025CAD0_S1;
/* unbake published declaration: published_fe29fb9c3df37d6187d0efb0 */
struct func_8025CAD0_S1 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x28 - 0x14 - sizeof(void*)];
    s32 unk28;
};

#endif
