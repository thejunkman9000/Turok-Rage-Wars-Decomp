#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
void func_0040EE64(O3M7D5 *, O3M7D5 *);
O3M7D5 *func_0041B690(O3Own *own, s32 n) {
    O3M7D5 *o;
    o = func_00252FFC(0x70);
    func_002A1748(o, 0, 0x70);
    *(O3Blk11 *)o = *(O3Blk11 *)own->child;
    o->h.id2 = 0x7D5;
    o->h.unk12 = 8;
    o->cnt = n;
    o->own = own;
    o->h.id = 0x7A51;
    o->mode = 0;
    func_0040EE64(own->child, o);
    return own->cur = o;
}
