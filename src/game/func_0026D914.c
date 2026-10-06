#include "b16_types.h"
extern s32 D_80110620;
extern DlCmd *D_80110634;
void func_0026D914(u32 a) {
    if (D_80110620 == 0) {
        DlCmd *p = D_80110634++;
        p->w0 = 0xE3001801;
        p->w1 = a;
    } else {
        DlCmd *p = D_80110634++;
        p->w0 = 0xE3001801;
        p->w1 = 0x80;
    }
}
