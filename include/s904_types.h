#ifndef S904_TYPES_H
#define S904_TYPES_H

#include "types.h"

/* Types recovered for the debug heap-map drawing routine func_002529E4 (module of the node pool manager at D_80103F70, see b12_types.h). */

/* node of the pool manager's list at D_80104584 (same record as B12Node of b12_types.h: key, size (= unk4), refs, flags, stamp (= unk10), ..., next at +0x24) */
typedef struct S904Node S904Node;
struct S904Node {
    /* 0x00 */ u32 key;
    /* 0x04 */ u32 size;
    /* 0x08 */ s32 pad8;
    /* 0x0C */ u32 flags;
    /* 0x10 */ u32 stamp;
    /* 0x14 */ u8 pad14[0x10];
    /* 0x24 */ S904Node *next;
};

/* heap segment record of the list headed by D_801051B0: next at +0xC, header size at +0x10, payload size at +0x14 */
typedef struct S904Seg S904Seg;
struct S904Seg {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ S904Seg *next;
    /* 0x10 */ u32 hdr;
    /* 0x14 */ u32 size;
};

#endif
