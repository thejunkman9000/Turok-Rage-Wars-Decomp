#include "types.h"
#include "span_16E000/code_8040C780.h"
#include "stddef.h"
/* Recursively replaces a node reference throughout a linked hierarchy and copies the old node links into its replacement. */
void func_8040ED38_de(Node_func_8040ED38_de *arg0, Node_func_8040ED38_de *arg1, Node_func_8040ED38_de *arg2, Node_func_8040ED38_de *arg3) {
    Node_func_8040ED38_de *temp_a0;
    Node_func_8040ED38_de *temp_a0_2;
    if (arg0 != NULL) {
        temp_a0 = arg0->unk4;
        if (temp_a0 != NULL) {
            func_8040ED38_de(temp_a0,arg1,arg2,arg3);
        }
        temp_a0_2 = arg0->unk8;
        if (temp_a0_2 != NULL) {
            func_8040ED38_de(temp_a0_2, arg0, arg2, arg3);
        }
        if (arg0->unk0 == arg2) {
            arg0->unk0 = arg3;
        }
        if (arg0->unk4 == arg2) {
            arg0->unk4 = arg3;
        }
        if (arg0->unk8 == arg2) {
            arg0->unk8 = arg3;
        }
        if (arg0 == arg2) {
            arg3->unk0 = (Node_func_8040ED38_de *) arg0->unk0;
            arg3->unk4 = (Node_func_8040ED38_de *) arg0->unk4;
            arg3->unk8 = (Node_func_8040ED38_de *) arg0->unk8;
        }
    }
}
