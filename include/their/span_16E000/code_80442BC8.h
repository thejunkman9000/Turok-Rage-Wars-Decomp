#ifndef UNBAKE_SPAN_16E000_CODE_80442BC8_H
#define UNBAKE_SPAN_16E000_CODE_80442BC8_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "gfx.h"
struct Object1C8;
/* unbake published declaration: published_0ba1cc40c2974d91467f499c */
struct Object1C8 {
    char pad[0x1C8];
    s32 first;
    s32 second;
};

struct Descriptor_func_80442D10_de;
/* unbake published declaration: published_0cfce3c2633f6ecff03a13d2 */
struct Descriptor_func_80442D10_de {
    short type;
    short pad;
    int flags;
    unsigned short x;
    unsigned short y;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    int value;
};

struct Object_func_80442CF4_de;
/* unbake published declaration: published_6501d5b0579adff2e3f6da61 */
struct Object_func_80442CF4_de {
    char pad[0x478];
    s32 flag;
};

struct Object_func_80442CF4_de;
/* unbake published declaration: published_1a00c346a1ac0a88b73d2e38 */
extern void func_80442CF4_de(s16 *record, struct Object_func_80442CF4_de *object);

struct Obj_func_80442DDC_de;
/* unbake published declaration: published_1d3c6526b26a2bf4a23c69c8 */
struct Obj_func_80442DDC_de {
    char pad[8];
    u32 flags;
};

struct Descriptor_func_80442D10_de;
struct Widget_func_80442D10_de;
/* unbake published declaration: published_38c79dcb2b4c1fd9256fbd53 */
struct Widget_func_80442D10_de {
    int id;
    unsigned short type;
    unsigned short pad;
    int flags;
    unsigned short x;
    unsigned short y;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    int value;
    struct Descriptor_func_80442D10_de *desc;
    int index;
    void *extra;
    int arg;
};

struct Descriptor_func_80442D10_de;
/* unbake published declaration: published_61b1d56803b1da9aa9eb3563 */
typedef struct Descriptor_func_80442D10_de Descriptor_func_80442D10_de;

struct Widget_func_80442D10_de;
/* unbake published declaration: published_897762f1c9c92618e41af025 */
typedef struct Widget_func_80442D10_de Widget_func_80442D10_de;

/* unbake published declaration: published_24123e4ecd14483e803ddff5 */
extern void func_80442D10_de(Widget_func_80442D10_de *w, Descriptor_func_80442D10_de *d, char **arena, int id, int arg);

struct State_func_80442A60_de;
/* unbake published declaration: published_b27b0dd976da6e875cdc7e3d */
struct State_func_80442A60_de {
    char pad0[0xB0];
    s32 a;
    s32 b;
    s32 padB8;
    s32 c;
};

struct Handlers_func_804431E4_de;
struct Handlers_func_804431E4_de {
    char pad[0xC];
    void (*callback)();
};
struct Handlers_func_804431E4_de;
struct Object_func_804431E4_de;
struct State_func_80442A60_de;
/* unbake published declaration: published_c1b5c9cb99d35275d5481efd */
struct Object_func_804431E4_de {
    char pad[0x14];
    struct Handlers_func_804431E4_de *handlers;
    char pad18[0x20 - 0x18];
    struct State_func_80442A60_de *state;
};

struct Object_func_804431E4_de;
/* unbake published declaration: published_3dc77e7d6c110be3a2e97bd5 */
extern void func_804431E4_de(struct Object_func_804431E4_de *object);

struct Object_func_80442B88_de;
/* unbake published declaration: published_49e0f8c35997fe3555a4cb46 */
struct Object_func_80442B88_de {
    char pad[0x1C8];
    s32 count;
};

struct MenuSpriteElement;
/* unbake published declaration: published_52174a080d2563622ba30c1b */
typedef struct MenuSpriteElement MenuSpriteElement;

struct Object1C8;
/* unbake published declaration: published_521c21f4180071b167936ef3 */
extern void func_80442B5C_de(struct Object1C8 *object);

struct MenuSpriteElement;
struct Shared_HudView;
/* unbake published declaration: published_e124d66d0bb11b50ee9e9595 */
struct MenuSpriteElement {
    char pad0[0x40];
    struct Shared_HudView *owner;
    char pad44[0x184];
    s32 frame;
    s32 active;
};

/* unbake published declaration: published_59a175bd27dd4acd97c6b999 */
extern void func_80442BA8_de(MenuSpriteElement *e);

/* unbake published declaration: published_7a6f660d7957cea6364643ee */
extern void func_80443528_us_rev1(void);

struct Handlers;
struct Handlers {
    char pad[0xC];
    void (*callback)(void *, void *);
};
struct Handlers;
struct Item_func_80442A60_de;
struct State_func_80442A60_de;
/* unbake published declaration: published_90b09ba84b5d850776b07296 */
struct Item_func_80442A60_de {
    char pad0[8];
    s32 resource;
    char padC[0x14 - 0xC];
    struct Handlers *handlers;
    char pad18[0x20 - 0x18];
    struct State_func_80442A60_de *state;
};

struct Object_func_80442B88_de;
/* unbake published declaration: published_91cce1dc6d4e6d9df2304150 */
extern s32 func_80442B88_de(struct Object_func_80442B88_de *object);

struct Owner_func_80443694_de;
/* unbake published declaration: published_9e3b72ef21ab977373fceb26 */
struct Owner_func_80443694_de {
    char pad[0x698];
    s32 value;
};

struct Holder_func_80443694_de;
struct Owner_func_80443694_de;
/* unbake published declaration: published_ddae5683ba6a82066eb8aae9 */
struct Holder_func_80443694_de {
    char pad[0x1C];
    struct Owner_func_80443694_de *owner;
};

struct Holder_func_80443694_de;
/* unbake published declaration: published_9e2e3503d7fce63c8e647273 */
extern s32 func_80443694_de(void *unused, struct Holder_func_80443694_de *holder);

/* unbake published declaration: published_a40a61a01feaa7bea0fbed29 */
extern void func_804433F8_de(void);

struct Obj_func_80442DDC_de;
/* unbake published declaration: published_aaed176c9ab4d1eaa1581b00 */
typedef struct Obj_func_80442DDC_de Obj_func_80442DDC_de;

/* unbake published declaration: published_c79198d6b4e786543b323d18 */
extern s32 func_80442CD8_de(s16 *record);

struct Item_func_80442A60_de;
struct List_func_80442A60_de;
/* unbake published declaration: published_d6f6972ee20d0a9e8cc907ff */
struct List_func_80442A60_de {
    struct Item_func_80442A60_de *head;
};

struct Object_func_80442ADC_de;
/* unbake published declaration: published_e2bfb755434e191e319b1806 */
struct Object_func_80442ADC_de {
    s32 pad0;
    s16 kind;
    char pad6[0x14 - 6];
    void **target;
};

#endif
