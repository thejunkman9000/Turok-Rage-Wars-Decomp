#ifndef UNBAKE_SPAN_1000_CODE_802A25C4_H
#define UNBAKE_SPAN_1000_CODE_802A25C4_H
#include "../types.h"
#include "common/draw_matrix_scratch.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "gfx.h"
#include "types.h"
struct func_802A6A44_S1;
/* unbake published declaration: published_000d7f870822fee42834fbed */
typedef struct func_802A6A44_S1 func_802A6A44_S1;

struct func_802A67D0_S2;
/* unbake published declaration: published_008f0c02f4bf38e0200d6d70 */
typedef struct func_802A67D0_S2 func_802A67D0_S2;

struct Node438C;
/* unbake published declaration: published_2b240ee930d5fec5b262eca9 */
typedef struct Node438C Node438C;

struct Node438C;
/* unbake published declaration: published_5ba614c53ea2c4f45442887e */
struct AnimationFrameDefinition;
typedef struct AnimationFrameDefinition AnimationFrameDefinition;
typedef struct AnimationFrameState AnimationFrameState;

struct AnimationFrameState;

struct AnimationFrameDefinition {
    u8 definition_prefix[0x1E];
    u8 mode;
};
struct AnimationFrameState {
    u8 node_prefix[0x2C];
    f32 endpoint;
    f32 frame;
    u8 state_between_frame_and_cache[4];
    s32 cached_frame;
};
struct Node438C {
    u8 pad0[4];
    struct Node438C *next;
    u8 pad8[8];
    f32 x;
    f32 y;
    f32 z;
    s32 a;
    s32 b;
    s32 c;
};

struct Node438C;
struct func_802A438C_S1;
/* unbake published declaration: published_036d1c7a6cc4c88e8d48daf5 */
struct func_802A438C_S1 {
    char pad0[0x40];
    struct Node438C * unk40;
    char pad40[0x48 - 0x40 - sizeof(Node438C*)];
    s32 unk48;
};

struct ObjectLinks54;
/* unbake published declaration: published_0683fb893040106b4d2b1e74 */
struct ObjectLinks54 {
    char pad0[0x8];
    char * unk_8;
    char pad8[0x28 - 0x8 - sizeof(char*)];
    f32 unk_28;
    char pad28[0x3C - 0x28 - sizeof(f32)];
    s32 unk_3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    char * unk_40;
    char pad40[0x4C - 0x40 - sizeof(char*)];
    f32 unk_4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    s32 unk_50;
};

struct State_func_802A2FA4_de;
/* unbake published declaration: published_074bd1b634f5ebafaf370a2f */
typedef struct State_func_802A2FA4_de State_func_802A2FA4_de;

struct func_802A6A14_S1;
/* unbake published declaration: published_07c377bac584634ec2e4f451 */
struct func_802A6A14_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    f32 unk14;
    char pad14[0x24 - 0x14 - sizeof(f32)];
    s32 unk24;
    char pad24[0x34 - 0x24 - sizeof(s32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
};

struct func_802A6A54_S2;
/* unbake published declaration: published_0b6a2f6e93f6bc2fe103f864 */
typedef struct func_802A6A54_S2 func_802A6A54_S2;

struct ObjectState68;
/* unbake published declaration: published_1293c3d64cffdc2bae3644f9 */
struct ObjectState68 {
    unsigned char padding_0[40];
    UnitMtx unk_28;
};

struct Shade;
/* unbake published declaration: published_13e86f0748f9f841ce6543f3 */
typedef struct Shade Shade;

struct Node802A697C;
struct State802A697C;
struct State802A697C {
    u8 pad0[4];
    struct State802A697C *next;
    struct Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};
struct Owner802A697C;
struct State802A697C;
/* unbake published declaration: published_16f4826953256702bea07668 */
struct Owner802A697C {
    u8 pad0[0x7528];
    struct State802A697C *head;
};

struct IntegerState6A94;
/* unbake published declaration: published_1c05e66987aa21ab0e18311d */
typedef struct IntegerState6A94 IntegerState6A94;

struct ObjectState68;
/* unbake published declaration: published_1d1edbf00d7f523164049e94 */
typedef struct ObjectState68 ObjectState68;

struct FloatState50;
/* unbake published declaration: published_2110b3e1239e03387011e420 */
struct FloatState50 {
    unsigned char padding_0[76];
    f32 unk_4C;
};

struct Scene_func_802A5180_de;
/* unbake published declaration: published_2218078b242094c373fa8de7 */
typedef struct Scene_func_802A5180_de Scene_func_802A5180_de;

struct Transform;
/* unbake published declaration: published_22b2680a9df0f7055970bfc7 */
struct Transform {
    char pad0[0x18];
    s16 position[3];
};

/* unbake published declaration: published_23db517e0dea0ad42e305716 */
extern void func_802A57D8_de(void);

/* unbake published declaration: published_27bb82d76b010eb69382836e */
extern void func_802A5A24_de(void *arg0, s32 arg1);

struct func_802A6A14_S1;
/* unbake published declaration: published_28fc8520f0f92535049a7330 */
typedef struct func_802A6A14_S1 func_802A6A14_S1;

struct Entity1DC;
/* unbake published declaration: published_30919526139865f6b9e4af0c */
struct Entity1DC {
    char pad[0x118];
    func_80204468_S3 *unk_118;
    char p11c[0x1f];
    u8 unk_13B;
    char p13c[0x9d];
    u8 unk_1D9;
};

struct Entity1DC;
/* unbake published declaration: published_320953b9b781c5141163a408 */
typedef struct Entity1DC Entity1DC;

struct Particle;
/* unbake published declaration: published_3544befd56dcc485b45b1ab8 */
typedef struct Particle Particle;

struct DefC;
/* unbake published declaration: published_b2feec4d35e702aa0cbe41a4 */
typedef struct DefC DefC;

struct ChildB4;
/* unbake published declaration: published_d5b148a94f6313b1cbd599ea */
typedef struct ChildB4 ChildB4;

struct DefC;
/* unbake published declaration: published_e7defe09eb3d568615ebe5ce */
struct DefC {
    int unk_0;
    f32 unk_4;
    f32 unk_8;
};

struct ChildB4;
/* unbake published declaration: published_ef1a077eb949ad92aaf19338 */
struct ChildB4 {
    int unk_0;
    struct ChildB4 *unk_4;
    f32 unk_8;
    int pc;
    f32 pos[3];
    f32 rot[3];
    f32 mat[32];
    char pa8[8];
    Entity1DC *unk_B0;
};

struct Node44;
/* unbake published declaration: published_60ca2772f7a59d5d7f3f2d8c */
struct Node44 {
    int unk_0;
    struct Node44 *unk_4;
    DefC *unk_8;
    char pc[0x10];
    Entity1DC *unk_1C;
    int p20;
    f32 unk_24;
    char p28[0x14];
    int unk_3C;
    ChildB4 *unk_40;
};

struct Node44;
/* unbake published declaration: published_9c3b1f2525213bbeae8f6d2b */
typedef struct Node44 Node44;

struct Root752C;
/* unbake published declaration: published_36eb75cbbefad46187ad37d9 */
struct Root752C {
    char pad[0x7528];
    Node44 *unk_7528;
};

/* unbake published declaration: published_37070b64c3b748993375f49f */
extern float D_800C5DC0_de;

struct func_802A41D8_S1;
/* unbake published declaration: published_37709a8f9cf13a48553e1371 */
typedef struct func_802A41D8_S1 func_802A41D8_S1;

struct Actor_func_802A274C_de;
/* unbake published declaration: published_3b1379e2d1967056ee57f50a */
typedef struct Actor_func_802A274C_de Actor_func_802A274C_de;

struct FloatStateB0;
/* unbake published declaration: published_3d38386ead1b4e9812679ac9 */
struct FloatStateB0 {
    unsigned char padding_0[172];
    f32 unk_AC;
};

struct Root752C;
/* unbake published declaration: published_3eb678251971204de09acc3a */
typedef struct Root752C Root752C;

/* unbake published declaration: published_432847e997a36415f4a98bfe */
extern void func_802A5A64_de(void *arg0);

struct ObjectLinks54;
/* unbake published declaration: published_44eaebb0d2819ee9c2b1dab2 */
typedef struct ObjectLinks54 ObjectLinks54;

struct func_802A68A0_S2;
/* unbake published declaration: published_46ac8c0ae4cdaab5ce091181 */
struct func_802A68A0_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x1C - 0x4 - sizeof(void*)];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    f32 unk24;
};

/* unbake published declaration: published_46adfdc2b421fb35dc45c275 */
extern float D_800C5E98_de;

struct Morph;
/* unbake published declaration: published_471c1d64ecc3b71e857a0ebf */
typedef struct Morph Morph;

struct func_802A438C_S1;
/* unbake published declaration: published_48aff555bca7bdd50b475004 */
typedef struct func_802A438C_S1 func_802A438C_S1;

struct Shade;
/* unbake published declaration: published_9d5d57f9e0082157b1319287 */
struct Shade {
    u8 a;
    u8 b;
    u8 g;
    u8 r;
};

struct Blend;
/* unbake published declaration: published_4a764ad24831a8bc534ad0f4 */
struct Blend {
    Shade from;
    Shade to;
    u16 first;
    u16 second;
};

struct func_802A41D8_S3;
/* unbake published declaration: published_4ec2570345a080c2ffda76f8 */
struct func_802A41D8_S3 {
    char pad0[0x1A0];
    char unk1A0;
};

struct ObjectStateB0;
/* unbake published declaration: published_4eecd6d2d37a3d5cd03ef0ef */
struct ObjectStateB0 {
    char pad0[0x10];
    Vec3 unk_10;
    char pad10[0xAC - 0x10 - sizeof(Vec3)];
    f32 unk_AC;
};

struct func_802A697C_S3;
/* unbake published declaration: published_4ffcbf6c3b522ded382478b8 */
struct func_802A697C_S3 {
    char pad0[0x1D9];
    char unk1D9;
};

struct func_802A6A54_S3;
/* unbake published declaration: published_50e783886cba417285182402 */
struct func_802A6A54_S3 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
};

struct func_802A41D8_S1;
/* unbake published declaration: published_512b11a834f524c48adab740 */
struct func_802A41D8_S1 {
    char pad0[0x10];
    func_80234DD0_S1_U260 unk10;
    char pad10[0x1C - 0x10 - sizeof(func_80234DD0_S1_U260)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
};

struct Track_func_802A274C_de;
struct Track_func_802A274C_de {
    char pad0[4];
    f32 span;
    f32 total;
};
struct Actor_func_802A274C_de;
struct Track_func_802A274C_de;
/* unbake published declaration: published_55390a206f3ac3faa7a01ba5 */
struct Actor_func_802A274C_de {
    char pad0[8];
    struct Track_func_802A274C_de *track;
    char pad12[0x18];
    f32 time;
};

struct Transform;
/* unbake published declaration: published_ba7b3b58bde0fb06ff06b7f2 */
typedef struct Transform Transform;

struct Particle;
/* unbake published declaration: published_55c23b7b83f64df94c8b172e */
struct Particle {
    char pad0[4];
    struct Particle *next;
    Transform transform;
};

struct Blend;
/* unbake published declaration: published_a4020f8ffe5077e3d4b71048 */
typedef struct Blend Blend;

struct Morph_func_802A2B58_de;
/* unbake published declaration: published_5bbd7be944116a449168aa5b */
struct Morph_func_802A2B58_de {
    s32 count;
    Blend *blends;
    Key *first;
    Key *second;
    void *firstFrame;
    void *secondFrame;
    f32 scaleS;
    f32 scaleT;
    f32 step;
};

struct FloatStateB0;
/* unbake published declaration: published_5df9b977720de001997ee1c1 */
typedef struct FloatStateB0 FloatStateB0;

struct func_802A66B4_S1;
/* unbake published declaration: published_6095d5c8b2f369f5aab87fe9 */
typedef struct func_802A66B4_S1 func_802A66B4_S1;

struct ParticleList;
/* unbake published declaration: published_61afaece61fdc999d4447fd6 */
typedef struct ParticleList ParticleList;

struct func_802A697C_S1;
/* unbake published declaration: published_6738488b5b50306ac5377528 */
struct func_802A697C_S1 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    void * unk1C;
    char pad1C[0x24 - 0x1C - sizeof(void*)];
    float unk24;
    char pad24[0x3C - 0x24 - sizeof(float)];
    int unk3C;
};

/* unbake published declaration: published_68c125299294dbb1c75e9d7c */
extern void func_802A5A54_de(void *arg0, int arg1);

struct func_802A41D8_S3;
/* unbake published declaration: published_7523a9257c3d02728e5e85c5 */
typedef struct func_802A41D8_S3 func_802A41D8_S3;

struct func_802A41D8_S2;
/* unbake published declaration: published_77a2bee88c071002bef3a984 */
struct func_802A41D8_S2 {
    char pad0[0x10];
    Vec3 unk10;
};

struct Node_func_802A2FA4_de;
/* unbake published declaration: published_81aa29f6b90bb123b8e36689 */
struct Node_func_802A2FA4_de {
    s32 unk0;
    struct Node_func_802A2FA4_de *next;
    f32 value;
};

struct func_802A41D8_S5;
/* unbake published declaration: published_88a2759eaac7ad56c4ee5662 */
struct func_802A41D8_S5 {
    char pad0[0x14];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
};

struct func_802A67D0_S2;
/* unbake published declaration: published_8aa4cfe346c09d6d87c80817 */
struct func_802A67D0_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x24 - 0x1C - sizeof(s32)];
    f32 unk24;
};

struct Particle;
struct ParticleList;
/* unbake published declaration: published_d1d46b6291c7b5e02e13d322 */
struct ParticleList {
    struct Particle *active;
    char pad4[0x10];
};

struct Particle;
struct Scene_func_802A5180_de;
/* unbake published declaration: published_8e6cc645eb40b2d099268869 */
struct Scene_func_802A5180_de {
    char pad0[0x94E0];
    ParticleList lists[10];
    char pad95A8[0x95A8 - 0x94E0 - 10 * 0x14];
    struct Particle *free;
    char pad95AC[0x95B8 - 0x95AC];
    s32 state;
};

struct func_802A6A44_S1;
/* unbake published declaration: published_939e73299db796ef878ec9ae */
struct func_802A6A44_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0xC - 0x4 - sizeof(int)];
    int unkC;
    char padC[0x10 - 0xC - sizeof(int)];
    int unk10;
};

struct func_802A68A0_S2;
/* unbake published declaration: published_96650d7d131a5c77fea464b7 */
typedef struct func_802A68A0_S2 func_802A68A0_S2;

struct FloatState50;
/* unbake published declaration: published_9d2c9ece7bc1e18d290f090e */
typedef struct FloatState50 FloatState50;

struct func_802A697C_S2;
/* unbake published declaration: published_9e3cbf6b60b2cf68f2483582 */
struct func_802A697C_S2 {
    char pad0[0x13B];
    char unk13B;
};

struct func_802A697C_S2;
/* unbake published declaration: published_a0aeadd415c2e2f16f9a8ad9 */
typedef struct func_802A697C_S2 func_802A697C_S2;

struct func_802A66EC_S1;
/* unbake published declaration: published_a99428585c75f0976cce7e26 */
typedef struct func_802A66EC_S1 func_802A66EC_S1;

struct Owner802A697C;
/* unbake published declaration: published_aabb587051f7fafb007713d5 */
typedef struct Owner802A697C Owner802A697C;

struct ObjectLinksB4;
/* unbake published declaration: published_b506dadf7708faaabbc4c574 */
struct ObjectLinksB4 {
    char pad0[0x4];
    char * unk_4;
    char pad4[0x8 - 0x4 - sizeof(char*)];
    f32 unk_8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    func_8020E674_S1_U8 unk_10;
    char pad10[0x1C - 0x10 - sizeof(func_8020E674_S1_U8)];
    f32 unk_1C;
    char pad1C[0x28 - 0x1C - sizeof(f32)];
    f32 unk_28;
    char pad28[0x68 - 0x28 - sizeof(f32)];
    f32 unk_68;
    char pad68[0xA8 - 0x68 - sizeof(f32)];
    f32 unk_A8;
    char padA8[0xAC - 0xA8 - sizeof(f32)];
    func_8022E280_S1_U744 unk_AC;
    char padAC[0xB0 - 0xAC - sizeof(func_8022E280_S1_U744)];
    s32 unk_B0;
};

struct Node_func_802A2FA4_de;
struct State_func_802A2FA4_de;
/* unbake published declaration: published_ba3493614f587952f967b7b6 */
struct State_func_802A2FA4_de {
    u8 pad0[0x1C];
    void *object;
    u8 pad20[4];
    f32 timer;
    u8 pad28[4];
    f32 count_up;
    f32 total;
    u8 pad34[8];
    u32 flags;
    struct Node_func_802A2FA4_de *nodes;
    u8 pad44[4];
    s32 active;
    f32 amount;
    s32 retries;
};

struct func_802A697C_S3;
/* unbake published declaration: published_c0fc14dc125c0e37dd4b81fc */
typedef struct func_802A697C_S3 func_802A697C_S3;

struct ObjectStateB0;
/* unbake published declaration: published_c2cf479782227822a6245a7a */
typedef struct ObjectStateB0 ObjectStateB0;

struct Blend;
struct Key;
struct Morph;
/* unbake published declaration: published_c8ba1e78919ccf2560a07a59 */
struct Morph {
    s32 count;
    struct Blend *blends;
    struct Key *first;
    struct Key *second;
    void *firstFrame;
    void *secondFrame;
};

/* unbake published declaration: published_c8e043a8c8f2e916f786cfa4 */
extern float D_800C5E90_de;

/* unbake published declaration: published_ca265700c0044527229178d8 */
extern float D_800C5E9C_de;

/* unbake published declaration: published_cd4efb78b88e6489f73a8c34 */
extern float D_800C5E94_de;

struct Vtx;
/* unbake published declaration: published_d14c0d76a8aa86adc60deb5f */
typedef struct Vtx Vtx;

struct ObjectState20;
/* unbake published declaration: published_d44ec21cb03fcb8a0c0e4fa2 */
struct ObjectState20 {
    unsigned char padding_0[8];
    f32 unk_8;
    unsigned char padding_C[16];
    u8 unk_1C;
};

/* unbake published declaration: published_d5fb73c731fb1ca458861bcb */
extern void func_802A598C_de(Owner802A697C *owner, int object);

struct Morph_func_802A2B58_de;
/* unbake published declaration: published_d645a53453bd89b3852a2a4c */
typedef struct Morph_func_802A2B58_de Morph_func_802A2B58_de;

struct func_802A6A54_S2;
/* unbake published declaration: published_d843df05176ffe2e989d6f49 */
struct func_802A6A54_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
};

struct ObjectLinksB4;
/* unbake published declaration: published_d87a55e235a2543bcf53331f */
typedef struct ObjectLinksB4 ObjectLinksB4;

struct func_802A41D8_S5;
/* unbake published declaration: published_dc8c9208cb182501b696cb5f */
typedef struct func_802A41D8_S5 func_802A41D8_S5;

struct func_802A66EC_S1;
/* unbake published declaration: published_de9ce72a60ffd40d01161c1c */
struct func_802A66EC_S1 {
    int unk0;
    char pad0[0x2588 - 0x0 - sizeof(int)];
    int unk2588;
    char pad2588[0x258C - 0x2588 - sizeof(int)];
    void * unk258C;
};

struct Vtx;
/* unbake published declaration: published_df7771c928ae03ca14c52d74 */
struct Vtx {
    s16 x;
    s16 y;
    s16 z;
    s16 flag;
    s16 s;
    s16 t;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

struct func_802A6A54_S3;
/* unbake published declaration: published_e3a8728a973917450080f9da */
typedef struct func_802A6A54_S3 func_802A6A54_S3;

struct Node_func_802A2FA4_de;
/* unbake published declaration: published_e685e2df5a3d43d8e44616fd */
typedef struct Node_func_802A2FA4_de Node_func_802A2FA4_de;

struct func_802A41D8_S2;
/* unbake published declaration: published_ed4c99949af150c623a24d58 */
typedef struct func_802A41D8_S2 func_802A41D8_S2;

/* unbake published declaration: published_ef0e94d977fda9ab87c2ed26 */
extern float D_800C5E88_de;

struct func_802A66B4_S1;
/* unbake published declaration: published_f4f97eec6e4e53e3adcb4142 */
struct func_802A66B4_S1 {
    char pad0[0x2588];
    s32 unk2588;
    char pad2588[0x258C - 0x2588 - sizeof(s32)];
    s32 unk258C;
};

struct IntegerState6A94;
/* unbake published declaration: published_f6e0de80a594e0337aea196c */
struct IntegerState6A94 {
    unsigned char padding_0[27280];
    s32 unk_6A90;
};

struct ObjectState20;
/* unbake published declaration: published_f84d44f9d985db5cbf356b07 */
typedef struct ObjectState20 ObjectState20;

/* unbake published declaration: published_fd14b892c325abac9afa5d74 */
extern Vector4f *func_802A5020_de(Vector4f *out, u32 bx, u32 by, u32 bz);

struct func_802A697C_S1;
/* unbake published declaration: published_fdcb18c30efd3c4dc3a3d6bf */
typedef struct func_802A697C_S1 func_802A697C_S1;





#endif
