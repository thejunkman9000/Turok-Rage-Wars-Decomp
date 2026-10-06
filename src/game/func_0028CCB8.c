#include "b20_types.h"
void func_00216488(void *buf, s32 a, s32 b, f32 c, s32 d, s32 e);
void func_002171FC(u8 *a, u8 *b, void *buf);
void func_0028CCB8(Level *lv, s32 arg1, s32 arg2) {
    u8 buf[0x18];
    s32 i;
    s32 n;
    u8 **arr;
    i = 0;
    func_00216488(buf, i, arg1, 102.399994f, arg2, 0);
    n = lv->cntF54;
    arr = lv->list4;
    for (; i < n; i++) {
        u8 *a = arr[i];
        func_002171FC(a, a + 0x170, buf);
    }
}
