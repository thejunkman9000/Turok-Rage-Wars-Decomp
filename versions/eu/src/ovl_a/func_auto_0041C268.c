#include "common.h"

typedef struct EuList { u8 pad[0x48]; s32 count; void *items[1]; } EuList;

extern void func_auto_0040ED68(void *, s32);

s32 func_auto_0041C268(EuList *list) {
    s32 i;

    for (i = 0; i < list->count; i++) {
        func_auto_0040ED68(list->items[i], 1);
    }
    return 0;
}
