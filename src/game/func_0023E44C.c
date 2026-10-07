#include "b09_types.h"

extern B09Obj2 *D_80103FCC;

void func_0023E44C(B09SrcObj *a) {
    switch (a->type) {
    case 1:
    case 2:
    case 3:
    case 4:
        D_80103FCC->unk0 = (s32)a->ref;
        if (a->ref != NULL) {
            D_80103FCC->unk4 = a->ref->w14;
        } else {
            D_80103FCC->unk4 = 0;
        }
        D_80103FCC->v8 = a->v180;
        D_80103FCC->unk14 = -1;
        break;
    case 5:
        if (a->ref != NULL) {
            D_80103FCC->unkC4 = a->ref->w14;
        } else {
            D_80103FCC->unkC4 = 0;
        }
        D_80103FCC->vC8 = a->v180;
        D_80103FCC->unkD4 = a->unkBC;
        break;
    case 7:
        D_80103FCC->unk0 = (s32)a->ref;
        D_80103FCC->unk4 = a->ref->w14;
        D_80103FCC->v8 = a->v180;
        D_80103FCC->unk14 = -1;
        break;
    case 8:
        D_80103FCC->unk0 = (s32)a->ref;
        D_80103FCC->unk4 = a->ref->w14;
        D_80103FCC->v8 = a->v180;
        D_80103FCC->unk14 = a->unk108;
        D_80103FCC->blk18 = a->blk10C;
        break;
    case 9:
        D_80103FCC->unk88 = (s32)a->ref;
        D_80103FCC->unk8C = a->ref->w14;
        D_80103FCC->v90 = a->v180;
        break;
    }
    D_80103FCC->vF0 = a->vF8;
    D_80103FCC->vE4 = a->v180;
    D_80103FCC->unkFC = a->type;
    D_80103FCC->unk100 = a->unkC0;
}
