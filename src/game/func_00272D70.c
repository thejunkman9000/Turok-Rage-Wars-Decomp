#include "span_1000/code_80271B18.h"
#include "types.h"





void func_80272D00_de(f32 (*mfThis)[4], f32 Theta, f32 X, f32 Y, f32 Z) {
    f32 sine;
    f32 cosine;
    f32 ab, bc, ca, t, one;

    sine = func_802B7130_de(Theta);
    cosine = func_802B6560_de(Theta);

    one = D_800C48D8_de;
    t = one - cosine;
    ab = X * Y * t;
    bc = Y * Z * t;
    ca = Z * X * t;

    mfThis[0][3] = mfThis[1][3] = mfThis[2][3] =
    mfThis[3][0] = mfThis[3][1] = mfThis[3][2] = 0.0f;
    mfThis[3][3] = one;

    t = X * X;
    X *= sine;
    mfThis[0][0] = t + cosine * (one - t);
    mfThis[2][1] = bc - X;
    mfThis[1][2] = bc + X;

    t = Y * Y;
    Y *= sine;
    mfThis[1][1] = t + cosine * (one - t);
    mfThis[2][0] = ca + Y;
    mfThis[0][2] = ca - Y;

    t = Z * Z;
    Z *= sine;
    mfThis[2][2] = t + cosine * (one - t);
    mfThis[1][0] = ab - Z;
    mfThis[0][1] = ab + Z;
}
