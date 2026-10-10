#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

s32 func_80255D14_de(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v0;

    temp_v1 = ((func_80239CDC_S1 *)(arg0))->unk4;
    if (temp_v1 != 0) {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unk8) = temp_v1;
        *(s32 *)(((func_80239CDC_S1 *)(arg0))->unk4 + ((func_80239CDC_S1 *)(arg0))->unkC) = arg1;
    } else {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unk8) = 0;
        *(s32 *)arg0 = arg1;
    }
    *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unkC) = 0;
    ((func_80239CDC_S1 *)(arg0))->unk4 = arg1;
    temp_v0 = ((func_80239CDC_S1 *)(arg0))->unk10 + 1;
    ((func_80239CDC_S1 *)(arg0))->unk10 = temp_v0;
    return temp_v0;
}

void func_80255D70_de(void *arg0, s32 arg1, s32 arg2) {
    char *o = (char *) arg0;
    s32 next = *(s32 *) (arg1 + ((func_80255D10_S1 *)(o))->unk8);
    s32 v0;

    if (next != 0) {
        s32 off8;
        *(s32 *) (next + ((func_80255D10_S1 *)(o))->unkC) = arg2;
        off8 = ((func_80255D10_S1 *)(o))->unk8;
        *(s32 *) (arg2 + off8) = *(s32 *) (arg1 + off8);
        *(s32 *) (arg1 + ((func_80255D10_S1 *)(o))->unk8) = arg2;
        *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unkC) = arg1;
        v0 = ((func_80255D10_S1 *)(o))->unk10 + 1;
    } else {
        s32 tail = ((func_80255D10_S1 *)(o))->unk0;
        if (tail != 0) {
            *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unkC) = tail;
            *(s32 *) (((func_80255D10_S1 *)(o))->unk0 + ((func_80255D10_S1 *)(o))->unk8) = arg2;
        } else {
            *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unkC) = 0;
            ((func_80255D10_S1 *)(o))->unk4 = arg2;
        }
        *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unk8) = 0;
        ((func_80255D10_S1 *)(o))->unk0 = arg2;
        v0 = ((func_80255D10_S1 *)(o))->unk10 + 1;
    }
    ((func_80255D10_S1 *)(o))->unk10 = v0;
}

void func_80255E24_de(void *arg0, s32 arg1, s32 arg2) {
    char *o = (char *) arg0;
    s32 next = *(s32 *) (arg1 + ((func_80255D10_S1 *)(o))->unkC);
    s32 v0;

    if (next != 0) {
        s32 offC;
        *(s32 *) (next + ((func_80255D10_S1 *)(o))->unk8) = arg2;
        offC = ((func_80255D10_S1 *)(o))->unkC;
        *(s32 *) (arg2 + offC) = *(s32 *) (arg1 + offC);
        *(s32 *) (arg1 + ((func_80255D10_S1 *)(o))->unkC) = arg2;
        *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unk8) = arg1;
        v0 = ((func_80255D10_S1 *)(o))->unk10 + 1;
    } else {
        s32 head = ((func_80255D10_S1 *)(o))->unk4;
        if (head != 0) {
            *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unk8) = head;
            *(s32 *) (((func_80255D10_S1 *)(o))->unk4 + ((func_80255D10_S1 *)(o))->unkC) = arg2;
        } else {
            *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unk8) = 0;
            ((func_80255D10_S1 *)(o))->unk0 = arg2;
        }
        *(s32 *) (arg2 + ((func_80255D10_S1 *)(o))->unkC) = 0;
        ((func_80255D10_S1 *)(o))->unk4 = arg2;
        v0 = ((func_80255D10_S1 *)(o))->unk10 + 1;
    }
    ((func_80255D10_S1 *)(o))->unk10 = v0;
}

void func_80255ED8_de(void *arg0, s32 arg1) {
    s32 next;
    s32 prev;

    next = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unk8);
    if (next != 0) {
        s32 off = ((func_80239CDC_S1 *)(arg0))->unkC;
        *(s32 *)(next + off) = *(s32 *)(arg1 + off);
    }
    prev = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unkC);
    if (prev != 0) {
        s32 off = ((func_80239CDC_S1 *)(arg0))->unk8;
        *(s32 *)(prev + off) = *(s32 *)(arg1 + off);
    }
    if (*(s32 *)arg0 == arg1) {
        *(s32 *)arg0 = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unkC);
    }
    if (((func_80239CDC_S1 *)(arg0))->unk4 == arg1) {
        ((func_80239CDC_S1 *)(arg0))->unk4 = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(arg0))->unk8);
    }
    ((func_80239CDC_S1 *)(arg0))->unk10 = ((func_80239CDC_S1 *)(arg0))->unk10 - 1;
}

/** Advance the cursor by its stride and decrement its remaining count. */
void func_80255F70_de(void *arg0) {
    char *cursor = *(char **)arg0;
    int stride = ((func_80203B60_S2 *)(arg0))->unkC;
    int value = *(int *)(cursor + stride);
    int count = ((func_80203B60_S2 *)(arg0))->unk10 - 1;
    ((func_80203B60_S2 *)(arg0))->unk10 = count;
    *(int *)arg0 = value;
}

/** Advance the cursor by its stride and decrement its remaining count. */
void func_80255F94_de(void *arg0) {
    char *cursor = ((func_80255F34_S1 *)(arg0))->unk4.v0;
    int stride = ((func_80255F34_S1 *)(arg0))->unk8;
    int value = *(int *)(cursor + stride);
    int count = ((func_80255F34_S1 *)(arg0))->unk10 - 1;
    ((func_80255F34_S1 *)(arg0))->unk10 = count;
    ((func_80255F34_S1 *)(arg0))->unk4.v1 = value;
}

void func_80255FB8_de(void *arg0, s32 arg1) {
    char *o = (char *)arg0;
    s32 next;
    s32 prev;
    s32 head;

    next = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8);
    if (next != 0) {
        s32 off = ((func_80239CDC_S1 *)(o))->unkC;
        *(s32 *)(next + off) = *(s32 *)(arg1 + off);
    }
    prev = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC);
    if (prev != 0) {
        s32 off = ((func_80239CDC_S1 *)(o))->unk8;
        *(s32 *)(prev + off) = *(s32 *)(arg1 + off);
    }
    if (*(s32 *)o == arg1) {
        *(s32 *)o = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC);
    }
    if (((func_80239CDC_S1 *)(o))->unk4 == arg1) {
        ((func_80239CDC_S1 *)(o))->unk4 = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8);
    }
    ((func_80239CDC_S1 *)(o))->unk10 = ((func_80239CDC_S1 *)(o))->unk10 - 1;

    head = *(s32 *)o;
    if (head != 0) {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC) = head;
        *(s32 *)(*(s32 *)o + ((func_80239CDC_S1 *)(o))->unk8) = arg1;
    } else {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC) = 0;
        ((func_80239CDC_S1 *)(o))->unk4 = arg1;
    }
    *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8) = 0;
    *(s32 *)o = arg1;
    ((func_80239CDC_S1 *)(o))->unk10 = ((func_80239CDC_S1 *)(o))->unk10 + 1;
}

void func_802560A4_de(void *arg0, s32 arg1) {
    char *o = (char *)arg0;
    s32 next;
    s32 prev;
    s32 tail;

    next = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8);
    if (next != 0) {
        s32 off = ((func_80239CDC_S1 *)(o))->unkC;
        *(s32 *)(next + off) = *(s32 *)(arg1 + off);
    }
    prev = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC);
    if (prev != 0) {
        s32 off = ((func_80239CDC_S1 *)(o))->unk8;
        *(s32 *)(prev + off) = *(s32 *)(arg1 + off);
    }
    if (*(s32 *)o == arg1) {
        *(s32 *)o = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC);
    }
    if (((func_80239CDC_S1 *)(o))->unk4 == arg1) {
        ((func_80239CDC_S1 *)(o))->unk4 = *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8);
    }
    ((func_80239CDC_S1 *)(o))->unk10 = ((func_80239CDC_S1 *)(o))->unk10 - 1;

    tail = ((func_80239CDC_S1 *)(o))->unk4;
    if (tail != 0) {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8) = tail;
        *(s32 *)(((func_80239CDC_S1 *)(o))->unk4 + ((func_80239CDC_S1 *)(o))->unkC) = arg1;
    } else {
        *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unk8) = 0;
        *(s32 *)o = arg1;
    }
    *(s32 *)(arg1 + ((func_80239CDC_S1 *)(o))->unkC) = 0;
    ((func_80239CDC_S1 *)(o))->unk4 = arg1;
    ((func_80239CDC_S1 *)(o))->unk10 = ((func_80239CDC_S1 *)(o))->unk10 + 1;
}

extern s32 func_802744D4_de(void);




void *func_80256190_de(void *arg0) {
    s32 index;
    s32 offset;
    void *node;

    node = *(void **)arg0;
    if (node == 0) {
        return 0;
    }
    index = func_802744D4_de() % ((func_80256130_S1 *)(arg0))->unk10;
    index--;
    if (index != -1) {
        offset = ((func_80256130_S1 *)(arg0))->unkC;
        do {
            { u8 *cursor = (u8 *)node; cursor += offset; node = *(void **)cursor; }
            index--;
        } while (index != -1);
    }
    return node;
}

void func_80256214_de(void *arg0) {
    s32 node = *(s32 *)arg0;
    if (node != 0) {
        s32 offset = ((func_80205628_S3 *)(arg0))->unkC;
        node = *(s32 *)(node + offset);
        while (node != 0) {
            node = *(s32 *)(node + offset);
        }
    }
}

int func_8025623C_de(void *arg0, int arg1) {
    int node = *(int *)arg0;
    if (node != 0) {
        do {
            if (node == arg1) {
                return 1;
            }
            node = *(int *)(node + ((func_80205628_S3 *)(arg0))->unkC);
        } while (node != 0);
    }
    return 0;
}
