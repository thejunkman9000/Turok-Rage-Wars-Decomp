#include "s1005_types.h"

extern s32 func_0028B1F8(void *lv, s32 id);
extern s32 func_0028C174(void *lv, s32 idx);
extern void **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
extern s32 func_0028FE08(void *tab, s32 idx, s32 sub);
extern void *func_00254094(s32 a, void **out, s32 c, void *name, s32 e);
extern s32 func_0028FE1C(void *node, s32 a, s32 b, s32 *out);
extern void *func_0028FD94(void *node, s32 idx);
extern void func_002537D8(s32 a, void *h);
extern void func_0026D7F4();

void func_0044C250(void *lv, S5Simp *out, s32 id) {
    s32 idx;
    s32 size;
    s32 base;
    s32 n;
    s32 cnt;
    void *node;
    void **h1;
    void *h2;
    void **h3;

    idx = func_0028B1F8(lv, id);
    if (idx == -1) {
        out->w8 = 0;
        return;
    }
    size = func_0028C174(lv, idx);
    h1 = func_002518DC(0, size, size, 0x18, 0, 0, 0, "CScene__ConstructMap: object index", 1);
    if (h1 != 0) {
        base = func_0028FE08(*h1, size, 1);
        h2 = func_00254094(0, &node, base, "CScene__ConstructMap: simp models index", 1);
        if (h2 != 0) {
            n = func_0028FE1C(node, base, 0, &cnt);
            h3 = func_002518DC(0, n, n, cnt, 0, 0, func_0026D7F4, "CScene__ConstructMap: simple model", 1);
            if (h3 != 0) {
                *out = *(S5Simp *)func_0028FD94(func_0028FD94(func_0028FD94(*h3, 2), 0), 0);
                func_002537D8(0, h3);
            }
            func_002537D8(0, h2);
        }
        func_002537D8(0, h1);
    }
}
