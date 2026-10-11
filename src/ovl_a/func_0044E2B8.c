/* their2 */
/* Port of func_8044D668_de.c of the other decompilation (CC0): func_0044E2B8 + func_0044E3E4 + func_0044E454 + func_0044E584 + func_0044E6A4, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044E2B8.h"
#include "types.h"
#include "shared/func_8044D794_de_closed.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "shared/func_8044DA54_de_closed.h"

extern void func_00255C58(void *, Entry_func_8044D794_de *);
extern void func_00255E78(void *, Entry_func_8044D794_de *);
extern void func_00278C80(s32);
extern s32 func_00285150(void ***, s32);
extern void *func_0028FD94(void *, s32);

/* Spawns the pickups of a level: between func_002458C8 and func_002458B4 it passes every item of both item tables whose kind is 1, 2, 4 or 10 to func_0028784C. */

extern void func_002458C8(void);
extern void func_002458B4(void);
extern void func_0028784C(Level *, Item_func_8044D668_de *);

void func_0044E2B8(Level *level) {
    s32 i;
    s32 n;
    Item_func_8044D668_de *item;

    func_002458C8();
    n = level->counts[0];
    for (i = 0; i < n; i++) {
        item = &level->items[0][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            func_0028784C(level, item);
        }
    }
    n = level->counts[1];
    for (i = 0; i < n; i++) {
        item = &level->items[1][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            func_0028784C(level, item);
        }
    }
    func_002458B4();
}

void func_0044E3E4(Owner_func_8044D794_de *arg0) {
    Entry_func_8044D794_de *entry;
    Entry_func_8044D794_de *next;

    entry = arg0->active;
    while (entry != 0) {
        next = entry->next;
        func_00278C80(entry->handle);
        func_00255E78(&arg0->active, entry);
        func_00255C58(&arg0->spare, entry);
        entry = next;
    }
}

extern s32 func_0028C174(s32, s32);

void func_0044E454(s32 arg0, void ***arg1) {
    void *obj;
    Group_func_8044D794_de *group;
    Piece *piece;
    s32 base;
    s32 count;
    s32 i;

    if (func_00285150(arg1, 0) != 0) {
        obj = **arg1;
        group = func_0028FD94(obj, 2);
        count = group->count;
        piece = group->pieces;
        i = 0;
        base = (s32) func_0028FD94(obj, i);
        if (count > 0) {
            do {
                if (piece[i].tag == -1) {
                    piece[i].tag = 0;
                } else {
                    piece[i].tag = func_0028C174(arg0, piece[i].tag);
                }
                piece[i].unk18 = base + piece[i].unk18;
                piece[i].unk1C = base + piece[i].unk1C;
                piece[i].unk20 = base + piece[i].unk20;
                piece[i].unk24 = base + piece[i].unk24;
                piece[i].unk28 = base + piece[i].unk28;
                piece[i].unk2C = base + piece[i].unk2C;
                piece[i].unk30 = base + piece[i].unk30;
                piece[i].unk34 = base + piece[i].unk34;
                piece[i].unk38 = base + piece[i].unk38;
                i++;
            } while (i < count);
        }
    }
}


void func_0044E584(s32 arg0, void ***arg1) {
    f32 scale;
    void *obj;
    Ent *ent;
    s32 count;
    s32 i;

    scale = 1.0f;
    if (func_00285150(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            ent = func_0028FD94(obj, i);
            switch (ent->kind) {
            case 1:
                ent->unk28 = ent->unk28 * scale;
                ent->unk30 = ent->unk30 * scale;
                ent->unk34 = ent->unk34 * scale;
                ent->unk50 = ent->unk50 * scale;
                ent->unk54 = ent->unk54 * scale;
                ent->unk58 = ent->unk58 * scale;
                break;
            case 11:
                ent->unkEC = ent->unkEC * scale;
                ent->unkF0 = ent->unkF0 * scale;
                break;
            case 0:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
            }
        }
    }
}

void func_0044E6A4(Owner_func_8044D794_de *arg0, void ***arg1) {
    void *obj;
    Frame_func_8044D794_de *frame;
    Bank_func_8044D794_de *bank;
    struct Entry_func_80405338_de *items;
    struct Entry_func_80405338_de *item;
    Slot_func_8044D794_de *slot;
    s32 count;
    s32 inner;
    s32 i;
    s32 j;
    s32 index;

    if (func_00285150(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            frame = func_0028FD94(func_0028FD94(obj, i), 1);
            inner = frame->count;
            j = 0;
            if (j < inner) {
                slot = frame->slots;
                do {
                    index = slot->item;
                    if (index != -1) {
                        bank = func_0028FD94(arg0->unk6C, 2);
                        items = bank->items;
                        if ((index < 0) || (index >= bank->count)) {
                            item = 0;
                        } else {
                            item = &items[index];
                        }
                        slot->item = (s32) item;
                    } else {
                        slot->item = 0;
                    }
                    slot++;
                    j++;
                } while (j < inner);
            }
        }
        arg0->unk7C = obj;
    }
}
