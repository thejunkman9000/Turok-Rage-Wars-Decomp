/* their2 */
/* Port of func_8044D0F0_de.c of the other decompilation (CC0): func_0044DD40 + func_0044DDC8 + func_0044DE04 + func_0044DE70, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern char D_800CA1BC[],D_800F81F0[];
extern s32 func_00285130(s32 a, s32 b);      /* resource callback (callee defined in src/game/func_00285130.c) */
extern int func_00264B8C(void);
extern int *func_002518DC(int,int,int,int,int,int,void *,void *,int);
extern void *func_002C2490(void *,const void *,int); /* memcpy: keep the neutral name, a builtin-typed memcpy declaration is expanded inline */
extern void func_002537D8(int,int *),func_0044E178(State_func_8044D0F0_de *,int,int);
void func_0044DD40(State_func_8044D0F0_de *state) {
 int *resource;
 int id;
 if(func_00264B8C()==0) {
  resource=func_002518DC(0,state->resource,state->resource,state->bank,0,0,(void *)func_00285130,D_800CA1BC,1);
  func_002C2490(D_800F81F0,(const void *)*resource,0x5000);
  func_002537D8(0,resource);
 }
}

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern int func_00264B8C(void);
extern int *func_002518DC(int,int,int,int,int,int,void *,void *,int);
extern void func_002537D8(int,int *);
extern void func_0044E178(State_func_8044D0F0_de *,int,int);


void func_0044DDC8(State_func_8044D0F0_de *state,int selection) {
 if(selection!=state->selection) {
  state->changed=0;
  func_0044E178(state,~selection,0);
 }
}

/* Resets part of a large state block: sets its word at offset 0x1B410 to 2 and clears the words
   at 0x1B414 to 0x1B41C and 0x1B434 to 0x1B440. */
void func_0044DE04(char *state) {
    ((func_8044DE04_S1 *)(state))->unk1B410 = 2;
    ((func_8044DE04_S1 *)(state))->unk1B414 = 0;
    ((func_8044DE04_S1 *)(state))->unk1B418 = 0;
    ((func_8044DE04_S1 *)(state))->unk1B41C = 0;
    ((func_8044DE04_S1 *)(state))->unk1B434 = 0;
    ((func_8044DE04_S1 *)(state))->unk1B438 = 0;
    ((func_8044DE04_S1 *)(state))->unk1B43C = 0;
    ((func_8044DE04_S1 *)(state))->unk1B440 = 0;
}

/* Copies up to max of a track's placed objects whose key matches into out: finds the key's index range in the track's sorted key table through func_00265570, queues each object in that range of the given kind (any kind for -1) on a local list through func_00255C40 and func_00255C58, then takes them back off through func_00256130 and func_00255E78, copying each 20-byte object, and returns how many were copied. */

extern void func_00255C40(IntrusiveList *list, s32 prevOffset, s32 nextOffset);
extern s32 *func_0028FD94(s32, s32);
extern s32 func_00265570(s32 *, s32, s32, s32 *, s32 *);
extern void func_00255C58(List_func_8044D220_de *, Node_func_8044D220_de *);
extern Node_func_8044D220_de *func_00256130(List_func_8044D220_de *);
extern void func_00255E78(List_func_8044D220_de *, Node_func_8044D220_de *);

s32 func_0044DE70(Track_func_8044D220_de *track, s32 kind, s32 key, Object_func_8044D220_de *out, s32 max) {
    List_func_8044D220_de list;
    Node_func_8044D220_de nodes[64];
    s32 first;
    s32 last;
    s32 found;
    s32 *keys;
    Object_func_8044D220_de *objects;
    Node_func_8044D220_de *node;
    s32 i;
    s32 match;
    s32 count;

    found = 0;
    count = (keys = func_0028FD94(track->resource, 0))[1];
    keys += 2;
    objects = (Object_func_8044D220_de *)(func_0028FD94(track->resource, 1) + 2);
    if (func_00265570(keys, count, key, &first, &last) != 0) {
        func_00255C40(&list, 4, 8);
        node = nodes;
        for (i = first; i <= last; i++) {
            match = 1;
            if (kind != -1) {
                match = objects[i].kind == kind;
            }
            if (match) {
                node->index = i;
                func_00255C58(&list, node);
                node++;
            }
        }
        for (max--; max != -1; max--) {
            if (list.count == 0) {
                return found;
            }
            node = func_00256130(&list);
            out[found++] = objects[node->index];
            func_00255E78(&list, node);
        }
    }
    return found;
}
