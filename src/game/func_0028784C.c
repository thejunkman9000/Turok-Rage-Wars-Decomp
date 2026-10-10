#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80286050.h"
#include "types.h"

/* Spawns an entity through func_80278C10_de when its bit is set in the current level's placement mask and it either names no flag or its flag in the global flag table D_8011FF08 is clear. */





extern void *D_8011FF08;
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_8028FDF8_de(void *table, s32 index);
extern void func_80278C10_de(Entity *entity);

void func_8028787C_de(World_func_8028787C_de *world, Entity *entity) {
    s32 index;
    s32 level;
    void *mask;
    unsigned char *bits;
    void *flags;
    s32 flag;
    s32 bit;

    index = entity->index;
    level = world->level;
    mask = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(world->levels, 0), level), 2);
    func_8028FDB4_de(mask, 0);
    func_8028FDF8_de(mask, 1);
    bits = func_8028FDB4_de(mask, 1);
    bit = 1 << (index & 7);
    if (bits[index / 8] & bit) {
        if (entity->flag != 0) {
            flag = entity->flag;
            flags = func_8028FDB4_de(D_8011FF08, 1);
            func_8028FDB4_de(flags, 0);
            if (((unsigned char *)func_8028FDB4_de(flags, 1))[flag] != 0) {
                return;
            }
        }
        func_80278C10_de(entity);
    }
}
