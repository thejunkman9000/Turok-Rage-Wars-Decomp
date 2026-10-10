#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028567C.h"
#include "types.h"



extern s32 D_8011FE88;
extern void *func_8028CE78_de(void *object, int index);
extern void func_80264DE0_de(unsigned int *record, unsigned int value);






void func_802858B0_de(void *arg0, void *arg1, Triple arg2,
                   f32 arg5, f32 arg6, void **arg7) {
    ((func_80285880_S1 *)(arg0))->unk8 = arg1;
    ((func_80285880_S1 *)(arg0))->unkC = arg2;
    ((func_80285880_S1 *)(arg0))->unk18 = arg5;
    ((func_80285880_S1 *)(arg0))->unk1C = arg6;
    ((func_80285880_S1 *)(arg0))->unk38 = arg7;
    if (arg7 != 0) {
        *arg7 = arg0;
    }
    func_80264DE0_de(&((func_80285880_S1 *)(arg0))->unk20,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, *(s16 *)arg1));
    func_80264DE0_de(&((func_80285880_S1 *)(arg0))->unk2C,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, ((func_8025E52C_S1 *)(arg1))->unk2));
}
