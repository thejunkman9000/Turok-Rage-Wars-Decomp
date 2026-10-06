#include "libaudio.h"

void alLink(ALLink *ln, ALLink *to) {
    ln->next = to->next;
    ln->prev = to;
    if (to->next != 0) {
        to->next->prev = ln;
    }
    to->next = ln;
}
