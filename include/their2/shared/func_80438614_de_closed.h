#ifndef FUNC_80438614_DE_CLOSED_H
#define FUNC_80438614_DE_CLOSED_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"



extern ModelPreviewScreen *D_800E5830;

extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(MenuWidget *,s32);
extern void func_80439B5C_de(void *,s32,Vec3,Vec3);
extern void func_80439BE0_de(void *,Vec3);
extern void func_80439C30_de(void *,Vec3);
extern void func_80439C80_de(void *,s32);


#if defined(VERSION_DE)
enum { MENU_804387F4_642 = 638 };
#elif defined(VERSION_EU_X)
enum { MENU_804387F4_642 = 647 };
#else
enum { MENU_804387F4_642 = 642 };
#endif


#endif
