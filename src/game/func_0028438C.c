#include "b19_types.h"
void func_00284408(B19Obj *);
void *func_0025CC8C(void);
B19Handle *func_0025C97C(void *, s32, void *, void *, s32);
void func_0028438C(B19Obj *o, s32 k) {
    if (o->unk1DC != 0) {
        if (o->unk1DC->fC == k && o->unk1DC->f8 != -1) return;
        func_00284408(o);
    }
    o->unk1DC = func_0025C97C(func_0025CC8C(), k, &o->pos, &o->pos, -1);
}
