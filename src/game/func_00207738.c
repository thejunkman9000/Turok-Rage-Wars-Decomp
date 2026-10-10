#include "span_1000/code_80206258.h"
#include "types.h"

/* Chooses the option label from the signed kind byte and, for the default
 * kind, the paired variant byte. The caller's context is unused. */
struct Input_func_80207738_de {
    char pad0[0x34];
    s8 variant;
    char pad35[2];
    s8 kind;
};

s32 func_80207738_de(void *context, struct Input_func_80207738_de *option) {
    s32 result;
    switch (option->kind) {
    case 3:
        return 21120;
    case 1:
    case 2:
        return 21140;
    case 0:
        result = 21100;
        switch (option->variant) {
        case 0:
        case 2:
            return 21100;
        case 1:
        case 3:
            return 21110;
        }
        break;
    default:
        return 21100;
    case 4:
        return 21130;
    }
    return result;
}
