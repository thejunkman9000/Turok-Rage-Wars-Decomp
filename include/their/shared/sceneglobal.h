#ifndef SHARED_SHARED_SCENEGLOBAL_H
#define SHARED_SHARED_SCENEGLOBAL_H

#include "types.h"

typedef struct Shared_SceneGlobal Shared_SceneGlobal;
struct Shared_SceneGlobal {
    u8 pad0[72]; /* +0x0: src/func_80286A78.c */
    u8 address48; /* +0x48: src/func_80286A78.c */
};
typedef char Shared_SceneGlobal_size_check[(sizeof(Shared_SceneGlobal) == 0x49) ? 1 : -1];

#endif
