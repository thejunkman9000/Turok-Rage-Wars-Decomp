#include "b20_types.h"

void func_0026D980(void *p);
void func_00282304(u8 *p, s32 a);
void func_0026D9D0(void);
extern DlCmd *D_80110634;

void func_0028B13C(Level *lv, s32 arg) {
    DlCmd *g;
    g = D_80110634++;
    g->w0 = 0xDB040004;
    g->w1 = 1;
    g = D_80110634++;
    g->w0 = 0xDB04000C;
    g->w1 = 1;
    g = D_80110634++;
    g->w0 = 0xDB040014;
    g->w1 = 0xFFFF;
    g = D_80110634++;
    g->w0 = 0xDB04001C;
    g->w1 = 0xFFFF;
    func_0026D980(&D_80110634);
    func_00282304((u8 *)lv + 0x1B08, arg);
    func_0026D9D0();
}
