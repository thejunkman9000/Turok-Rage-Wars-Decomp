#ifndef RAGEWARS_TLB_SNAPSHOT_H
#define RAGEWARS_TLB_SNAPSHOT_H

#include "types.h"

/* Compact TLB fields captured by func_802AD42C_de. */
typedef struct RageWarsTlbSnapshot {
    u16 pageMask;
    u16 virtualPage;
    u16 evenPage;
    u16 oddPage;
} RageWarsTlbSnapshot;

extern RageWarsTlbSnapshot D_800D3F70[31];

#endif
