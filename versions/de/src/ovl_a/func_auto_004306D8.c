#include "span_16E000/code_8042F988.h"
#include "span_1000/code_8022E938.h"
#include "span_16E000/code_80434F4C.h"
#include "span_1000/code_802A0888.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80405DC0.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Steps player arg2's menu state machine at 0x58 of its 0xB68-byte record in the block D_800E54A4 points to
   on the event func_8041B810_de reports: each state accepts its events, moves to the next state (by the game
   mode at 0x54 where it matters), updates the player's name records, and refreshes the player through
   func_804322AC_de. Returns zero. */
extern PakMenuController *D_800E54A4;
extern u8 D_80102B00[];
extern u8 D_80146398[];

extern void func_8029973C_de(void);
extern s32 func_8041B810_de(s32, s32);
extern void func_8041B7B4_de(s32, s32, s32);
extern void func_804322AC_de(s32);
extern void func_80434D70_de(s32);
extern s32 func_80435384_de(s32, s32 *);
extern s32 func_80434428_de(s32);
extern s32 func_80435128_de(s32);
extern void func_8043599C_de(s32, s32, s32);
extern void func_804356BC_de(s32);
extern void func_8043577C_de(s32);
extern void *func_8040EC30_de(s32, s32);
extern void func_8040E8D8_de(void *, s32);

extern s32 func_80404858_de(s32, s32);

extern s32 func_804358C0_de(s32, s32);
extern void func_8022EF30_de(void *);
extern void func_80404E28_de(s32);
extern void func_80433610_de(s32);
extern void func_802A0724_de(void *, void *, s32);
extern void func_80433BCC_de(s32);


extern s32 func_80405290_de(s32);

s32 func_auto_004306D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 answer;
    s32 i;
    s32 j;
    s32 p;
    s32 event;
    s32 slot;
    s32 other;
    s32 q;
    s32 found;
    u8 *node;
    u8 *next;
    u8 *settings;
    u8 c;
    s32 sub;
    s32 mode;

    func_8029973C_de();
    i = 0;
    p = arg2 & 0xFFFF;
    event = func_8041B810_de(D_800E54A4->root, p);
    switch (D_800E54A4->players[p].state) {
    case 1:
        switch (event) {
        case 0x2D0:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            func_804322AC_de(p);
            break;
        case 0x2D1:
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                func_804322AC_de(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    func_80434D70_de(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                func_804322AC_de(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 1;
                func_804322AC_de(p);
                break;
            }
            break;
        }
        break;
    case 3:
        switch (event) {
        case 0x2D8:
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                func_804322AC_de(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 1;
                func_804322AC_de(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    func_80434D70_de(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                func_804322AC_de(p);
                break;
            }
            break;
        case 0x2D7:
            D_800E54A4->players[p].state = 0x1C;
            func_804322AC_de(p);
            break;
        case 0x2D6:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            func_804322AC_de(p);
            break;
        }
        break;
    case 15:
        switch (event) {
        case 0x2C4:
            if (func_80435384_de(p, &answer) == 0) {
                if (answer == 1) {
                    D_800E54A4->players[p].state = 0xC;
                } else {
                    D_800E54A4->players[p].state = 0xB;
                }
            } else {
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
            }
            func_804322AC_de(p);
            break;
        case 0x2C5:
            if (D_800E54A4->phase == 7) {
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0xF;
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            func_804322AC_de(p);
            break;
        }
        break;
    case 16:
        switch (event) {
        case 0x2B6:
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].owner = (u8) D_800E54A4->players[p].record;
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].player = p;
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].time = D_800E54A4->players[p].profile;
            if (D_800E54A4->phase == 7) {
                settings = D_80146398;
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[0] = settings[0x7B];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[1] = settings[0x7D];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[2] = settings[0x79];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[3] = settings[0x7A];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[4] = settings[0x82];
            }
            if (func_80434428_de(p) == 1) {
                switch (D_800E54A4->phase) {
                case 0:
                    if (func_80435128_de(p) >= 0) {
                        D_800E54A4->players[p].state = 0x17;
                    } else {
                        D_800E54A4->players[p].state = 0xE;
                    }
                    break;
                case 7:
                    func_8043599C_de(p, 0, 0);
                    func_804356BC_de(0);
                    func_8029973C_de();
                    func_8043577C_de(9);
                    return 0;
                default:
                    D_800E54A4->players[p].state = 0xD;
                    break;
                }
                func_804322AC_de(p);
            }
            break;
        case 0x2B5:
            switch (D_800E54A4->phase) {
            case 0:
                D_800E54A4->players[p].state = 0x17;
                break;
            case 1:
                D_800E54A4->players[p].state = 0x17;
                break;
            case 7:
                D_800E54A4->players[p].state = 0x17;
                break;
            default:
                D_800E54A4->players[p].state = 0xD;
                break;
            }
            func_804322AC_de(p);
            break;
        }
        break;
    case 12:
        slot = func_80435128_de(p);
        if (slot >= 0) {
            node = func_8040EC30_de(D_800E54A4->players[p].menu, 0x2DA);
            for (j = 0; ((Shared_Item *) node)->flags & 0x10; j++) {
                D_800E54A4->players[p].records[slot].name[j] = *(u8 *) ((Shared_Item *) node)->label->unk38;
                next = (u8 *) ((Shared_Item *) node)->next;
                if (next == 0) {
                    break;
                }
                node = next;
            }
            for (j = 6; j > 0; j--) {
                c = D_800E54A4->players[p].records[slot].name[j];
                if (c != 0 && c != ' ') {
                    break;
                }
                D_800E54A4->players[p].records[slot].name[j] = 0;
            }
            D_800E54A4->players[p].state = 0x10;
            D_800E54A4->players[p].record = slot;
        } else {
            D_800E54A4->players[p].state = 3;
        }
        func_804322AC_de(p);
        break;
    case 11:
        switch (event) {
        case 0x2D3:
            D_800E54A4->players[p].state = 4;
            func_804322AC_de(p);
            break;
        case 0x2D4:
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
                D_800E54A4->players[p].state = 0xE;
                func_804322AC_de(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    func_80434D70_de(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                func_804322AC_de(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0xB;
                func_804322AC_de(p);
                break;
            }
            break;
        }
        break;
    case 4:
        switch (event) {
        case 0x2E8:
            switch (D_800E54A4->phase) {
            case 0:
                D_800E54A4->players[p].state = 0xF;
                break;
            case 2:
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                break;
            case 7:
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                break;
            case 1:
            case 4:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                break;
            }
            func_804322AC_de(p);
            break;
        case 0x2E7:
            i = D_800E54A4->players[p].slot;
            if (func_802A05D0_de(D_800E54A4->players[p].names[i].text) > 0) {
                D_800E54A4->players[p].state = 8;
                func_804322AC_de(p);
            }
            break;
        }
        break;
    case 8:
        switch (event) {
        case 0x2F4:
            if (func_80404858_de(p, D_800E54A4->players[p].slot) == 0) {
                if (func_802A03F4_de((u8 *)D_800D36D4,
                                     D_800E54A4->players[p].names[D_800E54A4->players[p].slot].code) == 0) {
                    for (j = 0; j < 4; j++) {
                        found = func_804358C0_de(D_800E54A4->players[p].profile, D_800E54A4->players[p].records[j].owner);
                        if (found != -1) {
                            func_8022EF30_de(&((Record_func_80433914_de *) D_80102B00)[found]);
                        }
                    }
                }
                D_800E54A4->players[p].state = 4;
                func_804322AC_de(p);
            } else {
                func_80404E28_de(p);
                func_80433610_de(p);
            }
            break;
        case 0x2F5:
            D_800E54A4->players[p].state = 4;
            func_804322AC_de(p);
            break;
        }
        break;
    case 7:
        switch (event) {
        case 0x2F0:
            i = D_800E54A4->players[p].choice;
            other = func_804358C0_de(D_800E54A4->players[p].profile, D_800E54A4->players[p].records[i].owner);
            if (other != -1) {
                func_8022EF30_de(&((Record_func_80433914_de *) D_80102B00)[other]);
            }
            func_8022EF30_de(&D_800E54A4->players[p].records[i]);
            if (func_80434428_de(p) == 1) {
                if (D_800E54A4->players[p].sub == 5) {
                    switch (D_800E54A4->phase) {
                    case 0:
                        D_800E54A4->players[p].back = 2;
                        D_800E54A4->players[p].state = 2;
                        D_800E54A4->players[p].next = 0xC;
                        D_800E54A4->players[p].sub = 0;
                        break;
                    case 2:
                        D_800E54A4->players[p].next = 9;
                        D_800E54A4->players[p].back = 2;
                        D_800E54A4->players[p].state = 2;
                        D_800E54A4->players[p].sub = 3;
                        break;
                    default:
                        D_800E54A4->players[p].state = 0xD;
                        break;
                    }
                } else {
                    D_800E54A4->players[p].state = 0xD;
                }
                func_804322AC_de(p);
            }
            break;
        case 0x2F1:
            D_800E54A4->players[p].state = 0xD;
            func_804322AC_de(p);
            break;
        }
        break;
    case 9:
        switch (event) {
        case 0x2B1:
            slot = func_80435128_de(p);
            if (slot >= 0) {
                func_802A0724_de(&D_800E54A4->players[p].records[slot],
                                 &D_800E54A4->players[((struct PakMenuTail *) ((u8 *) D_800E54A4 + sizeof(PakMenuController)))->source].records[((struct PakMenuTail *) ((u8 *) D_800E54A4 + sizeof(PakMenuController)))->sourceRecord],
                                 0x190);
                D_800E54A4->players[p].record = slot;
                D_800E54A4->players[p].records[slot].owner = slot;
                D_800E54A4->players[p].records[slot].time = D_800E54A4->players[p].profile;
            }
            if (func_80434428_de(p) == 1) {
                if (D_800E54A4->phase == 2) {
                    if (D_800E54A4->players[p].host == 1) {
                        func_80434D70_de(p);
                    } else {
                        D_800E54A4->players[p].state = 0xE;
                    }
                } else {
                    D_800E54A4->players[p].state = 0xD;
                }
                func_804322AC_de(p);
            }
            break;
        case 0x2B2:
            if (D_800E54A4->phase == 2) {
                if (D_800E54A4->players[p].host == 1) {
                    func_80434D70_de(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
            } else {
                D_800E54A4->players[p].state = 0xD;
            }
            func_804322AC_de(p);
            break;
        }
        break;
    case 13:
        if (event == 0x2CD) {
            sub = D_800E54A4->players[p].sub;
            switch (sub) {
            case 3:
                D_800E54A4->players[p].state = 0x11;
                q = ((int (*)(u8 *)) func_80434750_de)((u8 *) D_800E54A4 + p * sizeof(Shared_Player_func_80433F14));
                if (q >= 0) {
                    D_800E54A4->players[q].back = 2;
                    D_800E54A4->players[q].state = 2;
                    D_800E54A4->players[q].next = 0xD;
                    D_800E54A4->players[q].sub = 3;
                    func_804322AC_de(q);
                }
                break;
            case 6:
                switch (D_800E54A4->phase) {
                case 1:
                    D_800E54A4->players[p].state = 0x11;
                    q = ((int (*)(u8 *)) func_80434750_de)((u8 *) D_800E54A4 + p * sizeof(Shared_Player_func_80433F14));
                    if (q >= 0) {
                        D_800E54A4->players[q].back = 2;
                        D_800E54A4->players[q].state = 2;
                        D_800E54A4->players[q].next = 0xD;
                        D_800E54A4->players[q].sub = sub;
                        func_804322AC_de(q);
                    }
                    break;
                case 7:
                    D_800E54A4->players[p].state = 0x1A;
                    D_800E54A4->players[p].next = 0xD;
                    break;
                }
                break;
            case 0:
                D_800E54A4->players[p].state = 0xE;
                break;
            case 5:
                mode = D_800E54A4->phase;
                switch (mode) {
                case 3:
                    D_800E54A4->players[p].state = 0xE;
                    break;
                case 0:
                    D_800E54A4->players[p].back = 2;
                    D_800E54A4->players[p].state = 2;
                    D_800E54A4->players[p].next = 0xC;
                    D_800E54A4->players[p].sub = 0;
                    break;
                case 2:
                    D_800E54A4->players[p].back = mode;
                    D_800E54A4->players[p].state = mode;
                    D_800E54A4->players[p].next = 9;
                    D_800E54A4->players[p].sub = 3;
                    break;
                }
                break;
            }
            func_804322AC_de(p);
            break;
        }
        i = 0;
        switch (event) {
        case 0x2CB:
            i = 1;
            break;
        case 0x2CC:
            i = 2;
            break;
        case 0x2C8:
            i = 3;
            break;
        }
        switch (D_800E54A4->players[p].sub) {
        case 0:
            break;
        case 3:
            if (D_800E54A4->players[p].used[i] == 1) {
                func_8043599C_de(p, i, 0);
                D_800E54A4->players[p].choice = i;
                D_800E54A4->players[p].state = 0x1B;
                func_804322AC_de(p);
            }
            break;
        case 6:
            switch (D_800E54A4->phase) {
            case 1:
                if (D_800E54A4->players[p].used[i] == 1) {
                    D_800E54A4->players[p].choice = i;
                    D_800E54A4->players[p].state = 0x16;
                    func_804322AC_de(p);
                }
                break;
            case 7:
                if (D_800E54A4->players[p].used[i] == 1) {
                    func_8043599C_de(p, i, 0);
                    func_804356BC_de(0);
                    func_8029973C_de();
                    func_8043577C_de(9);
                    return 0;
                }
                break;
            }
            break;
        case 5:
            switch (D_800E54A4->phase) {
            case 0:
            case 2:
            case 3:
                if (D_800E54A4->players[p].used[i] != 2) {
                    D_800E54A4->players[p].choice = i;
                    D_800E54A4->players[p].state = 7;
                    func_804322AC_de(p);
                }
                break;
            }
            break;
        }
        break;
    case 22:
        switch (event) {
        case 0x28C:
            i = 0;
            break;
        case 0x28E:
            i = 1;
            break;
        case 0x290:
            i = 2;
            break;
        case 0x292:
            i = 3;
            break;
        case 0x28B:
            func_8043577C_de(3);
            return 0;
        }
        func_8043599C_de(p, D_800E54A4->players[p].choice, i);
        func_804356BC_de(i);
        func_8040E8D8_de(func_8040EC30_de(D_800E54A4->players[p].notes[D_800E54A4->players[p].choice], 0x2C9), 1);
        D_800E54A4->players[p].used[D_800E54A4->players[p].choice] = 0;
        ((struct PakMenuTail *) ((u8 *) D_800E54A4 + sizeof(PakMenuController)))->ports[i].x = 0;
        D_800E54A4->players[p].port = i;
        func_80433BCC_de(p);
        D_800E54A4->players[p].state = 0xD;
        func_804322AC_de(p);
        break;
    case 27:
        switch (event) {
        case 0x295:
            func_8043577C_de(3);
            return 0;
        case 0x296:
            i = 0;
            break;
        case 0x298:
            i = 1;
            break;
        case 0x29A:
            i = 2;
            break;
        case 0x29C:
            i = 3;
            break;
        }
        if (i != p) {
            func_8041B7B4_de(D_800E54A4->root, p, 1);
            D_800E54A4->players[i].back = 2;
            D_800E54A4->players[i].state = 2;
            D_800E54A4->players[i].next = 9;
            D_800E54A4->players[i].sub = 3;
            D_800E54A4->players[i].host = 1;
            func_804322AC_de(i);
        } else {
            D_800E54A4->players[p].state = 9;
            func_804322AC_de(p);
        }
        break;
    case 6:
        switch (event) {
        case 0x2AE:
            D_800E54A4->players[p].state = 0xE;
            func_804322AC_de(p);
            break;
        case 0x2AF:
            func_80434B08_de(p);
            if (func_80434428_de(p) == 1) {
                D_800E54A4->players[p].state = 0xE;
                func_804322AC_de(p);
            }
            break;
        }
        break;
    case 21:
        switch (event) {
        case 0x2A8:
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                D_800E54A4->players[p].state = 0xE;
                func_804322AC_de(p);
                break;
            }
            break;
        case 0x2A7:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            func_804322AC_de(p);
            break;
        }
        break;
    case 23:
        switch (event) {
        case 0x2B8:
            D_800E54A4->players[p].state = 0xC;
            func_804322AC_de(p);
            break;
        case 0x2B9:
            if (D_800E54A4->phase == 7) {
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0x17;
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            func_804322AC_de(p);
            break;
        }
        break;
    case 24:
        switch (event) {
        case 0x2BE:
            D_800E54A4->players[p].state = 0xD;
            D_800E54A4->players[p].sub = 5;
            func_804322AC_de(p);
            break;
        case 0x2BD:
            if (D_800E54A4->players[p].host == 1) {
                func_80434D70_de(p);
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            func_804322AC_de(p);
            break;
        }
        break;
    case 25:
        if (event == 0x2BB) {
            if (D_800E54A4->players[p].host == 1) {
                func_80434D70_de(p);
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            func_804322AC_de(p);
        }
        break;
    case 26:
        switch (event) {
        case 0x2C0:
            D_800E54A4->players[0].back = 2;
            D_800E54A4->players[0].state = 2;
            D_800E54A4->players[0].next = 0xD;
            D_800E54A4->players[0].sub = 6;
            func_804322AC_de(p);
            break;
        case 0x2C1:
            func_8022F204_de(0);
            func_8029973C_de();
            func_8043577C_de(9);
            return 0;
        }
        break;
    case 28:
        switch (event) {
        case 0x2A2:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            func_804322AC_de(p);
            break;
        case 0x2A3:
            if (func_80405290_de(p) != 0) {
                D_800E54A4->players[p].state = 0x1D;
                func_804322AC_de(p);
            } else {
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                func_804322AC_de(p);
            }
            break;
        }
        break;

    case 29:
        if (event == 0x2A5) {
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            func_804322AC_de(p);
        }
        break;
    }
    return 0;
}
