#ifndef UNBAKE_SPAN_1000_CODE_802B0388_H
#define UNBAKE_SPAN_1000_CODE_802B0388_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ALBank_s;
/* unbake published declaration: published_00a82b1fdadfbd02634b0e6e */
typedef struct ALBank_s ALBank_s;

struct func_802B6BE4_S3;
/* unbake published declaration: published_04c03f1fc574f08bdb7ca2a9 */
struct func_802B6BE4_S3 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x1C - 0x14 - sizeof(void*)];
    s32 unk1C;
    char pad1C[0x48 - 0x1C - sizeof(s32)];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
};

struct ALKeyMap;
/* unbake published declaration: published_07b881f462c1e6e39a436cad */
struct ALKeyMap {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
};

struct ALVoiceState_s;
/* unbake published declaration: published_0a51cb033267c9db670a1600 */
struct ALVoiceState_s {
    struct ALVoiceState_s *next;
    ALVoice_s voice;
    void *sound;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
};

struct func_802B6B90_S3;
/* unbake published declaration: published_0e9005c84d7b63ecd5f908b0 */
struct func_802B6B90_S3 {
    u8 unk0;
    char pad0[0x1 - 0x0 - sizeof(u8)];
    u8 unk1;
    char pad1[0x2 - 0x1 - sizeof(u8)];
    u8 unk2;
    char pad2[0xC - 0x2 - sizeof(u8)];
    u16 unkC;
};

struct func_802B6B90_S1;
/* unbake published declaration: published_10fa31c5d87be0f8d38be107 */
typedef struct func_802B6B90_S1 func_802B6B90_S1;

struct func_802B66A0_S2;
/* unbake published declaration: published_145a884fab7ed3fb5c8107c9 */
typedef struct func_802B66A0_S2 func_802B66A0_S2;

struct func_802B6BE4_S2;
/* unbake published declaration: published_16dab254cc8759c313166356 */
struct func_802B6BE4_S2 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x30 - 0x24 - sizeof(s32)];
    u8 unk30;
    char pad30[0x33 - 0x30 - sizeof(u8)];
    u8 unk33;
    char pad33[0x34 - 0x33 - sizeof(u8)];
    u8 unk34;
};

/* unbake published declaration: published_1aa599da8a0a684269cfab5e */


struct func_802B6D04_S1;
/* unbake published declaration: published_1af99d31fadad63c252f5471 */
typedef struct func_802B6D04_S1 func_802B6D04_S1;

struct ALInstrument;
/* unbake published declaration: published_4cb1dc53584155c0e701e111 */
typedef struct ALInstrument ALInstrument;

struct ALSound_s;
/* unbake published declaration: published_505d418350c61c1efbc93703 */
typedef struct ALSound_s ALSound_s;

struct ALKeyMap;
/* unbake published declaration: published_46c3dda5c9039c56f1ee3df4 */
typedef struct ALKeyMap ALKeyMap;

struct ALEnvelope;
/* unbake published declaration: published_677fb33ff7cb189eada3903f */
struct ALEnvelope {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
};

struct ALEnvelope;
/* unbake published declaration: published_d6b788a75899b2cbd9732529 */
typedef struct ALEnvelope ALEnvelope;

struct ALSound_s;
/* unbake published declaration: published_ce8fd87c9e7646e2cf48bc40 */
struct ALSound_s {
    ALEnvelope *envelope;
    ALKeyMap *keyMap;
    void *wavetable;
};

struct ALInstrument;
/* unbake published declaration: published_6d58f3608a4aae33abc0cae5 */
struct ALInstrument {
    u8 volume;
    u8 pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSound_s *soundArray[1];
};

struct ALChanState10;
/* unbake published declaration: published_1f07c927736d4e7c91e16300 */
struct ALChanState10 {
    ALInstrument *instrument;
    s16 bendRange;
    u8 fxId;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
};

struct func_802B6BE4_S4;
/* unbake published declaration: published_21e32ba92591a39289ba47c0 */
typedef struct func_802B6BE4_S4 func_802B6BE4_S4;

struct ALSeqPlayer;
/* unbake published declaration: published_2382d91b5db0091b23701d4d */
typedef struct ALSeqPlayer ALSeqPlayer;

struct func_802B67B0_S3;
/* unbake published declaration: published_2abbc805c2746ffcb94c27f6 */
struct func_802B67B0_S3 {
    char pad0[0x4];
    u8 * unk4;
};

struct func_802B6BE4_S2;
/* unbake published declaration: published_2b78410413f6257b66a3ab59 */
typedef struct func_802B6BE4_S2 func_802B6BE4_S2;

struct TableSlot;
/* unbake published declaration: published_2f8b83d1f42d5ddb06c1f65c */
typedef struct TableSlot TableSlot;

struct ObjectLinks88;
/* unbake published declaration: published_34b470c9b4c0b63a67c050d1 */
typedef struct ObjectLinks88 ObjectLinks88;

struct ALSeqPlayer_func_802B0C94_de;
/* unbake published declaration: published_38354d87df7f8d5f03227369 */
typedef struct ALSeqPlayer_func_802B0C94_de ALSeqPlayer_func_802B0C94_de;

struct func_802B6BE4_S4;
/* unbake published declaration: published_38f78c0c8ee42e507f5b7f9a */
struct func_802B6BE4_S4 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
    char padC[0x10 - 0xC - sizeof(s16)];
    void * unk10;
};

struct func_802B67B0_S1;
/* unbake published declaration: published_3bbe239f7ffe19b8afb19512 */
typedef struct func_802B67B0_S1 func_802B67B0_S1;

struct ALSeqPlayer_func_802B1814_de;
/* unbake published declaration: published_3bd60b39ce622c1af75cf22a */
typedef struct ALSeqPlayer_func_802B1814_de ALSeqPlayer_func_802B1814_de;

struct ObjectStateD;
/* unbake published declaration: published_3ccd14fa3f7aa70453a7f8e1 */
typedef struct ObjectStateD ObjectStateD;

struct ALBank_s;
/* unbake published declaration: published_3dd33a7fee761adb45a44a87 */
struct ALBank_s {
    s16 instCount;
    u8 flags;
    u8 pad;
    s32 sampleRate;
    ALInstrument *percussion;
    ALInstrument *instArray[1];
};

struct ALVoiceState_s38;
/* unbake published declaration: published_3f91288abb15ba02fff88cf1 */
typedef struct ALVoiceState_s38 ALVoiceState_s38;

struct ALChanState;
struct ALChanState {
    void *instrument;
    s16 bendRange;
    u8 fxId;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
};
struct ALChanState;
struct ALSeqPlayer_func_802B1814_de;
/* unbake published declaration: published_402487a067f8f08b8325f807 */
struct ALSeqPlayer_func_802B1814_de {
    char pad0[0x32];
    s16 vol;
    char pad1[0x60 - 0x34];
    struct ALChanState *chanState;
};

struct List802B663C;
/* unbake published declaration: published_4068af228583a2277a760142 */
typedef struct List802B663C List802B663C;

/* unbake published declaration: published_4129e3cee44fd162e492608b */
extern void func_802B0390_de(void *arg0, s32 arg1, s32 arg2);

/* unbake published declaration: published_47ad91f92c21ab3953564c95 */
typedef signed int ( *Lane_ALOscUpdate)(void *, float *);

struct func_802B65EC_S2;
/* unbake published declaration: published_49f79460598d4204478cd276 */
struct func_802B65EC_S2 {
    char pad0[0x14];
    void * unk14;
    char pad14[0x31 - 0x14 - sizeof(void*)];
    s8 unk31;
    char pad31[0x32 - 0x31 - sizeof(s8)];
    s8 unk32;
    char pad32[0x33 - 0x32 - sizeof(s8)];
    s8 unk33;
};

struct List802B663C;
/* unbake published declaration: published_d1a484d6d334a4f00c2c8d93 */
struct List802B663C {
    char pad[0x64];
    Node_func_80239AF4_de *head;
    Node_func_80239AF4_de *tail;
    Node_func_80239AF4_de *free;
};

/* unbake published declaration: published_4cc511a8c32aa5409d6aefae */
extern void func_802B156C_de(List802B663C *arg0, void *arg1);

struct EntryTable;
/* unbake published declaration: published_4d462a330ad4e1dc8c0b2003 */
typedef struct EntryTable EntryTable;

/* unbake published declaration: published_4d6780adfba2a5c0239dbe92 */
extern float D_800C74D0_de;

struct ALVoice_s;
struct ALVolumeEvent;
/* unbake published declaration: published_4f31575287426b27a4ecc4ba */
struct ALVolumeEvent {
    struct ALVoice_s *voice;
    s32 delta;
    u8 vol;
};

struct func_802B6B90_S1;
/* unbake published declaration: published_56476cd8e186dd6dddab1f9a */
struct func_802B6B90_S1 {
    char pad0[0x60];
    s32 unk60;
};

struct func_802B65EC_S1;
/* unbake published declaration: published_567dee3cb0e095cb2d6a046e */
struct func_802B65EC_S1 {
    char pad0[0x64];
    void * unk64;
    char pad64[0x68 - 0x64 - sizeof(void*)];
    void * unk68;
    char pad68[0x6C - 0x68 - sizeof(void*)];
    void * unk6C;
};

struct func_802B6A60_S1;
/* unbake published declaration: published_5acbf5c4fe67ef5ca38bc728 */
struct func_802B6A60_S1 {
    char pad0[0x34];
    u8 unk34;
    char pad34[0x60 - 0x34 - sizeof(u8)];
    func_802626BC_S1_U10 unk60;
};

struct ALVoiceState_s38;
/* unbake published declaration: published_ebd39888da2d477fb1e1229c */
struct ALVoiceState_s38 {
    struct ALVoiceState_s38 *next;
    ALVoice_s voice;
    ALSound_s *sound;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
};

struct ALOscEvent;
struct ALVoiceState_s38;
/* unbake published declaration: published_630a710ca92ba253df3a1640 */
struct ALOscEvent {
    struct ALVoiceState_s38 *vs;
    void *oscState;
    u8 chan;
};

struct func_802B6A60_S1;
/* unbake published declaration: published_685434652f2bcc083cdd2775 */
typedef struct func_802B6A60_S1 func_802B6A60_S1;

struct func_802B69B4_S2;
/* unbake published declaration: published_7089319bd8a0d6a686133f87 */
struct func_802B69B4_S2 {
    char pad0[0x34];
    u8 unk34;
};

struct Entry802B6BE4;
/* unbake published declaration: published_70cc99a3470cdfdd0248b39d */
struct Entry802B6BE4 {
    s16 type;
    s16 pad;
    void *object;
    s32 unused;
};

struct func_802B66A0_S1;
/* unbake published declaration: published_73df91d7947fd74b33e55b9b */
struct func_802B66A0_S1 {
    char pad0[0x48];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
};

struct ALVoiceState_s_func_802B1814_de;
/* unbake published declaration: published_76219ebcf7c7e931ffe90a48 */
typedef struct ALVoiceState_s_func_802B1814_de ALVoiceState_s_func_802B1814_de;

struct func_802B65EC_S2;
/* unbake published declaration: published_79b00dff00128b3cd0d49bac */
typedef struct func_802B65EC_S2 func_802B65EC_S2;

struct func_802B6D04_S1;
/* unbake published declaration: published_7a659539ba0ca0deb0748804 */
struct func_802B6D04_S1 {
    char pad0[0x48];
    void * unk48;
    char pad48[0x50 - 0x48 - sizeof(void*)];
    char * unk50;
    char pad50[0x78 - 0x50 - sizeof(char*)];
    void * unk78;
};

struct ALVoiceState_s;
/* unbake published declaration: published_7c300340d8ef9db0f81f6aef */
typedef struct ALVoiceState_s ALVoiceState_s;

/* unbake published declaration: published_7ee21e4171586ca9c3bfb584 */
typedef signed int ( *Lane_ALOscInit)(void * *, float *, unsigned char, unsigned char, unsigned char, unsigned char);

struct func_802B6B90_S3;
/* unbake published declaration: published_84183b676cfaf335a4f77828 */
typedef struct func_802B6B90_S3 func_802B6B90_S3;

struct func_802B6D04_S2;
/* unbake published declaration: published_8537b2401882dc9ad53a551c */
typedef struct func_802B6D04_S2 func_802B6D04_S2;

struct Entry802B6BE4;
/* unbake published declaration: published_8af316304f3500ddc9b656dc */
typedef struct Entry802B6BE4 Entry802B6BE4;

struct func_802B6B90_S2;
/* unbake published declaration: published_8caa734cd1255d970ba34c18 */
struct func_802B6B90_S2 {
    void *unk0;
    u16 unk4;
    char pad4[0x7 - 0x4 - sizeof(u16)];
    u8 unk7;
    char pad7[0x8 - 0x7 - sizeof(u8)];
    u8 unk8;
    char pad8[0x9 - 0x8 - sizeof(u8)];
    u8 unk9;
};

/* unbake published declaration: published_90f3ef4345b27702a43e4463 */
typedef void ( *Lane_ALOscStop)(void *);

struct func_802B69B4_S1;
/* unbake published declaration: published_920258baa34e7379b3bc785b */
struct func_802B69B4_S1 {
    char pad0[0x4];
    char unk4;
    char pad4[0xC - 0x4 - sizeof(char)];
    void * unkC;
};

struct TableSlot;
/* unbake published declaration: published_95f0680409e85c99c00fb02c */
struct TableSlot {
    void *entry;
    char rest[0xC];
};

struct func_802B66A0_S1;
/* unbake published declaration: published_9634451c3cf2aea5e7a78944 */
typedef struct func_802B66A0_S1 func_802B66A0_S1;

struct EntryTable;
/* unbake published declaration: published_9655492c9611af3d817bb3fd */
struct EntryTable {
    char header[0x10];
    void *entries[1];
};

struct ALSeqPlayer;
struct ALVoiceState_s;
/* unbake published declaration: published_99954e0c1a143980047559f9 */
struct ALSeqPlayer {
    char pad[0x64];
    struct ALVoiceState_s *vAllocHead;
};

struct func_802B67B0_S3;
/* unbake published declaration: published_9adf035bfd41487ca407cafd */
typedef struct func_802B67B0_S3 func_802B67B0_S3;

struct ALSound;
struct ALSound {
    void *envelope;
    void *keyMap;
    void *wavetable;
    u8 samplePan;
    u8 sampleVolume;
    u8 flags;
};
struct ALSound;
struct ALVoiceState_s_func_802B1814_de;
/* unbake published declaration: published_9de693b709ab016d3cfcda08 */
struct ALVoiceState_s_func_802B1814_de {
    struct ALVoiceState_s_func_802B1814_de *next;
    char voice[0x1C];
    struct ALSound *sound;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
};

struct func_802B67B0_S1;
/* unbake published declaration: published_a11062c6405932baaa99ab17 */
struct func_802B67B0_S1 {
    char pad0[0x60];
    void * unk60;
};

struct ObjectLinks88;
/* unbake published declaration: published_a8a3854486fb3c630ffc96d9 */
struct ObjectLinks88 {
    char pad0[0x18];
    void * unk_18;
    char pad18[0x24 - 0x18 - sizeof(void*)];
    s32 unk_24;
    char pad24[0x2C - 0x24 - sizeof(s32)];
    s32 unk_2C;
    char pad2C[0x48 - 0x2C - sizeof(s32)];
    char unk_48;
    char pad48[0x7C - 0x48 - sizeof(char)];
    void * unk_7C;
    char pad7C[0x80 - 0x7C - sizeof(void*)];
    char * unk_80;
    char pad80[0x84 - 0x80 - sizeof(char*)];
    s32 unk_84;
};

struct ObjectLinks34;
/* unbake published declaration: published_a8c827e58be6e0700898d841 */
typedef struct ObjectLinks34 ObjectLinks34;

/* unbake published declaration: published_b0a9cfc1590dca3edc1cd48b */
typedef int ALMicroTime;

struct ALChanState10;
/* unbake published declaration: published_bf0ec75c81671c8f827481ba */
typedef struct ALChanState10 ALChanState10;

struct ALNoteEvent;
/* unbake published declaration: published_b557dfa2ea5f3b1b7c670f8d */
typedef struct ALNoteEvent ALNoteEvent;

struct ALOscEvent;
/* unbake published declaration: published_b7d45e7f369bab62da1352e8 */
typedef struct ALOscEvent ALOscEvent;

struct ALVolumeEvent;
/* unbake published declaration: published_cc5bc045157546f2a9fb9bcb */
typedef struct ALVolumeEvent ALVolumeEvent;

struct ALNoteEvent;
struct ALVoice_s;
/* unbake published declaration: published_f4f89f579d65149712414f3e */
struct ALNoteEvent {
    struct ALVoice_s *voice;
};

struct ALEvent10;
/* unbake published declaration: published_cac4afb706b88d30b232b4bd */
struct ALEvent10 {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALNoteEvent note;
        ALVolumeEvent vol;
        Request spvol;
        InventorySlot sppriority;
        func_80284AF4_G2 spseq;
        func_80284AF4_G2 spbank;
        ALOscEvent osc;
    } msg;
};

struct ALEvent10;
/* unbake published declaration: published_f5f1cea777de085c59d5b61f */
typedef struct ALEvent10 ALEvent10;

struct ALSeqPlayer_func_802B0C94_de;
/* unbake published declaration: published_acc627ac53da16eb4790699c */
struct ALSeqPlayer_func_802B0C94_de {
    ALPlayer_s node;
    void *drvr;
    void *target;
    ALMicroTime curTime;
    ALBank_s *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent10 nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState10 *chanState;
    ALVoiceState_s38 *vAllocHead;
    ALVoiceState_s38 *vAllocTail;
    ALVoiceState_s38 *vFreeList;
    Lane_ALOscInit initOsc;
    Lane_ALOscUpdate updateOsc;
    Lane_ALOscStop stopOsc;
};

struct func_802B65EC_S1;
/* unbake published declaration: published_ae9e8f268557113f310d67ef */
typedef struct func_802B65EC_S1 func_802B65EC_S1;

struct func_802B66A0_S2;
/* unbake published declaration: published_b29441753d8ca77b7ca481e7 */
struct func_802B66A0_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
    char padC[0x10 - 0xC - sizeof(s16)];
    s32 unk10;
};

struct func_802B6D04_S2;
/* unbake published declaration: published_bc278b3b0dee7e068ab20200 */
struct func_802B6D04_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    u16 unkC;
    char padC[0x10 - 0xC - sizeof(u16)];
    void * unk10;
    char pad10[0x14 - 0x10 - sizeof(void*)];
    void * unk14;
};

struct func_802B6BE4_S3;
/* unbake published declaration: published_be3d63b8bfb3e4a32068703b */
typedef struct func_802B6BE4_S3 func_802B6BE4_S3;

struct func_802B6BE4_S1;
/* unbake published declaration: published_bf21bf5bdfa4d0cce295bfbd */
typedef struct func_802B6BE4_S1 func_802B6BE4_S1;

struct ObjectLinks34;
/* unbake published declaration: published_c22dbd8c04ca66b47061f528 */
struct ObjectLinks34 {
    char pad0[0x20];
    void * unk_20;
    char pad20[0x31 - 0x20 - sizeof(void*)];
    u8 unk_31;
};

/* unbake published declaration: published_c33e96c453876dad8a951c9f */
extern void func_802B1D24_de(void *arg0);

struct func_802B6B90_S2;
/* unbake published declaration: published_cb7695e8c5547a24433430a4 */
typedef struct func_802B6B90_S2 func_802B6B90_S2;

struct func_802B69B4_S2;
/* unbake published declaration: published_ccab4ee96dc1b1c1e8118571 */
typedef struct func_802B69B4_S2 func_802B69B4_S2;

/* unbake published declaration: published_d4d5108953f7e655e2381b62 */


struct func_802B6D04_S4;
/* unbake published declaration: published_dc87814b81d2a3e3f98da4ce */
struct func_802B6D04_S4 {
    char pad0[0x37];
    u8 unk37;
};

struct ObjectStateD;
/* unbake published declaration: published_e44df8b0439a4e095a9dbb02 */
struct ObjectStateD {
    unsigned char padding_0[12];
    u8 unk_C;
};

struct func_802B6D04_S4;
/* unbake published declaration: published_e8a1aacf8bb4cf2fcf4319d6 */
typedef struct func_802B6D04_S4 func_802B6D04_S4;

struct func_802B69B4_S1;
/* unbake published declaration: published_f5e457ee67cdfec3132abc68 */
typedef struct func_802B69B4_S1 func_802B69B4_S1;

/* unbake published declaration: published_f6b515ead2829b1044ae2511 */
extern float D_800C74CC_de;

struct func_802B6BE4_S1;
/* unbake published declaration: published_fd440f7751209dbe90e65b6a */
struct func_802B6BE4_S1 {
    char pad0[0x10];
    char * unk10;
};

extern int func_802B0630_eu(void * arg0, int arg1, int arg2);
#endif
