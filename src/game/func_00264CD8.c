#include "b14_types.h"
extern B14W3 D_8010FC40[];
void func_00264CD8(void) {
    if (D_8010FC40->c != 0) {
        D_8010FC40->c--;
        if (D_8010FC40->c == 0) {
            D_8010FC40->b = 0;
        }
    }
}
