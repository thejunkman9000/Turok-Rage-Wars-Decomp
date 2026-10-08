/* port guard: free(NULL) arrives from a not-yet-understood menu path; log the caller chain and ignore */
#include "b12_types.h"

extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
void func_00254930(s32 a, B12Node *n);

extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
extern void port_bt(void);

void func_00254784(B12Node **p) {
    u32 mask;
    u32 m2;
    B12Node *n;
    if (!p) { fprintf(__acrt_iob_func(2), "free(NULL) in func_00254784\n"); port_bt(); return; }
    n = p[-4];
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    func_00254930(0, n);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
