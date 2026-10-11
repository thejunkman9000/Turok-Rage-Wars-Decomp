#include "pfs_types.h"

s32 __osPfsSelectBank(OSPfs *pfs);

inline u16 __osSumcalc(u8 *ptr, int length) {
    int i;
    u32 sum = 0;
    u8 *tmp = ptr;
    for (i = 0; i < length; i++) {
        sum += *tmp++;
        sum &= 0xFFFF;
    }
    return sum;
}

inline s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum) {
    u16 data;
    u32 j;
    *csum = *icsum = 0;
    for (j = 0; j < 28; j += 2) {
        data = *(u16 *)((u8 *)ptr + j);
        *csum += data;
        *icsum += ~data;
    }
    return 0;
}

s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid) {
    u8 buf[32];
    u8 temp2[32];
    u16 addr[4];
    s32 i;
    s32 j;
    s32 ret;
    s32 dev;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    newid->repaired = -1;
    newid->random = osGetCount();
    newid->serial_mid = badid->serial_mid;
    newid->serial_low = badid->serial_low;
    for (i = 0; i < 62; i++) {
        pfs->activebank = i;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(pfs->queue, pfs->channel, 0, buf);
        if (ret != 0) {
            return ret;
        }
        buf[0] = i | 0x80;
        for (j = 1; j < 32; j++) {
            buf[j] = ~buf[j];
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, 0, buf, 0);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(pfs->queue, pfs->channel, 0, temp2);
        if (ret != 0) {
            return ret;
        }
        for (j = 0; j < 32; j++) {
            if (temp2[j] != buf[j]) {
                break;
            }
        }
        if (j != 32) {
            break;
        }
        if (i > 0) {
            pfs->activebank = 0;
            ret = __osPfsSelectBank(pfs);
            if (ret != 0) {
                return ret;
            }
            ret = __osContRamRead(pfs->queue, pfs->channel, 0, buf);
            if (ret != 0) {
                return ret;
            }
            if (buf[0] != 0x80) {
                break;
            }
        }
    }
    pfs->activebank = 0;
    ret = __osPfsSelectBank(pfs);
    if (ret != 0) {
        return ret;
    }
    dev = i > 0;
    newid->deviceid = dev | (badid->deviceid & 0xFFFE);
    newid->banks = i;
    newid->version = badid->version;
    __osIdCheckSum((u16 *)newid, &newid->checksum, &newid->inverted_checksum);
    addr[0] = 1;
    addr[1] = 3;
    addr[2] = 4;
    addr[3] = 6;
    for (j = 0; j < 4; j++) {
        ret = __osContRamWrite(pfs->queue, pfs->channel, addr[j], (u8 *)newid, 1);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, buf);
    if (ret != 0) {
        return ret;
    }
    for (j = 0; j < 32; j++) {
        if (buf[j] != ((u8 *)newid)[j]) {
            return 10;
        }
    }
    return 0;
}

s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp) {
    u16 sum;
    u16 isum;
    u16 addr[4];
    s32 i;
    s32 j;
    s32 ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    addr[0] = 1; addr[1] = 3; addr[2] = 4; addr[3] = 6; i = 1;
    for (; i < 4; i++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, addr[i], (u8 *)temp);
        if (ret != 0) {
            return ret;
        }
        __osIdCheckSum((u16 *)temp, &sum, &isum);
        if (temp->checksum == sum && temp->inverted_checksum == isum) {
            break;
        }
    }
    if (i == 4) {
        return 10;
    }
    for (j = 0; j < 4; j++) {
        if (j != i) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, addr[j], (u8 *)temp, 1);
            if (ret != 0) {
                return ret;
            }
        }
    }
    return 0;
}

s32 __osGetId_b(OSPfs *pfs) {
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
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->dir_size = 16;
    pfs->inode_table = 8;
    pfs->inode_start_page = pfs->banks * 2 + 3;
    pfs->minode_table = (pfs->banks + 1) * 8;
    pfs->dir_table = pfs->minode_table + pfs->banks * 8;
    ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0) {
        return ret;
    }
    return 0;
}

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank) {
    u8 sum;
    s32 ret;
    s32 j;
    s32 offset;
    u8 *address;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    if (bank == 0) {
        offset = pfs->inode_start_page;
    } else {
        offset = 1;
    }
    if (flag == PFS_WRITE) {
        sum = __osSumcalc((u8 *)(inode->inode_page + offset), (128 - offset) * 2);
        inode->inode_page[0].inode_t.page = sum;
    }
    for (j = 0; j < 8; j++) {
        address = (u8 *)inode + j * 32;
        if (flag == PFS_WRITE) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->inode_table + bank * 8 + j), address, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->minode_table + bank * 8 + j), address, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->inode_table + bank * 8 + j), address);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == PFS_READ) {
        sum = __osSumcalc((u8 *)(inode->inode_page + offset), (128 - offset) * 2);
        if ((u8)sum != inode->inode_page[0].inode_t.page) {
            for (j = 0; j < 8; j++) {
                address = (u8 *)inode + j * 32;
                ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->minode_table + bank * 8 + j), address);
            }
            if ((u8)sum != inode->inode_page[0].inode_t.page) {
                return 3;
            }
            for (j = 0; j < 8; j++) {
                address = (u8 *)inode + j * 32;
                ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->inode_table + bank * 8 + j), address, 0);
            }
            return 0;
        } else {
            for (j = 0; j < 8; j++) {
                address = (u8 *)inode + j * 32;
                ret = __osContRamWrite(pfs->queue, pfs->channel, (u16)(pfs->minode_table + bank * 8 + j), address, 0);
            }
        }
    }
    return 0;
}
