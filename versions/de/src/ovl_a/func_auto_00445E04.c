/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80445E04_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"
/* Copies a player label with spaces for empty characters and refreshes the entry. */


extern u8 D_80145040[],D_auto_800E20AC[];
extern s32 func_0022A590(void *,func_80209B64_S4 *);
extern void func_004424F4(s32,Entry_func_80445E04_de *,s32), func_00444260(void *);
s32 func_auto_00445E04(s32 arg0, Entry_func_80445E04_de *arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    u8 *var_a2;
    u8 *var_v1;
    u8 var_v0;
    func_80209B64_S4 *temp_s1;

    temp_s1 = arg1->unk1C;
    temp_v0 = func_0022A590(D_80145040, temp_s1);
    var_a2 = (temp_v0 * 0x18) + D_auto_800E20AC;
    var_v1 = (temp_v0 * 0x96) + (D_80145040 + 0x13DC);
    var_a1 = 0;
    var_a0 = 0;
    do {
        var_v0 = *var_a2;
        var_a2 += 1;
        if (var_v0 == 0) {
            var_v0 = 0x20;
        } else {
            var_a1 += 1;
        }
        *var_v1 = var_v0;
        var_a0 += 1;
        var_v1 += 1;
    } while (var_a0 < 8);
    *var_v1 = 0;
    if (var_a1 == 0) {
        func_00444260(temp_s1->unk5D8);
    }
    func_004424F4(arg0, arg1, arg2);
    return 1;
}
