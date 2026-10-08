#include "o04_types.h"
typedef struct { u8 pad0[0xC]; s16 unkC; } O04Obj;
extern O04Evt D_800E4604[];
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
extern char *getenv(const char *);
extern u32 port_unresolve(u32);
/* debug (TUROK_EVT=1): log the event table once and every dispatched / unmatched event */
s32 func_00424528(O04Obj *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    static int dumped, nlog;
    int dbg = getenv("TUROK_EVT") != 0;
    if (dbg && !dumped) { dumped = 1; for (i = 0; D_800E4604[i].fn != 0 && i < 200; i++) fprintf(__acrt_iob_func(2), "EVT[%d] ev=%x key=%d fn=%08x\n", i, D_800E4604[i].ev, D_800E4604[i].key, port_unresolve((u32)D_800E4604[i].fn)); }
    for (i = 0; D_800E4604[i].fn != 0; i++) {
        if (D_800E4604[i].ev == b) {
            if (D_800E4604[i].key == a->unkC || D_800E4604[i].key == 0x7530) {
                if (dbg && nlog++ < 400) fprintf(__acrt_iob_func(2), "EVT dispatch node=%d ev=%x -> %08x\n", a->unkC, b, port_unresolve((u32)D_800E4604[i].fn));
                return D_800E4604[i].fn(a, b, c, d, e);
            }
        }
    }
    if (dbg && b == 0xE06 && nlog++ < 400) fprintf(__acrt_iob_func(2), "EVT unmatched node=%d ev=%x\n", a->unkC, b);
    return 0;
}
