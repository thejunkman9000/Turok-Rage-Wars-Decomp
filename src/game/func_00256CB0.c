#include "b12_types.h"
#include "libaudio.h"

extern u32 D_800D0940;
extern s32 D_800D094C;
extern u32 D_800D0950;
extern u8 D_801469E8[];
extern OSMesgQueue D_8010BE00;
extern s32 D_8010BE28[];
extern u8 D_8010BE34[];
typedef struct B12Timer2 {
    struct B12Timer2 *next;
    u8 pad4[4];
    u16 count;
} B12Timer2;
extern B12Timer2 *D_8010BDFC;
void func_0028F844(void *a, void *b, void *c);
void func_00256EC8(s32 buf, s32 z);
void alClose(void *g);

void func_00256CB0(void) {
    s32 sp10[2];
    u32 msg;
    u32 cnt;
    s32 arg;
    s32 done;
    OSTime last;
    OSTime now;
    B12Timer2 *p;
    cnt = arg = done = 0;
    last = 0;
    func_0028F844(D_801469E8, sp10, &D_8010BE00);
    do {
        now = osGetTime();
        D_800D0950 = (u32)(((now - last) << 6) / 3000);
        osRecvMesg(&D_8010BE00, (OSMesg *)&msg, 1);
        last = osGetTime();
        switch (msg) {
        case 4:
            break;
        case 1:
            cnt++;
            if (cnt >= 0x15) {
                cnt = 0;
        case 7:
                D_800D094C++;
                while (!(osAiGetStatus() & 0x80000000)) {
                    func_00256EC8(D_8010BE28[D_800D0940 % 3], arg);
                }
                for (p = D_8010BDFC; p; p = p->next) {
                    if (p->count) {
                        p->count--;
                    }
                }
            }
            break;
        }
    } while (done == 0);
    alClose(D_8010BE34);
}
