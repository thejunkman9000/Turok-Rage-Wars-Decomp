#include "b04_types.h"
typedef struct { s16 cur; u8 pad2[0x66]; } B04SelL;
s32 func_002469F8(void *, s32, s32);
void func_002798CC(B04SelL *);
void func_002798D4(B04SelL *, s16, s32);
s16 func_00279918(B04SelL *);
typedef struct { s32 mask; s32 id; } B04Ent;
s32 func_002166F4(void *o, s32 a1, B04Ent *e, u32 mask) {
    B04SelL st;
    s32 def;
    s16 r;
    func_002798CC(&st);
    def = e->id;
    while (e->mask != -1) {
        if (e->mask == 0 && st.cur != 0) goto done;
        if (mask & e->mask) {
            if (func_002469F8(o, e->id, -1) != -1)
                func_002798D4(&st, e->id, 10);
        }
        e++;
    }
    if (st.cur == 0)
        func_002798D4(&st, def, 10);
done:
    r = func_00279918(&st);
    { s32 c = func_002469F8(o, r, -1); if (c == -1) return def; return r; }
}
