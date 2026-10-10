#ifndef RW_GAMEPLAY_TRANSITION_H

#define RW_GAMEPLAY_TRANSITION_H

#include "types.h"

#include "common/types_8a8189af7b05.h"

/* Player-transition records from origin/legacy shared headers. */

typedef struct Shared_ActorView Shared_ActorView;
struct Shared_ActorView {
    char pad0[0x8];
    /* The actual player position also has a word representation in the published
     * SharedPlayer.views0.positionBits; Triple is the copy-provider transport ABI. */
    union { Vec3 vector; Triple words; } position;
    char pad14[0x4];
    void * model; /* +0x18: src/func_8021B468.c */
    char pad1C[0xC8];
    u16 kind; /* +0xE4: src/func_8021B468.c */
    char padE6[0x10A];
    s32 frameValue; /* +0x1F0: src/func_8021B468.c */
    char pad1F4[0xF4];
    char weapon[368]; /* +0x2E8: src/func_8021B468.c */
    char ammoData[376]; /* +0x458: src/func_8021B468.c */
    s32 actorState; /* +0x5D0: src/func_8021B468.c */
    u32 mode; /* +0x5D4: src/func_8021B468.c */
    struct Shared_ControlView * controls; /* +0x5D8: src/func_8021B468.c */
    void *message; /* +0x5DC: src/func_8021B468.c */
    s32 state; /* +0x5E0: src/func_8021B468.c */
    char pad5E4[0x10];
    s16 ammo[3]; /* +0x5F4: src/func_8021B468.c */
    char pad5FA[0x56];
    s16 action; /* +0x650: src/func_8021B468.c */
    char pad652[0x46];
    void *controller; /* +0x698: src/func_8021B468.c */
    char pad69C[0x7C];
    f32 speed; /* +0x718: src/func_8021B468.c */
    char pad71C[0xABC];
    s32 stun; /* +0x11D8: src/func_8021B468.c */
    char pad11DC[0x8];
    s32 pending; /* +0x11E4: src/func_8021B468.c */
    char pad11E8[0x14];
    s32 field11FC; /* +0x11FC: src/func_8021B468.c */
    char pad1200[0x18];
    s32 field1218; /* +0x1218: src/func_8021B468.c */
    s32 projectileBase; /* +0x121C: src/func_8021B468.c */
    s32 projectileIndex; /* +0x1220: src/func_8021B468.c */
    void * projectiles[2]; /* +0x1224: src/func_8021B468.c */
    s32 field122C; /* +0x122C: src/func_8021B468.c */
    s32 field1230; /* +0x1230: src/func_8021B468.c */
    s32 field1234; /* +0x1234: src/func_8021B468.c */
    s32 field1238; /* +0x1238: src/func_8021B468.c */
    char pad123C[0x4];
    s32 field1240; /* +0x1240: src/func_8021B468.c */
    char pad1244[0x180];
    u8 specialState; /* +0x13C4: src/func_8021B468.c */
    char pad13C5[0x3];
    s32 special; /* +0x13C8: src/func_8021B468.c */
    char pad13CC[0x14];
    void * parent; /* +0x13E0: src/func_8021B468.c */
    char pad13E4[0x2FC];
    struct Shared_ActorView * next; /* +0x16E0: src/func_8021B468.c */
};
typedef char Shared_ActorView_size_check[(sizeof(Shared_ActorView) == 0x16E4) ? 1 : -1];

typedef struct Shared_ControlView Shared_ControlView;
struct Shared_ControlView {
    char pad0[0x80];
    s8 mode; /* +0x80: src/func_8021B468.c */
    char pad81[0xE];
    u8 transientFlag; /* +0x8F: src/func_8021B468.c */
    s8 resetFlag; /* +0x90: src/func_8021B468.c */
    char pad91[0x3];
    u8 germanActive; /* +0x94: src/func_8021B468.c */
};
typedef char Shared_ControlView_size_check[(sizeof(Shared_ControlView) == 0x95) ? 1 : -1];

typedef struct Shared_ProjectileView Shared_ProjectileView;
struct Shared_ProjectileView {
    char pad0[0x14];
    s32 source; /* +0x14: src/func_8021B468.c */
    char pad18[0x184];
    u16 flags; /* +0x19C: src/func_8021B468.c */
    char pad19E[0x2];
};
typedef char Shared_ProjectileView_size_check[(sizeof(Shared_ProjectileView) == 0x1A0) ? 1 : -1];

typedef struct Shared_PlayerSettingsView Shared_PlayerSettingsView;
struct Shared_PlayerSettingsView {
    char pad0[0x80];
    s8 character; /* +0x80: src/func_8021B468.c */
    char pad81[0x14];
    u8 active; /* +0x95: src/func_8021B468.c */
    char pad96[0x46A];
    s32 effect; /* +0x500: src/func_8021B468.c */
    char pad504[0xA0];
    s32 state; /* +0x5A4: src/func_8021B468.c */
};
typedef char Shared_PlayerSettingsView_size_check[(sizeof(Shared_PlayerSettingsView) == 0x5A8) ? 1 : -1];

#include "shared/gameplay_settings.h"

typedef struct Shared_ModelView Shared_ModelView;
struct Shared_ModelView {
    s32 unused; /* +0x0: src/func_8021B468.c */
    s32 flags; /* +0x4: src/func_8021B468.c */
};
typedef char Shared_ModelView_size_check[(sizeof(Shared_ModelView) == 0x8) ? 1 : -1];

typedef struct Shared_SpecialObjectView Shared_SpecialObjectView;
struct Shared_SpecialObjectView {
    char pad0[0x170];
    char segment[100]; /* +0x170: src/func_8021B468.c */
    s32 reset; /* +0x1D4: src/func_8021B468.c */
};
typedef char Shared_SpecialObjectView_size_check[(sizeof(Shared_SpecialObjectView) == 0x1D8) ? 1 : -1];

typedef struct Shared_GlobalPlayers Shared_GlobalPlayers;
struct Shared_GlobalPlayers {
    s32 unused; /* +0x0: src/func_8021B468.c */
    char *players; /* +0x4: src/func_8021B468.c */
    s32 count; /* +0x8: src/func_8021B468.c */
    char controller[20]; /* +0xC: src/func_8021B468.c */
    char effects; /* +0x20: src/func_8021B468.c */
    char pad21[0x3];
};
typedef char Shared_GlobalPlayers_size_check[(sizeof(Shared_GlobalPlayers) == 0x24) ? 1 : -1];

typedef struct Shared__struct_D_800D34C0_0x18 Shared__struct_D_800D34C0_0x18;
struct Shared__struct_D_800D34C0_0x18 {
    char pad0[0xC];
    s16 unkC; /* +0xC: src/func_8021B468.c */
    s16 unkE; /* +0xE: src/func_8021B468.c */
    s16 unk10; /* +0x10: src/func_8021B468.c */
    char pad12[0x6];
};
typedef char Shared__struct_D_800D34C0_0x18_size_check[(sizeof(Shared__struct_D_800D34C0_0x18) == 0x18) ? 1 : -1];

typedef struct Shared_HeightBonuses Shared_HeightBonuses;
struct Shared_HeightBonuses {
    f32 spawn; /* +0x0: src/func_8021B468.c */
    f32 projectile; /* +0x4: src/func_8021B468.c */
};
typedef char Shared_HeightBonuses_size_check[(sizeof(Shared_HeightBonuses) == 0x8) ? 1 : -1];

#endif
