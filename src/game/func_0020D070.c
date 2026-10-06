#include "b02_types.h"

void func_0020D014(B2Mgr *m);
void func_0020D1FC(B2Mgr *m);
void func_0020D220(B2Mgr *m, s32 key);
void func_0020D0CC(B2Mgr *m, s32 key);

void func_0020D070(B2Mgr *m, s32 a, s32 b) {
    func_0020D014(m);
    func_0020D1FC(m);
    func_0020D220(m, b);
    func_0020D0CC(m, a);
}
