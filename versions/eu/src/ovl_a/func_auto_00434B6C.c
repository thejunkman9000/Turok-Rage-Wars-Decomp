#define VERSION_EU
#include "span_16E000/code_8042F988.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"
#include "common/unused.h"

extern PakState *D_800E54A4;
extern char *D_800D3758;

extern char D_800DDEC0[];

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EE534[], D_800EE540[];
#else
extern char D_800DDEB0_de[];

#endif
extern s32 func_8040458C_de(s32, s32, s32 *, char *, u8 *, s32 *, char *, char *);
extern s32 func_804057BC_de(char *, s32);
extern void func_802A025C_de(char *, char *);
extern void func_802A0C08_de(char *, char *, ...);
extern Label *func_8040EC30_de(void *, s32);
extern s32 func_80405160_de(s32, s32 *);
extern s32 func_80435424_de(void);
extern s32 func_804057EC_de(s32);
extern void func_804322AC_de(s32, s32);
extern void func_80434250_de(s32, s32);

/* Builds a player's controller pak note list: each of the sixteen notes gets its name (a default when unnamed), its size and a numbered label with the extension when it has one, or empty entries once the pak cannot be read; then the free and used page counts are formatted into their menu items, and on any read failure the slot is marked failed instead of opening the note menu. */
#if defined(VERSION_DE)
enum { PAK_RESOURCE_2D7 = 750, PAK_RESOURCE_2D8 = 749, PAK_RESOURCE_2DB = 746, PAK_RESOURCE_2DC = 745, PAK_RESOURCE_2DD = 747 };
#elif defined(VERSION_EU)

extern u8 D_801462C8[];

extern char *D_800E27B4[], *D_800E1394[];
enum { PAK_RESOURCE_2D7 = 727, PAK_RESOURCE_2D8 = 728, PAK_RESOURCE_2DB = 731, PAK_RESOURCE_2DC = 732, PAK_RESOURCE_2DD = 733 };
#elif defined(VERSION_EU_X)

extern u8 D_801462C8[];

extern char *D_800DE03C[], *D_800DD124[];

enum { PAK_RESOURCE_2D7 = 753, PAK_RESOURCE_2D8 = 751, PAK_RESOURCE_2DB = 754, PAK_RESOURCE_2DC = 755, PAK_RESOURCE_2DD = 756 };
#else
enum { PAK_RESOURCE_2D7 = 727, PAK_RESOURCE_2D8 = 728, PAK_RESOURCE_2DB = 731, PAK_RESOURCE_2DC = 732, PAK_RESOURCE_2DD = 733 };
#endif

#if !defined(VERSION_EU) && !defined(VERSION_EU_X)
static const char controller_pak_note_label_format[] = "%d.%s.%s";
#endif

void func_auto_00434B6C(s32 player)
{
    char name[0x18];
    u8 ext[8];
    char extra1[8];
    char extra2[8];
    s32 status;
    s32 size;
    s32 failed;
    s32 i;
    Label *item;
    s32 note_status;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    GameLocalizationState *settings;

#else
#endif
    failed = 0;
    for (i = 0; i < 16 && failed == 0; i++) {
        note_status = func_8040458C_de(player, i, &status, name, ext, &size, extra1, extra2);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        settings = (GameLocalizationState *)D_801462C8;

#else
#endif
        if (note_status == 0) {
            if (status == 1) {
                if (func_804057BC_de(name, 16) == 1) {
#if defined(VERSION_EU)
                    func_802A025C_de(name, ((D_800E27B4)[settings->language]));
#elif defined(VERSION_EU_X)
                    func_802A025C_de(name, ((D_800DE03C)[settings->language]));
#else
                    func_802A025C_de(name, (D_800D3758));
#endif
                }
                func_802A025C_de(D_800E54A4->slots[player].notes[i].name, name);
                func_802A0C08_de(D_800E54A4->slots[player].notes[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
D_800DDEB0_de,
#endif
 size);
                if (ext[0] != 0) {
                    func_802A0C08_de(D_800E54A4->slots[player].notes[i].label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800EE534,
#else
controller_pak_note_label_format,
#endif
 i + 1,
                                  D_800E54A4->slots[player].notes[i].name, ext);
                    continue;
                }
                goto numbered;
            }
        } else {
            failed = 1;
        }
#if defined(VERSION_EU)
        func_802A025C_de(D_800E54A4->slots[player].notes[i].name, ((D_800E1394)[settings->language]));
#elif defined(VERSION_EU_X)
        func_802A025C_de(D_800E54A4->slots[player].notes[i].name, ((D_800DD124)[settings->language]));
#else
        func_802A025C_de(D_800E54A4->slots[player].notes[i].name, ((char *)D_800D3250[0]));
#endif
        func_802A0C08_de(D_800E54A4->slots[player].notes[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
D_800DDEB0_de,
#endif
 0);
    numbered:
        func_802A0C08_de(D_800E54A4->slots[player].notes[i].label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800EE540,
#else
D_800DDEC0,
#endif
 i + 1,
                      D_800E54A4->slots[player].notes[i].name);
    }
    if (failed == 0) {
        item = func_8040EC30_de(D_800E54A4->slots[player].menu, PAK_RESOURCE_2D8);
        if (func_80405160_de(player, &size) == 0) {
            func_802A0C08_de(D_800E54A4->slots[player].free,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
D_800DDEB0_de,
#endif
 size);
            item->text = D_800E54A4->slots[player].free;
            item = func_8040EC30_de(D_800E54A4->slots[player].menu, PAK_RESOURCE_2D7);
            size = func_80435424_de();
            func_802A0C08_de(D_800E54A4->slots[player].used,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
D_800DDEB0_de,
#endif
 func_804057EC_de(size));
            item->text = D_800E54A4->slots[player].used;
        } else {
            failed = 1;
        }
    }
    if (failed == 1) {
        D_800E54A4->slots[player].state = failed;
        func_804322AC_de(player, PAK_RESOURCE_2DB);
        return;
    }
    D_800E54A4->slots[player].cursor = -1;
    D_800E54A4->slots[player].scroll = 0;
    D_800E54A4->slots[player].items[0] = func_8040EC30_de(D_800E54A4->slots[player].menu, PAK_RESOURCE_2DB);
    D_800E54A4->slots[player].items[1] = func_8040EC30_de(D_800E54A4->slots[player].menu, PAK_RESOURCE_2DC);
    D_800E54A4->slots[player].items[2] = func_8040EC30_de(D_800E54A4->slots[player].menu, PAK_RESOURCE_2DD);
    func_80434250_de(player, 1);
}
