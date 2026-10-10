#ifndef UNBAKE_SPAN_16E000_CODE_80444EC0_H
#define UNBAKE_SPAN_16E000_CODE_80444EC0_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_25168ac75dfe83a275e1a77c */
extern void func_80444E70_de(s16 *record);

struct Options_func_80444D50_de;
/* unbake published declaration: published_2a5f6d62f13f732d50a9ff59 */
struct Options_func_80444D50_de {
    s32 flags;
    s32 pad4[3];
    s32 value;
};

struct OptionEditState;
/* unbake published declaration: published_462f25d66cf8f6aead9bbaad */
struct OptionEditState {
    char p[20];
    s32 *unk_14;
    char q[4];
    struct OptionEditState *unk_1C;
    s32 unk_20;
    char r[52];
    s32 unk_58;
    char a[1408];
    struct OptionEditState *unk_5DC;
};

struct OptionEditContext;
struct Shape_typemap_13;
/* unbake published declaration: published_6195794046218d83a4fcf814 */
struct OptionEditContext {
    char pad0[0x8];
    struct Shape_typemap_13 unk_8;
};

/* unbake published declaration: published_b518b4c0959eec69c9484c6a */
extern s32 func_80444EB4_de(void);

struct OptionEditContext;
/* unbake published declaration: published_c72531bcb1001b3895a614af */
typedef struct OptionEditContext OptionEditContext;

struct OptionEditState;
/* unbake published declaration: published_c7d379118a6fc56a528bc319 */
typedef struct OptionEditState OptionEditState;

/* unbake published declaration: published_e5051392cdad9c6945878a97 */
extern s32 func_80444E7C_de(void);

extern int func_80444E30_de(void);

struct Item_func_80441FE8_de;
#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_804451D0_de(struct Item_func_80441FE8_de *field);
#endif


#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445ECC(struct Item_func_80441FE8_de *field);
#endif


#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445AB8(struct Item_func_80441FE8_de *field);
#endif

#endif
