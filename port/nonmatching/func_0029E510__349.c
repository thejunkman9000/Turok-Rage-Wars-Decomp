#include "b22_types.h"
s32 func_0029E510(float *dst, float *src)
{
    float aug[4][8];
    s32 perm[4];
    s32 i, j, k, r, best, t;
    float piv, f, big, w;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            aug[i][j] = src[i * 4 + j];
            aug[i][j + 4] = 0.0f;
        }
        aug[i][i + 4] = 1.0f;
        perm[i] = i;
    }
    for (k = 0; k < 4; k++) {
        best = k;
        big = aug[perm[k]][k];
        if (!(0.0f <= big)) {
            big = -big;
        }
        for (r = k + 1; r < 4; r++) {
            w = aug[perm[r]][k];
            if (!(0.0f <= w)) {
                w = -w;
            }
            if (big < w) {
                big = aug[perm[r]][k];
                if (!(0.0f <= big)) {
                    big = -big;
                }
                best = r;
            }
        }
        t = perm[best];
        perm[best] = perm[k];
        perm[k] = t;
        piv = aug[perm[k]][k];
        if (piv == 0.0f) {
            return 1;
        }
        aug[perm[k]][k] = 1.0f;
        for (j = k + 1; j < 8; j++) {
            aug[perm[k]][j] = aug[perm[k]][j] / piv;
        }
        for (r = k + 1; r < 4; r++) {
            f = -aug[perm[r]][k];
            if (f != 0.0f) {
                aug[perm[r]][k] = 0.0f;
                for (j = k + 1; j < 8; j++) {
                    aug[perm[r]][j] = aug[perm[r]][j] + f * aug[perm[k]][j];
                }
            }
        }
    }
    for (k = 3; k > 0; k--) {
        for (r = k - 1; r >= 0; r--) {
            f = aug[perm[r]][k];
            for (j = k; j < 8; j++) {
                aug[perm[r]][j] = aug[perm[r]][j] - f * aug[perm[k]][j];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            dst[i * 4 + j] = aug[perm[i]][j + 4];
        }
    }
    return 0;
}
