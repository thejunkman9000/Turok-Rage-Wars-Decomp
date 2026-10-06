#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

static inline s32 next_page(OSPfs *pfs, u8 *cbank, __OSInode *inode, __OSInodeUnit *curr) {
    s32 ret;
    u8 b;

    if (curr->inode_t.bank != *cbank) {
        *cbank = curr->inode_t.bank;
        ret = __osPfsRWInode(pfs, inode, PFS_READ, *cbank);
        if (ret != 0) {
            return ret;
        }
    }
    *curr = inode->inode_page[curr->inode_t.page];
    if (curr->ushort < pfs->inode_start_page || curr->inode_t.bank >= pfs->banks || curr->inode_t.page == 0 || (s8)curr->inode_t.page < 0) {
        if (curr->ushort == PFS_EOF) {
            return 5;
        }
        return 3;
    }
    return 0;
}

s32 osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, int offset, int size_in_bytes, u8 *data_buffer) {
    s32 ret;
    __OSDir dir;
    __OSInode inode;
    u8 cbank;
    __OSInodeUnit curr_page;
    s32 offset_in_blocks;
    s32 size_in_blocks;
    u8 *buf;
    s32 addr;

    if (file_no >= pfs->dir_size || file_no < 0) {
        return 5;
    }
    if (size_in_bytes <= 0 || (size_in_bytes & 0x1F) != 0) {
        return 5;
    }
    if (offset < 0 || (offset & 0x1F) != 0) {
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
    if (dir.start_page.ushort < pfs->inode_start_page || dir.start_page.inode_t.bank >= pfs->banks || dir.start_page.inode_t.page == 0 || (s8)dir.start_page.inode_t.page < 0) {
        if (dir.start_page.ushort == PFS_EOF) {
            return 5;
        }
        return 3;
    }
    if (flag == PFS_READ && (dir.status & 2) == 0) {
        return 6;
    }
    cbank = 0xFF;
    offset_in_blocks = offset / 32;
    curr_page.ushort = dir.start_page.ushort;
    while (offset_in_blocks >= 8) {
        ret = next_page(pfs, &cbank, &inode, &curr_page);
        if (ret != 0) {
            return ret;
        }
        offset_in_blocks -= 8;
    }
    size_in_blocks = size_in_bytes / 32;
    buf = data_buffer;
    while (size_in_blocks > 0) {
        if (offset_in_blocks == 8) {
            ret = next_page(pfs, &cbank, &inode, &curr_page);
            if (ret != 0) {
                return ret;
            }
            offset_in_blocks = 0;
        }
        if (pfs->activebank != curr_page.inode_t.bank) {
            pfs->activebank = curr_page.inode_t.bank;
            ret = __osPfsSelectBank(pfs);
            if (ret != 0) {
                return ret;
            }
        }
        addr = curr_page.inode_t.page * 8 + offset_in_blocks;
        if (flag == PFS_READ) {
            ret = __osContRamRead(pfs->queue, pfs->channel, (u16)addr, buf);
        } else {
            ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)addr, buf, 0);
        }
        if (ret != 0) {
            return ret;
        }
        buf += 32;
        size_in_blocks--;
        offset_in_blocks++;
    }
    if (flag == PFS_WRITE && (dir.status & 2) == 0) {
        dir.status |= 2;
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->dir_table + file_no), (u8 *)&dir, 0);
        if (ret != 0) {
            return ret;
        }
    }
    return 0;
}
