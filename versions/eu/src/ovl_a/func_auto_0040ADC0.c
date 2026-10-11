#include "o06_types.h"
typedef struct { u8 pad4[4]; s16 unk4; u8 pad14[0x14-6]; char **unk14; } O06B;
extern u8 D_auto_80152789;
extern u16 D_auto_8015D48C;
extern char D_auto_800ED414[];
extern s32 func_auto_00442EE0(O06B *a);
extern void func_00265904(char *buf, const char *fmt, s32 a);

s32 func_auto_0040ADC0(O06B *a) {
    char *buf = a->unk14[D_auto_80152789];
    s32 x = D_auto_8015D48C;
    s32 len = func_auto_00442EE0(a) - 4;
    func_00265904(buf + len, D_auto_800ED414, x);
    return 0;
}
