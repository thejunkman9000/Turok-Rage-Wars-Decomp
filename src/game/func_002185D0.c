/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "gfx.h"
#include "span_1000/code_80217388.h"
#include "types.h"
#include "gbi.h"
/* Draws the team selection menu: each listed team icon is placed in the player's viewport, tinted
   with a pulsing shade under the cursor at 0x6C or grey 150 at three quarters alpha otherwise, faded by
   the menu's opening and the options fade D_801462DE and drawn scaled to the viewport and its size,
   and the "Select Team" title is drawn in white centred on the viewport. Adapted from func_80217630_de
   with 0x1C-byte items, the grey tint and the title added, reusing the scale and position variables
   for the title. */

#include "n64sdk.h"











extern u8 D_801462DE;
extern Gfx *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern char D_800C2260_de[]; /* "Select Team" */


extern void func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);
extern void func_802A84F8_de(void);


extern void func_802A8F28_de(char *, s32, s32, s32, s32, s32, f32, f32);

void func_802185D0_de(struct TeamMenu *menu, Item_func_80218F9C_de *items, s32 count, WeaponMenuPlayer *player) {
    s32 width;
    s32 height;
    f32 fade;
    s32 level;
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 alpha;
    s32 red;
    s32 green;
    s32 blue;
    WeaponMenuView *view;
    WeaponMenuView *titleView;
    f32 *viewport;
    Item_func_80218F9C_de *item;

    titleView = player->view;
    level = D_801462DE + 0x40;
    fade = menu->open * (level < 0x100 ? level : 255.0f);
    item = items;
    while (--count != -1) {
        view = player->view;
        scaleX = view->viewport[0] * (1.0f / 320.0f);
        scaleY = view->viewport[1] * (1.0f / 240.0f);
        viewport = view->viewport;
        x = viewport[2] + viewport[0] * 0.5f + item->position.x * 0.5f * viewport[0];
        y = viewport[3] + viewport[1] * 0.5f + item->position.y * 0.5f * viewport[1];
        alpha = item->width;
        if (item->icon != 0) {
            func_802AA950_de(item->icon, 0, &width, &height);
            if (menu->cursor == item->slot) {
                red = func_802B6560_de(menu->spin) * 63.0f + 192.0f;
                alpha = 1.0f;
                green = red;
                blue = red;
            } else {
                red = 150;
                green = red;
                blue = red;
                alpha *= 0.75f;
            }
            gDPSetEnvColor(D_80110634++, red, green, blue, alpha * fade);
            func_802AAC28_de(item->icon, 0, x - width * item->height * scaleX * 0.5f,
                          y - height * item->height * scaleY * 0.5f,
                          scaleX * item->height, scaleY * item->height, 1);
        }
        item++;
    }
    scaleY = titleView->viewport[1] / D_800E28D4;
    scaleX = titleView->viewport[0] / D_800E28D0;
    func_802A84F8_de();
    func_802AAB68_de(0.6f, 0.6f);
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    x = viewport[2] + viewport[0] * 0.5f;
    y = viewport[3] + viewport[1] * 0.5f;
    func_802A8F28_de(D_800C2260_de, x, y, 0xC8, 1, 1, scaleX, scaleY);
}
