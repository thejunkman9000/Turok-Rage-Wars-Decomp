#include "p4_types.h"
typedef struct { u8 pad0[0xC]; s16 h0C; } P4Sub;
typedef struct { u8 pad0[0x18]; P4Sub *sub; u8 pad1c[0xE4 - 0x1C]; u16 id; u8 pad_e6[0x2E8 - 0xE6]; } P4Ent2;
typedef struct { u8 pad0[0x138]; P4Ent2 *ents; s32 start; s32 end; } P4Mgr2;
s32 func_0028D02C(P4Mgr2 *m, s32 id, s32 w, s32 h, P4Ent2 **out, s32 max) {
    s32 i = m->start;
    s32 n = m->end;
    P4Ent2 *base = m->ents;
    s32 cnt = 0;
    for (; i < n; i++) {
        P4Ent2 *e = &base[i];
        if (cnt >= max) {
            return cnt;
        }
        if (id == -1 || e->id == id) {
            if (w == -1 || *(s32 *)e->sub == w) {
                if (h == -1 || e->sub->h0C == h) {
                    *out++ = e;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
