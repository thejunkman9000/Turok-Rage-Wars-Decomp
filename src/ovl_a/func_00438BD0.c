#include "o05_types.h"
typedef struct { u8 pad0[0x54]; s32 f54; u8 pad58[0x78 - 0x58]; s32 f78; u8 pad7C[0xA8 - 0x7C]; s32 fA8; } O05G;
extern O05G D_801468A0[];
extern s32 D_8015402C;
void func_00299368(s32 a);

void func_00438BD0(void) {
  O05G *g;
  D_801468A0->f78 = 0;
  (g = D_801468A0)->f54 = 0;
  if (g->fA8 == 1)
  {
    if (D_8015402C >= 0x23)
    {
      switch (*((u8 *) g - 0x5CB))
      {
        case 1: func_00299368(7); break;
        case 3: func_00299368(3); break;
        case 4: func_00299368(3); break;
        default: func_00299368(3); break;

      }
    } else func_00299368(10);
  }
  else func_00299368(10);
}
