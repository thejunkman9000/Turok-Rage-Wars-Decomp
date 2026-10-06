#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 initial_page, u16 *sum, u8 bank, __OSInodeUnit *final_page, s32 flag);


s32 __osBlockSum(OSPfs *pfs, u8 page, u16 *sum, u8 bank);

s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 initial_page, u16 *sum, u8 bank, __OSInodeUnit *final_page, s32 flag) {
    __OSInodeUnit next;
    __OSInodeUnit last_page;
    s32 ret;
    s32 offset;

    next.ushort = inode->inode_page[initial_page].ushort;
    if (next.ushort != PFS_EOF) { offset = (next.inode_t.bank == 0) ? pfs->inode_start_page : 1; } else { offset = (bank == 0) ? pfs->inode_start_page : 1; }
    if (next.inode_t.page < offset && next.ushort != PFS_EOF) {
        return 3;
    }
    *final_page = next;
    if (flag == 1) {
        inode->inode_page[initial_page].ushort = 3;
    }
    ret = __osBlockSum(pfs, initial_page, sum, bank);
    if (ret != 0) {
        return ret;
    }
    if (next.ushort == PFS_EOF) {
        return 0;
    }
    if (next.ushort >= pfs->inode_start_page) {
        do {
            last_page = next;
            next = inode->inode_page[last_page.inode_t.page];
            inode->inode_page[last_page.inode_t.page].ushort = 3;
            ret = __osBlockSum(pfs, last_page.inode_t.page, sum, bank);
            if (ret != 0) {
                return ret;
            }
        } while (next.inode_t.bank == bank && next.ushort >= pfs->inode_start_page);
        if (next.ushort >= pfs->inode_start_page && next.inode_t.bank == bank) {
            inode->inode_page[next.inode_t.page].ushort = 3;
        }
    }
    *final_page = next;
    return 0;
}
