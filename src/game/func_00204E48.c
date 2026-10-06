#include "b01_types.h"

typedef struct Msg204E48 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ u16 unkA;
} Msg204E48;

extern u8 D_8011FE88[];
void func_0028B64C(void *mgr, u16 a, u16 b, s32 flag);

void func_00204E48(Msg204E48 *msg) {
    func_0028B64C(D_8011FE88, msg->unkA, msg->unk4, 0);
}
