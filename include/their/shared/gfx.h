#ifndef UNBAKE_SHARED_GFX_H
#define UNBAKE_SHARED_GFX_H
#include "types.h"

typedef union Gfx {
    struct { u32 w0; u32 w1; } words;
    u64 force_structure_alignment;
} Gfx;

#endif
