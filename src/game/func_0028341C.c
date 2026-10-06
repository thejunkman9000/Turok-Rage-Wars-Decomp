#include "b19_types.h"
extern u8 D_80121990[];
void func_00284544(void *, B19Obj *);
void func_00284408(B19Obj *);
void func_0028341C(B19Obj *o) {
    func_00284544(D_80121990, o);
    func_00284408(o);
}
