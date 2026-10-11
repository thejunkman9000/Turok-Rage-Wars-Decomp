/* their2 */
#include "types.h"
#include "s1006_types.h"

/* Spawns the level's actors from the loaded placement resource (upstream func_8044C7B8_de):
   allocates a buffer of count 0x2E8-byte actors (8-byte header), initialises every actor from its 0x28-byte
   placement record, resolves the actor definitions, and for the first record and every record of type 0xB
   (player start) places each player on a spawn point object found through func_0044DE70 (angle clamped to
   +-pi and scaled to a short); afterwards links every remaining actor to the nearest actor of the same
   definition.  3.1415927f * 10430.06f folds to 32767.0f, hence the integer constants of the ROM's clamp. */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern s32 func_00285150(void ***handle, s32 arg1);
extern s32 func_0028B370(S6World *world, s32 arg1);
extern void **func_00254420(s32 arg0, void ***handle, s32 size);
extern void func_0028FEEC(void *src, void *dst, s32 flag);
extern s32 func_0044E038(S6World *world, void *a1, s32 group, void *a3);
extern s32 func_0044DE70(S6World *world, s32 kind, s32 key, S6Obj *out, s32 max);
extern s32 *func_0028CF48(S6World *world, u16 id);
extern void func_0024B398(S6Actor *actor, S6Rec *rec, s32 a2, s32 i);
extern s32 func_002866F8(S6World *world, void *pos);
extern void func_00449970(void *player, S6Rec *rec, s32 a2, s32 i);
extern void func_00274090(f32 *v);
extern s32 func_0024DDA4(S6Actor *a);
extern s32 func_0024DD7C(S6Actor *a);
extern f32 func_00217224(S6Actor *a, f32 x, f32 y, f32 z);
extern void func_00253CB0(s32 arg0, void ***handle, void **node);

extern S6V3 D_80145100;
extern s32 D_80145120;
extern u8 *D_80145044;
extern s32 D_80145048;
extern S6Cfg D_80146398[];

void func_0044D408(S6World *world, void ***handle) {
    S6Obj objs[8];
    S6Obj special;
    s32 count;
    S6Actor *actors;
    s32 mode;
    void **blk;
    s32 nobj;
    void *node;
    s32 *hdr;
    S6Rec *recs;
    S6Rec *rec;
    S6Actor *actor;
    S6Actor *other;
    S6Obj *obj;
    u8 *pl;
    S6Cfg *cfg;
    S6Cfg *cfg0 = D_80146398;
    f32 best;
    f32 d;
    s32 i;
    s32 j;
    s32 p;
    s32 idx;

    if (func_00285150(handle, 1) != 0) {
        mode = func_0028B370(world, 0);
        node = **handle;
        count = ((s32 *)node)[1];
        blk = func_00254420(0, handle, count * 0x2E8 + 8);
        if (blk != 0) {
            func_0028FEEC(node, *blk, 1);
            hdr = (s32 *)*blk;
            hdr[0] = 0x2E8;
            hdr[1] = count;
            recs = (S6Rec *)((u8 *)node + 8);
            actors = (S6Actor *)(hdr + 2);
            if (world->ready == 0) {
                world->key = func_0044E038(world, (u8 *)node + 0xC, world->group, world->cache);
                if (world->key != 0) {
                    world->ready = 1;
                }
            }
            idx = 0;
            nobj = 0;
            if (world->ready != 0) {
                nobj = func_0044DE70(world, world->group, world->key, objs, 8);
            }
            world->actors = actors;
            world->nActors = count;
            for (i = 0; i < count; i++) {
                rec = &recs[i];
                actor = &actors[i];
                actor->def = func_0028CF48(world, rec->id);
            }
            world->nSpawned = 0;
            for (i = 0; i < count; i++) {
                rec = &recs[i];
                func_0024B398(&actors[i], rec, mode, i);
                if (*func_0028CF48(world, rec->id) == 0xB || i == 0) {
                    world->nSpawned++;
                    D_80145100 = rec->pos;
                    D_80145100.y += 204.79999f;
                    D_80145120 = func_002866F8(world, &rec->pos);
                    for (p = 0; p < D_80145048; p++) {
                        pl = D_80145044 + p * 0x16E8;
                        cfg = cfg0 + p;
                        if (nobj != 0) {
                            if (cfg->kind == 0xC && *(s32 *)(pl + 0x1450) != 0 && world->group == 9) {
                                func_0044DE70(world, 9, 0xC1D, &special, 1);
                                obj = &special;
                            } else {
                                obj = &objs[idx];
                            }
                            rec->unk20 = obj->unk12;
                            func_00274090(&obj->ang);
                            rec->angle = (s16)(MAX(-3.1415927f, MIN(3.1415927f, obj->ang)) * 10430.06f);
                            rec->pos = obj->pos;
                            world->unk1B614 = 0;
                            world->unk1B618 = 0;
                            world->unk1B61C = 0;
                            idx++;
                            if (idx >= nobj) {
                                idx = 0;
                            }
                        }
                        func_00449970(pl, rec, mode, i);
                    }
                }
            }
            for (i = world->nSpawned; i < count; i++) {
                actor = &actors[i];
                best = 3.4028235e+38f;
                actor->nearest = 0;
                if (func_0024DDA4(actor) != 0) {
                    for (j = world->nSpawned; j < count; j++) {
                        other = &actors[j];
                        if (*actor->def == *other->def && func_0024DD7C(other) != 0 && actor != other) {
                            if (actor->nearest != 0) {
                                d = func_00217224(actor, other->pos.x, other->pos.y, other->pos.z);
                                if (d < best) {
                                    actor->nearest = other;
                                    best = d;
                                }
                            } else {
                                actor->nearest = other;
                                best = func_00217224(actor, other->pos.x, other->pos.y, other->pos.z);
                            }
                        }
                    }
                }
            }
        }
        func_00253CB0(0, handle, blk);
        world->unkF58 = 0;
    }
}
