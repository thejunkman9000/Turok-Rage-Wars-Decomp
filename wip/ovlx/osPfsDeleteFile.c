#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 initial_page, u16 *sum, u8 bank, __OSInodeUnit *final_page, s32 flag);


s32 __osBlockSum(OSPfs *pfs, u8 page, u16 *sum, u8 bank);

s32 osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name) {
    s32 file_no;
    s32 ret;
    __OSInode inode;
    __OSDir dir;
    __OSInodeUnit last_page;
    u8 startpage;
    u8 bank;
    u16 sum;
    s32 j;

    sum = 0;
    if (company_code == 0 || game_code == 0) {
        return 5;
    }
    if ((pfs->status & PFS_INITIALIZED) == 0) {
        return 5;
    }
    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    ret = osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, &file_no);
    if (ret != 0) {
        return ret;
    }
    if (file_no == -1) {
        return 5;
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dir_table + file_no), (u8 *)&dir);
    if (ret != 0) {
        return ret;
    }
    startpage = dir.start_page.inode_t.page;
    bank = dir.start_page.inode_t.bank;
    while (bank < pfs->banks) {
        ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsReleasePages(pfs, &inode, startpage, &sum, bank, &last_page, 1);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsRWInode(pfs, &inode, PFS_WRITE, bank);
        if (ret != 0) {
            return ret;
        }
        if (last_page.ushort == PFS_EOF) {
            break;
        }
        bank = last_page.inode_t.bank;
        startpage = last_page.inode_t.page;
    }
    if (bank >= pfs->banks) {
        return 3;
    }
    dir.game_code = 0;
    dir.company_code = 0;
    dir.start_page.ushort = 0;
    dir.data_sum = 0;
    for (j = 0; j < 16; j++) {
        dir.game_name[j] = 0;
    }
    for (j = 0; j < 4; j++) {
        dir.ext_name[j] = 0;
    }
    dir.status = 0;
    return __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->dir_table + file_no), (u8 *)&dir, 0);
}
