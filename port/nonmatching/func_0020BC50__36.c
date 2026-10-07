#include "b02_types.h"

void func_0020D1FC(B2Mgr *m);
void func_0020D220(B2Mgr *m, s32 key);
void func_0020EC14(B2Ctl *ctl);
void func_0020C5A0(B2Mgr *m, B2Node *n);
extern f32 D_800C6E58;
extern f32 D_800C6E5C;

static inline s32 getVal(B2Mgr *m, s32 i, s32 j) {
    B2Pool *pool = m->unk10;

    return (&pool->data[0] + (i * m->unk4 + j) * pool->elemSize)[0];
}

static inline void *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return &pool->data[idx * pool->elemSize];
}

static inline B2Node *find(B2Mgr *m, s32 key) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->id == key) {
            return n;
        }
    }
    return NULL;
}

void func_0020BC50(B2Mgr *m, s32 from, s32 to, B2Ctl *ctl) {
    B2Node *n;
    s32 i;
    s32 cnt;
    u8 *r;

    for (n = m->head; n != NULL; n = n->next) {
        n->unk4 = D_800C6E58;
        n->unk8 = -1;
        n->unk18 = 0;
        n->unk1C = 0;
        n->unk20 = 0;
        n->unk24 = 0;
        n->unk28 = 0;
        n->unk2C = 0;
        n->link30 = NULL;
    }
    m->unk20 = -1;
    m->unk1C = D_800C6E5C;
    func_0020D1FC(m);
    cnt = 0;
    func_0020EC14(ctl);
    func_0020D220(m, to);
    for (i = 0; i < m->unk4; i++) {
        if (i != to) {
            if (getVal(m, i, to) != 0) {
                r = getRec0(m, i);
                if (r != NULL && (*(u32 *)(r + 0xC) & 0x4300000) == 0) {
                    func_0020D220(m, i);
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0) {
        for (i = 0; i < m->unk4; i++) {
            if (i != to) {
                if (getVal(m, i, to) != 0) {
                    r = getRec0(m, i);
                    if (r != NULL && (*(u16 *)(r + 0xC) & 0x400) == 0) {
                        func_0020D220(m, i);
                    }
                }
            }
        }
    }
    func_0020C5A0(m, find(m, from));
    m->unk20 = m->unk18;
}
