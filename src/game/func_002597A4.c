#include "b13_types.h"

void *memcpy_call(void *dst, const void *src, u32 n) __asm__("memcpy");

void func_002597A4(SndQueue *q, s32 idx, s32 a2, Vec3f *pos) {
    SndVoice *src;
    SndNode *n;
    SndLink *l;
    SndLink *c;
    s32 pri;
    src = (SndVoice *)((u8 *)q->owner + 0x1DBC + idx * 0xCC);
    if (src->unkAC == 0) {
        l = q->free.link.next;
        if (l != &q->free.link) {
            l->prev->next = l->next;
            l->next->prev = l->prev;
            n = (SndNode *)l;
            memcpy_call(&n->body, src, 0xCC);
            n->body.unk40 = a2;
            n->body.pos.x = pos->x;
            n->body.pos.y = pos->y;
            n->body.pos.z = pos->z;
            n->body.unk14 = 0;
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
        }
        ((SndMgrQ *)q->owner)->unk2AB4 = 0;
        ((SndMgrQ *)q->owner)->unk2AB6 = -1;
        ((SndMgrQ *)q->owner)->unk2A88 = -1;
        ((SndMgrQ *)q->owner)->unk2A84 = -1;
    }
}
