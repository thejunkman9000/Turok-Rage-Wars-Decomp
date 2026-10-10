#ifndef SHARED_SHARED_SCENERESOURCES_H
#define SHARED_SHARED_SCENERESOURCES_H

#include "shared/sceneactorresources.h"
#include "shared/scenefontresources.h"

typedef struct Shared_SceneResources Shared_SceneResources;
struct Shared_SceneResources {
    Shared_SceneFontResources font; /* +0x0: src/func_80286A78.c */
    Shared_SceneActorResources actors; /* +0x2C8: src/func_80286A78.c */
};
typedef char Shared_SceneResources_size_check[(sizeof(Shared_SceneResources) == 0x2C9) ? 1 : -1];

#endif
