#include "common.h"

typedef struct { u8 pad0[0xC]; void *buf; } VSwap;
extern void *D_80146CF8;
extern void *D_80146CF0;

VSwap *func_0028F98C(VSwap *s) {
    if (s != 0) {
        if (s->buf == D_80146CF8) {
            return 0;
        }
        if (s->buf == osViGetCurrentFramebuffer()) {
            return 0;
        }
        if (s->buf != D_80146CF0) {
            return s;
        }
    }
    return 0;
}
