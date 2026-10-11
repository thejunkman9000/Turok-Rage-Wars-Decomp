/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028308C.h"
#include "types.h"
#include "common/unused.h"
#include "packed_float.h"


extern void func_80284178_de(void);
extern void func_802A42F4_de(void *arg0, void *arg1);


void func_80283A1C_de(void *arg0) {
    s32 temp;

    if (((func_802839F0_S1 *)(arg0))->unk1D9 != 0) {
        func_80284178_de();
        func_802A42F4_de(&D_801379C0, arg0);
    }
    temp = ((func_802839F0_S1 *)(arg0))->unk138;
    if (temp != 0) {
        func_80268C7C_de(&D_8013B1A8, temp);
        ((func_802839F0_S1 *)(arg0))->unk138 = 0;
    }
}

/* Adds acceleration along a direction and clamps the resulting speed to its configured limit. */

f32 func_802B72B0_de(f32);
void func_80271F9C_de(Vec3 *,Vec3 *,f32); void func_80271F34_de(Vec3 *,Vec3 *,Vec3 *);
void func_80283A80_de(Obj_func_80283A80_de *arg0) {
 Vec3 delta, direction;
 Vec3 *velocity, *dir;
 int condition;
 f32 accel, length, limit;
 accel=RW_BITS_TO_FLOAT(arg0->link->params->accel);
 if(accel != 0.0f) {
 dir=&direction;
 direction=arg0->direction;
 func_80271F9C_de(&delta,dir,accel);
 velocity=&arg0->velocity;
 func_80271F34_de(velocity,velocity,&delta);
 length=func_802B72B0_de(arg0->velocity.x*arg0->velocity.x+arg0->velocity.y*arg0->velocity.y+arg0->velocity.z*arg0->velocity.z);
 limit=RW_BITS_TO_FLOAT(arg0->link->params->limit);
 if(accel>0.0f) { if(!(limit<length)) goto done; } else { if(!(length<limit)) goto done; } func_80271F9C_de(velocity,dir,limit); done:;
 }
}

void func_80283BA0_de(void *arg0, s32 arg1) {
    if (((((struct ObjectState60 *) ((s8 *) arg0))->unk_4) == 0x56) && (arg1 == 2)) {
        (((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) = (s32) ((((struct ObjectState60 *) ((s8 *) arg0))->unk_5C) | 0x04000000);
    }
}


void func_80283BCC_de(void *arg0) {
    ((func_80283BA0_S1 *)(arg0))->unk5C |= 0x20000;
    ((func_80283BA0_S1 *)(arg0))->unk8 = D_801001F8.first;
    ((func_80283BA0_S1 *)(arg0))->unk1C = D_801001F8.second;
}
