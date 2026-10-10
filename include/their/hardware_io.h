#ifndef RAGEWARS_HARDWARE_IO_H
#define RAGEWARS_HARDWARE_IO_H

#include "types.h"

/* PI status: uncached hardware register; bits 0 and 1 report bus activity. */
#define PI_STATUS_REG 0xA4600010U
#define PI_STATUS_BUSY_MASK 3U
#define IO_READ_WORD(address) (*(volatile u32 *)(address))

#endif
