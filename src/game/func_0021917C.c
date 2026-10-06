#include "b04_types.h"
typedef struct { u8 pad0[0xB0]; u32 flagsB0; } B04Wpn;
typedef struct { u8 pad0[0x5D8]; ActorStats *stats; u8 pad5DC[0xBC]; B04Wpn *wpn; } B04Pl;
typedef struct { u8 pad0[0x6C]; s32 unk6C; } B04Tgt;
s32 func_0021917C(B04Tgt *t, B04Pl *p) {
    if ((p->wpn->flagsB0 & 0x8000) && p->stats->unk92 != 0xFF) {
        t->unk6C = -1;
        return 1;
    }
    return 0;
}
