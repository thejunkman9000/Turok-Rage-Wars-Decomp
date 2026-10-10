#ifndef RW_GAMEPLAY_REACTION_RULES_H
#define RW_GAMEPLAY_REACTION_RULES_H
#include "types.h"
typedef struct Shared_MatchRules Shared_MatchRules;
struct Shared_MatchRules {
    char pad0[0x20];
    s32 hideHud;        /* +0x20: src/func_8021EED8.c */
    s32 teams;          /* +0x24: src/func_8021EED8.c */
    char pad28[0x4];
    s32 teamScores[5];  /* +0x2C: src/func_8021EED8.c */
    s32 squadScores[5]; /* +0x40: src/func_8021EED8.c */
    s32 countRule;      /* +0x54: src/func_8021EED8.c */
    char pad58[0x20];
    s32 squads;         /* +0x78: src/func_8021EED8.c */
    char pad7C[0x1C];
    s32 markers;        /* +0x98: src/func_8021EED8.c */
};
/* Match-rule fields from src/func_8021EED8.c. */

#endif
