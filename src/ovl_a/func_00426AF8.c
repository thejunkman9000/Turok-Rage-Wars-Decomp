#include "span_16E000/code_804264F0.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8044ACCC.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"
#include "math_helpers.h"

extern struct Screen_func_80426918_de *D_800E4690;
extern s32 D_80154020[];

extern void func_8029973C_de(void);
extern void func_80298368_de(s32);
extern void func_8025DF34_de(s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_80419F58_de(void *, s32);
extern void func_802A2360_de(void);
extern s32 func_80419F38_de(void *);
extern void func_80419F24_de(void *);

extern void func_8042E988_de(s32);



s32 func_80426918_de(void *arg0, void *arg1, s32 delta) {
    s32 clock;

    if (D_80154020[1] == 1) {
        D_80154020[1] = 0;
        if (D_80154020[0] != -1) {
            D_800E4690->banner->alpha = 0x5A;
            func_8029973C_de();
            func_80298368_de(D_80154020[0]);
            return 0;
        }
        D_800E4690->banner->alpha = 0xFF;
        D_800E4690->state = 9;
    }
    switch (D_800E4690->state) {
    case 1:
        D_800E4690->left->x += D_800E4690->leftSpeed;
        D_800E4690->right->x -= D_800E4690->rightSpeed;
        if (--D_800E4690->timer > 0) {
            break;
        }
        func_8025DF34_de(0xE79);
        func_8040E8D8_de(D_800E4690->button, 1);
        func_80419F58_de(D_800E4690->prompt, 4);
        D_800E4690->state = 4;
        D_800E4690->timer = 4;
        break;
    case 2:
        D_800E4690->left->x -= D_800E4690->leftSpeed;
        D_800E4690->right->x += D_800E4690->rightSpeed;
        if (--D_800E4690->timer > 0) {
            break;
        }
        D_800E4690->state = 3;
        func_8029973C_de();
        if (D_801462D5 == 4) {
            func_80298368_de(3);
        } else {
            func_80298368_de(7);
        }
        return 0;
    case 3:
        if (D_800E4690->requested == 0) {
            func_802A2360_de();
            D_800E4690->requested = 1;
        }
        break;
    case 4:
        D_800E4690->timer = RW_CLAMP(D_800E4690->timer - 1, 0, D_800E4690->timer);
        if (D_800E4690->timer <= 0 && func_80419F38_de(D_800E4690->prompt) != 0) {
            func_80419F24_de(D_800E4690->prompt);
            D_800E4690->state = 3;
        }
        break;
    case 5:
        func_8025DF34_de(0xE78);
        func_8040E8D8_de(D_800E4690->button, 0);
        switch (D_801462D5) {
        case 1:
        case 3:
        case 4:
            func_804281A8_de();
        }
        func_804273D4_de();
        D_800E4690->state = 2;
        D_800E4690->timer = 4;
        break;
    case 8:
        D_800E4690->state = 3;
        func_804273D4_de();
        func_8042E988_de(0xB);
        return 0;
    case 9:
        D_800E4690->state = 3;
        func_80427008_de();
        break;
    }
    if (D_800E4690->state == 3) {
        clock = D_800E4690->clock + delta;
        D_800E4690->clock = clock;
        if (D_80154020[0] == -1) {
            D_800E4690->pulse->alpha = (u32)(func_802B6560_de(clock * 0.005f) * 100.0f + 150.0f);
        }
    }
    return 0;
}
