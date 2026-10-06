#include "b20_types.h"

typedef struct {
    u8 pad0[0x110];
    u32 fb;
    u32 unk114;
    u8 pad118[0x28];
} View;

OSTime osGetTime(void);
void func_00253C8C(s32 a, s32 b);
void func_0028F9EC(Vid *o, Job *j);
s32 func_0028F524(Vid *o, Job **a, Job **b, s32 mode);
void func_0028FA40(Vid *o, Job *a, Job *b);
extern u64 D_8011F2A0;
extern u64 D_8011F290;
extern f32 D_8011F298;
extern f32 D_800D29A0;
extern f32 D_800D299C;
extern s32 D_800D2950;
extern View D_8011FAC0[];
extern u32 D_801536F4;

void func_0028ED80(Vid *o) {
    Job *j;
    Job *a;
    Job *b;
    View *s;
    View *base;
    u32 fb;
    s32 mode;
    j = o->cur2F4;
    o->cur2F4 = 0;
    a = 0;
    b = 0;
    if ((j->flags4 & 0x10) && osSpTaskYielded((OSTask *)((u8 *)j + 0x10)) != 0) {
        j->flags4 |= 0x20;
        if ((j->flags8 & 7) == 3) {
            j->next = o->head2E8;
            o->head2E8 = j;
            if (o->tail2F0 == 0) {
                o->tail2F0 = j;
            }
        }
        if (j->flags8 & 0x20) {
            D_8011F298 = D_8011F298 + (f32)(((osGetTime() - D_8011F2A0) * 64) / 3) * 0.000001f;
        }
    } else {
        j->flags4 &= ~2;
        if (j->unk10 == 1) {
            D_800D2950 = 0;
            if (!(j->flags8 & 0x20)) {
                goto done;
            }
            D_8011F298 = D_8011F298 + (f32)(((osGetTime() - D_8011F2A0) * 64) / 3) * 0.000001f;
            D_800D29A0 = D_8011F298;
            D_800D299C = (f32)(((osGetTime() - D_8011F290) * 64) / 3) * 0.000001f;
            base = D_8011FAC0;
            fb = (u32)j->unkC;
            if (fb == base[0].fb) {
                s = base;
                goto sel;
            }
            if (fb == base[1].fb) {
                s = base + 1;
                goto sel;
            }
            s = base;
            if (fb == base[2].fb) {
                s += 2;
            }
sel:
            func_00253C8C(0, s->unk114 == D_801536F4);
            if (osSendMesg((OSMesgQueue *)((s32 *)j)[0x50 / 4], (OSMesg)((s32 *)j)[0x54 / 4], 1) == -1) {
                *(u8 *)0 = 0;
            }
        } else {
            D_800D299C = (f32)(((osGetTime() - D_8011F290) * 64) / 3) * 0.000001f;
            if (osSendMesg((OSMesgQueue *)((s32 *)j)[0x50 / 4], (OSMesg)((s32 *)j)[0x54 / 4], 1) == -1) {
                *(u8 *)0 = 0;
            }
        }
done:
        func_0028F9EC(o, j);
    }
    mode = (o->cur2F4 == 0) << 1 | (o->next2F8 == 0);
    if (func_0028F524(o, &a, &b, mode) != mode) {
        func_0028FA40(o, a, b);
    }
}
