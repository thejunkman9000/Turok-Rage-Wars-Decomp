#include "b24_types.h"

typedef struct Plr24 Plr24;
struct Plr24 {
    u8 pad0[0x5E4];
    s32 unk5E4;
    u8 pad5E8[0xC3C];
    s32 unk1224;
    s32 unk1228;
    u8 pad122C[0x4B4];
    Plr24 *next;
};

typedef struct Row18 Row18;
struct Row18 {
    s32 pad0;
    s16 id;
    u8 pad6[14];
    s32 (*fn)(Plr24 *, Row18 *, s32);
};
typedef struct Row14 Row14;
struct Row14 {
    s32 pad0;
    s16 id;
    u8 pad6[10];
    s32 (*fn)(Plr24 *, Row14 *, s32);
};
typedef struct Row10 Row10;
struct Row10 {
    s32 pad0;
    s16 id;
    u8 pad6[6];
    s32 (*fn)(Plr24 *, Row10 *, s32);
};
extern Row18 D_800D31D0[];
extern Row14 D_800D3230[];
extern Row18 D_800D32A8[];
extern Row14 D_800D3368[];
extern Row18 D_800D34C0[];
extern Row10 D_800D33C0[];
extern Row10 D_800D3390[];
extern Plr24 *D_80145060;

inline Row18 *lk0(s32 id) {
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

inline Row14 *lk1(s32 id) {
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

inline Row18 *lk2(s32 id) {
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

inline Row14 *lk3(s32 id) {
    s32 i;
    Row14 *p = D_800D3368;
    for (i = 1; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

inline Row18 *lk4(s32 id) {
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

inline Row10 *lk5(s32 id) {
    s32 i;
    Row10 *p = D_800D33C0;
    for (i = 15; i != -1; i--) {
        if (p->id == id) {
            return p;
        }
        p++;
    }
    return NULL;
}

inline Row10 *lk6(s32 id) {
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

s32 func_002AC6DC(Plr24 *a0, s32 a1, s32 a2) {
    s32 r = 0;
    Plr24 *q;
    Row18 *p18;
    Row14 *p14;
    Row10 *p10;
    if (a0->unk5E4 != 0) {
        p18 = lk0(a2);
        if (p18 != NULL) {
            r = p18->fn(a0, p18, -1);
        }
        if (r == 0) {
            p14 = lk1(a2);
            if (p14 != NULL) {
                r = p14->fn(a0, p14, -1);
            }
            if (r == 0) {
                p18 = lk2(a2);
                if (p18 != NULL) {
                    r = p18->fn(a0, p18, -1);
                }
                if (r == 0) {
                    p14 = lk3(a2);
                    if (p14 != NULL) {
                        r = p14->fn(a0, p14, -1);
                    }
                    if (r == 0) {
                        p18 = lk4(a2);
                        if (p18 != NULL) {
                            r = p18->fn(a0, p18, -1);
                        }
                        for (q = D_80145060; q != NULL; q = q->next) {
                            if (q->unk1224 == a1) {
                                q->unk1224 = 0;
                            } else if (q->unk1228 == a1) {
                                q->unk1228 = 0;
                            }
                        }
                        if (r == 0) {
                            p10 = lk5(a2);
                            if (p10 != NULL) {
                                r = p10->fn(a0, p10, a1);
                            }
                            if (r == 0) {
                                p10 = lk6(a2);
                                if (p10 != NULL) {
                                    r = p10->fn(a0, p10, -1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return r;
}
