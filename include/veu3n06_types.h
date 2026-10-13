#ifndef VEU3N06_TYPES_H
#define VEU3N06_TYPES_H
#include "common.h"

/* EU (PAL): global state block D_801462C8 (0x80152208).  Word 0 = option flags, the language index byte
   is at +0x581 (= 0x80152789), used as the index of the per-language text tables. */
typedef struct EuGlob {
    /* 0x000 */ u32 flags;
    /* 0x004 */ u8 pad4[0x57D];
    /* 0x581 */ u8 lang;
} EuGlob;
extern EuGlob D_801462C8;

#endif
