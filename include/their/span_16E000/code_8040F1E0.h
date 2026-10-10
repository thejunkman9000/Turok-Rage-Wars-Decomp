#ifndef UNBAKE_SPAN_16E000_CODE_8040F1E0_H
#define UNBAKE_SPAN_16E000_CODE_8040F1E0_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Slot_func_80411518_de;
/* unbake published declaration: published_284fcfe1210e7334d0e1bce9 */
struct Slot_func_80411518_de {
    char pad0[8];
    u16 flags;
    char padA[2];
    char data[0x20];
};

struct Entry_func_80411518_de;
struct Slot_func_80411518_de;
struct Entry_func_80411518_de {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct Slot_func_80411518_de **ns;
    char pad488[4];
    func_802B67B0_S2 *def;
    char pad490[0xC];
};
struct Entry_func_80411518_de;
struct Pool_func_80411518_de;
/* unbake published declaration: published_0006d09a1763606633a50b11 */
struct Pool_func_80411518_de {
    s16 count;
    char pad2[6];
    struct Entry_func_80411518_de *entries;
};

struct Usage;
/* unbake published declaration: published_03c2a290dbe4dd49894a495a */
struct Usage {
    s32 expiry;
    u16 count;
    u16 pad6;
};

/* unbake published declaration: published_0864cfe45541cd21522257b5 */
extern void func_80411A3C_de(void);

struct Entry_func_80410674_de;
/* unbake published declaration: published_0e36b67edf93b5254d64d6ac */
typedef struct Entry_func_80410674_de Entry_func_80410674_de;

/* unbake published declaration: published_102ccce939f0e6471030d4a3 */
extern void func_8040F208_de(void *object, int value);

struct Slot_func_8040F580_de;
/* unbake published declaration: published_10d7bbb7b36749a3808225a4 */
struct Slot_func_8040F580_de {
    char pad0[4];
    s32 owner;
    u16 flags;
    char padA[2];
    char data[0x20];
};

/* unbake published declaration: published_11b3a4057917fa30653c8192 */
extern void func_804101BC_de();

struct Chunk_func_804101BC_de;
/* unbake published declaration: published_11f491cae917f71248997dc1 */
struct Chunk_func_804101BC_de {
    char pad[0x484];
    void **primary;
    void **optional;
    char rest[0x10];
};

/* unbake published declaration: published_1887ffb28a3d109738575709 */
extern void func_8040F210_de(void *object, int value);

struct Resource_func_80410E1C_de;
struct Resource_func_80410E1C_de {
    void *data;
    s32 flags;
    char pad8[0x14];
};
struct Timer_func_80410E1C_de;
struct Timer_func_80410E1C_de {
    s32 owner;
    s16 delay;
};
struct Pool_func_80410E1C_de;
struct Resource_func_80410E1C_de;
struct Timer_func_80410E1C_de;
/* unbake published declaration: published_1c324e14701656de52ba83b6 */
struct Pool_func_80410E1C_de {
    s16 count;
    struct Resource_func_80410E1C_de *resources;
    s32 unk8;
    struct Timer_func_80410E1C_de *timers;
};

struct Field_u16_14;
/* unbake published declaration: published_1ede33c13f0680bf58214cda */
extern int func_8040F570_de(struct Field_u16_14 *a, struct Field_u16_14 *b);

/* unbake published declaration: published_22251c56f2385ceb0bd78658 */
extern void func_8040F568_de();

/* unbake published declaration: published_24813cee607d8d53543fa21a */
extern int D_80153C08;

/* unbake published declaration: published_2a348020c429d089dd627a8b */
extern s32 func_8040F160_de(s32 font, u8 *text, s32 length);

/* unbake published declaration: published_2a44faf18ff6e9efeb088173 */
extern void func_80411518_de(s32 index);

struct Record_func_80411A84_de;
/* unbake published declaration: published_2c22a657a0f7b78bbfc6a194 */
struct Record_func_80411A84_de {
    char pad0[0xA];
    s16 a;
    s16 c;
    char padE[28 - 0xE];
};

struct Quad_func_8040F218_de;
/* unbake published declaration: published_32f0bb0982ba1ebc77234a9e */
struct Quad_func_8040F218_de {
    char pad[0x2C];
    s32 values[4];
};

/* unbake published declaration: published_34edb256ed56416fbc8b308a */
extern s32 func_80411A74_de(void);

struct Pool_func_80411518_de;
/* unbake published declaration: published_4d916a0c35637e5d3ba6f97c */
typedef struct Pool_func_80411518_de Pool_func_80411518_de;

struct Widget_func_8040F230_de;
/* unbake published declaration: published_4f749df5d660eb50eb06ec52 */
typedef struct Widget_func_8040F230_de Widget_func_8040F230_de;

/* unbake published declaration: published_54c578bb597b50c3f9b15354 */
extern void func_80410448_de();

struct Glyph;
/* unbake published declaration: published_581b1892e540aaf16e15f8f5 */
struct Glyph {
    s8 width;
    char pad[7];
};

struct Slot_func_80411518_de;
/* unbake published declaration: published_589f3c8c5e2af3a5c70499a5 */
typedef struct Slot_func_80411518_de Slot_func_80411518_de;

struct Glyph;
/* unbake published declaration: published_67293df298bc84f6a358bdb8 */
typedef struct Glyph Glyph;

struct State_func_804101BC_de;
/* unbake published declaration: published_6ab84d8f8458ee7c8f229f38 */
struct State_func_804101BC_de {
    void *active;
    char pad[0x25C];
    void *resource;
    char pad264[0xC];
    s16 count;
};

/* unbake published declaration: published_6be5ca8dcec2a45f3f0fc523 */
extern s16 func_80411AA8_de(s32 index);

struct Entry_func_8040F580_de;
struct Slot_func_8040F580_de;
struct Entry_func_8040F580_de {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct Slot_func_8040F580_de **pages;
    char pad488[4];
    func_802B67B0_S2 *def;
    unsigned char refCount;
    char pad491[0xB];
};
struct Entry_func_8040F580_de;
struct Pool_func_8040F580_de;
/* unbake published declaration: published_6d00f2079521ae0d6ead164c */
struct Pool_func_8040F580_de {
    s16 count;
    char pad2[6];
    struct Entry_func_8040F580_de *entries;
};

struct Style;
/* unbake published declaration: published_728afe58c5feac493cabc624 */
struct Style {
    f32 scaleX;
    f32 scaleY;
    s32 v[5];
};

struct Widget_func_8040F6DC_de;
/* unbake published declaration: published_72eb8aef136018447f0868f4 */
struct Widget_func_8040F6DC_de {
    s32 name;
    struct Widget_func_8040F6DC_de *next;
    struct Widget_func_8040F6DC_de *children;
    char padC[2];
    u16 type;
    char pad10[2];
    u16 flags;
    char pad14[0x18];
    s32 words[4];
    char pad3C[8];
    s32 extra;
};

/* unbake published declaration: published_7989e469fab37721f662ce37 */
extern s16 func_80411A44_de(void);

struct FileHeader;
/* unbake published declaration: published_7c6d2b8bcb1c9f58d596d332 */
typedef struct FileHeader FileHeader;

struct Entry_func_80410674_de;
/* unbake published declaration: published_c66c2de8bb121f4ebf0f3a06 */
struct Entry_func_80410674_de {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

struct Entry_func_80410674_de;
struct FileHeader;
/* unbake published declaration: published_87696489dbb70f4aae4cd307 */
struct FileHeader {
    char pad0[0x25C];
    struct Entry_func_80410674_de *unk25C;
};

struct Widget_func_8040F6DC_de;
/* unbake published declaration: published_8f2a7e985dc7ed7b9c5564bd */
typedef struct Widget_func_8040F6DC_de Widget_func_8040F6DC_de;

struct Pair2C;
/* unbake published declaration: published_fb430193d0dd7a28b391da97 */
struct Pair2C {
    char pad[0x2C];
    u8 first;
    u8 second;
};

struct Pair2C;
/* unbake published declaration: published_96550baa552695b7510f6f28 */
extern void func_8040F1FC_de(struct Pair2C *record, u8 first, u8 second);

/* unbake published declaration: published_a06781be39636157c3b08813 */
extern s16 func_80411A84_de(s32 index);

struct Usage;
/* unbake published declaration: published_a0d766f808a4b40c84e787fe */
typedef struct Usage Usage;

struct Font_func_8040F160_de;
/* unbake published declaration: published_a4875c17a7b50b6b28ad9ee4 */
struct Font_func_8040F160_de {
    char pad[8];
    Glyph glyphs[1];
};

struct Slot_func_8040F580_de;
/* unbake published declaration: published_ac1d5f4824a968c4bcb85c8e */
typedef struct Slot_func_8040F580_de Slot_func_8040F580_de;

struct Style;
/* unbake published declaration: published_b4d9c120dee089f55b6fe308 */
typedef struct Style Style;

struct Font_func_8040F160_de;
/* unbake published declaration: published_bef7716292945c5a5bac2bc8 */
typedef struct Font_func_8040F160_de Font_func_8040F160_de;

/* unbake published declaration: published_ca165e9cb3d3ee697ce9af86 */
extern void func_8040F534_de(s32 width, s32 height);

struct Pool_func_80410E1C_de;
/* unbake published declaration: published_ce5a5ef95d62dc968be146dd */
typedef struct Pool_func_80410E1C_de Pool_func_80410E1C_de;

struct Pair14;
struct Widget_func_8040F230_de;
/* unbake published declaration: published_d84acf13645811d189702229 */
struct Widget_func_8040F230_de {
    char pad0[0x2C];
    struct Pair14 *normal;
    struct Pair14 *highlighted;
    struct Pair14 *pressed;
};

struct FileState;
/* unbake published declaration: published_da7e29631cc3fdd936346a93 */
struct FileState {
    s32 unk0;
    char pad4[0x244];
    s32 unk248;
};

struct Pool_func_8040F580_de;
/* unbake published declaration: published_dccf54c81f8849675ebf12a3 */
typedef struct Pool_func_8040F580_de Pool_func_8040F580_de;

struct FileState;
/* unbake published declaration: published_de6872a519471634c031aa77 */
typedef struct FileState FileState;

struct Quad_func_8040F218_de;
/* unbake published declaration: published_e6ffd88949c7585746bf8b82 */
extern void func_8040F218_de(struct Quad_func_8040F218_de *record, s32 first, s32 second, s32 third, s32 fourth);

/* unbake published declaration: published_ea02cac4a298fe29629e9e4e */
extern s32 func_80411ACC_de(s32 index);

struct Chunk_func_80410448_de;
struct Slot_func_8040F580_de;
struct func_802B67B0_S2;
struct Chunk_func_80410448_de {
    void *active;
    char pad4[0x480];
    struct Slot_func_8040F580_de **slots;
    char pad488[4];
    struct func_802B67B0_S2 *header;
    u8 live;
    char pad491[0xB];
};
struct Chunk_func_80410448_de;
struct Entry_func_804101BC_de;
struct Resource_func_804101BC_de;
struct State_func_80410448_de;
/* unbake published declaration: published_efb1a9887840ffe006766164 */
struct State_func_80410448_de {
    char pad0[0x25C];
    s16 count;
    struct Entry_func_804101BC_de *entries;
    char pad264[4];
    struct Resource_func_804101BC_de *resources;
    char pad26C[4];
    s16 chunkCount;
    char pad272[6];
    struct Chunk_func_80410448_de *chunks;
    char pad27C[0x28];
    s32 locked;
};

#endif
