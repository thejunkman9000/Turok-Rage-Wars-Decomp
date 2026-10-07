/* Minimal libultra types for the port's OS shim (layouts match include/common.h; kept separate so that the shim can
   include the Windows headers without clashing with the game's common.h). */
#ifndef OS_TYPES_H
#define OS_TYPES_H
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef signed char s8; typedef short s16; typedef int s32; typedef float f32;
typedef s32 OSPri; typedef s32 OSId; typedef u32 OSEvent; typedef void *OSMesg;
#define OS_MESG_NOBLOCK 0
#define OS_MESG_BLOCK 1
#define OS_EVENT_VI 7
#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
typedef struct OSThread_s {
    /* 0x00 */ struct OSThread_s *next;
    /* 0x04 */ OSPri priority;
    /* 0x08 */ struct OSThread_s **queue;
    /* 0x0C */ struct OSThread_s *tlnext;
    /* 0x10 */ u16 state;
    /* 0x12 */ u16 flags;
    /* 0x14 */ OSId id;
} OSThread;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue; OSThread *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg;
} OSMesgQueue;
typedef struct OSTimer_s {
    struct OSTimer_s *next; struct OSTimer_s *prev; u64 interval; u64 remaining; OSMesgQueue *mq; OSMesg msg;
} OSTimer;
struct OSPiHandle_s;
typedef struct { u16 type; u8 pri; u8 status; OSMesgQueue *retQueue; } OSIoMesgHdr;
typedef struct { OSIoMesgHdr hdr; void *dramAddr; u32 devAddr; u32 size; struct OSPiHandle_s *piHandle; } OSIoMesg;
typedef struct {
    u32 type; u32 flags; u64 *ucode_boot; u32 ucode_boot_size; u64 *ucode; u32 ucode_size; u64 *ucode_data;
    u32 ucode_data_size; u64 *dram_stack; u32 dram_stack_size; u64 *output_buff; u64 *output_buff_size;
    u64 *data_ptr; u32 data_size; u64 *yield_data_ptr; u32 yield_data_size;
} OSTask_t;
typedef union { OSTask_t t; long long int force_structure_alignment; } OSTask;
typedef struct { u16 type; u8 status; u8 errno_; } OSContStatus;
typedef struct { u16 button; s8 stick_x; s8 stick_y; u8 errno_; } OSContPad;
typedef struct OSViMode_s OSViMode;
#endif
