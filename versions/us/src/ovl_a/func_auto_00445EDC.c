/* their2 */
/* ported from melalawi/ragewars-decomp src/func_80445D6C_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"
/* Deletes the final character of the selected player's text entry: resets its cursor and, when the entry holds characters, decrements the count and length and clears the character at the new end. */





extern char D_80145040;
extern TextEntry_func_80445D6C_de D_800E63C0[];
extern s32 func_0022A590(void *table, s32 player);

s32 func_auto_00445EDC(s32 unused, MenuRules *menu) {
    s32 i;
    s32 count;

    i = func_0022A590(&D_80145040, menu->locked);
    count = D_800E63C0[i].count;
    D_800E63C0[i].cursor = 0;
    if (count == 0) {
        return 0;
    }
    D_800E63C0[i].count = count - 1;
    D_800E63C0[i].length--;
    D_800E63C0[i].text[D_800E63C0[i].length] = 0;
    return 0;
}
