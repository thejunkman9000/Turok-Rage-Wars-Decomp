#include "shared/unsigned_quotient.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
/* Builds and packs the animated part matrices of an actor, then updates the
 * frame timing totals. */
#include "types.h"
#include "common/unused.h"

/* Complete nonpadded pose records recovered from the pinned shared pose header. */
typedef struct Shared_PoseJointRef Shared_PoseJointRef;
struct Shared_PoseJointRef {
    s16 pos; 
    s16 rot; 
};

typedef struct Shared_PoseDefaultFrame Shared_PoseDefaultFrame;
struct Shared_PoseDefaultFrame {
    Vec3 pos;  
    s16 rot[4]; 
};

typedef struct Shared_PoseTrack Shared_PoseTrack;
struct Shared_PoseTrack {
    Shared_PoseJointRef *joints;     
    Shared_PoseDefaultFrame *frames; 
    void *posTable;                  
    void *rotTable;                  
    s32 rotFrame0;                   
    s32 rotFrame1;                   
    s32 posFrame0;                   
    s32 posFrame1;                   
    f32 blend;                       
};

typedef struct Shared_PoseFlags Shared_PoseFlags;
struct Shared_PoseFlags {
    s32 frame; 
    s32 blend; 
    s32 mode;  
};
#include "types.h"
typedef struct Shared_FrameProfile Shared_FrameProfile;
struct Shared_FrameProfile {
    u64 start;
    u32 unknown08[2];
    s32 frame;
    s32 prevCount;
    s32 count;
    u32 unknown1C;
    f32 prev;
    f32 cur;
    f32 avg;
};

typedef f32 PoseMatrix[4][4];
typedef void (*PoseCallback)(PoseMatrix, Shared_PoseContext *);

extern char D_800C3930_de;


extern s32 D_800D2978;
extern s32 D_800D297C;
extern Shared_FrameProfile D_80100530;
extern char D_8011FE88;




extern s32 D_801462C8;

extern s32 func_80245798_de(void);
extern void func_80247F18_de(Shared_PoseActor *, Shared_PosePart *, PoseMatrix, Vec3, Vec3, s32);
extern void func_802480F0_de(Shared_PoseActor *, s32, PoseMatrix);
extern f32 func_8024D284_de(Shared_PoseActor *);
extern s32 *func_8025193C_de(s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern void func_80253754_de(s32, s32 *);
extern void func_80261670_de(Shared_AnimState *, s32, s32, s32, s32, s32);
extern void func_80261E98_de();
extern void func_802624A8_de(Shared_AnimState *);
extern s32 func_802624D8_de(Shared_AnimState *);
extern void func_8026E5E0_de(u8 *, s32, PoseMatrix *, Shared_PoseActor *, void *);
extern void func_8026F620_de(PoseMatrix, PoseMatrix, PoseMatrix);
extern void func_80270910_de(PoseMatrix, u8 *);
extern void func_80270AAC_de(Vector4f *, f32, Vector4f *, Vector4f *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80272D00_de(PoseMatrix, f32, f32, f32, f32);
extern void func_8027302C(PoseMatrix, PoseMatrix);
extern void func_80273448_de(PoseMatrix, f32, f32, f32);
extern void func_8027347C_de(PoseMatrix, f32, f32, f32);
extern s32 func_802744D4_de(void);
extern f32 func_8027525C_de(StateFlags *, f32, f32);
extern s32 func_802799C0_de(void *, s32);
extern void func_8028C6D4_de(void *, Vec3 *, u8 *);
extern void *func_8028FDB4_de(void *, s32);
extern void func_802A57E0_de(void *, Shared_PoseActor *, PoseMatrix *);
extern u32 func_802BCF00_de(void);

static inline Vec3 randVec(void) {
    Vec3 v;

    v.x = func_802744D4_de() % 100;
    v.y = func_802744D4_de() % 100;
    v.z = func_802744D4_de() % 100;
    return v;
}

static inline void twistPart(Shared_PosePart *part, PoseMatrix cur, s32 n, s32 i) {
    Vec3 turn;
    Vec3 axis;
    PoseMatrix rotm;
    PoseMatrix inv;
    f32 angle;

    if (i != 0) {
        turn.x = cur[3][0];
        turn.y = cur[3][1];
        turn.z = cur[3][2];
        axis = part->unk_18;
        angle = D_800D06C0[0x19 - part->unk_12] * 0.5f;
        angle *= 0.3f;
        angle *= (n == 5 ? -2.0f : (f32)n);
        func_8027302C(inv, cur);
        func_80271F9C_de(&turn, &turn, -1.0f);
        func_80273448_de(inv, turn.x, turn.y, turn.z);
        func_80272D00_de(rotm, angle, axis.x, axis.y, axis.z);
        func_8026F620_de(cur, inv, rotm);
        func_80271F9C_de(&turn, &turn, -1.0f);
        func_80273448_de(cur, turn.x, turn.y, turn.z);
        if (part->unk_14[0] == i) {
            part->unk_12--;
        }
    }
}

static inline void trackPos(Shared_PoseTrack *t, s32 i, Vec3 *out) {
    if (t->joints[i].pos == -1) {
        *out = t->frames[i].pos;
    } else {
        f32 *data = func_8028FDB4_de(t->posTable, t->joints[i].pos);
        f32 *a = &data[t->posFrame0];
        f32 *b = &data[t->posFrame1];

        out->x = a[0] + t->blend * (b[0] - a[0]);
        out->y = a[1] + t->blend * (b[1] - a[1]);
        out->z = a[2] + t->blend * (b[2] - a[2]);
    }
}

static inline void trackRot(Shared_PoseTrack *t, s32 i, Vector4f *out, s32 slerp) {
    Shared_PoseDefaultFrame *frame;
    f32 z;
    if (slerp) {
        if (t->joints[i].rot == -1) {
            frame = t->frames;
            frame += i;
            out->x = frame->rot[0] * (1.0f / 32767.0f);
            out->y = frame->rot[1] * (1.0f / 32767.0f);
            z = frame->rot[2] * (1.0f / 32767.0f);
            goto default_frame;
        } else {
            f32 *data = func_8028FDB4_de(t->rotTable, t->joints[i].rot);

            func_80270AAC_de(out, t->blend, (Vector4f *)&data[t->rotFrame0], (Vector4f *)&data[t->rotFrame1]);
        }
    } else if (t->joints[i].rot == -1) {
        frame = t->frames;
            frame += i;

        out->x = frame->rot[0] * (1.0f / 32767.0f);
        out->y = frame->rot[1] * (1.0f / 32767.0f);
        z = frame->rot[2] * (1.0f / 32767.0f);
    default_frame:
        out->z = z;
        out->w = frame->rot[3] * (1.0f / 32767.0f);
    } else {
        f32 *data = func_8028FDB4_de(t->rotTable, t->joints[i].rot);
        f32 *a = &data[t->rotFrame0];
        f32 *b = &data[t->rotFrame1];

        out->x = a[0] + t->blend * (b[0] - a[0]);
        out->y = a[1] + t->blend * (b[1] - a[1]);
        out->z = a[2] + t->blend * (b[2] - a[2]);
        out->w = a[3] + t->blend * (b[3] - a[3]);
    }
}

static inline void quatToMtx(PoseMatrix m, Vector4f *q, Vec3 *t) {
    f32 xx = q->x * q->x;
    f32 yy = q->y * q->y;
    f32 zz = q->z * q->z;
    f32 ww = q->w * q->w;
    f32 xy = 2.0f * q->x * q->y;
    f32 wz = 2.0f * q->w * q->z;
    f32 xz = 2.0f * q->x * q->z;
    f32 wy = 2.0f * q->w * q->y;
    f32 yz = 2.0f * q->y * q->z;
    f32 wx = 2.0f * q->w * q->x;

    m[0][0] = ww + xx - yy - zz;
    m[0][1] = xy + wz;
    m[0][2] = xz - wy;
    m[0][3] = 0.0f;
    m[1][0] = xy - wz;
    m[1][1] = ww - xx + yy - zz;
    m[1][2] = yz + wx;
    m[1][3] = 0.0f;
    m[2][0] = xz + wy;
    m[2][1] = yz - wx;
    m[2][2] = ww - xx - yy + zz;
    m[2][3] = 0.0f;
    m[3][0] = t->x;
    m[3][1] = t->y;
    m[3][2] = t->z;
    m[3][3] = 1.0f;
}

static inline void packMtx(u32 *out, PoseMatrix m) {
    u32 *hi = out;
    u32 *lo = out + 8;
    u32 e1;
    u32 e2;

        e1 = (u32)m[0][0];
        e2 = (u32)m[0][1];
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[0][2];
        e2 = 0;
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[1][0];
        e2 = (u32)m[1][1];
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[1][2];
        e2 = 0;
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[2][0];
        e2 = (u32)m[2][1];
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[2][2];
        e2 = 0;
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[3][0];
        e2 = (u32)m[3][1];
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);
        e1 = (u32)m[3][2];
        e2 = 65536;
        *hi++ = (e1 & 0xFFFF0000) | (e2 >> 16);
        *lo++ = (e1 << 16) | (e2 & 0xFFFF);

}

s32 func_802484B0_de(Shared_PoseActor *actor, void *arg1, s32 arg2) {
    PoseMatrix mtx[129];
    Vec3 pos;
    Shared_PoseContext ctx;
    Shared_PoseTrack tracks[2];
    Shared_PoseFlags f;
    PoseMatrix m;
    Vec3 trans;
    Vec3 posA;
    Vec3 posB;
    Vector4f rot;
    Vector4f rotA;
    Vector4f rotB;
    Vec3 scale;
    Shared_PoseWorld *world;
    s32 *mem;
    Shared_AnimState *animA;
    Shared_AnimState *animB;
    s32 id0;
    s32 id1;
    s32 id2;
    s32 id3;
    s32 id4;
    s32 count;
    s32 kind;
    PoseMatrix *parent;
    u32 *out;
    s32 scaled;
    s32 ret;
    s32 skip;
    s32 isRoot;
    s32 isKind9;
    s32 i;
    PoseMatrix *cur;
    s32 flags;
    u32 dt;

    world = 0;
    ctx.parts = func_8028FDB4_de(arg1, 5);
    count = ctx.parts->count;
    actor->handle = func_802799C0_de(&D_8011FFB0, count);
    if (actor->handle == 0) {
        return 0;
    }
    ret = 0;
    isRoot = actor->flags & 1;
    isKind9 = actor->model->kind == 9;
    mem = func_8025193C_de(0, actor->unk_C8, actor->unk_C8, ((actor->unk_E6 * 4) + 0xF) & ~7, 4, 0, 0, &D_800C3930_de + 4, 0);
    skip = ret;
    if (mem != 0) {
        animA = &actor->animA;
        animB = &actor->animB;
        func_80261670_de(animA, *mem, actor->unk_C8, 0, 0, 0);
        if (func_802624D8_de(animA)) {
            if (actor->flags & 0x400) {
                func_80261670_de(animB, *mem, actor->unk_C8, 0, 0, 0);
                f.blend = func_802624D8_de(animB);
            } else {
                f.blend = 0;
            }
            ctx.actor = actor;
            ctx.handle = actor->handle;
            ctx.mtx = &mtx[1];
            ctx.arg2 = arg2;
            ctx.arg1 = arg1;
            ctx.animA = animA;
            ctx.animB = animB;
            f.frame = (!isRoot || isKind9) && !skip;
            func_80261E98_de(&actor->animA, &tracks[0], f.frame);
            func_80261E98_de(&actor->animB, &tracks[1]);
            kind = actor->model->kind;
            scaled = 0;
            scale.x = 1.0f;
            scale.y = 1.0f;
            scale.z = 1.0f;
            flags = actor->flags;
            if (flags & 0x300000) {
                if (flags & 0x100000) {
                    world = actor->world;
                    if (world->scale != 1.0f) {
                        scaled = 1;
                        if (world->scale > 1.0f) {
                            scale.x = world->scale;
                            scale.y = world->scale * 1.5f;
                        } else {
                            scale.x = world->scale;
                            scale.y = world->scale;
                            scale.z = world->scale;
                        }
                    }
                    f.frame = 1;
                } else {
                    f.frame = 0;
                }
                if (func_80245798_de()) {
                    f.frame = 0;
                }
            }
            if (!func_80245798_de() && ((animA->unk_B == 0 && animB->unk_B == 0) || kind == 1)) {
                f.mode = 0;
            } else {
                f.mode = 1;
            }
            if (!(actor->flags & 0x200000) && (kind == 1 || kind == 11)) {
                if (D_801462C8 & 0x100) {
                    id0 = 0xC3;
                    id1 = 0xC7;
                    id2 = 0xC2;
                    id3 = 0xC6;
                } else {
                    id0 = -1;
                    id1 = -1;
                    id2 = -1;
                    id3 = -1;
                }
                id4 = -1;
                if (D_801462C8 & 0x20) {
                    id4 = 1;
                }
                if (D_801462C8 & 0x80) {
                    scaled = 1;
                    func_80271F9C_de(&scale, &scale, 0.5f);
                }
            } else {
                id0 = -1;
                id1 = -1;
                id2 = -1;
                id3 = -1;
                id4 = -1;
            }
            mtx[0][0][0] = actor->mtx.right.x * 65536.0f;
            mtx[0][1][0] = actor->mtx.up.x * 65536.0f;
            mtx[0][2][0] = actor->mtx.forward.x * 65536.0f;
            mtx[0][3][0] = actor->mtx.m30 * 65536.0f;
            mtx[0][0][1] = actor->mtx.right.y * 65536.0f;
            mtx[0][1][1] = actor->mtx.up.y * 65536.0f;
            mtx[0][2][1] = actor->mtx.forward.y * 65536.0f;
            mtx[0][3][1] = actor->mtx.m31 * 65536.0f;
            mtx[0][0][2] = actor->mtx.right.z * 65536.0f;
            mtx[0][1][2] = actor->mtx.up.z * 65536.0f;
            mtx[0][2][2] = actor->mtx.forward.z * 65536.0f;
            mtx[0][3][2] = actor->mtx.m32 * 65536.0f;
            mtx[0][0][3] = mtx[0][1][3] = mtx[0][2][3] = 0.0f;
            mtx[0][3][3] = 65536.0f;
            out = (u32 *)actor->handle;
            i = 0;
            D_80100530.start = func_802BCF00_de();
            cur = &mtx[1];
            for (; i < count; cur++, out += 16, i++) {
                Shared_PosePartEntry *entry;
                s32 partFlags;

                ctx.index = i;
                entry = (Shared_PosePartEntry *)&ctx.parts->data[i * ctx.parts->stride];
                ctx.part = entry;
                parent = &mtx[entry->u.b.parent + 1];
                partFlags = entry->u.b.flags;
                trackPos(&tracks[0], i, &posA);
                trackRot(&tracks[0], i, &rotA, f.mode);
                if (f.blend) {
                    trackPos(&tracks[1], i, &posB);
                    trackRot(&tracks[1], i, &rotB, f.mode);
                    {
                        f32 t = actor->unk_130;

                        trans.x = posB.x + t * (posA.x - posB.x);
                        trans.y = posB.y + t * (posA.y - posB.y);
                        trans.z = posB.z + t * (posA.z - posB.z);
                    }
                    func_80270AAC_de(&rot, actor->unk_130, &rotB, &rotA);
                } else {
                    trans = posA;
                    rot = rotA;
                }
                if (f.frame) {
                    f.frame = 0;
                    trans.x = trans.y = 0.0f;
                }
                quatToMtx(m, &rot, &trans);
                if (actor->callback != 0) {
                    ((PoseCallback)actor->callback)(m, &ctx);
                }
                func_8026F620_de(*cur, m, *parent);
                if (actor->part.unk_12) {
                    s32 n = 0;
                    if (actor->part.unk_14[0] == i) {
                        n = 4;
                    }
                    if (actor->part.unk_14[1] == i) {
                        n = 3;
                    }
                    if (actor->part.unk_14[2] == i) {
                        n = 2;
                    }
                    if (actor->part.unk_14[3] == i) {
                        n = 1;
                    }
                    if (n != 0 && actor->callback != 0) {
                        twistPart(&actor->part, *cur, n, i);
                    }
                } else if (i != 0 && world != 0 && world->unk_1218 != 0 && ctx.part != 0 &&
                           ctx.part->u.f.kind == 1 && ctx.part->u.f.sway == 0) {
                    if ((actor->flags & 0x1000000) && actor->unk_B8 != 0) {
                        PoseMatrix bone;
                        Vec3 r = randVec();

                        func_80270910_de(bone, actor->unk_B8 + i * 64);
                        func_80247F18_de(actor, &actor->part, bone, actor->pos, r, i);
                    }
                    world->unk_1218 = 0;
                }
                if (actor->flags & 0x800000) {
                    func_802480F0_de(actor, partFlags, *cur);
                }
                if (partFlags == id0) {
                    id0 = -1;
                    func_8027347C_de(*cur, 2.0f, 2.0f, 2.0f);
                } else if (partFlags == id1) {
                    id1 = -1;
                    func_8027347C_de(*cur, 2.0f, 2.0f, 2.0f);
                } else if (partFlags == id2) {
                    id2 = -1;
                    func_8027347C_de(*cur, 2.0f, 2.0f, 2.0f);
                } else if (partFlags == id3) {
                    id3 = -1;
                    func_8027347C_de(*cur, 2.0f, 2.0f, 2.0f);
                } else if (partFlags == id4) {
                    id4 = -1;
                    func_8027347C_de(*cur, 3.0f, 3.0f, 3.0f);
                }
                if (scaled) {
                    func_8027302C(m, *cur);
                    func_8027347C_de(m, scale.x, scale.y, scale.z);
                    packMtx(out, m);
                } else {
                    packMtx(out, *cur);
                }
            }
            dt = func_802BCF00_de() - D_80100530.start;
            if (D_800D2978 != D_80100530.frame) {
                f32 last = D_80100530.cur;
                s32 n = D_80100530.count;

                D_80100530.frame = D_800D2978;
                D_80100530.cur = 0.0f;
                D_80100530.count = 0;
                D_80100530.prev = last;
                D_80100530.prevCount = n;
                D_80100530.avg = D_80100530.avg * 0.97f + last * 0.03f;
            }
            D_80100530.cur += (f32)(((u64)dt * 64) / 3000);
            D_80100530.count++;
            if (f.blend) {
                func_802624A8_de(animB);
            }
            func_802624A8_de(animA);
            switch (kind) {
                case 4:
                    actor->unk_70 = actor->model->unk_38;
                    break;
                case 1:
                case 11: {
                    f32 h = func_8024D284_de(actor);

                    actor->unk_70 = mtx[1][3][1] * (1.0f / 65536.0f) - actor->pos.y - h * 0.5f;
                    if (actor->unk_70 < 0.0f) {
                        actor->unk_70 = 0.0f;
                    }
                    if ((actor->flags & 0x20000000) && actor->surface != 0 && (actor->surface->flags & 0x40)) {
                        f32 ground = func_8027525C_de(actor->surface, actor->pos.x, actor->pos.z);
                        f32 d = actor->pos.y + actor->unk_70 + h;

                        d -= ground;

                        if (d > 0.0f) {
                            mtx[1][3][1] -= d * 65536.0f;
                            actor->unk_70 -= d;
                        }
                    }
                    break;
                }
                default:
                    actor->unk_70 = 0.0f;
                    break;
            }
            if (actor->unk_2E0 != 0) {
                s32 bit = 1 << actor->unk_1;

                if (actor->part.unk_C & bit) {
                    Shared_PosePartTable *table = func_8028FDB4_de(arg1, 3);
                    s32 n = table->count;

                    if (n != 0) {
                        u8 *data = table->data;

                        func_8026E5E0_de(data, n, &mtx[1], actor, func_8028FDB4_de(arg1, 5));
                    }
                }
            }
            if (actor->unk_13B) {
                func_802A57E0_de(&D_801379C0, actor, &mtx[1]);
            }
            if (!(actor->flags & 8)) {
                pos = actor->pos;
                pos.y += actor->unk_70;
                pos.y += func_8024D284_de(actor) * 0.5f;
                func_8028C6D4_de(&D_8011FE88, &pos, actor->unk_140[D_800D297C]);
            }
            ret = 1;
            actor->flags |= 0x200;
        }
        func_80253754_de(0, mem);
    }
    if (!ret) {
        actor->handle = 0;
    }
    return ret;
}
