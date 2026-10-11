#include "pfs_types.h"

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int file_size_in_bytes, s32 *file_no);
s32 __osClearPage(OSPfs *pfs, int page, u8 *data, u8 bank);
s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank, int *decleared, int *last_page);
s32 __osCheckId(OSPfs *pfs);
s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no);
s32 osPfsFreeBlocks(OSPfs *pfs, s32 *leo_bytes);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

#define ERRCK(f) ret = f; if (ret != 0) return ret

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, int file_size_in_bytes, s32 *file_no) {
    int file_size_in_pages;
    int start_page;
    int decleared;
    int last_page;
    int bytes;
    s32 ret;
    s32 j;
    s32 k;
    int old_last_page = 0;
    u8 old_bank = 0;
    int cnt = 0;
    __OSInode inode;
    __OSInode backup;
    u16 first;
    __OSDir dir;
    /* A narrow signed zero local (NOT int / u8 / u16) that is passed as ext_name of the second osPfsFindFile call: its spilled pseudo
       reserves the 4 byte frame slot at sp+0x268 that the original has (the pointer spill then lands at sp+0x26C, ROM) */
    s16 zero = 0;

    if (company_code == 0 || game_code == 0) {
        return PFS_ERR_INVALID;
    }
    file_size_in_pages = (file_size_in_bytes + PFS_PAGE_SIZE - 1) / PFS_PAGE_SIZE;
    if ((pfs->status & PFS_INITIALIZED) == 0) {
        return PFS_ERR_INVALID;
    }
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) {
        return PFS_ERR_NEW_PACK;
    }
    ret = osPfsFindFile(pfs, company_code, game_code, game_name, ext_name, file_no);
    if (ret != 0 && ret != PFS_ERR_INVALID) {
        /* both arms identical: the dead test keeps one more reference to pfs alive until jump2 deletes it, which lifts pfs above the
           hoisted &backup pointer in the global-alloc priority order (pfs gets s3, &backup s4, as in the ROM) */
        if (pfs) {
            return ret;
        } else {
            return ret;
        }
    } else if (*file_no != -1) {
        return PFS_ERR_EXIST;
    }
    osPfsFreeBlocks(pfs, &bytes);
    if (bytes < file_size_in_bytes) {
        return PFS_DATA_FULL;
    }
    if (file_size_in_pages == 0) {
        goto invalid;
    }
    ret = osPfsFindFile(pfs, 0, 0, 0, (u8 *)zero, file_no);
    if (ret != 0 && ret != PFS_ERR_INVALID) {
        return ret;
    } else if (*file_no == -1) {
        return PFS_DIR_FULL;
    }
    for (k = 0; (u8)k < pfs->banks; k++) {
        ERRCK(__osPfsRWInode(pfs, &inode, PFS_READ, (u8)k));
        ERRCK(__osPfsDeclearPage(pfs, &inode, file_size_in_pages, &start_page, (u8)k, &decleared, &last_page));
        if (start_page == -1) {
            continue;
        }
        if (cnt != 0) {
            backup.inode_page[old_last_page].inode_t.bank = k;
            backup.inode_page[old_last_page].inode_t.page = (u8)start_page;
            ERRCK(__osPfsRWInode(pfs, &backup, PFS_WRITE, old_bank));
        } else {
            first = ((u8)k << 8) | (u8)start_page;
        }
        for (j = 0; j < 128; j++) {
            backup.inode_page[j] = inode.inode_page[j];
        }
        cnt++;
        old_bank = k;
        old_last_page = last_page;
        if (decleared >= file_size_in_pages) {
            file_size_in_pages = 0;
            break;
        } else {
            file_size_in_pages -= decleared;
        }
    }
    if (file_size_in_pages > 0) {
        return PFS_ERR_INCONSISTENT;
    }
    if (start_page == -1) {
        return PFS_ERR_INCONSISTENT;
    }
    backup.inode_page[old_last_page].inode_t.bank = k;
    backup.inode_page[old_last_page].inode_t.page = (u8)start_page;
    ERRCK(__osPfsRWInode(pfs, &backup, PFS_WRITE, old_bank));
    dir.start_page.ushort = first;
    dir.company_code = company_code;
    dir.data_sum = 0;
    dir.game_code = game_code;
    for (j = 0; j < 16; j++) {
        dir.game_name[j] = *game_name++;
    }
    for (j = 0; j < 4; j++) {
        dir.ext_name[j] = *ext_name++;
    }
    ERRCK(__osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->dir_table + *file_no), (u8 *)&dir, 0));
    return 0;
invalid:
    return PFS_ERR_INVALID;
}
