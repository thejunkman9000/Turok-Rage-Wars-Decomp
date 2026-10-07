#include "b20_types.h"
void *func_0028FD94();
void port_dbg_words(const char *what, void *p, int n, int h);
void *func_0028CF48(Level *lv, s32 idx) {
    void *r;
    if (idx == -1) {
        return 0;
    }
    r = func_0028FD94(lv->unk78, idx);
    { static int n; if (n++ < 12) { s32 info[4]; info[0] = (s32)lv; info[1] = idx; info[2] = (s32)lv->unk78; info[3] = (s32)r; port_dbg_words("func_0028CF48 lv/idx/tbl/result", info, 4, 0); port_dbg_words("  tbl head", lv->unk78, 6, 0); } }
    return r;
}
