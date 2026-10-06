#include "b23_types.h"

typedef struct Node6D28 Node6D28;
struct Node6D28 {
    u8 pad0[4];
    Node6D28 *next;
    u8 pad8[0x40];
    s32 key;
};

typedef struct Pool6D28 {
    u8 pad0[0x94E0];
    u8 lists[10][0x14];
    u8 spare[0x8];
    u8 pad9[0x10];
} Pool6D28;

void func_00255E78(void *list, Node6D28 *n);
void func_00255CB4(void *list, Node6D28 *n);

void func_002A6D28(u8 *o, s32 key) {
    s32 i;
    Node6D28 *n, *next;
    void *list;

    if (*(s32 *)(o + 0x95B8) != 0x64) {
        for (i = 0; i < 10; i++) {
            list = o + 0x94E0 + i * 0x14;
            n = *(Node6D28 **)list;
            while (n != 0) {
                next = n->next;
                if (n->key == key) {
                    func_00255E78(list, n);
                    func_00255CB4(o + 0x95A8, n);
                }
                n = next;
            }
        }
    }
}
