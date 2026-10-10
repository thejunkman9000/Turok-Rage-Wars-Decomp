#include "span_1000/code_8028567C.h"



/** Clear the target word when the pointer field is populated. */
void func_80285960_de(char *object) {
    int *target = ((func_80285930_S1 *)(object))->unk38;
    if (target != 0) {
        *target = 0;
    }
}
