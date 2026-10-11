#include "r01_types.h"

extern u8 D_800F7450;
extern u8 D_800F7452;
extern u32 D_800F72A8;
void func_00200568(u32 addr, u32 val);
u32 func_002005A0(u32 addr);
void func_002005DC(u32 n);
void func_002010D8(s32 dir);
void func_002012D8(void);
u32 func_002023C4(void);
void func_002023D0(u32 sr);

void func_002014A4(void) {
    s32 cont;
    u32 cmd;

    do {
        cont = 1;
        while ((cmd = func_002005A0(0xB1FFFFF0)) == 0) {
            func_002005DC(1000);
        }
        if (cmd == 2) {
            func_00200568(0xB1FFFFFC, 0);
            func_002005DC(1000);
        } else {
            func_00200568(0xB1FFFFFC, 0x101);
            while (func_002005A0(0xB1FFFFF0) == cmd) {
                func_002005DC(500);
            }
            if (func_002005A0(0xB1FFFFF0) == 2) {
                func_00200568(0xB1FFFFFC, 0);
            } else {
                switch (cmd) {
                case 0x10:
                    break;
                case 0x11:
                    cont = 0;
                    break;
                case 0x12:
                    D_800F72A8 &= ~1;
                    D_800F7450 = 0;
                    D_800F7452 = 0;
                    func_002023D0(func_002023C4() & ~1);
                    break;
                case 0x13:
                    D_800F7452 = 0;
                    D_800F7450 = 0;
                    break;
                case 0x14:
                    D_800F7452 = 0xFF;
                    break;
                case 0x15:
                    D_800F7452 = 0;
                    break;
                case 0x16:
                    func_00200568(0xB1FE0000, (D_800F7452 << 24) | (D_800F7450 << 16));
                    break;
                case 0x17:
                    func_002010D8(2);
                    break;
                case 0x18:
                    func_002010D8(1);
                    break;
                case 0x19:
                    func_002012D8();
                    break;
                }
                func_00200568(0xB1FFFFFC, 0);
                while (func_002005A0(0xB1FFFFF0) == 1) {
                    func_002005DC(500);
                }
            }
        }
    } while (cont != 0 || D_800F7452 == 0);
    func_00200568(0xB1FFFFF0, 0);
}
