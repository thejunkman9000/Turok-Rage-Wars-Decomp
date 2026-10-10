#ifndef UNBAKE_SPAN_1000_CODE_8023D370_H
#define UNBAKE_SPAN_1000_CODE_8023D370_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Output;
/* unbake published declaration: published_00e661449e62a0aebf55af1f */
typedef struct Output Output;

struct func_8023EBC4_S1;
/* unbake published declaration: published_02219137c5c2c0d8f511db8e */
struct func_8023EBC4_S1 {
    s32 unk0;
    char pad0[0x88 - 0x0 - sizeof(s32)];
    s32 unk88;
    char pad88[0x9C - 0x88 - sizeof(s32)];
    s32 unk9C;
    char pad9C[0xB0 - 0x9C - sizeof(s32)];
    s32 unkB0;
    char padB0[0xC4 - 0xB0 - sizeof(s32)];
    s32 unkC4;
    char padC4[0xFC - 0xC4 - sizeof(s32)];
    s32 unkFC;
    char padFC[0x100 - 0xFC - sizeof(s32)];
    s32 unk100;
};

struct Ray;
/* unbake published declaration: published_07fede828375b3bb3bd2b420 */
typedef struct Ray Ray;

struct Polygon_func_8023E178_de;
/* unbake published declaration: published_08d518766fc7f4b9de04891d */
struct Polygon_func_8023E178_de {
    s32 type;
    s32 pad4;
    s32 kind;
    char padC[0x8];
    s32 flag;
    Vec3 point;
    char pad24[0x24];
    Vec3 normal;
    char pad54[0x78];
    f32 t;
    Vec3 hit;
};

struct Dst;
/* unbake published declaration: published_09a1db62808ed3f5d81bc403 */
typedef struct Dst Dst;

struct Polygon;
/* unbake published declaration: published_1589851ef205b1d2431a4a52 */
typedef struct Polygon Polygon;

struct Ray;
/* unbake published declaration: published_158f8fc6195180f5a0682ad5 */
struct Ray {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    Vec3 dir;
    char pad68[0x114];
    f32 nearest;
};

/* unbake published declaration: published_16c0f5387f2184cbb7e6da9b */
extern float D_800C87C0;

struct func_8023E844_S1;
/* unbake published declaration: published_1b278e70fbc88f78d362bc31 */
struct func_8023E844_S1 {
    char pad0[0x18C];
    int unk18C;
    char pad18C[0x190 - 0x18C - sizeof(int)];
    int unk190;
    char pad190[0x194 - 0x190 - sizeof(int)];
    int unk194;
};

struct func_8023E6C0_S1;
/* unbake published declaration: published_1d02e914bae317a0fbb9473b */
typedef struct func_8023E6C0_S1 func_8023E6C0_S1;

struct func_8023ED54_S1;
/* unbake published declaration: published_1dd1c72bb58e05878e2d0456 */
struct func_8023ED54_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    s32 unk8;
    char pad8[0xCC - 0x8 - sizeof(s32)];
    f32 unkCC;
};

struct Polygon_func_8023E8D4_de;
/* unbake published declaration: published_24da760bcc94d858391a76b5 */
struct Polygon_func_8023E8D4_de {
    s32 type;
    s32 pad4;
    s32 kind;
    char padC[0xC0];
    f32 t;
    Vec3 hit;
};

struct func_8023E854_S1;
/* unbake published declaration: published_25bd7264f230f37567904e9c */
typedef struct func_8023E854_S1 func_8023E854_S1;

/* unbake published declaration: published_333a59ad283b691ee90c82de */
extern void func_8023EC54_de(void *arg0, void *arg1);

/* unbake published declaration: published_373ad1a263ef18ab39d362a1 */
extern void func_8023EE34_de(void);

struct func_8023E8A4_S1;
/* unbake published declaration: published_3c19e48bcb2e32d05ffda679 */
struct func_8023E8A4_S1 {
    char pad0[0x18C];
    Triple unk18C;
};

struct func_8023E854_S2;
/* unbake published declaration: published_404fb1f405ff1b84723a4d36 */
typedef struct func_8023E854_S2 func_8023E854_S2;

struct func_8023E8A4_S1;
/* unbake published declaration: published_41e0e253a47cbf1b4f5f2046 */
typedef struct func_8023E8A4_S1 func_8023E8A4_S1;

struct Polygon_func_8023E178_de;
/* unbake published declaration: published_95b33b4d0fced86b5b78e978 */
typedef struct Polygon_func_8023E178_de Polygon_func_8023E178_de;

struct Ray_func_8023E178_de;
/* unbake published declaration: published_42eccc0d456fcb63c8fe6eee */
struct Ray_func_8023E178_de {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    Vec3 dir;
    char pad68[0x18];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E178_de nearest;
};

struct func_8023ED54_S1;
/* unbake published declaration: published_4547cb7d8d40055c5d1183a5 */
typedef struct func_8023ED54_S1 func_8023ED54_S1;

struct Polygon_func_8023E8D4_de;
/* unbake published declaration: published_7cd7a1e1e1e022d9852b9808 */
typedef struct Polygon_func_8023E8D4_de Polygon_func_8023E8D4_de;

struct Ray_func_8023E8D4_de;
/* unbake published declaration: published_4766403059ac241f8a7b496d */
struct Ray_func_8023E8D4_de {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    char pad5C[0x24];
    f32 slack;
    char pad84[0x2C];
    Polygon_func_8023E8D4_de nearest;
};

struct Instance;
struct Instance {
    u8 pad0[0x14];
    s32 field14;
};
struct Input;
struct Instance;
/* unbake published declaration: published_4d0a5c745029443a1de67ac0 */
struct Input {
    u8 pad0[0xB0];
    s32 type;
    u8 padB4[8];
    s32 fieldBC;
    s32 fieldC0;
    u8 padC4[0x34];
    Triple vecF8;
    struct Instance *instance104;
    s32 field108;
    Block70 block10C;
    s32 field17C;
    Triple vec180;
};

struct func_8023EE50_S1;
/* unbake published declaration: published_50e2f980d66f99c2ddca7e15 */
typedef struct func_8023EE50_S1 func_8023EE50_S1;

struct Ray_func_8023E8D4_de;
/* unbake published declaration: published_51973f2e2f71e695bf65a247 */
typedef struct Ray_func_8023E8D4_de Ray_func_8023E8D4_de;

struct func_8023E844_S1;
/* unbake published declaration: published_5c952b958406cbad72fd6a6a */
typedef struct func_8023E844_S1 func_8023E844_S1;

struct func_8023EBC4_S1;
/* unbake published declaration: published_5d68537f7c168cdfc777748e */
typedef struct func_8023EBC4_S1 func_8023EBC4_S1;

/* unbake published declaration: published_6a9649f2c1fc52691dbcf38a */
extern float D_800D0648;

struct Dst;
/* unbake published declaration: published_6d711e2d81dfbf8a51257f40 */
struct Dst {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

/* unbake published declaration: published_6df3af5ce6b6b1c39e3a827f */
extern float D_800C36D8_de;

/* unbake published declaration: published_6fdc5f83b2ded35605c39456 */
extern s32 func_8023E864_de(void *arg0, void *arg1);

struct Polygon;
/* unbake published declaration: published_effecfbeb347ac6c62e9f5cd */
struct Polygon {
    s32 type;
    s32 pad4;
    s32 kind;
    char padC[0x3C];
    Vec3 normal;
    char pad54[0x78];
    f32 t;
    Vec3 hit;
};

struct Ray_func_8023DF70_de;
/* unbake published declaration: published_761f64b943082051c2452ef7 */
struct Ray_func_8023DF70_de {
    char pad0[0x44];
    Vec3 start;
    Vec3 end;
    char pad5C[0x24];
    f32 slack;
    char pad84[0x2C];
    Polygon nearest;
};

struct Range;
/* unbake published declaration: published_7ae45a128559e7e93b366077 */
struct Range {
    char pad[8];
    f32 low;
    s32 count;
    f32 high;
    f32 extra;
    f32 limit;
};

/* unbake published declaration: published_7bd638fad8909c0ec0e2ff9b */
extern void func_8023E8B4_de(void *arg0, void *arg1);

/* unbake published declaration: published_85bd02c498f634c3d5a4805c */
extern void func_8023EBFC_de(void *arg0, void *arg1);

/* unbake published declaration: published_871525af44f4b5eeeee04bef */
extern void func_8023EE00_de();

struct func_8023E854_S2;
/* unbake published declaration: published_8beffac5499fc49c24f2f7cb */
struct func_8023E854_S2 {
    char pad0[0x48];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
};

struct func_8023EE24_S1;
/* unbake published declaration: published_951b1cccbfb5ebb6b1151fb1 */
typedef struct func_8023EE24_S1 func_8023EE24_S1;

struct Instance;
struct Output;
/* unbake published declaration: published_9909d1d275e9a7e2d844a831 */
struct Output {
    struct Instance *instance0;
    s32 instanceValue4;
    Triple vec8;
    s32 field14;
    Block70 block18;
    struct Instance *instance88;
    s32 instanceValue8C;
    Triple vec90;
    u8 pad9C[0x28];
    s32 fieldC4;
    Triple vecC8;
    s32 fieldD4;
    u8 padD8[0xC];
    Triple vecE4;
    Triple vecF0;
    s32 typeFC;
    s32 field100;
};

struct Ray_func_8023E178_de;
/* unbake published declaration: published_9fd08e73c78d1225e42f9720 */
typedef struct Ray_func_8023E178_de Ray_func_8023E178_de;

struct func_8023E854_S1;
/* unbake published declaration: published_a91e5e80d6563f5234a0d06a */
struct func_8023E854_S1 {
    char pad0[0x18C];
    f32 unk18C;
    char pad18C[0x190 - 0x18C - sizeof(f32)];
    f32 unk190;
    char pad190[0x194 - 0x190 - sizeof(f32)];
    f32 unk194;
};

struct func_8023E8A4_S2;
/* unbake published declaration: published_baa08ed709f770863d7600db */
typedef struct func_8023E8A4_S2 func_8023E8A4_S2;

struct Reusable;
/* unbake published declaration: published_bdb4434cd710fb753667046c */
typedef struct Reusable Reusable;

struct func_8023E8A4_S2;
/* unbake published declaration: published_c4e542e2fd00ddbede97aa6c */
struct func_8023E8A4_S2 {
    char pad0[0x48];
    Triple unk48;
};

struct Entry_func_8023EE60_de;
/* unbake published declaration: published_d86bdb8bcfbfe1be5bdb34c2 */
typedef struct Entry_func_8023EE60_de Entry_func_8023EE60_de;

struct Dst;
struct Entry_func_8023EE60_de;
/* unbake published declaration: published_f8c5f6045a1c8356027a5589 */
struct Entry_func_8023EE60_de {
    struct Dst *dst;
    s32 val0;
    u8 pad1[3];
    u8 flag0;
    u8 pad2[3];
    u8 flag1;
    u8 pad3[3];
    u8 flag2;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 extra;
};

struct func_8023EE50_S1;
/* unbake published declaration: published_c8bd41951a8475a15b52f039 */
struct func_8023EE50_S1 {
    char pad0[0x28];
    Entry_func_8023EE60_de unk28;
};

struct Segment_func_8023E6EC_de;
/* unbake published declaration: published_ca85eadb43a8f163af8e91fd */
typedef struct Segment_func_8023E6EC_de Segment_func_8023E6EC_de;

struct func_8023EE24_S1;
/* unbake published declaration: published_d33b993eaa085bd8a913f1b0 */
struct func_8023EE24_S1 {
    unsigned int unk0;
    char pad0[0x14 - 0x0 - sizeof(unsigned int)];
    int unk14;
    char pad14[0x88 - 0x14 - sizeof(int)];
    unsigned int unk88;
    char pad88[0x9C - 0x88 - sizeof(unsigned int)];
    unsigned int unk9C;
    char pad9C[0xB0 - 0x9C - sizeof(unsigned int)];
    unsigned int unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(unsigned int)];
    unsigned int unkB4;
    char padB4[0xC4 - 0xB4 - sizeof(unsigned int)];
    unsigned int unkC4;
};

struct Segment_func_8023E6EC_de;
/* unbake published declaration: published_d3664d8879d630de0b023150 */
struct Segment_func_8023E6EC_de {
    char pad0[0x40];
    Field_f32_10 *limits;
    f32 x0;
    char pad48[4];
    f32 y0;
    f32 x1;
    f32 height;
    f32 y1;
    char pad5C[0x74 - 0x5C];
    char node[1];
};

struct Input;
/* unbake published declaration: published_d8af6577883105e6cde5a3af */
typedef struct Input Input;

/* unbake published declaration: published_db79760f3c95c410fceddd2e */
extern float D_800C87B4;

struct func_8023ED54_S2;
/* unbake published declaration: published_df448dec3efe57c4ed0f00c7 */
struct func_8023ED54_S2 {
    char pad0[0x80];
    f32 unk80;
    char pad80[0x17C - 0x80 - sizeof(f32)];
    f32 unk17C;
};

struct func_8023ED54_S2;
/* unbake published declaration: published_e05f2a1216d66407b4d79fae */
typedef struct func_8023ED54_S2 func_8023ED54_S2;

struct Reusable;
/* unbake published declaration: published_ed867c6b9c14419dcd10a9da */
struct Reusable {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
    char pad18[0x70];
    s32 unk88;
    char pad8C[0x10];
    s32 unk9C;
    char padA0[0x10];
    s32 unkB0;
    s32 unkB4;
    char padB8[0xC];
    s32 unkC4;
};

struct func_8023E6C0_S1;
/* unbake published declaration: published_f12ed234e24bd08207f4a66a */
struct func_8023E6C0_S1 {
    char pad0[0x8];
    float unk8;
    char pad8[0xC - 0x8 - sizeof(float)];
    float unkC;
    char padC[0x10 - 0xC - sizeof(float)];
    float unk10;
    char pad10[0x14 - 0x10 - sizeof(float)];
    int unk14;
    char pad14[0x18 - 0x14 - sizeof(int)];
    float unk18;
};

struct Ray_func_8023DF70_de;
/* unbake published declaration: published_fd230efef2cc7197fad1b7c4 */
typedef struct Ray_func_8023DF70_de Ray_func_8023DF70_de;

#endif
