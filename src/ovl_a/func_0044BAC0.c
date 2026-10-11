/* their2 */
/* Port of func_8044AE70_de.c of the other decompilation (CC0): func_0044BAC0, symbols renamed to US v1.1 names. */
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Resets the controller and profile state for a new session: reinitialises the input buffers and stream through func_00285A94, osCreateMesgQueue, osSetEventMesg, osContInit, osGetThreadId and osSendMesg, then for slots 3 down to 0 clears the slot's three state words, refreshes its pad through func_002647A8 and counts the profiles func_0044BC58 accepts in D_800D0E52, remembering the lowest accepted slot in D_8010F320; finally checks the profile just below slot 0 with mode 4, marks the session reset and returns the remembered slot. */

extern char D_8010EC90[];
extern char D_8010ECC0[];
extern signed char D_8010FBB8;
extern char D_8010FC00[];
extern char D_8010FBD8[];
extern char D_8010FBC0[];
extern char D_8010F304[];
extern char D_800D0E51[];
extern char D_8010FBE0[];
extern s32 D_800D0E5C;

extern u8 D_800D0E52;

extern int D_8010FBF0[];
extern s32 D_8010FC28[];
extern s32 D_8010F310[];
extern ControllerProfile D_8010F328[];
extern signed char D_800D0E50;
extern short D_8010F320;

extern void func_00285A94(char *, char *, s32);
extern void osCreateMesgQueue(void *mq, void *msgBuf, s32 count);
extern void osSetEventMesg(s32 event, void *mq, void *msg);
extern s32 osContInit(void *mq, u8 *bitpattern, void *status);
extern s32 osGetThreadId(void *thread);
extern s32 osSendMesg(void *mq, void *msg, s32 flag);
extern void func_002647A8(s32);
extern s32 func_0044BC58(ControllerProfile *, s32);

s16 func_0044BAC0(void) {
    s32 i;

    func_00285A94(D_8010EC90, D_8010ECC0, 8);
    D_8010FBB8 = 2;
    osCreateMesgQueue(D_8010FC00, D_8010FBD8, 1);
    osCreateMesgQueue(D_8010FBC0, D_8010F304, 1);
    osSetEventMesg(5, D_8010FC00, (void *)1);
    osContInit(D_8010FC00, D_800D0E51, D_8010FBE0);
    osGetThreadId(0);
    D_800D0E5C = -1;
    osSendMesg(D_8010FBC0, (void *)0, 1);
    D_8010F320 = -1;
    D_800D0E52 = 0;
    for (i = 3; i >= 0; i--) {
        D_8010FBF0[i] = 0;
        D_8010FC28[i] = 0;
        D_8010F310[i] = 0;
        func_002647A8(i);
        if (func_0044BC58(&D_8010F328[i], i) != 0) {
            D_8010F320 = i;
            D_800D0E52++;
        }
    }
    func_0044BC58(&D_8010F328[i], 4);
    D_800D0E50 = 1;
    return D_8010F320;
}
