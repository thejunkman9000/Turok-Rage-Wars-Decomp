#include "o02_types.h"
extern s32 D_80153CAC, D_80153CA0, D_80153CA4, D_80153CA8;
extern s32 D_80153CC0, D_80153CC4, D_80153CC8, D_80153CCC;
extern s32 D_80153C6C, D_80153C74;
extern void (*D_80153CD4)(s32);
void func_00413D60(s32 idx, u32 argb) {
  u32 r = (argb >> 16) & 0xFF;
  u32 g = (argb & 0xFF00) >> 8;
  u32 b = argb & 0xFF;
  u32 a = argb >> 24;
  void (*fn)(s32);
  u32 v;
  if (D_80153CAC == 0)
  {
    a = 0xFF;
  }
 do { r = (D_80153CC0 < 0) ? ((r >> (-D_80153CC0)) & D_80153CA0) : ((r << D_80153CC0) & D_80153CA0); g = (D_80153CC4 < 0) ? ((g >> (-D_80153CC4)) & D_80153CA4) : ((g << D_80153CC4) & D_80153CA4); b = (D_80153CC8 < 0) ? ((b >> (-D_80153CC8)) & D_80153CA8) : ((b << D_80153CC8) & D_80153CA8); a = (D_80153CCC < 0) ? ((a >> (-D_80153CCC)) & D_80153CAC) : ((a << D_80153CCC) & D_80153CAC); v = ((r | g) | b) | a; fn = D_80153CD4; } while (0);
  D_80153C6C = idx;
  D_80153C74 = v;
  fn(idx);
}
