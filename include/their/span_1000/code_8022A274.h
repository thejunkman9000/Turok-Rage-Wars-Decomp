#ifndef UNBAKE_SPAN_1000_CODE_8022A274_H
#define UNBAKE_SPAN_1000_CODE_8022A274_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Loadout;
struct Loadout {
    char pad0[0x108];
    int capacity[1];
};
struct Loadout;
struct Player_func_8022ACB8_de;
/* unbake published declaration: published_059d5f6648278866f4d6a4c7 */
struct Player_func_8022ACB8_de {
    char pad0[0x18];
    struct Loadout *loadout;
    char pad1C[0x5D4 - 0x1C];
    int character;
    char pad5D8[0x1450 - 0x5D8];
    int isBot;
};

struct func_8022A94C_S1;
/* unbake published declaration: published_0936d00b096916eb666e3017 */
typedef struct func_8022A94C_S1 func_8022A94C_S1;

struct func_8022A67C_S1;
/* unbake published declaration: published_099136dd6a039ce25a71f9fd */
struct func_8022A67C_S1 {
    char pad0[0x20];
    SharedPlayer_func_8022A398_de * unk20;
};

struct Entry190;
/* unbake published declaration: published_0e216a6f1cf65c3faa66a3b8 */
struct Entry190 {
    s32 value;
    u8 pad[0x18C];
};

struct Shape_typemap_165;
struct func_8022A94C_S2;
/* unbake published declaration: published_161035619bf4011e3ac802b5 */
struct func_8022A94C_S2 {
    char pad0[0x2F0];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    s32 unk2FC;
    char pad2FC[0x344 - 0x2FC - sizeof(s32)];
    struct Shape_typemap_165 unk344;
    char pad344[0x354 - 0x344 - sizeof(struct Shape_typemap_165)];
    f32 unk354;
};

struct func_8022AAC4_S2;
/* unbake published declaration: published_183033b1ac737b9ef0458703 */
struct func_8022AAC4_S2 {
    char pad0[0x20];
    s16 * unk20;
    char pad20[0x24 - 0x20 - sizeof(s16*)];
    s16 * unk24;
};

struct func_8022A2FC_S2;
/* unbake published declaration: published_1cfe01918a61e27b3419e34d */
struct func_8022A2FC_S2 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x5DC - 0xE4 - sizeof(u16)];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

struct ObjectLinks1454_3;
/* unbake published declaration: published_1ec53ba82b331fdec926ab6f */
struct ObjectLinks1454_3 {
    char pad0[0x18];
    void * unk_18;
    char pad18[0x5D4 - 0x18 - sizeof(void*)];
    s32 unk_5D4;
    char pad5D4[0x5D8 - 0x5D4 - sizeof(s32)];
    char * unk_5D8;
    char pad5D8[0x1450 - 0x5D8 - sizeof(char*)];
    s32 unk_1450;
};

struct func_8022A738_S1;
/* unbake published declaration: published_1fc500ad62720b5a57731ff0 */
typedef struct func_8022A738_S1 func_8022A738_S1;

struct Entry190;
/* unbake published declaration: published_2750a7892258323bd850d395 */
typedef struct Entry190 Entry190;

struct Shape_typemap_165;
struct func_8022A94C_S1;
/* unbake published declaration: published_225f115ab82a31f6e3965ea8 */
struct func_8022A94C_S1 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    s32 unk14;
    char pad14[0x5C - 0x14 - sizeof(s32)];
    struct Shape_typemap_165 unk5C;
    char pad5C[0x6C - 0x5C - sizeof(struct Shape_typemap_165)];
    f32 unk6C;
    char pad6C[0x10E - 0x6C - sizeof(f32)];
    u8 unk10E;
    char pad10E[0x2E8 - 0x10E - sizeof(u8)];
    Block unk2E8;
    char pad2E8[0x86C - 0x2E8 - sizeof(Block)];
    s32 unk86C;
    char pad86C[0x11D8 - 0x86C - sizeof(s32)];
    f32 unk11D8;
};

struct ObjectLinks16E4_4;
/* unbake published declaration: published_28e11d6d389ce61167da19df */
typedef struct ObjectLinks16E4_4 ObjectLinks16E4_4;

struct Shared_func_8022AA34_View;
/* unbake published declaration: published_51dfbaef70ee8fc85702e67f */
typedef struct Shared_func_8022AA34_View Shared_func_8022AA34_View;

struct Shared_func_8022AA34_View;
/* unbake published declaration: published_f4edf0c76a49fa4e03e92aa1 */
struct Shared_func_8022AA34_View {
    char pad0[0x840];
    f32 value;
    char pad844[4];
    s32 override;
};

/* unbake published declaration: published_3ac7f1798c2ff0f83c6f0a26 */
extern f32 func_8022AA44_de(Shared_func_8022AA34_View *arg0);

struct func_8022A274_S2;
/* unbake published declaration: published_41b2895b57fa6fe48f911fbb */
struct func_8022A274_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

struct func_8022AA8C_S2;
/* unbake published declaration: published_4532fc0de67504d60ed3f0be */
typedef struct func_8022AA8C_S2 func_8022AA8C_S2;

struct IntegerStateD4;
/* unbake published declaration: published_4ae80a0aaddd6723180673f5 */
typedef struct IntegerStateD4 IntegerStateD4;

struct func_8022AA8C_S2;
/* unbake published declaration: published_4c646fb91c9a7503b24493b3 */
struct func_8022AA8C_S2 {
    char pad0[0x20];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
};

struct func_8022AE18_S1;
/* unbake published declaration: published_54cde665bc306aedeab1ed1c */
struct func_8022AE18_S1 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    int unk14;
    char pad14[0x2F0 - 0x14 - sizeof(int)];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    int unk2FC;
};

/* unbake published declaration: published_5b742462a68b4e861f8c59b5 */
extern float D_800C2D04_de;

struct Player_func_8022ACB8_de;
/* unbake published declaration: published_5bc4b3d5c5cb0ef4fe06c085 */
typedef struct Player_func_8022ACB8_de Player_func_8022ACB8_de;

struct func_8022A82C_S3;
/* unbake published declaration: published_6046cab7f6b515c856795ea7 */
typedef struct func_8022A82C_S3 func_8022A82C_S3;

struct Node_func_8022A748_de;
/* unbake published declaration: published_65b11992f216db868e538bb6 */
struct Node_func_8022A748_de {
    u8 pad0[0x5D8];
    u8 *state;
    u8 pad5DC[0x280];
    s32 field85C;
    u8 pad860[0xE80];
    struct Node_func_8022A748_de *next;
};

struct func_8022AA8C_S1;
/* unbake published declaration: published_65c226471b8a0fa1594a80f9 */
struct func_8022AA8C_S1 {
    char pad0[0x594];
    s32 unk594;
};

struct func_8022AB10_S1;
/* unbake published declaration: published_69a82f8c7746a2bc81d0d5a0 */
struct func_8022AB10_S1 {
    char pad0[0x594];
    s32 unk594;
    char pad594[0x604 - 0x594 - sizeof(s32)];
    s8 unk604;
};

struct IntegerStateD4;
/* unbake published declaration: published_6e934051ea768559ed939415 */
struct IntegerStateD4 {
    unsigned char padding_0[208];
    s32 unk_D0;
};

struct ObjectLinks16E4_4;
/* unbake published declaration: published_71ab8662cc70fe229ccf7c34 */
struct ObjectLinks16E4_4 {
    char pad0[0x698];
    char * unk_698;
    char pad698[0x16E0 - 0x698 - sizeof(char*)];
    char * unk_16E0;
};

struct func_8022A8B8_S2;
/* unbake published declaration: published_72ea591b15f0039a4396c116 */
struct func_8022A8B8_S2 {
    char pad0[0x670];
    f32 unk670;
    char pad670[0x16E0 - 0x670 - sizeof(f32)];
    char * unk16E0;
};

/* unbake published declaration: published_7571c71b217e3b88860f8c02 */
extern int func_8022AE28_de(void *arg0, void *arg1);

/* unbake published declaration: published_78018610ccb2b2074541ced1 */
extern void *func_8022A634_de(void *arg0, u32 arg1);

/* unbake published declaration: published_791442b2d2d12814cd475c22 */
extern void func_8022A95C_de(void *arg0);

struct func_8022A4F4_S2;
/* unbake published declaration: published_7fd67697501e5a26a3abc673 */
struct func_8022A4F4_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x5E4 - 0x10 - sizeof(f32)];
    s32 unk5E4;
    char pad5E4[0x16E0 - 0x5E4 - sizeof(s32)];
    void * unk16E0;
};

struct func_8022AB8C_S1;
/* unbake published declaration: published_850d5c62783d1da9927265de */
typedef struct func_8022AB8C_S1 func_8022AB8C_S1;

struct func_8022A918_S1;
/* unbake published declaration: published_8de5e968d23fa7685770a24d */
typedef struct func_8022A918_S1 func_8022A918_S1;

/* unbake published declaration: published_901aeb6e521aba66e5477146 */
extern float D_800C2CE8_de;

struct func_8022AB8C_S1;
/* unbake published declaration: published_90cb248c488f9fdd2d239363 */
struct func_8022AB8C_S1 {
    char pad0[0x594];
    s32 unk594;
    char pad594[0x62E - 0x594 - sizeof(s32)];
    s16 unk62E;
};

struct IntegerState6C;
/* unbake published declaration: published_9107d1abdb1da78254877a8e */
struct IntegerState6C {
    char pad0[0x54];
    int unk_54;
    char pad54[0x68 - 0x54 - sizeof(int)];
    int unk_68;
};

struct func_8022A5B0_S2;
/* unbake published declaration: published_92c7ffdef7995900bdda2506 */
struct func_8022A5B0_S2 {
    char pad0[0x698];
    s32 unk698;
    char pad698[0x16E0 - 0x698 - sizeof(s32)];
    char * unk16E0;
};

/* unbake published declaration: published_93396b4c2d980da4685e7c64 */
extern void func_8022A940_de(void *arg0);

struct ObjectLinks16E4_3;
/* unbake published declaration: published_96060df31aae1e37b338e3bf */
typedef struct ObjectLinks16E4_3 ObjectLinks16E4_3;

/* unbake published declaration: published_a01617c3bfa6576c20972ade */
extern void func_8022A8C8_de(char *object, f32 arg1);

/* unbake published declaration: published_a59bd593ee05ef71f12112d0 */
extern void func_8022A928_de(void *arg0, int arg1);

struct ObjectLinks16E4_3;
/* unbake published declaration: published_a7f94a89ca70a352fce6a235 */
struct ObjectLinks16E4_3 {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x16E0 - 0x5D8 - sizeof(char*)];
    void * unk_16E0;
};

struct func_8022A8E0_S2;
/* unbake published declaration: published_a89413e6c330ceb0c4fe604c */
struct func_8022A8E0_S2 {
    char pad0[0x5FE];
    s16 unk5FE;
    char pad5FE[0x1450 - 0x5FE - sizeof(s16)];
    s32 unk1450;
    char pad1450[0x16E0 - 0x1450 - sizeof(s32)];
    char * unk16E0;
};

struct func_8022A82C_S3;
/* unbake published declaration: published_b163026e2df9402443623b98 */
struct func_8022A82C_S3 {
    char pad0[0x8F];
    unsigned char unk8F;
    char pad8F[0x90 - 0x8F - sizeof(unsigned char)];
    unsigned char unk90;
};

/* unbake published declaration: published_b4239beec75f0f24408cd921 */
extern float D_800C2D08_de;

struct func_8022A5B0_S2;
/* unbake published declaration: published_b42708e46fcbbc7d67c633ca */
typedef struct func_8022A5B0_S2 func_8022A5B0_S2;

struct func_8022AB10_S1;
/* unbake published declaration: published_b54122cdcce4bd486d919c3c */
typedef struct func_8022AB10_S1 func_8022AB10_S1;

struct Node_func_8022A748_de;
/* unbake published declaration: published_b79b02e47d42e112b1dd9367 */
typedef struct Node_func_8022A748_de Node_func_8022A748_de;

struct GlobalState;
/* unbake published declaration: published_b81a9570ba06bf5dd1bc2150 */
typedef struct GlobalState GlobalState;

struct State_func_8022A68C_de;
/* unbake published declaration: published_bb7b6052d24dd8a9d1dbfa2c */
typedef struct State_func_8022A68C_de State_func_8022A68C_de;

struct func_8022AAC4_S2;
/* unbake published declaration: published_c22d5b6ee1c3cfcee0925d4f */
typedef struct func_8022AAC4_S2 func_8022AAC4_S2;

struct State_func_8022A68C_de;
/* unbake published declaration: published_c265d13aba34a9e67c5cdc49 */
struct State_func_8022A68C_de {
    char pad0[0x1C];
    int armed;
    int active;
};

struct func_8022A470_S2;
/* unbake published declaration: published_c36d24401a74637907233754 */
typedef struct func_8022A470_S2 func_8022A470_S2;

struct func_8022A8E0_S2;
/* unbake published declaration: published_c6b564d186761eb7721c44fb */
typedef struct func_8022A8E0_S2 func_8022A8E0_S2;

struct func_8022A918_S1;
/* unbake published declaration: published_c70c35c66cf6a2dbc8243f08 */
struct func_8022A918_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0xB4 - 0x4 - sizeof(int)];
    int unkB4;
};

struct Actor_func_8022AB20_de;
/* unbake published declaration: published_c897bd80de3fa86c70089ed6 */
struct Actor_func_8022AB20_de {
    char pad[0x5F4];
    s16 table[1];
};

struct func_8022A4F4_S2;
/* unbake published declaration: published_c9eb729cb16c3884140a569c */
typedef struct func_8022A4F4_S2 func_8022A4F4_S2;

struct func_8022AA8C_S1;
/* unbake published declaration: published_ce190ccd0cb48b2cda7aea82 */
typedef struct func_8022AA8C_S1 func_8022AA8C_S1;

struct func_8022A67C_S1;
/* unbake published declaration: published_cf31fb200e5d40b1bbaee1c4 */
typedef struct func_8022A67C_S1 func_8022A67C_S1;

struct IntegerState6C;
/* unbake published declaration: published_db8b2bbe944b3775ea68e10b */
typedef struct IntegerState6C IntegerState6C;

struct Actor_func_8022AB20_de;
/* unbake published declaration: published_e1d471388d7765c5b875097a */
typedef struct Actor_func_8022AB20_de Actor_func_8022AB20_de;

struct func_8022AE18_S1;
/* unbake published declaration: published_e2835f0da3c8845ddf1d83a0 */
typedef struct func_8022AE18_S1 func_8022AE18_S1;

struct ObjectLinks1454_3;
/* unbake published declaration: published_e3993e5a332a436619dc631c */
typedef struct ObjectLinks1454_3 ObjectLinks1454_3;

struct func_8022A94C_S2;
/* unbake published declaration: published_e7b619b2638cd40c3d4e892b */
typedef struct func_8022A94C_S2 func_8022A94C_S2;

struct func_8022A274_S2;
/* unbake published declaration: published_efce4d1c18bea1832e2b2c9e */
typedef struct func_8022A274_S2 func_8022A274_S2;

struct func_8022A2FC_S2;
/* unbake published declaration: published_f5b4a289ea1d0ee3de8ba2bd */
typedef struct func_8022A2FC_S2 func_8022A2FC_S2;

struct GlobalState;
/* unbake published declaration: published_f6a7a7eaf8f1a51ee0a74c57 */
struct GlobalState {
    u8 pad0[0x1C];
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
};

struct Node_func_8022A748_de;
struct func_8022A738_S1;
/* unbake published declaration: published_fa6f09c7fd45de77942bdad6 */
struct func_8022A738_S1 {
    char pad0[0x20];
    struct Node_func_8022A748_de * unk20;
};

struct func_8022A8B8_S2;
/* unbake published declaration: published_fba3e891ed8a516df3071c08 */
typedef struct func_8022A8B8_S2 func_8022A8B8_S2;

struct func_8022A470_S2;
/* unbake published declaration: published_fcec32abee0812b8faedf920 */
struct func_8022A470_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x16E0 - 0x10 - sizeof(f32)];
    void * unk16E0;
};

/* unbake published declaration: published_fd6ce0614343b9bc40f10a66 */
extern float D_800C2D00_de;

#endif
