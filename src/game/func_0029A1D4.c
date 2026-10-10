#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80297CD0.h"
#include "types.h"

/* Moves menu focus and sends leave and enter events through menu and element callbacks. */







extern Menu_func_802991D4_de *D_8014D080;
extern Element *func_80298170_de(s32 id);
extern MenuElementHandler func_802997E4_de(s32 kind);
extern s32 func_80411DF0_de(s32 id);






static inline s32 send_event(s32 value, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Menu_func_802991D4_de *manager;
    s32 locked;
    s32 index;
    s32 minusOne;
    s32 saved;
    s32 result;

    if (func_80411DF0_de(value) != 0) {
        if (value != D_8014D080->entries[D_8014D080->current].owner) {
            return 0;
        }
    }
    manager = D_8014D080;
    locked = manager->locked;
    index = manager->current;
    minusOne = -1;
    if ((value == locked) || (index == minusOne)) {
        return 0;
    }
    if (D_8014D080->callback != 0) {
        saved = D_8014D080->handled;
        D_8014D080->handled = 0;
        result = D_8014D080->callback(arg1, arg2, arg3, arg4);
        if (D_8014D080->handled == 1) {
            D_8014D080->handled = saved;
            return result;
        }
        D_8014D080->handled = saved;
    }
    if (value == ((func_8021C9B4_S3 *)(D_8014D080->entries[D_8014D080->current].primary))->unkC) {
        result = func_80297A34_de(arg1, arg2, arg3, arg4);
    } else {
        result = func_80296E3C_de(value, arg1, arg2, arg3, arg4);
    }
    return result;
}

void func_802991D4_de(s32 id) {
    Element *previous;

    if (func_802997E4_de(func_80298170_de(id)->kind) == 0) {
        return;
    }
    previous = D_8014D080->entries[D_8014D080->current].focus;
    if (previous != 0) {
        send_event(previous->id, 0x10,0,0,0);
    }
    D_8014D080->entries[D_8014D080->current].focus = func_80298170_de(id);
    send_event(id, 0xF,0,0,0);
}
