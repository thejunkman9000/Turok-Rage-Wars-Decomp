#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80200610.h"
/* Updates the selected byte in the aligned word addressed by arg0. */

void func_80200AD8_de(s32 arg0, s32 arg1) {
    int temp_ff;
    s32 word_2;
    struct Shape_func_8021A2D4_de_2 *word_3;
    int new_var3_2;
    s32 shift = (~arg0 & 3) * 8;
    int shift_ff;
    int temp;
    struct Shape_func_8021A2D4_de_2 *word = (struct Shape_func_8021A2D4_de_2 *) (arg0 & ~3);
    int new_var5_2;
    word_2 = (*word).field_0;
    shift_ff = 0xFF << shift;
    word_3 = word;
    new_var5_2 = shift_ff;
    do {
        ;
    } while (0);
    new_var3_2 = ~new_var5_2;
    temp_ff = (arg1 & 0xFF) << shift;
    word_3->field_0 = (word_2 & new_var3_2) | temp_ff;
}
