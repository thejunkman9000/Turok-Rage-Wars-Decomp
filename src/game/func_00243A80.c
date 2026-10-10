#include "span_1000/code_80243A80.h"
#include "common/types_8a8189af7b05.h"
#include "span_C76B0/data.h"
#include "types.h"

/* Moves an actor through collision queries and resolves its position and contact state. */

/* The values func_80243A90_de loads by address:
 * 0x800C8880 = -0.45 (float, D_800C3790_de in this cartridge's tables)
 * 0x800C8884 = -0.7071 (float, unnamed in this cartridge's tables)
 * 0x800C8888 = 204.79999 (float, D_800C3798_de in this cartridge's tables)
 * 0x800C888C = 1.0 (float, unnamed in this cartridge's tables)
 * 0x800C8890 = 51.199997 (float, D_800C37A0_de in this cartridge's tables)
 * 0x800C8894 = 1.024 (float, D_800C37A4_de in this cartridge's tables)
 * 0x800C8898 = 51.199997 (float, D_800C37A8_de in this cartridge's tables)
 */


#include "shared/legacy_collision_actor.h"

s32 func_8023D158_de(char *);
void func_8023E45C_de(void *);
void func_8023E690_de(void *, f32, f32, f32, f32);
void func_8023E6EC_de(void *, void *);
void func_8023E838_de(void *);
void func_8023EBD4_de(void *);
void func_8023EBFC_de(void *, void *);
void func_8023EC54_de(void *, void *);
void func_8023ECBC_de(void *, u16 *);
f32 func_802417C4_de(f32 *);
f32 func_8024D284_de(void *);
f32 func_8024D398_de(void *);
f32 func_8024E420_de(void *);
f32 func_8024E464_de(void *);
f32 func_80273F94_de(f32, f32);
void func_80274870_de(f32 *, f32, f32);
f32 func_8027525C_de(void *, f32, f32);
f32 func_80275DD4_de(void *, f32, f32);
void * func_8028C050_de(void *, void *);


s32 func_8023CFE0_de();                     /* extern */
s32 func_8023D380_de();                         /* extern */
extern Func80243A80Global *D_80103FCC;
extern s32 D_80103FD0;
extern Func80243A80State D_801000F0;
extern s32 D_80100170;

extern s32 D_801001D0;
extern s32 D_80100338;

extern float D_800C379C_de;

extern s32 D_801001D0;

/* Moves an actor through collision queries and updates its contact flags and resolved position. */
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x2d0, 0x2d4, 0x2d8, 0x2dc, 0x2e0, 0x2e4, 0x2e8, 0x2f8, 0x2fc, 0x300, 0x304], gap at: 0x2ec. */
typedef Shared_Func80243A80Frame Func80243A80Frame;

typedef Vec3 Func80243A80Vec3;
typedef Shared_Func80243A80Bits Func80243A80Bits;
s32 func_80243A90_de(Func80243A80Actor *arg0, Func80243A80Vec3 pos, u32 *arg4) {
    Func80243A80Frame frame;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v1_3;
    s32 var_a1; 
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u16 *temp_s0;
    u32 temp_a0;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_v0_2;
    u32 loopMask; 
    f32 dropDistance; 
    Func80243A80Actor *attachedActor; 
    s32 collisionOne; 
    f32 hitY; 
    f32 actorY; 
    f32 savedY; 

    func_8023EBD4_de(&frame.sp18);
    __builtin_memcpy(&D_80103FCC->x, &arg0->room, 12);
    arg0->flags = (u32) (arg0->flags & ~0x18);
    frame.sp18 = arg0;
    var_a1 = 0;
    if (arg0->type == 1) {
        var_a1 = (u32) var_a1 < (arg0->status & 0x300000);
    }
    frame.sp1C = var_a1;
    temp_f22 = func_8024E464_de(arg0);
    temp_f21 = func_8024D398_de(arg0);
    temp_f20 = func_8024D284_de(arg0);
    func_8023E690_de(&frame.sp18, temp_f22, temp_f21, temp_f20, func_8024E420_de(arg0));
    *(Func80243A80Vec3 *)&frame.sp5C = *(Func80243A80Vec3 *)&arg0->x;
    __builtin_memcpy(&frame.sp68, &pos, 12);
    __builtin_memcpy(&frame.sp8C, &arg0->room, 12);
    frame.spC4 = arg0->collision;
    var_v1 = 0;
    if ((*arg4 & 0x200) && (arg0->velY <= 0.0f)) {
        var_v1 = 1;
    }
    frame.sp3C = var_v1;
    frame.sp38 = ((u32) *arg4 >> 1) & 1;
    frame.sp40 = (((u32) arg0->flags >> 2) ^ 1) & 1;
    frame.sp44 = 1;
    frame.sp54 = arg0->flags;
    frame.sp34 = frame.sp28 * D_800C3790_de;
    frame.sp50 = ((u32) *arg4 >> 0x13) & 1;
    frame.sp58 = arg4;
    func_8023CFE0_de(&frame.sp18);
    if ((frame.sp3C != 0) && (frame.sp54 & 7) && !(frame.sp54 & 0x2000)) {
        __builtin_memcpy(&frame.sp210, &arg0->contactX, 12);
        frame.sp1E0 = arg0->x;
        frame.sp1E4 = arg0->groundY;
        frame.sp1E8 = arg0->z;
        func_8023E6EC_de(&frame.sp18, &frame.sp1C8);
    }
    if ((frame.sp1C != 0) || (frame.sp5C != frame.sp68) || (frame.sp60 != frame.sp6C) || (var_v0 = 0, (frame.sp64 != frame.sp70))) {
        var_v1_2 = ++D_800CB410_de;
        if (var_v1_2 < D_800CB414_de) {
            var_v1_2 = D_800CB414_de;
        }
        D_800CB414_de = var_v1_2;
        if ((arg4 != &D_80100338) && (arg4 != &D_801001D0) && (arg4 != &D_80103FD0) && (arg4 != &D_80100170)) {
            arg0->attached = 0;
            frame.sp54 &= ~0x7B;
        }
        frame.sp54 &= ~0x80;
        if (arg0->type == 1) {
            frame.sp2C8 = arg0->angle;
        } else {
            frame.sp2C8 = 0.0f;
        }
        temp_f22_2 = func_802B7130_de(frame.sp2C8);
        temp_f0 = func_802B6560_de(frame.sp2C8);
        frame.sp54 &= ~0x2000;
        temp_v1 = *arg4;
        if (temp_v1 & 4) {
            var_s0 = 1;
        } else if (temp_v1 & 0x800) {
            var_s0 = 3;
        } else {
            if (arg0->type == 1) var_s0 = 4;
            else var_s0 = 1;
        }
        var_v1_3 = var_s0;
        if (var_s0 >= 3) {
            var_v1_3 = 2;
        }
        frame.sp48 = var_v1_3;
        var_v1_4 = var_s0 + 1;
        if (var_v1_4 >= 4) {
            var_v1_4 = 3;
        }
        frame.sp4C = var_v1_4;
        func_8023E838_de(&frame.sp18);
        var_s3 = 0;
        loopMask = 0x80000;
        collisionOne = 1;
loop_34:
        if (*arg4 & loopMask) {
            frame.spC4 = func_8028C050_de(frame.spC4, &frame.sp68);
        }
        temp_v0 = func_8023D158_de((s8 *) &frame.sp18);
        var_a1 = 0;
        if (temp_v0 != 0) {
            if (frame.spC8 != collisionOne) {
                if (frame.spC8 == 4) {
                    if (((frame.sp110 * -temp_f22_2) + (frame.sp118 * -temp_f0)) < D_800C3794_de) {
                        frame.sp54 |= 0x80;
                        func_8023EBFC_de(&frame.sp18, &frame.spC8);
                    }
                } else {
                    goto block_42;
                }
            } else {
                frame.sp38 = 0;
block_42:
                frame.sp54 &= ~0x80;
            }
            func_8023E45C_de(&frame.sp18);
            var_s3 += 1;
            var_a1 = func_8023D380_de(&frame.sp18);
            __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
            __builtin_memcpy(&frame.sp68, &frame.sp1B0, 12);
            __builtin_memcpy(&frame.sp8C, &frame.sp1BC, 12);
        } else {
            __builtin_memcpy(&frame.sp5C, &frame.sp68, 12);
        }
        var_s0 -= 1;
        if (var_a1 == 0) {
        } else if (var_s0 != 0) {
            goto loop_34;
        }
        __builtin_memcpy(&arg0->x, &frame.sp5C, 12);
        __builtin_memcpy(&arg0->room, &frame.sp8C, 12);
        frame.sp54 &= ~4;
        if (*arg4 & 0x40000) {
            __builtin_memcpy(&frame.sp68, &frame.sp5C, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            savedY = frame.sp6C;
            dropDistance = D_800C3798_de;
            frame.sp6C = savedY - dropDistance;
            __builtin_memcpy(&frame.sp2A8, &D_801000F0, sizeof(D_801000F0));
            frame.sp58 = &frame.sp2A8;
            temp_v1_2 = frame.sp2A8 & 0xFFE7FFF7;
            frame.sp2A8 = temp_v1_2;
            frame.sp2A8 = temp_v1_2 | (*arg4 & 0x180008);
            frame.sp50 = 0;
            func_8023E838_de(&frame.sp18);
            arg0->contactX = 0.0f;
            arg0->contactZ = 0.0f;
            arg0->contactBits = D_800C379C_de;
            arg0->groundY = (f32) (arg0->y - dropDistance);
loop_49:
            if (func_8023D158_de((s8 *) &frame.sp18) != 0) {
                if (frame.spD0 == 7) {
                    frame.sp3C = 0;
                }
                func_8023D380_de(&frame.sp18);
                var_a1_3 = 0;
                arg0->groundY = frame.sp19C;
                __builtin_memcpy(&arg0->contactX, &frame.sp110, 12);
                actorY = arg0->y;
                hitY = frame.sp19C;
                var_f2 = actorY - hitY;
                if ((frame.sp3C != 0) && (var_f2 < D_800C37A0_de)) {
                    frame.sp3C = 0;
                    arg0->velY = 0.0f;
                    var_f2 = arg0->velY;
                    arg0->y = hitY;
                }
                if ((arg0->velY <= 0.0f) && (var_f2 < D_800C37A4_de)) {
                    if (frame.spC8 == 5) {
                        frame.sp54 |= 0x2004;
                        func_8023EC54_de(&frame.sp18, &frame.spC8);
                        var_a1_3 = 1;
                        *frame.sp58 &= ~8;
                    } else {
                        if (frame.spC8 < 5) goto no_attach;
                        if (frame.spC8 >= 0xA) goto no_attach;
                        if (frame.spC8 < 7) goto no_attach;
                        if (frame.sp11C->type != 1) goto no_attach;
                        attachedActor = frame.sp11C;
                        arg0->attached = attachedActor;
                        temp_v1_3 = attachedActor->flags;
                        attachedActor->flags = (s32) (temp_v1_3 | 0x20);
                        if (frame.sp1C != 0) {
                            attachedActor->flags = (s32) (temp_v1_3 | 0x60);
                        }
                        var_v0_2 = (frame.sp54 & ~3) | 2;
                        goto attach_done;
no_attach:
                        var_v0_2 = frame.sp54 | 4;
attach_done:
                        frame.sp54 = var_v0_2;
                    }
                }
                if (var_a1_3 != 0) {
                    __builtin_memcpy(&frame.sp5C, &frame.sp198, 12);
                    goto block_71;
                }
            } else {
                var_a1_3 = 0;
block_71:
                if (var_a1_3 == 0) {

                } else {
                    goto loop_49;
                }
            }
        }
        temp_a0 = frame.sp54;
        frame.sp54 = temp_a0 & ~0x100;
        if ((frame.sp38 != 0) || (temp_a0 & 0x80)) {
            __builtin_memcpy(&frame.sp5C, &arg0->x, 12);
            __builtin_memcpy(&frame.sp68, &arg0->x, 12);
            frame.sp44 = 0;
            frame.sp48 = 0;
            frame.sp4C = 0;
            frame.sp58 = &D_801000F0.flags;
            frame.sp68 -= temp_f22_2 * D_800C37A8_de;
            frame.sp70 -= temp_f0 * D_800C37A8_de;
            func_8023E838_de(&frame.sp18);
            if ((func_8023D158_de((s8 *) &frame.sp18) != 0) && (frame.spC8 == 4)) {
                if (frame.sp38 != 0) {
                    func_8023D380_de(&frame.sp18);
                    arg0->x = frame.sp198;
                    arg0->z = frame.sp1A0;
                    frame.sp54 |= 0x100;
                    func_8023EBFC_de(&frame.sp18, &frame.spC8);
                    if (arg0->type == 1) {
                        func_80274870_de(&frame.sp2C8, frame.sp2C8 - func_80273F94_de(frame.sp2C8, func_802417C4_de((f32 *) &frame.spC8)), 0.9f);
                        arg0->angle = frame.sp2C8;
                    }
                }
            } else {
                frame.sp54 &= ~0x80;
            }
        }
        if (*arg4 & 0x80000) {
            temp_s0 = func_8028C050_de(frame.spC4, &arg0->x);
            frame.sp54 &= ~0x5000;
            if ((temp_s0 != 0) && ((((Func80243A80Collision *)temp_s0)->flags & 0x41) == 0x41) && (func_80275DD4_de(temp_s0, arg0->x, arg0->z) <= arg0->y)) {
                temp_f0_2 = func_8027525C_de(temp_s0, arg0->x, arg0->z);
                if (arg0->y <= temp_f0_2) {
                    frame.sp54 |= 0x4000;
                }
                temp_f0_2 += frame.sp34;
                if (arg0->y <= temp_f0_2) {
                    frame.sp54 |= 0x1000;
                }
                func_8023ECBC_de(&frame.sp18, temp_s0);
            }
            arg0->collision = temp_s0;
        }
        arg0->flags = frame.sp54;
        return var_s3;
    }
    return 0;
}
