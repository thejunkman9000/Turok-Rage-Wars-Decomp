#ifndef UNBAKE_SPAN_1000_CODE_802AE028_H
#define UNBAKE_SPAN_1000_CODE_802AE028_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ObjectState10_2;
/* unbake published declaration: published_04dd50314abc3839e62b3c53 */
typedef struct ObjectState10_2 ObjectState10_2;

/* unbake published declaration: published_0796f670cb5200762abb22ce */
extern float D_800C7340_de;

struct func_802B3B80_S1;
/* unbake published declaration: published_0bd292649901bb93a8ee5d59 */
typedef struct func_802B3B80_S1 func_802B3B80_S1;

struct CopyDest802B3998;
/* unbake published declaration: published_0c355228b550dacb0864724b */
typedef struct CopyDest802B3998 CopyDest802B3998;

struct func_802B4220_S1;
/* unbake published declaration: published_117c8c3bc698903219506b12 */
struct func_802B4220_S1 {
    char pad0[0x18];
    s32 unk18;
    char pad18[0x24 - 0x18 - sizeof(s32)];
    s32 unk24;
    char pad24[0x2C - 0x24 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x48 - 0x2C - sizeof(s32)];
    char unk48;
};

struct CallbackNode;
/* unbake published declaration: published_188458e683ef2da7313c1753 */
struct CallbackNode {
    s32 state;
    struct CallbackNode *self;
    void *callback;
};

struct ALCSeq_s;
/* unbake published declaration: published_1b14434df26065b380b06182 */
typedef struct ALCSeq_s ALCSeq_s;

struct ALCSeqMarker;
/* unbake published declaration: published_1e50ee1a2be2393deb9fcf6f */
struct ALCSeqMarker {
    u32 validTracks;
    s32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
};

struct func_802B4220_S1;
/* unbake published declaration: published_28ac1f494e8c58c1495dfb7c */
typedef struct func_802B4220_S1 func_802B4220_S1;

struct ALCMidiHdr;
/* unbake published declaration: published_295745d87363764d92b8b37b */
struct ALCMidiHdr {
    u32 trackOffset[16];
    u32 division;
};

/* unbake published declaration: published_2c8f81d30b8edfd8bb457eb1 */
extern double D_800C7318_de;

/* unbake published declaration: published_314965b578d2d134c5475c60 */
extern f32 func_802AE7BC_de(void **arg0, s32 arg1, s32 arg2);

struct InitParams;
/* unbake published declaration: published_3cd19b1416d161cde5f8b6f8 */
struct InitParams {
    s32 count38;
    s32 count1C;
    u8 kind;
    u8 pad09[3];
    s32 context;
    s32 value10;
    s32 value14;
    s32 value18;
};

/* unbake published declaration: published_3d011662c268acdc65b95771 */
extern double D_800C7310_de;

struct ObjectState4C;
/* unbake published declaration: published_3f3feba93522ab7fe0dd5b68 */
typedef struct ObjectState4C ObjectState4C;

struct func_802B4E3C_S1;
/* unbake published declaration: published_41d9c3ea27d1da5a24b993f0 */
typedef struct func_802B4E3C_S1 func_802B4E3C_S1;

struct ResourceTable;
/* unbake published declaration: published_43e046ecb60e569d692dafba */
typedef struct ResourceTable ResourceTable;

struct DecodeResult_func_802AE6BC_de;
/* unbake published declaration: published_45da19a68f59d8771cf05077 */
struct DecodeResult_func_802AE6BC_de {
    s16 type;
    u8 pad2[2];
    u32 value;
    u8 pad8[8];
};

struct ObjectLinks4_5;
/* unbake published declaration: published_46dc549c87febdeb87819e7d */
typedef struct ObjectLinks4_5 ObjectLinks4_5;

/* unbake published declaration: published_4c091a2bc6d27e6dc782c143 */
extern double D_800C7300_de;

/* unbake published declaration: published_52eccffa7460d74f7002c807 */


struct ALCMidiHdr;
/* unbake published declaration: published_531220a59f14b8f3a8458263 */
typedef struct ALCMidiHdr ALCMidiHdr;

struct func_802B3B80_S1;
/* unbake published declaration: published_57c84aac9dd875292af256e7 */
struct func_802B3B80_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s16 unk30;
    char pad30[0x32 - 0x30 - sizeof(s16)];
    s16 unk32;
    char pad32[0x34 - 0x32 - sizeof(s16)];
    u8 unk34;
    char pad34[0x38 - 0x34 - sizeof(u8)];
    s16 unk38;
    char pad38[0x5C - 0x38 - sizeof(s16)];
    s32 unk5C;
    char pad5C[0x60 - 0x5C - sizeof(s32)];
    s32 unk60;
    char pad60[0x64 - 0x60 - sizeof(s32)];
    s32 unk64;
    char pad64[0x68 - 0x64 - sizeof(s32)];
    s32 unk68;
    char pad68[0x6C - 0x68 - sizeof(s32)];
    func_8028472C_S2_U118 unk6C;
    char pad6C[0x70 - 0x6C - sizeof(func_8028472C_S2_U118)];
    s32 unk70;
    char pad70[0x74 - 0x70 - sizeof(s32)];
    s32 unk74;
    char pad74[0x78 - 0x74 - sizeof(s32)];
    s32 unk78;
};

struct CopySource802B3998;
/* unbake published declaration: published_585c585b305c1011f69fb611 */
struct CopySource802B3998 {
    int word0;
    int word4;
    int word8;
    int wordsC[16];
    int words4C[16];
    unsigned char bytes8C[16];
    unsigned char bytes9C[16];
    int wordsAC[16];
};

struct CallbackNode;
/* unbake published declaration: published_59178e4ef4ff544b28c17f3a */
typedef struct CallbackNode CallbackNode;

struct Node_func_802AFD6C_de;
/* unbake published declaration: published_c2b9f745b4041770bc6f04c3 */
struct Node_func_802AFD6C_de {
    struct Node_func_802AFD6C_de *prev;
    struct Node_func_802AFD6C_de *next;
    s32 value;
    short type;
};

struct Node_func_802AFD6C_de;
struct func_802B4E3C_S1;
/* unbake published declaration: published_5bd193ec497f7d26e56486be */
struct func_802B4E3C_S1 {
    char pad0[0x8];
    struct Node_func_802AFD6C_de * unk8;
};

struct Node_func_802AFD6C_de;
/* unbake published declaration: published_71d6f4583e7c55a6e97028fe */
typedef struct Node_func_802AFD6C_de Node_func_802AFD6C_de;

struct ObjectLinks54_2;
/* unbake published declaration: published_6bcac5221796ba73eb7c2f0f */
struct ObjectLinks54_2 {
    unsigned char padding[80];
    Node_func_802AFD6C_de * link;
};

/* unbake published declaration: published_74d2c363bd98f33032d3bdac */
extern u32 func_802AE824_de(void **arg0, f32 arg1, s32 arg2);

struct RuntimeState;
/* unbake published declaration: published_799c71544c30f374162d59cb */
typedef struct RuntimeState RuntimeState;

struct ValueSet;
/* unbake published declaration: published_816cbefea6aa056496de4fa9 */
typedef struct ValueSet ValueSet;

struct RuntimeState;
/* unbake published declaration: published_8aa3adbf2f11d04f34fb23e1 */
struct RuntimeState {
    void *resources;
    u32 active;
    u32 scale;
    u32 total;
    u32 previous;
    u32 first;
    u8 *objects[16];
    u32 values[16];
    u8 flags98[16];
    u8 flagsA8[16];
    u32 results[16];
};

struct InitParams;
/* unbake published declaration: published_8cc9258e99ffb52feadb14d6 */
typedef struct InitParams InitParams;

/* unbake published declaration: published_8de01b16f233f7dac4447196 */
extern float D_800C7330_de;

struct DecodeResult;
/* unbake published declaration: published_8f8c6d4876789d1ca0677274 */
struct DecodeResult {
    s16 type;
    u8 pad2[6];
    u8 status;
    u8 first_data;
    u8 second_data;
    u8 extra1;
    u32 extra2;
};

/* unbake published declaration: published_a32ece83066792b62eb0903b */


struct ObjectLinks54_2;
/* unbake published declaration: published_a5a068b86cef295fcbf79d08 */
typedef struct ObjectLinks54_2 ObjectLinks54_2;

/* unbake published declaration: published_a81cdfb347d0421bc41e5942 */
extern float D_800C7320_de;

struct DecodeResult_func_802AE6BC_de;
/* unbake published declaration: published_aa482df5318d43931139a9d5 */
typedef struct DecodeResult_func_802AE6BC_de DecodeResult_func_802AE6BC_de;

struct ALCMidiHdr;
struct ALCSeq_s;
/* unbake published declaration: published_ab5073f2eb3eef6adb107de1 */
struct ALCSeq_s {
    struct ALCMidiHdr *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
};

/* unbake published declaration: published_b4a076dd2634a0deeff7d38d */


struct ValueSet;
/* unbake published declaration: published_bc5615ff3d4b2554c3acee3e */
struct ValueSet {
    char pad0[4];
    u32 mask;
    char pad8[8];
    u32 amount;
    s32 active;
    char pad18[0xA0];
    u32 values[16];
};

struct ObjectLinks4_5;
/* unbake published declaration: published_c53ebdf9114fd6de4583c60c */
struct ObjectLinks4_5 {
    Node_func_802AFD6C_de * link;
};

/* unbake published declaration: published_c919416d01b241acdb697ed0 */
extern int func_802AE7B0_de(void *arg0);

struct CopySource802B3998;
/* unbake published declaration: published_c9830dbec948ad11a15b5e13 */
typedef struct CopySource802B3998 CopySource802B3998;

struct CopyDest802B3998;
/* unbake published declaration: published_d757e50f6872d904b4bd5c29 */
struct CopyDest802B3998 {
    int pad0;
    int word4;
    int pad8;
    int wordC;
    int word10;
    int pad14;
    int words18[16];
    int words58[16];
    unsigned char bytes98[16];
    unsigned char bytesA8[16];
    int wordsB8[16];
};

/* unbake published declaration: published_d0d766ac96bde118f5020e3e */
extern void func_802AE93C_de(CopyDest802B3998 *src, CopySource802B3998 *dst);

/* unbake published declaration: published_d5a2b8e06ec9d4042842b601 */
extern void func_802AE8C8_de(CopyDest802B3998 *dst, CopySource802B3998 *src);

/* unbake published declaration: published_d5ef8877b8553c8c06b83da0 */
extern float D_800C7308_de;

struct ObjectState10_2;
/* unbake published declaration: published_e24a58c0d51f6f21df61b0e7 */
struct ObjectState10_2 {
    s16 type;
    u8 pad2[6];
    u8 unk_8;
    u8 unk_9;
    u8 padA;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 padE[2];
};

/* unbake published declaration: published_e53a293c8735a6e34dd5be2d */
extern double D_800C7338_de;

struct ALCSeqMarker;
/* unbake published declaration: published_ff44bea4240dfb7f4ad0a8c7 */
typedef struct ALCSeqMarker ALCSeqMarker;

/* unbake published declaration: published_ee27de925391815dc1c7245d */
extern void func_802AE290_de(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks);

struct DecodeResult;
/* unbake published declaration: published_f340bd4cfd5ad08beec8b02d */
typedef struct DecodeResult DecodeResult;

struct ResourceTable;
/* unbake published declaration: published_fe213f2506718195c4adbb52 */
struct ResourceTable {
    u32 entries[17];
};

struct ResourceTable;
struct RuntimeState_func_802AE5B8_de;
/* unbake published declaration: published_f7e288c9a46e510ca229650f */
struct RuntimeState_func_802AE5B8_de {
    struct ResourceTable *resources;
    u32 active;
    f32 scale;
    u32 unkC;
    u32 unk10;
    u32 one14;
    void *objects[16];
    u32 unk58[16];
    s8 flags98[16];
    s8 flagsA8[16];
    u32 results[16];
};

/* unbake published declaration: published_fb3ec561ef6b1038caea877d */
extern double D_800C7328_de;

struct ObjectState4C;
/* unbake published declaration: published_febae62e788c83015263ccf7 */
struct ObjectState4C {
    char pad0[0x24];
    s32 unk_24;
    char pad24[0x48 - 0x24 - sizeof(s32)];
    char unk_48;
};

struct RuntimeState_func_802AE5B8_de;
/* unbake published declaration: published_ff8517768b467e4a42decd9b */
typedef struct RuntimeState_func_802AE5B8_de RuntimeState_func_802AE5B8_de;

/* Process one compact-sequence MIDI message; O32/native all-version proof retained. */
void func_802AF2E0_de(void *object, Message_func_802AF150_de *message);

#endif
