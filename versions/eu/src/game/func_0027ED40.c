#include "span_1000/code_8026AC38.h"
#include "common/unused.h"
#include "span_1000/code_8027A0F4.h"
#include "gbi.h"
#include "types.h"
#include "span_1000/code_8027A0F4.h"

struct Shared_ParticleView {
    u32 unknown0[2];
    s32 unk8;
    u32 unknownC[6];
    s32 unk24;
    u32 unknown28[62];
    s32 grayscale;
    u32 unknown124;
    Vec3 unk128;
    u32 unknown134[59];
    Matrix viewMtx;
    u32 unknown260[178];
    f32 fadeRange;
};
struct Shared_AnimFrame {
    u8 kind;
    u8 unknown1;
    u8 shiftS;
    u8 shiftT;
};
struct Shared_AnimInfo {
    s32 count;
    s32 unk4;
    struct Shared_AnimFrame *frame;
};

struct Shared_ParticleView;
struct Frame118;
struct Shared_AnimInfo;

/* Draws one particle for a view: fades particles hidden behind geometry in or out, blends its colours towards the
 * descriptor's targets (greyscale for views that ask for it), picks the animation frame, builds its matrix (once per
 * frame for a shared camera, per view otherwise), selects the texture and render mode, works out its alpha from life,
 * fade-in, fade-out and distance from the view, and emits the colour and draw commands. */

extern Gfx *D_80110634;
extern struct Frame118 *D_8011BDC0;
extern u32 D_800E28A4;
extern f32 D_800D2988;
extern s32 D_800D297C;
extern char D_80100030;
extern s32 D_80140FF8;
extern struct Shared_ParticleView *D_80140FE8_de;

extern s32 D_801462C8;

extern char D_8011AF78;

void *func_80295F14_de(s32 *, s32);
void func_80295F78_de(void *, struct Shared_AnimInfo *);
#if defined(VERSION_US_REV1)
void func_80295FB4_us_rev1(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#else
void func_802950B4_de(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#endif
Shared_ParticleInstance *func_802392EC_de(struct Shared_ParticleView *);
s32 func_80243A90_de(Shared_ParticleInstance *, Vec3, void *);
void func_80272898_de(Matrix *, Vec3 *, Vec3 *);
void func_8027DD48_de(Shared_Particle *, void *, void *, f32);
void *func_802799C0_de(void *, s32);
void func_80268CE0_de(s32);
void func_8026925C_de(s32);
void func_80253754_de(s32, void *);
s32 func_802744D4_de(void);

static inline s32 func_8027ED6C_de_occluded(Shared_Particle *particle, struct Shared_ParticleView *view) {
    Shared_ParticleInstance *inst;
    s32 hit;

    inst = func_802392EC_de(view);
    if (inst != 0 && view->unk24 == 0) {
        Shared_ParticleInstance saved;
        saved = *inst;
        inst->pos = view->unk128;
        hit = func_80243A90_de(inst, particle->inst.pos, &D_80100030);
        *inst = saved;
    } else {
        Shared_ParticleInstance probe;
        probe = particle->inst;
        probe.pos = view->unk128;
        hit = func_80243A90_de(&probe, particle->inst.pos, &D_80100030);
    }
    return hit;
}

static inline s32 func_8027ED6C_de_mode(Shared_Particle *particle) {
    s32 mode = 0;

    if (particle->desc->flags & 0x2000000) {
        if (particle->flags & 2) {
            mode = 2;
        } else if (D_801462E3 == 2) {
            mode = 1;
        }
    }
    return mode;
}

static inline s32 func_8027ED6C_de_scale(f32 value, f32 div) {
    return (value < 0.0f) ? 0 : (s32)((s32)value / div);
}

static inline f32 lesser(f32 a, f32 b) { return a > b ? b : a; }
static inline f32 greater(f32 a, f32 b) { return a < b ? b : a; }

void func_8027ED6C_de(Shared_Particle *particle, struct Shared_ParticleView *view) {
    struct Shared_AnimInfo info;
    u8 env[3];
    u8 prim[3];
    Vec3 viewPos;
    void *model;
    struct Shared_ParticleDesc *desc;
    void *mtx;
    f32 fade;
    f32 ratio;
    f32 dist;
    s32 hit;
    s32 alpha;
    s8 duration;
    s32 mode;
    s32 frame;
    s32 time;
    s32 textured;
    s32 shiftS;
    s32 shiftT;
    s32 sum;
    s16 gray;
    u8 *envTo;
    u8 *primTo;
    u8 *envFrom;
    u8 *primFrom;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (particle->time < 0.0f) {
        return;
    }
    model = func_80295F14_de(&particle->model, -1);
    if (model == 0) {
        return;
    }
    desc = particle->desc;
    if ((desc->flags & 0x80000) && desc->animMode == 1) {
        if (particle->inst.type != 0x60) {
            particle->time = 0.0f;
        }
        hit = func_8027ED6C_de_occluded(particle, view);
        if (!hit) {
            fade = particle->opacity + D_800D2988 * 128.0f;
            alpha = (fade > 255.0f) ? 255 : (s32)fade;
        } else {
            fade = particle->opacity - D_800D2988 * 128.0f;
            alpha = (fade < 0.0f) ? 0 : (s32)fade;
        }
        particle->opacity = alpha;
        if (alpha == 0.0f) {
            func_80253754_de(0, model);
            return;
        }
    }

    particle->flags |= 8 << view->unk8;
    particle->alpha = 255.0f;
    ratio = particle->time / particle->life > 1.0f ? 1.0f : particle->time / particle->life;
    primFrom = particle->prim;
    envFrom = particle->env;
    primTo = desc->colors->prim;
    envTo = desc->colors->env;
    env[0] = (u32)((((envTo[0] - envFrom[0]) * ratio + envFrom[0]) > 255.0f ? 255.0f : ((envTo[0] - envFrom[0]) * ratio + envFrom[0])) < 0.0f ? 0.0f : (((envTo[0] - envFrom[0]) * ratio + envFrom[0]) > 255.0f ? 255.0f : ((envTo[0] - envFrom[0]) * ratio + envFrom[0])));
    env[1] = (u32)((((envTo[1] - envFrom[1]) * ratio + envFrom[1]) > 255.0f ? 255.0f : ((envTo[1] - envFrom[1]) * ratio + envFrom[1])) < 0.0f ? 0.0f : (((envTo[1] - envFrom[1]) * ratio + envFrom[1]) > 255.0f ? 255.0f : ((envTo[1] - envFrom[1]) * ratio + envFrom[1])));
    env[2] = (u32)((((envTo[2] - envFrom[2]) * ratio + envFrom[2]) > 255.0f ? 255.0f : ((envTo[2] - envFrom[2]) * ratio + envFrom[2])) < 0.0f ? 0.0f : (((envTo[2] - envFrom[2]) * ratio + envFrom[2]) > 255.0f ? 255.0f : ((envTo[2] - envFrom[2]) * ratio + envFrom[2])));
    prim[0] = (u32)((((primTo[0] - primFrom[0]) * ratio + primFrom[0]) > 255.0f ? 255.0f : ((primTo[0] - primFrom[0]) * ratio + primFrom[0])) < 0.0f ? 0.0f : (((primTo[0] - primFrom[0]) * ratio + primFrom[0]) > 255.0f ? 255.0f : ((primTo[0] - primFrom[0]) * ratio + primFrom[0])));
    prim[1] = (u32)((((primTo[1] - primFrom[1]) * ratio + primFrom[1]) > 255.0f ? 255.0f : ((primTo[1] - primFrom[1]) * ratio + primFrom[1])) < 0.0f ? 0.0f : (((primTo[1] - primFrom[1]) * ratio + primFrom[1]) > 255.0f ? 255.0f : ((primTo[1] - primFrom[1]) * ratio + primFrom[1])));
    prim[2] = (u32)((((primTo[2] - primFrom[2]) * ratio + primFrom[2]) > 255.0f ? 255.0f : ((primTo[2] - primFrom[2]) * ratio + primFrom[2])) < 0.0f ? 0.0f : (((primTo[2] - primFrom[2]) * ratio + primFrom[2]) > 255.0f ? 255.0f : ((primTo[2] - primFrom[2]) * ratio + primFrom[2])));

    if (view->grayscale != 0) {
        gray = env[0] + env[1] + env[2];
        gray /= 12;
        env[0] = gray * 2;
        env[1] = 0;
        env[2] = 0;
        gray = prim[0] + prim[1] + prim[2];
        gray /= 12;
        prim[0] = gray * 2;
        prim[1] = gray * 3;
        prim[2] = 0;
    }

    mode = func_8027ED6C_de_mode(particle);
    func_80295F78_de(model, &info);
    frame = particle->frame;
    time = particle->time;
    switch (desc->animMode) {
        case 0:
            if (frame >= info.count - 1) {
                time = particle->life;
                frame = info.count - 1;
                particle->time = time;
            }
            break;
        case 1:
            if (frame >= info.count) {
                frame = info.count - 1;
            }
            break;
        case 2:
            frame %= info.count;
            break;
        case 3:
            if (info.count * 2 - 2 > 0) {
                frame %= info.count * 2 - 2;
            } else {
                frame = 0;
            }
            if (frame >= info.count) {
                frame = (info.count * 2 - 2) - frame;
            }
            break;
        case 4:
            frame = func_802744D4_de() % info.count;
            break;
        case 5:
            if (particle->unk14F == -1) {
                particle->unk14F = func_802744D4_de() % info.count;
            }
            frame = particle->unk14F;
            break;
    }

    if (!(particle->flags & 0x100000)) {
        if (D_80140FF8 == 1) {
            struct Shared_ParticleView *camera = D_80140FE8_de;
            Vec3 local;
            f32 depth;
            func_80272898_de(&camera->viewMtx, &particle->inst.pos, &local);
            depth = local.z;
            if (depth < 0.0f) {
                depth = -depth;
            }
            func_8027DD48_de(particle, &particle->mtx[D_800D297C], camera, depth);
        } else {
            func_8027DD48_de(particle, &particle->mtx[D_800D297C], 0, 0.0f);
        }
        particle->unk14E = frame;
        particle->flags |= 0x100000;
    }
    func_80272898_de(&view->viewMtx, &particle->inst.pos, &viewPos);
    dist = viewPos.z;
    if (dist < 0.0f) {
        dist = -dist;
    }
    if (D_80140FF8 == 1) {
        gSPMatrix(D_80110634++, (u32)&particle->mtx[D_800D297C], G_MTX_LOAD);
    } else {
        mtx = func_802799C0_de(&D_8011FFB0, 1);
        if (mtx == 0) {
            func_80253754_de(0, model);
            return;
        }
        func_8027DD48_de(particle, mtx, view, dist);
        gSPMatrix(D_80110634++, (u32)mtx, G_MTX_LOAD);
    }

    textured = particle->flags & 0x800000;
    shiftS = 1 << (((desc->flags & 0x100) ? 7 : 6) + info.frame->shiftS);
    shiftT = 1 << (((desc->flags & 0x200) ? 7 : 6) + info.frame->shiftT);
#if defined(VERSION_US_REV1)
    func_80295FB4_us_rev1(&particle->model, model, frame, 0, shiftS, shiftT, 1, 1, 0);
#else
    func_802950B4_de(&particle->model, model, frame, 0, shiftS, shiftT, 1, 1, 0);
#endif
    switch (info.frame->kind) {
        case 0:
        case 1:
            func_80268CE0_de(0x18);
            break;
        case 3:
            func_80268CE0_de(0x1D);
            break;
    }
    if (textured) {
        func_8026925C_de(0xF);
        {
            gSPTextureL(D_80110634++, shiftS, shiftT, 0, 0xFF, 0, G_ON);
        }
    } else if ((desc->flags & 0x400) && desc->fade->unkE != 4) {
        func_8026925C_de(0xF);
    } else if (desc->flags & 0x4000) {
        func_8026925C_de(!(D_801462C8 & 0x200) ? 0xD : 0x11);
    } else {
        func_8026925C_de((D_801462C8 & 0x200) ? 0x12 : 0x13);
    }

    alpha = 0xFF;
    if ((desc->flags & 1) && particle->life > 0) {
        alpha = (particle->life - time) * 255.0f / particle->life;
    }
    duration = desc->fade->fadeIn;
    if (duration != -1 && time < duration) {
        alpha = alpha * (time + 1.0f) / (duration + 1.0f);
    }
    duration = desc->fade->fadeOut;
    if (duration != -1) {
        f32 left = particle->life - time;
        if ((left < 0.0f ? 0.0f : left) < duration) {
            alpha = func_8027ED6C_de_scale(alpha * (particle->life - time), duration + 1.0f);
        }
    }
    if (view->fadeRange < -0.0001f || view->fadeRange > 0.0001f) {
        f32 range = view->fadeRange;
        f32 half;
        f32 delta;
        switch (desc->fade->rangeMode) {
            case 2:
                alpha = alpha * (((range - dist) * 10.0f / range) > 1.0f ? 1.0f : ((range - dist) * 10.0f / range));
                break;
            case 0:
                alpha = alpha * (((range - dist) * 5.0f / range) > 1.0f ? 1.0f : ((range - dist) * 5.0f / range));
                break;
            case 1:
                half = range * 0.5f;
                delta = half - dist;
                alpha = alpha * (delta < 0.0f ? half + delta : half - delta) / half;
                break;
        }
    }

    if (info.frame->kind == 3) {
        switch (mode) {
            case 0:
            default:
                gDPSetEnvColor(D_80110634++, env[0], env[1], env[2], 255);
                break;
            case 2:
                gDPSetEnvColor(D_80110634++, env[0], env[0], env[2], 255);
                break;
            case 1:
                gDPSetEnvColor(D_80110634++, env[1], env[0], env[2], 255);
                break;
        }
    }
    alpha = (alpha > 255 ? 255 : alpha) < 0 ? 0 : (alpha > 255 ? 255 : alpha);
    gSPVertex(D_80110634++, (u32)&D_8011AF78, 4, 0);
    if (textured) {
        gSPTextureL(D_80110634++, shiftS, shiftT, 0, 0xFF, 0, G_ON);
        }
    particle->alpha = (alpha * particle->opacity) >> 8;
    switch (mode) {
        case 0:
        default:
            gDPSetPrimColor(D_80110634++, 0, 0, prim[0], prim[1], prim[2], (u32)particle->alpha);
            break;
        case 2:
            gDPSetPrimColor(D_80110634++, 0, 0, prim[0], prim[0], prim[2], (u32)particle->alpha);
            break;
        case 1:
            gDPSetPrimColor(D_80110634++, 0, 0, prim[1], prim[0], prim[2], (u32)particle->alpha);
            break;
    }
    gSP2Triangles(D_80110634++, 0, 1, 2, 0, 2, 3, 0, 0);
    func_80253754_de(0, model);
}
