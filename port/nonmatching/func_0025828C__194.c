#include "b13_types.h"

void *func_0028FD94(void *node, s32 idx);
void func_00257BD4(SndMgr *m, void *rec, Vec3f *pos, s32 id, s32 token, s32 a, s32 flags);

s32 func_0025828C(SndMgr *m, s32 id, Vec3f pos, s32 flags) {
    u32 *rec;
    u32 count;
    u32 i;
    s32 token;
    void *n;
    if (!(id < m->unk2B54)) {
        return -1;
    }
    n = func_0028FD94(m->tree2B4C, (s16)id);
    n = func_0028FD94(n, 0);
    m->unk2B88 = n;
    m->unk2B8C = 0x100;
    m->unk2B90 = -1;
    n = func_0028FD94(m->tree2B4C, (s16)id);
    rec = func_0028FD94(n, 1);
    count = rec[1];
    token = -1;
    if (count != 0) {
        SndMgr_Lock(m);
        token = ++m->unk10C;
        SndMgr_Unlock(m);
    }
    i = 0;
    if (count != 0) {
        do {
            func_00257BD4(m, (u8 *)rec + i * rec[0] + 8, &pos, id, token, 0, flags);
            i++;
        } while (i < count);
    }
    return token;
}
