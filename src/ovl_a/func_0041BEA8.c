/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "span_16E000/code_8041BEA8.h"
#include "span_1000/code_802A208C.h"
#include "span_16E000/code_80405DC0.h"
#include "span_16E000/code_8042F988.h"
#include "span_16E000/code_80434F4C.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
#include "common/unused.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;

#else
#endif
/* Calls func_8040E928_de with flag 1 on each of the list's items (count at 0x48, items from 0x4C) and
   returns 0. */

extern void func_8040E928_de(void *, int);

int func_8041BE28_de(List_func_8041BE28_de *list) {
    int i;

    for (i = 0; i < list->count; i++) {
        func_8040E928_de(list->items[i], 1);
    }
    return 0;
}
/* Updates the slot-selection dialog after availability and capacity probes, choosing unavailable, empty and confirmation states or entering the requested transition. The negative probe statuses -4, -3 and -1 trigger the error transition. */

#if defined(VERSION_DE)
enum { SLOT_RESOURCE_962 = 956, SLOT_RESOURCE_966 = 961, SLOT_RESOURCE_968 = 960, SLOT_RESOURCE_971 = 964 };
#elif defined(VERSION_EU)
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

extern s32 D_800E25A4[];

#elif defined(VERSION_EU_X)
enum { SLOT_RESOURCE_962 = 967, SLOT_RESOURCE_966 = 969, SLOT_RESOURCE_968 = 971, SLOT_RESOURCE_971 = 975 };

extern s32 D_800E25A4[];

#else
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

#endif
extern s32 func_80264614_de(s32);
extern void func_80298368_de(s32);
extern void func_802991D4_de(s32);
extern void func_8029973C_de(void);
extern void func_802A2360_de(void);
extern s32 func_802A0C08_de(void *, const char *, ...);
extern s32 func_80404BE8_de(s32, s32, s32 *);
extern s32 func_80404F04_de(s32);
extern s32 func_80435384_de(s32,u32 *);
extern void func_80404E28_de(s32);
extern void func_8040E8D8_de(s32,s32);

extern void func_8041C244_de(void);
extern void func_80434FB4_de(s32);
extern Label *func_8040EC30_de(s32,s32);
extern s32 D_800D36D4, D_800E28CC, D_800DF4C0,D_8010F190,D_80146D60,D_8014AD94;

#if defined(VERSION_DE)
extern char D_800DD450[];

extern s32 D_800DF4C4;
#elif defined(VERSION_EU)
extern char D_800EDAD0[];
extern s32 D_800EFB34;
#elif defined(VERSION_EU_X)
extern char D_800EDAD0[];
extern s32 D_800EACF4;

#elif defined(VERSION_US)
extern char D_800DD450[];

extern s32 D_800DE174;
#else
extern char D_800DD450[];
extern s32 D_800E3514;

#endif
extern SlotDialog *D_800E3518;
void func_8041BE90_de(void) {
    s32 sp10;
    u32 sp14;
    s32 var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    Label *temp_s0;

    func_802991D4_de(SLOT_RESOURCE_962);
    func_8040E8D8_de(D_800E3518->absent, 0);
    var_s2 = 0;
    func_8040E8D8_de(D_800E3518->unavailable, 0);
    var_s1 = 1;
    func_8040E8D8_de(D_800E3518->prompt, 0);
    temp_v0 = func_80264614_de(0);
    if (temp_v0 == 1) {
        func_8041C19C_de();
        if (D_800E3518->ready == 1) {
            func_80404E28_de(D_800DF4C0);
            temp_v0_2 = func_80404F04_de(D_800DF4C0);
            switch (temp_v0_2) { /* irregular */
            case 0:
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                if ((func_80404BE8_de(((D_800E25A4)[D_80152789]), D_800DF4C0, &sp10) == 0) && (func_80435384_de(D_800DF4C0, &sp14) == 0)) {
#else
                if ((func_80404BE8_de((D_800D36D4), D_800DF4C0, &sp10) == 0) && (func_80435384_de(D_800DF4C0, &sp14) == 0)) {
#endif
                    var_s1 = sp14 > 0U;
                }
                break;
            case -4:
            case -3:
            case -1:
                var_s2 = 1;
                break;
            }
        }
    }
    if (temp_v0 == 0) {
        D_800E3518->state = 1;
        D_800E3518->elapsed = 0;
        func_8040E8D8_de(D_800E3518->main, 0);
        func_8040E8D8_de(D_800E3518->unavailable, 1);
        goto block_25;
    }
    if (D_800E3518->ready == 0) {
        D_800E3518->state = 2;
        D_800E3518->elapsed = 0;
        func_8040E8D8_de(D_800E3518->main, 0);
        func_8040E8D8_de(D_800E3518->absent, 1);
        var_a0 = SLOT_RESOURCE_971;
        goto block_24;
    }
    if ((var_s2 == 1) || (D_8010F190 & 0x1000)) {
        func_8029973C_de();
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        if (var_s2 == 0) {
#if defined(VERSION_DE)
            D_800DF4C4 = 0;
#elif defined(VERSION_EU)
            D_800EFB34 = 0;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 0;
#elif defined(VERSION_US)
            D_800DE174 = 0;
#else
            D_800E3514 = 0;
#endif
        } else {
#if defined(VERSION_DE)
            D_800DF4C4 = 2;
#elif defined(VERSION_EU)
            D_800EFB34 = 2;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 2;
#elif defined(VERSION_US)
            D_800DE174 = 2;
#else
            D_800E3514 = 2;
#endif
        }
        func_80434FB4_de(6);
        func_80298368_de(0x13);
        return;
    }
    if (var_s1 == 1) {
        func_8041C244_de();
        return;
    }
    temp_s0 = func_8040EC30_de(D_800E3518->root, SLOT_RESOURCE_968);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_802A0C08_de(D_800E3518->text, D_800EDAD0, D_800DF4C0 + 1);
#else
    func_802A0C08_de(D_800E3518->text, D_800DD450, D_800DF4C0 + 1);
#endif
    temp_s0->text = D_800E3518->text;
    D_800E3518->state = 3;
    D_800E3518->elapsed = 0;
    func_8040E8D8_de(D_800E3518->main, 0);
    func_8040E8D8_de(D_800E3518->prompt, 1);
    var_a0 = SLOT_RESOURCE_966;
block_24:
    func_802991D4_de(var_a0);
block_25:
    func_802A2360_de();
}

/* Calls func_802A2394_de and func_8029973C_de, then func_80298368_de with 2, sets D_8014ADA0 and returns
   one. */
extern s32 D_8014ADA0;
extern void func_802A2394_de();
extern void func_8029973C_de();
extern void func_80298368_de(s32);

s32 func_8041C164_de(void) {
    func_802A2394_de();
    func_8029973C_de();
    func_80298368_de(2);
    D_8014ADA0 = 1;
    return 1;
}
