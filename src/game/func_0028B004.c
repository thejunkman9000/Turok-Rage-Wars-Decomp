#include "b20_types.h"
void func_0026D980();
void func_0026D9D0(void);
void func_00249E18(Entity *e, s32 a);
extern DlCmd *D_80110634;
void func_0028B004(Level *lv, s32 arg) {
    DlCmd *g;
    s32 i;
    s32 n;
    s32 c;
    Entity **arr;
    func_0026D980();
    n = lv->numActors;
    g = D_80110634++;
    g->w0 = 0xDB040004;
    g->w1 = 5;
    g = D_80110634++;
    g->w0 = 0xDB04000C;
    g->w1 = 5;
    g = D_80110634++;
    g->w0 = 0xDB040014;
    g->w1 = 0xFFFB;
    g = D_80110634++;
    g->w0 = 0xDB04001C;
    g->w1 = 0xFFFB;
    arr = (Entity **)lv->actors;
    for (i = 0; i < n; i++) {
        Entity *e = arr[i];
        if (e->flags & 4) {
            c = lv->cnt10BC;
            if (c != 0x40) {
                lv->arr10C0[c] = e;
                lv->cnt10BC = c + 1;
            }
        } else {
            func_00249E18(e, arg);
        }
    }
    func_0026D9D0();
}
