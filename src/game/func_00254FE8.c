#include "span_1000/code_80254CE4.h"
#include "types.h"

/* Finds an evictable entry of a list: skips entries flagged 0x702 and returns the first one untouched for at least five ticks of D_80105180, remembering the first recently used candidate in *recent when that slot is still empty; returns null when none qualifies. */





extern s32 D_80105180[];

Entry_func_80255048_de *func_80255048_de(s32 unused, EntryList *list, Entry_func_80255048_de **recent)
{
    Entry_func_80255048_de *e = list->first;

    if (*recent == 0) {
        for (; e != 0; e = e->next) {
            if (!(e->flags & 0x702)) {
                if ((u32)(D_80105180[0] - e->stamp) >= 5) {
                    return e;
                }
                *recent = e;
                break;
            }
        }
    }
    for (; e != 0; e = e->next) {
        if (!(e->flags & 0x702) && (u32)(D_80105180[0] - e->stamp) >= 5) {
            return e;
        }
    }
    return 0;
}
