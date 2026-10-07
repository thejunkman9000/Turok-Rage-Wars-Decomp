#include "b12_types.h"

extern B12Mgr D_80103F70;
extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u32 D_80105190;
extern B12Bucket *D_80105194;
extern u32 D_80105180;
extern u8 D_80104570[];
extern u8 D_8010A248[];
extern OSMesgQueue D_801047E0;
void func_00255F58(void *list, B12Node *n);
B12Ent *func_00254E70(s32 a, s32 sz);
void func_00255110(void *port, B12Ent *e);
s32 func_0025519C(void *port, B12Ent *e, void *q);
B12Ent *func_00252714(s32 a, B12Ent *e, s32 b);
void func_00254E28(s32 a, B12Ent *e);
void func_00255E78(void *l, void *n);
void func_00255C58(void *l, void *n);
void func_00255CB4(void *l, void *n);

inline void hashFind(u32 key, B12Ent **out) {
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

B12Ent *func_00251F0C(s32 a0, u32 key, B12Node *dep1, B12Node *dep2, s32 sz, void *owner, void *fn, void *unused, s32 flag) {
    B12Ent *sp10;
    B12Ent *e;
    B12Ent *p;
    B12Node *n;
    s32 found;
    u32 m1;
    u32 m2;
    u32 m3;
    u32 m4;
    u32 m5;
    u32 m6;
    u32 m7;
    u32 m8;
    m1 = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(m1);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m1);
    }
    hashFind(key, &sp10);
    found = 0;
    if (sp10) {
        n = sp10->node;
        n->refs++;
        n->flags |= 0x100;
        n = sp10->node;
        n->unk10 = D_80105180;
        func_00255F58(D_80104570, n);
        m2 = __osDisableInt();
        if (--D_8010515C != 0) {
            __osRestoreInt(m2);
            osSendMesg(&D_80105140, 0, 1);
        } else {
            __osRestoreInt(m2);
        }
        return (B12Ent *)sp10->node;
    }
    flag |= D_80103F70.f120C;
    for (p = D_80103F70.lists3[2].head; p; p = p->next) {
        if (p->key == key) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        e = func_00254E70(0, sz);
        sp10 = e;
        if (e) {
            e->key = key;
            e->stamp = 0;
            e->owner = owner;
            e->fn = fn;
            e->size = sz;
            e->node = dep1;
            e->dep = dep2;
            if (dep1) {
                dep1->refs++;
                dep1->flags |= 0x100;
            }
            if (dep2) {
                dep2->refs++;
                dep2->flags |= 0x100;
            }
            func_00255E78(&D_80103F70.lists3[1], sp10);
            func_00255CB4(&D_80103F70.lists3[2], sp10);
            m3 = __osDisableInt();
            if (--D_8010515C != 0) {
                __osRestoreInt(m3);
                osSendMesg(&D_80103F70.q11D0, 0, 1);
            } else {
                __osRestoreInt(m3);
            }
            if (flag != 0) {
                sp10->flags &= ~0xE;
                func_00255110(D_8010A248, sp10);
                m4 = __osDisableInt();
                if (++D_8010515C != 1) {
                    __osRestoreInt(m4);
                    osRecvMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m4);
                }
                sp10 = func_00252714(0, sp10, 0);
                m5 = __osDisableInt();
                if (--D_8010515C != 0) {
                    __osRestoreInt(m5);
                    osSendMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m5);
                }
                if (sp10 != 0) {
                    return (B12Ent *)sp10->node;
                }
                return 0;
            }
            if (func_0025519C(D_8010A248, sp10, &D_80103F70.q870) != 0) {
                return 0;
            }
            m6 = __osDisableInt();
            if (++D_8010515C != 1) {
                __osRestoreInt(m6);
                osRecvMesg(&D_80103F70.q11D0, 0, 1);
            } else {
                __osRestoreInt(m6);
            }
            if (dep1) {
                dep1->refs--;
                if (dep1->refs == 0) {
                    dep1->flags &= ~0x100;
                }
            }
            if (dep2) {
                dep2->refs--;
                if (dep2->refs == 0) {
                    dep2->flags &= ~0x100;
                }
            }
            func_00255E78(&D_80103F70.lists3[2], sp10);
            func_00255C58(&D_80103F70.lists3[1], sp10);
            func_00254E28(0, sp10);
            m7 = __osDisableInt();
            if (--D_8010515C != 0) {
                __osRestoreInt(m7);
                osSendMesg(&D_80105140, 0, 1);
            } else {
                __osRestoreInt(m7);
            }
            return 0;
        }
    }
    m8 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m8);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m8);
    }
    return 0;
}
