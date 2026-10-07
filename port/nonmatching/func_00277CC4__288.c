#include "b17_types.h"

typedef struct M5Cell { f32 x0, z0, x1, z1; } M5Cell;
typedef struct M5Ent { s32 *a; M5Cell *cell; s32 pad8; } M5Ent;
typedef struct M5Grid {
    u8 pad0[0x1500];
    s32 n;
    u8 pad1504[4];
    M5Ent ent[1];
} M5Grid;

#define BOXHIT(q, rec) \
    ((q)->mx.x > (rec)->box.mn.x && (q)->mn.x < (rec)->box.mx.x && (q)->mx.z > (rec)->box.mn.z && \
     (q)->mn.z < (rec)->box.mx.z && (q)->mx.y > (rec)->box.mn.y && (q)->mn.y < (rec)->box.mx.y)

extern M5Grid D_8011FE88;
void *func_0028FD94();

s32 func_00277CC4(Box3 *q, WRec **out, s32 *cnt) {
    s32 hashes[64];
    M5Ent *list[64];
    s32 spare[64];
    s32 n, ncell, i, ret, j, k, sum, dup, m;
    WTab *tab;
    WRec *rec;
    M5Cell *c;
    s32 *wp;
    s32 off;
    M5Ent *e;
    M5Grid *g;

    g = &D_8011FE88;
    n = 0;
    ncell = 0;
    i = 0;
    ret = 0;
    if (g->n > 0) {
        off = 0x1508;
        do {
            e = (M5Ent *)((u8 *)g + off);
            c = e->cell;
            if (q->mn.x < c->x1 && c->x0 < q->mx.x && q->mn.z < c->z1 && c->z0 < q->mx.z) {
                list[ncell] = e;
                ncell++;
            }
            off += 12;
            i++;
        } while (i < g->n);
    }
    if (ncell == 1) {
        tab = func_0028FD94(*list[0]->a, 2);
        do { j = tab->count; } while (0);
        j--;
        if (j != -1) {
            rec = tab->r;
            do {
                if (BOXHIT(q, rec)) {
                    do {
                    out[n] = rec;
                    n++;
                    if (rec->bBA != 0) {
                        ret = 1;
                    }
                    if (n == 0x40) {
                        break;
                    }
                    } while (0);
                }
                rec++;
                j--;
            } while (j != -1);
        }
        *cnt = n;
    } else if (ncell >= 2) {
        for (i = 0; i < ncell; i++) {
            tab = func_0028FD94(*list[i]->a, 2);
            j = tab->count;
            j--;
            if (j != -1) {
                rec = tab->r;
                do {
                    if (BOXHIT(q, rec)) {
                        sum = 0;
                        wp = (s32 *)((u8 *)rec + 0x60);
                        for (k = 0; k < 16; k++) {
                            sum += wp[k];
                        }
                        dup = 0;
                        if (i != 0) {
                            for (m = 0; m < n; m++) {
                                if (hashes[m] == sum) {
                                    dup = 1;
                                    break;
                                }
                            }
                        }
                        if (dup == 0) {
                            out[n] = rec;
                            hashes[n] = sum;
                            n++;
                            if (rec->bBA != 0) {
                                ret = 1;
                            }
                            if (n == 0x40) {
                                *cnt = n;
                                return ret;
                            }
                        }
                    }
                    rec++;
                    j--;
                } while (j != -1);
            }
        }
        do { *cnt = n; } while (0);
    } else {
        *cnt = n;
    }
    return ret;
}