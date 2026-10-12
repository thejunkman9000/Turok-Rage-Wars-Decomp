/* PORT override of src/game/func_002231B0.c (player view: turn and tilt from the pad output): unchanged game logic plus native mouse look (port/input.c). */
#include "s702_types.h"

typedef struct B05P10 {
    u8 pad0[0x5D8];
    void *stats;
    u8 pad5DC[0xB0];
    f32 f68C;                   /* +0x688 pad output: +0x4 = the tilt accumulator of func_002631D0 */
    u8 pad690[0x8];
    struct { u8 pad[4]; s8 port; } *ctl;   /* +0x698 controller slot (0x8010F328 + 0x224 * port; port -1 = merged) */
    f32 f69C;
    f32 f6A0;
    u8 pad6A4[0x80];
    f32 f724;
    u8 pad728[0xC4];
    f32 f7EC;
    u8 pad7F0[0x9C4];
    s32 unk11B4;
    u8 pad11B8[0x20];
    f32 f11D8;
} B05P10;

typedef struct B05A10 {
    u8 pad0[0x6C];
    f32 ang;
} B05A10;

typedef struct B05Sta10 {
    u8 pad0[0x79];
    u8 b79;
    u8 b7A;
    s8 b7B;
    u8 pad7C;
    u8 b7D;
} B05Sta10;

typedef struct B05In10 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
} B05In10;

typedef struct B05Hit10 {
    u8 pad0[0x50];
    u32 flags;
} B05Hit10;

B05Hit10 *func_0024E7CC(B05A10 *);
void func_002748E0(void *, f32, f32);
int input_native_active(int port);          /* port/input.c (native host code) */
int port_human_slot(const void *ctl);       /* port/input.c: the port of a real controller slot, -2 for an AI controller */
float input_native_get(int port, int what);
float powf(float, float);

static f32 s_pitch[5];                      /* PORT: mouse-look pitch (degrees, + = up) per controller slot -1..3 */

void func_002231B0(B05P10 *p, B05A10 *a, B05In10 *in) {
    f32 om;
    B05Sta10 *st;
    B05Hit10 *h;
    f32 turn;
    f32 m;
    f32 spd;
    f32 w;
    f32 x;
    f32 e6A0_ = p->f6A0;
    if (!((p->unk11B4 == 0) && (!(p->f11D8 > 0.0f)))) {     /* PORT: dead / cut-scene: the next life starts with a level view */
        s32 sl = port_human_slot(p->ctl);
        if (sl >= -1) s_pitch[sl + 1] = 0.0f;
    }
    if ((p->unk11B4 == 0) && (!(p->f11D8 > 0.0f))) {
        om = p->f7EC * 0.99f;
        st = p->stats;
        m = (((f32) st->b79) * 0.0078125f) - 1.0f;
        turn = (m * 0.5f) + 0.875f;
        m = (((f32) st->b7A) * 0.0078125f) - 1.0f;
        turn = turn * ((1.0f - om) * in->f4);
        spd = (m * 0.4f) + 0.6f;
        spd = spd * (((1.0f - om) * in->f8) * in->fC);
        switch (st->b7B) {
        case 1:
            spd = 0.5f;
            break;
        case 0:
            if (st->b7D == 0) {
                spd = 0.8f;
            }
            break;
        }

        h = func_0024E7CC(a);
        if ((h == ((void *) 0)) || ((h->flags & 0x6000) != 0x2000)) {
            if (in->f0 != 0.0f) {
                func_002748E0(&a->ang, a->ang + ((p->f69C * 8e+01f * in->f0) * 0.017453294f), turn);
            }
        }
        w = (-p->f6A0) * 8e+01f;
        if (w < 0.0f) {
            x = (w * (-0.71619713f)) * in->f10;
        } else {
            x = (w * 0.71619713f) * in->f14;
        }
        func_002748E0(&p->f724, x * 0.017453294f, spd);
        {   /* PORT: native mouse look (port/input.c, native_controls): turn by exactly the mouse motion, tilt the view to an exact angle */
            /* only actors driven by a real controller slot (0x8010F328 + 0x224 * n, n = -1 merged .. 3): bots carry their own AI controller object
               (e.g. 0x8010EEB8, whose port byte reads 0) and must never get the mouse - they were turned by the player's mouse and ended with NaN angles
               (invisible bots, NaN animation-event positions -> INT_MIN damage, the "health 265 then dead" bug) */
            s32 port = port_human_slot(p->ctl);
            if (port >= -1 && input_native_active(port)) {
                /* the game's own speed sliders (options: turn speed b79, look speed b7A, 0..255, centre 128) scale the mouse too:
                   1/8 x at 0, 1 x at the centre, 8 x at the top (x controls.ini mouse_sens_x / _y) */
                f32 dyaw = input_native_get(port, 2) * powf(8.0f, ((f32) st->b79 - 128.0f) / 128.0f);
                f32 dtilt = input_native_get(port, 3) * powf(8.0f, ((f32) st->b7A - 128.0f) / 128.0f);
                f32 t;
                if ((h == ((void *) 0)) || ((h->flags & 0x6000) != 0x2000)) {
                    a->ang = a->ang + dyaw * 0.017453294f;
                }
                /* view tilt x (degrees, + = up: checked on screen) = -f6A0 * 80 * 0.71619713 * (f14 for x >= 0, f10 below).  The game rebuilds f6A0 /
                   f68C from the controller every frame (in the default control style they spring back to the centre), so the mouse keeps its own pitch
                   per player and sets the view to it: an absolute, 1:1 FPS pitch (mouse down = look down) within the game's limits. */
                {
                    f32 up = 8e+01f * 0.71619713f * (in->f14 < 0.0f ? -in->f14 : in->f14);
                    f32 dn = 8e+01f * 0.71619713f * (in->f10 < 0.0f ? -in->f10 : in->f10);
                    f32 *pp = &s_pitch[port + 1];
                    *pp -= dtilt;                                        /* dtilt: + = mouse moved down */
                    if (*pp > up) *pp = up;
                    if (*pp < -dn) *pp = -dn;
                    t = (*pp >= 0.0f) ? up : dn;
                    t = (t > 0.001f) ? -*pp / t : 0.0f;                 /* the matching tilt input, for code that reads it (aiming) */
                    p->f6A0 = t;
                    p->f68C = t;
                    p->f724 = *pp * 0.017453294f;
                }
                { static int lg = -1; extern char *getenv(const char *); extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);   /* TUROK_LOOKLOG=1 */
                  if (lg < 0) lg = getenv("TUROK_LOOKLOG") != 0;
                  if (lg && (dyaw != 0.0f || dtilt != 0.0f)) fprintf(__acrt_iob_func(2), "LOOK p=%p in=%p entry6A0=%.3f yaw=%.3f tilt_in=%.3f f6A0=%.3f f68C=%.3f f724=%.3f in10=%.3f in14=%.3f mode=%d\n", (void *)p, (void *)in, (double)e6A0_, (double)dyaw, (double)dtilt, (double)p->f6A0, (double)p->f68C, (double)p->f724, (double)in->f10, (double)in->f14, (int)((B05Sta10 *)p->stats)->b7B); }
            }
        }
    }
}
