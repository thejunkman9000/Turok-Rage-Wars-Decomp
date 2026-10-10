#ifndef FUNC_8043E444_DE_CLOSED_H
#define FUNC_8043E444_DE_CLOSED_H
#include "shared/func_8043F294_de_closed.h"
#include "types.h"
typedef struct Shared_DebugField Shared_DebugField;
struct Shared_DebugField {
    char *name;
    u32 type;
    u32 unknown08[3];
    f32 scale;
    void *(*get)(void);
};
typedef struct Shared_DebugWidget Shared_DebugWidget;
struct PlayerRankInner;
struct Shared_DebugWidget {
    u32 unknown00;
    s16 type;
    u16 unknown06;
    u32 unknown08[3];
    union {
        Shared_DebugField *field;
        char **text;
    };
    struct PlayerRankInner *inner;
};

#include "types.h"




extern Shared_DebugField *D_800E1CC0[];


#endif
