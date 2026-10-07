#include "b02_types.h"

s32 func_0020CB3C(B2Mgr *m, Vec3f *p);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
extern B2Mgr D_8013B364;
extern B2Row D_80121990[];
extern const f32 D_800C6F50;

void func_0020EC14(B2Ctl *ctl) {
    register B2Mgr *m asm("$17") = &D_8013B364;
    B2Actor *n;
    B2Actor *p;
    register s32 i asm("$19");
    u8 *row;
    s32 off;

    if (m != NULL) {
        row = (u8 *)D_80121990;
        off = 0xFC28;
        for (i = 0; i < 3; i++, row += 0x14) {
            for (n = *(B2Actor **)(row + off); n != NULL; n = n->next1EC) {
                switch (n->type) {
                case 0x41E:
                    p = n->unk12C;
                    if (p == NULL) {
                        break;
                    }
                    if (p->kind != 1) {
                        break;
                    }
                    if ((p->flags & 0x300000) == 0) {
                        break;
                    }
                    if (p == ctl->owner) {
                        break;
                    }
                case 0x402:
                case 0x404:
                case 0x40B:
                case 0x40F:
                    func_0020CFE0(m, func_0020CB3C(m, &n->pos))->unk18 = D_800C6F50;
                    break;
                }
            }
        }
    }
}
