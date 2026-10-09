
#include "r08_types.h"

typedef struct R8Cfg { u8 pad0[0x14]; s32 unk14; } R8Cfg;
typedef struct R8Actor { u8 pad0[0x60]; R8Mtx mtx[2]; u8 padE0[0x38]; R8Cfg *cfg; } R8Actor;
typedef struct R8Mgr { u8 pad0[0x7528]; R8Emit *list; } R8Mgr;

extern s32 D_800D297C;
extern u8 D_8013BA80[];

void func_002702EC(void *, void *);
void func_00270980(void *, void *);
void func_00272898(void *);
void func_00273340(void *, void *);
void func_0027335C(void *, void *);
void func_002734EC(void *, f32, f32, f32);
void func_002A35C0(void *, void *, void *);

void func_002A52E4(R8Mgr *mgr, R8Actor *who) {
    u8 sp10[0x40];
    R8Emit *e;
    R8Part *p;
    f32 k;
    s32 i;
    u8 *dst, *src;

    e = mgr->list;
    if (e == NULL) {
        return;
    }
    do {
        if (e->flags & 8) {
            p = e->parts;
            if (p != NULL) {
                do {
                    if (p->owner == (s32)who) {
                        if (who != NULL) {
                            if ((s32)who == -1) {
                                p->mtx[D_800D297C] = p->mtx[D_800D297C ^ 1];
                                p->owner = 0;
                            } else {
                                func_00270980(sp10, &who->mtx[D_800D297C]);
                                k = 0.01f;
                                if (who->cfg->unk14 != 0) {
                                    k = 0.29257143f;
                                }
                                func_002734EC(sp10, k, k, k);
                                func_00272898(sp10);
                                func_00273340(sp10, p->unk10);
                                if (e->flags & 4) {
                                    func_0027335C(sp10, (u8 *)p + 0x1C);
                                } else {
                                    func_002702EC(sp10, &p->mtx[D_800D297C]);
                                }
                            }
                            p->unk8 = e->info->unk8;
                        }
                        p->owner = -1;
                    }
                    p = p->next;
                } while (p != NULL);
            }
        } else if ((R8Actor *)e->owner == who) {
            if (e->flags & 2) {
              register s32 t asm("$2") = D_800D297C;
              register u8 *wm asm("$5") = (u8 *)((t << 6) + (s32)who);
              __asm__("" : "+r"(wm));
              if (e->unk24 > 0.0f) {
                wm += 0x60;
                func_00270980(sp10, wm);
                k = 0.01f;
                if (who->cfg->unk14 != 0) {
                    k = 0.29257143f;
                }
                func_002734EC(sp10, k, k, k);
                func_00272898(sp10);
                func_002A35C0(D_8013BA80, e, sp10);
              }
            }
            if (e->owner != NULL) {
                if (e->flags & 1) {
                    if (e->owner->unk13B != 0) {
                        e->owner->unk13B = e->owner->unk13B - 1;
                    }
                }
                if (e->flags & 2) {
                    if (e->owner->unk1D9 != 0) {
                        e->owner->unk1D9 = e->owner->unk1D9 - 1;
                    }
                }
            }
            e->owner = NULL;
            if (e->unk24 < e->info->unk4) {
                e->unk24 = e->info->unk4;
            }
        }
        e = e->next;
    } while (e != NULL);
}


