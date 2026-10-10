#ifndef FUNC_80299A80_DE_CLOSED_H
#define FUNC_80299A80_DE_CLOSED_H
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "types.h"
struct Shared_WidgetIdE { u8 pad0[0xE]; u16 id; };










extern struct WidgetTable *D_8014D080;

static inline WidgetCallback func_8029AA80_find(s32 id) {
    struct WidgetHandler *h = D_8014D080->handlers;
    s32 i;

    for (i = 0; i < 64; i++, h++) {
        if (h->id == id) {
            return h->callback;
        }
    }
    return 0;
}

/* Finds the widget's handler by identifier and, if present, calls it with the widget and the by-value event arguments. */

#endif
