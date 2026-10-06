#include "libaudio.h"

void alUnlink(ALLink *ln) {
    if (ln->next != 0) {
        ln->next->prev = ln->prev;
    }
    if (ln->prev != 0) {
        ln->prev->next = ln->next;
    }
}
