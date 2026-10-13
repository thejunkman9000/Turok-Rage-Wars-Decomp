#include "m01_types.h"

extern M1World D_80145040[];
typedef struct V3W { M1Actor *head; u8 p4[0x24]; u8 w28[0x1240]; u8 w1268[0x600]; } V3W;
extern V3W D_80145060;
extern u8 D_80145088[];
extern s32 D_auto_800E0D14[];
M1Actor *func_0022A410(void *world);
void func_0025DF54(s32 id);
void func_0022E16C(M1Actor *a, M1Actor *b, s32 n);
void func_00237E70(u8 *p, void *pawn, s32 v);
void func_00214178(M1Actor *a, M1State *s, s32 n);

void func_auto_00204030(M1Actor *actor, M1State *state) {
    M1Info *info = &actor->def->info;
    M1Actor *pl;
    M1Blk *blk;
    M1Blk *blk2;
    M1Stats *st;
    Vec3f dv;
    s32 d;
    s32 id;

    switch (actor->unkE4) {
    case 0x64E:
        pl = func_0022A410(D_80145040);
        if (pl != NULL && pl->unk5E4 != 0 && state->unk36 != state->unk34) {
            blk = &D_80145040->blk;
            if (blk->unk68 == 0 && state->unk12C.i == 0) {
                st = pl->stats;
                if (st->b8F == 1) {
                    st->b8F = 0;
                    pl->stats->b90 = 1;
                    blk->unk74 = 1;
                    state->unk12C.i = 1;
                    func_0025DF54(0xE0D);
                }
            }
        }
        break;
    case 0x653:
    case 0x654:
    case 0x655:
    case 0x656:
        if (state->unk36 == state->unk34) return;
        pl = func_0022A410(D_80145040);
        if (pl == NULL) return;
        if (pl->stats->b8F == 0) return;
        dv.x = pl->pos.x - actor->pos.x;
        dv.y = pl->pos.y - actor->pos.y;
        dv.z = pl->pos.z - actor->pos.z;
        d = (s32)sqrtf(dv.x * dv.x + dv.y * dv.y + dv.z * dv.z);
        if (!((f32)d < 122.88f)) return;
        {
            pl->stats->b8F = 0;
            pl->stats->b90 = 1;
            pl->stats->h8++;
            func_0022E16C(pl, pl, 3);
            blk2 = &D_80145040->blk;
            blk2->unk84 = 0;
            blk2->unk80 = 0;
            switch (pl->stats->b92) {
            case 0: id = 0x2E6; break;
            case 1: id = 0x2E4; break;
            case 2: id = 0x2E8; break;
            case 3: id = 0x2EC; break;
            case 4: id = 0x2EA; break;
            default: goto after;
            }
            func_0025DF54(id);
after:
            {
            u8 *g;
            u8 *w;
            pl = D_80145060.head;
            if (pl != NULL) {
            w = D_80145060.w28;
            g = D_80145060.w1268;
            for (; pl != NULL; pl = pl->next) {
                if (pl->pawn != NULL) {
                    func_00237E70(w, pl->pawn, D_auto_800E0D14[g[0x581]]);
                }
            }
            }
            }
        }
        break;
    }
    if (state->unkCB != 0) {
        if (info->flags & 2) {
            actor->flags &= ~0x2000;
            actor->flags &= ~0x100;
        }
        if (state->unk128.i != 0) {
            func_00214178(actor, state, 0);
        }
        if (actor->unkE4 == 0x64C) {
            func_00214178(actor, state, 2);
        }
    }
}
