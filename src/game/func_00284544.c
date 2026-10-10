#include "span_1000/code_8028308C.h"
#include "types.h"
#include "common/unused.h"





extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);

void func_80284570_de(EffectSystem *arg0, Effect_func_802800C0_de *arg1) {
    s32 *temp_v1;
    s32 temp_a1;
    s32 temp_v1_2;

    temp_v1_2 = arg1->flags;
    if (temp_v1_2 & 0x100) {
        if (!(temp_v1_2 & 0x800)) {
            func_80279A00_de(arg1);
            if (arg1->unk1D9 != 0) {
                func_80284178_de(arg1);
                func_802A42F4_de(&D_801379C0, arg1);
            }
            temp_a1 = arg1->unk138;
            if (temp_a1 != 0) {
                func_80268C7C_de(&D_8013B1A8, temp_a1);
                arg1->unk138 = 0;
            }
            temp_v1 = arg1->refCount;
            if (temp_v1 != 0) {
                *temp_v1 -= 1;
            }
            arg1->flags =
                arg1->flags & 0xFDFFFEFF;
            func_80255ED8_de(arg1->list, (s32)arg1);
            arg1->list = 0;
            func_80255CB8_de(&arg0->free, (s32)arg1);
            if (arg1->flags & 0x01000000) {
                func_80255ED8_de(&arg0->groups, (s32)arg1);
            }
        }
    }
}
