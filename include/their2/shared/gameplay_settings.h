#ifndef RW_GAMEPLAY_SETTINGS_H
#define RW_GAMEPLAY_SETTINGS_H
#include "types.h"
/* Actual 0x96-byte player-settings records based at Game+0xD0.
 * ROM joining-player stores (+0x78/+0x7F) and exact transition caller
 * reads (+0x80/+0x95) corroborate the shared record. */
typedef struct Shared_PlayerSettingsRecord Shared_PlayerSettingsRecord;
struct Shared_PlayerSettingsRecord {
    char pad0[0x78];
    u8 enabled; /* +0x78: func_80423F48_de ROM joining-player stores */
    char pad79[6];
    u8 slot; /* +0x7F: func_80423F48_de ROM slot-number stores */
    s8 character; /* +0x80: src/func_8021B468.c */
    char pad81[0x14];
    u8 active; /* +0x95: src/func_8021B468.c */

};
typedef char Shared_PlayerSettingsRecord_size_check[(sizeof(Shared_PlayerSettingsRecord) == 0x96) ? 1 : -1];
#endif
