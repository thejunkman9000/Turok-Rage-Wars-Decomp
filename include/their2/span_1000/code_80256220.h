#ifndef UNBAKE_SPAN_1000_CODE_80256220_H
#define UNBAKE_SPAN_1000_CODE_80256220_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Chunk_func_80256454_de;
/* unbake published declaration: published_07b27a6457d5aa8896bf9e24 */
typedef struct Chunk_func_80256454_de Chunk_func_80256454_de;

struct CartridgeReadWorker;
/* unbake published declaration: published_10f9e83a8c5d9240b662eefd */
struct CartridgeReadWorker {
    u8 reserved[0x230];
    u8 requestQueueStorage;
    u8 reserved231[0xA48 - 0x231];
    u8 completionQueueStorage;
};

struct func_802566A8_S1;
/* unbake published declaration: published_14ccacd3811bdac9e3d22473 */
struct func_802566A8_S1 {
    char pad0[0x5068];
    char unk5068;
    char pad5068[0x507C - 0x5068 - sizeof(char)];
    char unk507C;
};

struct func_802566A8_S1;
/* unbake published declaration: published_1799cea1a047582d9198d5b8 */
typedef struct func_802566A8_S1 func_802566A8_S1;

struct func_8025631C_S1;
/* unbake published declaration: published_218994c2c236214c7bebb275 */
struct func_8025631C_S1 {
    char pad0[0x230];
    char unk230;
};

struct Handles;
/* unbake published declaration: published_29fc1527f83f17a215342d48 */
typedef struct Handles Handles;

struct Item57BD4;
/* unbake published declaration: published_2a33848bb491d1088f7d503a */
typedef struct Item57BD4 Item57BD4;

struct Chunk;
/* unbake published declaration: published_2fd72050322a9dc45086a183 */
struct Chunk {
    void *source;
    void *destination;
    s32 length;
    void *queue;
};

/* unbake published declaration: published_371b9c65e07f3b7db9c3344b */
extern void func_802567D0_de();

struct func_8025663C_S1;
/* unbake published declaration: published_3997c3b6c319542b49717abe */
struct func_8025663C_S1 {
    char pad0[0x5068];
    IntrusiveList unk5068;
    char pad5068[0x507C - 0x5068 - sizeof(IntrusiveList)];
    char unk507C;
};

/* unbake published declaration: published_3b2a515897f177d656052295 */
extern int D_800CB708;

struct func_8025844C_S1;
/* unbake published declaration: published_42c7e15038664af720ebfc4d */
struct func_8025844C_S1 {
    char pad0[0x104];
    s32 unk104;
    char pad104[0x134 - 0x104 - sizeof(s32)];
    s32 unk134;
    char pad134[0x1DB8 - 0x134 - sizeof(s32)];
    void * unk1DB8;
    char pad1DB8[0x2BA0 - 0x1DB8 - sizeof(void*)];
    f32 unk2BA0;
    char pad2BA0[0x2BA4 - 0x2BA0 - sizeof(f32)];
    f32 unk2BA4;
    char pad2BA4[0x2BA8 - 0x2BA4 - sizeof(f32)];
    f32 unk2BA8;
    char pad2BA8[0x2BB0 - 0x2BA8 - sizeof(f32)];
    s32 unk2BB0;
    char pad2BB0[0x2BB4 - 0x2BB0 - sizeof(s32)];
    s32 unk2BB4;
};

/* unbake published declaration: published_4a1611cf17947173b11204e8 */
extern int D_800CB714;

struct CartridgeReadRequest;
/* unbake published declaration: published_4cc1848bc5cf9db8b9ab70b0 */
struct CartridgeReadRequest {
    u32 devAddr;
    void *buffer;
    s32 size;
    void *replyQueue;
    void *replyMsg;
};

struct func_8025631C_S1;
/* unbake published declaration: published_5fdb4977edfba083a3e28a8f */
typedef struct func_8025631C_S1 func_8025631C_S1;

struct Chunk_func_80256454_de;
struct Queue;
/* unbake published declaration: published_654b14b818922d3de31b976e */
struct Chunk_func_80256454_de {
    void *source;
    void *destination;
    s32 length;
    struct Queue *queue;
    s32 value;
};

/* unbake published declaration: published_683458b17224779cd3e34427 */
extern u32 func_802571F0_de(s32 offset, s32 length);

struct Window;
/* unbake published declaration: published_6ff32aeacce86ed0c0c69ee1 */
typedef struct Window Window;

struct Handles;
/* unbake published declaration: published_fcdedd67a944ec8676030449 */
struct Handles {
    char pad0[0x60];
    s16 handles[17];
};

struct func_80257A34_S1;
/* unbake published declaration: published_71480ad655bed6538f6029e2 */
struct func_80257A34_S1 {
    char pad0[0x7C];
    Handles unk7C;
    char pad7C[0x110 - 0x7C - sizeof(Handles)];
    char unk110;
    char pad110[0x138 - 0x110 - sizeof(char)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
    char pad1DB8[0x1DBC - 0x1DB8 - sizeof(char)];
    char unk1DBC;
};

/* unbake published declaration: published_78321ff48ed95117476198c2 */
extern int D_801076A0;

struct Chunk;
/* unbake published declaration: published_7b73b4bfb0a99fedf73517d3 */
typedef struct Chunk Chunk;

struct Item57BD4;
/* unbake published declaration: published_81ea3d2ee5342d06cf91f7b5 */
struct Item57BD4 {
    s16 field0;
    s16 field2;
    s16 field4;
    u16 flags;
};

struct Window;
/* unbake published declaration: published_821eb52ed20ecea3b6b8c6be */
struct Window {
    struct Window *next;
    struct Window *prev;
    u32 base;
    s32 frame;
    s32 buffer;
};

struct Voice;
/* unbake published declaration: published_8d20c9ca3e1ff8c12f390ca7 */
typedef struct Voice Voice;

struct Node_func_80256FC0_de;
/* unbake published declaration: published_90fa643b9f16f6dac6a652bf */
struct Node_func_80256FC0_de {
    struct Node_func_80256FC0_de *prev;
    struct Node_func_80256FC0_de *next;
    s32 field8;
    u32 age;
};

/* unbake published declaration: published_92fe323e16b89451d27de51f */
extern s32 * func_80256E6C_de(s32 * * arg0);

/* unbake published declaration: published_942a55b90581ff5a0892104e */
extern int D_800CD8C4_de;

struct Voice;
/* unbake published declaration: published_94bfc509575194cc406b8cbe */
struct Voice {
    s32 unk0;
    s32 sound;
    s32 unk8;
    s32 unkC;
    char pad10[0x28];
    s16 priority;
    s16 channel;
    char pad3C[0x64];
    s32 pending;
    s32 flags;
    char padA8[0x24];
};

struct func_80257BD4_S1;
/* unbake published declaration: published_9886e007b39bfc599651d29d */
typedef struct func_80257BD4_S1 func_80257BD4_S1;

struct CartridgeReadWorker;
/* unbake published declaration: published_a585e414e73ea4238c1fca45 */
typedef struct CartridgeReadWorker CartridgeReadWorker;

struct Node_func_80256FC0_de;
/* unbake published declaration: published_a7f4f4730b25ba436295aee3 */
typedef struct Node_func_80256FC0_de Node_func_80256FC0_de;

struct func_80257BD4_S1;
/* unbake published declaration: published_ac566d6a5651f4b0a76bb1e4 */
struct func_80257BD4_S1 {
    char pad0[0x110];
    char unk110;
    char pad110[0x138 - 0x110 - sizeof(char)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
    char pad1DB8[0x2B8C - 0x1DB8 - sizeof(char)];
    s16 unk2B8C;
    char pad2B8C[0x2B90 - 0x2B8C - sizeof(s16)];
    s32 unk2B90;
    char pad2B90[0x2B98 - 0x2B90 - sizeof(s32)];
    void * unk2B98;
};

struct ObjectLinksC;
/* unbake published declaration: published_b41c9c95077595293077342a */
struct ObjectLinksC {
    u8 unk_0;
    unsigned char padding_1[3];
    s32 unk_4;
    s32 *unk_8;
};

struct CacheEntry;
/* unbake published declaration: published_bbcddc0b1600da70fbf6d2a2 */
struct CacheEntry {
    struct CacheEntry *next;
    void *key;
    u16 state;
    u16 size;
    s32 padC;
    char data[0x80];
};

struct func_80257A34_S1;
/* unbake published declaration: published_bf2cb5508b794be5c366dfb5 */
typedef struct func_80257A34_S1 func_80257A34_S1;

struct ObjectLinksC;
/* unbake published declaration: published_c167377f0f3fe33ead5c8511 */
typedef struct ObjectLinksC ObjectLinksC;

struct CartridgeReadRequest;
/* unbake published declaration: published_cb803780a83fbab7b4c2c4be */
typedef struct CartridgeReadRequest CartridgeReadRequest;

struct func_8025663C_S1;
/* unbake published declaration: published_cc00ff5d5576fc32bc8ea265 */
typedef struct func_8025663C_S1 func_8025663C_S1;

struct CacheEntry;
/* unbake published declaration: published_e73e6506dcd77d0eec43a7b6 */
typedef struct CacheEntry CacheEntry;

/* unbake published declaration: published_d23e37f17c21a6c2b01375ff */
extern s32 func_80256EA8_de(Work56EC8 *arg0);

struct func_8025844C_S1;
/* unbake published declaration: published_e5c4b9d11970f72fb62ca1ef */
typedef struct func_8025844C_S1 func_8025844C_S1;

#endif
