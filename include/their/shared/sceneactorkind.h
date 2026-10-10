#ifndef SHARED_SHARED_SCENEACTORKIND_H
#define SHARED_SHARED_SCENEACTORKIND_H

#include "types.h"

typedef struct Shared_SceneActorKind Shared_SceneActorKind;
struct Shared_SceneActorKind {
    u16 kind; /* +0x0: src/func_80286A78.c */
};
typedef char Shared_SceneActorKind_size_check[(sizeof(Shared_SceneActorKind) == 0x2) ? 1 : -1];

#endif
