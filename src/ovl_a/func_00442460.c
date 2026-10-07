#include "o06_types.h"
extern f32 func_0044239C(s32 c, s32 d, f32 x, f32 y);
f32 func_00442460(u8 *s, f32 x, f32 y) {
 f32 w = 0.0f;
 for (; s != 0 && *s != 0 && *s != 10; ) { u8 c = *s++; w += func_0044239C(c, *s, x, y); }
 return w; }
