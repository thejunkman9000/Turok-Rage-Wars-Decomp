
#include "common.h"
s32 func_00274544(void);
s32 func_002847E0(s32 n) {
 if (n) return func_00274544() % (n + 1);
 return 0;
}
