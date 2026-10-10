#include "span_1000/code_8024D018.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024D018.h"
#include "types.h"
#include "math_helpers.h"

/* Returns a player's body lean on the ground: a controlled player on an accepted floor (func_802757E4_de) that
 * is not held (flag 1) nor in states 1 or 2 computes a tilt toward the floor normal from func_80275C94_de by
 * three eighths of its slope (at most 25 degrees), which the body tilt from func_8024D728_de then replaces,
 * and leans along its heading by three quarters of the ground slope ahead from func_80240A98_de (at most 25),
 * blending lean and tilt halfway through func_80270CD0_de; other players take func_8024D728_de's tilt, and
 * objects without a floor or held players get the identity. The sine is kept in D_80115DEC. */

extern f32 D_80115DEC;
extern s32 func_802757E4_de(s32);
extern void func_80275C94_de(Vec3 *, s32);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);



extern Vector4f func_8024D728_de(char *);
extern f32 func_80240A98_de(Probe *, f32, f32, f32, f32);
extern void func_80270CD0_de(Vector4f *, f32, Vector4f *, Vector4f *);
static inline s32 is_held(char *obj) {
    return (*(u8 *)obj != 1) ? 0 : (((func_8024D860_S1 *)(obj))->unk100 & 1);
}

Vector4f func_8024D870_de(char *obj) {
    Vec3 normal;
    Vec3 up;
    Vec3 axis;
    Vector4f tilt;
    Vector4f lean;
    Vector4f result;
    Probe probe;
    f32 slope;
    f32 sine;
    f32 cosine;
    f32 angle;
    f32 half;
    char *self;

    if (((func_8024D860_S1 *)(obj))->unk14 != 0 && is_held(obj) == 0) {
        if (*(u8 *)obj == 1) {
            self = obj;
            if (((func_8024D860_S1 *)(obj))->unk38 & 3) {
                goto identity;
            }
            if (((func_8024D860_S1 *)(obj))->unk100 & 0x300000) {
                if (func_802757E4_de(((func_8024D860_S1 *)(obj))->unk14) != 0) {
                    goto identity;
                }
                func_80275C94_de(&normal, ((func_8024D860_S1 *)(obj))->unk14);
                up.x = 0.0f;
                up.y = 1.0f;
                up.z = 0.0f;
                func_80272018_de(&axis, &up, &normal);
                func_8027207C_de(&axis);
                slope = func_802745D0_de(up.x * normal.x + up.y * normal.y + up.z * normal.z);
                D_80115DEC = func_802B7130_de(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt.x = axis.x * D_80115DEC;
                tilt.y = axis.y * D_80115DEC;
                tilt.z = axis.z * D_80115DEC;
                tilt.w = func_802B6560_de(RW_MIN(slope, 0.43633235f) * 0.375f);
                tilt = func_8024D728_de(obj);
                sine = func_802B7130_de(((func_8024D860_S2 *)(self))->unk6C);
                cosine = func_802B6560_de(((func_8024D860_S2 *)(self))->unk6C);
                probe.dir = ((func_8024D860_S2 *)(self))->unk44;
                probe.start.x = ((func_8024D860_S2 *)(self))->unk8;
                probe.start.y = ((func_8024D860_S2 *)(self))->unk40;
                probe.start.z = ((func_8024D860_S2 *)(self))->unk10;
                slope = func_80240A98_de(&probe, ((func_8024D860_S1 *)(obj))->unk8, ((func_8024D860_S1 *)(obj))->unk10, ((func_8024D860_S1 *)(obj))->unk8 - sine,
                                      ((func_8024D860_S1 *)(obj))->unk10 - cosine);
                slope = RW_MIN(slope, 25.0f) * 0.75f;
                half = 0.5f;
                angle = slope * half;
                D_80115DEC = func_802B7130_de(angle);
                lean.y = 0.0f;
                lean.x = cosine * D_80115DEC;
                lean.z = -sine * D_80115DEC;
                lean.w = func_802B6560_de(angle);
                func_80270CD0_de(&result, half, &lean, &tilt);
                return result;
            }
        }
        return func_8024D728_de(obj);
    }
identity:
    tilt.x = tilt.y = tilt.z = 0.0f;
    tilt.w = 1.0f;
    return tilt;
}
