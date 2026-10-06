#include "b14_types.h"
typedef struct { s32 w[6]; } B14W6;
void *func_002604BC(void *p);
B14W6 *func_0028FD94(void *tree, s16 id);
void func_00262524(void *p, B14W6 *out) {
    *out = *func_0028FD94(func_002604BC(p), 6);
}
