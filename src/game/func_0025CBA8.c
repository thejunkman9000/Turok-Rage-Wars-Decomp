#include "b13_types.h"

typedef struct SndListNode SndListNode;
struct SndListNode { u8 pad0[4]; SndListNode *next; s32 id; s32 unkC; };
typedef struct SndPlaylist { u8 pad0[0x14]; SndListNode *head; u8 pad18[0x10]; s32 unk28; } SndPlaylist;

s32 func_0025E114(s32 id);

void func_0025CBA8(SndPlaylist *l) {
    SndListNode *n;
    if (l->unk28 == 0) {
        for (n = l->head; n != 0; n = n->next) {
            if (func_0025E114(n->id) == 0) {
                n->unkC = -1;
                n->id = -1;
            }
        }
    }
}
