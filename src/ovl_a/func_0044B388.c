/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044A738_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
/* Detaches the object at offset 0xC of an owner: when there is one, finalises it through
   func_0044ADC0 and removes it from the lists at offsets 0xC and 0x20 through func_00255E78 and
   func_00255CB4. Returns the object. */


extern void func_0044ADC0(void *);
extern void func_00255E78(void *, void *);




void *func_0044B388(struct Draw *owner) {
    void *object = owner->model;

    if (object != 0) {
        func_0044ADC0(object);
        func_00255E78(&((func_8044B388_S1 *)(owner))->unkC, object);
        func_00255CB4(&((func_8044B388_S1 *)(owner))->unk20, object);
    }
    return object;
}
