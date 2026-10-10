#ifndef FUNC_80214624_DE_CLOSED_H
#define FUNC_80214624_DE_CLOSED_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"

typedef struct { Vec3 pos; s32 unkC; } ApproachLocation;
extern s32 D_8013B290;
extern f32 D_800C2160_de[],D_800C215C_de;
extern f32 func_80216F44_de(Actor_func_80214624_de *,Vec3);
extern f32 func_8024D398_de(Actor_func_80214624_de *);
extern f32 func_80271AA8_de(Vec3 *);
extern ApproachLocation *func_80219408_de(void *);
extern s32 func_80240660_de(Actor_func_80214624_de *,Vec3,s32,s32,Vec3 *);
extern s32 func_80240698_de(Actor_func_80214624_de *,s32,Vec3,s32,s32,Vec3 *);
extern s32 func_80275B10_de(s32,f32,f32);
extern void func_8024E79C_de(Actor_func_80214624_de *,Vec3,Vec3 *,s32 *,s32,s32);
extern void func_80271F34_de(Vec3 *,Vec3 *,Vec3 *);
extern void func_80271F68_de(Vec3 *,Vec3 *,Vec3 *);
extern void func_80271F9C_de(Vec3 *,Vec3 *,f32);
extern void func_8027207C_de(Vec3 *);
static inline void approach(Actor_func_80214624_de *arg0,Actor_func_80214624_de *arg2,Actor_func_80214624_de *temp_a2,Vec3 *posp,s32 *roomp) {
 Vec3 delta,offset; f32 temp_f20;
        if (temp_a2 != 0) {
            func_80271F68_de(&delta, &arg2->pos, &temp_a2->pos);
            delta.y = 0;
            func_8027207C_de(&delta);
        } else {
            delta.x = 0;
            delta.y = 0;
            delta.z = 0;
        }
        temp_f20 = func_8024D398_de(arg2);
        func_80271F9C_de(&delta, &delta, temp_f20 + func_8024D398_de(arg0) + D_800C215C_de);
        func_80271F34_de(&offset, &arg2->pos, &delta);
        func_8024E79C_de(arg2, offset, posp, roomp, 0, 0);
}

#endif
