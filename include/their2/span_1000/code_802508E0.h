#ifndef UNBAKE_SPAN_1000_CODE_802508E0_H
#define UNBAKE_SPAN_1000_CODE_802508E0_H
#include "../types.h"
/* unbake published declaration: published_11c7696e79f010e2a046034f */
extern int func_80250DE0_de(void *object);

struct Manager;
/* unbake published declaration: published_12933b915dcbe0f860eb4329 */
struct Manager {
    char queue[0x92C];
    IntrusiveList pending;
    IntrusiveList active;
    char padActive[0x20 - sizeof(IntrusiveList)];
    char lock[0x18];
    char unk978[0x24];
    s32 mask;
};

struct Node_func_80251F6C_de;
/* unbake published declaration: published_868ec43bfd65da05ab16085c */
struct Node_func_80251F6C_de {
    void *data;
    s32 unk04;
    s32 count;
    s32 flags;
    s32 stamp;
};

struct Node_func_80251F6C_de;
struct Request_func_80251F6C_de;
/* unbake published declaration: published_e546da1825169a729172d073 */
struct Request_func_80251F6C_de {
    struct Node_func_80251F6C_de *node;
    struct Node_func_80251F6C_de *extra;
    s32 key;
    s32 priority;
    s32 flags;
    void *unk14;
    void *owner;
    s32 mode;
    void *unk20;
    struct Request_func_80251F6C_de *next;
};

struct HashNode_func_80251F6C_de;
struct Request_func_80251F6C_de;
/* unbake published declaration: published_17544ba17a507721db57cd53 */
struct HashNode_func_80251F6C_de {
    s32 key;
    struct Request_func_80251F6C_de *value;
    s32 unk08;
    struct HashNode_func_80251F6C_de *next;
};

/* unbake published declaration: published_41e6661373fd313a0bb6e1c5 */
extern int D_801005A0[];

struct Node_func_80251F6C_de;
/* unbake published declaration: published_44d49fbf858d92f4f5adbe91 */
typedef struct Node_func_80251F6C_de Node_func_80251F6C_de;

struct Manager_func_802524B0_de;
/* unbake published declaration: published_4c800f7b799fc16868dca250 */
struct Manager_func_802524B0_de {
    char queue[0x92C];
    IntrusiveList pending;
    IntrusiveList active;
    char padActive[0x20 - sizeof(IntrusiveList)];
    char lock[0x18];
};

struct Node_func_802524B0_de;
/* unbake published declaration: published_527f280f158087124b794469 */
typedef struct Node_func_802524B0_de Node_func_802524B0_de;

/* unbake published declaration: published_54f070afe567675dcae1170b */
extern int func_802532F4_de(void *arg0);

struct ObjectState13;
/* unbake published declaration: published_57eaffb7ef3f31753b78acc3 */
typedef struct ObjectState13 ObjectState13;

struct func_80250A7C_S1;
/* unbake published declaration: published_5baa2db40261a81c99a1096e */
struct func_80250A7C_S1 {
    char pad0[0xD0];
    s32 unkD0;
    char padD0[0xD8 - 0xD0 - sizeof(s32)];
    u16 unkD8;
    char padD8[0xDA - 0xD8 - sizeof(u16)];
    u8 unkDA;
};

/* unbake published declaration: published_5cf02409776f0f729329f5ef */
extern void func_80253300_de(void *arg0);

struct Node_func_80251328_de;
/* unbake published declaration: published_5f34cbeed82fc7cd606f6f28 */
struct Node_func_80251328_de {
    s32 resource;
    char pad4[8];
    s32 flags;
    s32 lastUsed;
    char pad14[4];
    struct Node_func_80251328_de *next;
};

struct Node_func_80252774_de;
struct Request_func_80252774_de;
/* unbake published declaration: published_63d5ef887ca95f876049c54a */
struct Node_func_80252774_de {
    void *data;
    s32 pad4;
    s32 count;
    s32 flags;
    s32 pad10;
    struct Request_func_80252774_de *owner;
};

/* unbake published declaration: published_baf0ead475e3585a400eb3d6 */
struct Request_func_80252774_de {
    struct Node_func_80252774_de *node;
    s32 pad4;
    s32 key;
    s32 priority;
};

struct HashNode_func_80252774_de;
struct Request_func_80252774_de;
/* unbake published declaration: published_6054a0a66acc845e1c48eb96 */
struct HashNode_func_80252774_de {
    s32 key;
    struct Request_func_80252774_de *value;
    s32 pad8;
    struct HashNode_func_80252774_de *next;
};

struct Manager_func_802524B0_de;
/* unbake published declaration: published_617b37b864bf418f3b691390 */
typedef struct Manager_func_802524B0_de Manager_func_802524B0_de;

struct func_80250D88_S1;
/* unbake published declaration: published_6c94774fc53b65d6e6ebbaef */
struct func_80250D88_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0xDC - 0x18 - sizeof(void*)];
    unsigned int unkDC;
};

struct func_80250950_S1;
/* unbake published declaration: published_6ea2dcf3b17b4aed0abbd659 */
struct func_80250950_S1 {
    char pad0[0x1];
    s8 unk1;
    char pad1[0x20 - 0x1 - sizeof(s8)];
    s32 unk20;
    char pad20[0xD0 - 0x20 - sizeof(s32)];
    s32 unkD0;
    char padD0[0xD8 - 0xD0 - sizeof(s32)];
    u16 unkD8;
};

struct func_802532A0_S1;
/* unbake published declaration: published_72cfbc13d8bd37d4620729c5 */
typedef struct func_802532A0_S1 func_802532A0_S1;

struct Request_func_802524B0_de;
/* unbake published declaration: published_85069e4368e572c5fa84d4a3 */
typedef struct Request_func_802524B0_de Request_func_802524B0_de;

struct ObjectState13;
/* unbake published declaration: published_8ba4febe86c7eec8a0cbfa88 */
struct ObjectState13 {
    unsigned char padding_0[18];
    signed char unk_12;
};

struct Manager;
/* unbake published declaration: published_8ca8f323357b88093c9a5852 */
typedef struct Manager Manager;

struct Node_func_802524B0_de;
/* unbake published declaration: published_f32cdc5aa9915b9da98cdb06 */
struct Node_func_802524B0_de {
    void *data;
    s32 pad4;
    s32 count;
    s32 flags;
};

struct Node_func_802524B0_de;
struct Request_func_802524B0_de;
/* unbake published declaration: published_921b0c40cde95fa81e6abd8a */
struct Request_func_802524B0_de {
    struct Node_func_802524B0_de *node;
    s32 pad4[3];
    s32 flags;
};

struct Owner_func_80250C84_de;
/* unbake published declaration: published_923e8de7d4448c9efa2fd618 */
struct Owner_func_80250C84_de {
    char pad0[0x20];
    s32 field20;
    char pad24[4];
    char transform[0xA8];
    s32 flagsD0;
    char padD4[6];
    u8 colorFrame;
};

struct Node_func_80251328_de;
/* unbake published declaration: published_bbd0c616130897e0f51bf2b1 */
typedef struct Node_func_80251328_de Node_func_80251328_de;

struct func_80250D88_S2;
/* unbake published declaration: published_9a623cd741f135e84aa271db */
typedef struct func_80250D88_S2 func_80250D88_S2;

struct Node_func_80252774_de;
/* unbake published declaration: published_9c4af8872aafcf4f5c71b94d */
typedef struct Node_func_80252774_de Node_func_80252774_de;

/* unbake published declaration: published_9ced9b5f8e2904ed81e9b7a9 */
extern void *func_802517B4_de(s32 arg0, s32 arg1);

/* unbake published declaration: published_9f212b8f433bec53cacb7329 */
extern void func_80250AD4_de(void *arg0);

struct func_80250ACC_S1;
/* unbake published declaration: published_9fc9b84ecbc0a325cb25fc1b */
struct func_80250ACC_S1 {
    char pad0[0x20];
    s32 unk20;
    char pad20[0xB4 - 0x20 - sizeof(s32)];
    void * unkB4;
    char padB4[0xD0 - 0xB4 - sizeof(void*)];
    s32 unkD0;
};

/* unbake published declaration: published_a0bb1d0e2e390a27443501e2 */
extern int func_80250BF0_de();

struct func_802532A0_S1;
/* unbake published declaration: published_a210b21945b0f357288409b4 */
struct func_802532A0_S1 {
    char pad0[0x8];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    unsigned int unkC;
};

struct func_80250ACC_S1;
/* unbake published declaration: published_a4fdb0e2acaf457241ea19e3 */
typedef struct func_80250ACC_S1 func_80250ACC_S1;

/* unbake published declaration: published_a605950640d1141829f378a8 */
extern s8 func_80250E14_de(void *arg0);

/* unbake published declaration: published_b82fba100a891a9ce6bc22c5 */
extern void func_80250A9C_de();

struct func_80250D88_S2;
/* unbake published declaration: published_b83033eafebae05ea7740da2 */
struct func_80250D88_S2 {
    char pad0[0xE];
    signed char unkE;
    char padE[0xF - 0xE - sizeof(signed char)];
    signed char unkF;
    char padF[0x24 - 0xF - sizeof(signed char)];
    unsigned int unk24;
};

struct func_80250A7C_S1;
/* unbake published declaration: published_bd6d549cd578d9ac225fc4da */
typedef struct func_80250A7C_S1 func_80250A7C_S1;

struct ObjectLinksDC;
/* unbake published declaration: published_bdeebab3b35c87113b617d3a */
typedef struct ObjectLinksDC ObjectLinksDC;

struct ObjectLinksDC;
/* unbake published declaration: published_ca50e1e4664d0cdb33f2cb65 */
struct ObjectLinksDC {
    char pad0[0x18];
    char * unk_18;
    char pad18[0xD8 - 0x18 - sizeof(char*)];
    unsigned short unk_D8;
};

struct HashNode_func_80251F6C_de;
/* unbake published declaration: published_d5643f1bf6a8ea29b1123d0d */
typedef struct HashNode_func_80251F6C_de HashNode_func_80251F6C_de;

/* unbake published declaration: published_d9ec36f7db62108b4f73db4f */
extern void func_802524B0_de(void *arg);

/* unbake published declaration: published_da4868c14232f42040251bcf */
extern void func_8025331C_de(void *arg0);

struct Owner_func_80250C84_de;
/* unbake published declaration: published_e22025a2ed26050ab3f44cc8 */
typedef struct Owner_func_80250C84_de Owner_func_80250C84_de;

struct HashNode_func_80252774_de;
/* unbake published declaration: published_e86ade69c7acff0ad1c429b9 */
typedef struct HashNode_func_80252774_de HashNode_func_80252774_de;

struct Request_func_80252774_de;
/* unbake published declaration: published_ee259a995ec6c2afea920d0f */
typedef struct Request_func_80252774_de Request_func_80252774_de;

struct Shape_func_802BC570_de;
/* unbake published declaration: published_ef1650913039058763b76548 */
struct Shape_func_802BC570_de {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct Request_func_80251F6C_de;
/* unbake published declaration: published_f7649ae8905cf7de8b50cf2c */
typedef struct Request_func_80251F6C_de Request_func_80251F6C_de;

struct func_80250D88_S1;
/* unbake published declaration: published_fd949475b474c617c2cb8b85 */
typedef struct func_80250D88_S1 func_80250D88_S1;

struct func_80250950_S1;
/* unbake published declaration: published_fe35cc6b286e4b2ab3d3c808 */
typedef struct func_80250950_S1 func_80250950_S1;

#endif
