#include "b14_types.h"
typedef struct { u32 bits; f32 start; f32 len; } B14Span;
static inline u32 b14_log2c(u32 x) {
    u32 count = 0;
    u32 last = 0;
    u32 i;
    for (i = 0; i < 32; i++) {
        if (x & (1 << i)) {
            count++;
            last = i;
        }
    }
    if (count >= 2) {
        return last + 1;
    }
    return last;
}


B14Span func_002608EC(f32 a, f32 b, f32 rate) {
B14Span r;
    f32 t;
    u32 n;
    s32 i;
    r.start = a;
    r.len = b - a;
    t = r.len / (rate + rate);
    if (t <= 0.0f) {
        n = (s32)t + 1;
    } else {
        i = (s32)t;
        n = i + 1;
        if ((f32)i != t) {
            n = i + 2;
        }
    }
    r.bits = b14_log2c(n);
    return r;
}
