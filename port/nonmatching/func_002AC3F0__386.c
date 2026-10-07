#include "b24_types.h"

typedef struct Row18 {
    s32 pad0;
    s16 id;
    s16 unk6;
    u8 pad8[4];
    s16 unkC;
    u8 padE[0xA];
} Row18;

typedef struct Row14 {
    s32 pad0;
    s16 id;
    u8 pad6[6];
    s16 unkC;
    u8 padE[6];
} Row14;

typedef struct Row10 {
    s32 pad0;
    s16 id;
    u8 pad6[0xA];
} Row10;

extern Row18 D_800D31D0[];
extern Row14 D_800D3230[];
extern Row18 D_800D32A8[];
extern Row18 D_800D34C0[];
extern Row10 D_800D3390[];
extern u32 D_800CE474[];
extern s32 D_801468F4;
s32 func_0022ABF0(Ent24 *, s32, s32);
s32 func_0022ACA8(Ent24 *, s32, s32);
s32 func_0024E914(void *);

static inline Row18 *lk0(s32 id) {
    s32 i;
    Row18 *p = D_800D31D0;
    for (i = 3; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

static inline Row14 *lk1(s32 id) {
    s32 i;
    Row14 *p = D_800D3230;
    for (i = 5; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

static inline Row18 *lk2(s32 id) {
    s32 i;
    Row18 *p = D_800D32A8;
    for (i = 7; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

static inline Row18 *lk4(s32 id) {
    s32 i;
    Row18 *p = D_800D34C0;
    for (i = 15; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

static inline Row10 *lk6(s32 id) {
    s32 i;
    Row10 *p = D_800D3390;
    for (i = 2; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

#define ISX(o) (*(u8 *)(o) == 1 && ((o)->flags100 & 0x300000))

s32 func_002AC3F0(void *a0, Ent24 *o) {
    s32 id = func_0024E914(a0);
    Row18 *r18;
    Row14 *r14;
    Row10 *r10;
    s32 i, hasA, hasB, v;
    if (ISX(o)) {
        if (o->unk5E4 == 0) {
            return 0;
        }
        if (D_801468F4 != 0 && o->unk5D8->unk8F != 0) {
            return 1;
        }
        r18 = lk0(id);
        if (r18 != NULL) {
            hasA = 1;
            hasB = 1;
            if (o->unkE4 == D_800CE474[0] || o->unkE4 == D_800CE474[1]) {
                return 1;
            }
            if (o->slot[r18->unkC].b != -1) {
                return 0;
            }
            for (i = 0; i < 22; i++) {
                if (o->slot[i].b == 3) {
                    hasA = 0;
                } else if (o->slot[i].b == 7) {
                    hasB = 0;
                }
            }
            if (hasA != 0) {
                return 1;
            }
            if (hasB != 0) {
                return 0;
            }
            return 0;
        }
        r14 = lk1(id);
        if (r14 != NULL) {
            v = func_0022ACA8(o, r14->unkC, 0);
            if (o->unkE4 == D_800CE474[0] || o->unkE4 == D_800CE474[1]) {
                return 1;
            }
            return *(s16 *)((u8 *)o + r14->unkC * 2 + 0x5F4) < v;
        }
        r18 = lk2(id);
        if (r18 != NULL) {
            return o->unk5E4 < func_0022ABF0(o, id, -1);
        }
        r18 = lk4(id);
        if (r18 != NULL) {
            return 1;
        }
        r10 = lk6(id);
        if (r10 == NULL) {
            return 0;
        }
        if (o->unkE4 == D_800CE474[0] || o->unkE4 == D_800CE474[1]) {
            if (r10->id != 0xBD6) {
                return 1;
            }
        }
        return r10->id != 0xBD6;
    }
    return ISX(o);
}
