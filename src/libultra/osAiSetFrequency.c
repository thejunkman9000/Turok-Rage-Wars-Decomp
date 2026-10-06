#include "common.h"

s32 osAiSetFrequency(u32 freq) {
    register u32 dacRate;
    register u8 bitRate;
    register f32 ftmp;

    ftmp = osViClock / (f32)freq + .5f;

    dacRate = ftmp;

    if (dacRate < 0x84) {
        return -1;
    }

    bitRate = (dacRate / 66) & 0xFF;
    if (bitRate > 16) {
        bitRate = 16;
    }

    HW_REG(AI_DACRATE_REG, u32) = dacRate - 1;
    HW_REG(AI_BITRATE_REG, u32) = bitRate - 1;
    HW_REG(AI_CONTROL_REG, u32) = 1;

    return osViClock / (s32)dacRate;
}
