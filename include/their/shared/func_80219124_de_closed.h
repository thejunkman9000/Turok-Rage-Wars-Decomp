#ifndef FUNC_80219124_DE_CLOSED_H
#define FUNC_80219124_DE_CLOSED_H
#include "types.h"
#include "span_C76B0/data.h"
#include "types.h"
typedef struct Shared_MenuItemRecord Shared_MenuItemRecord;
struct Shared_MenuItemRecord {
    s32 index;
    s32 enabled;
    f32 angle;
    s32 image;
    f32 value;
};
typedef struct Shared_MenuItemList Shared_MenuItemList;
struct Shared_MenuItemList {
    u32 unknown00[7];
    Shared_MenuItemRecord records[4];
    s32 selection;
};

extern f32 D_800C917C;


#endif
