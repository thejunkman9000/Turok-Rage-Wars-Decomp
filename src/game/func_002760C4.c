#include "b17_types.h"

extern SessMgr D_8011FE88;
Rec5A *func_0028B2D4(SessMgr *s, s32 id);

s32 func_002760C4(s32 id) {
    Rec5A *r = func_0028B2D4(&D_8011FE88, id);
    if (r == 0) {
        return 0;
    }
    return r->b58;
}
