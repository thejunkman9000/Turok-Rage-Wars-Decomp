#include "common.h"

typedef struct S705Rec {
    /* 0x0 */ s32 off;
    /* 0x4 */ s8 w;
    /* 0x5 */ s8 h;
    /* 0x6 */ s8 c;
    /* 0x7 */ s8 d;
} S705Rec;

typedef struct S705Meta {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s16 fmt;
    /* 0x0A */ u8 pad0A[0xE];
    /* 0x18 */ s32 base;
    /* 0x1C */ s32 size;
} S705Meta;

typedef struct S705Obj {
    /* 0x000 */ s32 loaded;
    /* 0x004 */ S705Rec rec[0x60];
    /* 0x304 */ s32 off[0x60];
    /* 0x484 */ u8 **blocks;
    /* 0x488 */ void **pals;
    /* 0x48C */ S705Meta *meta;
    /* 0x490 */ u8 count;
    /* 0x491 */ u8 pad491[3];
    /* 0x494 */ s32 timer494;
    /* 0x498 */ s16 timer498;
    /* 0x49A */ s16 pad49A;
} S705Obj;

typedef struct S705Slot {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ s32 time;
    /* 0x08 */ u16 flags;
    /* 0x0A */ u16 pad0A;
    /* 0x0C */ u8 payload[0x20];
} S705Slot;

typedef struct S705Pool {
    s16 count;
    s16 pad2[3];
    S705Obj *entries;
} S705Pool;
extern S705Pool D_80153C20;
extern s32 D_80153BD0[];
extern s32 D_801539B0[];
extern u8 D_800E10E0[];

s32 func_002A2934(void);
void func_002A28CC(void);
void func_00413464(void *p);
void func_00413484(void *p);
void func_00419510(void *p);
void func_00419748(s32 a);
void func_004196C0(void *a, void *b);
s32 func_00252FFC(s32 n);
s32 func_002A1E8C(void *a, void *b);
void func_002A1EB0(s32 a);
void func_002A1ED4(s32 a, s32 b, s32 c, s32 d);
void func_002A1F60(s32 a, s32 b, s32 c);
void func_004137A0(void *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, s32 l);

void *func_00410FD4(u8 slot, s32 idx, s32 which) {
    s32 off;
    S705Obj *obj;
    S705Obj *o2;
    S705Slot *s;
    u8 *blk;
    s32 bpp;
    s32 i;
    void *payload;
    void *payload2;
    S705Meta *meta;
    s32 fmt;
    S705Rec *r;
    S705Slot *saved;
    s32 thr;
    s32 sizes[0x60];
    u8 st[0x20];
    s32 *g;
    s32 sz;
    s32 t;

    blk = D_80153C20.entries[idx].blocks[which];
    off = slot * 0x2C;
    s = (S705Slot *)(off + (s32)blk);
    if (s->flags & 1) {
        s->time = func_002A2934() + 10;
        obj = &D_80153C20.entries[idx];
        if (obj->timer498 == 0 && obj->timer494 != -1) {
            obj->timer494 = s->time;
        }
        return blk + slot * 0x2C + 0xC;
    }
    fmt = 0;
    func_002A28CC();
    meta = D_80153C20.entries[idx].meta;
    r = &D_80153C20.entries[idx].rec[slot];
    bpp = 0;
    saved = s;
    if (r->w == 0 || r->h == 0) {
        return 0;
    }
    payload = saved->payload;
    func_00413464(payload);
    payload2 = payload;
    if (meta->fmt == 0) {
        bpp = 0x20;
    } else if (meta->fmt < 0x11) {
        bpp = 4;
    } else if (meta->fmt < 0x101) {
        bpp = 8;
    }
    if (meta->fmt > 0) {
        fmt = 0x14;
        if (bpp == 8) {
            fmt = 0x1E;
        }
    } else {
        if (bpp == 0x10) {
            fmt = 0x1C;
        } else if (bpp == 0x18) {
            fmt = 8;
        } else if (bpp == 0x20) {
            fmt = 0xC;
        }
    }
    if (D_80153C20.entries[idx].loaded == 0) {
        g = D_80153BD0;
        o2 = (S705Obj *)(g[0x16]) + idx;
        g[-0x88] = func_002A1E8C(g - 0x87, D_800E10E0);
        sz = o2->meta->size;
        o2->off[0] = func_00252FFC(sz);
        {
            u8 *st = (u8 *)(g - 0x88);
            func_002A1F60(g[-0x88], *(volatile s32 *)(st + 0x250) + o2->meta->base, 0);
        }
        func_002A1ED4(D_80153C20.entries[idx].off[0], sz, 1, g[-0x88]);
        for (i = 0; i < 0x60; i++) {
            t = (sizes[i] = o2->rec[i].c * o2->rec[i].h);
            sizes[i] = t * bpp / 8;
            o2->off[i] = o2->off[0] + (o2->rec[i].off - o2->meta->base);
        }
        thr = 0x1000;
        if (meta->fmt > 0) {
            thr = 0x800;
        }
        for (i = 0; i < 0x60; i++) {
            if (thr < sizes[i]) {
                S705Rec *rr = &D_80153C20.entries[idx].rec[i];
                func_00413464(st);
                func_004137A0(st, fmt, rr->w, rr->h, rr->c, rr->h, 0, sizes[i], D_80153C20.entries[idx].off[i], 0, meta->fmt * 2, (s32)D_80153C20.entries[idx].pals[which], meta->fmt);
                func_00419510(st);
                func_00413484(st);
            }
        }
        func_002A1EB0(D_801539B0[0]);
        D_801539B0[0] = 0;
        o2->loaded = 1;
    }
    t = (r->c * r->h * bpp) >> 3;
    func_004137A0(payload, fmt, r->w, r->h, r->c, r->h, 0, t, D_80153C20.entries[idx].off[slot], 0, meta->fmt * 2, (s32)D_80153C20.entries[idx].pals[which], meta->fmt);
    func_00419748(0);
    func_004196C0(payload2, payload);
    func_00419748(1);
    func_002A28CC();
    saved->time = func_002A2934() + 10;
    D_80153C20.entries[idx].count++;
    saved->flags |= 1;
    return saved->payload;
}
