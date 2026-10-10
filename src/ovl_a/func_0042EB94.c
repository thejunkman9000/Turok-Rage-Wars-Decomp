#include "o04_types.h"
char *func_002A152C(char *s, char *find);
s32 func_002A1238(char *s);
void func_002A12E8(char *dst, char *src);
void func_0042EB94(char *s, char *find, char *repl) {
    char buf[0xC8];
    char *p;
    s32 flen;
    s32 slen;
    s32 pre;
    s32 i;
    s32 n;
    p = func_002A152C(s, find);
    flen = func_002A1238(find);
    while (p != 0) {
        slen = func_002A1238(s);
        pre = p - s - flen;
        for (i = 0; i < pre; i++) {
            buf[i] = s[i];
        }
        buf[pre] = 0;
        func_002A12E8(buf, repl);
        n = func_002A1238(buf);
        i = pre + flen;
        if (i < slen) {
        top:
            buf[n++] = s[i];
            buf[n] = 0;
            i++;
            if (i < slen) goto top;
        }
        n = func_002A1238(buf);
        for (i = 0; i < n; i++) {
            s[i] = buf[i];
        }
        s[n] = 0;
        p = func_002A152C(s, find);
    }
}
