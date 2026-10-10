#ifndef UNBAKE_SPAN_16E000_CODE_8040C780_H
#define UNBAKE_SPAN_16E000_CODE_8040C780_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Widget_func_8040E984_de;
/* unbake published declaration: published_005d35c3847ad474b8054e27 */
struct Widget_func_8040E984_de {
    char pad0[4];
    struct Widget_func_8040E984_de *next;
    struct Widget_func_8040E984_de *child;
    s16 id;
    u16 selector;
    char pad10[4];
    s16 x;
    s16 y;
    s16 width;
    s16 height;
};

struct Tree_func_8040EDE4_de;
/* unbake published declaration: published_03093d79b06961ba62ffb201 */
struct Tree_func_8040EDE4_de {
    struct Tree_func_8040EDE4_de *parent;
    struct Tree_func_8040EDE4_de *next;
    struct Tree_func_8040EDE4_de *child;
    short id;
};

struct Widget_func_8040E67C_de;
/* unbake published declaration: published_06324be3fe3fd2f3688a258a */
typedef struct Widget_func_8040E67C_de Widget_func_8040E67C_de;

struct Widget_func_8040F044_de;
/* unbake published declaration: published_6c3f6a8c693ee7703ae9b378 */
typedef struct Widget_func_8040F044_de Widget_func_8040F044_de;

struct Widget_func_8040F044_de;
/* unbake published declaration: published_fb173b77307d97d25107c02a */
struct Widget_func_8040F044_de {
    struct Widget_func_8040F044_de *parent;
    struct Widget_func_8040F044_de *next;
    struct Widget_func_8040F044_de *child;
    char padC[2];
    u16 type;
    char pad10[0x1C];
};

/* unbake published declaration: published_10f2cfdc28ab6554fc4ddbd5 */
extern void func_8040F044_de(Widget_func_8040F044_de *a, Widget_func_8040F044_de *b);

struct DrawArgs;
/* unbake published declaration: published_16bf3aaaeff23f6141221db2 */
typedef struct DrawArgs DrawArgs;

/* unbake published declaration: published_171312f6bc4042436aa69337 */
extern int D_800DEA6C;

struct Node_func_8040ED38_de;
/* unbake published declaration: published_18d470b8dcafccc49cb370c0 */
struct Node_func_8040ED38_de {
    struct Node_func_8040ED38_de *unk0;
    struct Node_func_8040ED38_de *unk4;
    struct Node_func_8040ED38_de *unk8;
};

/* unbake published declaration: published_1c96d7f0b05dc549f09b3ee3 */
extern void func_8040CAB0_de();

struct Node_func_8040EB48_de;
/* unbake published declaration: published_a35b9a97e4e62868872deec1 */
struct Node_func_8040EB48_de {
    struct Node_func_8040EB48_de *next;
    char pad4[0x12 - 4];
    unsigned short flags;
};

struct Node_func_8040EB48_de;
/* unbake published declaration: published_2d0cb8ebde67882a175a6b73 */
extern s32 func_8040EBAC_de(struct Node_func_8040EB48_de *node);

struct Node_func_8040EB48_de;
/* unbake published declaration: published_2f45effc97a37a4adbee44e3 */
extern s32 func_8040EB48_de(struct Node_func_8040EB48_de *node);

struct Sprite_func_8040CAB0_de;
/* unbake published declaration: published_3f5682e2387168fc32f94ef1 */
typedef struct Sprite_func_8040CAB0_de Sprite_func_8040CAB0_de;

struct Node_func_8040EF84_de;
/* unbake published declaration: published_476e09ef46a6809a4143b397 */
typedef struct Node_func_8040EF84_de Node_func_8040EF84_de;

struct Widget_func_8040CD50_de;
/* unbake published declaration: published_512a6982797e273fb85647ab */
struct Widget_func_8040CD50_de {
    char pad0[0x12];
    u16 flags;
    char pad14[0x18];
    s32 image;
};

struct Widget_func_8040CD50_de;
/* unbake published declaration: published_589c2d3f16d60de676bd50a8 */
typedef struct Widget_func_8040CD50_de Widget_func_8040CD50_de;

struct Widget_func_8040E67C_de;
/* unbake published declaration: published_d956d5f7aab851fc086db652 */
struct Widget_func_8040E67C_de {
    char pad0[0x12];
    u16 flags;
};

struct Widget_func_8040E67C_de;
/* unbake published declaration: published_5ac4794bf610253f7869abcb */
extern void func_8040E900_de(struct Widget_func_8040E67C_de *record, int enable);

struct Tree_func_8040EEA4_de;
/* unbake published declaration: published_7092c58b1c5c7859810f2189 */
struct Tree_func_8040EEA4_de {
    struct Tree_func_8040EEA4_de *parent;
    struct Tree_func_8040EEA4_de *next;
    struct Tree_func_8040EEA4_de *child;
    short id;
    short pad_0E;
    s32 pad_10;
    short field_14;
    short field_16;
};

struct Batch_func_8040CF8C_de;
/* unbake published declaration: published_71403489cb33d3ae653b0903 */
typedef struct Batch_func_8040CF8C_de Batch_func_8040CF8C_de;

struct Node_func_8040EB48_de;
/* unbake published declaration: published_865190ae73fd935b39a071a4 */
extern s32 func_8040EB68_de(struct Node_func_8040EB48_de *node);

struct Node_func_8040ED38_de;
/* unbake published declaration: published_8d7faa0443ddf491a40233cf */
typedef struct Node_func_8040ED38_de Node_func_8040ED38_de;

struct Widget_func_8040CF8C_de;
/* unbake published declaration: published_92e1044ef340eee50117de5a */
struct Widget_func_8040CF8C_de {
    char pad0[0x12];
    u16 flags;
    char pad14[0x18];
    u32 colors[4];
};

struct Node_func_8040E7FC_de;
/* unbake published declaration: published_9d310123602790f2f6267750 */
typedef struct Node_func_8040E7FC_de Node_func_8040E7FC_de;

struct Tree;
/* unbake published declaration: published_af5898f9f1608847b07f8059 */
struct Tree {
    char pad0[4];
    struct Tree *next;
    struct Tree *child;
    short id;
};

struct DrawArgs_func_8040E67C_de;
/* unbake published declaration: published_afb2cee3e23cd6e1a01f9057 */
struct DrawArgs_func_8040E67C_de {
    s32 x;
    s32 y;
    s32 flags;
    f32 scaleX;
    f32 scaleY;
    s32 v[5];
};

struct Node_func_8040EBF4_de;
/* unbake published declaration: published_c93036c8f1c616283031cce5 */
struct Node_func_8040EBF4_de {
    struct Node_func_8040EBF4_de *next;
    char pad4[0x14 - 4];
    s16 x;
    s16 y;
};

struct Node_func_8040EBF4_de;
/* unbake published declaration: published_b14727248e7451de281163eb */
extern void func_8040EBF4_de(struct Node_func_8040EBF4_de *node, s32 *x, s32 *y);

struct DrawArgs;
/* unbake published declaration: published_b2da656ff3eac1df4a82aae4 */
struct DrawArgs {
    s32 x;
    s32 y;
    s32 flags;
    f32 scaleX;
    f32 scaleY;
    u8 alpha;
    u8 pad15[3];
    s32 v[4];
};

struct Node_func_8040EB48_de;
/* unbake published declaration: published_b73774a397e7065d1148efdd */
extern s32 func_8040EB8C_de(struct Node_func_8040EB48_de *node);

struct Pair14;
/* unbake published declaration: published_b8b9336f4e6f6f319af86296 */
extern void func_8040E978_de(struct Pair14 *record, s16 first, s16 second);

struct Widget_func_8040C950_de;
struct Widget_func_8040C950_de {
    char pad0[0x14];
    s16 x;
    s16 y;
    s16 width;
    s16 height;
};
struct Slider;
struct Widget_func_8040C950_de;
/* unbake published declaration: published_de8bd231932c5d73b61cd83e */
struct Slider {
    char pad0[0x44];
    s32 min;
    s32 max;
    char pad4C[4];
    s32 value;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    struct Widget_func_8040C950_de *thumb;
    struct Widget_func_8040C950_de *fill;
    s32 flags;
};

struct Slider;
/* unbake published declaration: published_e5ec205af86cd58d3244f721 */
typedef struct Slider Slider;

/* unbake published declaration: published_b906e42639aa0d5ba452ecaf */
extern void func_8040C950_de(Slider *slider);

struct Widget_func_8040CF8C_de;
/* unbake published declaration: published_bd019de7c939396d10f336cb */
typedef struct Widget_func_8040CF8C_de Widget_func_8040CF8C_de;

struct Node_func_8040EF84_de;
/* unbake published declaration: published_ccd05843bfebe01d65326aa5 */
struct Node_func_8040EF84_de {
    char pad0[4];
    struct Node_func_8040EF84_de *left;
    struct Node_func_8040EF84_de *right;
    char padC[2];
    u16 kind;
    char pad10[2];
    u16 flags;
    char pad14[0x18];
    void *ref2C;
    void *ref30;
    void *ref34;
    void *ref38;
    char pad3C[8];
    void *ref44;
};

struct DrawArgs_func_8040E67C_de;
/* unbake published declaration: published_db8aad3633b3d303ee70634a */
typedef struct DrawArgs_func_8040E67C_de DrawArgs_func_8040E67C_de;

struct Widget_func_8040E984_de;
/* unbake published declaration: published_e06145cada2217e30a1c7b78 */
typedef struct Widget_func_8040E984_de Widget_func_8040E984_de;

/* unbake published declaration: published_cd2e07aeb182f41253a441bf */
extern void func_8040E984_de(Widget_func_8040E984_de **hit, Widget_func_8040E984_de *node, DrawArgs_func_8040E67C_de args, s32 px, s32 py);

/* unbake published declaration: published_d08a6460255bec38f9b81884 */
extern int D_8014D710;

struct Batch;
/* unbake published declaration: published_d16f395ed6721ce7bb544fa2 */
typedef struct Batch Batch;

struct Sprite_func_8040CAB0_de;
/* unbake published declaration: published_fb86da0299df93b544f19852 */
struct Sprite_func_8040CAB0_de {
    s32 glyph;
    f32 x;
    f32 y;
    s32 color;
    f32 scale;
    u16 page;
    u16 pad16;
};

struct Batch;
struct Sprite_func_8040CAB0_de;
/* unbake published declaration: published_d4655371dbea4179f8c97fa6 */
struct Batch {
    s32 pad0[4];
    struct Sprite_func_8040CAB0_de *cursor;
    s32 count;
};

/* unbake published declaration: published_e2a9c6b133a097a5b503256b */
extern void func_8040C948_de(void);

/* unbake published declaration: published_ee5cbfc4781fb5e8edb4802b */
extern void func_8040E894_de();

struct Node_func_8040E7FC_de;
/* unbake published declaration: published_f87b9e858d40f98d23abcb0b */
struct Node_func_8040E7FC_de {
    s32 unk0;
    struct Node_func_8040E7FC_de *next;
    u8 pad8[0xA];
    u16 flags;
};

struct Batch_func_8040CF8C_de;
struct Shape_typemap_165;
/* unbake published declaration: published_ffd893d6040b297aa212cc13 */
struct Batch_func_8040CF8C_de {
    struct Shape_typemap_165 area;
    void *cursor;
    s32 count;
};

#endif
