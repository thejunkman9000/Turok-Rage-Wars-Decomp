#include "b24_types.h"

void func_002A453C(Emit *);
void func_002A438C(Emit *, s32);
void func_002A4708(EmitMgr *, Emit *, s32);
void func_002A4DC4(EmitMgr *, Emit *, s32);

static inline void upd(EmitMgr *m, Emit *e, s32 c) {
    if (e->flags & 8) {
        func_002A453C(e);
    }
    if (e->flags & 4) {
        func_002A438C(e, c);
    }
    if (e->unk48 >= 2) {
        if (e->unk34 >= 0) {
            func_002A4708(m, e, c);
        } else {
            func_002A4DC4(m, e, c);
        }
    }
}

void func_002A7480(EmitMgr *m, s32 c) {
    Emit *e;
    for (e = m->head; e != NULL; e = e->next) {
        if (e->unk34 < 0) {
            upd(m, e, c);
        }
    }
    for (e = m->head; e != NULL; e = e->next) {
        if (e->unk34 > 0) {
            upd(m, e, c);
        }
    }
}
