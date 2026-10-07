#include "b18_types.h"

typedef struct B18Item B18Item;
struct B18Item {
    /* 0x000 */ u8 pad0[0x5C];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xD0];
    /* 0x130 */ s32 *counter;
    /* 0x134 */ u8 pad134[4];
    /* 0x138 */ void *handle;
    /* 0x13C */ u8 pad13C[0x9D];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[0xA];
    /* 0x1E4 */ void *list;
    /* 0x1E8 */ u8 pad1E8[4];
    /* 0x1EC */ B18Item *next;
};

typedef struct B18Cell {
    B18Item *head;
    u8 pad[0x10];
} B18Cell;

typedef struct B18World {
    /* 0x0000 */ u8 pad0[0xFC00];
    /* 0xFC00 */ u8 listA[0x14];
    /* 0xFC14 */ u8 listB[0x14];
    /* 0xFC28 */ B18Cell cells[3];
} B18World;

extern u8 D_8013B1A8[];
extern u8 D_8013BA80[];

void func_00279A70(B18Item *a);
void func_0028414C(B18Item *a);
void func_002A52E4(void *a, B18Item *b);
void func_00268C7C(void *a, void *b);
void func_00255E78(void *a, B18Item *b);
void func_00255C58(void *a, B18Item *b);

void func_0027FF2C(B18World *w) {
    s32 i;
    u8 *row;
    B18Item *it;
    B18Item *cur;
    u32 f;

    i = 0;
    row = (u8 *)w;
    do {
        it = *(B18Item **)(row + 0xFC28);
        if (it != NULL) {
            do {
                cur = it;
                f = cur->flags;
                it = it->next;
                if (f & 0x100)
                if (!(f & 0x800)) {
                    func_00279A70(cur);
                    if (cur->unk1D9 != 0) {
                        func_0028414C(cur);
                        func_002A52E4(D_8013BA80, cur);
                    }
                    if (cur->handle != NULL) {
                        func_00268C7C(D_8013B1A8, cur->handle);
                        cur->handle = NULL;
                    }
                    if (cur->counter != NULL) {
                        *cur->counter -= 1;
                    }
                    cur->flags &= 0xFDFFFEFF;
                    func_00255E78(cur->list, cur);
                    cur->list = NULL;
                    func_00255C58(w->listA, cur);
                    if (cur->flags & 0x1000000) {
                        func_00255E78(w->listB, cur);
                    }
                }
            } while (it != NULL);
        }
        i++;
        row += 0x14;
    } while (i < 3);
}
