#ifndef SHARED_SHARED_SCENEACTORPREFIX_H
#define SHARED_SHARED_SCENEACTORPREFIX_H

#include "types.h"

typedef struct Shared_SceneActorPrefix Shared_SceneActorPrefix;
struct Shared_SceneActorPrefix {
    u8 pad0[24]; /* +0x0: src/func_80286A78.c */
    void * definition; /* +0x18: src/func_80286A78.c */
    u8 pad1C[200]; /* +0x1C: src/func_80286A78.c */
};
typedef char Shared_SceneActorPrefix_size_check[(sizeof(Shared_SceneActorPrefix) == 0xE4) ? 1 : -1];

#endif
