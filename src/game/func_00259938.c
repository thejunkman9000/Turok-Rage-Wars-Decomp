#include "p3_types.h"

typedef struct P3Link {
    struct P3Link *prev;   /* 0x00 */
    struct P3Link *next;   /* 0x04 */
} P3Link;

typedef struct {
    P3Link link;
    u8 pad08[0xB0 - 8];
    s32 key;               /* 0xB0 */
} P3LNode;

typedef struct {
    u8 pad0[4];
    P3Link active;         /* 0x04 */
    u8 pad0C[0xD8 - 0xC];
    P3Link done;           /* 0xD8 */
} P3LOwner;

void func_00259938(P3LOwner *o, s32 key)
{
  P3LNode *n = (P3LNode *) o->active.next;
  P3LNode *next;
  while (((P3Link *) n) != (&o->active))
  {
    next = (P3LNode *) n->link.next;
    if ((key == (-1)) || (n->key != key))
    {
 do { n->link.prev->next = n->link.next; n->link.next->prev = n->link.prev; n->link.prev = o->done.prev; n->link.next = &o->done; o->done.prev->next = &n->link; o->done.prev = &n->link; } while (0);
    }
    n = next;
  }

}
