#include "p4_types.h"
typedef struct { s32 pad0; s32 count; u16 ids[1]; } P4IdTbl;
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x54 - 0x28]; s32 f54; u8 pad58[0x94 - 0x58]; P4IdTbl *tbl; } P4Owner;
typedef struct { u8 pad0[4]; s16 idx; u8 pad6[0xE4 - 6]; u16 id; } P4Item;
void func_00246BD8(P4Item *item, s32 a, s32 b);
static inline s32 find(P4IdTbl *t, u16 id) {
    s32 i;
    u16 *p = t->ids;
    s32 n = t->count;
    for (i = 0; i < n; i++, p++) {
        if (*p == id) return i;
    }
    return -1;
}
void func_0028B250(P4Owner *o, P4Item *it, s32 id) {
    s32 i;
    if (it->id != id) {
        i = find(o->tbl, id);
        if (i != -1) {
            it->idx = i;
            it->id = id;
            func_00246BD8(it, o->f54, o->f24);
        }
    }
}