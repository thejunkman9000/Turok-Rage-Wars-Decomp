#ifndef RESIDENT_PICKUP_DESCRIPTORS_H
#define RESIDENT_PICKUP_DESCRIPTORS_H
#include "types.h"

/* Item lookup reads the ID at offset four. Pickup handlers read the
 * localized label directory, sound and effect IDs from the shared prefix. */
typedef struct ResidentPickupPrefix {
    const char **labels;
    s16 itemId;
    s16 soundId;
    s16 effectId;
    u16 flags;
} ResidentPickupPrefix;
typedef s32 (*ResidentPickupHandler)(void *actor, void *entry);
typedef s32 (*ResidentTargetedPickupHandler)(void *actor, void *entry, s32 target);
typedef struct ResidentPowerupDescriptor {
    ResidentPickupPrefix common;
    s16 slotIndex;
    s16 powerupType;
    s32 amount;
    ResidentPickupHandler handler;
} ResidentPowerupDescriptor;
typedef struct ResidentWeaponDescriptor {
    ResidentPickupPrefix common;
    s16 weaponSlot;
    s16 ammoAmount;
    ResidentPickupHandler handler;
} ResidentWeaponDescriptor;
typedef struct ResidentHealthDescriptor {
    ResidentPickupPrefix common;
    s32 amount;
    s32 value;
    ResidentPickupHandler handler;
} ResidentHealthDescriptor;
typedef struct ResidentLifeDescriptor {
    ResidentPickupPrefix common;
    u16 amount;
    u16 flags;
    ResidentPickupHandler handler;
} ResidentLifeDescriptor;
typedef struct ResidentSpecialDescriptor {
    ResidentPickupPrefix common;
    ResidentPickupHandler handler;
} ResidentSpecialDescriptor;
typedef struct ResidentTargetedDescriptor {
    ResidentPickupPrefix common;
    ResidentTargetedPickupHandler handler;
} ResidentTargetedDescriptor;
typedef struct ResidentAmmoDescriptor {
    ResidentPickupPrefix common;
    s16 ammoAmount[3];
    u16 flags;
    ResidentPickupHandler handler;
} ResidentAmmoDescriptor;
extern const char *D_800D7070[103];
#endif
