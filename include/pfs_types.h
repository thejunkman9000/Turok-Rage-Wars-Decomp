#ifndef PFS_TYPES_H
#define PFS_TYPES_H

#include "common.h"

/* Controller Pak file system types (N64 SDK pfs.h layout) */

#define PFS_READ 0
#define PFS_WRITE 1
#define PFS_FORCE 1

#define PFS_ERR_INCONSISTENT 3
#define PFS_ERR_ID_FATAL 10
#define PFS_DATA_FULL 7
#define PFS_DIR_FULL 8
#define PFS_ERR_EXIST 9

#define PFS_INITIALIZED 0x1
#define PFS_CORRUPTED 0x2
#define PFS_ID_BROKEN 0x4
#define PFS_MOTOR_INITIALIZED 0x8
#define PFS_GBPAK_INITIALIZED 0x10

#define PFS_ONE_PAGE 8
#define PFS_PAGE_SIZE (BLOCKSIZE * PFS_ONE_PAGE)
#define PFS_EOF 1

#define PFS_FILE_NAME_LEN 16
#define PFS_FILE_EXT_LEN 4

#define DEF_DIR_PAGES 2

typedef struct {
    /* 0x0 */ u32 file_size;
    /* 0x4 */ u32 game_code;
    /* 0x8 */ u16 company_code;
    /* 0xA */ u8 ext_name[PFS_FILE_EXT_LEN];
    /* 0xE */ u8 game_name[PFS_FILE_NAME_LEN];
} OSPfsState;

typedef union {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ushort;
} __OSInodeUnit;

typedef struct {
    /* 0x00 */ __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct {
    /* 0x00 */ u32 game_code;
    /* 0x04 */ u16 company_code;
    /* 0x06 */ __OSInodeUnit start_page;
    /* 0x08 */ u8 status;
    /* 0x09 */ s8 reserved;
    /* 0x0A */ u16 data_sum;
    /* 0x0C */ u8 ext_name[PFS_FILE_EXT_LEN];
    /* 0x10 */ u8 game_name[PFS_FILE_NAME_LEN];
} __OSDir;

typedef struct {
    /* 0x00 */ u32 repaired;
    /* 0x04 */ u32 random;
    /* 0x08 */ u64 serial_mid;
    /* 0x10 */ u64 serial_low;
    /* 0x18 */ u16 deviceid;
    /* 0x1A */ u8 banks;
    /* 0x1B */ u8 version;
    /* 0x1C */ u16 checksum;
    /* 0x1E */ u16 inverted_checksum;
} __OSPackId;

typedef struct {
    /* 0x000 */ __OSInode inode;
    /* 0x100 */ u8 bank;
    /* 0x101 */ u8 map[256];
} __OSInodeCache;

#endif
