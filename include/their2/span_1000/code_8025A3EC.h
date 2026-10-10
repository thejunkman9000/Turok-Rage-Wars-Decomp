#ifndef UNBAKE_SPAN_1000_CODE_8025A3EC_H
#define UNBAKE_SPAN_1000_CODE_8025A3EC_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
/* unbake published declaration: published_11285859b1a0bf203f660253 */
extern float D_800D0D10;

struct Record_func_8025B758_de;
/* unbake published declaration: published_483934e4e37f04a047815963 */
typedef struct Record_func_8025B758_de Record_func_8025B758_de;

struct Record_func_8025B758_de;
/* unbake published declaration: published_54258ba7b7dcb23d150105d5 */
struct Record_func_8025B758_de {
    s32 index;
    char pad04[4];
    s32 f08;
    s32 f0C;
    char pad10[4];
    s32 f14;
    char pad18[0x14];
    f32 f2C;
    char pad30[4];
    f32 f34;
    s16 f38;
    s16 f3A;
    char pad3C[4];
    s32 f40;
    char pad44[0x14];
    s32 f58;
    s32 f5C;
    char pad60[0x44];
    s32 fA4;
    char padA8[4];
    s32 fAC;
    s32 owner;
    s32 fB4;
    f32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    char padC8[4];
};

struct func_8025B778_S2;
/* unbake published declaration: published_115014568e69ed2ff5155653 */
struct func_8025B778_S2 {
    char pad0[0x4];
    Record_func_8025B758_de unk4;
};

struct func_8025BB7C_S1;
/* unbake published declaration: published_1159930aeb6411afaf27bd1e */
struct func_8025BB7C_S1 {
    char pad0[0x44];
    Triple unk44;
    char pad44[0x50 - 0x44 - sizeof(Triple)];
    int unk50;
};

struct Slot_func_8025B5F0_de;
/* unbake published declaration: published_16c7b2c1d9f89e1d5e98be65 */
typedef struct Slot_func_8025B5F0_de Slot_func_8025B5F0_de;

/* unbake published declaration: published_18b89677f5b374a4b67b54d1 */


struct Slot_func_8025BA4C_de;
/* unbake published declaration: published_8968b083a2e70141897ba1df */
struct Slot_func_8025BA4C_de {
    char pad0[8];
    s32 used;
    char pad[0x9C];
    s32 value;
    char pad2[0x20];
};

struct Header_func_8025B5F0_de;
/* unbake published declaration: published_d1b134c6fb973a3af12cc6b7 */
typedef struct Header_func_8025B5F0_de Header_func_8025B5F0_de;

struct Slot_func_8025BA4C_de;
/* unbake published declaration: published_d4e623d56009104bfd1d2cf6 */
typedef struct Slot_func_8025BA4C_de Slot_func_8025BA4C_de;

struct Header_func_8025B5F0_de;
/* unbake published declaration: published_fd46f18b809d2dffcc2acc8e */
struct Header_func_8025B5F0_de {
    char pad[0x102];
    s16 local;
};

struct Record_func_8025BA4C_de;
/* unbake published declaration: published_19645132e596f0dd062ad6a1 */
struct Record_func_8025BA4C_de {
    Header_func_8025B5F0_de *header;
    Slot_func_8025BA4C_de slots[17];
};

struct func_8025C4D4_S1;
/* unbake published declaration: published_1c30e2a566042f4ff31aefc2 */
typedef struct func_8025C4D4_S1 func_8025C4D4_S1;

struct func_8025B778_S2;
/* unbake published declaration: published_220cc41265d1d4867395c0e6 */
typedef struct func_8025B778_S2 func_8025B778_S2;

struct Owner_func_8025B5F0_de;
/* unbake published declaration: published_2611ca871cb9cc4205d0c18f */
typedef struct Owner_func_8025B5F0_de Owner_func_8025B5F0_de;

struct func_8025BB7C_S1;
/* unbake published declaration: published_263d654f927bba27b6ca9064 */
typedef struct func_8025BB7C_S1 func_8025BB7C_S1;

/* unbake published declaration: published_27ab39f0eeceb2a91f9079b3 */
extern f32 func_8025C1CC_de(f32 arg0);

struct Owner_func_8025B5F0_de;
/* unbake published declaration: published_be9f60e2b5cec068c1b92ddf */
struct Owner_func_8025B5F0_de {
    char pad[0x84];
    char sound[0x58];
    s16 samples[20];
    char pad2[(0x104 - 0xDC) - 40];
    s32 key;
};

struct Owner_func_8025B5F0_de;
struct Slot_func_8025B5F0_de;
/* unbake published declaration: published_2d12fc877125e67b86c5a07b */
struct Slot_func_8025B5F0_de {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 value;
    s32 active;
    struct Owner_func_8025B5F0_de *owner;
    char pad3[0x18];
};

/* unbake published declaration: published_2d79540d89447eac12a054bf */
extern int D_800CBB00;

struct IntegerStateB4;
/* unbake published declaration: published_2e724f553c561ed251512d20 */
struct IntegerStateB4 {
    s32 unk_0;
    s32 unk_4;
    unsigned char padding_8[8];
    s32 unk_10;
    unsigned char padding_14[60];
    s32 unk_50;
    unsigned char padding_54[88];
    s32 unk_AC;
    s32 unk_B0;
};

struct Slot_func_8025B8BC_de;
/* unbake published declaration: published_2effad6115999cf16fef1856 */
struct Slot_func_8025B8BC_de {
    char pad0[0xA8];
    s32 flags;
    char padaC[8];
    char *owner;
    char end[0x14];
};

struct Slot_func_8025BF08_de;
/* unbake published declaration: published_411c60d12e22b3df48e7efdc */
typedef struct Slot_func_8025BF08_de Slot_func_8025BF08_de;

struct func_8025C458_S1;
/* unbake published declaration: published_420e1afdca7317c7609fc0e0 */
struct func_8025C458_S1 {
    char unk0;
    char pad0[0xB0 - 0x0 - sizeof(char)];
    s32 unkB0;
    char padB0[0xC8 - 0xB0 - sizeof(s32)];
    f32 unkC8;
};

struct Slot_func_8025BDAC_de;
/* unbake published declaration: published_da39b06e9d469bbfabd03a5f */
struct Slot_func_8025BDAC_de {
    int id;
    char pad4[0x9C];
    int keyA;
    char padA4[8];
    int keyB;
    char padB0[0x1C];
};

struct Slot_func_8025BDAC_de;
/* unbake published declaration: published_fc9b69e5525cee0bb817368f */
typedef struct Slot_func_8025BDAC_de Slot_func_8025BDAC_de;

struct Obj_func_8025BDAC_de;
/* unbake published declaration: published_496edf8d89de79f019d15a12 */
struct Obj_func_8025BDAC_de {
    Header_func_8025B5F0_de *owner;
    char pad4[8];
    Slot_func_8025BDAC_de slots[16];
};

/* unbake published declaration: published_4eb8b8a771551f34260b477f */
extern f32 func_8025C2EC_de(u8 arg0, u8 arg1);

/* unbake published declaration: published_4f8b815da50fb612ba3d4e90 */
extern float D_800C9044;

struct Record_func_8025BA4C_de;
/* unbake published declaration: published_50ff856006d28b9744556670 */
typedef struct Record_func_8025BA4C_de Record_func_8025BA4C_de;

/* unbake published declaration: published_5c428a76b5cd748697dbcb2f */
extern void func_8025C438_de(void *arg0, s32 arg1);

/* unbake published declaration: published_652fdd5b4f07d5e8ba62f1a2 */
extern void func_8025C4B4_de(void *arg0, f32 arg1);

struct func_8025AA4C_S2;
/* unbake published declaration: published_6c4f9d849af6a88e297dc6ac */
typedef struct func_8025AA4C_S2 func_8025AA4C_S2;

struct Slots;
/* unbake published declaration: published_6cbd8e66adbaf8d14dd93e20 */
struct Slots {
    char pad0[0x60];
    s16 ids[16];
};

struct func_8025B718_S1;
/* unbake published declaration: published_6d1ae8da4e07f370c1280c8b */
struct func_8025B718_S1 {
    int unk0;
    char pad0[0x8 - 0x0 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x14 - 0xC - sizeof(int)];
    int unk14;
    char pad14[0x2C - 0x14 - sizeof(int)];
    float unk2C;
    char pad2C[0x34 - 0x2C - sizeof(float)];
    float unk34;
    char pad34[0x38 - 0x34 - sizeof(float)];
    short unk38;
    char pad38[0x3A - 0x38 - sizeof(short)];
    short unk3A;
    char pad3A[0x40 - 0x3A - sizeof(short)];
    int unk40;
    char pad40[0x58 - 0x40 - sizeof(int)];
    int unk58;
    char pad58[0x5C - 0x58 - sizeof(int)];
    int unk5C;
    char pad5C[0xA4 - 0x5C - sizeof(int)];
    int unkA4;
    char padA4[0xAC - 0xA4 - sizeof(int)];
    int unkAC;
    char padAC[0xB0 - 0xAC - sizeof(int)];
    int unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(int)];
    int unkB4;
    char padB4[0xB8 - 0xB4 - sizeof(int)];
    float unkB8;
    char padB8[0xBC - 0xB8 - sizeof(float)];
    int unkBC;
    char padBC[0xC0 - 0xBC - sizeof(int)];
    int unkC0;
    char padC0[0xC4 - 0xC0 - sizeof(int)];
    int unkC4;
};

struct Slot_func_8025BF08_de;
/* unbake published declaration: published_6e0738ea1b4b391418e895fb */
struct Slot_func_8025BF08_de {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 other;
    s32 active;
    Owner_func_8025B5F0_de *owner;
    s32 value;
    char pad3[0x14];
};

/* unbake published declaration: published_723bba2c95094828f4353d0e */
extern float D_800C3F68_de;

struct Slots;
/* unbake published declaration: published_da753dc32155d7c3abbcf17a */
typedef struct Slots Slots;

struct Context_func_8025AE1C_de;
/* unbake published declaration: published_ee7582da8a01e5f3c0394a36 */
struct Context_func_8025AE1C_de {
    char pad0[0x7C];
    Slots slots;
    char padFC[0x104 - 0xFC];
    s32 frame;
    char pad108[0x134 - 0x108];
    s32 track;
    char pad138[0x2B98 - 0x138];
    s32 result;
};

struct Context_func_8025AE1C_de;
struct View_func_8025AE1C_de;
/* unbake published declaration: published_7312aacc7e506b3601cb5b06 */
struct View_func_8025AE1C_de {
    s32 slot;
    s32 handle;
    s32 field8;
    s32 fieldC;
    s32 frame;
    char pad14[4];
    s32 finished;
    char pad1C[0x2C - 0x1C];
    f32 time;
    char pad30[0x38 - 0x30];
    s16 field38;
    s16 field3A;
    char pad3C[0x44 - 0x3C];
    Triple position;
    Triple *tracked;
    char pad54[0xA0 - 0x54];
    s32 hold;
    s32 flags;
    s32 trackId;
    s32 done;
    struct Context_func_8025AE1C_de *context;
    s32 fieldB4;
    char padB8[4];
    s32 followTrack;
};

struct func_8025C388_S1;
/* unbake published declaration: published_75c8cde26eb99a731008e860 */
typedef struct func_8025C388_S1 func_8025C388_S1;

/* unbake published declaration: published_78bf9666c834e755dbae7b83 */
extern float D_800C3F80_de;

struct Slot_func_8025C008_de;
/* unbake published declaration: published_7da27111b1693da0576f221b */
struct Slot_func_8025C008_de {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x50];
    s32 mask;
    s32 value;
    s32 active;
    Owner_func_8025B5F0_de *owner;
    char pad3[0x18];
};

/* unbake published declaration: published_7ed8ca2b41cd67787d74853e */
extern float D_800C3F88_de;

struct func_8025C458_S1;
/* unbake published declaration: published_82e872b9d88843573d24e428 */
typedef struct func_8025C458_S1 func_8025C458_S1;

struct Slot_func_8025C008_de;
/* unbake published declaration: published_c1c1e7935300033bc70fbe4e */
typedef struct Slot_func_8025C008_de Slot_func_8025C008_de;

struct Record_func_8025C008_de;
/* unbake published declaration: published_8519d2d1487104b73c676b88 */
struct Record_func_8025C008_de {
    Header_func_8025B5F0_de *header;
    Slot_func_8025C008_de slots[17];
};

/* unbake published declaration: published_87a171396b7bd585b04a8170 */
extern s16 func_8025C25C_de(s16 arg0, s16 arg1);

struct Slot_func_8025B8BC_de;
/* unbake published declaration: published_98817db262a07239d0592f72 */
typedef struct Slot_func_8025B8BC_de Slot_func_8025B8BC_de;

/* unbake published declaration: published_889028a9a426fc17104d508d */
extern void func_8025B8BC_de(Slot_func_8025B8BC_de *base, s16 index);

struct func_8025BB9C_S1;
/* unbake published declaration: published_8a16ae417582876c58db14a6 */
typedef struct func_8025BB9C_S1 func_8025BB9C_S1;

/* unbake published declaration: published_8b0d2555207f6a3f6dd82dad */
extern void func_8025BD00_de(void **arg0);

/* unbake published declaration: published_8d0f93ab8a382ebf99ad3dbd */
extern s32 func_8025B854_de(s32 arg0, s16 arg1);

/* unbake published declaration: published_d0bd0971d15b1c0a7365db9c */


/* unbake published declaration: published_97086d4c5cc8f647432e887c */
extern void func_8025BB3C_de(s32 a);

struct Record_func_8025BF08_de;
/* unbake published declaration: published_974c4d2b30a8ce66aa2e021a */
typedef struct Record_func_8025BF08_de Record_func_8025BF08_de;

struct func_8025BB9C_S1;
/* unbake published declaration: published_9cbb746176de05909502ccf1 */
struct func_8025BB9C_S1 {
    char pad0[0xA8];
    int unkA8;
};

struct Header_func_8025B5F0_de;
struct Record_func_8025B5F0_de;
/* unbake published declaration: published_ad466bf0195d970e7bf6ba56 */
struct Record_func_8025B5F0_de {
    struct Header_func_8025B5F0_de *header;
    Slot_func_8025B5F0_de slots[17];
};

struct Record_func_8025BF08_de;
/* unbake published declaration: published_b25d96dc8fac9746d3a20514 */
struct Record_func_8025BF08_de {
    Header_func_8025B5F0_de *header;
    Slot_func_8025BF08_de slots[17];
};

/* unbake published declaration: published_b4ad6bfd8722b66f05e99a91 */
extern float D_800C3F50_de;

struct func_8025AA4C_S1;
/* unbake published declaration: published_b8ce2814aca5017dc9fff98c */
typedef struct func_8025AA4C_S1 func_8025AA4C_S1;

struct func_8025AA4C_S2;
/* unbake published declaration: published_ba51c6c8cbca7a2927ca81bd */
struct func_8025AA4C_S2 {
    char pad0[0x128];
    f32 unk128;
    char pad128[0x12C - 0x128 - sizeof(f32)];
    f32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(f32)];
    f32 unk130;
};

struct Record_func_8025C008_de;
/* unbake published declaration: published_c1e5dfe4521dcfd7bd543c6f */
typedef struct Record_func_8025C008_de Record_func_8025C008_de;

/* unbake published declaration: published_c3cd75f8b4d1f1c9430b047c */
extern float D_800CB8E8;

struct func_8025AA4C_S1;
/* unbake published declaration: published_c51ef0cc843cc146160cbeaf */
struct func_8025AA4C_S1 {
    char pad0[0x2B98];
    char * unk2B98;
};

struct Emitter;
/* unbake published declaration: published_c530eb27e48afa6c43e4984f */
struct Emitter {
    char pad0[0x34];
    f32 level;
    char pad38[0xC];
    f32 x;
    f32 y;
    f32 z;
    char pad50[8];
    f32 distance;
    f32 lastDistance;
    char pad60[0x48];
    s32 id;
    char padAC[4];
    void *scene;
    char padB4[0xC];
    s32 reset;
};

/* unbake published declaration: published_cb88aa6162974c2a6d1678e2 */
extern float D_800C3F84_de;

struct func_8025B718_S1;
/* unbake published declaration: published_d8d40eb17ea3d2e293f4e8d7 */
typedef struct func_8025B718_S1 func_8025B718_S1;

struct Record_func_8025B5F0_de;
/* unbake published declaration: published_dd1fa05e82581e58f804b403 */
typedef struct Record_func_8025B5F0_de Record_func_8025B5F0_de;

struct func_8025C4D4_S1;
/* unbake published declaration: published_e0fec0a0cc3207388daacc40 */
struct func_8025C4D4_S1 {
    char unk0;
    char pad0[0x34 - 0x0 - sizeof(char)];
    f32 unk34;
    char pad34[0xB0 - 0x34 - sizeof(f32)];
    s32 unkB0;
    char padB0[0xB8 - 0xB0 - sizeof(s32)];
    f32 unkB8;
};

struct IntegerStateB4;
/* unbake published declaration: published_e2dc1e4fc1722d54507bd311 */
typedef struct IntegerStateB4 IntegerStateB4;

struct Context_func_8025AE1C_de;
/* unbake published declaration: published_f1fddc52b188e339c61af2ed */
typedef struct Context_func_8025AE1C_de Context_func_8025AE1C_de;

struct View_func_8025AE1C_de;
/* unbake published declaration: published_f4afd3c260668e2aa8243023 */
typedef struct View_func_8025AE1C_de View_func_8025AE1C_de;

/* unbake published declaration: published_f82a5270e2a1c8b58680cf67 */
extern float D_800C9048;

struct Emitter;
/* unbake published declaration: published_f94db4f00780b69e713d726e */
typedef struct Emitter Emitter;

struct func_8025C388_S1;
/* unbake published declaration: published_fcca454896e003ea51112293 */
struct func_8025C388_S1 {
    char pad0[0x34];
    Vec3 unk34;
    char pad34[0x44 - 0x34 - sizeof(Vec3)];
    s8 unk44;
};

struct Obj_func_8025BDAC_de;
/* unbake published declaration: published_ff2091330e213b2b7efdf424 */
typedef struct Obj_func_8025BDAC_de Obj_func_8025BDAC_de;

#endif
