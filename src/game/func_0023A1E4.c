#include "b08_types.h"

typedef struct ObjBuf {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 padC[0x34];
    s32 unk40;
} ObjBuf;

void func_0025E410(void *p);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);

void func_0023A1E4(u8 *o) {
    ObjBuf *b = (ObjBuf *)o;

    *(s32 *)(o + 0x1200) = 1;
    func_0025E410(o + 0x40);
    func_002538A8(0);
    if (b->unk0 != 0) {
        func_002537D8(0, b->unk0);
        b->unk0 = 0;
        b->unk4 = 0;
        b->unk8 = 0;
    }
}
