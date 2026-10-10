#ifndef FUNC_8020EF80_EU_X_CLOSED_H
#define FUNC_8020EF80_EU_X_CLOSED_H
#include "types.h"
typedef struct Shared_PickupGoalNode Shared_PickupGoalNode;
struct Shared_PickupGoalNode {
    s32 id;
    u32 unknown4[3];
    Shared_PickupGoalNode *next;
    u32 unknown14[8];
    s32 goal;
};

#include "common/unused.h"
#include "types.h"

extern PickupGoalNodeList D_8013B364;

extern void func_8020D014_de(PickupGoalNodeList *list);
extern void func_8020D1FC_de(PickupGoalNodeList *list);
extern s32 func_8020F150_de(s32 *ids);
extern void func_8020D0CC_de(PickupGoalNodeList *list, s32 key);
extern Shared_PickupGoalNode *func_8020CFE0_de(PickupGoalNodeList *list, u32 key);
extern void func_8020D114_de(PickupGoalNodeList *list, s32 *output, s32 count);


#endif
