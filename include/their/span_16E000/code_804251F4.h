#ifndef UNBAKE_SPAN_16E000_CODE_804251F4_H
#define UNBAKE_SPAN_16E000_CODE_804251F4_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct State_func_80426090_de;
/* unbake published declaration: published_149d2a17b30650b6792d4c96 */
struct State_func_80426090_de {
    char p[0x78];
    u8 unk78;
    char p2[6];
    s8 unk7F;
    char p3[17];
    u8 unk91;
};

struct PresetRow;
/* unbake published declaration: published_86c849b243c2f437e2b9f84a */
typedef struct PresetRow PresetRow;

struct Preset;
/* unbake published declaration: published_3107b53ce4cc4b1066f70484 */
struct Preset {
    u8 bytes[0x2A];
};

struct Preset;
/* unbake published declaration: published_a03581e9e9c33694a1b8aad7 */
typedef struct Preset Preset;

struct PresetRow;
/* unbake published declaration: published_b4fc9db0a806de3404683fb8 */
struct PresetRow {
    Preset presets[20];
};

struct PresetTable;
/* unbake published declaration: published_26b74ecb5b68fb324b83d867 */
struct PresetTable {
    char pad0[0x16];
    PresetRow rows[1];
};

struct Arg;
struct State_func_80426090_de;
/* unbake published declaration: published_2c72e7c06a77100a18b52569 */
struct Arg {
    char p[0x18];
    func_8024DED0_S2 *unk18;
    char p2[0x5bc];
    struct State_func_80426090_de *unk5D8;
    char p3[0x26];
    InventorySlot slots[8];
};

struct func_80426270_S1;
/* unbake published declaration: published_503d00a3d9e3bf5254bbf72d */
struct func_80426270_S1 {
    char pad0[0x4];
    func_8024DED0_S2 unk4;
};

struct Player_func_80425014_de;
/* unbake published declaration: published_525e601b7dea1d57b1473452 */
struct Player_func_80425014_de {
    char pad0[0xF];
    u8 slot;
    char pad10[0x17 - 0x10];
    u8 count;
    char pad18[0x125 - 0x18];
    u8 flags[4][5];
    char pad139[0x190 - 0x139];
};

struct PresetTable;
/* unbake published declaration: published_767629d0db8c3ca85512618a */
typedef struct PresetTable PresetTable;

struct State_func_80426090_de;
/* unbake published declaration: published_90c28843677630ac3e5e4fa3 */
typedef struct State_func_80426090_de State_func_80426090_de;

struct Info_func_80426174_de;
struct Info_func_80426174_de {
    char pad[0x4C];
    unsigned char enabled[22];
    unsigned char values[22];
    unsigned char present;
    char pad79[0x18];
    unsigned char locked;
};
struct Info_func_80426174_de;
struct Player_func_80426174_de;
/* unbake published declaration: published_ab2ac7be99c25768ba7e7b53 */
struct Player_func_80426174_de {
    char pad[0x5D8];
    struct Info_func_80426174_de *info;
    char pad5DC[0x26];
    struct {
        unsigned char flag;
        unsigned char value;
    } options[22];
};

struct Arg;
/* unbake published declaration: published_e68d152a416db95919d2d05f */
typedef struct Arg Arg;

struct Player_func_80426174_de;
/* unbake published declaration: published_ea8470cd8d29f595d3da4567 */
typedef struct Player_func_80426174_de Player_func_80426174_de;

struct func_80426270_S1;
/* unbake published declaration: published_f0053f043b5a756997f28447 */
typedef struct func_80426270_S1 func_80426270_S1;

#endif
