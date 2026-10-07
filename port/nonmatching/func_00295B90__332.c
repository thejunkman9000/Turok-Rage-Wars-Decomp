#include "common.h"

extern s32 D_800D2B04;
void *memcpy(void *, const void *, u32);
s32 func_00285150();
s32 *func_00254420(s32, void *, s32);
void func_00253CB0(s32, void *, s32 *);
void *func_0028FD94(s32 *, s32);
void *func_0028FDA8(s32 *, s32, s32 *);
s32 func_0028FDD8(s32 *, s32);

void func_00295B90(s32 pg, s32 **obj) {
    s32 *root;
    s32 *tabA;
    s32 *tabB;
    s32 *buf;
    s32 *h;
    s32 *d;
    void *sr;
    s32 cnt;
    s32 modA;
    s32 modB;
    s32 fmt;
    s32 i;
    s32 j;
    s32 n;
    u32 m;
    s32 sz;
    s32 sz0;
    s32 sz1;
    s32 sz2;
    s32 total;
    s32 off0;
    s32 off1;
    s32 x;
    u16 *px;
    u32 pix;
    u32 pix2;
    u32 r, g, b, a;
    u32 out;

    if (func_00285150(obj, (u32)~pg >> 31) == 0) {
        return;
    }
    root = **(s32 ***)obj;
    if (*root == 0) {
        return;
    }
    tabA = func_0028FD94(root, 2);
    cnt = *tabA;
    if (cnt != 0) {
        modA = pg % cnt;
    } else {
        modA = 0;
    }
    tabB = func_0028FD94(root, 1);
    modB = pg % *tabB;
    if (D_800D2B04 != 0) {
        fmt = 4;
    } else {
        fmt = (u32)obj[2] >> 30;
    }
    if (fmt != 0) {
        x = *(u8 *)func_0028FD94(root, 0);
        if (x < 2) {
            if (x >= 0) {
                for (i = 0; i < cnt; i++) {
                    px = func_0028FDA8(tabA, i, &n);
                    m = (u32)n >> 1;
                    for (j = 0; j < m; j++) {
                        pix = px[j];
                        pix2 = *px;
                        r = (pix >> 8) & 0xF8;
                        g = (pix >> 3) & 0xF8;
                        b = (pix2 << 2) & 0xF8;
                        a = pix2 & 1;
                        switch (fmt) {
                        case 1:
                            out = (g << 8) | (r << 3) | (b >> 2);
                            *px++ = out | a;
                            break;
                        case 2:
                            out = (r << 8) | (r << 3) | (b >> 2);
                            *px++ = out | a;
                            break;
                        case 3:
                            out = (g << 8) | (g << 3) | (b >> 2);
                            *px++ = out | a;
                            break;
                        case 4:
                            out = (u32)(r + b + g) / 3 >> 2;
                            *px++ = out | a;
                            break;
                        default:
                            px++;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (pg >= 0) {
        sz0 = func_0028FDD8(root, 0);
        sz1 = func_0028FDD8(tabB, modB) + 0x10;
        if (cnt != 0) {
            sz2 = func_0028FDD8(tabA, modA) + 0x10;
        } else {
            sz2 = 8;
        }
        off0 = ((sz0 + 7) & ~7) + 0x18;
        total = off0 + ((sz1 + 7) & ~7);
        total = total + ((sz2 + 7) & ~7);
        buf = func_00254420(0, obj, total);
        if (buf != 0) {
            h = (s32 *)*buf;
            h[0] = 3;
            h[1] = 0x18;
            h[2] = off0;
            h[3] = total;
            d = func_0028FD94(h, 0);
            sr = func_0028FD94(root, 0);
            sz = func_0028FDD8(root, 0);
            memcpy(d, sr, sz);
            d = func_0028FD94(h, 1);
            d[0] = 1;
            d[1] = 0x10;
            d = func_0028FD94(d, 0);
            sr = func_0028FD94(tabB, modB);
            sz = func_0028FDD8(tabB, modB);
            memcpy(d, sr, sz);
            d = func_0028FD94(h, 2);
            if (cnt != 0) {
                d[0] = 1;
                d[1] = 0x10;
                d = func_0028FD94(d, 0);
                sr = func_0028FD94(tabA, modA);
                sz = func_0028FDD8(tabA, modA);
                memcpy(d, sr, sz);
            } else {
                d[0] = 0;
            }
        }
        func_00253CB0(0, obj, buf);
    }
}
