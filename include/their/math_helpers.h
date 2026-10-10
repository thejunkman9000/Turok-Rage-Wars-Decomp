#ifndef RAGEWARS_MATH_HELPERS_H
#define RAGEWARS_MATH_HELPERS_H

#define RW_CLAMP(value, low, high) ((value) < (low) ? (low) : (value) > (high) ? (high) : (value))
#define RW_MIN(a, b) ((a) > (b) ? (b) : (a))

#define RW_MIN_LT(a, b) ((a) < (b) ? (a) : (b))
#define RW_MAX_GT(a, b) ((a) > (b) ? (a) : (b))
#define RW_ABS(value) ((value) < 0.0f ? -(value) : (value))

#endif
