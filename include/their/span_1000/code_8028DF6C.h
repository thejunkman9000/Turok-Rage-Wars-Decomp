#ifndef UNBAKE_SPAN_1000_CODE_8028DF6C_H
#define UNBAKE_SPAN_1000_CODE_8028DF6C_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct View_func_8028FA60_de;
/* unbake published declaration: published_026e731961a094583ee7a0c5 */
typedef struct View_func_8028FA60_de View_func_8028FA60_de;

struct Def;
struct Def {
    s32 type;
    char pad4[0x24];
    s16 id;
};
struct Actor_func_8028E284_de;
struct Def;
/* unbake published declaration: published_045d19883b8cec92eb1342c8 */
struct Actor_func_8028E284_de {
    char pad0[0x18];
    struct Def *def;
    char pad1C[0xC8];
    u16 id;
    char padE6[0x202];
};

struct Scene_func_8028E284_de;
/* unbake published declaration: published_077c5f866dfe2bda27afd723 */
typedef struct Scene_func_8028E284_de Scene_func_8028E284_de;

/* unbake published declaration: published_0b992ecbc6bf0dbf1a8192f9 */
extern s32 func_8028E6FC_de(void *arg0);

struct Node_func_8028E930_de;
/* unbake published declaration: published_0e3bab1809010d86df9161b3 */
struct Node_func_8028E930_de {
    struct Node_func_8028E930_de *next;
    void *queue;
};

/* unbake published declaration: published_0f07e65ed07b1f9fa6ced88f */
extern float D_800C5350_de;

struct Obj_func_8028E860_de;
/* unbake published declaration: published_10200b99609fd8bbb5a29aa7 */
struct Obj_func_8028E860_de {
    u8 unk0;
    char pad1[0x17];
    s32 *unk18;
    char pad2[0xE4 - 0x1C];
    u16 unkE4;
};

/* unbake published declaration: published_165a6f07b0cef8982101c941 */
extern void *func_8028E770_de(void *object, int index);

struct func_8028F934_S2;
/* unbake published declaration: published_189c527104123b4acc615f3a */
typedef struct func_8028F934_S2 func_8028F934_S2;

struct func_8028E6D8_S1;
/* unbake published declaration: published_19dd51771b632869a4eec278 */
typedef struct func_8028E6D8_S1 func_8028E6D8_S1;

struct func_8028E768_S1;
/* unbake published declaration: published_2a5d304a002d7b5dd6624eab */
struct func_8028E768_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    s32 * unk18;
    char pad18[0xE4 - 0x18 - sizeof(s32*)];
    u16 unkE4;
    char padE4[0x174 - 0xE4 - sizeof(u16)];
    s32 unk174;
    char pad174[0x1A4 - 0x174 - sizeof(s32)];
    s8 unk1A4;
};

struct func_8028E044_S2;
/* unbake published declaration: published_31105747e55a4cbde75c6333 */
struct func_8028E044_S2 {
    char pad0[0x1B664];
    char * unk1B664;
};

struct Panel;
/* unbake published declaration: published_39349f173e9c2ed459fcb3b8 */
struct Panel {
    s16 active;
    char pad2[0x20 - 2];
    s16 mode;
    char pad22[0x40 - 0x22];
    char row0[0x18];
    char row0Slots[0x20];
    char row1[0x18];
    char row1Slots[0x20];
    char elements[0x2E0 - 0xB0];
    s32 field2E0;
    s32 field2E4;
    s32 field2E8;
    s32 field2EC;
    s32 field2F0;
    s32 field2F4;
    s32 field2F8;
    s32 field2FC;
    s32 field300;
};

/* unbake published declaration: published_3d3e9987ce6daae535ba5d7d */
extern s32 func_8028E044_de(void *arg0, void *arg1);

/* unbake published declaration: published_3d82cb8c1c41df06a0d65d13 */
extern int D_800CD710;

struct func_8028F934_S1;
/* unbake published declaration: published_3fc6793ffe7859666c5799ba */
struct func_8028F934_S1 {
    void * unk0;
    char pad0[0x4 - 0x0 - sizeof(void*)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    s32 unk10;
};

struct ObjectLinks2F8;
/* unbake published declaration: published_4121b61ad6e4cef4967081f2 */
struct ObjectLinks2F8 {
    unsigned char padding_0[756];
    void *unk_2F4;
};

struct Actor_func_8028E284_de;
struct Scene_func_8028E284_de;
/* unbake published declaration: published_4153955936ae61402a7e0c90 */
struct Scene_func_8028E284_de {
    char pad[0x138];
    struct Actor_func_8028E284_de *actors;
    s32 pad13C;
    s32 count;
};

/* unbake published declaration: published_41f495748741d7144e5f14a3 */
extern float D_800C533C_de;

struct Actor_func_8028E284_de;
/* unbake published declaration: published_477ea12fa11d76b04d52866e */
typedef struct Actor_func_8028E284_de Actor_func_8028E284_de;

struct func_8028E74C_S1;
/* unbake published declaration: published_48a8d7723b2d9c3695d9dc7e */
struct func_8028E74C_S1 {
    char pad0[0xAC];
    char * unkAC;
};

struct ObjectLinks2E4;
/* unbake published declaration: published_4c882e12da2ec8ecf0315af3 */
struct ObjectLinks2E4 {
    unsigned char padding_0[736];
    void *unk_2E0;
};

struct Scene_func_8028FA60_de;
/* unbake published declaration: published_4efadede35de395a3c3e265a */
struct Scene_func_8028FA60_de {
    s32 pad0;
    s32 flags;
    s32 options;
    s32 padC;
    s32 mode;
    char pad14[0x38 - 0x14];
    s32 music;
    s64 *time;
};

struct func_8028FBF0_S1;
/* unbake published declaration: published_50f06882c0f33a59842de7dd */
typedef struct func_8028FBF0_S1 func_8028FBF0_S1;

struct func_8028E6D8_S2;
/* unbake published declaration: published_519fb057288148542b478c13 */
struct func_8028E6D8_S2 {
    char pad0[0xC];
    char unkC;
    char padC[0x1508 - 0xC - sizeof(char)];
    char unk1508;
};

struct OSScClientWork;
/* unbake published declaration: published_528a782db375874dea165493 */
struct OSScClientWork {
    struct OSScClientWork *next;
    Queue_func_802517B4_de *queue;
};

struct ObjectLinks2E4;
/* unbake published declaration: published_52cc9386a245904f442065ea */
typedef struct ObjectLinks2E4 ObjectLinks2E4;

struct Scene_func_8028FA60_de;
struct View_func_8028FA60_de;
/* unbake published declaration: published_55ed0de75e5b4f8701477797 */
struct View_func_8028FA60_de {
    char pad0[0x2F4];
    struct Scene_func_8028FA60_de *current;
    struct Scene_func_8028FA60_de *next;
};

/* unbake published declaration: published_56d7c22382e7b35e89a77a56 */
extern void func_8028E284_de(Scene_func_8028E284_de *scene);

struct IntegerState14;
/* unbake published declaration: published_5df1bc00a27b37975b9481b1 */
typedef struct IntegerState14 IntegerState14;

struct FrameSchedule;
/* unbake published declaration: published_5e0f58d2ed5ff9c5444fb091 */
struct FrameSchedule {
    char pad0[0x110];
    s32 task;
    char pad114[0x10];
    u32 duration;
};

struct OSScTask_s;
/* unbake published declaration: published_60550ce805c82a80d1796eec */
struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;
    struct { s32 type; } list;
};

/* unbake published declaration: published_628ffa351ec54ef8e4246066 */
extern void func_8028F8BC_de(void *arg0, void *arg1);

struct func_8028FBF0_S1;
/* unbake published declaration: published_6457b42933e3481738d5dae7 */
struct func_8028FBF0_S1 {
    char pad0[0x78];
    char unk78;
    char pad78[0x2F4 - 0x78 - sizeof(char)];
    s32 unk2F4;
    char pad2F4[0x2F8 - 0x2F4 - sizeof(s32)];
    s32 unk2F8;
    char pad2F8[0x300 - 0x2F8 - sizeof(s32)];
    s32 unk300;
};

struct FrameSchedule;
/* unbake published declaration: published_f98f1bd0aed5cf878632bcaf */
typedef struct FrameSchedule FrameSchedule;

struct Scene_func_8028FA60_de;
/* unbake published declaration: published_6cb8b066c2f34ff599dc0bdc */
typedef struct Scene_func_8028FA60_de Scene_func_8028FA60_de;

struct func_8028EAAC_S1;
/* unbake published declaration: published_73ad20db98222555210edfad */
typedef struct func_8028EAAC_S1 func_8028EAAC_S1;

struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_79c5bfbd6ff11ebc1a2c1614 */
extern void func_8028DFE4_de(struct Shape_func_802764D4_de_2 *arg0, struct Shape_func_802764D4_de_2 *arg1);

struct func_8028E74C_S1;
/* unbake published declaration: published_7c749357c33cd41200edb83f */
typedef struct func_8028E74C_S1 func_8028E74C_S1;

/* unbake published declaration: published_803429cf88f61674da7ca594 */
extern int D_800CD708;

struct OSScTask_s;
/* unbake published declaration: published_85adbcd32d29abc73ae7d429 */
typedef struct OSScTask_s OSScTask_s;

struct func_8028F89C_S1;
/* unbake published declaration: published_9aed1b71fd47014aa10cf6d8 */
typedef struct func_8028F89C_S1 func_8028F89C_S1;

struct func_8028E910_S1;
/* unbake published declaration: published_a02f213f26503f4ad6695943 */
typedef struct func_8028E910_S1 func_8028E910_S1;

struct OSScClientWork;
struct OSScTask_s;
struct OSSched;
/* unbake published declaration: published_a1460cc0e7fc97dc38fd8e6e */
struct OSSched {
    char pad0[0x2E0];
    struct OSScClientWork *clientList;
    struct OSScTask_s *audioListHead;
    struct OSScTask_s *gfxListHead;
    struct OSScTask_s *audioListTail;
    struct OSScTask_s *gfxListTail;
    struct OSScTask_s *curRSPTask;
    struct OSScTask_s *curRDPTask;
    u32 frameCount;
    s32 doAudio;
};

/* unbake published declaration: published_a14efd81742c794f41e56a05 */
extern s32 func_8028E020_de(void *arg0, void *arg1);

struct ImageSet;
/* unbake published declaration: published_ab67dc25b4a72ca4f1f5624a */
struct ImageSet {
    u16 columns;
    u16 rows;
    char pad[4];
};

struct ImageSet;
/* unbake published declaration: published_ad40a9bc0d55554f8f788b9e */
typedef struct ImageSet ImageSet;

struct func_8028E044_S1;
/* unbake published declaration: published_ae9589b76f0f1a2adb5b31f0 */
typedef struct func_8028E044_S1 func_8028E044_S1;

struct OSScClientWork;
/* unbake published declaration: published_b39c7b143df90fc3ed397482 */
typedef struct OSScClientWork OSScClientWork;

struct func_8028F934_S2;
/* unbake published declaration: published_b5ae5cf83449f91bda5b19ca */
struct func_8028F934_S2 {
    char pad0[0x2E4];
    void * unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(void*)];
    void * unk2E8;
    char pad2E8[0x2EC - 0x2E8 - sizeof(void*)];
    void * unk2EC;
    char pad2EC[0x2F0 - 0x2EC - sizeof(void*)];
    void * unk2F0;
    char pad2F0[0x300 - 0x2F0 - sizeof(void*)];
    s32 unk300;
};

struct ObjectLinks2F8;
/* unbake published declaration: published_b63396f8a3904d5de1d4e630 */
typedef struct ObjectLinks2F8 ObjectLinks2F8;

struct func_8028E044_S2;
/* unbake published declaration: published_b72d29a012d03a803b4008eb */
typedef struct func_8028E044_S2 func_8028E044_S2;

struct Node_func_8028E930_de;
struct func_8028E910_S1;
/* unbake published declaration: published_b813aa5c64c467d7865a79ff */
struct func_8028E910_S1 {
    char pad0[0x20];
    char unk20;
    char pad20[0x40 - 0x20 - sizeof(char)];
    char unk40;
    char pad40[0x2E0 - 0x40 - sizeof(char)];
    struct Node_func_8028E930_de * unk2E0;
};

struct OSSched;
/* unbake published declaration: published_b83c6f1c0d92479f021f9f24 */
typedef struct OSSched OSSched;

struct Obj_func_8028E860_de;
/* unbake published declaration: published_bd21c358c4331bbfb9fba5b8 */
typedef struct Obj_func_8028E860_de Obj_func_8028E860_de;

struct Node_func_8028FC10_de;
/* unbake published declaration: published_bf66e0cd4e4959024cc25af0 */
typedef struct Node_func_8028FC10_de Node_func_8028FC10_de;

struct func_8028EAAC_S1;
/* unbake published declaration: published_c1fac8c4e4c4efbcba85d672 */
struct func_8028EAAC_S1 {
    char pad0[0x78];
    char unk78;
};

struct func_8028E6D8_S2;
/* unbake published declaration: published_c617eceb380013f7944f6ff4 */
typedef struct func_8028E6D8_S2 func_8028E6D8_S2;

/* unbake published declaration: published_c88faf7456bfa53d479a0f86 */
extern int func_8028FD44_de(int arg0);

struct func_8028E6D8_S1;
/* unbake published declaration: published_c897b7d927eba6f14da051b9 */
struct func_8028E6D8_S1 {
    char pad0[0x1504];
    s32 unk1504;
};

/* unbake published declaration: published_cb9c5032a191f85126922fec */
extern void func_8028E068_de(void *arg0);

struct func_8028F934_S1;
/* unbake published declaration: published_cc92922b2b1a1e1feaca1bb8 */
typedef struct func_8028F934_S1 func_8028F934_S1;

/* unbake published declaration: published_cca8c98fa4d4d02adf61b05b */
extern s32 func_8028DF90_de(void *arg0, s32 arg1);

struct func_8028F89C_S1;
/* unbake published declaration: published_d056e4255733648baa929a32 */
struct func_8028F89C_S1 {
    char pad0[0x2E0];
    char * unk2E0;
};

/* unbake published declaration: published_e3e5d99d5a1ead4a3e71ba78 */
extern void *func_8028F9AC_de(void *arg0);

struct Panel;
/* unbake published declaration: published_e8cd4fecc2f5d2816e29400a */
typedef struct Panel Panel;

struct Node_func_8028FC10_de;
/* unbake published declaration: published_e8f4a6b7a57eced0d90e96a2 */
struct Node_func_8028FC10_de {
    char pad0[8];
    u32 flags;
    char padC[4];
    s32 type;
};

struct Node_func_8028E930_de;
/* unbake published declaration: published_eb05236f7f7db618e3ed362b */
typedef struct Node_func_8028E930_de Node_func_8028E930_de;

/* unbake published declaration: published_f22b80b04d37c1b2dff25cab */
extern void *func_8028F94C_de(void *object);

struct func_8028E044_S1;
/* unbake published declaration: published_f518606d30dba9b920490d80 */
struct func_8028E044_S1 {
    char pad0[0x3C];
    char unk3C;
    char pad3C[0x138 - 0x3C - sizeof(char)];
    char * unk138;
    char pad138[0x140 - 0x138 - sizeof(char*)];
    s32 unk140;
    char pad140[0x1B6A4 - 0x140 - sizeof(s32)];
    s32 unk1B6A4;
};

struct func_8028E768_S1;
/* unbake published declaration: published_fe5455ec009c64373bdede4e */
typedef struct func_8028E768_S1 func_8028E768_S1;

struct IntegerState14;
/* unbake published declaration: published_fee24e686b57d4e4d004a12e */
struct IntegerState14 {
    unsigned char padding_0[4];
    s32 unk_4;
    unsigned char padding_8[8];
    s32 unk_10;
};


struct Ctx_func_8028F544_de;
struct Node_func_8028F544_de;
struct Scene_func_8028FA60_de;
struct View_func_8028FA60_de;
extern s32 func_8028F544_de(struct Ctx_func_8028F544_de *, struct Node_func_8028F544_de **, struct Node_func_8028F544_de **, s32);
extern void func_8028FA60_de(struct View_func_8028FA60_de *, struct Scene_func_8028FA60_de *, struct Scene_func_8028FA60_de *);
#endif
