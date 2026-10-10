#include "span_1000/code_802106E0.h"
#include "span_1000/code_80208000.h"
#include "types.h"

extern s32 D_800D297C;
extern char D_8013B364[];
extern void func_80211020_de(void *);
extern s32 func_802099B4_de(void **, void *);
extern s32 func_80209874_de(void *, s32);
extern f32 func_802726BC_de(f32 *, f32 *);
extern f32 func_80209BE0_de(void **);
extern s32 func_802744D4_de(void);
extern f32 func_80209DAC_de(void *);
extern f32 func_80209308_de(Brain_func_80209308_de *, Vec3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void func_80210964_de(void *, s32);
extern void func_80209E80_de(void *);
#include "shared/route_relation_grid.h"
extern void func_80208410_de(void *);
extern void func_80208AAC_de(void *);

/* Update the rider close-attack state using the existing close-attack records.
 * Callee-specific views share the same measured incoming actor/brain pointer. */
void func_8021113C_eu(CloseAttackActor *actor) {
    s32 mine, theirs, dir, route;
    CloseAttackActor *player;
    CloseAttackActor *target;
    CloseAttackBrain *brain;
    f32 speed;
    s32 pattern;

    brain = actor->self->brain;
    func_80211020_de(brain);
    player = brain->target;
    if (player != 0) {
        if (!(brain->frames & 3)) {
            brain->visible = func_802099B4_de((void **)brain, player);
        }
        brain->frames += 1;
        target = brain->target->self;
        mine = brain->player->flags & 0x3000;
        theirs = (target->flags & 0x3000) != 0;
        if (mine && !theirs) {
            func_80209874_de(brain, 12);
            return;
        }
        route = target->brain->route;
        if (brain->visible != 0) {
            if (func_802726BC_de(&target->pos.x, &brain->player->pos.x) < 360000.0f) {
                brain->combat = 3;
                func_80209874_de(brain, 7);
                return;
            }
            speed = func_80209BE0_de((void **)brain) * 0.4f;
            if (--brain->timer <= 0) {
                brain->timer = func_802744D4_de() % 4 + 12;
                brain->pattern = func_802744D4_de() % 2;
                if (func_802744D4_de() % 2 == 1) {
                    brain->pattern = 2;
                }
            }
            func_80209308_de((Brain_func_80209308_de *)brain, &target->pos, 2.0f, func_80209DAC_de(brain));
            pattern = brain->pattern;
            if (pattern == 0) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) - 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (!(brain->walk[dir] < 100.0f)) {
                    brain->player->strafe = -speed;
                } else {
                    goto halt;
                }
            } else if (pattern == 1) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) + 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (brain->walk[dir] < 100.0f) {
halt:
                    brain->player->strafe = 0.0f;
                    brain->pattern = 2;
                } else {
                    brain->player->strafe = speed;
                }
            } else {
                brain->player->strafe = 0.0f;
            }
            brain->w14 = -1;
            func_80209E80_de(brain);
        } else {
            brain->destination = route;
            func_80208410_de(brain);
            func_80208AAC_de(brain);
        }
        if (route != brain->node) {
            brain->node = route;
            if (func_8020D1CC_de(D_8013B364, brain->route, route) == 0) {
                func_80209874_de(brain, 1);
            }
        }
    }
}
