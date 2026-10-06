#include "pfs_types.h"

s32 __osPfsSelectBank(OSPfs *pfs);
s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum);
s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);

s32 __osGetId(OSPfs *pfs) {
    u16 sum;
    u16 isum;
    u8 temp[32];
    __OSPackId newid;
    __OSPackId *id;
    s32 k;
    s32 ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum((u16 *)temp, &sum, &isum);
    id = (__OSPackId *)temp;
    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, (__OSPackId *)temp);
        if (ret == 10) {
            ret = __osRepairPackId(pfs, id, &newid);
            if (ret != 0) {
                return ret;
            }
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }
    if ((id->deviceid & 1) == 0) {
        ret = __osRepairPackId(pfs, id, &newid);
        if (ret != 0) {
            return ret;
        }
        id = &newid;
        if ((id->deviceid & 1) == 0) {
            return 11;
        }
    }
    for (k = 0; k < 32; k++) {
        pfs->id[k] = ((u8 *)id)[k];
    }
    pfs->version = id->version; pfs->banks = id->banks; pfs->dir_size = 16; pfs->inode_table = 8; pfs->inode_start_page = pfs->banks * 2 + 3; pfs->minode_table = (pfs->banks + 1) * 8; pfs->dir_table = pfs->minode_table + pfs->banks * 8;
    ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0) {
        return ret;
    }
    return 0;
}
