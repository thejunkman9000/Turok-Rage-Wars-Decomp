#ifndef UNBAKE_SPAN_1000_CODE_8026AC38_H
#define UNBAKE_SPAN_1000_CODE_8026AC38_H
#include "../types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "gfx.h"
struct ObjectState18;
/* unbake published declaration: published_05556071161c88ddf76df2f8 */
typedef struct ObjectState18 ObjectState18;

struct Mesh;
/* unbake published declaration: published_0c77412ad2139c3d336e201f */
struct Mesh {
    u32 list;
    u32 matrix;
    u32 aux;
    u32 vertices;
    u16 scaleS;
    u16 scaleT;
    s32 segmented;
    s32 unused;
    struct Mesh *next;
};

struct Mesh;
/* unbake published declaration: published_284dbbd552735a7b805dd8da */
typedef struct Mesh Mesh;

struct Material18;
/* unbake published declaration: published_bfc47e234cb394f705837e81 */
struct Material18 {
    u32 flags;
    char pad4[0x13];
    u8 alpha;
};

struct Material18;
/* unbake published declaration: published_d5b58f370c3ce9c39c212224 */
typedef struct Material18 Material18;

struct Group18;
/* unbake published declaration: published_0f381107e1ff494ba6c4a46b */
struct Group18 {
    char pad0[3];
    s8 mode;
    Material18 *material;
    Mesh *meshes;
    char padc[8];
    struct Group18 *next;
};

struct Item_func_8026BC60_de;
/* unbake published declaration: published_1be6df839f4a9d9e18fe60b2 */
struct Item_func_8026BC60_de {
    s32 *data;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    s32 unk18;
    struct Item_func_8026BC60_de *next;
};

struct Source_func_8026BC60_de;
/* unbake published declaration: published_c32b64573486fe510b59f3a3 */
struct Source_func_8026BC60_de {
    s32 flags;
    u16 id;
    u8 pad6[0x12];
    u16 unk18;
    u16 unk1A;
};

struct Item_func_8026BC60_de;
struct Node_func_8026BC60_de;
struct Source_func_8026BC60_de;
/* unbake published declaration: published_0f4601991c60c5af5f322bab */
struct Node_func_8026BC60_de {
    u32 key;
    struct Source_func_8026BC60_de *source;
    struct Item_func_8026BC60_de *head;
    struct Item_func_8026BC60_de *tail;
    struct Node_func_8026BC60_de *prev;
    struct Node_func_8026BC60_de *next;
    struct Node_func_8026BC60_de *left;
    struct Node_func_8026BC60_de *right;
};

/* unbake published declaration: published_1c1c01bbff894ebbf8593e2b */
extern void func_8026D980_de();

struct Material;
/* unbake published declaration: published_2edc1a47efb0915b5c6f1468 */
typedef struct Material Material;

/* unbake published declaration: published_30b80827bbd9066a3c9f00d4 */
extern void func_8026D8F8_de();

struct Item_func_8026BC60_de;
/* unbake published declaration: published_315b9fb5685de9a6cfd9fbc3 */
typedef struct Item_func_8026BC60_de Item_func_8026BC60_de;

/* unbake published declaration: published_35f2bcca153bdd52240cf840 */
extern int D_800CC360;

/* unbake published declaration: published_3cf653d93a18218ceed18b1a */
extern void func_8026D88C_de();

/* unbake published declaration: published_3f0ca835a8df8c4943254a85 */
extern float D_800C4668_de;

/* unbake published declaration: published_434ffa4a8a17018844798a75 */
extern void func_8026C020_de();

struct Source_func_8026BC60_de;
/* unbake published declaration: published_4474d32e613a6fc921bd344a */
typedef struct Source_func_8026BC60_de Source_func_8026BC60_de;

struct Owner104;
/* unbake published declaration: published_4d9b38e2a65fbf9716e822cf */
typedef struct Owner104 Owner104;

/* unbake published declaration: published_53156f512337b6ec135a1f1a */
extern int D_80137288;

/* unbake published declaration: published_60c1c622197254c22a2e809c */
extern void func_8026BC60_de();

struct Frame118;
/* unbake published declaration: published_64c3cc95ba7f9fba637d8b3d */
typedef struct Frame118 Frame118;

struct Node_func_8026BC60_de;
/* unbake published declaration: published_f5a0dba3b3af0d2f715085fe */
typedef struct Node_func_8026BC60_de Node_func_8026BC60_de;

struct Material;
/* unbake published declaration: published_9bb0e6e3f90d160ea5a6a9ee */
struct Material {
    u8 pad[6];
    u8 flags;
};

struct Owner104;
/* unbake published declaration: published_a06ff17beed598c3be57b10b */
struct Owner104 {
    char pad0[0x102];
    unsigned short flags;
};

struct Frame118;
/* unbake published declaration: published_bb201f59fb58ea9c0d21b286 */
struct Frame118 {
    char pad0[0x114];
    Gfx *commands;
};

struct Group18;
/* unbake published declaration: published_d7b966bcd12027b60306b722 */
typedef struct Group18 Group18;

/* unbake published declaration: published_dbf25b38b5de00a84eab9f5a */
extern void func_8026D83C_de(void);

/* unbake published declaration: published_de0837aed8862b181f421d76 */
extern void func_8026D844_de();

/* unbake published declaration: published_e007207fdac57b5aa077b520 */
extern void func_8026D9D0_de();

struct ObjectState18;
/* unbake published declaration: published_e9d961aab7c83d7335a09f46 */
struct ObjectState18 {
    s32 flags;
    u8 padding4[0xC];
    u8 color[4];
    u8 fog[4];
};

/* unbake published declaration: published_ec0805fdce95d38ddaca3d83 */
extern void func_8026D834_de(void);


struct Bank_func_8028B274_de;
struct Object_func_8028B274_de;
extern void func_8028B274_de(struct Bank_func_8028B274_de *, struct Object_func_8028B274_de *, s32, s32);
#endif
