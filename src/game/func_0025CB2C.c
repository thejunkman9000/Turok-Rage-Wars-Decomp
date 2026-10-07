#include "b13_types.h"

typedef struct SndListNode SndListNode;
struct SndListNode { u8 pad0[4]; SndListNode *next; s32 id; u8 padC[2]; s16 sndId; Vec3f pos; s32 unk1C; };
typedef struct SndPlaylist { u8 pad0[0x14]; SndListNode *head; u8 pad18[0x10]; s32 unk28; } SndPlaylist;

extern s32 D_800D0D5C;

s32 func_0025DE74(s32 id, Vec3f pos, s32 a, s32 b);

void func_0025CB2C(SndPlaylist *l) {
    SndListNode *n;
    for (n = l->head; n != 0; n = n->next) {
        n->id = func_0025DE74(n->sndId, n->pos, n->unk1C, -1);
        D_800D0D5C = n->id;
    }
    l->unk28 = 0;
}
