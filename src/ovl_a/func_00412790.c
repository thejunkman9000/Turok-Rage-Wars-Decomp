#include "o02_types.h"
typedef struct { u8 pad[0xE]; u16 type; u8 pad10[0x2C-0x10]; } S_hdr;
typedef struct { s32 w[11]; } S_h2c;
typedef struct { u8 pad0[0xE]; u16 type; u8 pad10[0x38]; u8 b48, b49, b4A, b4B, b4C, b4D, b4E, b4F, b50, b51; u8 pad52[2]; u8 pad54[0xC]; } S_dummy;
typedef struct { S_h2c h; u8 pad2C[0x18]; void *f44; u8 b48, b49, b4A, b4B, b4C, b4D, b4E, b4F, b50, b51; u8 pad52[0xE]; } S_node;
S_node *func_0040ECB0(void *n, u16 id);
void *func_00411E4C(s32 i);
s32 func_0029A958(void);
void *func_00252FFC(s32 n);
void func_002A1748(void *p, s32 v, s32 n);
void func_0040EDB8(void *n, void *p, void *old, void *new);
s32 func_00412790(s32 id, u8 cols, u8 rows, u8 a, u8 b, u8 c, u8 d) {
    S_node *parent, *n;
    void *root;
    s32 size;
    parent = func_0040ECB0(func_00411E4C(func_0029A958()), id);
    root = func_00411E4C(func_0029A958());
    n = func_00252FFC(0x60);
    func_002A1748(n, 0, 0x60);
    n->h = parent->h;
    ((S_hdr *)n)->type = 0xB;
    n->b4B = b;
    n->b4A = a;
    n->b49 = rows;
    n->b48 = cols;
    n->b51 = d;
    n->b50 = c;
    n->b4F = d;
    n->b4E = c;
    n->b4D = d;
    n->b4C = c;
    size = a * b * 8;
    n->f44 = func_00252FFC(size);
    func_002A1748(n->f44, 0, size);
    func_0040EDB8(root, 0, parent, n);
    return 1;
}
