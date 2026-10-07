#include "b13_types.h"

typedef struct SndListNode SndListNode;
struct SndListNode { u8 pad0[4]; SndListNode *next; s32 id; s32 unkC; };
typedef struct SndPlaylist { u8 pad0[0x14]; SndListNode *head; u8 pad18[0x10]; s32 unk28; } SndPlaylist;

extern s32 D_800D0D58;

void func_0025E194(s32 id);

void func_0025CAD0(SndPlaylist *l) {
    SndListNode *n;
    for (n = l->head; n != 0; n = n->next) {
        func_0025E194(n->id);
        D_800D0D58 = n->id;
    }
    l->unk28 = 1;
}
