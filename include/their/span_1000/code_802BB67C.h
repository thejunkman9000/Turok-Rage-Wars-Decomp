#ifndef UNBAKE_SPAN_1000_CODE_802BB67C_H
#define UNBAKE_SPAN_1000_CODE_802BB67C_H
#include "../types.h"
struct Node802C07B0;
/* unbake published declaration: published_05e4417f27fad02a33c4521d */
typedef struct Node802C07B0 Node802C07B0;

struct Node_func_802BB9F8_de;
/* unbake published declaration: published_1287e5bf20c271a75bfd989e */
struct Node_func_802BB9F8_de {
    void *next;
    void *prev;
    u64 field8;
    u64 field10;
    s32 field18;
    s32 field1C;
};

struct Node802C07B0;
/* unbake published declaration: published_1298ced7750465d5b9f5e87e */
struct Node802C07B0 {
    s32 field0;
    s32 field4;
    u64 field8;
    u64 field10;
    void *field18;
    void *field1C;
};

/* unbake published declaration: published_4fa9db80beb44cb71d6ec826 */
extern void func_802BB9F8_de();

/* unbake published declaration: published_589dede4ffe442e522f349ec */
extern void func_802BBC20_de();

/* unbake published declaration: published_71ef9c311cee9588203fdb18 */
extern void func_802BBA4C_de(u64 interval);

struct ThreadNode;
/* unbake published declaration: published_75ee48439baed9bf398878fe */
struct ThreadNode {
    struct ThreadNode *next;
    s32 priority;
    struct ThreadNode **queue;
    s32 unk0C;
    u16 state;
};

struct ThreadNode;
/* unbake published declaration: published_97e9d3a7ca67229e01f188b2 */
typedef struct ThreadNode ThreadNode;

struct Node_func_802BB9F8_de;
/* unbake published declaration: published_dc6a9b18b039a14b121ce4c3 */
typedef struct Node_func_802BB9F8_de Node_func_802BB9F8_de;

#endif
