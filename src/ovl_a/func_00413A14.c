#include "o02_types.h"
typedef struct { u8 pad[8]; s16 v; } S_func_00413A14;
extern S_func_00413A14 *D_80153D54;
extern void (*D_80153CD8)(void);
extern s32 D_80153C78;
extern s32 D_80153C80;
s32 func_00413A14(s32 base, s32 n) {
    D_80153C78 = base + n * D_80153D54->v;
    D_80153CD8();
    return D_80153C80;
}
