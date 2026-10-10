#ifndef UNBAKE_SPAN_16E000_CODE_80423280_H
#define UNBAKE_SPAN_16E000_CODE_80423280_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Rec_func_80424B90_de;
/* unbake published declaration: published_06803c7b75ac4006055e5a6d */
typedef struct Rec_func_80424B90_de Rec_func_80424B90_de;

struct TabOptionsCommitOptions;
/* unbake published declaration: published_0a4bfa13a99ed399c8105aed */
typedef struct TabOptionsCommitOptions TabOptionsCommitOptions;

struct Rec_func_80424B90_de;
/* unbake published declaration: published_0c50a8d7256508ed654e810d */
struct Rec_func_80424B90_de {
    char pad0[2];
    s16 unk2;
    s16 unk4;
    char pad6[0x96 - 6];
};

struct CompactOptionsCommitContext;
/* unbake published declaration: published_1d9a69fee8fa1771eb5cf2c9 */
typedef struct CompactOptionsCommitContext CompactOptionsCommitContext;

struct State_func_804242D4_de;
/* unbake published declaration: published_3614b8eab5ceb6fb9775edc4 */
struct State_func_804242D4_de {
    void *first;
    char pad4[0x18 - 4];
    s32 value;
};

/* unbake published declaration: published_42d1ee0743e2e631bd1161f2 */
extern void func_80423080_de();

/* unbake published declaration: published_4cd134ba2c85d90b9c64cfa7 */
extern s32 func_80423758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct OptionsCommitContext;
/* unbake published declaration: published_67655e7487e0a35db018e9be */
struct OptionsCommitContext {
    char pad0[0x8];
    void * unk_8;
    void * unk_C;
    void * unk_10;
    void * unk_14;
};

struct OptionsBuildSettings;
/* unbake published declaration: published_72b14b3b2fcc0ada094ac5ed */
typedef struct OptionsBuildSettings OptionsBuildSettings;

/* unbake published declaration: published_757bf2e575a6bc03e10a9d08 */
extern void func_8042302C_de();

/* unbake published declaration: published_842bf1ece6c550f237046b6e */
extern s32 func_8042343C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_8b90bd446fb7c4d157df9464 */
extern s32 func_80424348_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct State_func_80423328_de;
/* unbake published declaration: published_983d20d04171430974473409 */
typedef struct State_func_80423328_de State_func_80423328_de;

/* unbake published declaration: published_98971c7ec74e734ca3d9c0ba */
extern void func_80424B90_de();

struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
struct State_func_804241BC_de;
/* unbake published declaration: published_9c915bd44326e4e970c53464 */
struct State_func_804241BC_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct Frame_func_804217D4_de *list;
    s32 opening;
    char pad10[0x14 - 0x10];
    s32 delay;
    s32 target;
};

/* unbake published declaration: published_a2cb1f67c8fe935def15f44b */
extern s32 func_804239B0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct TabOptionsCommitContext;
/* unbake published declaration: published_acf4fe81aa590565406e43ab */
struct TabOptionsCommitContext {
    char pad0[0x50];
    void * unk_50;
    void * unk_54;
    void * unk_58;
};

struct TabOptionsCommitContext;
/* unbake published declaration: published_b3125684c906ded98359a366 */
typedef struct TabOptionsCommitContext TabOptionsCommitContext;

struct State_func_80423328_de;
/* unbake published declaration: published_c53a766f254e7d6b336e1ce7 */
struct State_func_80423328_de {
    s32 unk0;
    char pad4[0x1C];
    s32 unk20;
};

struct Screen_func_80423828_de;
/* unbake published declaration: published_d27da0083895542d7c2d9a87 */
struct Screen_func_80423828_de {
    char pad0[0x1C];
    s32 shown;
    char pad20[0x30 - 0x20];
    s32 mode;
    s32 next_mode;
    char pad38[0x44 - 0x38];
    void *window;
    char pad48[0x4C - 0x48];
    void *second_window;
    char pad50[0x60 - 0x50];
    s32 timer;
};

struct TabOptionsCommitOptions;
/* unbake published declaration: published_e2af352f04afc35cf7b67f26 */
struct TabOptionsCommitOptions {
    char pad0[0x10];
    s32 position;
    char pad14[0x1B - 0x14];
    u8 first;
    char pad1C[0x580 - 0x1C];
    u8 second;
};

struct CompactOptionsCommitContext;
/* unbake published declaration: published_e9999bf9198132a2605c1276 */
struct CompactOptionsCommitContext {
    void * unk_0;
    void * unk_4;
    void * unk_8;
};

struct OptionsBuildSettings;
/* unbake published declaration: published_ed13af02a69cd77e86bde57e */
struct OptionsBuildSettings {
    char pad0[0x10];
    s32 position;
    char pad14[0x7];
    u8 first;
    char pad1C[0x3];
    u8 second;
    char pad20[0x560];
    u8 third;
};

struct OptionsCommitContext;
/* unbake published declaration: published_f79b188d82206fec506ecb0b */
typedef struct OptionsCommitContext OptionsCommitContext;

#endif
