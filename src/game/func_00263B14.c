#include "b14_types.h"
extern u8 D_800D0E50;
extern s32 D_800D0E5C;
extern u8 D_8010FBB8;
extern u8 D_8010EC90[];
extern OSMesgQueue D_8010FBC0;
extern OSMesgQueue D_8010FC00;
extern B14Ctl D_8010F328[];
s32 osGetThreadId(OSThread *t);
void func_00285C48(void *p);
void func_00263760();
void func_00264124(B14Ctl *c);
s32 func_00264748();
static inline s32 b14_lock(s32 flag) {
    s32 r = osRecvMesg(&D_8010FBC0, 0, flag) == 0;
    if (r != 0) {
        D_800D0E5C = osGetThreadId(0);
    }
    return r;
}
void func_00263B14(void) {
    s32 i;
    B14Ctl *c;
    if (D_800D0E50 != 0) {
        func_00285C48(D_8010EC90);
        if (b14_lock(0) != 0) {
            func_00263760();
            for (i = 0, c = D_8010F328; i < 4; i++, c++) {
                func_00264124(c);
            }
            switch (D_8010FBB8) {
            case 0:
                if (func_00264748() != 0) {
                    D_8010FBB8 = 1;
                    osContStartQuery(&D_8010FC00);
                } else {
                    osContStartReadData(&D_8010FC00);
                }
                break;
            case 1:
            case 2:
            case 3:
                D_8010FBB8 = 0;
                osContStartReadData(&D_8010FC00);
                break;
            default:
                break;
            }
            D_800D0E5C = -1;
            osSendMesg(&D_8010FBC0, 0, 1);
        }
    }
}
