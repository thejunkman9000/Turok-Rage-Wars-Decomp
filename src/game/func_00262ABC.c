#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802624A0.h"
#include "types.h"
/* Spawns the effect a description asks for: the spawn of func_80262CE0_de (id resolution, free node, init
 * through func_802466A0_de and start) inlined with the id, variant, count, owner, position, scale, direction
 * and colour taken from the description record and no counted reference. Adapted from func_80262CE0_de with
 * the enabled and count tests as separate early returns. */







extern char D_8011FE88;
extern s32 D_800CD764_de;
extern s32 D_800CD8D0;
extern s32 D_8013B290;

extern s32 func_8028B21C_de(void *, s32);
extern s32 func_8028B25C_de(void *, s32);
extern void func_80255ED8_de(void *, Effect_func_80262A9C_de *);
extern void func_80255CB8_de(void *, Effect_func_80262A9C_de *);
extern void func_802466A0_de(Effect_func_80262A9C_de *, s32, s32, s32, s32, s32, s32, f32, Vec3, s32, Vec3, Vec3, s32);
extern void func_8024B2D0_de(Effect_func_80262A9C_de *);





static inline Effect_func_80262A9C_de *take_effect(void *scene, s32 *ref) {
    Effect_func_80262A9C_de *effect;

    if (D_8013B290 == 0 && (unsigned int)((func_80262ABC_S1 *)(scene))->unk5F24 >= 3) {
        return 0;
    }
    effect = ((func_80262ABC_S1 *)(scene))->unk5F00.v0;
    if (effect != 0) {
        func_80255ED8_de(&((func_80262ABC_S1 *)(scene))->unk5F00.v1, effect);
        func_80255CB8_de(&((func_80262ABC_S1 *)(scene))->unk5F14, effect);
        effect->ref = ref;
        if (ref != 0) {
            *ref += 1;
        }
    }
    return effect;
}

static inline Effect_func_80262A9C_de *spawn_effect(void *scene, s32 id, s32 variant, s32 count, s32 owner, Vec3 position,
                                   f32 scale, Vec3 direction, Vec3 color, s32 *ref) {
    Effect_func_80262A9C_de *effect;

    if (D_800CD764_de == 0) {
        return 0;
    }
    if (count == 0) {
        return 0;
    }
    if (id == -1) {
        id = func_8028B21C_de(&D_8011FE88, variant);
        if (id == -1) {
            return 0;
        }
    }
    if ((unsigned int)(variant + 1) < 2) {
        variant = func_8028B25C_de(&D_8011FE88, id);
    }
    effect = take_effect(scene, ref);
    if (effect == 0) {
        return 0;
    }
    func_802466A0_de(effect, id, variant, D_800CD8D0, count, -1, owner, scale, position, 0x80000, color, direction, 0);
    func_8024B2D0_de(effect);
    return effect;
}

Effect_func_80262A9C_de *func_80262A9C_de(void *scene, EffectDesc *desc) {
    return spawn_effect(scene, desc->id, desc->variant, desc->count, desc->owner, desc->position, desc->scale,
                        desc->direction, desc->color, 0);
}
