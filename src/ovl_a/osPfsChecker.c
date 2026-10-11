#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);
s32 __osGetId_b(OSPfs *pfs);
s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 osPfsChecker(OSPfs *pfs);
s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

s32 osPfsChecker(OSPfs *pfs) {
    s32 j;
    s32 ret;
    s32 offset;
    s32 fixed;
    u8 cbank;
    s32 first;
    s32 bad;
    u8 bank;
    __OSInodeUnit cur;
    __OSInodeUnit tmp;
    __OSInode tmpinode;
    __OSInode inode;
    __OSDir dir;
    __OSInodeUnit map[16];
    __OSInodeCache cache;

    fixed = 0;
    ret = __osCheckId(pfs);
    if (ret == 2) {
        ret = __osGetId_b(pfs);
    }
    if (ret != 0) {
        return ret;
    }
    ret = corrupted_init(pfs, &cache);
    if (ret != 0) {
        return ret;
    }
    for (j = 0; j < pfs->dir_size; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dir_table + j), (u8 *)&dir);
        if (ret != 0) {
            return ret;
        }
        if (dir.company_code != 0 && dir.game_code != 0) {
            first = bad = 0;
            cur.ushort = dir.start_page.ushort;
            cbank = 0xFF;
            while (cur.ushort >= pfs->inode_start_page && cur.inode_t.bank < pfs->banks && cur.inode_t.page != 0 && (s8)cur.inode_t.page >= 0) {
                if (cbank != cur.inode_t.bank) {
                    cbank = cur.inode_t.bank;
                    ret = __osPfsRWInode(pfs, &inode, PFS_READ, cbank);
                    if (ret != 0 && ret != 3) {
                        return ret;
                    }
                }
                bad = corrupted(pfs, cur, &cache) - first;
                if (bad != 0) {
                    break;
                }
                first = 1;
                cur = inode.inode_page[cur.inode_t.page];
            }
            if (bad == 0 && cur.ushort == 1) {
                continue;
            }
        } else if (dir.company_code == 0 && dir.game_code == 0) {
            continue;
        }
        dir.company_code = 0;
        dir.game_code = 0;
        dir.start_page.ushort = 0;
        dir.status = 0;
        dir.data_sum = 0;
        if (pfs->activebank != 0) {
            pfs->activebank = 0;
            ret = __osPfsSelectBank(pfs);
            if (ret != 0) {
                return ret;
            }
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->dir_table + j), (u8 *)&dir, 0);
        if (ret != 0) {
            return ret;
        }
        do {
            fixed++;
        } while (0);
    }
    for (j = 0; j < pfs->dir_size; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dir_table + j), (u8 *)&dir);
        if (ret != 0) {
            return ret;
        }
        if (dir.company_code != 0 && dir.game_code != 0 && dir.start_page.ushort >= (u16)pfs->inode_start_page) {
            map[j].ushort = dir.start_page.ushort;
        } else {
            map[j].ushort = 0;
        }
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        if (bank == 0) {
            offset = pfs->inode_start_page;
        } else {
            offset = 1;
        }
        for (j = 0; j < offset; j++) {
            tmpinode.inode_page[j] = inode.inode_page[j];
        }
        for (; j < 128; j++) {
            tmpinode.inode_page[j].ushort = 3;
        }
        for (j = 0; j < pfs->dir_size; j++) {
            while (map[j].inode_t.bank == bank) {
                if (map[j].ushort < (u16)pfs->inode_start_page) {
                    break;
                }
                tmp = inode.inode_page[map[j].inode_t.page];
                tmpinode.inode_page[map[j].inode_t.page] = tmp;
                map[j] = tmp;
            }
        }

        ret = __osPfsRWInode(pfs, &tmpinode, PFS_WRITE, bank);
        if (ret != 0) {
            return ret;
        }
    }
    if (fixed != 0) {
        pfs->status |= PFS_CORRUPTED;
    } else {
        pfs->status &= ~PFS_CORRUPTED;
    }
    return 0;
}
