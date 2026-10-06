#include "pfs_types.h"

s32 __osCheckId(OSPfs *pfs);

s32 osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no) {
    s32 j;
    s32 ret;
    s32 k;
    s32 mismatch;
    __OSDir dir;

    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    for (j = 0; j < pfs->dir_size; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dir_table + j), (u8 *)&dir);
        if (ret != 0) {
            return ret;
        }
        if (dir.company_code == company_code && dir.game_code == game_code) {
            mismatch = 0;
            if (game_name != NULL) {
                for (k = 0; k < 16; k++) {
                    if (dir.game_name[k] != game_name[k]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (ext_name != NULL) {
                if (mismatch) {
                    continue;
                }
                for (k = 0; k < 4; k++) {
                    if (dir.ext_name[k] != ext_name[k]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (!mismatch) {
                *file_no = j;
                return ret;
            }
        }
    }
    *file_no = -1;
    return 5;
}
