#ifndef UNBAKE_SPAN_1000_CODE_80254CE4_H
#define UNBAKE_SPAN_1000_CODE_80254CE4_H
#include "../types.h"
#include "common/draft_fields_func_80255630_de.h"
#include "resident_event_handler.h"
struct func_80255428_S3;
/* unbake published declaration: published_045461a1dd2b8d4beae95fea */
struct func_80255428_S3 {
    char pad0[0xC];
    s32 * unkC;
};

struct Entry_func_80255048_de;
/* unbake published declaration: published_125696dde62088ca0d50b87d */
struct Entry_func_80255048_de {
    char pad0[0xC];
    s32 flags;
    s32 stamp;
    s32 pad14;
    struct Entry_func_80255048_de *next;
};

struct EntryList;
struct Entry_func_80255048_de;
/* unbake published declaration: published_1a35f00ad220ce2b9ddf2e25 */
struct EntryList {
    s32 pad0;
    struct Entry_func_80255048_de *first;
};

struct Pool80255720;
/* unbake published declaration: published_1b2e87be51281e2dfd4c34b5 */
typedef struct Pool80255720 Pool80255720;

struct EntryList;
/* unbake published declaration: published_1bfeea0e204e48514d8f7e3a */
typedef struct EntryList EntryList;

union func_80255428_S1_UC;
/* unbake published declaration: published_2454ca53adeff867294024af */
typedef union func_80255428_S1_UC func_80255428_S1_UC;

struct Entry_func_802553B4_de;
/* unbake published declaration: published_307e00adaba3b5ee6da804de */
typedef struct Entry_func_802553B4_de Entry_func_802553B4_de;

struct Block80255720;
/* unbake published declaration: published_37434993fe264f2e6c89bf06 */
struct Block80255720 {
    struct Block80255720 *prev;
    struct Block80255720 *next;
    struct Block80255720 *prev_phys;
    struct Block80255720 *next_phys;
    s32 offset;
    s32 size;
};

struct Block80255720;
/* unbake published declaration: published_4d314ac55639218413f392c1 */
typedef struct Block80255720 Block80255720;

struct Pool80255ACC;
/* unbake published declaration: published_3eb66d694750fd43588f89a1 */
struct Pool80255ACC {
    s32 unk0;
    s32 unk4;
    Block80255720 *head;
    Block80255720 *tail;
};

struct Entry_func_802553B4_de;
/* unbake published declaration: published_5011b85c9ddb578815e0d99f */
struct Entry_func_802553B4_de {
    u32 key;
    s32 value;
    s32 index;
    struct Entry_func_802553B4_de *next;
};

struct func_80255428_S3;
/* unbake published declaration: published_510517ac103df9968e45e8ab */
typedef struct func_80255428_S3 func_80255428_S3;

struct Slot_func_802552E0_de;
/* unbake published declaration: published_5275d2499eae2c164ac21fdd */
struct Slot_func_802552E0_de {
    s32 key;
    s32 value;
    u32 index;
    struct Slot_func_802552E0_de *next;
};

union func_80255428_S1_UC;
/* unbake published declaration: published_6745ba3e286e03484d06c387 */
union func_80255428_S1_UC {
    s32 * v0;
    s32 v1;
};

struct Heap_func_80255920_de;
/* unbake published declaration: published_69b8ef8a0ffc76780319fc12 */
typedef struct Heap_func_80255920_de Heap_func_80255920_de;

struct func_802551C8_S1;
/* unbake published declaration: published_6e9c4615b724a50441d8b3cf */
typedef struct func_802551C8_S1 func_802551C8_S1;

struct Block_func_80255920_de;
/* unbake published declaration: published_7233a371d0fc27c84613b070 */
struct Block_func_80255920_de {
    struct Block_func_80255920_de *prevFree;
    struct Block_func_80255920_de *nextFree;
    struct Block_func_80255920_de *prev;
    struct Block_func_80255920_de *next;
    u32 size;
    u32 free;
};

struct Entry_func_80255048_de;
/* unbake published declaration: published_784b36c4d958803c98e79326 */
typedef struct Entry_func_80255048_de Entry_func_80255048_de;

/* unbake published declaration: published_7cd7beb42dc0251ddac38686 */
extern void func_80255488_de(s32 arg0);

struct Block80255720;
struct Pool80255720;
/* unbake published declaration: published_d7efa28b05fd07c2434fac46 */
struct Pool80255720 {
    s32 unk0;
    s32 unk4;
    struct Block80255720 *head;
    struct Block80255720 *tail;
    struct Block80255720 *anchor;
};

/* unbake published declaration: published_7e61ce33f53dd0084e1127fa */
extern void func_80255780_de(Pool80255720 *arg0);

/* unbake published declaration: published_8513e828ffb8a2ded20fe61c */
extern s32 func_80255540_de(s32 arg0);

struct func_80255428_S2;
/* unbake published declaration: published_95a33efee409bffb8b393664 */
typedef struct func_80255428_S2 func_80255428_S2;

struct Block_func_802558B4_de;
/* unbake published declaration: published_d15be43a69ce6a7d9d2deff0 */
struct Block_func_802558B4_de {
    struct Block_func_802558B4_de *next;
    struct Block_func_802558B4_de *previous;
    s32 a;
    s32 b;
    s32 header;
    s32 size;
};

struct Block_func_802558B4_de;
struct Heap;
/* unbake published declaration: published_a02c79920a46a5d8f672f4b8 */
struct Heap {
    char *start;
    char *end;
    struct Block_func_802558B4_de *free;
    struct Block_func_802558B4_de *last;
    struct Block_func_802558B4_de *first;
};

struct Slot_func_802552E0_de;
/* unbake published declaration: published_abe0511c0dab1894ec4b2030 */
typedef struct Slot_func_802552E0_de Slot_func_802552E0_de;

struct Block_func_80255920_de;
struct Heap_func_80255920_de;
/* unbake published declaration: published_b6fae899c01d1846abdc36a5 */
struct Heap_func_80255920_de {
    char pad0[8];
    struct Block_func_80255920_de *head;
    struct Block_func_80255920_de *tail;
};

struct func_80255110_S2;
/* unbake published declaration: published_c0b2a5e50c75ed6737704572 */
struct func_80255110_S2 {
    char pad0[0x230];
    s32 unk230;
};

struct Pool80255ACC;
/* unbake published declaration: published_c2bf235983211202905435a0 */
typedef struct Pool80255ACC Pool80255ACC;

struct func_80255110_S2;
/* unbake published declaration: published_d823235aad853495bf67de5d */
typedef struct func_80255110_S2 func_80255110_S2;

struct func_80255428_S1;
/* unbake published declaration: published_de1f7cbe29b7be0cf800e2c2 */
struct func_80255428_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    func_80255428_S1_UC unkC;
};

struct Block_func_80255920_de;
/* unbake published declaration: published_e349fd73150068f924489ee6 */
typedef struct Block_func_80255920_de Block_func_80255920_de;

/* unbake published declaration: published_e65333b9c3055f24dd4dc4f7 */
extern void func_802552E0_de(s32 capacity);

struct func_80255428_S1;
/* unbake published declaration: published_ee6093f0bede11040bc86ed6 */
typedef struct func_80255428_S1 func_80255428_S1;

struct func_80255428_S2;
/* unbake published declaration: published_ef32df4718c0aa44c26962d7 */
struct func_80255428_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 * unkC;
};

struct func_802551C8_S1;
/* unbake published declaration: published_fa87d24bf4dcac4df450408b */
struct func_802551C8_S1 {
    char pad0[0x238];
    s32 unk238;
};

extern s32 D_80100560;

#endif
