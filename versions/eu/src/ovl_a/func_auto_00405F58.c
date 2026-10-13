#include "common.h"
typedef struct Shared_PakMenuItem {
    u32 unknown0[2];
    u32 flags;
    u32 unknownC[7];
} Shared_PakMenuItem;
typedef struct Shared_ControllerPort {
    u32 unknown0;
    s8 channel;
} Shared_ControllerPort;
struct SharedPlayer;
typedef struct Shared_PakMenu {
    u32 unknown0[3];
    Shared_PakMenuItem *items;
    u32 unknown10[3];
    struct SharedPlayer *player;
    Shared_ControllerPort *owner;
} Shared_PakMenu;

extern s32 D_auto_8015D4CC;
extern s32 D_auto_800EEEE8;
extern s32 D_auto_800EEEE4;
extern u8 D_auto_80152789;
extern u8 D_auto_80152208[];
extern char *D_auto_800E25D4[];
extern char *D_auto_800E25C4[];
extern char *D_auto_800E25A4[];
extern char *D_auto_800E25B4[];

extern s32 func_auto_0040458C(s32 ch, s32 index, s32 *exists, char *name, char *ext, s32 *size,
                              char *company, char *code);
extern s32 func_002A1238(char *);
extern s32 func_002A137C(char *a, char *b);

static inline s32 k7_chk(char *gc, char *cc) { if (func_002A1238(gc) == 4 && func_002A1238(cc) == 2 && func_002A137C(gc, D_auto_800E25D4[D_auto_80152789]) == 0 && func_002A137C(cc, D_auto_800E25C4[D_auto_80152789]) == 0) return 1; return 0; }

void func_auto_00405F58(Shared_PakMenu *menu) {
    s32 ch;
    s32 i;
    s32 other;
    s32 result;
    s32 match;
    char *title;
    char ext[8];
    char company[8];
    char code[8];
    char name[16];
    s32 exists;
    s32 size;
    u8 *lb1;
    u8 *lb2;

    if (D_auto_8015D4CC != 0) {
        ch = D_auto_800EEEE8;
    } else {
        ch = menu->owner->channel;
    }
    for (i = 0; i < 16; i++) {
        result = func_auto_0040458C(ch, i, &exists, name, ext, &size, company, code);
        other = 1;
        if (result == 0 && exists != 0) {
            switch (D_auto_800EEEE4) {
                case 1:
                    match = k7_chk(code, company);
                    lb1 = D_auto_80152208;
                    title = D_auto_800E25A4[lb1[0x581]];
                    break;
                case 2:
                    match = k7_chk(code, company);
                    lb2 = D_auto_80152208;
                    title = D_auto_800E25B4[lb2[0x581]];
                    break;
                case 0:
                default:
                    other = 0;
                    goto done;
            }
            if (func_002A137C(name, title) == 0 && match != 0) {
                other = 0;
            }
        }
    done:
        if (other) {
            menu->items[i + 3].flags &= ~0x1000000;
        } else {
            menu->items[i + 3].flags |= 0x1000000;
        }
    }
}
