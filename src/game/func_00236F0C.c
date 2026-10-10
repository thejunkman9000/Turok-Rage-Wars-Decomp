#include "abi.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80233920.h"
#include "span_1000/code_8026AC38.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "video_dimensions.h"
#include "gfx.h"
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800D297C;
extern s32 D_80146894;
extern f32 D_800FF224_de;
extern f32 D_800D2988;
extern World_func_80236F1C_de D_80145040;
extern char D_800CBCC0;
extern char D_800CBCF0_de;
extern void func_80253BBC_de(s32, s32);
extern void func_80235AE0_de(Racer *);
extern void func_802362E8_de(Racer *, s32);
extern void func_80239FD4_de(Racer *, s32);
extern void func_80233C88_de(Racer *);
extern void func_80238314_de(Race *, Racer *);
extern void func_804429D4_de(void *);
extern void func_802372D4_de(Racer *);
extern s32 func_80245784_de(void);
extern s32 func_80245798_de(void);
extern void func_8022A3F8_de(World_func_80236F1C_de *, Racer *);
/* Per-frame race update: clears three per-frame flags of the race's own racer, passes the race's first word to func_80253BBC_de, runs the 30-frame flash timer (restarted while D_80146894 is set or in mode 3) and while it runs clears the screen with a full-screen viewport, scissor and fill before func_8026D8F8_de, then updates every racer in the list until it ends or func_80245784_de or func_80245798_de reports, updates the race's own racer, hands the list to func_8022A3F8_de when the replay flag of D_80145040 is set, and passes the own racer's block at 0x554 to func_804429D4_de. */
void func_00236F0C(Race *race, s32 arg1)
{
    Racer *racer;
    race->self.hit = 0;
    race->self.boost = 0;
    race->self.spin = 0;
    if (race->music != 0) {
        func_80253BBC_de(0, race->music);
    }
    if (D_80146894 != 0 || race->mode == 3) {
        D_800FF224_de = 30.0f;
    }
    if (D_800FF224_de != 0.0f) {
        D_800FF224_de -= D_800D2988;
    }
    if (D_800FF224_de < 0.0f) {
        D_800FF224_de = 0.0f;
    }
    if (D_800FF224_de != 0.0f) {
        racer = race->racers;
        if (racer != 0) {
            gDPPipeSync(D_80110634++);
            gSPDisplayList(D_80110634++, ((&D_800CBCC0)));
            gSPDisplayList(D_80110634++, ((&D_800CBCF0_de)));
            racer->viewports[D_800D297C].vscale[0] = SCREEN_WD;
            racer->viewports[D_800D297C].vscale[1] = SCREEN_HT;
            racer->viewports[D_800D297C].vtrans[0] = SCREEN_WD;
            racer->viewports[D_800D297C].vtrans[1] = SCREEN_HT;
            gSPMoveMem(D_80110634++, G_MV_VIEWPORT, 0, 16, ((&racer->viewports[D_800D297C])));
            gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, (int)((float)((0)) * 4.0F), (int)((float)((0)) * 4.0F), (int)((float)((SCREEN_WD - 1)) * 4.0F), (int)((float)((SCREEN_HT - 1)) * 4.0F));
            gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((D_8011BDC0->colorImage)));
            gDPSetCycleType(D_80110634++, G_CYC_FILL);
            gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
            gDPSetRenderMode(D_80110634++, ((0)), 0);
            gDPSetFillColor(D_80110634++, ((0x10001)));
            gDPFillRectangle(D_80110634++, 0, 0, (SCREEN_WD), (SCREEN_HT));
            func_8026D8F8_de();
        }
    }
    for (racer = race->racers; racer != 0;) {
        func_80235AE0_de(racer);
        func_802362E8_de(racer, arg1);
        if (racer->effect != 0) {
            func_80239FD4_de(racer, racer->effectArg);
        }
        func_80233C88_de(racer);
        func_80238314_de(race, racer);
        func_804429D4_de(racer->sound);
        func_802372D4_de(racer);
        if (func_80245784_de() != 0 || func_80245798_de() != 0) {
            racer = 0;
        } else {
            racer = racer->next;
        }
    }
    func_80235AE0_de(&race->self);
    if (race->mode == 0) {
        func_80233C88_de(&race->self);
    }
    func_80238314_de(race, &race->self);
    if (D_80145040.replay != 0) {
        racer = race->racers;
        if (racer != 0) {
            func_8022A3F8_de(&D_80145040, racer);
        }
    }
    func_804429D4_de(race->self.sound);
}

extern Gfx *D_80110634;
extern void func_8026D8F8_de(void);

void func_002372C4(Racer *racer) {
    Entity_func_80233C88_de *entity = (Entity_func_80233C88_de *)racer;
    f32 x;
    f32 y;
    f32 width;
    f32 height;

    func_8026D8F8_de();
    x = entity->x;
    y = entity->y;
    width = entity->width;
    height = entity->height;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                     0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, 0);
    gDPFillRectangle(D_80110634++, x, y, (x + width) - 1.0f, y + 2.0f);
    gDPFillRectangle(D_80110634++, x, (y + height) - 2.0f,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, x, y, x + 2.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, (x + width) - 2.0f, y,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE,
                     0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(D_80110634++, (1 << 16) | 1);
    gDPFillRectangle(D_80110634++, x, y, (x + width) - 1.0f, y);
    gDPFillRectangle(D_80110634++, x, (y + height) - 1.0f,
                    (x + width) - 1.0f, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, x, y, x, (y + height) - 1.0f);
    gDPFillRectangle(D_80110634++, (x + width) - 1.0f, y,
                    x + width, (y + height) - 1.0f);
}

/* Posts a text as on-screen messages, one per line: when func_80245784_de reports it, the messages already in
 * the pool's list at 0xE40 are flagged kind 4 and the new ones get kind 1, otherwise kind 2; the text (or
 * D_800D7028 when given D_800D7034) is split at newlines and for each non-empty line the oldest message node
 * of the owner's list at 0xF24 is recycled and set up centred horizontally 80 pixels above the bottom of the
 * screen at unit size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;

extern s32 D_800E28D0;
extern void func_80239CE0_de(Message *);
extern void func_80255ED8_de(void *, Message *);
extern void func_80255D14_de(void *, Message *);
extern s32 func_80245784_de(void);












static inline Message *recycle(void *owner, void *pool) {
    Message *oldest;

    oldest = ((func_80237E70_S1 *)(owner))->unkF24.v0;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&((func_80237E70_S1 *)(owner))->unkF24.v1, oldest);
        func_80255D14_de(&((func_80237E70_S2 *)(pool))->unkE40.v0, oldest);
    }
    return oldest;
}

static inline Message *post_lines(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target) {
    Message *message;
    s32 height;
    u8 *line;
    u8 *p;

    message = 0;
    if (pool == 0) {
        return message;
    }
    if (text == D_800D7034.unk0) {
        text = D_800D7028.unk0;
    }
    p = text;
    line = p;
    while (*p != 0) {
        p++;
        if (*p == '\n' || *p == 0) {
            if (line != p) {
                message = recycle(owner, pool);
                if (message != 0) {
                    message->kind = kind;
                    message->text = line;
                    message->timer = 0;
                    message->alpha = 1.0f;
                    message->size = size * 15.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->pad28 = 0;
                    message->pad2C = 0;
                    message->scaleX = 1.0f;
                    message->scaleY = 1.0f;
                    height = (&D_800E28D0)[1]; /* FAKEMATCH */
                    message->x = D_800E28D0 / 2;
                    message->y = height - 80;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

Message *func_00237E70(void *owner, void *pool, u8 *text) {
    Message *pending;
    s32 kind;

    kind = 2;
    if (pool == 0) {
        return 0;
    }
    if (func_80245784_de() != 0) {
        pending = ((func_80237E70_S2 *)(pool))->unkE40.v1;
        if (pending != 0) {
            kind = 1;
            do {
                pending->kind = 4;
                pending = ((func_80237E70_S4 *)(pending))->unk4;
            } while (pending != 0);
        }
    }
    return post_lines(owner, pool, text, kind, 1.0f, -1);
}
