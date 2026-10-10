/* func_00265E30: dispatch a message to all objects (handler table D_800D1380[kind]).  -O2 -mcpu=r4300. */
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

static inline void send_(void *tgt, void *dst, s32 kind, M04Vec3 p, M04Part q) {
    if (D_800D1380[kind].fn != 0) {
        D_800D1380[kind].fn(tgt, dst, kind, p, q);
    }
}

void func_00265E30(void *src, void *dst, s32 kind, s32 id, M04Vec3 pos, M04Part part) {
    s32 i;
    s32 n;
    u8 *p;
    void **pp;
    void *cur;
    u8 *base;
    M04Node *o;
    if (D_8011FE88.mode == 4 || (D_800D1380[kind].flags & 0x10)) {
        if (!(D_800D1380[kind].flags & 2)) {
            send_(src, dst, kind, pos, part);
        } else if (D_800D1380[kind].flags & 8) {
            n = D_8011FE88.nobjs;
            base = D_8011FE88.objs;
            i = 0;
            if (n > 0) {
                do {
                    cur = base + i * 0x2E8;
                    if (cur != src) {
                        send_(cur, dst, kind, pos, part);
                    }
                    i++;
                } while (i < n);
            }
            o = D_80145060;
            if (o != 0) {
                do {
                    if ((void *)o != src && (void *)((u8 *)o + 0x2E8) != src) {
                        send_(o, dst, kind, pos, part);
                    }
                    o = o->next;
                } while (o != 0);
            }
        } else {
            n = *(s32 *)((u8 *)&D_8011FE88 + 0xE50);
            for (i = 0; i < n; i++) {
                cur = ((M04WorldB *)&D_8011FE88)->tab[i];
                if (cur != src) {
                    send_(cur, dst, kind, pos, part);
                }
            }
            o = D_80145060;
            if (o != 0) {
                do {
                    if ((void *)o != src && (void *)((u8 *)o + 0x2E8) != src) {
                        send_(o, dst, kind, pos, part);
                    }
                    o = o->next;
                } while (o != 0);
            }
        }
    }
}