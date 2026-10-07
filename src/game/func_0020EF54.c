#include "b02_types.h"

void func_0020D014(B2Mgr *m);
void func_0020D1FC(B2Mgr *m);
void func_0020D0CC(B2Mgr *m, s32 key);
void func_0020D114(B2Mgr *m, s32 *out, s32 n);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
s32 func_0020F150(s32 *ids);
extern B2Mgr D_8013B364;

s32 func_0020EF54(B2Ctl *ctl) {
    B2Mgr *m;
    s32 ids[30];
    s32 i;
    s32 id;
    B2Node *n;

    if (ctl->unk68 != 0) {
        return 1;
    }
    m = &D_8013B364;
    for (i = 29; i >= 0; i--) {
        ids[i] = 0;
    }
    switch (ctl->unkBC) {
    case 0:
        ids[0] = 0xBC6;
        ids[1] = 0xBC7;
        ids[2] = 0xBC4;
        ids[3] = 0xBC5;
        ids[4] = 0xBC8;
        ids[5] = 0xBC9;
        ids[6] = 0x6BA;
        ids[7] = 0x6BB;
        break;
    case 1:
        ids[0] = 0x6BA;
        ids[1] = 0x6BB;
        break;
    case 2:
        ids[0] = 0x6BA;
        break;
    case 3:
        ids[0] = 0x6BB;
        break;
    case 4:
        ids[0] = 0xBC6;
        ids[1] = 0xBC7;
        ids[2] = 0xBC4;
        ids[3] = 0xBC5;
        ids[4] = 0xBC8;
        ids[5] = 0xBC9;
        break;
    case 5:
        ids[0] = 0xBC6;
        ids[1] = 0xBC7;
        break;
    case 6:
        ids[0] = 0xBC4;
        ids[1] = 0xBC5;
        break;
    case 7:
        ids[0] = 0xBC8;
        ids[1] = 0xBC9;
        break;
    }
    if (ids[0] != 0) {
        func_0020D014(m);
        func_0020D1FC(m);
        if (func_0020F150(ids) == 0) {
            ctl->unk68 = NULL;
            ctl->unkBC = -1;
            return 1;
        }
        m->unk18 = -1;
        func_0020D0CC(m, ctl->unk4);
        id = m->unk18;
        if (id != -1) {
            n = func_0020CFE0(m, id);
            ctl->unkC = m->unk18;
            ctl->unk68 = n->unk34;
            func_0020D114(m, ctl->q, 4);
            return 1;
        }
        ctl->unk68 = NULL;
        ctl->unkBC = id;
    } else {
        ctl->unk68 = NULL;
        ctl->unkBC = -1;
    }
    return 1;
}
