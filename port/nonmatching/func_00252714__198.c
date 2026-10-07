#include "b12_types.h"


extern u8 D_80105120[];
extern u8 D_80104570[];
extern u8 D_80104584[];
extern u8 D_801051A0[];
extern B12Node *D_80104568;
extern B12Node **D_80104564;
extern s32 D_8010513C;
extern u32 D_80105190;
extern B12Bucket *D_80105194;
void func_00255E78(void *l, void *n);
void func_00255C58(void *l, void *n);
void func_00254E28(s32 a, void *n);
void func_00255354(u32 key, void *n);
void func_00255428(u32 a, u32 key);
void func_00255ACC(void *heap, s32 key);

inline void hashFind(u32 key, B12Ent ***out) {
    B12Bucket *b = &D_80105194[((key << 5) ^ (key >> 1) ^ (key >> 9) ^ (key >> 17)) & D_80105190];
    if (b->unk0 == key) {
        *out = (B12Ent **)b->unk4;
        return;
    }
    *out = 0;
    for (; b; b = b->next) {
        if (b->unk0 == key) {
            *out = (B12Ent **)b->unk4;
            break;
        }
    }
}

B12Ent *func_00252714(s32 unused, B12Ent *m, s32 flag) {
    B12Ent *res;
    B12Node *n;
    B12Node *q;
    u32 key;
    func_00255E78(D_80105120, m);
    func_00255C58(D_80105120 - 0x14, m);
    if (m->node != 0) {
    key = m->key;
    hashFind(key, (B12Ent ***)&res);
    if (res) {
        if (res->stamp < m->stamp) {
            func_00255428(res->key, key);
            res->node->link = 0;
            if (!(res->node->flags & 0x702)) {
                func_00255ACC(D_801051A0, res->node->key);
                n = res->node;
                func_00255E78(D_80104570, n);
                if (n->flags & 0x1000) {
                    func_00255E78(D_80104584, n);
                }
                if (D_80104568 == n) {
                    D_80104568 = 0;
                }
                *(u32 *)((u8 *)n + 0xC) = 0;
                {
                    B12Node **tab = D_80104564;
                    *(B12Node **)((u8 *)tab + D_8010513C * 4) = n;
                }
                D_8010513C++;
            }
            func_00254E28(0, res);
        } else {
            func_00255ACC(D_801051A0, m->node->key);
            n = m->node;
            func_00255E78(D_80104570, n);
            if (n->flags & 0x1000) {
                func_00255E78(D_80104584, n);
            }
            if (D_80104568 == n) {
                D_80104568 = 0;
            }
            *(u32 *)((u8 *)n + 0xC) = 0;
            {
                B12Node **tab = D_80104564;
                *(B12Node **)((u8 *)tab + D_8010513C * 4) = n;
            }
            D_8010513C++;
            func_00254E28(0, m);
            return res;
        }
    }
    func_00255354(m->key, m);
    m->node->link = (B12Node *)m;
    if (flag) {
        q = m->node;
        q->refs--;
        if (q->refs == 0) {
            q->flags &= ~0x100;
        }
    }
    return m;
    }
    func_00254E28(0, m);
    return 0;
}
