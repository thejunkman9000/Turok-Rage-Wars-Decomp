#include "b07_types.h"

void func_00264874(s32 a0);
void func_002538A8(s32 a0);
void func_002537D8(s32 a0, s32 a1);

void func_0022ED94(s32 *p)
{
    func_00264874(0);
    func_002538A8(0);
    if (p[0] != 0) {
        func_002537D8(0, p[0]);
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
    }
}
