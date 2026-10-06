#include "b04_types.h"
typedef struct { s16 *start; s16 *cur; } B04Seq;
s32 func_002171C8(B04Seq *s) {
    s16 *p = s->cur;
    s16 v = *p;
    s->cur = ++p;
    if (*p == -1)
        s->cur = s->start;
    return v;
}
