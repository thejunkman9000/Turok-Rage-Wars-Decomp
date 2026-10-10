#pragma once
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028FC98.h"
struct Shared_Pickup;
typedef struct Shared_World {
    s32 mode;
    u8 unknown4[0xE4];
    s32 resource;
    u8 unknownEC[0x34];
    s32 counter120;
    s32 counter124;
    u8 system128[0x1B08 - 0x128];
    u8 system1B08[0x11778 - 0x1B08];
    World_func_80290238_de system11778;
    u8 unknown15384[0x1B308 - 0x15384];
    f32 elapsed;
    u8 unknown1B30C[0x108];
    s32 frozen;
    u8 unknown1B418[0x1FC];
    Vec3 offset;
    struct Shared_Pickup *objects[16];
    s32 count;
} Shared_World;
extern Shared_World D_8011FE88;
