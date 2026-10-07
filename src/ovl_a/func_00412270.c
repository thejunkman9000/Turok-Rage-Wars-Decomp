#include "o02_types.h"
typedef struct { u8 pad[0x48]; u8 b48, b49, b4A, b4B, b4C, b4D, b4E, b4F, b50, b51; } S_func_00412270;
void func_00412270(S_func_00412270 *p) {
    if (p->b4B < p->b4D) p->b4D = p->b4B;
    if (p->b4A < p->b4C) p->b4C = p->b4A;
    if (p->b4D < p->b51) p->b4D = p->b51;
    if (p->b4C < p->b50) p->b4C = p->b50;
    if (!((p->b4D - p->b4F) < (p->b49 - p->b51))) p->b4F = p->b4D - (p->b49 - p->b51) + 1;
    if (!((p->b4C - p->b4E) < (p->b48 - p->b50))) p->b4E = p->b4C - (p->b48 - p->b50) + 1;
    if (p->b4D < p->b4F) p->b4F = p->b4D;
    if (p->b4C < p->b4E) p->b4E = p->b4C;
}
