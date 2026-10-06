#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

s32 osPfsFileState(OSPfs *pfs, s32 file_no, OSPfsState *state) {
    s32 ret;
    __OSInode inode;
    __OSDir dir;
    __OSInodeUnit last_page;
    __OSInodeUnit page;
    s32 j;
    s32 blockcount;
    u8 bank;

    if (file_no >= pfs->dir_size || file_no < 0) {
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
    ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dir_table + file_no), (u8 *)&dir);
    if (ret != 0) {
        return ret;
    }
    if (dir.company_code == 0 || dir.game_code == 0) {
        return 5;
    }
    if (dir.start_page.ushort < pfs->inode_start_page) {
        return 3;
    }
    page.ushort = dir.start_page.inode_t.page;
    bank = dir.start_page.inode_t.bank;
    blockcount = 0;
    while (bank < pfs->banks) {
        ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank);
        if (ret != 0) {
            return ret;
        }
        last_page = inode.inode_page[page.inode_t.page];
        blockcount++;
        while (last_page.ushort >= pfs->inode_start_page) {
            last_page = inode.inode_page[last_page.inode_t.page];
            blockcount++;
            if (last_page.inode_t.bank != bank) {
                bank = last_page.inode_t.bank;
                page = last_page;
                break;
            }
        }
        if (last_page.ushort == 1) {
            goto done;
        }
    }
    if (last_page.ushort != 1) {
        return 3;
    }
done:
    state->file_size = blockcount << 8;
    state->company_code = dir.company_code;
    state->game_code = dir.game_code;
    for (j = 0; j < 16; j++) {
        state->game_name[j] = dir.game_name[j];
    }
    for (j = 0; j < 4; j++) {
        state->ext_name[j] = dir.ext_name[j];
    }
    return 0;
}
