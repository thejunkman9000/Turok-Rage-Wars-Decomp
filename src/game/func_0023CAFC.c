#include "b09_types.h"

extern B09LoaderCtl D_80103720;
extern B09IoQ D_80103254;
extern u8 D_801051B8[];
extern u8 D_80156000[];
void func_0023CA14(void *);
void func_0023C1E0(B09LoadReq *);
void func_0023CE8C(B09LoadReq *);
void func_0023CCC4(B09LoadReq *);
void func_0023CDC4(B09LoadReq *);
void func_0025631C(u8 *, s32, s32, u8 *);

void func_0023CAFC(B09List *l, B09LNode *n) {
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        l->head = n->next;
        n->next->prev = NULL;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        l->tail = n->prev;
        n->prev->next = NULL;
    }
}
