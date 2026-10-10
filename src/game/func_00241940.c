#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"
/* Builds the eight world-space corners of an object's collision box: the extents come from the shape at
 * 0x18 + 0x14 (half width and depth, or the radius for a cylinder of kind 1), grown by the optional
 * attachment's sizes from func_8024D398_de, func_8024D284_de and func_8024E420_de; the box is turned by the object's
 * rest matrix from 0x2A4 and its heading 0x6C composed with its orientation at 0x5C, moved to its position
 * and, for shapes flagged 1, its bottom corners are dropped to the ground height of the given floor. */







extern f32 D_80115DEC;
extern f32 func_8024D398_de(s32);
extern f32 func_8024D284_de(s32);
extern f32 func_8024E420_de(s32);


extern void func_80273648_de(f32 *, s32);
extern void func_80274098_de(Vector4f *, Vector4f *, Vector4f *);
extern void func_80274244_de(Vector4f *, f32 *);
extern void func_8026F620_de(f32 *, f32 *, f32 *);
extern void func_80273448_de(f32 *, s32, s32, s32);
extern void func_80272944_de(f32 *, Vec3 *, Vec3 *, s32);








void func_80241950_de(char *obj, Vec3 *corners, char *floor, s32 attachment) {
    f32 matrix[16];
    f32 rest[16];
    f32 turn[16];
    Vector4f yaw;
    Vector4f orient;
    Shape_func_80241950_de *shape;
    char *anim;
    f32 grow;
    f32 lift;
    f32 extra;
    f32 extentX;
    f32 extentZ;
    f32 height;
    f32 minX;
    f32 maxX;
    f32 minZ;
    f32 maxZ;
    f32 top;
    f32 bottom;
    f32 diff;
    f32 sine;
    f32 angle;

    anim = obj + 0x170;
    shape = (Shape_func_80241950_de *)(((func_80241940_S1 *)(obj))->unk18 + 0x14);
    if (attachment != 0) {
        grow = func_8024D398_de(attachment);
        lift = func_8024D284_de(attachment);
        extra = func_8024E420_de(attachment);
    } else {
        lift = 0.0f;
        grow = 0.0f;
        extra = 0.0f;
    }
    diff = extra - lift;
    if (shape->kind != 1) {
        extentX = shape->halfWidth * 0.5f + grow * 0.5f;
        extentZ = shape->halfDepth * 0.5f + grow * 0.5f;
        height = shape->height + extra;
    } else {
        extentZ = shape->radius + grow;
        height = shape->height + extra;
        extentX = extentZ;
    }
    bottom = shape->center.y + diff;
    minX = shape->center.x - extentX;
    top = shape->center.y + height;
    maxZ = shape->center.z + extentZ;
    maxX = shape->center.x + extentX;
    minZ = shape->center.z - extentZ;
    corners[0].x = minX;
    corners[0].y = top;
    corners[0].z = maxZ;
    corners[1].x = maxX;
    corners[1].y = top;
    corners[1].z = maxZ;
    corners[2].x = maxX;
    corners[2].y = top;
    corners[2].z = minZ;
    corners[3].x = minX;
    corners[3].y = top;
    corners[3].z = minZ;
    corners[4].x = minX;
    corners[4].y = bottom;
    corners[4].z = maxZ;
    corners[5].x = maxX;
    corners[5].y = bottom;
    corners[5].z = maxZ;
    corners[6].x = maxX;
    corners[6].y = bottom;
    corners[6].z = minZ;
    corners[7].x = minX;
    corners[7].y = bottom;
    corners[7].z = minZ;
    func_80273648_de(rest, ((func_80241940_S2 *)(anim))->unk134);
    sine = func_802B7130_de(((func_80241940_S1 *)(obj))->unk6C * 0.5f);
    yaw.x = 0.0f;
    yaw.y = sine;
    yaw.z = 0.0f;
    angle = ((func_80241940_S1 *)(obj))->unk6C * 0.5f;
    D_80115DEC = sine;
    yaw.w = func_802B6560_de(angle);
    func_80274098_de(&orient, &yaw, &((func_80241940_S1 *)(obj))->unk5C);
    func_80274244_de(&orient, turn);
    func_8026F620_de(matrix, rest, turn);
    func_80273448_de(matrix, ((func_80241940_S1 *)(obj))->unk8, ((func_80241940_S1 *)(obj))->unkC, ((func_80241940_S1 *)(obj))->unk10);
    func_80272944_de(matrix, corners, corners, 8);
    if (shape->flags & 1) {
        bottom = ((func_80241940_S3 *)(floor))->unk54 - ((func_80241940_S3 *)(floor))->unk10;
        lift = bottom;
        corners[4].y = bottom;
        corners[5].y = bottom;
        corners[6].y = bottom;
        corners[7].y = bottom;
    }
}
