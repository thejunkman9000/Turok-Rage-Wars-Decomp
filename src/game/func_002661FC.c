/* PARTIAL (20 words): only the type==1 arm differs (ROM keeps inlined helper result in v1 and builds v0 via beqz; ours threads it to direct returns) */
#include "b15_types.h"

s32 func_0024D150(B15Obj *a);
extern s32 D_8013B290;
extern u8 D_801462E5;

static inline s32 chk(B15Obj *a, B15Obj *t) {
    u32 f;

    if (D_801462E5 != 0) {
        return 1;
    }
    if (t->unkE4 == a->unkE4) {
        return 0;
    }
    f = a->flags;
    if (!(f & 0x310000)) {
        return 0;
    }
    if (D_8013B290 != 0 && !(t->flags & 0x300000) && !(f & 0x300000)) {
        return 0;
    }
    switch (a->def->type) {
    case 1:
    case 4:
    case 7:
    case 0xB:
        return 1;
    }
    return 0;
}

static inline s32 chk3(B15Obj *a, B15Obj *t) {
    u32 f;
    register s32 res asm("$3");

    if (D_801462E5 != 0) {
        res = 1;
        goto done;
    }
    if (t->unkE4 == a->unkE4) {
        res = 0;
        goto done;
    }
    f = a->flags;
    if (!(f & 0x310000)) {
        res = 0;
        goto done;
    }
    if (D_8013B290 != 0 && !(t->flags & 0x300000) && !(f & 0x300000)) {
        res = 0;
        goto done;
    }
    switch (a->def->type) {
    case 1:
    case 4:
    case 7:
    case 0xB:
        res = 1;
        goto done;
    }
    res = 0;
done:
    return res;
}

s32 func_002661FC(B15Obj *a, B15Obj *t)
{
  B15Obj *p;
  B15Obj *u;
  if (a == t)
  {
    return 0;
  }
  if ((a->flags & 0x300000) && (!func_0024D150(a)))
  {
    return 0;
  }
  if (t->type != 1)
  {
    if (t->type != 2)
    {
      return 1;
    }
    p = t->unk12C;
    u = t;
    if (p != ((void *) 0))
    {
      if ((p->type == 1) && (!chk(a, p)))
      {
        return 0;
      }
      if ((a == u->unk12C) && ((*u->unk118) & 0x40))
      {
        return 0;
      }
    }
    if (((u->unk4 != 0x14) || (a->def->type != 1)) || (a->unkE4 != 0xCA))
    {
      return 1;
    }
    return 0;
  }
  if (chk3(a, t))
  {
    return 1;
  }
  if (a || t)
  {
 do { } while (0);
    return 0;
  }
  else
  {
    return 0;
  }
}
