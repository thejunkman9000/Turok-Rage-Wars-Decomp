#ifndef RESET_STORAGE_H
#define RESET_STORAGE_H
#include "types.h"
/* Storage views of measured reset and timer fields; complete objects remain unknown. */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 padding_10[4];
    s32 unk14;
    s32 unk18;
    u8 padding_1C[8];
    f32 unk24;
    s32 unk28;
    f32 unk2C;
    u8 padding_30[60];
    s32 unk6C;
    s32 unk70;
} ResetFourStorage;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 padding_10[4];
    s32 unk14;
    s32 unk18;
    u8 padding_1C[12];
    f32 unk28;
    s32 unk2C;
    f32 unk30;
    u8 padding_34[840];
    s32 unk37C;
    s32 unk380;
    u8 padding_384[4];
    s32 unk388;
    s32 unk38C;
    s32 unk390;
} ResetThirtySixStorage;
typedef struct {
    u8 padding_0[4];
    f32 unk4;
    u8 padding_8[884];
    s32 unk37C;
} ResetTimerStorage;
typedef struct {
    u8 padding_0[1688];
    void * unk698;
} ResetOwnerStorage;
typedef struct {
    u8 padding_0[176];
    s32 unkB0;
} ResetFlagsStorage;
#endif
