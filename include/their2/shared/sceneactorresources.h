#ifndef SHARED_SHARED_SCENEACTORRESOURCES_H
#define SHARED_SHARED_SCENEACTORRESOURCES_H

#include "types.h"

typedef struct Shared_SceneActorResources Shared_SceneActorResources;
struct Shared_SceneActorResources {
    u8 base; /* +0x0: src/func_80286A78.c */
};
typedef char Shared_SceneActorResources_size_check[(sizeof(Shared_SceneActorResources) == 0x1) ? 1 : -1];

#endif
