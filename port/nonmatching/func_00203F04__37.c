#include "b01_types.h"
#include "m01_types.h"

extern B01Actor **D_80103FCC;
extern u8 D_80103FD0[];
void func_00271FD8(Vec3f *dst, Vec3f *a, Vec3f *b);
f32 func_0024D274(B01Actor *actor);
s32 func_00244494(B01Actor *actor, Vec3f from, Vec3f to, void *hit);
typedef struct { s32 a, b, c; } IV3;
extern M1World D_80145040[];
extern M1Actor *D_80145060;
extern u8 D_80145088[];
extern s32 D_800D70DC;
M1Actor *func_0022A410(void *world);
void func_0025DF54(s32 id);
void func_0022E16C(M1Actor *a, M1Actor *b, s32 n);
void func_00237E70(u8 *p, void *pawn, s32 v);
void func_00214178(M1Actor *a, M1State *s, s32 n);

s32 func_00203F04(B01Actor *actor, B01State *state, B01Actor *target) {
    Vec3f from;
    Vec3f to;
    func_00271FD8(&to, &target->pos, &actor->pos);
    from.x = state->vec130.x;
    from.y = state->vec130.y;
    from.z = state->vec130.z;
    *(IV3 *)&from = *(IV3 *)&actor->pos;
    from.y += func_0024D274(actor) * 0.5f;
    *(IV3 *)&to = *(IV3 *)&target->pos;
    to.y += func_0024D274(target) * 0.5f;
    if (func_00244494(actor, from, to, D_80103FD0) != 0) {
        if (*D_80103FCC != target) {
            return 0;
        }
    }
    return 1;
}

void func_0020402C(M1Actor *actor, M1State *state) {
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
            for (pl = D_80145060; pl != NULL; pl = pl->next) {
                if (pl->pawn != NULL) {
                    func_00237E70(D_80145088, pl->pawn, D_800D70DC);
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
