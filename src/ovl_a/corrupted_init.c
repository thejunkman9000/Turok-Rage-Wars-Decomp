#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osGetId_b(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 osPfsChecker(OSPfs *pfs);
s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache) {
    s32 i;
    s32 j;
    s32 ret;
    s32 offset;
    u8 bank;
    s32 mask;
    __OSInodeUnit tmp;
    __OSInode inode;

    for (j = 0; j < 256; j++) { cache->map[j] = 0; }
    cache->bank = 0xFF;
    for (bank = 0; bank < pfs->banks; bank++) {
        if (bank == 0) {
            offset = pfs->inode_start_page;
        } else {
            offset = 1;
        }
        ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        for (j = offset; j < 128; j++) { tmp = inode.inode_page[j]; if (tmp.ushort >= pfs->inode_start_page && tmp.inode_t.bank != bank) { cache->map[(tmp.inode_t.page >> 2) + ((tmp.inode_t.bank & 7) << 5)] |= 1 << (bank % 8); } }
    }
    return 0;
}
