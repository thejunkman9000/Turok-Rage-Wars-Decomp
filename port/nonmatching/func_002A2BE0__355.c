#include "b23_types.h"

typedef struct IRect4 {
    s32 a, b, c, d;
} IRect4;

typedef struct Obj2BE0 {
    u8 pad0[8];
    s32 unk8;
    u8 padC[6];
    u16 unk12;
} Obj2BE0;

typedef struct Blk12 {
    s32 w[3];
} Blk12;

typedef struct Blk28 {
    s32 w[7];
} Blk28;

s32 func_0040E154(void *p, void *q, Obj2BE0 *o, Blk12 *args);
void func_0040E87C(s32 a0, Blk12 args, Blk28 blk);
void func_0040F508(IRect4 *r, void *q);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);

void func_002A2BE0(Obj2BE0 *o, Blk12 args, Blk28 blk) {
    u8 buf1[16];
    u8 buf2[16];
    IRect4 saved, cur;
    s32 flag = 0;
    if (func_0040E154(buf1, buf2, o, &args) != 0) {
        if (o->unk12 & 0x200) {
            func_002A2898(&saved.a, &saved.c, &saved.b, &saved.d);
            cur = saved;
            func_0040F508(&cur, buf2);
            flag = 1;
            func_002A2870(cur.a, cur.c, cur.b, cur.d);
        }
        func_0040E87C(o->unk8, args, blk);
        if (flag != 0) {
            func_002A2870(saved.a, saved.c, saved.b, saved.d);
        }
    }

}
