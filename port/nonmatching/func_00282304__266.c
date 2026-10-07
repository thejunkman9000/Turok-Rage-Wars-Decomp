#include "b18_types.h"

typedef struct B18DObj B18DObj;
struct B18DObj {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[0x44];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18CfgB *cfg;
    /* 0x11C */ u8 pad11C[0x34];
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15C */ u8 pad15C[0x7D];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[0x1A];
    /* 0x1F4 */ B18DObj *next;
};

typedef struct B18DCam {
    /* 0x000 */ u8 pad0[0x2F0];
    /* 0x2F0 */ u8 unk2F0[0x60];
    /* 0x350 */ f32 f350;
    /* 0x354 */ f32 f354;
    /* 0x358 */ f32 f358;
    /* 0x35C */ f32 f35C;
    /* 0x360 */ f32 f360;
    /* 0x364 */ f32 f364;
} B18DCam;

typedef struct B18DWorld {
    /* 0x0000 */ u8 pad0[0xFC14];
    /* 0xFC14 */ B18DObj *head;
} B18DWorld;

extern DlCmd *D_80110634;
extern s32 D_801450B8;
extern u8 *D_801450A8;
extern s32 D_800D297C;
extern u8 D_8013BA80[];

void func_0026D914(s32 a);
s32 func_00297B74(void *a, f32 *b);
void func_00272908(void *m, void *in, void *out);
void func_0027DD1C(B18DObj *o, void *m, void *c, f32 d);
void func_0027EB00(B18DObj *o, B18DCam *c);
void func_0027ED40(B18DObj *o, B18DCam *c);
void func_0027E758(B18DObj *o, B18DCam *c);
void func_002A68A0(void *a, B18DObj *o, void *m);

#define DLPUSH(a, b) \
    { \
        DlCmd *dl = D_80110634++; \
        dl->w0 = (a); \
        dl->w1 = (b); \
    }

#define SETUP(o) \
    if (D_801450B8 == 1) { \
        u8 *pp = D_801450A8; \
        func_00272908(pp + 0x220, &(o)->pos, &tv); \
        z = tv.z; \
        if (z < 0.0f) z = -z; \
        func_0027DD1C(o, (u8 *)(o) + ((D_800D297C << 6) + 0x60), pp, z); \
    } else { \
        func_0027DD1C(o, (u8 *)(o) + ((D_800D297C << 6) + 0x60), 0, 0.0f); \
    } \
    (o)->flags |= 0x100000

void func_00282304(B18DWorld *w, B18DCam *cam) {
    B18DObj *o;
    struct { Vec3f min, max; } bb;
    Vec3f tv;
    f32 z;
    s32 vis;
    u32 drawn;
    u32 m10000;

    if (w->head == NULL) return;
    DLPUSH(0xE7000000, 0);
    DLPUSH(0xE3001A01, 0x20);
    func_0026D914(0x80);
    DLPUSH(0xE3000A01, 0);
    DLPUSH(0xD9F9FBFF, 0);
    o = w->head;
    if (o != NULL) {
    m10000 = 0x10000;
    do {
        vis = 0;
        drawn = o->flags & 0x100000;
        if (o->unk14 == 0) {
            if ((o->flags & 0x400000) || o->cfg->unk14 != 0) {
                vis = 1;
            } else {
                f32 s = o->unk158;
                f32 a = o->unk154 * s;
                f32 b = o->unk150 * s;
                f32 e, t, u;
                if (!(b <= a)) a = b;
                e = s;
                if (!(a <= e)) e = a;
                t = e * 1.4142135f;
                u = t * 0.5f;
                bb.min.x = o->pos.x - u;
                bb.max.x = o->pos.x + u;
                bb.min.y = o->pos.y - u;
                bb.max.y = o->pos.y + t;
                bb.min.z = o->pos.z - u;
                bb.max.z = o->pos.z + u;
                if (bb.min.x < cam->f35C && cam->f350 < bb.max.x && bb.min.z < cam->f364 && cam->f358 < bb.max.z &&
                    bb.min.y < cam->f360 && cam->f354 < bb.max.y && func_00297B74(cam->unk2F0, (f32 *)&bb) != 0) {
                    vis = 1;
                }
            }
        }
        if (vis != 0) {
            if (drawn == 0) {
                SETUP(o);
            }
            if (o->cfg->unk14 != 0) {
                func_0027EB00(o, cam);
            } else {
                func_0027ED40(o, cam);
            }
            if (o->cfg->flags & 0x100000) {
                func_0027E758(o, cam);
            }
            if (o->unk1D9 != 0 && drawn == 0) {
                if (!(o->cfg->flags & m10000)) {
                    func_002A68A0(D_8013BA80, o, (u8 *)o + ((D_800D297C << 6) + 0x60));
                }
            }
        } else if (o->unk1D9 != 0 && drawn == 0) {
            SETUP(o);
            if (!(o->cfg->flags & m10000)) {
                func_002A68A0(D_8013BA80, o, (u8 *)o + ((D_800D297C << 6) + 0x60));
            }
        }
        o = o->next;
    } while (o != NULL);
    }
    DLPUSH(0xE7000000, 0);
    DLPUSH(0xE3000A01, 0x100000);
    func_0026D914(0);
    DLPUSH(0xE3001A01, 0x10);
}
