#include "b23_types.h"

void func_002A1960(u8 *dst, u8 *drive, u8 *dir, u8 *name, u8 *ext) {
    u8 *p;
    u8 c, d, c1;

    if (drive == 0) {
        goto dirpart;
    }
    c1 = *drive;
    if (c1 == 0) {
        goto dirpart;
    }
    *dst = c1;
    dst++;
    *dst = 0x3A;
    dst++;
dirpart:
    if (dir == 0) {
        goto namepart;
    }
    if (*dir == 0) {
        goto namepart;
    }
    p = dir;
copydir:
    c = *p;
    p++;
    *dst = c;
    dst++;
    if (*p != 0) {
        goto copydir;
    }
    d = p[-1];
    if (d == 0x2F) {
        goto namepart;
    }
    if (d == 0x5C) {
        goto namepart;
    }
    *dst = 0x5C;
    dst++;
namepart:
    if (name == 0) {
        goto extpart;
    }
    c = *name;
    p = name;
    if (c == 0) {
        goto extpart;
    }
copyname:
    p++;
    *dst = c;
    c = *p;
    dst++;
    if (c != 0) {
        goto copyname;
    }
extpart:
    if (ext == 0) {
        goto done;
    }
    p = ext;
    c = *p;
    if (c == 0) {
        goto done;
    }
    if (c == 0x2E) {
        goto copyext;
    }
    *dst = 0x2E;
    dst++;
copyext:
    c = *p;
    if (c == 0) {
        goto done;
    }
copyext2:
    p++;
    *dst = c;
    c = *p;
    dst++;
    if (c != 0) {
        goto copyext2;
    }
done:
    *dst = 0;
}
