#include "pfs_types.h"

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int file_size_in_bytes, s32 *file_no);
s32 __osClearPage(OSPfs *pfs, int page, u8 *data, u8 bank);
s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank, int *decleared, int *last_page);
s32 __osCheckId(OSPfs *pfs);
s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
s32 osPfsFreeBlocks(OSPfs *pfs, s32 *leo_bytes);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank, int *decleared, int *last_page) {
    int j;
    int i;
    int first;
    int start;
    u8 buf[32];
    int ret = 0;
    int prev;

    if (bank == 0) {
        start = pfs->inode_start_page;
    } else {
        start = 1;
    }
    for (j = start; j < 128; j++) {
        if (inode->inode_page[j].ushort == 3) {
            break;
        }
    }
    if (j == 128) {
        *first_page = -1;
        return ret;
    }
    for (i = 0; i < 32; i++) {
        buf[i] = 0;
    }
    *decleared = 1;
    prev = j;
    first = j;
    j++;
    for (; *decleared < file_size_in_pages && j < 128; j++) {
        if (inode->inode_page[j].ushort == 3) {
            inode->inode_page[prev].inode_t.bank = bank;
            inode->inode_page[prev].inode_t.page = j;
            ret = __osClearPage(pfs, prev, buf, bank);
            if (ret != 0) {
                return ret;
            }
            prev = j;
            (*decleared)++;
        }
    }
    *first_page = first;
    if (j == 128 && *decleared < file_size_in_pages) {
        *last_page = prev;
        return ret;
    }
    inode->inode_page[prev].ushort = 1;
    ret = __osClearPage(pfs, prev, buf, bank);
    *last_page = 0;
    return ret;
}
