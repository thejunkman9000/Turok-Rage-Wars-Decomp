/* Small C-library level shims: names the matching build reached through asm-label aliases. */
#include <math.h>
#include <string.h>

float b04_sqrtf(float x) { return sqrtf(x); }
float b05_sqrtf(float x) { return sqrtf(x); }
float b08_sqrtf(float x) { return sqrtf(x); }
float sqrtf_(float x) { return sqrtf(x); }
float trw_sqrtf(float x) { return sqrtf(x); }
void *memcpy_call(void *d, const void *s, unsigned n) { return memcpy(d, s, n); }
