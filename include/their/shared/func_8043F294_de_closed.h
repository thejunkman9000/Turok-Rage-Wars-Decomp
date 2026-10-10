#ifndef FUNC_8043F294_DE_CLOSED_H
#define FUNC_8043F294_DE_CLOSED_H
#include "types.h"
typedef struct Shared_MenuSelection {
    u32 unknown0;
    s8 index;
} Shared_MenuSelection;
typedef struct Shared_MenuHandle {
    u8 unknown0[0x1C];
    struct SharedPlayer *owner;
    Shared_MenuSelection *selection;
} Shared_MenuHandle;
typedef struct Shared_MenuInput {
    u32 unknown0[8];
    s32 buttons;
} Shared_MenuInput;

#include "common/unused.h"
#include "types.h"

                             
                             


#endif
