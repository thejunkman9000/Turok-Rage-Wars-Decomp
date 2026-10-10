#ifndef UNBAKE_SPAN_1000_CODE_8022AE90_H
#define UNBAKE_SPAN_1000_CODE_8022AE90_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct IntegerState1250;
/* unbake published declaration: published_08e8580ff60ee0382ad494a0 */
typedef struct IntegerState1250 IntegerState1250;

struct ObjectState12C4;
/* unbake published declaration: published_0eb244c33979bc26a0bbd8bb */
typedef struct ObjectState12C4 ObjectState12C4;

struct func_8022B7E8_S1;
/* unbake published declaration: published_0ee108d87183ac3065a744f4 */
struct func_8022B7E8_S1 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x11E4 - 0x5DC - sizeof(void*)];
    f32 unk11E4;
    char pad11E4[0x13E0 - 0x11E4 - sizeof(f32)];
    void * unk13E0;
};

/* unbake published declaration: published_0fc0dd3624473a7f2fb31176 */
extern int func_8022B460_de(char *object);

struct func_8022B054_S1;
/* unbake published declaration: published_13403bede75c8379a2fd173c */
struct func_8022B054_S1 {
    char pad0[0x16C4];
    Triple unk16C4;
};

struct Record_func_8022BA0C_de;
/* unbake published declaration: published_14e2e8944d097b36ef008f76 */
typedef struct Record_func_8022BA0C_de Record_func_8022BA0C_de;

struct ObjectState16DA;
/* unbake published declaration: published_1cd2ea7ece1eb8fc84e41c25 */
struct ObjectState16DA {
    unsigned char padding_0[5848];
    u16 unk_16D8;
};

/* unbake published declaration: published_287db6dfb6752d1a45b8451c */
extern int func_8022BA90_de(void);

struct func_8022B3C0_S1;
/* unbake published declaration: published_2e4bf898444101da33f9cedb */
typedef struct func_8022B3C0_S1 func_8022B3C0_S1;

struct func_8022B450_S1;
/* unbake published declaration: published_35380b55ad1c15cb42f13990 */
struct func_8022B450_S1 {
    char pad0[0x11FC];
    float unk11FC;
};

struct func_8022B7E8_S2;
/* unbake published declaration: published_404b45a2cba18af247baf840 */
struct func_8022B7E8_S2 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x5D8 - 0x100 - sizeof(s32)];
    char * unk5D8;
};

struct func_8022B450_S1;
/* unbake published declaration: published_44b804bc9091f5146095867a */
typedef struct func_8022B450_S1 func_8022B450_S1;

struct Timer;
/* unbake published declaration: published_4f87e612c7bf3d6cefc6ade1 */
typedef struct Timer Timer;

struct ScoreTable;
struct ScoreTable {
    u8 pad00[0x3C];
    short value[8];
};
struct Record_func_8022BA0C_de;
struct ScoreTable;
/* unbake published declaration: published_54590210b81c39658e5b7632 */
struct Record_func_8022BA0C_de {
    u8 pad0000[0x5D8];
    struct ScoreTable *scores;
    u8 pad05DC[0x16E0 - 0x5DC];
    struct Record_func_8022BA0C_de *next;
    u8 pad16E4[4];
};

struct ObjectState12C4;
/* unbake published declaration: published_5a1fb98d3e8341a5d4539456 */
struct ObjectState12C4 {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3288];
    f32 unk_12C0;
};

struct func_8022B474_S1;
/* unbake published declaration: published_5cf561d3ed6f936674476769 */
typedef struct func_8022B474_S1 func_8022B474_S1;

struct Timer;
/* unbake published declaration: published_bf7d7290b9a1c0f9a5bdf66e */
struct Timer {
    float step;
    float duration;
    int kind;
    float target;
    float elapsed;
    int tag;
};

struct Obj_func_8022B550_de;
/* unbake published declaration: published_5cf7cde759cc21dfa4041191 */
struct Obj_func_8022B550_de {
    char pad[0x1248];
    Timer timers[5];
};

struct func_8022B174_S1;
/* unbake published declaration: published_692d519974906c975758346b */
typedef struct func_8022B174_S1 func_8022B174_S1;

struct func_8022AE90_S1;
/* unbake published declaration: published_6aa7beda2bb560018252b3d2 */
struct func_8022AE90_S1 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5DC - 0x8 - sizeof(char)];
    s32 unk5DC;
    char pad5DC[0x11BC - 0x5DC - sizeof(s32)];
    s32 unk11BC;
};

struct IntegerState1218;
/* unbake published declaration: published_707cbace053252121fcc882b */
struct IntegerState1218 {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3112];
    s32 unk_1210;
    s32 unk_1214;
};

struct func_8022B3C0_S1;
/* unbake published declaration: published_73c38bb38ea64269b773cbcc */
struct func_8022B3C0_S1 {
    char pad0[0x1200];
    Vec3 unk1200;
};

struct func_8022B974_S1;
/* unbake published declaration: published_7623c5b0de57f0583ec70b52 */
struct func_8022B974_S1 {
    char pad0[0x1210];
    s32 unk1210;
    char pad1210[0x1214 - 0x1210 - sizeof(s32)];
    s32 unk1214;
};

struct ObjectState13E4;
/* unbake published declaration: published_76db0b2067440d065f57b233 */
struct ObjectState13E4 {
    char pad0[0x170];
    char unk_170;
    char pad170[0x174 - 0x170 - sizeof(char)];
    s32 unk_174;
    char pad174[0x11E4 - 0x174 - sizeof(s32)];
    f32 unk_11E4;
    char pad11E4[0x13E0 - 0x11E4 - sizeof(f32)];
    s32 unk_13E0;
};

struct func_8022B2F4_S2;
/* unbake published declaration: published_806f6af2585bdc1ff03f12ba */
typedef struct func_8022B2F4_S2 func_8022B2F4_S2;

struct func_8022B054_S1;
/* unbake published declaration: published_8906ec8a34b5ec7ab8c886d9 */
typedef struct func_8022B054_S1 func_8022B054_S1;

struct func_8022B474_S1;
/* unbake published declaration: published_8c36771b8dc0e561879547e2 */
struct func_8022B474_S1 {
    char pad0[0x120C];
    s32 unk120C;
};

struct func_8022AF64_S1;
/* unbake published declaration: published_97c85c652d11a4bf00886865 */
typedef struct func_8022AF64_S1 func_8022AF64_S1;

/* unbake published declaration: published_9aa92165d22a60bc2000be40 */
extern void func_8022B484_de(char *arg0);

struct ObjectState16DA;
/* unbake published declaration: published_9d369c88e3aaa2c3a2e65a60 */
typedef struct ObjectState16DA ObjectState16DA;

struct Obj_func_8022B550_de;
/* unbake published declaration: published_a3764761fcb17c52d1e69807 */
typedef struct Obj_func_8022B550_de Obj_func_8022B550_de;

struct IntegerState16D4;
/* unbake published declaration: published_a8f88f9c2fe11ec8232d40b6 */
struct IntegerState16D4 {
    unsigned char padding_0[5840];
    s32 unk_16D0;
};

struct func_8022AF64_S1;
/* unbake published declaration: published_ac1e0fe4bd03a5184eb29199 */
struct func_8022AF64_S1 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5DC - 0x8 - sizeof(char)];
    s32 unk5DC;
    char pad5DC[0x11C0 - 0x5DC - sizeof(s32)];
    s32 unk11C0;
};

/* unbake published declaration: published_ad35bd4b0a5e6d849d7573e2 */
extern int func_8022B97C_de(void);

struct func_8022B08C_S2;
/* unbake published declaration: published_b428b40f2d4bc7ca5f91690d */
struct func_8022B08C_S2 {
    char pad0[0x160];
    Matrix_func_80213CF8_de unk160;
};

struct func_8022B08C_S1;
/* unbake published declaration: published_b59b2da73099edc69595dfaa */
struct func_8022B08C_S1 {
    char pad0[0x5DC];
    Matrix_func_80213CF8_de * unk5DC;
};

struct Context;
struct Record_func_8022BA0C_de;
/* unbake published declaration: published_b5cc6653516f5b2ef9f70bf1 */
struct Context {
    u8 pad00[4];
    struct Record_func_8022BA0C_de *base;
    u8 pad08[0x18];
    struct Record_func_8022BA0C_de *head;
};

struct Game_func_8022B7F8_de;
/* unbake published declaration: published_b895d967d20ee65dcf56ec21 */
typedef struct Game_func_8022B7F8_de Game_func_8022B7F8_de;

struct func_8022B174_S1;
/* unbake published declaration: published_bc20686177b8a8cbdd3af605 */
struct func_8022B174_S1 {
    char pad0[0x1210];
    int unk1210;
};

struct func_8022B08C_S1;
/* unbake published declaration: published_be76bef1f7b63c486dbc39ff */
typedef struct func_8022B08C_S1 func_8022B08C_S1;

/* unbake published declaration: published_bedad43fada45affa9cd8970 */
extern float D_800C7E08;

struct func_8022B974_S1;
/* unbake published declaration: published_c49bbf96eb94fa3c94a8bdd4 */
typedef struct func_8022B974_S1 func_8022B974_S1;

struct IntegerState11C0;
/* unbake published declaration: published_c5c7151e39a75b33e38aa221 */
struct IntegerState11C0 {
    unsigned char padding_0[4540];
    s32 unk_11BC;
};

struct ObjectState13E4;
/* unbake published declaration: published_c7b12421cdd96ae5dc67e27f */
typedef struct ObjectState13E4 ObjectState13E4;

struct Context;
/* unbake published declaration: published_d78b3f9953887a26e895b58f */
typedef struct Context Context;

/* unbake published declaration: published_d0f17ebaaffc3d0d287ac078 */
extern void *func_8022BA0C_de(Context *context);

struct func_8022B74C_S1;
/* unbake published declaration: published_d8510b02194590f62762da5c */
struct func_8022B74C_S1 {
    char pad0[0x5DC];
    s32 unk5DC;
    char pad5DC[0x13B0 - 0x5DC - sizeof(s32)];
    s32 unk13B0;
};

struct IntegerState16D4;
/* unbake published declaration: published_de8feecac4afb8751af8ff89 */
typedef struct IntegerState16D4 IntegerState16D4;

struct func_8022B2F4_S2;
/* unbake published declaration: published_df3044a0db7113f387875e40 */
struct func_8022B2F4_S2 {
    char pad0[0x5D0];
    s32 unk5D0;
    char pad5D0[0x11FC - 0x5D0 - sizeof(s32)];
    f32 unk11FC;
    char pad11FC[0x16E0 - 0x11FC - sizeof(f32)];
    void * unk16E0;
};

struct func_8022B08C_S2;
/* unbake published declaration: published_dfe89f8028e39d171440ed59 */
typedef struct func_8022B08C_S2 func_8022B08C_S2;

struct func_8022B74C_S1;
/* unbake published declaration: published_e647bf74034dba29511a337e */
typedef struct func_8022B74C_S1 func_8022B74C_S1;

struct func_8022B7E8_S2;
/* unbake published declaration: published_ece4aa3ef9c75460212f85c2 */
typedef struct func_8022B7E8_S2 func_8022B7E8_S2;

struct func_8022AE90_S1;
/* unbake published declaration: published_ed924cfd8a35ae03f23ac565 */
typedef struct func_8022AE90_S1 func_8022AE90_S1;

struct IntegerState1250;
/* unbake published declaration: published_ef71d2c80e4ab5e0a1eb1e71 */
struct IntegerState1250 {
    unsigned char padding_0[4684];
    s32 unk_124C;
};

struct func_8022B720_S1;
/* unbake published declaration: published_f14b180f2f2b0453652f1468 */
typedef struct func_8022B720_S1 func_8022B720_S1;

struct IntegerState1218;
/* unbake published declaration: published_f4831a94aaa371270e421117 */
typedef struct IntegerState1218 IntegerState1218;

struct Game_func_8022B7F8_de;
/* unbake published declaration: published_f51088d29b468f0a67779910 */
struct Game_func_8022B7F8_de {
    char pad0[0x1240];
    MenuSettings settings;
};

struct func_8022B720_S1;
/* unbake published declaration: published_f75f0de4205caff128d53374 */
struct func_8022B720_S1 {
    char pad0[0x11DC];
    f32 unk11DC;
    char pad11DC[0x122C - 0x11DC - sizeof(f32)];
    s32 unk122C;
};

struct IntegerState11C0;
/* unbake published declaration: published_fa1c7ff4f52beba043842724 */
typedef struct IntegerState11C0 IntegerState11C0;

struct func_8022B7E8_S1;
/* unbake published declaration: published_fe8f6897d614f753a07c396b */
typedef struct func_8022B7E8_S1 func_8022B7E8_S1;

#endif
