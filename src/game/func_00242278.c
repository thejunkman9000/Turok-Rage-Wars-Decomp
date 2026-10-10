#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"













extern char D_80100338;

extern void func_80241950_de(Owner_func_80241BAC_de *, Bounds *, Actor_func_80242288_de *, Owner_func_80241BAC_de *);
extern s32 func_8023E178_de(Actor_func_80242288_de *, void *, f32, s32, f32, s32, s32 *, s32);
extern s32 func_8023EA44_de(Actor_func_80242288_de *, s32 *, void *, f32, s32);
extern s32 func_8023E8D4_de(Actor_func_80242288_de *, s32 *, s32);
extern void func_80240D20_de(s32 *, Bounds *);
extern void func_80240E00_de(s32 *, Bounds *);
extern void func_80240EE0_de(s32 *, Bounds *);
extern void func_80240FC0_de(s32 *, Bounds *);
extern void func_802410A0_de(s32 *, Bounds *);
extern void func_80241180_de(s32 *, Bounds *);








void func_80242288_de(Actor_func_80242288_de *actor, Owner_func_80241BAC_de *owner) {
    Query_func_80242288_de query;
    Bounds bounds;
    Entry_func_80242288_de *entry;

    entry = &((EntryBlock *)owner->entries)->entry;
    if ((actor->field40 != &D_80100338) && (((func_80242278_S1 *)(actor->field40))->unk4 != 0)) {
        f32 value;
        s32 *word;
        void *owner_data;

        func_80241950_de(owner, &bounds, actor, actor->owner);
        query.word4 = 0;
        query.word8 = 2;
        query.wordC = 0;
        query.word10 = 0;
        query.owner = owner;
        query.index = -1;
        switch (entry->kind) {
        case 1:
            word = &query.word0;
            owner_data = &((func_80242278_S2 *)(owner))->unk8;
            value = ((EntryBlock *)owner->entries)->entry.value + actor->fieldC;
            if ((actor->field5C != *(f32 *)&query.word4) ||
                (actor->field64 != *(f32 *)&query.word4)) {
                *word = 3;
                func_8023E178_de(actor, owner_data, value, ((func_80241F14_S3 *)(&bounds))->unk4,
                              ((func_80241F14_S3 *)(&bounds))->unk34, 1, word, 1);
            }
            if (actor->field60 > 0.0f) {
                *word = 2;
                func_80240E00_de(word, &bounds);
                func_8023EA44_de(actor, word, owner_data, value, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                func_80240D20_de(word, &bounds);
                func_8023EA44_de(actor, word, owner_data, value, 1);
                return;
            }
            break;
        case 2:
        {
            f32 movement;
            f32 zero;

            word = &query.word0;
            movement = actor->field60;
            zero = *(f32 *)&query.word4;
            if (zero < movement) {
                *word = 2;
                func_80240E00_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            if ((actor->field5C != zero) || (actor->field64 != zero)) {
                *word = 3;
                func_80240EE0_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                func_80240FC0_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                func_802410A0_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
                func_80241180_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            if (actor->field60 < 0.0f) {
                *word = 9;
                func_80240D20_de(word, &bounds);
                func_8023E8D4_de(actor, word, 1);
            }
            break;
        }
        }
    }
}
