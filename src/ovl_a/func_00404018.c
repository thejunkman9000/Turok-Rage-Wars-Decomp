#include "o01_types.h"

extern O01Pad4 D_8010FBE0[];
extern OSMesgQueue D_8010FC00;
extern OSPfs D_80153510[];
extern s32 D_80153500[];
extern s32 D_801534F0[];
extern O01Rumble D_80153330[];
extern u8 D_8010FBB8;
s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel);
s32 func_00403E90(s32 pad);
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);

s32 func_00404018(s32 pad) {
    s32 i;
    s32 r;
    s32 v;
    s32 code;
    s32 ok;
    s32 ret;
    if (D_8010FBE0[pad].unk3 != 0) {
        D_80153500[pad] = -2;
        ret = 0;
    } else {
        i = 0;
        do {
            r = osPfsInitPak(&D_8010FC00, &D_80153510[pad], pad);
            switch (r) {
            case 0:
            case 2:
                D_80153500[pad] = -5;
                break;
            case 1:
                D_80153500[pad] = -2;
                break;
            case 4:
            case 11:
                code = -3;
                goto st;
            case 10:
                code = -4;
            st:
                D_80153500[pad] = code;
                break;
            }
            if (D_80153500[pad] == -5) {
                goto got5;
            }
            if (D_80153500[pad] == -2) {
                goto fin;
            }
            i++;
        } while (i < 4);
        goto fin2;
    got5:
        D_801534F0[pad] = 3;
        if (func_00403E90(pad) != 0) {
            D_80153500[pad] = -4;
            goto fin2;
        }
        D_80153500[pad] = 0;
    fin:
    fin2:
        v = D_80153500[pad];
        ok = 0;
        if (v == 0 || v == -4) {
            ok = 1;
        }
        ret = ok;
    }
    return ret;
}

void func_004041E8(void) {
    s32 i;
    s32 ok;
    O01Rumble *r;
    func_0026451C(1);
    func_00263760();
    D_8010FBB8 = 2;
    for (i = 0; i < 4; i++) {
        r = &D_80153330[i];
        if (D_8010FBE0[i].unk3 != 0) {
            r->ok = 0;
            ok = 0;
        } else {
            r->ok = osMotorInit(&D_8010FC00, &r->pfs, i) == 0;
            ok = r->ok;
        }
        if (ok != 0) {
            D_801534F0[i] = 2;
        } else if (func_00404018(i) != 0) {
            D_801534F0[i] = 3;
        } else {
            D_801534F0[i] = 1;
        }
    }
    func_0026456C();
}
