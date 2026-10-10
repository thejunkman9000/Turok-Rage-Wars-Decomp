#ifndef FUNC_8028C568_DE_CLOSED_H
#define FUNC_8028C568_DE_CLOSED_H
#include "common/unused.h"

#include "span_C76B0/data.h"
#include "types.h"

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);
extern void func_80278C10_de(void *);
#if defined(VERSION_EU)
extern f32 func_802AD520_eu(s32);
#else
extern f32 func_802B2350(s32);
#endif
static inline f32 recordValue(s32 id) {
#if defined(VERSION_EU)
    return func_802AD520_eu(id);
#else
    return func_802B2350(id);
#endif
}

struct func_8028C544_S2;
struct func_8028C544_S3;


#endif
