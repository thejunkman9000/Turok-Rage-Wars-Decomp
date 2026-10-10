#include "span_C76B0/data.h"
#include "common/data.h"
#include "types.h"
#include "common/unused.h"

/* Spawns the effects that template block 2 of the system lists for a kind: for each template in the kind's range it filters by player mask, existing owner effects, anchor distance, mode, team flags and a percent chance, builds a spawn matrix (source matrix, mirror, translation or rotation), then for a random count allocates effects, fills their timing, spread, colour, render and direction fields from the template's packed floats, links them into their group, aims shots at the held target for kinds 0x2D and 0x4F, and plays their sound. Returns the number spawned. */

/* These canonical scalar owners are immutable ROM rodata. */

extern Shared_GlobalRuntimeState D_80145060;
extern EffectTarget *D_80103FCC;
extern EffectTarget D_801041F0;

extern Vec3 D_801042C8;

extern func_8028414C_S1 *D_80140FE8_de;
extern s32 D_80140FF8;

extern u8 D_801462E5;
extern s32 D_800D297C;

extern f32 D_800CD6B0;

extern EffectBlock *func_8028FDB4_de(s32, s32);
extern s32 func_80265550_de(EffectEntry *, s32, s32, s32 *, s32 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_8027207C_de(Vec3 *);
extern void func_80272898_de(void *, void *, void *);
extern void func_80272B38_de(Matrix_func_80213CF8_de *, Vec3 *, Vec3 *);
extern void func_80272CB0_de(Matrix_func_80213CF8_de *, f32, f32, f32);
extern void func_80272C60_de(Matrix_func_80213CF8_de *, f32, f32, f32);
extern void func_802727D8_de(Matrix_func_80213CF8_de *);
extern void func_80274244_de(Vector4f *, Matrix_func_80213CF8_de *);
extern void func_8024D4AC_de(Vector4f *, EffectActor *, Vec3);
extern void func_80273198_de(Matrix_func_80213CF8_de *, Vec3 *);
extern void func_80270910_de(Matrix_func_80213CF8_de *, Matrix_func_80213CF8_de *);
extern void func_8026EF58_de(Matrix_func_80213CF8_de *, Matrix_func_80213CF8_de *);
extern void func_8027347C_de(Matrix_func_80213CF8_de *, f32, f32, f32);
extern void func_80273448_de(Matrix_func_80213CF8_de *, f32, f32, f32);
extern void func_8027DD48_de(EffectActor *, Matrix_func_80213CF8_de *, void *, f32);
extern s32 func_802744D4_de(void);
extern void func_80284570_de(EffectSystem *, Effect_func_802800C0_de *);
extern void func_80255ED8_de(EffectList *, Effect_func_802800C0_de *);
extern void func_80255CB8_de(EffectList *, Effect_func_802800C0_de *);
extern void func_80255D14_de(EffectList *, Effect_func_802800C0_de *);
extern void func_80255D70_de(EffectList *, Effect_func_802800C0_de *, Effect_func_802800C0_de *);
extern void func_80295E84_de(u32 *, s32);
extern void func_80246184_de(Effect_func_802800C0_de *);
extern f32 func_80285630_de(CharacterScreenCell);

#if defined(VERSION_EU)
extern f32 func_802AD520_eu(s32);
#else
extern f32 func_802B2350(s32);
#endif

extern void func_8022B040_de(s32, Effect_func_802800C0_de *);
extern void func_8027DAD0_de(Effect_func_802800C0_de *, s32, s32);
extern void func_802A4598_de(void *, Effect_func_802800C0_de *, s32);
extern s32 func_80268BE0_de(void *, s32);
extern void func_802843B8_de(Effect_func_802800C0_de *, s32);
extern void func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_802765B0_de(s8, u8, u8, u8, u8 *, u8 *, u8 *);

extern void func_80276B44_de(u8, u8, u8, u8, u8 *, u8 *, u8 *);

static inline s32 effect_spawn_random_count(s32 range) {
    return range != 0 ? func_802744D4_de() % (range + 1) : 0;
}

static inline Effect_func_802800C0_de *effect_spawn_find_owned(EffectList *list, void *ownerId, EffectEntry *entry) {
    Effect_func_802800C0_de *effect;

    effect = list->head;
    if (entry != 0) {
        for (; effect != 0; effect = effect->next) {
            if (effect->ownerId == ownerId && effect->entry == entry) {
                return effect;
            }
        }
    } else {
        for (; effect != 0; effect = effect->next) {
            if (effect->ownerId == ownerId) {
                return effect;
            }
        }
    }
    return 0;
}

static inline Effect_func_802800C0_de *effect_spawn_allocate(EffectSystem *sys, u8 index) {
    Effect_func_802800C0_de *effect;
    EffectList *list;
    s32 i;

    if (sys->free.head == 0) {
        for (i = 0; i <= index; i++) {
            if ((&sys->lists[i])->tail != 0) {
                func_80284570_de(sys, (&sys->lists[i])->tail);
                break;
            }
        }
    }
    effect = sys->free.head;
    if (effect == 0) {
        return 0;
    }
    func_80255ED8_de(&sys->free, effect);
    list = &sys->lists[index];
    func_80255CB8_de(list, effect);
    effect->list = list;
    effect->groupNext = 0;
    effect->unk1F0 = 0;
    effect->flags = 0x100;
    return effect;
}

static inline void effect_spawn_aim(Effect_func_802800C0_de *effect, EffectTarget *aimTarget, Vec3 *vel, s32 sourceType) {
    Matrix_func_80213CF8_de targetMtx;
    Matrix_func_80213CF8_de targetInv;
    Vec3 up;
    EffectActor *targetActor;
    s32 targetTeam;

    if (aimTarget->matrixIndex != -1) {
        effect->mode = -4;
        targetActor = D_801041F0.actor;
        targetTeam = aimTarget->unk7E;
        func_80270910_de(&targetMtx, &targetActor->u60.link.matrixArray[D_801041F0.matrixIndex]);
        func_8026EF58_de(&targetInv, &targetMtx);
        func_80272898_de(&targetInv, &aimTarget->pos, &effect->unk50);
        up = D_801042C8;
        func_8027207C_de(&up);
        func_80272B38_de(&targetInv, &up, vel);
        effect->unk134 = (s32) targetActor;
        effect->flags |= 0x10000;
        effect->unk1D1 = D_801041F0.matrixIndex;
        if (effect->kind == 0x56 && targetTeam == sourceType) {
            effect->flags |= 0x4000000;
        }
    }
}

s32 func_802800C0_de(EffectSystem *sys, EffectActor *source, EffectActor *owner, s32 *refCount, s32 arg4, s32 kind,
                  Vec3 arg6, Vector4f rotation, Vec3 pos, Vec3 *aim, s32 arg10, s32 arg11) {
    Matrix_func_80213CF8_de mtx;
    Vec3 dir;
    Vec3 dirOut;
    Vec3 offset;
    Vec3 offsetOut;
    Vec3 delta;
    Vector4f quat;
    EffectTarget target;
    Vec3 aimDelta;
    s32 first;
    s32 last;
    u8 h, sv, v;
    u8 r, g, b;
    u8 r0, g0, b0;
    u8 r1, g1, b1;
    s32 count;
    s32 j;
    s32 n;
    s32 mode;
    s32 i;
    EffectActor *anchor;
    void *ownerId;
    s32 extra;
    s32 life;
    s32 layer;
    s32 ok;
    s32 hue;
    u8 sat;
    u8 val;
    s32 spread;
    u32 *bits;
    u8 mask;
    s32 resource;
    EffectBlock *block;
    s32 numEntries;
    EffectEntry *entries;
    EffectEntry *entry;
    Effect_func_802800C0_de *effect;
    EffectRender *render;
    Vec3 *vel;
    EffectTarget *aimTarget;
    func_8028414C_S1 *camera;
    f32 distSq;
    f32 scale;
    f32 depth;
    s32 sourceType;
    s32 sound;

    if (D_80145060.frozen != 0) {
        return 0;
    }
    count = 0;
    resource = sys->resource;
    D_80103FCC = &target;
    sys->last = 0;
    block = func_8028FDB4_de(resource, 1);
    numEntries = block->count;
    if (func_80265550_de(block->entries, numEntries, kind, &first, &last) != 0) {
        entries = func_8028FDB4_de(resource, 2)->entries;
        anchor = 0;
        if (D_80145060.actorList != 0) {
            anchor = D_80145060.actorList;
        }
        ownerId = 0;
        if (owner != 0) {
            switch (owner->type) {
                case 1:
                case 2:
                    ownerId = owner;
                    break;
                case 0:
                    ownerId = owner->u60.link.owner;
                    owner = 0;
                    break;
            }
        }
        mask = 1;
        if (D_801462E5 != 0) {
            mask = 2;
        }
        for (i = first; i <= last; i++) {
            entry = &entries[i];
            ok = (entry->playerMask & mask) != 0;
            if ((entry->flags & 0x80) && ownerId != 0) {
                if (effect_spawn_find_owned(&sys->lists[entry->params->listIndex], ownerId, entry) != 0) {
                    ok = 0;
                }
            }
            if (anchor != 0) {
                func_80271F68_de(&delta, &pos, &anchor->pos);
            } else {
                delta.x = delta.y = delta.z = 0.0f;
            }
            distSq = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            if (entry->flags & 0x400000) {
                if (262144.0f <= distSq) {
                    ok = 0;
                }
            } else if (entry->flags & 0x200000) {
                if (distSq <= 262144.0f) {
                    ok = 0;
                }
            }
            switch (entry->params->unkE) {
                case 6:
                    mode = -7;
                    break;
                case 5:
                    mode = -6;
                    break;
                case 0:
                    mode = -4;
                    break;
                case 1:
                    mode = -5;
                    break;
                default:
                    switch (arg10) {
                        case -5:
                        case -3:
                        case -2:
                            mode = arg10;
                            break;
                        default:
                            mode = -3;
                            break;
                    }
                    break;
                case 3:
                    if (0.0f <= (f32) arg10) {
                        mode = arg10;
                    } else {
                        ok = 0;
                        mode = 0;
                    }
                    break;
                case 4:
                    if (source->type == 2 && source->unk1D0 == -8) {
                        arg10 = -8;
                        D_801002E0 = source->unk174;
                    }
                    mode = arg10;
                    break;
            }
            if (entry->flags & 0x2000000) {
                if (D_801462E3 == 0 || !(arg11 & 1)) {
                    ok = 0;
                }
            }
            if (entry->flags & 0x4000000) {
                if (D_801462E3 != 0) {
                    ok = 0;
                }
            }
            if (entry->params->chance != 100) {
                if (func_802744D4_de() % 1000 + 1 > entry->params->chance * 10) {
                    ok = 0;
                }
            }
            if (!ok) {
                continue;
            }
            extra = 0;
            if (entry->flags & 0x8000) {
                switch (source->type) {
                    case 2:
                        if (!(source->flags & 0x100000)) {
                            if (D_80140FF8 == 1) {
                                camera = D_80140FE8_de;
                                func_80272898_de(&camera->unk220, &source->pos, &aimDelta);
                                depth = aimDelta.z;
                                if (depth < 0.0f) {
                                    depth = -depth;
                                }
                                func_8027DD48_de(source, &source->u60.matrices[D_800D297C], camera, depth);
                            } else {
                                func_8027DD48_de(source, &source->u60.matrices[D_800D297C], 0, 0.0f);
                            }
                            source->flags |= 0x100000;
                        }
                        func_80270910_de(&mtx, &source->u60.matrices[D_800D297C]);
                        scale = 0.09765625f;
                        if (source->model->unk14 != 0) {
                            scale = 2.857143f;
                        }
                        func_8027347C_de(&mtx, scale, scale, scale);
                        if (source->model->flags & 8) {
                            func_80273448_de(&mtx, 0.0f, -source->unk154 * source->unk158, 0.0f);
                        }
                        break;
                    case 1:
                        extra = 0x400000;
                        func_80272CB0_de(&mtx, -1.0f, 1.0f, -1.0f);
                        break;
                    default:
                        func_80272C60_de(&mtx, source->pos.x, source->pos.y, source->pos.z);
                        break;
                }
            } else if (entry->flags & 0x1000000) {
                func_802727D8_de(&mtx);
            } else {
                if (entry->flags & 0x40000) {
                    func_8024D4AC_de(&quat, owner, pos);
                } else {
                    quat = rotation;
                }
                func_80274244_de(&quat, &mtx);
            }
            n = entry->params->countBase + effect_spawn_random_count(entry->params->countRange);
            for (j = 0; j < n; j++) {
                life = entry->params->lifeBase + effect_spawn_random_count(entry->params->lifeRange);
                if (life == 0) {
                    continue;
                }
                effect = effect_spawn_allocate(sys, entry->params->listIndex);
                if (effect == 0) {
                    break;
                }
                count++;
                func_80295E84_de(&effect->unk11C, entry->unk4);
                func_80246184_de(effect);
                effect->unk110 = 0;
                effect->unk114 = 0;
                effect->kind = kind;
                effect->entry = entry;
                effect->mode = mode;
                if (source->type == 2) {
                    effect->source = source;
                } else {
                    effect->source = 0;
                }
                effect->ownerId = ownerId;
                effect->owner = owner;
                effect->refCount = refCount;
                if (refCount != 0) {
                    (*refCount)++;
                }
                effect->unk134 = arg4;
                effect->unk13C = 0;
                effect->flags = (effect->flags & ~0xE600) | (arg11 | extra);
                bits = &effect->unk11C;
                layer = 0;
                if (effect->entry->flags & 0x2000000) {
                    if (effect->flags & 2) {
                        layer = 2;
                    } else if (D_801462E3 == 2) {
                        layer = 1;
                    }
                }
                *bits |= layer << 30;
                effect->unk1D9 = 0;
                spread = entry->params->unkD;
                if (spread < 0) {
                    effect->unk140 = spread;
                } else {
                    effect->unk140 = -(f32) effect_spawn_random_count(spread);
                }
                effect->unk19C[0] = func_80285630_de(entry->unk2C[2]) * D_800C4E04_de;
                effect->unk19C[2] = func_80285630_de(entry->unk2C[1]) * 0.41887906f;
                effect->unk19C[4] = func_80285630_de(entry->unk2C[0]);
                effect->unk19C[1] = func_80285630_de(entry->unk2C[5]) * D_800C4E04_de;
                effect->unk19C[3] = func_80285630_de(entry->unk2C[4]) * 0.41887906f;
                effect->unk19C[5] = func_80285630_de(entry->unk2C[3]);
                if (entry->flags & 2) {
                    effect->unk144 = effect_spawn_random_count(life);
                } else {
                    effect->unk144 = 0.0f;
                }
                effect->unk148 = entry->params->unkB;
                effect->life = life;
                effect->unk14E = 0;
                effect->unk14F = -1;
                if (aim == 0) {
                    dir.x = func_80285630_de(entry->direction[0]);
                    dir.y = func_80285630_de(entry->direction[1]);
                    dir.z = func_80285630_de(entry->direction[2]);
                    func_8027207C_de(&dir);
                    if (dir.x != 0.0f || dir.y != 0.0f || dir.z != 0.0f) {
                        func_80272898_de(&mtx, &dir, &dirOut);
                    } else {
                        dirOut = dir;
                    }
                    if (mode == -8) {
                        effect->direction = D_801002E0;
                        func_8027207C_de(&effect->direction);
                    } else {
                        effect->direction = dirOut;
                    }
                }
                effect->unk150[0] = func_80285630_de(entry->unk24[0]);
                effect->unk150[1] = func_80285630_de(entry->unk24[2]);
                effect->unk150[2] = func_80285630_de(entry->unk24[4]);
                effect->unk150[3] = func_80285630_de(entry->unk24[1]);
                effect->unk150[4] = func_80285630_de(entry->unk24[3]);
                effect->unk150[5] = func_80285630_de(entry->unk24[5]);
                if (entry->unk14 != 0) {
                    effect->unk180[0] = func_80285630_de(entry->unk20[0]);
                    effect->unk180[1] = func_80285630_de(entry->unk20[2]);
                    effect->unk180[2] = func_80285630_de(entry->unk20[4]);
                    effect->unk180[3] = func_80285630_de(entry->unk20[1]);
                    effect->unk180[4] = func_80285630_de(entry->unk20[3]);
                    effect->unk180[5] = func_80285630_de(entry->unk20[5]);
                } else {
                    effect->unk180[0] = func_80285630_de(entry->unk20[0]);
                    effect->unk180[1] = func_80285630_de(entry->unk20[2]);
                    effect->unk180[2] = func_80285630_de(entry->unk20[4]);
                    effect->unk180[3] = func_80285630_de(entry->unk20[1]);
                    effect->unk180[4] = func_80285630_de(entry->unk20[3]);
                    effect->unk180[5] = func_80285630_de(entry->unk20[5]);
                }
                if ((entry->flags & 0x80000) && entry->unk8 == 1) {
                    effect->unk1D8 = 0;
                    effect->alpha = 0.0f;
                } else {
                    effect->unk1D8 = 0xFF;
                    effect->alpha = 255.0f;
                }
                effect->unk14 = 0;
                effect->pos = pos;
                offset.x = func_80285630_de(entry->offset[0]);
                offset.y = func_80285630_de(entry->offset[1]);
                offset.z = func_80285630_de(entry->offset[2]);
                if (offset.x != 0.0f || offset.y != 0.0f || offset.z != 0.0f) {
                    func_80272898_de(&mtx, &offset, &offsetOut);
                    if (!(entry->flags & 0x8000)) {
                        func_80271F34_de(&offsetOut, &pos, &offsetOut);
                    }
                    effect->pos = offsetOut;
                }
                if (aim != 0) {
                    func_80271F68_de(&aimDelta, aim, &effect->pos);
                    func_8027207C_de(&aimDelta);
                    func_80273198_de(&mtx, &aimDelta);
                    if (mode == -8) {
                        effect->direction = D_801002E0;
                        func_8027207C_de(&effect->direction);
                    } else {
                        dir.x = func_80285630_de(entry->direction[0]);
                        dir.y = func_80285630_de(entry->direction[1]);
                        dir.z = func_80285630_de(entry->direction[2]);
                        func_8027207C_de(&dir);
                        if (dir.x != 0.0f || dir.y != 0.0f || dir.z != 0.0f) {
                            func_80272898_de(&mtx, &dir, &dirOut);
                        } else {
                            dirOut = dir;
                        }
                        effect->direction = dirOut;
                    }
                }
                effect->unk168 = effect->pos;
                effect->unk50 = effect->pos;
                func_80271F9C_de(&effect->velocity, &dirOut, func_80285630_de(entry->motion->speed));
                if (entry->flags & 0x20) {
                    func_80271F34_de(&effect->velocity, &effect->velocity, &arg6);
                }
                hue = 0;
                if (entry->color->hueRange != 0) {
                    hue = func_802744D4_de() % (entry->color->hueRange * 2) - (u8) entry->color->hueRange;
                }
                sat = entry->color->unkD != 0 ? func_802744D4_de() % entry->color->unkD : 0;
                val = entry->color->unkE != 0 ? func_802744D4_de() % entry->color->unkE : 0;
                r = entry->color->rgb0[0];
                g = entry->color->rgb0[1];
                b = entry->color->rgb0[2];
                func_802765B0_de(hue, r, g, b, &h, &sv, &v);
                func_80276968_de(sat, h, sv, v, &r, &g, &b);
                func_80276B44_de(val, r, g, b, &r0, &g0, &b0);
                r = entry->color->rgb1[0];
                g = entry->color->rgb1[1];
                b = entry->color->rgb1[2];
                func_802765B0_de(hue, r, g, b, &h, &sv, &v);
                func_80276968_de(sat, h, sv, v, &r, &g, &b);
                func_80276B44_de(val, r, g, b, &r1, &g1, &b1);
                effect->rgb0[0] = r0;
                effect->rgb0[1] = g0;
                effect->rgb0[2] = b0;
                effect->rgb1[0] = r1;
                effect->rgb1[1] = g1;
                effect->rgb1[2] = b1;
                render = &effect->render;
                *render = D_80100090;
                render->unk5 = entry->unkA;
                render->unk4 = entry->unk9;
                render->unk6 = entry->unkB;
                render->unk8 = func_80285630_de(entry->motion->unk0);
#if defined(VERSION_EU)
                render->unkC = func_802AD520_eu(entry->motion->unk8);
                render->unk10 = func_802AD520_eu(entry->motion->unkA);
                render->unk14 = func_802AD520_eu(entry->motion->unkC);
                render->unk18 = func_802AD520_eu(entry->motion->unkE);
#else
                render->unkC = func_802B2350(entry->motion->unk8);
                render->unk10 = func_802B2350(entry->motion->unkA);
                render->unk14 = func_802B2350(entry->motion->unkC);
                render->unk18 = func_802B2350(entry->motion->unkE);
#endif
                if (render->unk5 == 8 || render->unk6 == 8 || render->unk4 == 8) {
                    if (effect->owner != 0 && effect->owner->type == 1 && (effect->owner->unk100 & 0x300000)) {
                        func_8022B040_de(effect->owner->unk1D8, effect);
                    }
                }
                if (kind == 0x101 || kind == 0x128) {
                    render->flags |= 4;
                }
                if (entry->flags & 0x100000) {
                    render->flags |= 0x40000;
                }
                if (entry->flags & 0x800) {
                    render->flags |= 0x2000;
                }
                if (entry->flags & 0x40000000) {
                    render->flags |= 0x4000;
                }
                if (entry->params->unk5 != 3) {
                    Effect_func_802800C0_de *other;

                    for (other = sys->groups.head; other != 0; other = other->groupNext) {
                        if (other->entry == effect->entry) {
                            break;
                        }
                    }
                    if (other != 0) {
                        func_80255D70_de(&sys->groups, other, effect);
                    } else if (effect->entry->flags & 0x2000) {
                        func_80255CB8_de(&sys->groups, effect);
                    } else {
                        func_80255D14_de(&sys->groups, effect);
                    }
                    effect->flags |= 0x1000000;
                }
                if ((D_800CC134[entry->model->unk94].offset & 1) || kind == 0x68) {
                    render->flags |= 0x20000;
                }
                vel = &effect->velocity;
                func_80271F9C_de(vel, vel, D_800CD6B0);
                if ((kind == 0x2D || kind == 0x4F) && (sourceType = source->type) == 2) {
                    aimTarget = &D_801041F0;
                    if (aimTarget->actor != 0) {
                        effect_spawn_aim(effect, aimTarget, vel, sourceType);
                    }
                }
                effect->unk1E0 = D_800CD6B4;
                func_8027DAD0_de(effect, 0, 0);
                if (entry->unk6 != -1) {
                    func_802A4598_de(&D_801379C0, effect, entry->unk6);
                }
                if (entry->unk7 != -1) {
                    effect->unk138 = func_80268BE0_de(&D_8013B1A8, entry->unk7);
                } else {
                    effect->unk138 = 0;
                }
                if (!(effect->flags & 0x200000) && (sound = entry->sound) != 0) {
                    switch (effect->kind) {
                        case 0x22:
                        case 0x5F:
                        case 0x60:
                            func_802843B8_de(effect, sound);
                            break;
                        default:
                            func_8025DE54_de(sound, effect->pos, 0, -1);
                            break;
                    }
                }
                sys->last = effect;
            }
        }
    }
    D_80103FCC = &D_801041F0;
    return count;
}
