#include "common.h"
typedef struct { u8 pad[0x20]; s32 f20; } Q4O;
typedef struct { s32 cur; f32 timer; s32 len; u8 text[24]; } Q4T;
typedef struct { u8 pad[4]; f32 f4; } Q4E;
typedef struct { u8 pad[0x14]; s32 f14; u8 pad18[8]; s32 f20; } Q4B;
typedef struct { u8 pad[0x30]; f32 f30; f32 f34; } Q4D;
extern u32 D_auto_8015220C;
extern s32 D_auto_8015DDA4;
extern u8 D_auto_80152226;
extern u32 D_auto_80152208;
extern u8 D_auto_8012BA00[];
extern u8 D_auto_8012BDC8[];
extern s32 func_0026439C();
extern s32 func_002643A8();
extern s32 func_002643C0();
extern s32 func_002934DC();
extern void func_auto_0043EBEC();
extern void func_00293808();
extern void func_00293268();
extern void func_auto_0044E7F8();

s32 func_auto_0043D568(s32 a, Q4O *o) {
    s32 code;
    s32 n;
    s32 i;
    s32 r;
    u32 m;
    u8 *g;
    switch (D_auto_8015DDA4) {
    default:
    case 0: code = 1000; break;
    case 1: code = 2000; break;
    case 2: code = 3000; break;
    case 3: code = 4000; break;
    case 4: code = 5000; break;
    case 5: code = 6000; break;
    case 6: code = 0x1CE9; break;
    case 7: code = 0x1D4D; break;
    case 8: code = 0x1DB1; break;
    case 9: code = 0x1DB2; break;
    case 10: code = 0x1F40; break;
    }
    if (func_0026439C(o->f20)) {
        if (code == 0x1F40) {
            D_auto_80152226 = 1;
            func_auto_0043EBEC(o);
            func_00293808(D_auto_8012BA00, 0x11);
            return 1;
        }
        if (func_002934DC()) {
            func_auto_0044E7F8(D_auto_8012BDC8, code, 2);
            return 0;
        }
        g = (u8 *)&D_auto_80152208;
        g[0x1D] = 0;
        g[0x1E] = 1;
        func_auto_0043EBEC(o);
        func_00293268(D_auto_8012BA00, code);
        return 1;
    }
    if (func_002643A8(o->f20)) {
        i = D_auto_8015DDA4;
        for (n = 0; n < 11; n++) {
            i--;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
            switch (i) {
            default:
            case 0: m = 0x10000; break;
            case 1: m = 0x20000; break;
            case 2: m = 0x40000; break;
            case 3: m = 0x80000; break;
            case 4: m = 0x100000; break;
            case 5: m = 0x200000; break;
            case 6: m = 0x800000; break;
            case 7: m = 0x400000; break;
            case 8: m = 0x1000000; break;
            case 9: m = 0x2000000; break;
            case 10: m = 0x4000000; break;
            }
            if (D_auto_8015220C & m) {
                goto found;
            }
        }
        r = -1;
        goto done;
    found:
        r = i;
        goto done;
    }
    if (func_002643C0(o->f20)) {
        i = D_auto_8015DDA4;
        for (n = 0; n < 11; n++) {
            i++;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
            switch (i) {
            default:
            case 0: m = 0x10000; break;
            case 1: m = 0x20000; break;
            case 2: m = 0x40000; break;
            case 3: m = 0x80000; break;
            case 4: m = 0x100000; break;
            case 5: m = 0x200000; break;
            case 6: m = 0x800000; break;
            case 7: m = 0x400000; break;
            case 8: m = 0x1000000; break;
            case 9: m = 0x2000000; break;
            case 10: m = 0x4000000; break;
            }
            if (D_auto_8015220C & m) {
                goto found;
            }
        }
        r = -1;
        goto done;
    }
    return 0;
done:
    D_auto_8015DDA4 = r;
    return 0;
}
