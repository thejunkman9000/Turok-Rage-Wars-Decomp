#include "b24_types.h"

void func_002A453C(Emit *);
void func_002A438C(Emit *, s32);
void func_002A4708(s32, Emit *, s32);
void func_002A4DC4(s32, Emit *, s32);

void func_002A72F4(s32 a, Emit *e, s32 c) {
    if (e->flags & 8) {
        func_002A453C(e);
    }
    if (e->flags & 4) {
        func_002A438C(e, c);
    }
    if (e->unk48 >= 2) {
        if (e->unk34 >= 0) {
            func_002A4708(a, e, c);
        } else {
            func_002A4DC4(a, e, c);
        }
    }
}
