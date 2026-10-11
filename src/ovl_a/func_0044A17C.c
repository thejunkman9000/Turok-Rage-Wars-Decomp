/* their2 */
/* ported from melalawi/ragewars-decomp src/func_8044952C_de.c (CC0); only symbol names changed (func_00XXXXXX / D_XXXXXXXX = US v1.1 addresses); built with @SN */
#include "common/unused.h"
#include "span_C76B0/data.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "types.h"
/* declarations of symbols that the headers declare under their own (German version) names */
extern float D_800C7428;
extern float D_800C742C;
extern Entry190 D_80102B10[];
extern void func_0025E13C(s32 arg0);
/** Reset a player for a new life: restore health, clear status timers and effects, and drop any carried object. */




typedef struct RespawnFlags {
    int bits;
} RespawnFlags;

typedef struct RespawnCarried {
    char pad0[0x100];
    int flags;
    char pad104[0x170 - 0x104];
    RespawnFlags state;
} RespawnCarried;

typedef struct RespawnPair {
    signed char kind;
    signed char state;
} RespawnPair;

typedef struct RespawnPlayer {
    char pad0[0x38];
    int moving;
    char pad3C[0x174 - 0x3C];
    int maxHealth;
    char pad178[0x5D4 - 0x178];
    int character;
    char pad5D8[0x5E4 - 0x5D8];
    int health;
    char pad5E8[0x5EA - 0x5E8];
    short state;
    char pad5EC[0x602 - 0x5EC];
    RespawnPair effects[22];
    char pad62E[0x670 - 0x62E];
    float bob;
    char pad674[0x698 - 0x674];
    void *anim;
    char pad69C[0x11B4 - 0x69C];
    int field11B4;
    int field11B8;
    char pad11BC[0x11D8 - 0x11BC];
    int field11D8;
    char pad11DC[0x11E4 - 0x11DC];
    int field11E4;
    RespawnCarried *carried;
    int field11EC;
    char pad11F0[0x11FC - 0x11F0];
    int field11FC;
    char pad1200[0x1210 - 0x1200];
    int field1210;
    char pad1214[0x12C0 - 0x1214];
    float fade;
    char pad12C4[0x13C8 - 0x12C4];
    int field13C8;
    char pad13CC[0x13D4 - 0x13CC];
    int field13D4;
    int field13D8;
    int field13DC;
    int field13E0;
    int field13E4;
    char pad13E8[0x1450 - 0x13E8];
    int isBot;
    void *brain;
} RespawnPlayer;


extern unsigned char D_801462E5;

static inline int isOnline(void) {
    return D_801462E5;
}
extern unsigned int D_800D2980;
extern short D_800CF198[];


extern void func_0022B500(struct RespawnPlayer *);
extern void func_00264808(void *, int);
extern void func_002266E4(struct RespawnPlayer *);
extern void func_0021A78C(struct RespawnPlayer *);
extern int func_002934DC(void);

extern void func_0021AF6C(struct RespawnPlayer *);
extern void func_00208000(void *);
extern void func_00217388(struct RespawnCarried *, struct RespawnFlags *);
extern void func_00262CA8(struct RespawnCarried *);

static inline void releaseState(struct RespawnCarried *carried, struct RespawnFlags *state) {
    if (state != 0) {
        func_00217388(carried, state);
        state->bits |= 0x20;
    }
}

void func_0044A17C(struct RespawnPlayer *player) {
    int i;
    struct RespawnCarried *carried;

    func_0022B500(player);
    player->moving = 0;
    player->fade = D_800C7428;
    func_00264808(player->anim, 1);
    if (D_801462E5 != 0) {
        func_002266E4(player);
    } else {
        if (player->isBot == 0) {
            player->health = D_80102B10[player->character].value + 0x6400;
        } else {
            player->health = 0x6400;
        }
        player->maxHealth = player->health;
    }
    player->bob = D_800C742C;
    func_0021A78C(player);
    player->field11D8 = 0;
    player->field11FC = 0;
    player->field13E0 = 0;
    player->field1210 = 0;
    player->field11EC = 0;
    player->field11E4 = 0;
    player->field13D8 = 0;
    player->field13DC = 0;
    player->field13E4 = 0;
    player->field13D4 = 0;
    if (func_002934DC() != 0 && D_801462E5 == 0 && D_800D2980 > 10 && player->state < 11) {
        func_0025E13C(D_800CF198[player->state]);
    }
    if (isOnline()) {
        func_0021AF6C(player);
    }
    player->field11B4 = 0;
    player->field11B8 = 0;
    player->field13C8 = 0;
    if (player->isBot != 0) {
        func_00208000(player->brain);
    }
    for (i = 1; i < 22; i++) {
        if (player->effects[i].state == 3 || player->effects[i].state == 7) {
            player->effects[i].kind = 0;
            player->effects[i].state = -1;
        }
    }
    carried = player->carried;
    if (carried != 0) {
        releaseState(carried, &carried->state);
        carried->flags &= ~0x2000;
        carried->flags &= ~0x100;
        func_00262CA8(player->carried);
        player->carried = 0;
    }
}

