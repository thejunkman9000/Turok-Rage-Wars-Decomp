#ifndef UNBAKE_SPAN_16E000_CODE_804196C0_H
#define UNBAKE_SPAN_16E000_CODE_804196C0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct func_80419D04_S1;
/* unbake published declaration: published_01d87bbdd805a4c0831b5ded */
struct func_80419D04_S1 {
    char pad0[0x4];
    u8 unk4;
    char pad4[0x3F];
    s32 unk44;
    s32 unk48;
    s32 unk4C[5];
    s32 unk60[5];
    s32 unk74;
    char pad78[0x8];
    s32 unk80;
};

struct Record_func_8041A280_de;
/* unbake published declaration: published_060d90221fa638c18235c469 */
struct Record_func_8041A280_de {
    char pad0[0xC];
    s16 field_0C;
    s16 field_0E;
    char pad10[0x12 - 0x10];
    s16 field_12;
    char pad14[0x20 - 0x14];
    s32 field_20;
    f32 field_24;
    char pad28[0x2C - 0x28];
    u32 colours[4];
    char pad3C[0x44 - 0x3C];
    struct Record_func_8041A280_de *frame;
    struct Record_func_8041A280_de *item;
    f32 scaleX;
    f32 scaleY;
    char pad54[0x60 - 0x54];
    u32 copies[4];
    u32 greenStep;
    u32 redStep;
    s32 active;
};

struct Animation;
/* unbake published declaration: published_09747a96bafe283d128f836f */
typedef struct Animation Animation;

struct Object_func_80419F58_de;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_10798e53457e41f831174d6f */
struct Object_func_80419F58_de {
    char pad0[0x44];
    s32 busy;
    char pad48[0x4C - 0x48];
    s32 entries[(0x74 - 0x4C) / 4];
    s32 index;
    struct Resource_func_80419E54_de *target;
};

/* unbake published declaration: published_137f6ced39d1425f5bcc049e */
extern float D_800E1470;

struct FrameSequence_func_804199DC_de;
/* unbake published declaration: published_15eebe4e0389b029a05a1151 */
struct FrameSequence_func_804199DC_de {
    char pad0[0x44];
    void *target;
    s32 *frames;
    s32 frame;
    s32 count;
    s32 elapsed;
    s32 duration;
    s32 unk5C;
    s32 loops;
};

/* unbake published declaration: published_1fac1ce263db6ea0fa858e5b */
extern void func_8041A400_de();

/* unbake published declaration: published_25776c13cf388022d693ebf2 */
extern s32 func_80419F9C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_2841aaefce60f88bceda7422 */
extern float D_800E1474;

struct Animation;
/* unbake published declaration: published_297e9dc51cb52156c45a661d */
struct Animation {
    char pad0[0xC];
    s16 kindA;
    s16 kindB;
    char pad10[2];
    s16 flags;
    char pad14[0x30];
    s32 widget;
    s32 *frames;
    char pad4C[4];
    s32 count;
    s32 unk54;
    char pad58[4];
    s32 unk5C;
    char pad60[4];
};

struct Object_func_80419F38_de;
/* unbake published declaration: published_2c8e54914d75aeed318e0612 */
struct Object_func_80419F38_de {
    char pad0[0x44];
    s32 busy;
    char pad48[0x84 - 0x48];
    s32 pending;
};

struct FrameSequence_func_804199DC_de;
/* unbake published declaration: published_45def24525cf751dabd044ce */
extern s32 func_804199F8_de(struct FrameSequence_func_804199DC_de *sequence);

struct Record_func_8041A280_de;
/* unbake published declaration: published_513c889c4b1adad743c0fd9a */
typedef struct Record_func_8041A280_de Record_func_8041A280_de;

/* unbake published declaration: published_5ca69737dce68c455716498f */
extern void func_8041989C_de();

struct Object_func_80419F38_de;
/* unbake published declaration: published_6082eb3effaf094aeb17c3f7 */
extern s32 func_80419F38_de(struct Object_func_80419F38_de *object);

/* unbake published declaration: published_813b39b60e19f734ee9ac698 */
extern s32 func_80419A4C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Triple;
/* unbake published declaration: published_86a6c048e10bc58e9a49a984 */
extern void func_80419ADC_de(s32 arg0, struct Triple arg1);

struct FrameSequence_func_804199DC_de;
/* unbake published declaration: published_8f4fddc1c2f0ec13059a8918 */
extern s32 func_80419A0C_de(struct FrameSequence_func_804199DC_de *sequence);

/* unbake published declaration: published_930a823379bc9bb8e426e198 */
extern void func_80419E24_de();

struct Resource_func_80419E54_de;
struct Source_func_80419F24_de;
/* unbake published declaration: published_957ef1db4481565d81c29c86 */
struct Source_func_80419F24_de {
    char pad[0x78];
    struct Resource_func_80419E54_de *target;
    char pad7C[0x83 - 0x7C];
    u8 value;
    s32 pending;
};

struct Triple;
/* unbake published declaration: published_9727ed7ad42a827e88a359ce */
extern void func_8041A02C_de(s32 arg0, struct Triple arg1);

struct Object_func_80419E54_de;
/* unbake published declaration: published_d9c444528dcef248634dc5e0 */
typedef struct Object_func_80419E54_de Object_func_80419E54_de;

struct Source_func_80419F24_de;
/* unbake published declaration: published_e0b38653856760aa63ef3f2d */
extern void func_80419F24_de(struct Source_func_80419F24_de *source);

struct func_80419D04_S1;
/* unbake published declaration: published_e3aa35677785bc7fe0a77ab3 */
typedef struct func_80419D04_S1 func_80419D04_S1;

struct FrameSequence_func_804199DC_de;
/* unbake published declaration: published_e3b33ceb5be3a825c854e479 */
extern s32 func_804199EC_de(struct FrameSequence_func_804199DC_de *sequence);

struct Object_func_80419E54_de;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_ef8fef4af4286e657d80adb1 */
struct Object_func_80419E54_de {
    char pad0[0xC];
    short a;
    short b;
    short pad1;
    short c;
    char pad2[0x64];
    struct Resource_func_80419E54_de *resource;
    int pad3;
    union
  {
    int value;
    unsigned char bytes[4];
  } owner;
    int pad4;
};

extern void func_80419B18_eu_x(void);
#endif
