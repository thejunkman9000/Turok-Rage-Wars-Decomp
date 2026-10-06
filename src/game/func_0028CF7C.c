#include "b20_types.h"

typedef struct { s32 key; u8 pad4[8]; s16 unkC; } Ent;

Ent *func_0028FD94(s32 *tbl, s32 idx);

Ent *func_0028CF7C(Level *lv, s32 a, s32 b) {
    s32 n = lv->unk78[0];
    s32 i = 0;
    Ent *e;
    if (n > 0) {
        do {
            e = func_0028FD94(lv->unk78, i);
            if (a == -1 || e->key == a) {
                if (b == -1 || e->unkC == b) {
                    return e;
                }
            }
            i++;
        } while (i < n);
    }
    return 0;
}
