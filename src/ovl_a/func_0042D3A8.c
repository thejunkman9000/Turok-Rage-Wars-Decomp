#include "o04_types.h"
typedef struct { u8 pad0[0x91]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96b;
extern O04ModeS53C0 *D_800E53C0;
extern O04Ent96b D_80146398[];
s32 func_00425FDC(s32 a);
void func_004260C4(s32 a, void *b);
void func_00425BC0(s32 a);
void func_0042D3A8(void) {
    s32 i;
    O04Ent96b *e;
    for (i = 0; i < 8; i++) {
        s32 n = D_800E53C0->unkF0[i];
        if (n != -1) {
            e = &D_80146398[n];
            if (e->unk91 == 0) {
                D_800E53C0->unk32C = func_00425FDC(n);
                func_004260C4(n, &D_800E53C0->unk110[n]);
                func_00425BC0(n);
            }
        }
    }
}
