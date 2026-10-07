#include "b02_types.h"

s32 func_0020CC0C(B2Mgr *m, s32 x, s32 y);
void func_0020D014(B2Mgr *m);
void func_0020EDCC(B2Ctl *ctl);
void func_0020EE50(B2Ctl *ctl);
void func_0020EEA4(B2Ctl *ctl);
void func_0020EC14(B2Ctl *ctl);
void func_0020D1FC(B2Mgr *m);
void func_0020D220(B2Mgr *m, s32 key);
void func_0020D0CC(B2Mgr *m, s32 key);
void func_0020D114(B2Mgr *m, s32 *out, s32 n);
extern B2Mgr D_8013B364;

s32 func_0020EAE0(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;

    if (m == NULL) {
        return 1;
    }
    if (ctl->unkC == -1) {
        return 1;
    }
    if (ctl->unk4 == ctl->unkC) {
        return 1;
    }
    if (ctl->unk28 == ctl->unkC && ctl->q[0] != -1 && ctl->q[1] != -1) {
        if (ctl->unk4 == ctl->q[0]) {
            return 1;
        }
        if (func_0020CC0C(m, ctl->unk4, ctl->q[0]) != -1) {
            return 1;
        }
    }
    func_0020D014(m);
    if (ctl->unk2F4 != 0) {
        func_0020EDCC(ctl);
    }
    if (ctl->unk2F8 != 0) {
        func_0020EE50(ctl);
    }
    if (ctl->unk2FC != 0) {
        func_0020EEA4(ctl);
    }
    func_0020EC14(ctl);
    func_0020D1FC(m);
    func_0020D220(m, ctl->unkC);
    m->unk18 = -1;
    func_0020D0CC(m, ctl->unk4);
    func_0020D114(m, ctl->q, 4);
    ctl->unk1BC = 0;
    ctl->unk1C0 = -1;
    ctl->unk28 = ctl->unkC;
    return 1;
}
