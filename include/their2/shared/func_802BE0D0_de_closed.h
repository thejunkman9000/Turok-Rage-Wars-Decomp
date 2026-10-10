#ifndef FUNC_802BE0D0_DE_CLOSED_H
#define FUNC_802BE0D0_DE_CLOSED_H
#include "types.h"
#include "acmd.h"
#include "span_1000/code_802BE0D0.h"

extern u32 func_802570C0_de(void *book, s32 size); /* game ADPCM codebook cache */
extern Acmd *func_802BEC34_de(Acmd *ptr, ALLoadFilter48_2 *f, s32 tsam, s32 nbytes, s16 outp, s16 inp,
                           u32 flags); /* _decodeChunk */


#endif
