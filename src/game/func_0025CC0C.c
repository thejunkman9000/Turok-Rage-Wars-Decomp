#include "b13_types.h"

typedef struct SndListNode SndListNode;
struct SndListNode { u8 pad0[4]; SndListNode *next; s32 id; s32 unkC; };
typedef struct SndPlaylist { u8 pad0[0x14]; SndListNode *head; u8 pad18[0x10]; s32 unk28; } SndPlaylist;

void func_0025E194(s32 id);
void func_00255E78(void *list, void *node);
void func_00255CB4(void *pl, void *node);

void func_0025CC0C(SndPlaylist *l) {
    SndListNode *n;
    SndListNode *next;
    for (n = l->head; n != 0; n = next) {
        next = n->next;
        func_0025E194(n->id);
        n->unkC = -1;
        n->id = -1;
        func_00255E78(&l->head, n);
        func_00255CB4(l, n);
    }
}
