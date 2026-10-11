/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"

/* Copies the three-word vector passed by value into the object's vector at 0x480. */





void func_8041CDB0_de(Obj_func_8041CDB0_de *arg0, Vec3 v) {
    arg0->unk480 = v;
}

/* Copies the three-word vector passed by value into the object's vector at 0x48C. */





void func_8041CDDC_de(Obj_func_8041CDDC_de *arg0, Vec3 v) {
    arg0->unk48C = v;
}

/* Stores arg1 into the word at 0x498 of the object arg0. */



void func_8041CE08_de(Obj_func_8041CE08_de *arg0, s32 arg1) {
    arg0->unk498 = arg1;
}

/* Stores a value into the word at offset 0x49C of an object; func_80420618_de and func_8043AB40_de call
   it with zero, func_8041CAD8_de writes the same word directly and func_8041C7F4_de reads it. */


void func_8041CE10_de(struct Object49C *object, s32 value) {
    object->value = value;
}

/* Sets field 0x274 of arg0 to 0xFFFF and then calls func_8041C610_de on it. */
void func_8041CE18_de(Unk8041CE88 *arg0) {
    arg0->unk274 = 0xFFFF;
    func_8041C610_de(arg0);
}
