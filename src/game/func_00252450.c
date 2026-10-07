#include "b12_types.h"

typedef struct B12Msg {
    B12Node *node;
    u8 pad4[0xC];
    u32 flags;
} B12Msg;

extern B12Mgr D_80103F70;
extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u8 D_8010A248[];
extern u8 D_801051A0[];
void func_00254F3C(s32 a, u32 b);
s32 func_0025519C(void *port, B12Msg *n, void *q);
void func_00255E78(void *l, B12Msg *n);
void func_00255C58(void *l, B12Msg *n);
void func_00254D70(s32 a, B12Node *n);
void func_00255ACC(void *heap, s32 key);
void func_00254A70(s32 a, B12Node *n);
void func_00254E28(s32 a, B12Msg *n);
void func_00252714(s32 a, B12Msg *n, s32 b);

void func_00252450(void) {
    B12Msg *msg;
    B12Node *p;
    u32 mask;
    u32 m2;
    while (1) {
        osRecvMesg(&D_80103F70.q870, (OSMesg *)&msg, 1);
        if ((u32)msg < 2) {
            mask = __osDisableInt();
            if (++D_8010515C != 1) {
                __osRestoreInt(mask);
                osRecvMesg(&D_80103F70.q11D0, 0, 1);
            } else {
                __osRestoreInt(mask);
            }
            func_00254F3C(0, (u32)msg);
            m2 = __osDisableInt();
            if (--D_8010515C != 0) {
                __osRestoreInt(m2);
                osSendMesg(&D_80105140, 0, 1);
            } else {
                __osRestoreInt(m2);
            }
        } else {
            msg->flags &= ~2;
            if (msg->flags & 8) {
                msg->flags &= ~8;
                if (func_0025519C(D_8010A248, msg, &D_80103F70.q870) != 0) {
                    continue;
                }
                mask = __osDisableInt();
                if (++D_8010515C != 1) {
                    __osRestoreInt(mask);
                    osRecvMesg(&D_80103F70.q11D0, 0, 1);
                } else {
                    __osRestoreInt(mask);
                }
                func_00255E78(&D_80103F70.lists3[2], msg);
                func_00255C58(&D_80103F70.lists3[1], msg);
                p = msg->node;
                p->flags &= ~2;
                while (p->refs != 0) {
                    p->refs--;
                    if (p->refs == 0) {
                        p->flags &= ~0x100;
                    }
                }
                if (!(p->flags & 0x702)) {
                    func_00254D70(0, p);
                    func_00255ACC(D_801051A0, p->key);
                    func_00254A70(0, p);
                }
                func_00254E28(0, msg);
                m2 = __osDisableInt();
                if (--D_8010515C != 0) {
                    __osRestoreInt(m2);
                    osSendMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m2);
                }
            } else {
                msg->flags &= ~4;
                mask = __osDisableInt();
                if (++D_8010515C != 1) {
                    __osRestoreInt(mask);
                    osRecvMesg(&D_80103F70.q11D0, 0, 1);
                } else {
                    __osRestoreInt(mask);
                }
                func_00252714(0, msg, 1);
                m2 = __osDisableInt();
                if (--D_8010515C != 0) {
                    __osRestoreInt(m2);
                    osSendMesg(&D_80105140, 0, 1);
                } else {
                    __osRestoreInt(m2);
                }
            }
        }
    }
}
