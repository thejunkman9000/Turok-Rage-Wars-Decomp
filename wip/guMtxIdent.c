#include "common.h"

void guMtxIdent(Mtx *m) {
    f32 mf[4][4];

    guMtxIdentF(mf);
    guMtxF2L(mf, m);
}
