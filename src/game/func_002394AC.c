#include "b08_types.h"

typedef struct SlotObj {
    u8 pad0[0x11D8];
    ChanObj *free11D8;
    u8 pad11DC[0x10];
    s32 list11EC;
    ChanObj *cur11F0;
} SlotObj;

extern f32 D_800C8634;

void func_00255E78(void *list, void *n);
void func_00255C58(void *list, void *n);

static inline void setChans(ChanObj *co, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f v) {
    co->ch[0].v = v;
    co->ch[0].d = d;
    co->ch[1].mode = e;
    co->ch[2].mode = e;
    co->ch[3].mode = e;
    co->ch[1].v.x = a * D_800C8634;
    co->ch[2].v.x = b * D_800C8634;
    co->ch[3].v.x = c * D_800C8634;
}

void func_002394AC(SlotObj *o, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f v) {
    ChanObj *n;

    n = o->free11D8;
    if (n != NULL) {
        func_00255E78(&o->free11D8, n);
        func_00255C58(&o->list11EC, n);
    } else {
        n = o->cur11F0;
    }
    setChans(n, a, b, c, d, e, v);
}
