#include "common.h"

void __osViSwapContext(void) {
    register OSViMode *modep;
    register OSViContext *vc;
    u32 origin;
    u32 hStart;
    u32 yScaleLow;
    u32 field;
    register u32 buffer;

    field = 0;
    vc = __osViNext;
    modep = vc->modep;
    field = HW_REG(VI_V_CURRENT_LINE_REG, u32) & 1;
    buffer = osVirtualToPhysical(vc->buffer);
    origin = buffer + modep->fldRegs[field].origin;

    if (vc->state & 2) {
        vc->x.scale |= modep->comRegs.xScale & ~0xFFF;
    } else {
        vc->x.scale = modep->comRegs.xScale;
    }

    if (vc->state & 4) {
        yScaleLow = (u32)(modep->fldRegs[field].yScale & 0xFFF);
        vc->y.scale = vc->y.factor * yScaleLow;
        vc->y.scale |= modep->fldRegs[field].yScale & ~0xFFF;
    } else {
        vc->y.scale = modep->fldRegs[field].yScale;
    }

    hStart = modep->comRegs.hStart;
    if (vc->state & 0x20) {
        hStart = 0;
    }

    if (vc->state & 0x40) {
        vc->y.scale = 0;
        origin = osVirtualToPhysical(vc->buffer);
    }

    if (vc->state & 0x80) {
        vc->y.scale = (vc->y.offset << 0x10) & 0x3FF0000;
        origin = osVirtualToPhysical(vc->buffer);
    }

    HW_REG(VI_ORIGIN_REG, u32) = origin;
    HW_REG(VI_WIDTH_REG, u32) = modep->comRegs.width;
    HW_REG(VI_BURST_REG, u32) = modep->comRegs.burst;
    HW_REG(VI_V_SYNC_REG, u32) = modep->comRegs.vSync;
    HW_REG(VI_H_SYNC_REG, u32) = modep->comRegs.hSync;
    HW_REG(VI_LEAP_REG, u32) = modep->comRegs.leap;
    HW_REG(VI_H_START_REG, u32) = hStart;
    HW_REG(VI_V_START_REG, u32) = modep->fldRegs[field].vStart;
    HW_REG(VI_V_BURST_REG, u32) = modep->fldRegs[field].vBurst;
    HW_REG(VI_INTR_REG, u32) = modep->fldRegs[field].vIntr;
    HW_REG(VI_X_SCALE_REG, u32) = vc->x.scale;
    HW_REG(VI_Y_SCALE_REG, u32) = vc->y.scale;
    HW_REG(VI_CONTROL_REG, u32) = vc->features;

    __osViNext = __osViCurr;
    __osViCurr = vc;
    *__osViNext = *__osViCurr;
}
