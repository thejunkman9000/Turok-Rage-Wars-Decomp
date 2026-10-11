/* their2 */
/* Port of func_8044BE04_de.c of the other decompilation (CC0): func_0044CA54 + func_0044CBE0 + func_0044CD58, symbols renamed to US v1.1 names. */
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_8025E280.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
#include "stddef.h"

extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
extern s32 func_00255CB4(IntrusiveList *list, void *node);
extern void func_0025E20C(s32 arg0);
extern void func_0025E488();
/* Loads a scene's light into the global light D_800D0EE0: copies the ambient and directional colours from the scene's light settings (bytes 0xD and 0xA) into both colour copies and the direction bytes from 0x11, then scales the direction to 127.0f in length through func_002BC380 and func_0027200C and stores it as shorts at 0x1B2B4 of the scene. */
extern u8 D_800D0EE0[];
extern u8 D_800D0EE4[];
extern u8 D_800D0EEC[];
extern u8 D_800D0EF0[];
extern f32 func_002BC380(f32);
extern void func_0027200C(f32 *, f32 *, f32);
void func_0044CA54(Scene_func_8044BE04_de *scene) {
    s32 i;
    u8 c;
    f32 v[3];
    f32 length;
    u8 *light;
    for (i = 0; i < 3; i++) {
        c = scene->light->ambient[i];
        light = D_800D0EE0;
        light[i] = c;
        D_800D0EE4[i] = c;
        c = scene->light->color[i];
        light[i + 8] = c;
        D_800D0EEC[i] = c;
        D_800D0EF0[i] = scene->light->dir[i];
    }
    v[0] = scene->light->dir[0];
    v[1] = scene->light->dir[1];
    v[2] = scene->light->dir[2];
    length = func_002BC380(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (length != 0.0f) {
        func_0027200C(v, v, 127.0f / length);
        scene->dir[0] = v[0];
        scene->dir[1] = v[1];
        scene->dir[2] = v[2];
    }
}
int func_0022A404(void *);
void func_002537D8(void *, void *);
void func_00254784(void *);
void func_00255E78(void *, s32);
void func_0025CC0C(void *);
s32 * func_0025CC8C(void);
void func_0028D578(void *);
void func_0044ACCC(void *);
extern s32 D_80145040;
/* Shut down the subsystem, free its owned resources, and unlink its list. */
void func_0044CBE0(func_8044CBE0_S1 *arg0) {
    s32 temp_v0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s1;
    func_8020D0CC_S2 *var_a1;
    temp_v0 = func_0022A404(&D_80145040);
    if (temp_v0 != 0) {
        func_0044ACCC((void *) temp_v0);
    }
    func_0025CC0C(func_0025CC8C());
    func_0025E488();
    func_0025E20C(0x1000);
    func_002537D8(NULL, arg0->unk100);
    func_002537D8(NULL, arg0->unkB8);
    func_002537D8(NULL, arg0->unkBC);
    func_002537D8(NULL, arg0->unkC0);
    func_002537D8(NULL, arg0->unkC4);
    func_002537D8(NULL, arg0->unkC8);
    func_002537D8(NULL, arg0->unkD0);
    func_002537D8(NULL, arg0->unkD4);
    func_002537D8(NULL, arg0->unkEC);
    func_002537D8(NULL, arg0->unkCC);
    func_002537D8(NULL, arg0->unkE8);
    temp_a1 = arg0->unkF0;
    if (temp_a1 != NULL) {
        func_002537D8(NULL, temp_a1);
    }
    temp_a1_2 = arg0->unkF4;
    if (temp_a1_2 != NULL) {
        func_002537D8(NULL, temp_a1_2);
    }
    temp_a1_3 = arg0->unkFC;
    if (temp_a1_3 != NULL) {
        func_002537D8(NULL, temp_a1_3);
    }
    func_0028D578(arg0);
    temp_s1 = arg0->unk1B500.head;
    var_a1 = temp_s1;
    if (temp_s1 != NULL) {
        do {
            temp_s0 = var_a1->unk10;
            func_00255E78(&arg0->unk1B500, (s32) var_a1);
            var_a1 = temp_s0;
        } while (var_a1 != NULL);
    }
    func_00254784(temp_s1);
}
/* Binds a loaded collision mesh to the world: records the vertex, face and edge lists from the
   node's four chunks with their counts, resets the two bucket lists and files the 48 buckets into
   the second, then for every face of both lists clears the solid bit when it is hidden and marks it
   0xF0 when its group bit is set in the current group's bitmap. */
extern s32 func_00285150(void ***handle, s32 arg1);
extern void *func_0028FD94(void *node, s32 index);
extern void func_0028FDD8(void *node, s32 arg1);
static inline s32 groupHas(World_func_8044C108_de *world, s32 n) {
    s32 index;
    void *g;
    u8 *bits;
    s32 mask;
    index = world->group;
    g = func_0028FD94(func_0028FD94(func_0028FD94(world->tree, 0), index), 2);
    func_0028FD94(g, 0);
    func_0028FDD8(g, 1);
    bits = func_0028FD94(g, 1);
    mask = 1 << (n & 7);
    return bits[n / 8] & mask;
}
void func_0044CD58(World_func_8044C108_de *world, void ***handle) {
    void *node;
    struct Shape_func_802764D4_de_2 *l0;
    struct Shape_func_802764D4_de_2 *l1;
    struct Shape_func_802764D4_de_2 *l2;
    struct Shape_func_802764D4_de_2 *l3;
    s32 k;
    s32 i;
    s32 n;
    s32 count;
    Face *face;
    if (func_00285150(handle, 0) != 0) {
        node = **handle;
        l0 = func_0028FD94(node, 0);
        l1 = func_0028FD94(node, 1);
        l2 = func_0028FD94(node, 2);
        l3 = func_0028FD94(node, 3);
        count = l0->field_4;
        world->verts = &((func_8020CC0C_S1 *)(l0))->unk8;
        world->faces = &((func_8044CD58_S2 *)(l1))->unk8;
        world->nfaces = count;
        count = l2->field_4;
        world->edgeData = &((func_8020CC0C_S1 *)(l2))->unk8;
        world->edges = &((func_8044CD58_S2 *)(l3))->unk8;
        world->nedges = count;
        func_00255C40(&world->listA, 0, 4);
        func_00255C40(&world->listB, 0, 4);
        for (k = 0; k < 0x30; k++) {
            func_00255CB4(&world->listB, &world->buckets[k]);
        }
        n = world->nfaces;
        for (i = 0; i < n; i++) {
            face = &world->faces[i];
            if (face->hidden != 0) {
                face->flags &= 0xFE;
            }
            if (groupHas(world, face->group)) {
                face->flags |= 0xF0;
            }
        }
        n = world->nedges;
        for (i = 0; i < n; i++) {
            face = &world->edges[i];
            if (face->hidden != 0) {
                face->flags &= 0xFE;
            }
            if (groupHas(world, face->group)) {
                face->flags |= 0xF0;
            }
        }
    }
}
