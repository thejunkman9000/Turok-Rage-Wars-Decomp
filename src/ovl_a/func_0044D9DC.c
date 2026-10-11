/* their2 */
/* Port of func_8044CD8C_de.c of the other decompilation (CC0): func_0044D9DC + func_0044DC48, symbols renamed to US v1.1 names. */
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Loads every still-empty cell of the level's tile grid: for each row and column whose cell
   record has no resource, fetches the cell's block through func_0028FE1C and func_002518DC,
   binds and spawns each object of its two object lists (0xE8- and 0x1C8-byte records) and
   releases the spawned handles and the block. */

extern void func_0028795C(void *c, void ***arg1);      /* resource callback (callee defined in src/game/func_0028795C.c) */
extern char D_800CA300[];

extern void func_0024F284(ObjB *obj, s32 arg1);
extern void *func_0024F6DC(ObjB *obj, s32 type);
extern void func_00250950(ObjA *obj, s32 arg1);
extern void *func_00250754(ObjA *obj, s32 type);
extern void **func_002518DC(s32, s32, s32, s32, s32, Level_func_8044CD8C_de *, void *, void *, s32);
extern void func_002536F4(s32, void *);
extern void func_0026E158(void *handle);
extern void *func_0028FD94(void *node, s32 index);
extern s32 func_0028FE1C(s32, s32, s32, s32 *);

void func_0044D9DC(Level_func_8044CD8C_de *level) {
    s32 size;
    s32 width;
    s32 row;
    s32 lastCol;
    s32 lastRow;
    s32 rows;
    func_8022BC04_S3 *cells;
    func_8022BC04_S3 *cell;
    s32 col;
    s32 first;
    s32 key;
    void **block;
    void *node;
    ResourceManagerState *list;
    s32 i;
    s32 n;
    s32 m;
    ObjA *a;
    ObjA *objsA;
    ObjB *objsB;
    ObjB *b;
    void *handle;

    width = ((ResourceManagerState *) func_0028FD94(level->grid, 0))->count;
    row = 0;
    rows = ((ResourceManagerState *) func_0028FD94(level->grid, 2))->count;
    cells = &((func_8044D9DC_S1 *)(func_0028FD94(level->grid, 4)))->unk8;
    lastRow = rows - 1;
    lastCol = width - 1;
    /* FAKEMATCH: constant-holding local first keeps the column loop's entry test as slt */
    first = 0;
    for (; row <= lastRow; row++) {
        for (col = first; col <= lastCol; col++) {
            cell = &cells[col + row * width];
            if (cell->unk10 != 0) {
                continue;
            }
            key = func_0028FE1C(level->file, level->key, col + row * width, &size);
            block = func_002518DC(0, key, key, size, 4, level, (void *) func_0028795C, D_800CA300, 1);
            if (block == 0) {
                continue;
            }
            node = *block;
            if (*(s32 *) node != 0) {
                list = func_0028FD94(node, 0);
                n = list->count;
                objsA = (ObjA *) (list + 1);
                for (i = 0; i < n; i++) {
                    a = &objsA[i];
                    a->block = block;
                    func_00250950(a, 0);
                    handle = func_00250754(a, a->type);
                    if (handle != 0) {
                        func_0026E158(handle);
                        func_002536F4(0, handle);
                    }
                }
                list = func_0028FD94(node, 1);
                m = list->count;
                objsB = (ObjB *) (list + 1);
                for (i = 0; i < m; i++) {
                    b = &objsB[i];
                    b->block = block;
                    func_0024F284(b, 0);
                    handle = func_0024F6DC(b, b->type);
                    if (handle != 0) {
                        func_0026E158(handle);
                        func_002536F4(0, handle);
                    }
                }
            }
            func_002536F4(0, block);
        }
    }
}

/* Runs func_0044DCA4 and func_0044DD40 on a large state block, then clears its word at offset
   0x1B444, sets the word at 0x1B448 to 0x15 and copies D_801462CC into the word at 0x1B44C. */

extern struct Shape_func_8021A2D4_de_2 D_801462CC;
extern void func_0044DCA4(char *);
extern void func_0044DD40(char *);

void func_0044DC48(char *state) {
    func_0044DCA4(state);
    func_0044DD40(state);
    ((func_8044DC48_S1 *)(state))->unk1B444 = 0;
    ((func_8044DC48_S1 *)(state))->unk1B448 = 0x15;
    ((func_8044DC48_S1 *)(state))->unk1B44C = D_801462CC.field_0;
}
