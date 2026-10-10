#ifndef FUNC_802453D4_DE_CLOSED_H
#define FUNC_802453D4_DE_CLOSED_H
#include "shared/func_804235A8_eu_layout.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"


struct SharedTrackObject;



#include "types.h"
#include "common/types_8a8189af7b05.h"

/* The copied prefix is exactly 0x50 bytes. */
typedef struct SharedTrackObjectPrefix {
    u32 unknown0[2];
    Vec3 position;
    u8 unknown14[0x3C];
} SharedTrackObjectPrefix;

typedef struct SharedTrackObject {
    SharedTrackObjectPrefix prefix;
    u8 unknown50[0x1C];
    f32 yaw;
} SharedTrackObject;

typedef struct SharedTrackCamera {
    u8 unknown0[0x28];
    f32 distance;
    f32 pitch;
    u8 unknown30[8];
    Vec3 position;
} SharedTrackCamera;

/* The two adjacent track constants are consumed at base and base+4. */
struct SharedTrackConstants { f32 amplitude; f32 unit; };
union SharedVectorBits { Triple words; Vec3 vector; };

#include "span_1000/code_80245980.h"
#include "span_C76B0/data.h"
#include "span_1000/code_80243A80.h"

extern Shared_MenuContext *D_800E2830;
extern s32 D_800E28D0;

extern s32 D_800E28D4;
extern s32 D_801377B8[2];
void func_802A84F8_de(void);

void func_802A8F28_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7);

#endif
