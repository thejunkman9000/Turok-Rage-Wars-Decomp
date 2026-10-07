#include "b13_types.h"

void func_00258760(SndMgr *m);
void func_002587C4(SndMgr *m);
s32 func_0025E520(SndInfo *i);
s32 func_0025E52C(SndInfo *i);
s32 func_0025E538(SndInfo *i);
s32 func_0025E568(SndInfo *i);
s32 func_0025E574(SndInfo *i);
s32 func_0025E598(SndInfo *i);
void func_0025BB9C(SndVoice *v, s32 tag);
void func_0025BBA4(SndVoice *v, SndInfo *info, s32 flags);

s32 func_00259280(SndQueue *q, SndInfo *info, Vec3f *pos, s32 a3, s32 flags) {
    SndLink *l;
    SndNode *n;
    SndLink *c;
    SndVoice *b;
    s32 pri;
    if (q->free.link.next != &q->free.link) {
        func_00258760(q->owner);
        l = q->free.link.next;
        l->prev->next = l->next;
        l->next->prev = l->prev;
        n = (SndNode *)l;
        n->body.unkC = q->owner->unk108++;
        n->body.unk4 = a3;
        n->body.unk40 = -1;
        n->body.unk3C = a3;
        n->body.unk3A = func_0025E520(info);
        n->body.unk38 = (s8)func_0025E538(info);
        n->body.unk14 = (s16)func_0025E52C(info);
        n->body.unk54 = func_0025E568(info);
        n->body.unkA4 = (s16)func_0025E598(info);
        n->body.unk20 = (s8)func_0025E574(info);
        n->body.unk1C = 0x7D00;
        n->body.unk18 = 0x7D00;
        n->body.unk24 = 0;
        n->body.unk10 = q->owner->unk104;
        n->body.pos = *pos;
        n->body.unk50 = 0;
        n->body.unkAC = 0;
        b = &n->body;
        func_0025BB9C(b, q->owner->unk2B8C);
        n->body.unkC0 = q->owner->unk2BAC;
        func_0025BBA4(b, info, flags);
        pri = n->body.unk38;
        for (c = q->active.link.next; c != &q->active.link; c = c->next) {
            if (((SndNode *)c)->body.unk38 < pri) {
                break;
            }
        }
        n->link.prev = c->prev;
        n->link.next = c;
        c->prev->next = &n->link;
        c->prev = &n->link;
        func_002587C4(q->owner);
        return n->body.unkC;
    }
    return -1;
}
