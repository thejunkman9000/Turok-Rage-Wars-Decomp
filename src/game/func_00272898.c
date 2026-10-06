#include "b16_types.h"

void func_00272898(B16Mtx4 m) {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (m[i][j] > 32767.0f) {
                m[i][j] = 32767.0f;
            } else if (m[i][j] < -32767.0f) {
                m[i][j] = -32767.0f;
            }
        }
    }
}
