#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802624A0.h"
#include "version_calls.h"
/* Spawns the effect of an item variant: resolves the variant's effect id, loads its descriptor and first record, takes the effect count from the record's model and turns the colour vector by the record's angle, then spawns the effect through the inline spawner of func_80262A9C_de with the given owner, position, scale, direction and counted reference, releasing both resources. Adapted from func_80262A9C_de with the descriptor loading added. */
#include "types.h"
extern s32 D_800CD764_de;
extern s32 D_800CD8D0;
extern s32 D_8013B290;
extern struct Pool_func_802627A0_de {
    char pad0[0x24];
    s32 count;
    char pad28[0x54 - 0x28];
    s32 table;
} D_8011FE88;
extern char D_800C4260_de;
extern char D_800C4274_de;
extern s32 func_8028FE28_de(s32, s32, s32);
extern void **func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, void *, s32);
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern void *func_8028FDB4_de(void *, s32);
extern s32 func_8028CF6C_de(void *, s32);
extern f32 func_802B2350(s32);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80253754_de(s32, void **);
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
Effect_func_80262A9C_de *func_802627A0_de(void *scene, s32 variant, s32 owner, Vec3 position, f32 scale, Vec3 direction,
                      Vec3 color, s32 *ref) {
    Effect_func_80262A9C_de *effect;
    s32 id;
    s32 key;
    void **descriptor;
    void **resource;
    Record_func_802627A0_de *record;
    s32 count;
    s32 size;
    s32 clip;
    effect = 0;
    id = func_8028B21C_de(&D_8011FE88, variant);
    if (id != -1) {
        key = func_8028FE28_de(D_8011FE88.table, D_8011FE88.count, id);
        descriptor = func_8025193C_de(0, key, key, 0x18, 0, 0, 0, &D_800C4260_de, 1);
        if (descriptor != 0) {
            clip = func_8028FE3C_de(*descriptor, key, 0, &size);
            resource = func_8025193C_de(0, clip, clip, size, 0, 0, 0, &D_800C4274_de, 1);
            if (resource != 0) {
                record = func_8028FDB4_de(*resource, 0);
                count = func_8028CF6C_de(&D_8011FE88, record->count);
                func_80271F9C_de(&color, &color, func_802B2350(record->angle));
                effect = spawn_effect(scene, id, variant, count, owner, position, scale, direction, color, ref);
                func_80253754_de(0, resource);
            }
            func_80253754_de(0, descriptor);
        }
    }
    return effect;
}
