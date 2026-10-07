#include "b20_types.h"

typedef struct {
    u8 pad0[0x110];
    u32 fb;
    u8 pad114[0x10];
    u32 unk124;
    u8 pad128[0x18];
} View;

OSTime osGetTime(void);
void osViSwapBuffer(void *buf);
void func_002909EC(View *v);
void func_0028F9EC(Vid *o, Job *j);
s32 func_0028F524(Vid *o, Job **a, Job **b, s32 mode);
void func_0028FA40(Vid *o, Job *a, Job *b);
extern u64 D_8011F2A8;
extern f32 D_800D29A4;
extern View D_8011FAC0[];
extern s32 D_8014696C;
extern s32 D_8011FAB8;
extern s32 D_80146D64;
extern s32 D_80146CF4;
extern s32 D_801469E0;
extern s32 D_8014AD90;
extern s32 D_8014AD88;
extern s32 D_80146CF0;
extern s32 D_8014AD8C;
extern View *D_80146970[];
extern u32 D_800E28A0;

void func_0028F258(Vid *o)
{
  Job *j;
  Job *a;
  Job *b;
  View *s;
  View *base;
  u32 fb;
  s32 mode;
  s32 t;
  s32 idx;
  u32 lim;
  u64 d;
  j = o->next2F8;
  a = 0;
  b = 0;
  j->flags4 &= ~1;
  if (j->unk10 == 1)
  {
    if (j->flags8 & 0x20)
    {
      D_800D29A4 = ((f32) (((osGetTime() - D_8011F2A8) * 64) / 3)) * 0.000001f;
    }
    o->next2F8 = 0;
    do {
        if (j->flags8 & 0x20) {
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
            if (fb != base[2].fb) {
                s = base;
            } else {
                s = base;
                s += 2;
            }
sel:
            D_80146CF4 = D_8014696C;
            D_8014696C = D_8011FAB8;
            D_8011FAB8 = D_80146D64;
            D_80146D64 = D_801469E0 + 1;
            if (!((u32)D_80146D64 < s->unk124)) {
                t = D_8014AD90;
                if (t != 0) {
                    goto join;
                }
                if (D_8014AD88 == 0) {
                    D_80146CF0 = s->fb;
                    osViSwapBuffer((void *)s->fb);
                    D_8014AD88 = D_8014AD88 + 1;
                    goto done;
                }
            }
            t = D_8014AD90;
join:
            D_8014AD90 = t + 1;
            idx = D_8014AD8C;
            D_80146970[idx] = s;
            D_8014AD8C = idx + 1;
            if (!((u32)(idx + 1) < D_800E28A0)) {
                D_8014AD8C = 0;
            }
done:
            func_002909EC(s);
        }
    } while (0);
  }
  func_0028F9EC(o, j);
  mode = ((o->cur2F4 == 0) << 1) | (o->next2F8 == 0);
  if (func_0028F524(o, &a, &b, mode) != mode)
  {
    func_0028FA40(o, a, b);
  }
}
