#include "b20_types.h"

typedef struct { void *data; s32 size; } Blk;

void *memcpy(void *dst, const void *src, u32 n);
void func_002537D8(s32 a, void *b);
void *func_00254224(s32 a, s32 *out, s32 b, void *c);
Blk *func_002543A8(s32 a, s32 b, s32 c, s32 d, Level *lv, s32 e, void *f);
s32 func_0028FE08(s32 *tbl, s32 *a, s32 idx);
extern u8 D_800CA200[];
extern s32 D_800CA370[];

void func_0028D35C(Level *lv, s32 idx, void *dst, s32 maxSize) {
    s32 sp20;
    s32 r;
    void *h;
    Blk *b;
    s32 n;
    r = func_0028FE08(lv->unk4C, lv->unk1C, idx);
    h = func_00254224(0, &sp20, r, D_800CA200);
    b = func_002543A8(0, sp20, 8, r, lv, 0, &D_800CA370[1]);
    n = b->size;
    if (maxSize < n) {
        n = maxSize;
    }
    memcpy(dst, b->data, n);
    func_002537D8(0, b);
    if (lv->unk1B40C != idx) {
        func_002537D8(0, h);
    }
}
