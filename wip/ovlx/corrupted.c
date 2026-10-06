#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osGetId_b(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 osPfsChecker(OSPfs *pfs);
s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache) {
    s32 j;
    s32 cnt;
    s32 ret;
    s32 offset;
    s32 idx;
    u8 bank;
    s32 b;
    u8 fb; u16 us;

    cnt = 0;
    us = fpage.ushort; idx = (fpage.inode_t.page >> 2) + ((fpage.inode_t.bank & 7) << 5); fb = fpage.inode_t.bank;
    for (bank = 0; bank < pfs->banks; bank++) {
        if (bank == 0) {
            offset = pfs->inode_start_page;
        } else {
            offset = 1;
        }
        b = bank;
        if (b != fpage.inode_t.bank && !((cache->map[idx] >> (b & 7)) & 1)) {
            continue;
        }
        if (bank != cache->bank) {
            ret = __osPfsRWInode(pfs, &cache->inode, PFS_READ, bank);
            if (ret != 0 && ret != 3) {
                return ret;
            }
            cache->bank = bank;
        }
        for (j = offset; cnt < 2 && j < 128; j++) {
            if (cache->inode.inode_page[j].ushort == fpage.ushort) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            return 2;
        }
    }
    return cnt;
}
