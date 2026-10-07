#include "o03_types.h"
typedef struct { O3Hdr h; u8 pad[0x34]; O3Ent ent[1]; } O3LL;
void func_002A125C(void *dst, void *src);
void func_0041ADB4(O3List *o, void *src) {
    O3ListSel *s = (O3ListSel *)o;
    func_002A125C(&o->ent[s->cnt], src);
    s->cnt = s->cnt + 1;
}
