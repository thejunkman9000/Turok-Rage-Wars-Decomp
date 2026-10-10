#ifndef UNBAKE_SPAN_1000_CODE_802412C0_H
#define UNBAKE_SPAN_1000_CODE_802412C0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
struct Ray180;
/* unbake published declaration: published_006a37321258c9d98baff2fe */
struct Ray180 {
    char pad0[0x8];
    f32 spacing;
    char padC[0x4];
    f32 length;
    char pad14[0x4];
    f32 radius;
    char pad1C[0x28];
    Vec3 start;
    Vec3 end;
    char pad5C[0x24];
    f32 scale;
    Box box;
    Vector4f rect;
    char padAC[0xD0];
    f32 nearest;
};

struct EntryC;
/* unbake published declaration: published_0240a83bd49f10aebf82a071 */
typedef struct EntryC EntryC;

struct func_80243864_S2;
/* unbake published declaration: published_036b958ec0a5aba8dc95547a */
struct func_80243864_S2 {
    char pad0[0x68];
    char unk68;
    char pad68[0xB4 - 0x68 - sizeof(char)];
    void ** unkB4;
};

struct func_80241940_S1;
/* unbake published declaration: published_03d60a930d0332502936b326 */
typedef struct func_80241940_S1 func_80241940_S1;

struct ElementE8;
/* unbake published declaration: published_0445ba05aaec1c45a7452b73 */
struct ElementE8 {
    char pad0[0xB8];
    Box box;
    char padD0[0x8];
    u16 flags;
    char padDA[0xE];
};

struct ElementE8;
/* unbake published declaration: published_88c064ad2beae4b4306f5d02 */
typedef struct ElementE8 ElementE8;

struct Hit8;
/* unbake published declaration: published_0aa573eca826d710b0163560 */
struct Hit8 {
    ElementE8 *element;
    f32 t;
};

struct ObjectState7;
/* unbake published declaration: published_0daa8274947bd1be992a3a58 */
typedef struct ObjectState7 ObjectState7;

/* unbake published declaration: published_0dadede3237207b7d92f60e2 */
extern float D_800C3744_de;

struct EntryBlock;
/* unbake published declaration: published_0fc4df5f6587136d624b1fc3 */
typedef struct EntryBlock EntryBlock;

struct Actor_func_802426CC_de;
/* unbake published declaration: published_11099269e4acc6554db9aa50 */
typedef struct Actor_func_802426CC_de Actor_func_802426CC_de;

struct Owner_func_80241BAC_de;
/* unbake published declaration: published_a7d1175aa39e3c197909e049 */
typedef struct Owner_func_80241BAC_de Owner_func_80241BAC_de;

struct Owner_func_80241BAC_de;
/* unbake published declaration: published_d6c5cbcfac500293f7f2d7e9 */
struct Owner_func_80241BAC_de {
    u8 pad0[0x18];
    u8 *entries;
};

struct Actor_func_80242288_de;
/* unbake published declaration: published_11fbb919b01f7388c817fb29 */
struct Actor_func_80242288_de {
    Owner_func_80241BAC_de *owner;
    u8 pad04[8];
    f32 fieldC;
    u8 pad10[0x30];
    void *field40;
    u8 pad44[0x18];
    f32 field5C;
    f32 field60;
    f32 field64;
};

struct Input_func_802426CC_de;
/* unbake published declaration: published_13f7fc65f0a785f3cfca728c */
typedef struct Input_func_802426CC_de Input_func_802426CC_de;

struct ContextB0;
/* unbake published declaration: published_14c68f4aaa31051fd494f5c3 */
typedef struct ContextB0 ContextB0;

struct FloatState68;
/* unbake published declaration: published_189efde190ce855a0135ddf1 */
typedef struct FloatState68 FloatState68;

struct Input_func_80242550_de;
/* unbake published declaration: published_19b5f1dcd5a1dbd62917e422 */
struct Input_func_80242550_de {
    u8 pad0[8];
    Triple position;
};

struct Ray180;
/* unbake published declaration: published_1ab74a34f06ad47143d04f5d */
typedef struct Ray180 Ray180;

struct Query_func_80241BAC_de;
/* unbake published declaration: published_1d0d334f093dd4f3b914bd48 */
typedef struct Query_func_80241BAC_de Query_func_80241BAC_de;

struct EntryC;
/* unbake published declaration: published_26d8cf1fe4b8be8064068d04 */
struct EntryC {
    void **resource;
    Vector4f *rect;
    s32 unk_8;
};

struct Shape_func_80241950_de;
/* unbake published declaration: published_2b786a0ce545213aa8096b32 */
struct Shape_func_80241950_de {
    s32 flags;
    u16 kind;
    f32 radius;
    f32 halfWidth;
    f32 height;
    f32 halfDepth;
    Vec3 center;
};

struct Query_func_80242288_de;
/* unbake published declaration: published_2cd453ab2e744498de0a1d86 */
struct Query_func_80242288_de {
    s32 word0;
    s32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    u8 pad14[0x40];
    Owner_func_80241BAC_de *owner;
    s32 index;
    u8 pad5C[0x84];
};

struct Actor_func_80242288_de;
/* unbake published declaration: published_2d65fe54b99bb75f5eeac3b0 */
typedef struct Actor_func_80242288_de Actor_func_80242288_de;

struct Footprint;
/* unbake published declaration: published_3331fc293c06699f2df510ae */
typedef struct Footprint Footprint;

/* unbake published declaration: published_37f5c593c3b9fef37d0506ee */
extern float D_800C3740_de;

struct FloatState20;
/* unbake published declaration: published_3a3afc2a286a829c2bba77cc */
struct FloatState20 {
    unsigned char padding_0[28];
    f32 unk_1C;
};

struct func_802414E4_S1;
/* unbake published declaration: published_3ad74272832fcdd7b43ba049 */
typedef struct func_802414E4_S1 func_802414E4_S1;

struct ModelF0;
/* unbake published declaration: published_3f84a15e8b5c5c399bd4df3c */
typedef struct ModelF0 ModelF0;

struct Footprint;
/* unbake published declaration: published_428cba235cd504f7268ec4eb */
struct Footprint {
    char pad0[0x18];
    Vec3 corner[4];
    f32 pad48;
    f32 winding;
};

struct func_80241940_S2;
/* unbake published declaration: published_537dfddba0383bc6c6e8942c */
typedef struct func_80241940_S2 func_80241940_S2;

struct func_80241940_S2;
/* unbake published declaration: published_5492ff9b1c2a2b781b7c3781 */
struct func_80241940_S2 {
    char pad0[0x134];
    s32 unk134;
};

struct func_80243864_S2;
/* unbake published declaration: published_54c07879638e8daca765efda */
typedef struct func_80243864_S2 func_80243864_S2;

struct Input_func_80242550_de;
/* unbake published declaration: published_5984983f1ca64f233ca6ec48 */
typedef struct Input_func_80242550_de Input_func_80242550_de;

struct ActorB0;
/* unbake published declaration: published_5d8625a8acee59c8329c17b4 */
struct ActorB0 {
    u8 pad0[0x40];
    s32 *flags;
    u8 pad44[0x68];
    u8 *data;
};

/* unbake published declaration: published_5d869b9544c66862d6d5e556 */
extern f32 func_802417C4_de(f32 *arg0);

struct FloatState68_2;
/* unbake published declaration: published_5fb610ec104daa9c40ebdeeb */
struct FloatState68_2 {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[76];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct func_80241940_S1;
/* unbake published declaration: published_6248b3b3033f3f27cbddf37f */
struct func_80241940_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x18 - 0x10 - sizeof(s32)];
    char * unk18;
    char pad18[0x5C - 0x18 - sizeof(char*)];
    Vector4f unk5C;
    char pad5C[0x6C - 0x5C - sizeof(Vector4f)];
    f32 unk6C;
};

struct Query_func_80242288_de;
/* unbake published declaration: published_62697177158b6cbfe92e4526 */
typedef struct Query_func_80242288_de Query_func_80242288_de;

struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_62e60b8daec117d0562a4691 */
extern void func_80243814_de(struct Shape_func_802764D4_de_2 *arg0, struct Shape_func_802764D4_de_2 *arg1);

struct FloatState68;
/* unbake published declaration: published_647fcf158541faf521b168c9 */
struct FloatState68 {
    unsigned char padding_0[92];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
};

struct Bounds;
/* unbake published declaration: published_6874ef701875bae26c8f6f60 */
struct Bounds {
    u8 bytes[0x60];
};

struct Entry_func_80242288_de;
/* unbake published declaration: published_a0e277e0990471795692dea9 */
struct Entry_func_80242288_de {
    u8 pad0[4];
    u16 kind;
    u8 pad6[2];
    f32 value;
};

struct Entry_func_80242288_de;
/* unbake published declaration: published_f19f9fbaa87f39470b10294c */
typedef struct Entry_func_80242288_de Entry_func_80242288_de;

struct EntryBlock;
/* unbake published declaration: published_6d443c5955d8d48c581997ca */
struct EntryBlock {
    u8 pad[0x14];
    Entry_func_80242288_de entry;
};

struct func_80241718_S1;
/* unbake published declaration: published_6f5fc7634629cc587ef1fef4 */
struct func_80241718_S1 {
    char pad0[0x1C];
    f32 unk1C;
    char pad1C[0x48 - 0x1C - sizeof(f32)];
    Vec3 unk48;
};

struct Query_func_80241BAC_de;
/* unbake published declaration: published_706af802400f22efac8513d5 */
struct Query_func_80241BAC_de {
    s32 word0;
    s32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    u8 pad14[0x40];
    void *input;
    s32 index;
    u8 pad5C[0x80];
};

struct Actor_func_802426CC_de;
/* unbake published declaration: published_73601f473afae128af98a5fe */
struct Actor_func_802426CC_de {
    u8 pad00[0x3C];
    s32 flags;
    u8 pad40[0x70];
    Query_func_80241BAC_de saved_query;
};

struct func_80241F14_S3;
/* unbake published declaration: published_7397db40595e054b3f2cd626 */
typedef struct func_80241F14_S3 func_80241F14_S3;

struct Entry_func_80242550_de;
/* unbake published declaration: published_74196441df550b6a8cf28d0d */
struct Entry_func_80242550_de {
    u8 pad0[4];
    u16 kind;
};

struct QueryE0;
/* unbake published declaration: published_7513b39de9f24a2424a753b0 */
typedef struct QueryE0 QueryE0;

struct ActorB0;
/* unbake published declaration: published_7a0c6c38405ccb885a6c4846 */
typedef struct ActorB0 ActorB0;

/* unbake published declaration: published_7cca6bce0528d911c9f46184 */
extern void func_802428D0_de(void *first, void *second);

struct ContextB0;
/* unbake published declaration: published_7ea48cbcd58ed80a6d51be33 */
struct ContextB0 {
    Ray180 *ray;
    Vec3 *start;
    Vec3 *end;
    Matrix_func_80213CF8_de matrix;
    f32 reach;
    s32 segments;
    f32 step;
    ElementE8 *element;
    s32 kind;
    char pad60[0x48];
    s32 isKind9;
    char padAC[0x4];
};

struct FloatState68_2;
/* unbake published declaration: published_856cbe29cf802bd447431e91 */
typedef struct FloatState68_2 FloatState68_2;

struct func_802414E4_S1;
/* unbake published declaration: published_8c73d365caa4fc2e49de95b4 */
struct func_802414E4_S1 {
    char pad0[0x18];
    char unk18;
    char pad18[0x48 - 0x18 - sizeof(char)];
    char unk48;
};

/* unbake published declaration: published_8dd69502a2fbcc38052476b6 */
extern void func_802428EC_de(void *arg0, void *arg1);

struct Input_func_80241BAC_de;
struct Owner_func_80241BAC_de;
/* unbake published declaration: published_8eeaab39eec2720cacd4f13c */
struct Input_func_80241BAC_de {
    u8 kind;
    u8 pad01[7];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0xC];
    f32 floor;
    u8 pad24[0x10];
    struct Owner_func_80241BAC_de *owner;
    s32 flags38;
    u8 pad3C[0xC4];
    s32 flags100;
};

struct func_80241940_S3;
/* unbake published declaration: published_9013b3b14f7838f24d620bf1 */
struct func_80241940_S3 {
    char pad0[0x10];
    f32 unk10;
    char pad10[0x54 - 0x10 - sizeof(f32)];
    f32 unk54;
};

struct func_80243864_S1;
/* unbake published declaration: published_956f89f136528c5e1090735d */
typedef struct func_80243864_S1 func_80243864_S1;

struct ObjectState7;
/* unbake published declaration: published_9acc12e0849dacd857989d43 */
struct ObjectState7 {
    char pad0[0x6];
    s8 unk_6;
};

struct Entry_func_80242550_de;
/* unbake published declaration: published_9c96c273ceb2160bceebae80 */
typedef struct Entry_func_80242550_de Entry_func_80242550_de;

/* unbake published declaration: published_ad00b8426f276ec0357b4a78 */
extern float D_800C3760_de;

struct QueryE0;
/* unbake published declaration: published_b2a31f192e82445c89c02dc8 */
struct QueryE0 {
    s32 word0;
    f32 word4;
    s32 word8;
    s32 wordC;
    s32 word10;
    s32 word14;
    Vec3 vectors[4];
    Vec3 result;
    void *input;
    s32 index;
    u8 pad5C[0x84];
};

struct Actor_func_80241BAC_de;
/* unbake published declaration: published_b3f6bfb8eb082b2149c0535b */
struct Actor_func_80241BAC_de {
    u8 pad00[0x3C];
    s32 flags;
    u8 pad40[0x1C];
    f32 move_x;
    f32 move_y;
    f32 move_z;
    u8 pad68[0x48];
    Query_func_80241BAC_de saved_query;
};

struct func_80241F14_S3;
/* unbake published declaration: published_b5b7578539cb923c56695a60 */
struct func_80241F14_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x34 - 0x4 - sizeof(s32)];
    f32 unk34;
};

struct Actor_func_80242550_de;
/* unbake published declaration: published_bd6cb5f21ae22c726da8b099 */
struct Actor_func_80242550_de {
    Owner_func_80241BAC_de *owner;
    u8 pad04[0x3C];
    s32 *flags;
    Triple previous;
    Triple position;
    Triple delta;
};

struct Actor_func_80242550_de;
/* unbake published declaration: published_be5f7a2c523b762c40d4cbc7 */
typedef struct Actor_func_80242550_de Actor_func_80242550_de;

struct Input_func_80241BAC_de;
/* unbake published declaration: published_bee7a8f1672cb9f5ae396c54 */
typedef struct Input_func_80241BAC_de Input_func_80241BAC_de;

struct Input_func_802426CC_de;
/* unbake published declaration: published_c1554220aafcd9d75d81b090 */
struct Input_func_802426CC_de {
    u8 kind;
    u8 pad01[7];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0xC];
    f32 floor;
    u8 pad24[0x10];
    void *owner;
    s32 flags38;
    u8 pad3C[0xC4];
    s32 flags100;
};

struct func_80241940_S3;
/* unbake published declaration: published_c15f199e9bd7b5f3fe6f54ec */
typedef struct func_80241940_S3 func_80241940_S3;

struct FloatState20;
/* unbake published declaration: published_c3968fdb0807ef953dbbe86e */
typedef struct FloatState20 FloatState20;

struct Actor_func_80241BAC_de;
/* unbake published declaration: published_c548edb233e76a1025c52ccd */
typedef struct Actor_func_80241BAC_de Actor_func_80241BAC_de;

struct func_80243864_S1;
/* unbake published declaration: published_d056dc4d9d884ad0e2170bb7 */
struct func_80243864_S1 {
    char pad0[0x58];
    void * unk58;
    char pad58[0x64 - 0x58 - sizeof(void*)];
    char unk64;
    char pad64[0xA4 - 0x64 - sizeof(char)];
    void * unkA4;
};

/* unbake published declaration: published_d1572cb9625ddcee70a5a4ab */
extern s32 func_80243850_de(void *arg0, void *arg1);

struct Bounds;
/* unbake published declaration: published_d68777f9f24f1b270eb03926 */
typedef struct Bounds Bounds;

struct Shape_func_80241950_de;
/* unbake published declaration: published_e0cb1ae7b2b9dfc92d73af19 */
typedef struct Shape_func_80241950_de Shape_func_80241950_de;

struct ModelF0;
/* unbake published declaration: published_e5061bd5434d867774c2f82a */
struct ModelF0 {
    s32 unk_0;
    s32 count;
    ElementE8 elements[1];
};

struct Hit8;
/* unbake published declaration: published_e6542634928440a90cd2cd26 */
typedef struct Hit8 Hit8;

struct func_80241718_S1;
/* unbake published declaration: published_e81578136d8c6845ed33fa57 */
typedef struct func_80241718_S1 func_80241718_S1;

struct func_802428DC_S2;
/* unbake published declaration: published_f18bda0b46f542a9be5ac1c2 */
typedef struct func_802428DC_S2 func_802428DC_S2;

struct func_802428DC_S2;
/* unbake published declaration: published_f9f6c367009a1cb348baea9f */
struct func_802428DC_S2 {
    char pad0[0x3C];
    int unk3C;
    char pad3C[0x5C - 0x3C - sizeof(int)];
    Vec3 unk5C;
};

#endif
