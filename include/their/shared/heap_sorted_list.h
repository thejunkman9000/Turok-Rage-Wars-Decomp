#ifndef RW_HEAP_SORTED_LIST_H
#define RW_HEAP_SORTED_LIST_H
#include "types.h"
struct Node80254C10;
/* Generic list routines address links by the offsets at 8 and C. */
typedef struct Shared_HeapSortedList {
    struct Node80254C10 *first;
    struct Node80254C10 *last;
    s32 link8;
    s32 linkC;
    s32 count;
} Shared_HeapSortedList;
extern Shared_HeapSortedList D_80100584;
#endif
