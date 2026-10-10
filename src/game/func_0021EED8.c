#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_802A8A94.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "math_helpers.h"
#include "stddef.h"
/* Draws a player's HUD for one frame unless the game state is 8 or 11: ticks the HUD animations,
   draws the health counter and its hurt flash (four corner sprites in an environment colour that
   fades with the flash), the lives or trial counter, the score counter with its animated icon and
   the ticker of fading player names, the second counter (count rule) or the squad score, the
   power-up icon and status sprite, the zoom gauge, the ammo pips for weapon 12, and finally the
   team and squad overlays. */
extern char D_800C25FC_de[];
extern char D_800C93D8_de;
extern char D_800C943C;
extern char D_800C9468;
extern char D_800C94A4_de;
extern f32 D_800C9F64_de[];
extern f32 D_800C9F74_de[];
extern HudStatusShared_Settings D_801462C8;
extern f32 D_800C9190_de[2];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800E28D8;
extern Gfx *D_80110634;
extern char D_8011FE88;
extern char D_8011D8D0;
extern f32 D_801377B0;
extern s32 D_80140FF8;
void func_802183E8_de(void *, Shared_HudView *, Shared_HudPlayer *);
void func_80218F08_de(void *, Shared_HudView *, Shared_HudPlayer *);
void func_80219490_de(void *, Shared_HudView *);
void func_8021E2A0_de(Shared_HudPlayer *, Shared_HudView *);
void func_8021EA54_de(Shared_HudPlayer *, Shared_HudView *);
void func_8022C1E8_de(Shared_HudPlayer *, Shared_HudView *);
void func_8022C37C_de(Shared_HudPlayer *, Shared_HudView *);
void func_80253754_de(s32, s16 **);
s32 func_80283228_de(void *, Shared_HudPlayer *);
s16 **func_8028BEAC_de(void *, s32, s32, s32);
void func_802A6900_de(void *, Shared_HudPlayer *);
void func_802A7AA4_de(void *);
void func_802A822C_de(s32, f32, f32, f32, f32, s32, s32, s32);
void func_802A8F28_de(char *, s32, s32, s32, s32, s32, f32, f32);
void func_802A9234_de(s32);
void func_802AA70C_de(void *, void *);

s32 func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);
s32 func_802BD320_de(char *, const char *, ...);
f32 func_804422F0_de(char *, f32, f32);
static inline HudStatusShared_MatchRules *hudRules(void) {
    return &D_801462C8.rules;
}
void func_8021EEFC_de(Shared_HudPlayer *player, Shared_HudView *view) {
    char text[16];
    f32 sx;
    f32 sy;
    f32 kx;
    f32 ky;
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 flashFade;
    f32 fade;
    f32 flashFade2;
    f32 fade2;
    f32 textScale;
    f32 nameZoom;
    f32 iconFade;
    f32 icon;
    f32 status;
    f32 zoom;
    f32 step;
    f32 stepOut;
    f32 limit;
    s32 n;
    s32 i;
    s32 k;
    s32 ammo;
    s32 j;
    s32 r;
    s32 g;
    s32 b;
    s32 score;
    s32 frames;
    s16 **res;
    s32 indent;
    s32 left;
    s32 top;
    s32 w;
    s32 width;
    s32 level;
    if (D_801462C8.state != 0xB && D_801462C8.state != 8) {
        func_802A7AA4_de(player->anim0);
        func_802A7AA4_de(player->anim1);
        func_802A7AA4_de(player->anim2);
        func_802A7AA4_de(player->anim3);
        func_802A7AA4_de(&player->livesAnim);
        func_802A7AA4_de(player->anim5);
        func_802A7AA4_de(&player->scoreAnim);
        func_802A7AA4_de(&player->countAnim);
        func_802A7AA4_de(&player->squadAnim);
        func_8021E2A0_de(player, view);
        if (view->flags == 0) {
            func_80219490_de(player->effect, view);
        }
        func_802183E8_de(player->strokes, view, player);
        func_80218F08_de(player->trails, view, player);
        func_802A6900_de(player->marks, player);
        func_802A9234_de(D_801462C8.hudFade);
        sx = view->width / (f32) D_800E28D0;
        sy = view->height / (f32) D_800E28D4;
        if (D_800E28D8 == 0) {
            kx = ky = 1.0f;
        } else {
            kx = ky = 1.5f;
        }
        scaleX = sx * kx;
        scaleY = sy * ky;
        if (hudRules()->hideHud == 0) {
            func_8021EA54_de(player, view);
        }
        n = (player->health + 0xFF) >> 8;
        x = player->healthX * scaleX + view->x;
        y = player->healthY * scaleY + view->y + view->height;
        if (hudRules()->hideHud == 0) {
            func_802A822C_de(n, x - scaleX * 3.0f, y - scaleY * 4.0f, scaleX, scaleY, 1, 0, 0);
        }
        n = player->health;
        if (n != player->flashHealth) {
            if (n < player->flashHealth) {
                player->flashAlpha += ((player->flashHealth - n) >> 8) * 5;
                if (n == 0) {
                    player->flashAlpha = 255.0f;
                }
                if (player->flashAlpha < 50.0f) {
                    player->flashAlpha = 50.0f;
                }
                if (player->flashAlpha > 255.0f) {
                    player->flashAlpha = 255.0f;
                }
                player->flashState = 2;
            }
            player->flashHealth = n;
        }
        /* The two flash blocks keep the centre's x in y and its y in x. */
        if (player->hurt > 0.0f) {
            flashFade = player->flashAlpha - 12.0f;
            fade = (flashFade < 0.0f) ? 0.0f : flashFade;
            player->flashAlpha = fade;
            if (player->fxFlags & 0x4000) {
                if (fade != 0.0f) {
                    r = 253.0f - (128.0f - fade * 0.512f);
                    g = 198.0f - fade * 0.792f;
                    b = 34.0f - fade * 0.136f;
                } else {
                    r = 0x7D;
                    g = 0xC6;
                    b = 0x22;
                }
            } else {
                if (fade != 0.0f) {
                    r = fade * 1.012f;
                    g = 105.0f - fade * 0.42f;
                    b = 179.0f - fade * 0.716f;
                } else {
                    r = 0;
                    g = 0x69;
                    b = 0xB3;
                }
            }
            y = view->x + view->width * 0.5f;
            x = view->y + view->height * 0.5f;
            func_802A9234_de(0xFA);
            gDPSetEnvColor(D_80110634++, (r), (g), (b), 250);
            for (k = 0; k < 4; k++) {
                func_802AAC28_de(0x208, k, y + scaleX * D_800C9F64_de[k + 4], x + scaleY * D_800C9F74_de[k + 4], sx,
                              scaleY * 1.5f, 1);
            }
            player->flashState = 0;
        }
        if (player->flashState == 2) {
            flashFade2 = player->flashAlpha - 12.0f;
            fade2 = (flashFade2 < 0.0f) ? 0.0f : flashFade2;
            player->flashAlpha = fade2;
            if (fade2 > 0.0f) {
                y = view->x + view->width * 0.5f;
                x = view->y + view->height * 0.5f;
                r = 253;
                g = 0;
                b = 0;
                gDPSetEnvColor(D_80110634++, (r), (g), (b), (player->flashAlpha));
                for (k = 0; k < 4; k++) {
                    func_802AAC28_de(0x208, k, y + scaleX * D_800C9F64_de[k + 4], x + scaleY * D_800C9F74_de[k + 4], sx,
                                  scaleY * 1.5f, 1);
                }
            } else {
                player->flashState = 0;
            }
        }
        if (D_800E28D8 == 0) {
            kx = ky = 0.75f;
        } else {
            kx = ky = 1.0f;
        }
        scaleX = sx * kx;
        scaleY = sy * ky;
        if (D_801462C8.hudShown == 0) {
            n = player->lives;
            if (player->livesLast != n) {
                func_802AA70C_de(&player->livesAnim, &D_800C93D8_de);
                player->livesLast = n;
            }
            if (player->livesAnim != 0 && player->livesShown != 0) {
                x = player->livesX * sx + view->x;
                y = player->livesY * sy + view->y;
                func_802AAC28_de(0x12C, 0, x + sx * 18.0f, y + sy * 28.0f, sx, sy, 1);
                func_802AAC28_de(0x1F6, 0, x, y, sx, sy, 1);
                func_802A822C_de(player->lives, x + sx * 30.0f, y + sy * 24.0f, sx, sy, 1, 0, 0);
            }
        } else if ((D_801462C8.trialKind == 1 || D_801462C8.trialKind == 4) && player->hideLives == 0) {
            n = player->lifeCount - 1;
            if (n < 0) {
                n = 0;
            }
            x = player->livesX * scaleX + view->x;
            y = player->livesY * scaleY + view->y;
            func_802A9234_de(player->alpha);
            func_802A822C_de(n, x, y + scaleY * 22.0f, scaleX, scaleY, 1, 0, 0);
            func_802AAC28_de(0x1F6, 0, x + scaleX * 20.0f, y + scaleY * 16.0f, scaleX, scaleY * 1.5f, 1);
            if (D_801462C8.rules.markers != 0) {
                func_802AAC28_de(0x203, 0, x + scaleX * 40.0f, y + scaleY * 11.0f, scaleX, scaleY * 1.5f, 1);
            }
        }
        if (hudRules()->hideHud == 0 && D_801462C8.hudShown != 0) {
            if (hudRules()->teams != 0) {
                if (player->owner->team != 0xFF) {
                    score = hudRules()->teamScores[player->owner->team];
                } else {
                    score = 0;
                }
            } else {
                score = player->owner->score;
            }
            if (score < -99) {
                score = -99;
            }
            if (player->scoreLast != score) {
                func_802AA70C_de(&player->scoreAnim, &D_800C943C);
                player->scoreLast = score;
                player->scoreFrame = 0;
            }
            if (player->scoreState == 0) {
                player->scoreState = 1;
            }
            player->scoreAnim = 1;
            player->alpha = 255.0f;
            if (player->scoreAnim != 0 && player->scoreState != 0) {
                frames = 1;
                if (D_801462C8.rules.teams != 0) {
                    res = func_8028BEAC_de(&D_8011FE88, 0x204, 0, 1);
                } else {
                    res = func_8028BEAC_de(&D_8011FE88, 0x1FA, 0, 1);
                }
                if (res != NULL) {
                    frames = (*res != NULL) ? **res : 1;
                    func_80253754_de(0, res);
                }
                x = player->scoreX * scaleX + view->x + view->width;
                y = player->scoreY * scaleY + view->y;
                if (x > 200.0f) {
                    x -= 12.0f;
                }
                func_802A9234_de(player->alpha);
                func_802A822C_de(player->scoreLast, x + scaleX * 48.0f, y + scaleY * 22.0f, scaleX, scaleY, 1, 0, 0);
                if (player->scoreState < 2) {
                    if (hudRules()->markers != 0) {
                        func_802AAC28_de(0x202, 0, x, y + scaleY * 11.0f, scaleX, scaleY * 1.5f, 1);
                    }
                    if (hudRules()->teams != 0) {
                        func_802AAC28_de(0x204, 0, x + scaleX * 8.0f, y + scaleY * 16.0f, scaleX, scaleY * 1.5f, 1);
                    } else {
                        func_802AAC28_de(0x1FA, 0, x + scaleX * 8.0f, y + scaleY * 16.0f, scaleX, scaleY * 1.5f, 1);
                    }
                    player->nameHead = 0;
                    player->nameTail = 0;
                    for (i = 0; i < 8; i++) {
                        player->names[i] = NULL;
                        player->nameFades[i] = 0xFF;
                    }
                } else {
                    if (++player->scoreFrame >= frames * 4) {
                        player->scoreFrame = 0;
                        player->scoreState = 1;
                        player->nameHead = 0;
                        player->nameTail = 0;
                        for (i = 0; i < 8; i++) {
                            player->names[i] = NULL;
                            player->nameFades[i] = 0xFF;
                        }
                    }
                    if (hudRules()->markers != 0) {
                        func_802AAC28_de(0x202, 0, x, y + scaleY * 11.0f, scaleX, scaleY * 1.5f, 1);
                    }
                    if (hudRules()->teams != 0) {
                        func_802AAC28_de(0x204, player->scoreFrame % frames, x + scaleX * 8.0f, y + scaleY * 16.0f,
                                      scaleX, scaleY * 1.5f, 1);
                    } else {
                        func_802AAC28_de(0x1FA, player->scoreFrame % frames, x + scaleX * 8.0f, y + scaleY * 16.0f,
                                      scaleX, scaleY * 1.5f, 1);
                    }
                    func_802A84F8_de();
                    func_802AAB68_de(1.0f, 1.0f);
                    if (D_801462C8.rules.markers == 0) {
                        /* Names scroll right to left, each fading out from 0xFF in steps of 6. */
                        for (i = player->nameHead; i >= player->nameTail; i--) {
                            if (player->names[i] != NULL) {
                                if (D_800E28D8 == 0 && D_80140FF8 == 1) {
                                    nameZoom = 0.75f;
                                    indent = 0xF;
                                } else {
                                    nameZoom = 1.0f;
                                    indent = 0;
                                }
                                scaleX *= nameZoom;
                                func_802BD320_de(text, D_800C25FC_de, player->names[i]->owner->name);
                                func_802AAB3C_de(0, 0, 0, 1, 1, 1);
                                textScale = D_801377B0 * 0.5f * scaleX * func_802AA864_de();
                                scaleY *= nameZoom;
                                w = func_804422F0_de(text, textScale, func_802AA864_de());
                                player->nameWidths[i] = w;
                                width = w;
                                for (j = player->nameHead; i < j; j--) {
                                    width += player->nameWidths[j] + 8;
                                }
                                left = (x - 12.0f) + indent;
                                top = y + 4.0f;
                                func_802A8F28_de(text, left - width + 2, (top + 2) + scaleY * 16.0f,
                                              player->nameFades[i], 0, 0, scaleX * 0.5f, scaleY);
                                if (player->names[i] == player) {
                                    func_802AAB3C_de(0xFF, 0, 0, 1, 1, 1);
                                } else {
                                    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 1, 1, 1);
                                }
                                func_802A8F28_de(text, left - width, top + scaleY * 16.0f, player->nameFades[i], 0, 0,
                                              scaleX * 0.5f, scaleY);
                                player->nameFades[i] -= 6;
                                if (player->nameFades[i] < 0) {
                                    player->nameFades[i] = 0;
                                    player->nameTail = (player->nameTail + 1) % 8;
                                }
                                scaleX /= nameZoom;
                                scaleY /= nameZoom;
                            }
                        }
                    }
                }
            }
            if (hudRules()->countRule != 0) {
                n = player->owner->count;
                if (player->countLast != n) {
                    func_802AA70C_de(&player->countAnim, &D_800C9468);
                    if (player->countLast == -1) {
                        player->countState = 1;
                    }
                    player->countLast = n;
                }
                if (player->countState == 0) {
                    player->countState = 1;
                }
                player->countAnim = 1;
                if (player->countState != 0) {
                    n = 1;
                    res = func_8028BEAC_de(&D_8011FE88, 0x1FD, 0, 1);
                    if (res != NULL) {
                        if (*res != NULL) {
                            n = **res;
                        }
                        func_80253754_de(0, res);
                    }
                    x = player->countX * scaleX + view->x + view->width;
                    y = player->countY * scaleY + view->y;
                    if (x > 200.0f) {
                        x -= 12.0f;
                    }
                    func_802A9234_de(player->alpha);
                    func_802A822C_de(player->owner->count, x + scaleX * 48.0f, y + scaleY * 20.0f, scaleX, scaleY, 1,
                                  0, 0);
                    if (player->countState < 2) {
                        func_802AAC28_de(0x1FD, 0, x + scaleX * 8.0f, y + scaleY * 16.0f, scaleX, scaleY, 1);
                    } else {
                        if (++player->countFrame >= n * 4) {
                            player->countFrame = 0;
                            player->countState = 1;
                        }
                        func_802AAC28_de(0x1FD, player->countFrame % n, x + scaleX * 8.0f, y + scaleY * 16.0f, scaleX,
                                      scaleY, 1);
                    }
                }
            } else if (hudRules()->squads != 0) {
                if (player->owner->team != 0xFF) {
                    score = hudRules()->squadScores[player->owner->team];
                } else {
                    score = 0;
                }
                if (player->squadLast != score) {
                    func_802AA70C_de(&player->squadAnim, &D_800C94A4_de);
                    if (player->squadLast == -1) {
                        player->squadState = 1;
                    }
                    player->squadLast = score;
                }
                if (player->squadState == 0) {
                    player->squadState = 1;
                }
                player->squadAnim = 1;
                if (player->squadState != 0) {
                    frames = 1;
                    res = func_8028BEAC_de(&D_8011FE88, 0x201, 0, 1);
                    if (res != NULL) {
                        if (*res != NULL) {
                            frames = **res;
                        }
                        func_80253754_de(0, res);
                    }
                    x = player->squadX * scaleX + view->x + view->width;
                    y = player->squadY * scaleY + view->y;
                    if (x > 200.0f) {
                        x -= 12.0f;
                    }
                    func_802A9234_de(player->alpha);
                    func_802A822C_de(score, x + scaleX * 48.0f, y + scaleY * 20.0f, scaleX, scaleY, 1, 0, 0);
                    if (player->squadState < 2) {
                        func_802AAC28_de(0x201, 0, x + scaleX * 8.0f, y + scaleY * 16.0f, scaleX, scaleY * 1.5f, 1);
                    } else {
                        if (++player->squadFrame >= frames * 4) {
                            player->squadFrame = 0;
                            player->squadState = 1;
                        }
                        func_802AAC28_de(0x201, player->squadFrame % frames, x + scaleX * 8.0f, y + scaleY * 16.0f,
                                      scaleX, scaleY * 1.5f, 1);
                    }
                }
            }
        }
        if (player->fxFlags & 0x10000) {
            level = player->fxTime;
            if (level != player->iconLast) {
                player->iconState = 2;
                player->iconLast = level;
            }
            if (player->iconState == 2) {
                iconFade = player->fxTime * 5.0f;
                icon = (iconFade > 255.0f) ? 255.0f : iconFade;
                player->iconAlpha = icon;
                if (icon > 0.0f) {
                    x = view->x + view->width * 0.5f;
                    y = view->y + view->height * 0.5f;
                    func_802A9234_de(icon);
                    func_802AAC28_de(0x209, 0, x - scaleX * 31.0f, y - scaleY * 32.0f, scaleX, scaleY, 1);
                } else {
                    player->iconState = 0;
                }
            }
        }
        if ((player->fxFlags != 0 && player->fxFlags < 0x2000) || player->boost > 0.0f) {
            level = player->fxTime;
            if (level != player->statusLast || player->boost > 0.0f) {
                player->statusState = 2;
                player->statusLast = level;
            }
            if (player->statusState == 2) {
                if (player->fxFlags & 0x20) {
                    if (player->fxStage == 2) {
                        status = 255.0f - player->fxTime * 1.7f;
                        if (status < 0.0f) {
                            status = 0.0f;
                        }
                        player->statusAlpha = status;
                    } else if (player->fxStage == 3) {
                        player->statusAlpha = 0.0f;
                    } else {
                        player->statusAlpha = 255.0f;
                    }
                } else if (player->fxTime > 0.0f) {
                    player->statusAlpha = (player->fxTime * 5.0f > 255.0f) ? 255.0f : player->fxTime * 5.0f;
                } else if (player->boost > 0.0f) {
                    player->statusAlpha = 255.0f;
                }
                if (player->statusAlpha > 0.0f) {
                    x = view->x + view->width;
                    y = view->y + view->height;
                    level = 0;
                    if (player->boost > 0.0f) {
                        level = 1;
                    }
                    func_802A9234_de(player->statusAlpha);
                    func_802AAC28_de(0x20C, level, x - scaleX * 70.0f, y - scaleY * 140.0f, scaleX, scaleY, 1);
                } else {
                    /* Clears the icon state, not the status state. */
                    player->iconState = 0;
                }
            }
        }
        zoom = player->zoom;
        if (zoom < 1.0f) {
            step = (1.0f - D_800C9190_de[1]) * 0.25f;
            y = view->y + view->height;
            x = view->x;
            limit = D_800C9190_de[1] + step;
            if (zoom < limit) {
                level = 3;
            } else if (zoom < (limit += step)) {
                level = 2;
            } else if (zoom < limit + step) {
                level = 1;
            } else {
                level = 0;
            }
            func_802A9234_de(0xFF);
            func_802AAC28_de(0x20B, level, x + scaleX * 10.0f, y - scaleY * 140.0f, scaleX, scaleY, 1);
        } else if (zoom > 1.0f) {
            stepOut = (D_800C9190_de[0] - 1.0f) * 0.25f;
            y = view->y + view->height;
            x = view->x;
            if (D_800C9190_de[0] - stepOut < zoom) {
                level = 3;
            } else if (D_800C9190_de[0] - (stepOut + stepOut) < zoom) {
                level = 2;
            } else if (D_800C9190_de[0] - (stepOut + stepOut + stepOut) < zoom) {
                level = 1;
            } else {
                level = 0;
            }
            func_802A9234_de(0xFF);
            func_802AAC28_de(0x20A, level, x + scaleX * 10.0f, y - scaleY * 140.0f, scaleX, scaleY, 1);
        }
        if (player->weapon == 0xC && player->kind != D_800CE47C) {
            ammo = 3 - func_80283228_de(&D_8011D8D0, player);
            if (player->ammo < ammo) {
                ammo = player->ammo;
            }
            x = view->x + view->width * 0.5f;
            y = view->y + view->height * 0.5f;
            for (i = 0; i < 3; i++, ammo--) {
                func_802A9234_de(ammo > 0 ? 0xFF : 0x40);
                func_802AAC28_de(0x2F4, 0, x + D_800CAB78_eu[i] * scaleX, y + scaleY * 64.0f, scaleX, scaleY, 1);
            }
        }
        if (hudRules()->hideHud == 0) {
            if (player->owner->active == 1 && hudRules()->countRule != 0) {
                func_8022C1E8_de(player, view);
            }
            if (hudRules()->hideHud == 0 && hudRules()->squads != 0 && player->owner->active != 0) {
                func_8022C37C_de(player, view);
            }
        }
    }
}
/* Aims a player's view camera and updates the player: with a view at 0x5DC, camera mode 1 at 0x5D0
   looks from the player's eye (the body position plus the eye offset at 0x73C, raised at least 40.96)
   along the body heading with the player's angles and sway and the aim zoom at 0x7EC, and mode 2 orbits the player at the angle
   D_800C9FA0_de and distance D_800CAB88_eu, which input bits 0x200 and 0x100 turn and 0x800 and 0x400 pull
   in and push out; the camera is set through func_80238F24_de and the view refreshed through
   func_80234FEC_de before the player is updated through func_8021D774_de. */
extern void func_80238F24_de(void *, s32, f32, f32, f32, f32, f32, f32, f32, f32, Shared_Quad, s32, f32, f32);
extern void func_80234FEC_de(void *);
extern void func_8021D774_de(Player_func_80220A80_de *);


void func_80220A80_de(Player_func_80220A80_de *player, Body_func_80220A80_de *body) {
    void *view;
    f32 angle;
    f32 x;
    view = player->view;
    if (view != 0) {
        if (player->cameraMode == 1) {
            func_80238F24_de(view, 0, body->heading, player->angles[0] + player->sway[0] - player->pitchBase,
                          player->angles[1] + player->sway[1], player->angles[2] + player->sway[2],
                          body->x + player->eye[0], body->y, body->z + player->eye[2],
                          ((player->eye[1] + player->eyeOffset - player->crouch - player->duck) < (40.96f) ? (40.96f) : (player->eye[1] + player->eyeOffset - player->crouch - player->duck)), body->rotation, body->room, player->zoom,
                          3.0f);
        } else if (player->cameraMode == 2) {
            if (player->input & 0x200) {
                D_800C9FA0_de += 0.06981318f;
            } else if (player->input & 0x100) {
                D_800C9FA0_de -= 0.06981318f;
            } else if (player->input & 0x800) {
                D_800CAB88_eu -= 4.096f;
            } else if (player->input & 0x400) {
                D_800CAB88_eu += 4.096f;
            }
            angle = body->heading + D_800C9FA0_de;
            x = body->x + D_800CAB88_eu * func_802B7130_de(angle);
            func_80238F24_de(view, 1, angle, 0.0f, 0.0f, 0.0f, x, body->y + 81.92f,
                          body->z + D_800CAB88_eu * func_802B6560_de(angle), 0.0f, body->rotation, body->room,
                          0.0f, 3.0f);
        }
        func_80234FEC_de(view);
    }
    func_8021D774_de(player);
}
/* Regenerates a player's health at 0x5E4 toward the cap from func_8022AC00_de: under flag 4 at 0x122C it adds D_800D2988 times gFastRegen's rate and mirrors the result to 0x174 and 0x45C, otherwise, while the flag byte at D_801462E5 is set, the speed at 0x18's 0x24 meets D_800C78B8's threshold, the health is nonzero and the word 0x60F past that flag byte does not hold it back, it adds the speed scaled by D_800C78BC, D_800D2988 and D_800C78C0's rate. */
extern f32 D_800D2988;
extern struct D_800C7470_Pair D_800C27C0_de;
extern struct D_800C7470_Pair D_800C78C0;
extern MultiplayerOptions D_801462E5;
extern s32 func_8022AC00_de(SharedPlayer_func_80220D44_de *p);
void func_80220D44_de(SharedPlayer_func_80220D44_de *p) {
    f32 f0;
    f32 f20;
    f32 cur;
    s32 cap;
    s32 val;
    MultiplayerOptions *regen;
    if ((p->views122C.view122C_1.flags & 4) && p->views5E4.view5E4_2.health > 0) {
        cap = func_8022AC00_de(p);
        f20 = p->views5E4.view5E4_2.health + D_800D2988 * D_800C27C0_de.second;
        f0 = cap;
        if (!(f0 <= f20)) {
            f0 = f20;
        }
        val = f0;
        p->views5E4.view5E4_2.health = val; p->views1C.view174_17.unk174 = val; p->views1C.view45C_31.unk45C = p->views5E4.view5E4_2.health;
        return;
    }
    regen = &D_801462E5;
    f20 = p->views18.view18_3.body->speed;
    if (regen->enabled == 0) return;
    if (f20 < D_800C78B8) return;
    cur = p->views5E4.view5E4_2.health;
    if (cur == 0.0f) return;
    if (p->views5D8.view5D8_4.ctrl->flag != 0 && ((SessionState *)&regen->session)->paused != 0) return;
    f20 = cur + (s32)(f20 * D_800C78BC) * (D_800D2988 * D_800C78C0.first);
    p->views5E4.view5E4_2.health = RW_MIN_LT(f20, func_8022AC00_de(p));
}
