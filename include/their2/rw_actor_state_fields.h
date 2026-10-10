#ifndef RW_ACTOR_STATE_FIELDS_H
#define RW_ACTOR_STATE_FIELDS_H
#include "types.h"
/* Consumed fragments of32byte actor state records, separate from24byte
 * player states. Transition routine scans signedstateID+0 and invokes
 * enter+4 with actor/context. Animation routine reads f32scale+20,
 * signedthreshold+24 and bitflags+28. Other fields remain unclaimed. */
struct func_802070D0_S3;
struct func_802070D0_S1;
typedef struct func_802070D0_S3 func_802070D0_S3;
typedef struct func_802070D0_S1 func_802070D0_S1;
typedef void (*RwActorStateEnter)(void *, void *);
typedef struct RwActorStateEntry { s32 id; RwActorStateEnter enter; } RwActorStateEntry;
typedef struct RwActorStateDispatch { s32 id; RwActorStateEnter enter; RwActorStateEnter update; } RwActorStateDispatch;
typedef struct RwActorStateAnimation { f32 scale; s32 threshold; u32 flags; } RwActorStateAnimation;
#endif
