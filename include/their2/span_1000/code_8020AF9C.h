#ifndef UNBAKE_SPAN_1000_CODE_8020AF9C_H
#define UNBAKE_SPAN_1000_CODE_8020AF9C_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Node8020BC50;
/* unbake published declaration: published_06e8cf02ded32d1637b1a119 */
struct Node8020BC50 {
    s32 key;
    f32 value;
    s32 state;
    s32 fieldC;
    struct Node8020BC50 *next;
    s32 field14;
    s32 field18;
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    s32 field2C;
    s32 field30;
};

struct ObjectLinks14;
/* unbake published declaration: published_105d8ff3f799cb245eb17710 */
typedef struct ObjectLinks14 ObjectLinks14;

struct Node;
/* unbake published declaration: published_131eb5201f987226a7ee2510 */
struct Node {
    int id;
    char pad4[0xC];
    struct Node *next;
    char pad14[0x18];
    int active;
};

struct ObjectState10;
/* unbake published declaration: published_18c52eb083772e360a699614 */
typedef struct ObjectState10 ObjectState10;

struct func_8020CFE0_S1;
/* unbake published declaration: published_1be78bbb8d833a3f5b41860f */
struct func_8020CFE0_S1 {
    char pad0[0x24];
    char * unk24;
};

struct func_8020D014_S1;
/* unbake published declaration: published_1d8c46f15b6ff713ed82bf90 */
typedef struct func_8020D014_S1 func_8020D014_S1;

/* unbake published declaration: published_295e9dd4f70d6ccf55d8c6fd */
extern float D_800C1D6C_de;

struct func_8020D014_S1;
/* unbake published declaration: published_2cb31ac16c072f48e0516396 */
struct func_8020D014_S1 {
    char pad0[0x1C];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    void * unk24;
};

struct func_8020D014_S2;
/* unbake published declaration: published_3242b1c0f34855779b8e94df */
typedef struct func_8020D014_S2 func_8020D014_S2;

struct Node8020D114;
/* unbake published declaration: published_691e6301b653044fa0239551 */
struct Node8020D114 {
    s32 value;
    char pad04[0xC];
    struct Node8020D114 *next;
    char pad14[0x1C];
    struct Node8020D114 *parent;
};

struct Node8020D114;
struct func_8020D114_S1;
/* unbake published declaration: published_34214a37b8aadfb40535c8c3 */
struct func_8020D114_S1 {
    char pad0[0x18];
    s32 unk18;
    char pad18[0x24 - 0x18 - sizeof(s32)];
    struct Node8020D114 * unk24;
};

struct func_8020D28C_S2;
/* unbake published declaration: published_346c7ef41c4830039977ac09 */
typedef struct func_8020D28C_S2 func_8020D28C_S2;

struct func_8020CFE0_S2;
/* unbake published declaration: published_3a8fbfb327cb8984be75c522 */
typedef struct func_8020CFE0_S2 func_8020CFE0_S2;

struct EntryList8020CCE8;
struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_3f55d50b201521f5f17b63f9 */
struct EntryList8020CCE8 {
    s32 pad0[2];
    struct Shape_func_802764D4_de_2 *table;
    s32 count;
};

struct Node8020BC50;
/* unbake published declaration: published_41f391dabe86bb2803b42eb1 */
typedef struct Node8020BC50 Node8020BC50;

struct func_8020D318_S1;
/* unbake published declaration: published_4220b90139afbbd4bd8333b1 */
typedef struct func_8020D318_S1 func_8020D318_S1;

struct Obj_func_8020D220_de;
/* unbake published declaration: published_44d64947a38e1ade7bd58f6e */
typedef struct Obj_func_8020D220_de Obj_func_8020D220_de;

struct Table8020BC50;
/* unbake published declaration: published_4b34694c40b48b48298cfcd9 */
typedef struct Table8020BC50 Table8020BC50;

struct Obj8020BC50;
/* unbake published declaration: published_4fcf30ac2b7b14ee224216f6 */
typedef struct Obj8020BC50 Obj8020BC50;

struct func_8020D114_S1;
/* unbake published declaration: published_5147a0abcb46320c90ccc55b */
typedef struct func_8020D114_S1 func_8020D114_S1;

struct ObjectLinks14;
/* unbake published declaration: published_548dcc358b732f3d8e6a94ac */
struct ObjectLinks14 {
    char pad0[0x4];
    int unk_4;
    char pad4[0x10 - 0x4 - sizeof(int)];
    char * unk_10;
};

struct EntryList8020CCE8;
/* unbake published declaration: published_55e09597e6a09ab9989f121f */
typedef struct EntryList8020CCE8 EntryList8020CCE8;

struct Graph;
/* unbake published declaration: published_5a813921f62628e8bc56ae36 */
typedef struct Graph Graph;

struct func_8020D28C_S2;
/* unbake published declaration: published_5d6b791d51f9ed2e5c6fb149 */
struct func_8020D28C_S2 {
    char pad0[0x10];
    char * unk10;
    char pad10[0x24 - 0x10 - sizeof(char*)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    s32 unk28;
};

/* unbake published declaration: published_719e701ef96bca29585dba9b */
extern int func_8020D280_de(void *arg0);

struct Node8020D114;
/* unbake published declaration: published_809d03be2e9f18e6f49a8d4c */
typedef struct Node8020D114 Node8020D114;

struct func_8020CA10_S1;
/* unbake published declaration: published_8b1ea2efb996dba0e19daa5a */
struct func_8020CA10_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    f32 unk14;
    char pad14[0x34 - 0x14 - sizeof(f32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
    char pad40[0x44 - 0x40 - sizeof(s32)];
    s32 unk44;
    char pad44[0x48 - 0x44 - sizeof(s32)];
    s32 unk48;
    char pad48[0x4C - 0x48 - sizeof(s32)];
    s32 unk4C;
};

/* unbake published declaration: published_9d8bacb56c56878c4ec8a923 */
extern void func_8020D2FC_de(void *object);

union ObjectState4;
/* unbake published declaration: published_a2d11bbeb0359680959a53fe */
typedef union ObjectState4 ObjectState4;

struct Table8020BC50;
/* unbake published declaration: published_c092e8a7d7374530a3c9a162 */
struct Table8020BC50 {
    s32 stride;
    char data[4];
};

struct Obj8020BC50;
/* unbake published declaration: published_a8c8b9b35783cd3eb3f7b8eb */
struct Obj8020BC50 {
    Table8020BC50 *records;
    s32 count;
    char pad8[8];
    Table8020BC50 *links;
    char pad14[4];
    s32 result;
    f32 value;
    s32 selected;
    Node8020BC50 *nodes;
};

union ObjectState4;
/* unbake published declaration: published_bd70a927b401e8573634e7e2 */
union ObjectState4 {
    u32 v0;
    u16 v1;
};

struct ObjectState10;
/* unbake published declaration: published_b090fafbd02dc950fefd461c */
struct ObjectState10 {
    char pad0[0xC];
    ObjectState4 unk_C;
};

struct Node;
struct Obj_func_8020D220_de;
/* unbake published declaration: published_b1807966b2a5679dac55a37d */
struct Obj_func_8020D220_de {
    char pad[0x24];
    struct Node *list;
    char pad28[0x10];
    int ids[64];
};

struct func_8020CFE0_S2;
/* unbake published declaration: published_b3629bd564f1fbc91d4e4113 */
struct func_8020CFE0_S2 {
    s32 unk0;
    char pad0[0x10 - 0x0 - sizeof(s32)];
    char * unk10;
};

struct func_8020CFE0_S1;
/* unbake published declaration: published_b5e75c2f143dde68ebfd3acd */
typedef struct func_8020CFE0_S1 func_8020CFE0_S1;

/* unbake published declaration: published_b6bf87db9b8d9ba787b2138e */
extern float D_800C1D68_de;

/* unbake published declaration: published_b770c1f8c567acc301cff786 */
extern void func_8020D35C_de(void *arg0);

struct func_8020D328_S2;
/* unbake published declaration: published_b7ac9581d642f6052c383980 */
typedef struct func_8020D328_S2 func_8020D328_S2;

/* unbake published declaration: published_bb9469d4f8480e6d2f8f4bb5 */
extern int func_8020D318_de(void *arg0);

struct func_8020D328_S2;
/* unbake published declaration: published_bc66a20f6fe48fbca32d2da9 */
struct func_8020D328_S2 {
    char pad0[0x10];
    char * unk10;
    char pad10[0x28 - 0x10 - sizeof(char*)];
    s32 unk28;
};

/* unbake published declaration: published_c3555ffd5431f2550e1379ec */
extern int func_8020D308_de(void *arg0);

struct Node;
/* unbake published declaration: published_e222d586d74f8a368921d0e4 */
typedef struct Node Node;

struct func_8020CA10_S1;
/* unbake published declaration: published_e6feb6eeacff0282c3cdb52f */
typedef struct func_8020CA10_S1 func_8020CA10_S1;

/* unbake published declaration: published_e7b00906c578a68ce0991437 */
extern float D_800C1D8C_de;

struct func_8020D318_S1;
/* unbake published declaration: published_e9545038e41ec5b020745511 */
struct func_8020D318_S1 {
    char pad0[0x28];
    unsigned int unk28;
};

struct func_8020D014_S2;
/* unbake published declaration: published_f042aba3980f95cd04605cde */
struct func_8020D014_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    void * unk10;
    char pad10[0x18 - 0x10 - sizeof(void*)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
};

struct LinkTable;
struct LinkTable {
    int stride;
    int pad4;
    Link first;
};
struct Graph;
struct LinkTable;
/* unbake published declaration: published_f2918a1ecee7b747cc92bc38 */
struct Graph {
    char pad0[8];
    struct LinkTable *links;
    int count;
};

/* unbake published declaration: published_f4bfbb2cc68809cd9a00a17c */
extern void *func_8020D28C_de(void *arg0);

/* unbake published declaration: published_fae6b8d16de9dfee75e442d5 */
extern void func_8020CA10_de(void *arg0, s32 arg1);

#endif
