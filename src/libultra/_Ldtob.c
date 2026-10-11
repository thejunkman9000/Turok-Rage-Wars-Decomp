#include "common.h"

/* the stub build of the printf family keeps _Ldtob (called by xprintf's %e/%f/%g paths) as an empty function: `jr ra ; nop` */
void _Ldtob(_Pft *x, u8 type) {
}
