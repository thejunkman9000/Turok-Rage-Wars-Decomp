#include "b20_types.h"

s32 *func_0028FD94();

void *func_0028D220(Level *lv, s32 unused, s32 idx) {
    s32 *t = func_0028FD94(func_0028FD94(lv->unk7C), 1);
    return (u8 *)t + (idx * t[0] + 8);
}
