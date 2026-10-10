#ifndef UNBAKE_SPAN_1000_CODE_8025E568_H
#define UNBAKE_SPAN_1000_CODE_8025E568_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct func_802604BC_S1;
/* unbake published declaration: published_02819758a31f14332eb938c6 */
typedef struct func_802604BC_S1 func_802604BC_S1;

struct Output8025EF54;
/* unbake published declaration: published_2a2eb9deedded25a95ec7e2b */
typedef struct Output8025EF54 Output8025EF54;

struct Output8025EF54;
/* unbake published declaration: published_cdc83dd55f89fa8261367f37 */
struct Output8025EF54 {
    f32 value;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
};

/* unbake published declaration: published_18787352fdd7e12b7096f609 */
extern void func_8025EF34_de(u32 *stream, Output8025EF54 *out, s32 count);

/* unbake published declaration: published_1b93271c82023ab5196f1a69 */
extern unsigned int func_80260684_de(unsigned int value);

/* unbake published declaration: published_1bc7c35d73297edb48b03210 */
extern int func_8025E59C_de(void *arg0);

struct Stream;
/* unbake published declaration: published_1f7f797417930054505f67ba */
typedef struct Stream Stream;

struct Segment8025FFD0;
/* unbake published declaration: published_2633b1c33c6f95a8ebcab113 */
typedef struct Segment8025FFD0 Segment8025FFD0;

struct func_802604CC_S1;
/* unbake published declaration: published_291962219397ab67e232ddd6 */
struct func_802604CC_S1 {
    char * unk0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    Rec_func_8024C92C_de * unk4;
    char pad4[0x8 - 0x4 - sizeof(Rec_func_8024C92C_de*)];
    void * unk8;
    char pad8[0x18 - 0x8 - sizeof(void*)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
};

/* unbake published declaration: published_30cbba56b30eec1fd783a60a */
extern f32 func_8025F434_de(f32 amount, f32 period);

/* unbake published declaration: published_3ce980fa18ae30cdcc733ec6 */
extern float D_800C9208;

/* unbake published declaration: published_5524166dab3742327c73e6a5 */
extern float D_800C4168_de;

/* unbake published declaration: published_636473c1d76e24946114f8c4 */
extern float D_800C91F8;

/* unbake published declaration: published_67184d930d4ac38742479298 */
extern float func_80260634_de(float value, int bits);

/* unbake published declaration: published_67b4c7f31738eb0e7f358b52 */
extern void func_80260724_de(u32 arg0, u32 arg1, u32 arg2);

struct Segment8025FFD0;
/* unbake published declaration: published_71c058498749e81250acf0f5 */
struct Segment8025FFD0 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    u32 unkC;
    u8 pad10[0x24 - 0x10];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

struct Stream;
/* unbake published declaration: published_730a91d84ecf1f2848f89e0f */
struct Stream {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    float coeff[4];
    u32 unk20;
    u32 unk24;
    s32 unk28;
};

struct Decode8025EF54;
/* unbake published declaration: published_7598639328854dcddf288d01 */
struct Decode8025EF54 {
    s32 bits;
    f32 base;
    f32 range;
    s32 unused;
    u32 stream;
    s32 first_bits;
    s32 second_bits;
};

struct Curve;
/* unbake published declaration: published_7cb475e0208a5b101b9b5ca8 */
typedef struct Curve Curve;

/* unbake published declaration: published_8bde59fbb86224d79dbebb53 */
extern unsigned int func_802606A4_de(unsigned int arg0);

/* unbake published declaration: published_8cf464420d9d53416e12bd2d */
extern double D_800C40F8_de;

/* unbake published declaration: published_99e6bc882a4e9698aedf8ca5 */
extern float D_800C9200;

/* unbake published declaration: published_a36f884bdaf244f05a761365 */
extern double D_800C4100_de;

/* unbake published declaration: published_a43ab6b9961c5194e91f310b */
extern Func802608ECResult func_802608CC_de(f32 arg0, f32 arg1, f32 arg2);

struct func_802604CC_S1;
/* unbake published declaration: published_a6720ff6eb76cd341019d4d4 */
typedef struct func_802604CC_S1 func_802604CC_S1;

struct Decode8025EF54;
/* unbake published declaration: published_ab65fb419b45fdedbb6be78d */
typedef struct Decode8025EF54 Decode8025EF54;

struct Poly;
/* unbake published declaration: published_bd36bf17fb68947a13a28b29 */
struct Poly {
    float a;
    float b;
    float c;
    float d;
    u32 duration;
};

struct Poly;
/* unbake published declaration: published_d6461703cd7dbaf326d6781b */
typedef struct Poly Poly;

struct Curve;
/* unbake published declaration: published_d9fcdf72c3e321aef5c20f85 */
struct Curve {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u32 unk20;
    s32 unk24;
    s32 unk28;
};

struct func_802604BC_S1;
/* unbake published declaration: published_f0364ac7202117430ed269c4 */
struct func_802604BC_S1 {
    char pad0[0x10];
    unsigned int * unk10;
};

/* unbake published declaration: published_f705540c0fc247149b26919f */
extern void func_80260828_de(u32 *arg0, u32 arg1, u32 arg2);

#endif
