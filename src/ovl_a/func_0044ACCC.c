/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044A07C_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "shared/world.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"
#include "span_1000/code_8026AC38.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern void func_0028B250(struct Bank_func_8028B274_de *, struct Object_func_8028B274_de *, s32, s32);

/* Releases the two handles at offsets 0x11BC and 0x11C0 of an object: each goes to func_0025CA44
   with what func_0025CC8C returns, and each is then cleared. */


extern void *func_0025CC8C();
extern void func_0025CA44(void *, s32);

void func_0044ACCC(struct Object_func_8044A07C_de *object) {
    func_0025CA44(func_0025CC8C(), object->first);
    object->first = 0;
    func_0025CA44(func_0025CC8C(), object->second);
    object->second = 0;
}

/* Stores the second argument at 0x5E0 of the actor, calls func_002266E4 and func_0021AF6C on it, then starts sound D_8011FE88 for it through func_0028B250 with 0x66, D_800CE47C or its type's entry of D_800CE430 chosen by the options D_801462E5 and D_801468F4.
   Adapted from func_0022BB70 with a leading field store and two calls added and the D_801462C8 offsets changed to the symbols D_801462E5 and D_801468F4. */


extern void func_002266E4();
extern void func_0021AF6C(void *);
extern u8 D_801462E5;
extern s32 D_801468F4;











void func_0044AD14(void *arg0, s32 arg1) {
    s32 var_a2;

    ((func_8044AD14_S1 *)(arg0))->unk5E0 = arg1;
    func_002266E4();
    func_0021AF6C(arg0);
    if (D_801462E5 == 0) {
        var_a2 = 0x66;
    } else if (D_801468F4 != 0 && ((func_8021C9B4_S2 *)(((func_8044AD14_S1 *)(arg0))->unk5D8))->unk8F != 0) {
        var_a2 = D_800CE47C;
    } else {
        var_a2 = D_800CE430[((func_8021C9B4_S3 *)(((func_8044AD14_S1 *)(arg0))->unk18))->unkC];
        ((func_8044AD14_S1 *)(arg0))->unk3 = ((func_8021C9B4_S2 *)(((func_8044AD14_S1 *)(arg0))->unk5D8))->unk81;
    }
    ((void (*)(void *, void *, s32, s32))func_0028B250)(&D_8011FE88, arg0, var_a2, ((func_8044AD14_S1 *)(arg0))->unk86C);
}
