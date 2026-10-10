#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028567C.h"
#include "types.h"

/* With interrupts masked, takes the first node of a pool's free list, moves it onto the pool's active list and initialises it with its key, position, two values and owner slot (storing the node there), then binds the two handles named by the key's identifiers, returning the node or null. */









extern char D_8011FE88;
extern s32 func_802BCF30_de(void);
extern void func_802BCF50_de(s32 mask);
extern void func_80255ED8_de(Pool_func_80285B64_de *pool, Node_func_80285B64_de *node);
extern void func_80255D14_de(Node_func_80285B64_de **list, Node_func_80285B64_de *node);
extern s32 func_8028CE78_de(void *table, s32 id);
extern void func_80264DE0_de(void *slot, s32 handle);

static inline void bind(Node_func_80285B64_de *node, s32 offset, s32 id) {
    func_80264DE0_de((char *)node + offset, func_8028CE78_de(&D_8011FE88, id));
}

static inline void init(Node_func_80285B64_de *node, Clip *key, Vec3 position, f32 value0, f32 value1, Node_func_80285B64_de **owner) {
    node->key = key;
    node->position = position;
    node->value0 = value0;
    node->value1 = value1;
    node->owner = owner;
    if (owner != 0) {
        *owner = node;
    }
    bind(node, 0x20, key->mode);
    bind(node, 0x2C, key->frames);
}

Node_func_80285B64_de *func_80285B64_de(Pool_func_80285B64_de *pool, Clip *key, Vec3 position, f32 value0, f32 value1, Node_func_80285B64_de **owner) {
    s32 mask;
    Node_func_80285B64_de *node;

    mask = func_802BCF30_de();
    node = pool->free;
    if (node != 0) {
        func_80255ED8_de(pool, node);
        func_80255D14_de(&pool->active, node);
        init(node, key, position, value0, value1, owner);
    }
    func_802BCF50_de(mask);
    return node;
}
