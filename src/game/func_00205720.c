#include "s502_types.h"

typedef struct S5Q4 {
    f32 w[4];
} S5Q4;

typedef struct S5Info {
    /* 0x00 */ u32 flags;
    /* 0x04 */ s32 kind;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ s16 id14;
    /* 0x16 */ s16 id16;
    /* 0x18 */ f32 v18;
    /* 0x1C */ f32 v1C;
    /* 0x20 */ f32 v20;
    /* 0x24 */ s16 id24;
} S5Info;

typedef struct S5Spawn {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 surf;
    /* 0x18 */ u8 *def;
    /* 0x1C */ Vec3f v1C;
    /* 0x28 */ u8 pad28[0x34];
    /* 0x5C */ S5Q4 q;
    /* 0x6C */ f32 ang;
} S5Spawn;

typedef struct S5Own {
    /* 0x000 */ u8 pad0[0x124];
    /* 0x124 */ s32 list;
    /* 0x128 */ s32 count;
} S5Own;

typedef struct S5Ent {
    s16 id;
    s16 w;
} S5Ent;

typedef struct S5Obj {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ u8 pad14[0x18C];
    /* 0x1A0 */ s32 unk1A0;
} S5Obj;

typedef struct S5Walk S5Walk;
struct S5Walk {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 *kindp;
    /* 0x1C */ u8 pad1C[0x2D0];
    /* 0x2EC */ S5Walk *next;
};

typedef struct S5List {
    s16 count;
    u8 pad[0x66];
} S5List;

void func_00216288(void *o, s32 id, Vec3f pos, s32 z);
s32 func_00222D40(s32 a, s32 id);
s32 func_0022A404(void *p);
s32 func_0022A8E0(void *p);
s32 func_0022ADA0(s32 a, s32 id);
s32 func_00262D00(void *a0, s32 id, s32 z, s32 *p, s32 t0, Vec3f pos, f32 ang, Vec3f v1, Vec3f v2, void *list);
f32 func_00275E44(s32 a, f32 x, f32 z);
s32 func_00279808(void *tab);
void func_002798CC(S5List *l);
void func_002798D4(S5List *l, s32 id, s32 w);
s32 func_00279918(S5List *l);
s32 func_00280094(void *a0, void *a1, void *a2, void *list, s32 z, s32 id, Vec3f v1, S5Q4 q, Vec3f pos, s32 z1, s32 m1, s32 z2);
s32 func_0028B238(void *a0, s32 id);
s32 *func_0028CF48(void *a0, s32 id);
S5Obj *func_0028FFB0(void *a0, void *list, s32 id, Vec3f v, Vec3f pos, s32 t0, s32 z);

extern s16 D_800CD760[];
extern s16 D_800CD764[];
extern s16 D_800CD768[];
extern s16 D_800CD778[];
extern s16 D_800CD784[];
extern s16 D_800CD794[];
extern S5Ent D_800CD798[];
extern u8 *D_800E4680;
extern u8 D_8011FE88[];
extern u8 D_80121990[];
extern u8 D_80131600[];
extern u8 D_80135210[];
extern S5Walk *D_8013B124;
extern s32 D_8013B290;
extern u8 D_80145040[];
typedef struct { u8 pad[0x1D]; u8 unk1D; } S5G;
extern S5G D_801462C8[];
extern u8 D_801462D5;
extern s32 D_80146918;
extern s32 D_80146920;

static inline s32 canSpawn(s32 id) {
    S5Walk *w;

    if (id == 0x84F) {
        w = D_8013B124;
        if (w != NULL) {
            do {
                if (*w->kindp == 4) {
                    return 0;
                }
                w = w->next;
            } while (w != NULL);
        }
        return func_0022A8E0(D_80145040) == 0;
    }
    return 1;
}

/* Same check as canSpawn, written with an early return and a goto to the trailing 'return 0': the layout of the blocks
   decides how reorg fills the branch delay slots (plain bne here, bnel in the other copy) -- see FINDINGS. */
static inline s32 canSpawnTbl(s32 id) {
    S5Walk *w;

    if (id != 0x84F) {
        return 1;
    }
    w = D_8013B124;
    while (w != NULL) {
        if (*w->kindp == 4) {
            goto zero;
        }
        w = w->next;
    }
    return func_0022A8E0(D_80145040) == 0;
zero:
    return 0;
}

static inline void spawnObj(S5Spawn *sp, S5Own *own, Vec3f pos, s32 t0, s32 id) {
    S5Obj *o;

    if (id == 0xBD7 && D_80146918 != 0 && D_80146920 != 0) {
        return;
    }
    if (id == 0x1388 && D_801462D5 == 1) {
        id = *D_800E4680 + 0x1388;
        if (id == 0x1388) {
            return;
        }
    }
    o = func_0028FFB0(D_80131600, &own->list, id, sp->v1C, pos, t0, 0);
    if (o != NULL) {
        o->unk1A0 = 0;
        own->count--;
        func_00216288(o, 0x11D, o->pos, 0);
    }
}

static inline void callA(S5Spawn *sp, S5Own *own, Vec3f v1, Vec3f v2, s32 p68, s32 p6C, s32 *p70) {
    if (func_00262D00(D_80135210, p6C, 0, p70, p68, v1, sp->ang, sp->v1C, v2, &own->list) != 0) {
        own->count--;
    }
}

static inline void callB(S5Spawn *sp, S5Own *own, Vec3f v, s32 p6C, s32 p70) {
    own->count -= func_00280094(D_80121990, sp, sp, &own->list, 0, p70, sp->v1C, sp->q, v, 0, -1, 0);
}

void func_00205720(S5Spawn *sp, S5Own *own) {
    Vec3f pos;
    Vec3f v2;
    S5Info *info;
    s32 t0;
    f32 h;
    s32 *p;
    s32 id;
    s32 id8;
    s32 s5;
    s32 s6;
    s32 s3;
    s32 v;
    S5Ent *e;
    s16 *e2;
    S5List l70;
    S5List lD8;

    info = (S5Info *)(sp->def + 0x14);
    pos = sp->pos;
    t0 = sp->surf;
    if (t0 != 0) {
        h = func_00275E44(t0, sp->pos.x, sp->pos.z);
        if (pos.y < h) {
            pos.y = h;
        }
    }
    switch (info->kind) {
    case 0:
        p = func_0028CF48(D_8011FE88, info->id16);
        switch (*p) {
        case 8:
            id8 = func_0028B238(D_8011FE88, info->id14);
            if (canSpawn(id8)) {
                spawnObj(sp, own, pos, t0, id8);
            }
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
            v2.x = info->v18;
            v2.y = info->v1C;
            v2.z = info->v20;
            callA(sp, own, pos, v2, t0, info->id14, p);
            break;
        }
        break;
    case 1:
        callB(sp, own, pos, 0, info->id24);
        break;
    case 2:
        s5 = -1;
        s6 = s5;
        s3 = s5;
        if (D_801462C8->unk1D != 0) {
            if (info->flags & 0x20) {
                s5 = (s16)func_00279808(D_800CD764);
            }
            if (info->flags & 0x40) {
                s6 = (s16)func_00279808(D_800CD784);
            }
            if (info->flags & 0x80) {
                func_002798CC(&lD8);
                for (e = D_800CD798; e->id != -1; e++) {
                    if (canSpawnTbl(e->id)) {
                        func_002798D4(&lD8, e->id, e->w);
                    }
                }
                s3 = (s16)func_00279918(&lD8);
            }
        } else {
            v = func_0022A404((u8 *)D_801462C8 - 0x1288);
            if (v == 0) {
                return;
            }
            if (info->flags & 0x20) {
                func_002798CC(&l70);
                for (e2 = D_800CD760; *e2 != -1; e2 += 2) {
                    if (func_00222D40(v, *e2) != 0) {
                        func_002798D4(&l70, e2[0], e2[1]);
                    }
                }
                s5 = (s16)func_00279918(&l70);
            }
            if (info->flags & 0x40) {
                func_002798CC(&l70);
                e2 = D_800CD768;
                if (D_8013B290 != 0) {
                    e2 = D_800CD778;
                }
                for (; *e2 != -1; e2 += 2) {
                    if (func_0022ADA0(v, *e2) != 0) {
                        func_002798D4(&l70, e2[0], e2[1]);
                    }
                }
                s6 = (s16)func_00279918(&l70);
            }
            if (info->flags & 0x80) {
                s3 = (s16)func_00279808(D_800CD794);
            }
        }
        func_002798CC(&l70);
        if (s5 != -1) {
            func_002798D4(&l70, s5, 0x64);
        }
        if (s6 != -1) {
            func_002798D4(&l70, s6, 0x64);
        }
        if (s3 != -1) {
            func_002798D4(&l70, s3, 0x64);
        }
        if (l70.count != 0) {
            id = (s16)func_00279918(&l70);
            spawnObj(sp, own, pos, t0, id);
        }
        break;
    }
}
