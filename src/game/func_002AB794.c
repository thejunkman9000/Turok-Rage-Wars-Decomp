#include "b24_types.h"

typedef struct Scn {
    u8 pad0[0x40];
    s32 unk40;
    u8 pad44[0x44];
    s32 unk88;
} Scn;

extern f32 D_800CB380;
extern u8 D_801462DE;
s32 func_002A33AC(void);
void func_002A3090(void);
void func_0026D8F8(void);
void func_00296FF8(void);
void func_002A94E8(void);
void func_002A9700(void);
void func_002ABB58(f32, f32);
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002AA224(s32);
void func_002A8650(Scn *, s32);

void func_002AB794(Scn *s) {
    u8 buf[0x100];
    if (func_002A33AC() == 1) {
        func_002A3090();
        func_0026D8F8();
        func_00296FF8();
    }
    func_002A94E8();
    func_002A9700();
    func_002ABB58(D_800CB380, D_800CB380);
    func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    func_002AA224(D_801462DE);
    if (s->unk40 != 0) {
        func_002A8650(s, 1);
    }
    if (s->unk88 != 0) {
        func_002A8650(s, 2);
    }
}
