#include "o01_types.h"

typedef struct O01B4 { char c[4]; } O01B4;
typedef struct O01SubF {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01SubF;
typedef struct O01OwnF {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ O01SubF *unk20;
} O01OwnF;
typedef struct O01TxtF {
    /* 0x0 */ char *buf;
} O01TxtF;
typedef struct O01ItemF {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ O01TxtF *unk14;
} O01ItemF;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153750;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_8011FECC;
extern O01B4 D_800E0DA8;
extern u8 D_800E0DA4[];
extern O01TxtF D_800D7780;
extern O01TxtF D_800D7798;
extern O01TxtF D_800D7E14;
s32 func_00405160(s32 pad, s32 *out);
u32 func_004057EC(u32 n);
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_00408118(O01ItemF *item, O01OwnF *own) {
    O01B4 buf;
    char *bp;
    s32 pad;
    s32 freeb;
    s32 need;
    char *dst;
    s32 r;
    O01TxtF *t;
    u8 *fmt;
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = own->unk20->unk4;
    }
    buf = D_800E0DA8;
    bp = buf.c;
    if (D_80153750 != 0) {
        item->unk14 = &D_800D7780;
        if (func_00405160(pad, &freeb) == 0) {
            if (D_8015377C != 0) {
                need = func_004057EC(0x18);
            } else {
                need = func_004057EC(D_8011FECC + 0x610);
            }
            dst = item->unk14->buf;
            func_00265904(buf.c, D_800E0DA4, freeb);
            dst += 0xE;
            *dst = buf.c[0];
            dst++;
            *dst = buf.c[1];
            dst++;
            *dst = buf.c[2];
            func_00265904(buf.c, D_800E0DA4, need);
            dst += 0xF;
            *dst = buf.c[0];
            dst++;
            *dst = buf.c[1];
            dst++;
            *dst = buf.c[2];
        }
    } else {
        if (D_8015375C != 0) {
            t = &D_800D7798;
        } else if (D_80153760 != 0) {
            t = &D_800D7780;
        } else {
            goto none;
        }
        item->unk14 = t;
        r = func_00405160(pad, &freeb);
        need = func_004057EC(D_8011FECC + 0x610);
        dst = item->unk14->buf;
        if (r == 0) {
            dst += 0xE;
            fmt = D_800E0DA4;
            func_00265904(bp, fmt, freeb);
            *dst = buf.c[0];
            dst++;
            *dst = buf.c[1];
            dst++;
            *dst = buf.c[2];
            func_00265904(bp, D_800E0DA4, need);
            dst += 0xF;
            *dst = buf.c[0];
            dst++;
            *dst = buf.c[1];
            dst++;
            *dst = buf.c[2];
        }
    }
    goto done;
none:
    item->unk14 = &D_800D7E14;
done:
    return 0;
}
