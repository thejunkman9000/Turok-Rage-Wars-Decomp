#include "b21_types.h"

extern char D_8014ADA8[];
extern char D_800CA4F0[];
extern char D_800CA4F8[];
extern char D_800CA504[];
extern B21Game D_8011FAC0;
void func_00291404(B21Game *g);

void func_00293518(void) {
    sprintf(D_8014ADA8, D_800CA4F0, D_800CA4F8, D_800CA504);
    __osSetFpcCsr(__osGetFpcCsr() | 0x400);
    func_00291404(&D_8011FAC0);
}
