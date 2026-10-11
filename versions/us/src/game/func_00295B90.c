#include "span_1000/code_80294C64.h"
#include "types.h"
#include "common/unused.h"

extern s32 func_80285180_de(void *, s32);
extern s32 *func_8028FDB4_de(void *, s32);
extern u16 *func_8028FDC8_de(void *, s32, u32 *);
extern s32 func_8028FDF8_de(void *, s32);
extern s32 **func_80254480_de(s32, void *, s32);
extern void func_80253D10_de(s32, void *, s32 **);
extern void *func_802BD3A0_de(void *, const void *, s32);

/* Recolours the RGBA5551 frames of a resource by the global or per-resource colour mode, then rebuilds it as a three-part block holding the header, one selected entry of list 1 and one of list 2. */
void func_80294C8C_de(s32 arg0, Resource_func_80294C8C_de *arg1) {
    u32 size;
    s32 rem1;
    s32 rem2;
    s32 *obj;
    s32 *list2;
    s32 *list1;
    s32 count;
    s32 mode;
    s32 i;
    s32 j;
    s32 n;
    s32 kind;
    s32 len0;
    s32 len1;
    s32 len2;
    s32 off1;
    s32 off2;
    s32 total;
    s32 **res;
    s32 *hdr;
    s32 *entry;

    if (func_80285180_de(arg1, arg0 >= 0) == 0) {
        return;
    }
    obj = *arg1->handle;
    if (*obj == 0) {
        return;
    }
    list2 = func_8028FDB4_de(obj, 2);
    count = *list2;
    if (count != 0) {
        rem2 = arg0 % count;
    } else {
        rem2 = 0;
    }
    list1 = func_8028FDB4_de(obj, 1);
    rem1 = arg0 % *list1;
    if (D_800CD894_de != 0) {
        mode = 4;
    } else {
        mode = arg1->flags >> 30;
    }
    if (mode != 0) {
        kind = *(u8 *)func_8028FDB4_de(obj, 0);
        if (kind < 2) if (kind >= 0) {
            for (i = 0; i < count; i++) {
                u16 *data = func_8028FDC8_de(list2, i, &size);
                n = size >> 1;
                for (j = 0; j < n; j++) {
                    u32 r = (data[j] >> 8) & 0xF8;
                    u32 g = (data[j] >> 3) & 0xF8;
                    u32 b = (data[j] << 2) & 0xF8;
                    u32 a = data[j] & 1;
                    switch (mode) {
                    case 1:
                        data[j] = (g << 8) | (r << 3) | (b >> 2) | a;
                        break;
                    case 2:
                        data[j] = (r << 8) | (r << 3) | (b >> 2) | a;
                        break;
                    case 3:
                        data[j] = (g << 8) | (g << 3) | (b >> 2) | a;
                        break;
                    case 4:
                        data[j] = (r + b + g) / 12 | a;
                        break;
                    }
                }
            }
        }
    }
    if (arg0 < 0) {
        return;
    }
    len0 = func_8028FDF8_de(obj, 0);
    len1 = func_8028FDF8_de(list1, rem1) + 0x10;
    if (count != 0) {
        len2 = func_8028FDF8_de(list2, rem2) + 0x10;
    } else {
        len2 = 8;
    }
    total = ((len0 + 7) & ~7) + 0x18;
    off1 = total;
    total += (len1 + 7) & ~7;
    off2 = total;
    total += (len2 + 7) & ~7;
    res = func_80254480_de(0, arg1, total);
    if (res != 0) {
        hdr = *res;
        hdr[0] = 3;
        hdr[1] = 0x18;
        hdr[2] = off1;
        hdr[3] = off2;
        func_802BD3A0_de(func_8028FDB4_de(hdr, 0), func_8028FDB4_de(obj, 0), func_8028FDF8_de(obj, 0));
        entry = func_8028FDB4_de(hdr, 1);
        entry[0] = 1;
        entry[1] = 0x10;
        func_802BD3A0_de(func_8028FDB4_de(entry, 0), func_8028FDB4_de(list1, rem1), func_8028FDF8_de(list1, rem1));
        entry = func_8028FDB4_de(hdr, 2);
        if (count != 0) {
            entry[0] = 1;
            entry[1] = 0x10;
            func_802BD3A0_de(func_8028FDB4_de(entry, 0), func_8028FDB4_de(list2, rem2), func_8028FDF8_de(list2, rem2));
        } else {
            entry[0] = 0;
        }
    }
    func_80253D10_de(0, arg1, res);
}
