
#include "m04_types.h"

typedef void (*M04Handler)(void *, void *, s32, M04Vec3, M04Part);

typedef struct M04Msg {
    M04Handler fn;
    u32 flags;
} M04Msg;

typedef struct M04World {
    /* 0x000 */ s32 mode;
    /* 0x004 */ u8 pad4[0x134];
    /* 0x138 */ u8 *objs;
    /* 0x13C */ u8 pad13C[4];
    /* 0x140 */ s32 nobjs;
} M04World;

typedef struct M04WorldB {
    /* 0x000 */ u8 pad0[0xC50];
    /* 0xC50 */ void *tab[1];
} M04WorldB;

typedef struct M04Node {
    u8 pad0[0x16E0];
    struct M04Node *next;
} M04Node;

extern M04Msg D_800D1380[];
extern M04World D_8011FE88;
extern M04Node *D_80145060;

void func_00265E30(void *src, void *dst, s32 kind, s32 id, M04Vec3 pos, M04Part part) {
    struct { M04Vec3 p; M04Part q; } L;
    u8 pad[8];
    s32 i;
    s32 n;
    u8 *p;
    void **pp;
    M04Node *o;
    pad[0] = 0;
    if (D_8011FE88.mode == 4 || (D_800D1380[kind].flags & 0x10)) {
        if (!(D_800D1380[kind].flags & 2)) {
            L.p = pos;
        L.q = part;
            if (D_800D1380[kind].fn != 0) {
                D_800D1380[kind].fn(src, dst, kind, L.p, L.q);
            }
        } else if (D_800D1380[kind].flags & 8) {
            n = D_8011FE88.nobjs;
            i = 0;
            if (n > 0) {
                p = D_8011FE88.objs;
                do {
                    if (p != src) {
                        L.p = pos;
        L.q = part;
                        if (D_800D1380[kind].fn != 0) {
                            D_800D1380[kind].fn(p, dst, kind, L.p, L.q);
                        }
                    }
                    i++;
                    p += 0x2E8;
                } while (i < n);
            }
            o = D_80145060;
            if (o != 0) {
                do {
                    if ((void *)o != src && (void *)((u8 *)o + 0x2E8) != src) {
                        L.p = pos;
        L.q = part;
                        if (D_800D1380[kind].fn != 0) {
                            D_800D1380[kind].fn(o, dst, kind, L.p, L.q);
                        }
                    }
                    o = o->next;
                } while (o != 0);
            }
        } else {
            n = *(s32 *)((u8 *)&D_8011FE88 + 0xE50);
            i = 0;
            if (n > 0) {
                pp = (void **)((u8 *)&D_8011FE88 + 0xC50);
                do {
                    if (*pp != src) {
                        L.p = pos;
        L.q = part;
                        if (D_800D1380[kind].fn != 0) {
                            D_800D1380[kind].fn(*pp, dst, kind, L.p, L.q);
                        }
                    }
                    i++;
                    pp++;
                } while (i < n);
            }
            o = D_80145060;
            if (o != 0) {
                do {
                    if ((void *)o != src && (void *)((u8 *)o + 0x2E8) != src) {
                        L.p = pos;
        L.q = part;
                        if (D_800D1380[kind].fn != 0) {
                            D_800D1380[kind].fn(o, dst, kind, L.p, L.q);
                        }
                    }
                    o = o->next;
                } while (o != 0);
            }
        }
    }
}


