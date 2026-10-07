#include "p1_types.h"

typedef struct REnt REnt;
struct REnt {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ REnt *next;
    /* 0x08 */ u8 pad8[0x2C];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[4];
    /* 0x3C */ u32 flags;
    /* 0x40 */ u8 pad40[8];
    /* 0x48 */ s32 unk48;
};

typedef struct Rend {
    /* 0x0000 */ DlCmd *dl;
    /* 0x0004 */ u8 pad4[0x7524];
    /* 0x7528 */ REnt *ents;
} Rend;

extern DlCmd *D_80110634;
void func_0026D8F8(void);
void func_00296FF8(void);
void func_0026925C(s32);
void func_00268CE0(s32);
void func_002A453C(REnt *);
void func_002A438C(REnt *, s32);
void func_002A4708(Rend *, REnt *, s32);
void func_002A4DC4(Rend *, REnt *, s32);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002A577C(Rend *r, s32 arg) {
    REnt *e;
    DlCmd *c;

    func_0026D8F8();
    func_00296FF8();
    if (r->dl != NULL) {
        GFX(0xDE000000, (u32)r->dl)
        return;
    }
    r->dl = D_80110634;
    GFX(0xDE010000, 0)
    GFX(0xE7000000, 0)
    func_0026925C(0xE);
    func_00268CE0(0x1C);
    GFX(0xD9F8FB7F, 0)
    GFX(0xD9FFFFFF, 0x200004)
    GFX(0xE3000A01, 0)
    GFX(0xE3000C00, 0x80000)
    GFX(0xD7000000, 0)
    for (e = r->ents; e != NULL; e = e->next) {
        if (e->unk34 < 0) {
            if (e->flags & 8) {
                func_002A453C(e);
            }
            if (e->flags & 4) {
                func_002A438C(e, arg);
            }
            if (e->unk48 >= 2) {
                if (e->unk34 >= 0) {
                    func_002A4708(r, e, arg);
                } else {
                    func_002A4DC4(r, e, arg);
                }
            }
        }
    }
    for (e = r->ents; e != NULL; e = e->next) {
        if (e->unk34 > 0) {
            if (e->flags & 8) {
                func_002A453C(e);
            }
            if (e->flags & 4) {
                func_002A438C(e, arg);
            }
            if (e->unk48 >= 2) {
                if (e->unk34 >= 0) {
                    func_002A4708(r, e, arg);
                } else {
                    func_002A4DC4(r, e, arg);
                }
            }
        }
    }
    GFX(0xDF000000, 0)
    c = r->dl++;
    c->w0 = 0xDE010000;
    c->w1 = (u32)D_80110634;
    GFX(0xDE000000, (u32)r->dl)
}
