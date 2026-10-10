#include "common.h"
/* 4x4 Gauss-Jordan inverse with row permutation (partial pivoting on an augmented 4x8 matrix); returns 1 if singular */
s32 func_0029E510(float (*dst)[4], float (*src)[4])
{
    float aug[4][8];
    s32 perm[4];
    s32 i, j, k, t, r;
    float f, big, w, a;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            aug[i][j] = *(float *)((char *)src + (i * 16 + j * 4));
            aug[i][j + 4] = 0.0f;
        }
        aug[i][i + 4] = 1.0f;
        perm[i] = i;
    }
    for (k = 0; k < 4; k++) {
        j = k;
        w = aug[perm[j]][j];
        if (!(0.0f <= w)) {
            big = -w;
        } else {
            big = w;
        }
        for (i = j + 1; i < 4; i++) {
            a = aug[perm[i]][k];
            if (!(0.0f <= a)) {
                w = -a;
            } else {
                w = a;
            }
            if (big < w) {
                j = i;
                big = aug[perm[i]][k];
                if (!(0.0f <= big)) {
                    big = -big;
                }
            }
        }
        t = perm[j];
        perm[j] = perm[k];
        perm[k] = t;
        big = aug[t][k];
        if (big == 0.0f) {
            w = 0.0f;
            return 1;
        }
        aug[t][k] = 1.0f;
        for (j = k + 1; j < 8; j++) {
            aug[t][j] = aug[t][j] / big;
        }
        for (i = k + 1; i < 4; i++) {
            r = perm[i];
            f = -aug[r][k];
            if (f != 0.0f) {
                aug[r][k] = 0.0f;
                for (j = k + 1; j < 8; j++) {
                    aug[r][j] = aug[r][j] + f * aug[t][j];
                }
            }
        }
    }
    for (k = 3; k > 0; k--) {
        t = perm[k];
        for (i = k - 1; i >= 0; i--) {
            r = perm[i];
            f = aug[r][k];
            for (j = k; j < 8; j++) {
                aug[r][j] = aug[r][j] - f * aug[t][j];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        r = perm[i];
        for (j = 0; j < 4; j++) {
            *(float *)((char *)dst + (i * 16 + j * 4)) = aug[r][j + 4];
        }
    }
    return 0;
}
