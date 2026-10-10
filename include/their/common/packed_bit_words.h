#ifndef PACKED_BIT_WORDS_H
#define PACKED_BIT_WORDS_H
#include "types.h"
/* Consecutive 32-bit storage words used by the scalar bit packer. */
typedef struct { u32 low; u32 high; } PackedBitWords;
#endif
