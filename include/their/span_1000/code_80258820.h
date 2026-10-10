#ifndef UNBAKE_SPAN_1000_CODE_80258820_H
#define UNBAKE_SPAN_1000_CODE_80258820_H
#include "../types.h"
struct IntegerState1DC4;
/* unbake published declaration: published_0d25c4401f061547b77cd3d7 */
typedef struct IntegerState1DC4 IntegerState1DC4;

struct Obj_func_80258E5C_de;
/* unbake published declaration: published_0d708b23622cc9971510f6b9 */
typedef struct Obj_func_80258E5C_de Obj_func_80258E5C_de;

struct SortTable;
/* unbake published declaration: published_128e302b87d2a7507334621e */
typedef struct SortTable SortTable;

/* unbake published declaration: published_140d151382722b118c4e6475 */
extern void *func_80258BF4_de(void *arg0, int arg1);

struct Scene_func_80259038_de;
/* unbake published declaration: published_ac55b3b0fd4614f850475ded */
struct Scene_func_80259038_de {
    char pad0[0x130];
    s32 lastPick;
    char pad134[0x2B54 - 0x134];
    s32 count;
    s32 ids;
    s32 *weights;
};

struct Scene_func_80259038_de;
/* unbake published declaration: published_de597651f4ff761a820fe0ff */
typedef struct Scene_func_80259038_de Scene_func_80259038_de;

/* unbake published declaration: published_14dc4f862866c12fd4e59606 */
extern s32 func_80259038_de(Scene_func_80259038_de *scene, s16 id, s16 avoid);

struct SortTable;
/* unbake published declaration: published_a8020e204bf9abbde14b7c2c */
struct SortTable {
    char unknown00[0xE];
    s16 count;
    u32 entries[1];
};

/* unbake published declaration: published_1a9f9db1365d7c11b2e3108a */
extern void func_80258F6C_de(SortTable *table);

struct func_80258D44_S1;
/* unbake published declaration: published_24cdb7b5f0cbd654361315d8 */
struct func_80258D44_S1 {
    char pad0[0x2B98];
    int unk2B98;
};

/* unbake published declaration: published_2ab654ceb32ee278688eacb9 */
extern float D_800C8FE0;

struct func_80258D3C_S1;
/* unbake published declaration: published_33ddb2c321cc387f0e8cadfd */
typedef struct func_80258D3C_S1 func_80258D3C_S1;

struct func_80258C14_S1;
/* unbake published declaration: published_3571fe71d6087924dcfe06f1 */
struct func_80258C14_S1 {
    char pad0[0x2B78];
    void * unk2B78;
};

struct func_80258C2C_S1;
/* unbake published declaration: published_3e690d241ba24b49784736fc */
struct func_80258C2C_S1 {
    char pad0[0x110];
    s32 unk110;
    char pad110[0x138 - 0x110 - sizeof(s32)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
    char pad1DB8[0x2B9C - 0x1DB8 - sizeof(char)];
    s32 unk2B9C;
};

struct func_80258BAC_S1;
/* unbake published declaration: published_44590da61090a901d7f6a4e5 */
typedef struct func_80258BAC_S1 func_80258BAC_S1;

struct func_80258D68_S1;
/* unbake published declaration: published_49d7dbd02bf7ddd7223c89e5 */
typedef struct func_80258D68_S1 func_80258D68_S1;

/* unbake published declaration: published_4a4d421c76cdf002a51b2924 */
extern void func_80258B94_de(void *arg0, int arg1);

struct func_80258D44_S1;
/* unbake published declaration: published_4ddf4988269b879b35fd0a50 */
typedef struct func_80258D44_S1 func_80258D44_S1;

struct func_80258BFC_S1;
/* unbake published declaration: published_520ae3242eed2fc9d76601d7 */
typedef struct func_80258BFC_S1 func_80258BFC_S1;

/* unbake published declaration: published_5575b0336fe6dd1b278bf966 */
extern void func_80258BBC_de(void *object, int value);

/* unbake published declaration: published_56d5ac14d1ba50d835743124 */
extern int func_80258D2C_de(void *object);

struct func_80258B00_S1;
/* unbake published declaration: published_62dc948ec44e7b675a7e6721 */
typedef struct func_80258B00_S1 func_80258B00_S1;

struct func_80258A9C_S1;
/* unbake published declaration: published_63675adae85f82b131091fb0 */
typedef struct func_80258A9C_S1 func_80258A9C_S1;

struct func_80258BDC_S1;
/* unbake published declaration: published_6e727442d5334dcbf35d4d8f */
typedef struct func_80258BDC_S1 func_80258BDC_S1;

struct func_80258BE4_S1;
/* unbake published declaration: published_7047b293804e751578b2d3ce */
typedef struct func_80258BE4_S1 func_80258BE4_S1;

struct func_80259014_S1;
/* unbake published declaration: published_7344386921a4ea51334777d5 */
typedef struct func_80259014_S1 func_80259014_S1;

struct func_80258F30_S1;
/* unbake published declaration: published_77a81fd6c9835c08733f29f4 */
struct func_80258F30_S1 {
    char pad0[0x2BA8];
    float unk2BA8;
    char pad2BA8[0x2BC0 - 0x2BA8 - sizeof(float)];
    char unk2BC0;
};

struct func_80258C2C_S1;
/* unbake published declaration: published_847961ab619af0b65687d75e */
typedef struct func_80258C2C_S1 func_80258C2C_S1;

struct Obj_func_80258E5C_de;
/* unbake published declaration: published_853f7a632e302c7c5d64659c */
struct Obj_func_80258E5C_de {
    char pad[0x2B9C];
    int level;
};

/* unbake published declaration: published_8aa15ae9851ea41d02de21b0 */
extern char *func_80258BC4_de(char *object, int index);

struct Slot_func_80258FF4_de;
/* unbake published declaration: published_8ab7906c2b55a808530e92a1 */
struct Slot_func_80258FF4_de {
    char pad[0xC];
    int id;
    char pad2[0xBC];
};

struct func_80258B00_S1;
/* unbake published declaration: published_8de264deeef2c3e8468bd41c */
struct func_80258B00_S1 {
    char pad0[0x104];
    s32 unk104;
    char pad104[0x134 - 0x104 - sizeof(s32)];
    s32 unk134;
    char pad134[0x2BB4 - 0x134 - sizeof(s32)];
    s32 unk2BB4;
};

struct func_80258D4C_S1;
/* unbake published declaration: published_92a463913b370a00a464027b */
typedef struct func_80258D4C_S1 func_80258D4C_S1;

/* unbake published declaration: published_99ea9461e357a7802d1ab47f */
extern void func_80258D38_de(void *arg0, int arg1);

/* unbake published declaration: published_9d716e77b427800f8393559f */
extern int func_80258FF4_de(char *arg0, int id);

struct func_80258F30_S1;
/* unbake published declaration: published_a5a891999c54ea3bb6f37f18 */
typedef struct func_80258F30_S1 func_80258F30_S1;

struct func_802588F4_S1;
/* unbake published declaration: published_ad6e841fa447b12a38f08938 */
struct func_802588F4_S1 {
    char pad0[0x110];
    char unk110;
    char pad110[0x138 - 0x110 - sizeof(char)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
};

struct func_802588F4_S1;
/* unbake published declaration: published_af968422af4a2588926d34c3 */
typedef struct func_802588F4_S1 func_802588F4_S1;

struct func_80258BAC_S1;
/* unbake published declaration: published_b16c67aa01f91ca72e153974 */
struct func_80258BAC_S1 {
    char pad0[0x2BA0];
    int unk2BA0;
};

/* unbake published declaration: published_b6bed5b607cf8670fceb5471 */
extern void *func_80258BDC_de(void *arg0, int arg1);

struct Slot_func_80258FF4_de;
/* unbake published declaration: published_b95277b863aaed4236b800fb */
typedef struct Slot_func_80258FF4_de Slot_func_80258FF4_de;

/* unbake published declaration: published_bd70bd35adfaff06991f5b47 */
extern double D_800C3EE8_de;

struct func_80258BE4_S1;
/* unbake published declaration: published_c06a61dcc06fabc638646aca */
struct func_80258BE4_S1 {
    char pad0[0x2B70];
    char * unk2B70;
};

struct func_80258BDC_S1;
/* unbake published declaration: published_c08c1a0f4eb2b1a24aaf94dd */
struct func_80258BDC_S1 {
    char pad0[0x2BA8];
    int unk2BA8;
};

struct func_80258D28_S1;
/* unbake published declaration: published_d8ed9348eb42e1c1e3eb4f65 */
typedef struct func_80258D28_S1 func_80258D28_S1;

struct func_80258BFC_S1;
/* unbake published declaration: published_d9a740d1782d3870e466af73 */
struct func_80258BFC_S1 {
    char pad0[0x2B74];
    int unk2B74;
};

struct func_80258C14_S1;
/* unbake published declaration: published_e1a304dd1f25e7207e7e36e2 */
typedef struct func_80258C14_S1 func_80258C14_S1;

struct IntegerState1DC4;
/* unbake published declaration: published_e4a0fc6c9c58b0ef1eeba78b */
struct IntegerState1DC4 {
    unsigned char padding_0[7616];
    s32 unk_1DC0;
};

struct func_80258D4C_S1;
/* unbake published declaration: published_e585fb15e13622a30739c322 */
struct func_80258D4C_S1 {
    char pad0[0x2BB0];
    int unk2BB0;
};

struct func_80259014_S1;
/* unbake published declaration: published_e95d38ef2c6d32606abb4c5f */
struct func_80259014_S1 {
    char pad0[0x1DBC];
    Slot_func_80258FF4_de unk1DBC;
};

struct func_80258D3C_S1;
/* unbake published declaration: published_f326e705f63438ded082d32d */
struct func_80258D3C_S1 {
    char pad0[0x2BB4];
    int unk2BB4;
};

struct func_80258D28_S1;
/* unbake published declaration: published_f34a2ef7b2dae43e058f1d4a */
struct func_80258D28_S1 {
    char pad0[0x2BAC];
    int unk2BAC;
};

struct func_80258D68_S1;
/* unbake published declaration: published_f3f851b1ff4b49a2e82dad79 */
struct func_80258D68_S1 {
    char pad0[0x2BB8];
    int unk2BB8;
};

/* unbake published declaration: published_fc2993ca93bf031f38aeb071 */
extern void func_80258B8C_de(void *arg0, int arg1);

struct func_80258A9C_S1;
/* unbake published declaration: published_ff0b33690720f619293cca91 */
struct func_80258A9C_S1 {
    char pad0[0x2BBC];
    f32 unk2BBC;
};

/* unbake published declaration: published_ff8a246cca12595013e88ed8 */
extern float D_800C8FE4;

#endif
