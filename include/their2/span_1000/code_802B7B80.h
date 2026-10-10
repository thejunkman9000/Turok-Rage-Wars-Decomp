#ifndef UNBAKE_SPAN_1000_CODE_802B7B80_H
#define UNBAKE_SPAN_1000_CODE_802B7B80_H
#include "../types.h"
struct Block40;
/* unbake published declaration: published_033686857e297286f81d954e */
struct Block40 {
    u8 bytes[0x28];
};

struct OSMesgQueue;
struct OSPfs;
/* unbake published declaration: published_1229eeabb8828cf3eebc6424 */
struct OSPfs {
    int status;
    struct OSMesgQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct __OSContRamReadFormat;
/* unbake published declaration: published_4cba076162532bfa7df885a5 */
struct __OSContRamReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
};

struct Block40;
/* unbake published declaration: published_736adec7d29f3a194e461b4c */
typedef struct Block40 Block40;

/* unbake published declaration: published_80b3484974c4a5157eb92c29 */
extern unsigned int func_802B80B4_eu(void *arg0);

/* unbake published declaration: published_b91a736f7d55c3858520961b */


struct __OSContRamReadFormat;
/* unbake published declaration: published_ca5d307e2535af31862e2878 */
typedef struct __OSContRamReadFormat __OSContRamReadFormat;

struct OSPfs;
/* unbake published declaration: published_d956fa81bfabadfa7028fd20 */
typedef struct OSPfs OSPfs;


struct Triple;
extern u32 func_802B7B80_us(struct Triple *);
extern u32 func_802B7C50_de(struct Triple *);
extern u32 func_802B7F30_eu_x(struct Triple *);
#endif
