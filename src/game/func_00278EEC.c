#include "b17_types.h"

extern SessMgr D_8011FE88;
void func_0028BAF8(SessMgr *s, Rec14 *r, s32 n);
void func_0028C544(SessMgr *s, Rec14 *r);
void func_00278C80(Rec14 *r);

void func_00278EEC(Rec14 *r) {
    r->flagsE |= 0x10;
    func_0028BAF8(&D_8011FE88, r, 1);
    if (D_8011FE88.mode == 4 && (r->flagsE & 2)) {
        func_0028C544(&D_8011FE88, r);
    } else {
        func_00278C80(r);
    }
}
