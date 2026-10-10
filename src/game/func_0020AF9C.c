#include "s502_types.h"

s32 func_0024DED0(S5Actor *a);
s32 func_0024DF4C(S5Actor *a);
s32 func_0024DF90(S5Actor *a);
s32 func_0024E61C(S5Actor *a);
s32 func_00243A80(S5Actor *a, Vec3f pos, B2Opts *opts);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
extern B2Opts D_801040D0;
extern B2Opts D_80104050;
extern B2Opts D_80104070;
extern B2Opts D_80103FF0;

static inline Vec3f *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return (Vec3f *)&pool->data[idx * pool->elemSize];
}

static inline B2Edge *getEdge(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool8;

    return (B2Edge *)&pool->data[idx * pool->elemSize];
}

static inline s32 collect(B2Mgr *m, s32 key, s32 *outV, s32 *outI) {
    s32 k;
    s32 cnt;
    B2Edge *e;

    cnt = k = 0;
    for (; k < m->count; k++) {
        e = getEdge(m, k);
        if (e->a == key) {
            outV[cnt] = e->b;
            outI[cnt] = k;
            cnt++;
        }
        if (e->b == key) {
            outV[cnt] = e->a;
            outI[cnt] = k;
            cnt++;
        }
    }
    return cnt;
}

static inline s32 probe(B2Mgr *m, S5Actor *a, s32 idx) {
    Vec3f pos;
    B2Opts opts;
    B2Blk80 save;
    s32 r;
    s32 s0;

    pos = *getRec0(m, idx);
    pos.y += 61.44f;
    if (a->kind == 1 && (a->flags & 0x300000)) {
        opts = D_801040D0;
    } else {
        s0 = func_0024DED0(a);
        if (func_0024DF4C(a) == 0) {
            if (s0 != 0) {
                opts = D_80104050;
            } else {
                opts = D_801040D0;
            }
        } else if (func_0024DF90(a) == 0) {
            opts = D_80104070;
        } else {
            opts = D_80103FF0;
        }
    }
    opts.w0 = 0x4000;
    save = *(B2Blk80 *)a;
    r = func_00243A80(a, pos, &opts);
    *(B2Blk80 *)a = save;
    return r;
}

void func_0020AF9C(B2Mgr *m, S5Actor *a) {
    s32 nb[64];
    s32 ed[64];
    Vec3f d;
    f32 bestd;
    f32 dd;
    f32 ady;
    f32 dy;
    S5Brain *br;
    B2Rec *rec;
    B2Edge *e;
    s32 f1;
    s32 f2;
    s32 i;
    s32 j;
    s32 cnt;
    s32 key;
    s32 best;
    s32 idx;
    s32 started;
    s32 edge;
    s32 z;
    s32 type;
    s32 x;
    s32 w;

    for (i = 0; i < 64; i++) {
        nb[i] = -1;
        ed[i] = -1;
    }
    started = 0;
    f1 = a->flags38 & 0x2000;
    f2 = a->flags38 & 0x1000;
    func_00271FD8(&d, getRec0(m, a->brain->key), &a->pos);
    if (f1 != 0 || f2 != 0) {
        dd = d.x * d.x + d.y * d.y + d.z * d.z;
    } else {
        dd = d.x * d.x + d.z * d.z;
    }
    ady = d.y;
    bestd = dd;
    if (ady < 0.0f) {
        ady = -ady;
    }
    best = a->brain->key;
    if (a->unk1450 != 0) {
        if (a->brain->unk14 != -1) {
            x = func_0024E61C(a);
            z = 0;
            w = a->unk650 == 0xF;
            if (x != 0) {
                z = a->unk6D0 == 0;
                goto b14;
            }
            if (w != 0 || f1 != 0) {
b14:
                if (z == 0) {
                    idx = a->brain->unk14;
                    if (idx == -1) {
                        idx = a->brain->unkC;
                    }
                    rec = (B2Rec *)getRec0(m, idx);
                    func_00271FD8(&d, (Vec3f *)rec, &a->pos);
                    if (f1 != 0 || f2 != 0 || (rec->flags & 0x200)) {
                        dd = d.x * d.x + d.y * d.y + d.z * d.z;
                    } else {
                        dd = d.x * d.x + d.z * d.z;
                    }
                    if (dd < bestd) {
                        if (d.y < 0.0f) {
                            if (-d.y < 307.19998f) {
                                goto b27;
                            }
                        } else if (d.y < 307.19998f) {
b27:
                            a->brain->prev = a->brain->key;
                            a->brain->key = idx;
                        }
                    }
                } else {
                    a->brain->unk14 = -1;
                    goto b30;
                }
            } else {
                goto b30;
            }
        } else {
            goto b30;
        }
    } else {
b30:
        cnt = collect(m, a->brain->key, nb, ed);
        i = 0;
        if (cnt > 0) {
            do {
                idx = nb[i];
                rec = (B2Rec *)getRec0(m, idx);
                e = getEdge(m, ed[i]);
                if (!(*(u32 *)&rec->flags & 0x300000) || f2 != 0 || f1 != 0) {
                    func_00271FD8(&d, (Vec3f *)rec, &a->pos);
                    if (f1 != 0 || f2 != 0) {
                        dd = d.x * d.x + d.y * d.y + d.z * d.z;
                    } else {
                        dd = d.x * d.x + d.z * d.z;
                    }
                    dy = d.y;
                    if (dy < 0.0f) {
                        dy = -dy;
                    }
                    type = e->kind;
                    if (type == 3 || type == 10 || type == 5 || (f2 == 0 && (rec->flags & 0x20))) {
                        if (dy < ady) {
                            if (started == 0) {
                                bestd = -1.0f;
                                started = 1;
                            }
                            if (dd < bestd || bestd == -1.0f) {
                                if (probe(m, a, idx) == 0) {
                                    bestd = dd;
                                    best = idx;
                                }
                            }
                        }
                    } else if (dd < bestd) {
                        if (probe(m, a, idx) == 0) {
                            bestd = dd;
                            best = idx;
                        }
                    }
                }
                i++;
            } while (i < cnt);
        }
        if (a->brain->key != best) {
            a->brain->prev = a->brain->key;
        }
        a->brain->key = best;
    }
}
