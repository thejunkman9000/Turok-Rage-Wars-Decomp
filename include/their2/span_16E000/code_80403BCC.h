#include "types.h"
#ifndef UNBAKE_SPAN_16E000_CODE_80403BCC_H
#define UNBAKE_SPAN_16E000_CODE_80403BCC_H
#include "../types.h"
struct OSPfs_func_80403E90_de;
/* unbake published declaration: published_004e2b8bec5ffcce69b921cc */
typedef struct OSPfs_func_80403E90_de OSPfs_func_80403E90_de;

struct Entry_func_80405338_de;
/* unbake published declaration: published_011300264b2058f0ff134143 */
struct Entry_func_80405338_de {
    char data[32];
};

struct Menu_func_80403BE0_de;
/* unbake published declaration: published_013696cdd9b7f72332b6eb78 */
struct Menu_func_80403BE0_de {
    char pad[0x34];
    int group;
    char pad38[0x3C];
    int id;
};

struct Record_func_80403E10_de;
/* unbake published declaration: published_1309ed83534a0323451030aa */
typedef struct Record_func_80403E10_de Record_func_80403E10_de;

/* unbake published declaration: published_21f0806d92abe8ebd0adbc81 */
extern int func_80403BE0_de();

struct Entry_func_804053E0_de;
/* unbake published declaration: published_b88b69cd6b9885c7860ca4a9 */
struct Entry_func_804053E0_de {
    s32 size;
    char data[28];
};

struct Entry_func_804053E0_de;
struct Record_func_804053E0_de;
/* unbake published declaration: published_2a2afdc7171d7f40fe06b951 */
struct Record_func_804053E0_de {
    s32 header;
    struct Entry_func_804053E0_de entries[16];
};

struct NoteState;
/* unbake published declaration: published_2bc374a825995824a2135759 */
struct NoteState {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    char ext_name[4];
    char game_name[16];
    char pad[2];
};

/* unbake published declaration: published_3122d4789195821fd3636d80 */
extern f32 func_80403C58_de(f32 from, f32 to, f32 t);

/* unbake published declaration: published_419b793d42c07ee23e8bcb5b */
extern s32 func_80403BCC_de(void);

/* unbake published declaration: published_47b5a317cfc575d516d7e9d2 */
extern unsigned char * D_800D36DC;

/* unbake published declaration: published_4a75c944c83923d135bd0b68 */
extern void func_80403DE8_de(void);

struct NoteState_func_8040458C_de;
/* unbake published declaration: published_ed659289df7e606f3babab29 */
typedef struct NoteState_func_8040458C_de NoteState_func_8040458C_de;

struct NoteState_func_8040458C_de;
/* unbake published declaration: published_fffe8122cb3ee4a081db4c1d */
struct NoteState_func_8040458C_de {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    u8 ext_name[4];
    u8 game_name[16];
    char pad[2];
};

struct PakDirectory_func_8040458C_de;
/* unbake published declaration: published_58866b64743f8dad35af2a10 */
struct PakDirectory_func_8040458C_de {
    s32 free;
    NoteState_func_8040458C_de notes[16];
};

struct Entry_func_80405338_de;
struct Record_func_80405338_de;
/* unbake published declaration: published_66163c7d740c162cbe4caadf */
struct Record_func_80405338_de {
    s32 header;
    struct Entry_func_80405338_de entries[16];
};

struct PakDirectory;
/* unbake published declaration: published_8d304d79ff17c7d7a511dc96 */
typedef struct PakDirectory PakDirectory;

struct Device;
/* unbake published declaration: published_9298e54b10005db89bd0e952 */
typedef struct Device Device;

struct Record_func_80403E10_de;
/* unbake published declaration: published_9d0609c7892d4316f4e53f09 */
struct Record_func_80403E10_de {
    char pad[0x11];
    unsigned char kind;
    unsigned char subtype;
};

struct Device;
/* unbake published declaration: published_9d33b6900b09315b450c116e */
struct Device {
    s8 pad0[0x68];
};

struct NoteState;
/* unbake published declaration: published_f3c80236f8339bd141232d0f */
typedef struct NoteState NoteState;

struct PakDirectory;
/* unbake published declaration: published_a098445dd5c9c25f01864301 */
struct PakDirectory {
    s32 free;
    NoteState notes[16];
};

/* unbake published declaration: published_aa3b6be379b1712a13ee5623 */
extern f32 func_80403C98_de(f32 from, f32 to, f32 weight);

struct OSPfs_func_80403E90_de;
/* unbake published declaration: published_b1876b5a60d0b8f14479037d */
struct OSPfs_func_80403E90_de {
    char pad[0x68];
};

struct Menu_func_80403BE0_de;
/* unbake published declaration: published_b536b3ca16cf976472230984 */
typedef struct Menu_func_80403BE0_de Menu_func_80403BE0_de;

struct PakDirectory_func_8040458C_de;
/* unbake published declaration: published_cefd4eafa9e2b46db0d0c9e0 */
typedef struct PakDirectory_func_8040458C_de PakDirectory_func_8040458C_de;

/* unbake published declaration: published_ecb6d5f01b93e0aeae164d0b */
extern s32 func_804053E0_de(s32 index, s32 entry, s32 *out);

/* unbake published declaration: published_ed54d139e16275628ec46d83 */
extern void func_80404DDC_de(void);

extern int func_804041E8_de(void);
void func_80404D84_de(void);
#endif
