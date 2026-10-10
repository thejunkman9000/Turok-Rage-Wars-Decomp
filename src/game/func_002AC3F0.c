#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"
/* Returns whether a player actor can use the item picked up through func_8024E924_de: never for non-players or disabled actors, always during a team round when the model says so, and otherwise by the item's table: a D_800D31D0 power-up when the actor's team matches a D_800CE474 entry or its slot is free while not both states 3 and 7 are in use, a D_800D3230 weapon when on those teams or below the level from func_8022ACB8_de, a D_800D32A8 item when func_8022AC00_de exceeds the actor's count at 0x5E4, any D_800D34C0 item, and a D_800D3390 item unless it is item 0xBD6. */
extern char D_800D31D0;
extern char D_800D3230;
extern char D_800D32A8;
extern char D_800D3390;
extern char D_800D34C0;
extern s32 D_800CE474[2];
extern s32 D_801468F4;
extern s32 func_8024E924_de(s32 arg0);
extern s32 func_8022ACB8_de(Actor_func_802AB400_de *actor, s16 index, s32 arg2);
extern s32 func_8022AC00_de(Actor_func_802AB400_de *actor, s32 id);
static inline Entry_func_802AB400_de *find_entry(char *table, s32 count, s32 size, s32 id) {
    Entry_func_802AB400_de *entry;
    s32 i;
    entry = (Entry_func_802AB400_de *)table;
    for (i=count; i!=-1; --i) {
        if (entry->id == id) return entry;
        entry=(Entry_func_802AB400_de *)((char *)entry+size);
    }
    return 0;
}
s32 func_802AB400_de(s32 arg0, Actor_func_802AB400_de *actor) {
    Entry_func_802AB400_de *powerup;
    Entry_func_802AB400_de *weapon;
    Entry_func_802AB400_de *item;
    Entry_func_802AB400_de *bonus;
    Entry_func_802AB400_de *special;
    s32 id;
    s32 level;
    s32 noState3;
    s32 noState7;
    s32 i;
    Actor_func_802AB400_de *player;
    id = func_8024E924_de(arg0);
    if (((actor)->type == 1 && ((actor)->flags & 0x300000) != 0)) {
        player = actor;
        if (player->count == 0) {
            return 0;
        }
        if (D_801468F4 != 0 && player->model->unk8F != 0) {
            return 1;
        }
        powerup = find_entry(&D_800D31D0, 3, 0x18, id);
        if (powerup != 0) {
            noState3 = 1;
            noState7 = 1;
            if (player->team == D_800CE474[0] || player->team == D_800CE474[1]) {
                return 1;
            }
            if (player->slots[powerup->index].pad1 != -1) {
                return 0;
            }
            for (i = 0; i < 22; i++) {
                if (player->slots[i].pad1 == 3) {
                    noState3 = 0;
                } else if (player->slots[i].pad1 == 7) {
                    noState7 = 0;
                }
            }
            if (noState3 || noState7) {
                return 1;
            }
            return 0;
        }
        weapon = find_entry(&D_800D3230, 5, 0x14, id);
        if (weapon != 0) {
            level = func_8022ACB8_de(player, weapon->index, 0);
            if (player->team == D_800CE474[0] || player->team == D_800CE474[1]) {
                return 1;
            }
            return player->levels[weapon->index] < level;
        }
        item = find_entry(&D_800D32A8, 7, 0x18, id);
        if (item != 0) {
            return player->count < func_8022AC00_de(player, id);
        }
        bonus = find_entry(&D_800D34C0, 15, 0x18, id);
        if (bonus != 0) {
            return 1;
        }
        special = find_entry(&D_800D3390, 2, 0x10, id);
        if (special != 0) {
            if ((player->team == D_800CE474[0] || player->team == D_800CE474[1]) && special->id != 0xBD6) {
                return 1;
            }
            return special->id != 0xBD6;
        }
        return 0;
    }
    return ((actor)->type == 1 && ((actor)->flags & 0x300000) != 0);
}
typedef struct Handler Handler;
/* Dispatches an item effect with the given id to an actor that can receive it: looks the id up in each item handler table in turn (D_800D31D0, D_800D3230, D_800D32A8, D_800D3368, D_800D34C0, D_800D33C0 and D_800D3390) and returns the first nonzero handler result, clearing the given target from every actor's two lock-on slots after the D_800D34C0 handler. */
extern char D_800D31D0;
extern char D_800D3230;
extern char D_800D32A8;
extern char D_800D3368;
extern char D_800D3390;
extern char D_800D33C0;
extern char D_800D34C0;
extern Actor_func_802AB6EC_de *D_80145060;
static inline Handler *find_handler(char *table, s32 count, s32 size, s32 id) {
    Handler *entry;
    s32 i;
    entry = (Handler *)table;
    i = count;
    do {
        if (entry->id == id) {
            return entry;
        }
        i--;
        entry = (Handler *)((char *)entry + size);
    } while (i != -1);
    return 0;
}
s32 func_802AB6EC_de(Actor_func_802AB6EC_de *actor, s32 target, s32 id) {
    Handler *entry;
    Actor_func_802AB6EC_de *other;
    s32 result;
    result = 0;
    if (actor->enabled != 0) {
        entry = find_handler(&D_800D31D0, 3, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3230, 5, 0x14, id);
        if (entry != 0) {
            result = entry->handle10(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D32A8, 7, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3368, 1, 0x14, id);
        if (entry != 0) {
            result = entry->handle10(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D34C0, 15, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        for (other = D_80145060; other != 0; other = other->next) {
            if (other->lockOn[0] == target) {
                other->lockOn[0] = 0;
            } else if (other->lockOn[1] == target) {
                other->lockOn[1] = 0;
            }
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D33C0, 15, 0x10, id);
        if (entry != 0) {
            result = entry->handleC.targeted(actor, entry, target);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3390, 2, 0x10, id);
        if (entry != 0) {
            result = entry->handleC.plain(actor, entry);
        }
    }
    return result;
}
