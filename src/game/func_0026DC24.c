#include "b16_types.h"

typedef struct B16QEntry {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} B16QEntry;

extern s32 *D_8011064C;
extern s32 D_80110624;
extern s32 D_80110640;
extern s32 D_801153D0;
extern s32 *D_801153D8[];
extern B16QEntry D_801157D8[];

s32 *func_0028FD94(s32 *node, s32 idx);
void func_0026BC60(void);
void func_00253610(s32 a, s32 *b);

void func_0026DC24(s32 **p, s32 b, s32 c, s32 d, s32 *node, s32 key) {
    B16QEntry *e;
    s32 *root = *p;
    if (node == NULL) {
        node = func_0028FD94(root, 0);
    }
    if (D_8011064C != (s32 *)p || D_80110624 != key || D_80110640 == 0x20) {
        func_0026BC60();
        if (D_801153D0 == 0x100) {
            return;
        }
        func_00253610(0, (s32 *)p);
        D_801153D8[D_801153D0++] = (s32 *)p;
    }
    D_8011064C = (s32 *)p;
    D_80110624 = key;
    e = &D_801157D8[D_80110640++];
    e->a = b;
    e->d = c;
    e->b = d;
    e->c = (s32)node;
}
