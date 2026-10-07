#include "o02_types.h"
void func_002A1D38(void);
void func_0029E8A0(void);
void func_0029E8A8(void);
void func_002A1E34(void);
void func_004143E0(void) {
    func_002A1D38();
    func_0029E8A0();
}
void func_00414404(void) {
    func_0029E8A8();
    func_002A1E34();
}
f64 func_00414430(void) {
    return (f64)(s64)osGetTime() / (f64)(s64)osClockRate;
}
