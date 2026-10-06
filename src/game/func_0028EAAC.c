#include "b20_types.h"

typedef struct {
    u8 pad0[0x110];
    s32 unk110;
    u8 pad114[0x10];
    u32 unk124;
} Frm;

void func_0028F934(Vid *o, Job *m);
void func_0028ED80(Vid *o);
void func_0028FBB8(Vid *o);
s32 func_0028F524(Vid *o, Job **a, Job **b, s32 mode);
void func_0028FA40(Vid *o, Job *a, Job *b);
void func_00263B14(void);
void osViSwapBuffer(void *buf);
extern s32 D_800D2954;
extern s32 D_800D2B1C;
extern OSThread D_8010A248;
extern s32 D_801469E0;
extern s32 D_8014AD88;
extern s32 D_80146CF0;
extern s32 D_80146CF8;
extern s32 D_8014AD90;
extern s32 D_8011FAB4;
extern Frm *D_80146970[];
extern u32 D_800E28A0;
extern s32 D_800D2950;

void func_0028EAAC(Vid *o) {
    Job *m;
    Job *a;
    Job *b;
    Job *j;
    Job *c;
    Job *k;
    Qn *n;
    Frm *fr;
    s32 mode;
    s32 buf;
    m = 0;
    a = 0;
    b = 0;
    if (D_800D2954 != 0) {
        D_800D2954 = D_800D2954 - 1;
        if (D_800D2954 == 0) {
            osSetThreadPri(&D_8010A248, D_800D2B1C);
        }
    }
    o->unk2FC = o->unk2FC + 1;
    while (osRecvMesg(&o->q78, (OSMesg *)&m, 0) != -1) {
        func_0028F934(o, m);
    }
    D_801469E0 = D_801469E0 + 1;
    if (D_8014AD88 != 0) {
        D_801469E0 = 0;
        D_8014AD88 = 0;
        buf = D_80146CF0;
        D_80146CF0 = 0;
        D_80146CF8 = buf;
    }
    if (D_8014AD90 != 0) {
        fr = D_80146970[D_8011FAB4];
        if (!((u32)(D_801469E0 + 1) < fr->unk124)) {
            D_80146CF0 = fr->unk110;
            osViSwapBuffer((void *)fr->unk110);
            D_8014AD90 = D_8014AD90 - 1;
            D_8014AD88 = D_8014AD88 + 1;
            D_8011FAB4 = D_8011FAB4 + 1;
            if (!((u32)D_8011FAB4 < D_800E28A0)) {
                D_8011FAB4 = 0;
            }
        }
    }
    if (o->cur2F4 == 0 && o->next2F8 == 0) {
        j = o->head2E8;
        if (j != 0 && j->unk10 == 1 && j->flags4 == 0x32) {
            j->flags4 = 2;
            o->cur2F4 = o->head2E8;
            c = o->head2E8;
            k = c->next;
            o->head2E8 = k;
            if (k == 0) {
                o->tail2F0 = 0;
            }
            func_0028ED80(o);
        }
    }
    D_800D2950 = D_800D2950 + 1;
    if (D_800D2950 == 0x4B0) {
        *(u8 *)0 = 0;
    }
    if (o->unk300 != 0 && o->cur2F4 != 0) {
        func_0028FBB8(o);
    } else {
        mode = (o->cur2F4 == 0) << 1 | (o->next2F8 == 0);
        if (func_0028F524(o, &a, &b, mode) != mode) {
            func_0028FA40(o, a, b);
        }
    }
    n = o->unk2E0;
    while (n != 0) {
        if (((s32 *)n->q)[2] < 2) {
            osSendMesg(n->q, (OSMesg)o, 0);
        }
        n = n->next;
    }
    func_00263B14();
}
