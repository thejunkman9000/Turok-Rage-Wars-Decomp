#include "shared/func_802BB8B0_de_closed.h"
#include "common/unused.h"
#include "types.h"
/* __osInsertTimer, drafted from ultralib src/os/timerintr.c. */

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 mask);

u64 func_802BBAAC_de(struct OSTimer_s *t)
{
    struct OSTimer_s *timep;
    u64 tim;
    u32 savedMask = func_802BCF30_de();

    timep = ((struct OSTimer_s *)D_800D5280)->next;
    tim = t->value;
    for (; timep != D_800D5280 && tim > timep->value; timep = timep->next) {
        tim -= timep->value;
    }

    t->value = tim;

    if (timep != D_800D5280) {
        timep->value -= tim;
    }

    t->next = timep;
    t->prev = timep->prev;
    timep->prev->next = t;
    timep->prev = t;
    func_802BCF50_de(savedMask);
    return tim;
}
