#include "b12_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
s32 func_00278530(s32 a, s32 b, void *c, void *d, s32 e, B12Obj *o);
s32 func_00253E04(s32 a, s32 *b, s32 c);

/* port: logs the lit-vertex cache fills (one per panel) so a rematch that reuses stale blocks shows up as "no fills" */
s32 func_00250BD4(B12Obj *o, s32 **b) {
    s32 x = **b;
    s32 r;
    { static int n; extern int port_verbose(void); if (++n <= 2000 && (n <= 20 || (n % 100) == 0) && port_verbose()) fprintf(__acrt_iob_func(2), "litfill #%d obj=%p key=%08X level=%08X\n", n, (void *)o, (unsigned)o->unkD0, (unsigned)*o->unk20); }
    r = func_00278530(x, *o->unk20, o->unkB8, o->unk28, 0, o);
    return func_00253E04(0, (s32 *)b, r);
}
