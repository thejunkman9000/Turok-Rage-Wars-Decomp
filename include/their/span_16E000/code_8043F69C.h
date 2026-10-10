#ifndef UNBAKE_SPAN_16E000_CODE_8043F69C_H
#define UNBAKE_SPAN_16E000_CODE_8043F69C_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct Node_func_804428F8_de;
/* unbake published declaration: published_043b2f8a47ccf457a567fdbd */
typedef struct Node_func_804428F8_de Node_func_804428F8_de;

struct Entry_func_80441EB0_de;
struct List_func_80441EB0_de;
/* unbake published declaration: published_070e2cfd656ca1e28def9b73 */
struct List_func_80441EB0_de {
    struct Entry_func_80441EB0_de *entries;
    s16 count;
    char pad6[0x1A];
    s32 value;
};

struct func_8043FFAC_S2;
/* unbake published declaration: published_0e5a1ee32f7b9b635ca31be5 */
typedef struct func_8043FFAC_S2 func_8043FFAC_S2;

struct TextLayerMetrics;
/* unbake published declaration: published_15843de0411780422d617b0f */
struct TextLayerMetrics {
    int field0;
    int width;
    int height;
    int rest[7];
};

struct TextLayerMetrics;
/* unbake published declaration: published_17dd3d2cc300c82b93d0b841 */
typedef struct TextLayerMetrics TextLayerMetrics;

struct State_func_8044214C_de;
/* unbake published declaration: published_2385e9e212b68b63b86d7183 */
typedef struct State_func_8044214C_de State_func_8044214C_de;

struct LayeredText;
/* unbake published declaration: published_317d6b43f29db17b1b2c264b */
typedef struct LayeredText LayeredText;

struct LayeredText;
/* unbake published declaration: published_426f74a411d99255cb047cb4 */
struct LayeredText {
    int value;
    short mode;
    short reserved;
    int flags;
    int fieldC;
    int field10;
    int *text;
    int field18;
    int spacing;
    int field20;
    int field24;
};

struct func_8043FFAC_S2;
/* unbake published declaration: published_4aeb6cba81d665dc87f1126c */
struct func_8043FFAC_S2 {
    s16 unk0;
    char pad0[0x2E];
    f32 unk30;
    f32 unk34;
    s32 unk38;
    s32 unk3C;
};

struct State_func_804428F8_de;
/* unbake published declaration: published_a1baf179e551ec7d2ccec48f */
struct State_func_804428F8_de {
    char pad00[0xB0];
    s32 field_B0;
    s32 field_B4;
    char padB8[0xBC - 0xB8];
    s32 field_BC;
};

struct List_func_804428F8_de;
/* unbake published declaration: published_fb68549113e7d47d01dbc5ab */
typedef struct List_func_804428F8_de List_func_804428F8_de;

struct List_func_804428F8_de;
struct Node_func_804428F8_de;
struct State_func_804428F8_de;
struct Table_func_804428F8_de;
/* unbake published declaration: published_5608825387c13a5566de3d79 */
struct Node_func_804428F8_de {
    char pad00[0x8];
    s32 handle;
    char pad0C[0x14 - 0xC];
    struct Table_func_804428F8_de *table;
    char pad18[0x20 - 0x18];
    struct State_func_804428F8_de *state;
    char pad24[0x28 - 0x24];
    s16 kind;
    char pad2A[0x1D4 - 0x2A];
    struct Node_func_804428F8_de *next;
};

/* unbake published declaration: published_babba732ab8b06635aeedb97 */
struct List_func_804428F8_de {
    struct Node_func_804428F8_de *head;
    char pad04[0x10 - 0x4];
    s32 flag;
};

struct Table_func_804428F8_de {
    char pad00[0xC];
    void (*handler)(Node_func_804428F8_de *, List_func_804428F8_de *);
};
struct Item_func_80441FE8_de;
/* unbake published declaration: published_5ac626d1b63214553b13e1eb */
typedef struct Item_func_80441FE8_de Item_func_80441FE8_de;

struct Params_func_804427C4_de;
/* unbake published declaration: published_5eeada745599afce8216f77b */
struct Params_func_804427C4_de {
    char pad[0x14];
    s32 a;
    s32 pad18;
    s32 b;
    s32 c;
    s32 d;
};

struct State_func_804428F8_de;
/* unbake published declaration: published_6068f610f9cb5035c7eb131c */
typedef struct State_func_804428F8_de State_func_804428F8_de;

struct Params_func_80442690_de;
/* unbake published declaration: published_62dd14abb079c2669ee387bb */
struct Params_func_80442690_de {
    char pad[0x18];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
};

struct func_8043FFAC_S4;
/* unbake published declaration: published_6a3da065c4842a68cb05795e */
struct func_8043FFAC_S4 {
    s32 unk0;
    char pad0[0x8];
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 pad1B;
};

struct MenuRules;
struct Outer;
/* unbake published declaration: published_9954cf370044cd4ba661e761 */
struct Outer {
    char pad[0x14];
    struct MenuRules *inner;
};

struct Outer;
/* unbake published declaration: published_6c9f4b0c7b75d21e26875cdb */
extern s32 func_804423AC_de(struct Outer *outer);

struct Entry_func_804410AC_de;
struct MenuRules;
/* unbake published declaration: published_de652fe8c7d1f6e11ee527d8 */
struct Entry_func_804410AC_de {
    char pad0[8];
    s32 flags;
    char pad0C[4];
    s8 back[4];
    char pad14[4];
    struct MenuRules *target;
    char pad1C[0xC];
};

struct Entry_func_804410AC_de;
struct Menu_func_804410AC_de;
/* unbake published declaration: published_6f928b2268bf61502e83c39a */
struct Menu_func_804410AC_de {
    s16 cursor;
    char pad2[0xA];
    struct Entry_func_804410AC_de *entries;
    s32 count;
};

struct Model_func_8044214C_de;
/* unbake published declaration: published_b0badffe398891f9e56f1103 */
typedef struct Model_func_8044214C_de Model_func_8044214C_de;

struct Model_func_8044214C_de;
/* unbake published declaration: published_e1094a1d75933c81a39d4d1c */
struct Model_func_8044214C_de {
    float x;
    float y;
    float depth;
    char padc[8];
    float dx;
    float dy;
    float dz;
    char pad20[0xD4];
    float size;
    char padf8[0x90];
};

struct State_func_8044214C_de;
/* unbake published declaration: published_aa9e1325c2fbec0c187b1c14 */
struct State_func_8044214C_de {
    int selection;
    Model_func_8044214C_de model;
    char pad18c[0x2EC];
    int active;
    float size;
};

struct State_func_8044214C_de;
struct Widget_func_8044214C_de;
/* unbake published declaration: published_700a14e8f068f58d7cfde1d0 */
struct Widget_func_8044214C_de {
    char pad[0x20];
    struct State_func_8044214C_de *state;
};

struct Node_func_804429D4_de;
/* unbake published declaration: published_730010e057e37ed1c88e1f07 */
struct Node_func_804429D4_de {
    char pad0[0x14];
    void **vtable;
    char pad18[0x1B8];
    struct Node_func_804429D4_de *next;
};

struct Widget_func_8044214C_de;
/* unbake published declaration: published_75048687b1600994328aa7fa */
typedef struct Widget_func_8044214C_de Widget_func_8044214C_de;

struct Node_func_80442A28_de;
/* unbake published declaration: published_8056e8896dbc131035baa742 */
struct Node_func_80442A28_de {
    char pad0[0x28];
    short kind;
    char pad1[0x1A8];
    struct Node_func_80442A28_de *next;
};

struct Node_func_804429D4_de;
struct Owner_func_804429D4_de;
/* unbake published declaration: published_8c0b67e5869f1e7ddffaa5f0 */
struct Owner_func_804429D4_de {
    char pad[4];
    struct Node_func_804429D4_de *head;
};

struct func_8043FFAC_S5;
/* unbake published declaration: published_9316966ba8a744de9dcf6c36 */
typedef struct func_8043FFAC_S5 func_8043FFAC_S5;

struct Object_func_804420B4_de;
/* unbake published declaration: published_a7b00f001fca13e6d78aa28b */
struct Object_func_804420B4_de {
    char pad[0x17];
    u8 character;
};

struct Item_func_80441FE8_de;
/* unbake published declaration: published_c833319cc5f279b22ff66284 */
struct Item_func_80441FE8_de {
    int unk0;
    short type;
    char pad6[0xE];
    u8 **text;
};

struct Node_func_80442A28_de;
/* unbake published declaration: published_d87125e14130ab82b23c66ee */
typedef struct Node_func_80442A28_de Node_func_80442A28_de;

struct func_8043FFAC_S4;
/* unbake published declaration: published_ec8208c3adadc60c6fecba92 */
typedef struct func_8043FFAC_S4 func_8043FFAC_S4;

/* unbake published declaration: published_ed52fb4d69212af0b02833b0 */
extern float func_8044222C_de(int c, unsigned char next, float sx, float sy);

struct List_func_80441EB0_de;
struct Params_func_80441EB0_de;
/* unbake published declaration: published_f50218950d878df7f64682f6 */
struct Params_func_80441EB0_de {
    char pad[0x18];
    struct List_func_80441EB0_de *list;
    s32 b;
    s32 c;
    s32 d;
};

struct func_8043FFAC_S5;
/* unbake published declaration: published_f692aedc4b9e5024eec400bd */
struct func_8043FFAC_S5 {
    s32 unk0;
    char pad0[0x10];
    s32 unk14;
    char pad14[0x4];
    s32 unk1C;
};

struct func_802285C4_S1;
/* unbake published declaration: published_fa55c34a40ac684eb8e4e5c0 */
extern char *func_80442214_de(struct func_802285C4_S1 *object);

#endif
