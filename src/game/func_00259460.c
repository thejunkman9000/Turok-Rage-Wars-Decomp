#include "b13_types.h"

void *memcpy_call(void *dst, const void *src, u32 n) __asm__("memcpy");

void func_00258760(SndMgr *m);
void func_002587C4(SndMgr *m);
s32 func_0025B054(SndVoices *p, s16 a, s16 b, s16 c, s32 d);
s16 alSndpAllocate(void *p, s32 snd);
void func_00257814(SndMgr *m, s32 id, s32 a, Vec3f *pos);

void func_00259460(SndQueue *q) {
    s16 *ids;
    void *player;
    u8 *bank;
    SndNode *n;
    SndLink *next;
    SndVoice *v;
    s16 idx;
    s32 old;
    func_00258760(q->owner);
    ids = q->owner->snd;
    player = q->owner->player;
    bank = (u8 *)q->owner->unk7C[3];
    for (n = (SndNode *)q->active.link.next; n != &q->active; n = (SndNode *)next) {
        next = n->link.next;
        if (n->body.unk14 != 0) {
            if (--n->body.unk14 == 0) {
                n->body.unk10 = q->owner->unk104;
                n->body.unk40 = q->owner->unk108++;
                n->body.unkA0 = 0;
            }
            continue;
        }
        if (q->owner->unk104 - n->body.unk10 >= 0x10) {
            n->link.prev->next = next;
            n->link.next->prev = n->link.prev;
            SndLink_AddTail(&q->free.link, &n->link);
        } else {
            idx = func_0025B054(&q->owner->pool, n->body.unk3C, n->body.unk3A, n->body.unk38, 0);
            if (idx == -1 || idx == 16) {
                break;
            }
            old = ids[idx];
            if (old != -1) {
                break;
            }
            ids[idx] = alSndpAllocate(player, *(s32 *)(bank + (n->body.unk3A << 2) + 0x10));
            if (ids[idx] == old) {
                break;
            }
            v = (SndVoice *)((u8 *)q->owner + 0x1DBC + idx * 0xCC);
            memcpy_call(v, &n->body, 0xCC);
            v->unkC = n->body.unk40;
            v->unk8 = ids[idx];
            v->unk10 = q->owner->unk104;
            v->idx = idx;
            func_00257814(q->owner, v->unkC, 0, &v->pos);
            n->body.unk40 = old;
            n->body.unk38 = old;
            n->link.prev->next = n->link.next;
            n->link.next->prev = n->link.prev;
            SndLink_AddTail(&q->free.link, &n->link);
        }
    }
    func_002587C4(q->owner);
}
