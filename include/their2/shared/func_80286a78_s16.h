#ifndef SHARED_SHARED_FUNC_80286A78_S16_H
#define SHARED_SHARED_FUNC_80286A78_S16_H

#include "shared/sceneactorkind.h"
#include "shared/sceneactorprefix.h"

typedef struct Shared_func_80286A78_S16 Shared_func_80286A78_S16;
struct Shared_func_80286A78_S16 {
    Shared_SceneActorPrefix prefix; /* +0x0: src/func_80286A78.c */
    Shared_SceneActorKind kind; /* +0xE4: src/func_80286A78.c */
    char padE6[0x2];
};
typedef char Shared_func_80286A78_S16_size_check[(sizeof(Shared_func_80286A78_S16) == 0xE8) ? 1 : -1];

#endif
