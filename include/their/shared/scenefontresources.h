#ifndef SHARED_SHARED_SCENEFONTRESOURCES_H
#define SHARED_SHARED_SCENEFONTRESOURCES_H

#include "types.h"

typedef struct Shared_SceneFontResources Shared_SceneFontResources;
struct Shared_SceneFontResources {
    u8 bytes[712]; /* +0x0: src/func_80286A78.c */
};
typedef char Shared_SceneFontResources_size_check[(sizeof(Shared_SceneFontResources) == 0x2C8) ? 1 : -1];

#endif
