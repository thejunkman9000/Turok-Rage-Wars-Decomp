#ifndef SHARED_SHARED_FUNC_80286A78_S18_H
#define SHARED_SHARED_FUNC_80286A78_S18_H

#include "shared/sceneactorkind.h"
#include "shared/sceneactorprefix.h"

typedef struct Shared_func_80286A78_S18 Shared_func_80286A78_S18;
struct Shared_func_80286A78_S18 {
    Shared_SceneActorPrefix prefix; /* +0x0: src/func_80286A78.c */
    Shared_SceneActorKind kind; /* +0xE4: src/func_80286A78.c */
    char padE6[0x2];
};
typedef char Shared_func_80286A78_S18_size_check[(sizeof(Shared_func_80286A78_S18) == 0xE8) ? 1 : -1];

#endif
