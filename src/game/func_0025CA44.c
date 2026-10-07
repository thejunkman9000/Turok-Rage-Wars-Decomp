#include "b13_types.h"

typedef struct SndListNode SndListNode;
struct SndListNode { u8 pad0[4]; SndListNode *next; s32 id; s32 unkC; };
typedef struct SndPlaylist { u8 pad0[0x14]; SndListNode *head; u8 pad18[0x10]; s32 unk28; } SndPlaylist;

extern s32 D_800D0D54;

void func_0025E194(s32 id);
void func_00255E78(void *list, void *node);
void func_00255CB4(void *pl, void *node);

s32 func_0025CA44(SndPlaylist *l, SndListNode *target) {
    SndListNode *n;
    if (target == 0) {
        return 0;
    }
    for (n = l->head; n != 0; n = n->next) {
        if (n == target) {
            func_0025E194(n->id);
            D_800D0D54 = n->id;
            func_00255E78(&l->head, n);
            func_00255CB4(l, n);
            return 1;
        }
    }
    return 0;
}
