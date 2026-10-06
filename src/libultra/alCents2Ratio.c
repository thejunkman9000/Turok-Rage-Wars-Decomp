#include "libaudio.h"

f32 alCents2Ratio(s32 cents) {
    f32 ratio = 1.0f; f32 base = 1.0005778f; if (cents < 0) { base = 0.99942254f; cents = -cents; } while (cents != 0) { if (cents & 1) { ratio *= base; } cents >>= 1; base *= base; } return ratio;
}
