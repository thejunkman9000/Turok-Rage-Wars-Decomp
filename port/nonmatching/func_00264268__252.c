#include "b14_types.h"
extern u8 D_800D0E50;
extern s32 D_800D0E5C;
extern s8 D_8010FBB8;
extern OSMesgQueue D_8010FBC0;
extern OSMesgQueue D_8010FC00;
s32 osGetThreadId(OSThread *t);
void func_00263760();
void func_00285A94(void *a, void *b, s32 n);
void func_00264268(B14Ctl *c) {
    OSPfs *pfs;
    if (D_800D0E50 != 0 && c->f0 != 0) {
        if (osRecvMesg(&D_8010FBC0, 0, 1) == 0) {
            D_800D0E5C = osGetThreadId(0);
        }
        func_00263760();
        D_8010FBB8 = 2;
        c->fCC = 0;
        c->fD0.i = 0;
        c->fD4.i = 0;
        func_00285A94(c->blkA, c->blkB, 3);
        pfs = &c->pfs;
        osMotorInit(&D_8010FC00, pfs, c->port);
        osMotorStop(pfs);
        osMotorStop(pfs);
        if (osMotorInit(&D_8010FC00, pfs, c->port) == 0) {
            c->fC8 = 1;
        }
        D_8010FBB8 = 2;
        D_800D0E5C = -1;
        osSendMesg(&D_8010FBC0, 0, 1);
    }
}
