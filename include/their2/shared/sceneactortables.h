#ifndef SHARED_SHARED_SCENEACTORTABLES_H
#define SHARED_SHARED_SCENEACTORTABLES_H

#include "shared/sceneprimaryactors.h"

typedef struct Shared_SceneActorTables Shared_SceneActorTables;
struct Shared_SceneActorTables {
    void * kind64e[10]; /* +0x0: src/func_80286A78.c */
    Shared_ScenePrimaryActors primary; /* +0x28: src/func_80286A78.c */
    void * kindBd6; /* +0x3C: src/func_80286A78.c */
};
typedef char Shared_SceneActorTables_size_check[(sizeof(Shared_SceneActorTables) == 0x40) ? 1 : -1];

#endif
