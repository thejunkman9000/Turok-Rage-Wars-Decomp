
#include "b12_types.h"

extern B12Mgr D_80103F70;
extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u32 D_80105190;
extern B12Bucket *D_80105194;
extern u32 D_80105180;
extern u8 D_80104570[];
extern u8 D_8010A248[];
extern u8 D_801051B8[];
extern OSMesgQueue D_801047E0;
void func_00255F58(void *list, B12Node *n);
B12Ent *func_00254E70(s32 a, s32 sz);
B12Node *func_00251448(s32 a, u32 flags);
s32 func_00254B2C(s32 a, u32 b, s32 c, u32 d);
void func_00254C10(s32 a, B12Node *n);
void func_00254A70(s32 a, B12Node *n);
void func_00255110(void *port, B12Ent *e);
B12Ent *func_00252714(s32 a, B12Ent *e, s32 b);
void func_00254E28(s32 a, B12Ent *e);
void func_00255E78(void *l, void *n);
void func_00255CB4(void *l, void *n);
void func_0025631C(void *c, s32 src, u32 total, s32 dst);
void func_002563F4(void *c, s32 src, u32 total, s32 dst, void *reply, void *msg, s32 jam);

static inline void hashFind(u32 key, B12Ent **out) {
    B12Bucket *b = &D_80105194[((key << 5) ^ (key >> 1) ^ (key >> 9) ^ (key >> 17)) & D_80105190];
    if (b->unk0 == key) {
        *out = (B12Ent *)b->unk4;
        return;
    }
    *out = 0;
    for (; b; b = b->next) {
        if (b->unk0 == key) {
            *out = (B12Ent *)b->unk4;
            break;
        }
    }
}

B12Ent **func_002518DC(s32 a0, u32 key, s32 src, u32 size, s32 e, void *owner, void *fn, void *unused, s32 flag) {
    B12Ent *sp20;
    B12Ent *ne;
    B12Ent *q;
    B12Ent *p;
    B12Ent *r;
    B12Node *n;
    B12Node *nd;
    s32 found;
    u32 fl;
    u32 m1;
    u32 m2;
    u32 m3;
    u32 m4;
    u32 m5;
    u32 m6;
    u32 m7;
    u32 m8;
    u32 m9;
    u32 fl2;
    B12Node *n2;
    m1 = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(m1);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m1);
    }
    hashFind(key, &sp20);
    if (sp20 && size >= sp20->stamp) {
        n = sp20->node;
        n->refs++;
        n->flags |= 0x100;
        n = sp20->node;
        n->unk10 = D_80105180;
        func_00255F58(D_80104570, n);
        m2 = __osDisableInt();
        if (--D_8010515C != 0) {
            __osRestoreInt(m2);
            osSendMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m2);
        }
        return (B12Ent **)sp20->node;
    }
    flag |= D_80103F70.f120C;
    if (flag == 0) {
        found = 0;
        for (p = D_80103F70.lists3[2].head; p; p = p->next) {
            if (p->key == key) {
                if (p->stamp >= size) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (flag == 0 && found != 0) goto done;
alloc:
    ne = func_00254E70(0, e);
    sp20 = ne;
    if (ne) {
        if (fn) {
            fl = (e & 0x1C) | 0x22;
        } else {
            fl = e;
        }
        sp20->dep = 0;
        nd = func_00251448(0, fl);
        if (nd) {
            nd->refs++;
            nd->flags |= 0x100;
            nd->key = func_00254B2C(0, size, (fl >> 5) & 1, fl);
            if (nd->key) {
                nd->unk4 = size;
                nd->flags |= fl;
                func_00254C10(0, nd);
            } else {
                nd->refs--;
                if (nd->refs == 0) {
                    nd->flags &= ~0x100;
                }
                func_00254A70(0, nd);
                nd = 0;
            }
        }
        sp20->node = nd;
        q = sp20;
        if (nd) {
            if (size & 1) {
                size++;
            }
            q->key = key;
            q->stamp = size;
            q->owner = owner;
            q->fn = fn;
            q->size = e;
            func_00255E78(&D_80103F70.lists3[1], q);
            func_00255CB4(&D_80103F70.lists3[2], sp20);
            if (flag != 0) {
                if (fn) {
                    sp20->flags |= 4;
                }
                m3 = __osDisableInt();
                if (--D_8010515C != 0) {
                    __osRestoreInt(m3);
                    osSendMesg(&D_80103F70.q11D0, 0, 1);
                } else {
                    __osRestoreInt(m3);
                }
                func_0025631C(D_801051B8, src, size, sp20->node->key);
                if (fn) {
                    func_00255110(D_8010A248, sp20);
                }
                m4 = __osDisableInt();
                if (++D_8010515C != 1) {
                    __osRestoreInt(m4);
                    osRecvMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m4);
                }
                if (fn) {
                    sp20->flags &= ~4;
                }
                r = func_00252714(0, sp20, 0);
                if (r && r != sp20) {
                    n2 = r->node;
                    n2->refs++;
                    n2->flags |= 0x100;
                }
                m5 = __osDisableInt();
                if (--D_8010515C != 0) {
                    __osRestoreInt(m5);
                    osSendMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m5);
                }
                if (r) {
                    return (B12Ent **)r->node;
                }
                return 0;
            }
            fl2 = sp20->flags;
            sp20->flags = fl2 | 2;
            if (fn) {
                sp20->flags = fl2 | 0xE;
            }
            m6 = __osDisableInt();
            if (--D_8010515C != 0) {
                __osRestoreInt(m6);
                osSendMesg(&D_80103F70.q11D0, 0, 1);
            } else {
                __osRestoreInt(m6);
            }
            func_002563F4(D_801051B8, src, size, sp20->node->key, &D_801047E0, sp20, 0);
            return 0;
        }
        func_00254E28(0, sp20);
    }
done:
    m7 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m7);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m7);
    }
    return 0;
}


