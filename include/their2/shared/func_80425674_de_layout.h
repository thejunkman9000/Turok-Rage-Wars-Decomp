#ifndef RW_FUNC_80425674_DE_LAYOUT_H
#define RW_FUNC_80425674_DE_LAYOUT_H

#include "types.h"
#include "shared/gameplay_settings.h"
typedef struct Shared_GameSlot Shared_GameSlot;
struct Shared_GameSlot {
    u8 enabled;
    u8 unknown01[6];
    u8 slot;
    s8 kind;
    u8 unknown09[0x10];
    u8 controller;
    u8 unknown1A[2];
    u8 role;
    u8 escort;
    u8 secondListMode;
    u8 unknown1F[0x77];
};
typedef struct Shared_Game Shared_Game;
struct Shared_Game {
    u32 flags;
    u8 unknown04[9];
    u8 controllerMode;
    u8 unknown0E[2];
    s32 buttons;
    u8 unknown14[7];
    u8 firstListMode;
    u8 unknown1C;
    u8 local;
    u8 mode1E;
    /* The ROM addresses these overlapping arrays from Game+0xD0 and +0x148.
     * Each 0x96-byte settings record's +0x78/+0x7F fields are the same
     * enabled/slot bytes used by the existing slots array. */
    union {
        struct {
            u8 unknown1F[0x129];
            Shared_GameSlot slots[8];
        };
        struct {
            u8 reserved1F[0xB1];
            Shared_PlayerSettingsRecord playerSettings[8];
            u8 reserved580[0x78];
        };
    };
    u8 unknown5F8[0x34];
    s32 unk62C;
    u8 unknown630[0x40];
    s32 split;
    u32 unknown674[3];
    s32 humanWon;
    /* origin/legacy shared/game.h retains the complete 0xCAC-byte game record. */
    u8 reserved684[0xCAC - 0x684];
};
typedef char Shared_Game_size_check[(sizeof(Shared_Game) == 0xCAC) ? 1 : -1];
typedef char Shared_Game_settings_offset_check[(((u32)&((Shared_Game *)0)->playerSettings) == 0xD0) ? 1 : -1];
typedef char Shared_Game_slots_offset_check[(((u32)&((Shared_Game *)0)->slots) == 0x148) ? 1 : -1];
#endif
