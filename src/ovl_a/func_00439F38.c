#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Handles the menu message func_80299A08_de reports after func_8029973C_de: 0x3DA waits through
   func_80298368_de for a time chosen by setting D_801462D5 through jtbl_800DDF70 (20, 15 or 10, and
   3 for any other setting); 0x3DB sends code -1 to func_8042E988_de and calls func_802998A8_de.
   Returns zero. */
extern u8 D_801462D5;
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_80298368_de(s32);
extern void func_8042E988_de(s32);
extern void func_802998A8_de(void);

#if defined(VERSION_DE)
enum { MENU_80439F38_986 = 980, MENU_80439F38_987 = 981 };
#elif defined(VERSION_EU_X)
enum { MENU_80439F38_986 = 990, MENU_80439F38_987 = 991 };
#else
enum { MENU_80439F38_986 = 986, MENU_80439F38_987 = 987 };
#endif

s32 func_80439D58_de(void) {
    /* FAKEMATCH: preserve resident jump-table labels and recovered dispatch schedule. */
    s32 time;
    u32 setting;

    func_8029973C_de();
    switch (func_80299A08_de()) {
    case MENU_80439F38_986:
        setting = D_801462D5;
        if (setting >= 5) {
            goto wait_3;
        }
        switch (setting) {
        case 0: goto wait_20;
        case 1: goto wait_3;
        case 2: goto wait_15;
        case 3: goto wait_10;
        case 4: goto wait_10;
        }
    wait_20:
        time = 20;
        goto wait;
    wait_15:
        time = 15;
        goto wait;
    wait_10:
        time = 10;
        goto wait;
    wait_3:
        time = 3;
    wait:
        func_80298368_de(time);
        return 0;
    case MENU_80439F38_987:
        func_8042E988_de(-1);
        func_802998A8_de();
        return 0;
    }
    return 0;
}

/* Calls func_8029973C_de, then func_8042E988_de with -1, then func_802998A8_de, and returns zero. */
extern void func_8029973C_de();
extern void func_8042E988_de(s32);
extern void func_802998A8_de();

s32 func_80439E04_de(void) {
    func_8029973C_de();
    func_8042E988_de(-1);
    func_802998A8_de();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E59B0, an actor kind at D_800E59B4 and a handler at D_800E59B8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8043A014)(void *, s32, s32, s32, s32);


extern FieldRow D_800E59B0[];
extern FieldRow D_800E59B4[];
extern Handler8043A014 D_800E59B8;




s32 func_80439E34_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E59B8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E59B8;
        index = 0;
        do {
            if (D_800E59B0[index].value == arg1) {
                actor_kind = ((func_8021C9B4_S3 *)(arg0))->unkC;
                table_kind = D_800E59B4[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler8043A014 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            index++;
        } while (*(Handler8043A014 *)entry != 0);
    }
    return 0;
}
