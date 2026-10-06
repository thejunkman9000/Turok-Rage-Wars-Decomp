#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

s32 osPfsFreeBlocks(OSPfs *pfs, s32 *leo_bytes) {
    __OSInode inode;
    s32 j;
    u8 bank;
    s32 offset;
    s32 free_pages = 0;
    s32 ret;

    if ((pfs->status & PFS_INITIALIZED) == 0) {
        return 5;
    }
    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank);
        if (ret != 0) {
            return ret;
        }
        offset = (bank == 0) ? pfs->inode_start_page : 1;
        for (j = offset; j < 128; j++) {
            if (inode.inode_page[j].ushort == 3) {
                free_pages++;
            }
        }
    }
    *leo_bytes = free_pages * 256;
    return 0;
}
