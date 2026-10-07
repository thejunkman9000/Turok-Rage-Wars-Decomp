#include "o03_types.h"
extern O3Pk *D_800E3590;
extern O3Tbl D_800E3594[];
extern u8 D_80102B4A[];
s32 func_00265670(void *p, s32 i);
void func_00439E60();
void func_00439EB4();
s32 func_0025471C();
void func_0025470C(s32 a);
void func_0041D550(void) {
    s32 i;
    s32 snd;
    s32 idx;
    if (D_800E3590->cur == 0) {
        func_00439E60(D_800E3590->sub, 0);
        return;
    }
    i = 0;
    do {
        if (D_800E3594[i].key == D_800E3590->cur->id) {
            snd = 0;
            if (func_00265670(D_80102B4A + D_800E3590->slot * 0x190, i) == 1) {
                idx = 0;
                switch (i) {
        case 0x24:
            snd = 0xE75;
            break;
        case 0x25:
            snd = 0xE76;
            break;
        case 0x26:
            snd = 0xE77;
            break;
        case 0x27:
            snd = 0xE78;
            break;
        case 0x28:
            snd = 0xE79;
            break;
        case 0x29:
            snd = 0xE7A;
            break;
        case 0x2A:
            snd = 0xE7B;
            break;
        case 0x2B:
            snd = 0xE7C;
            break;
        case 0x2C:
            snd = 0xE7D;
            break;
        case 0x2D:
            snd = 0xE7E;
            break;
        case 0x2E:
            snd = 0xE7F;
            break;
        case 0x2F:
            snd = 0xE80;
            break;
        case 0x30:
            snd = 0xE81;
            break;
        case 0x31:
            snd = 0xE82;
            break;
        default:
            snd = 0xE74;
            idx = i;
            break;
        }
        func_00439E60(D_800E3590->sub, snd);
        func_00439EB4(D_800E3590->sub, idx);
        if (func_0025471C() == 0) {
            func_0025470C(1);
        }
            } else {
                func_00439E60(D_800E3590->sub, snd);
            }
            return;
        }
        i++;
    } while (i < 0x32);
}
