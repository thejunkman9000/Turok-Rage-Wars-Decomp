typedef int s32;
extern s32 D_auto_801371FC;
extern s32 D_auto_8014DE64;
extern s32 D_auto_8014DE60;
s32 LevelIdToWorld(s32 a);

void func_auto_004433C0(void) {
    D_auto_8014DE64 = LevelIdToWorld(D_auto_801371FC);
    D_auto_8014DE60 = 1;
}
