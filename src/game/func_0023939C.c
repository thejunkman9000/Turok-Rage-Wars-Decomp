#include "p2_types.h"

typedef struct { s32 a, b, c; } Args3;
void func_002979E8(void *a, Args3 *args);

/* printf-like wrapper: the three stack-passed words after `o` are handed on as a block */
void func_0023939C(Obj2F0 *o, Args3 args) {
    func_002979E8(&o->f2F0, &args);
}