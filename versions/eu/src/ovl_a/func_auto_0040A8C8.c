#include "o01_types.h"

typedef struct PV { char pad[0x22]; s16 value; } PV;
typedef struct Fld { char pad[0x14]; char **text; } Fld;
extern PV *D_800E28BC;
extern u8 D_auto_80152789;
extern u8 D_auto_800ED400[];
s32 func_auto_00442EE0(void *field);
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_auto_0040A8C8(Fld *field) {
    s32 value = D_800E28BC->value;
    char *text = field->text[D_auto_80152789];

    func_00265904(text + (func_auto_00442EE0(field) - 2), D_auto_800ED400, value);
    return 0;
}
