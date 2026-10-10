#ifndef RESIDENT_ARENA_MENU_H
#define RESIDENT_ARENA_MENU_H
#include "types.h"
/* The 28-byte resident menu slots read by 80428120/80428E10 and the
 * four navigation handlers 80428850/804289B4/80428B18/80428C7C.
 * -1 is a missing successor. Handler order is named by byte offset
 * until a direction-to-event mapping is established. */
typedef struct ResidentArenaMenuSlot {
    s32 resource_id;
    s32 category;
    s32 category_index;
    s32 next_0c;
    s32 next_10;
    s32 next_14;
    s32 next_18;
} ResidentArenaMenuSlot;
typedef char arena_menu_slot_size[(sizeof(ResidentArenaMenuSlot) == 28) ? 1 : -1];
#endif
