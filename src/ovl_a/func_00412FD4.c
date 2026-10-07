#include "o02_types.h"
typedef struct { u8 fmt; u8 pad1[0x13]; s32 f14; s32 f18; } S_fmt;
typedef struct { s32 w[13]; } S_row;
extern S_row D_800E2B20[];
extern S_row D_80153D20;
extern S_row D_80153CE0;
extern void (*D_80153CD0)(void);
extern void (*D_80153CD4)(void);
extern void (*D_80153CD8)(void);
extern void (*D_80153CDC)(void);
extern S_fmt *D_80153D54;
extern S_fmt *D_80153D58;
extern s32 D_80153C60, D_80153C64, D_80153C6C, D_80153C70, D_80153C78, D_80153C7C, D_80153C84, D_80153C88;
extern s32 D_80153C90, D_80153C94, D_80153C98, D_80153C9C;
extern s32 D_80153CA0, D_80153CA4, D_80153CA8, D_80153CAC;
extern s32 D_80153CB0, D_80153CB4, D_80153CB8, D_80153CBC;
extern s32 D_80153CC0, D_80153CC4, D_80153CC8, D_80153CCC;
void func_0041404C(void);
void func_00414078(void);
void func_004140A4(void);
void func_004140EC(void);
void func_00414114(void);
void func_0041413C(void);
void func_004141B8(void);
void func_004141E8(void);
void func_00414240(void);
void func_00414260(void);
void func_00414280(void);
void func_004142A0(void);
void func_004142C4(void);
void func_00412FD4(S_fmt *a, S_fmt *b) {
    S_row r;
    S_row r2;
    s32 v;
    D_80153CDC = 0;
    D_80153CD8 = 0;
    D_80153CD4 = 0;
    D_80153CD0 = 0;
    D_80153C88 = 0;
    D_80153C7C = 0;
    D_80153C70 = 0;
    D_80153C64 = 0;
    D_80153C84 = 0;
    D_80153C78 = 0;
    D_80153C6C = 0;
    D_80153C60 = 0;
    D_80153D58 = 0;
    D_80153D54 = 0;
    if (a != 0) {
        D_80153D58 = a;
        r = D_800E2B20[a->fmt];
        D_80153D20 = r;
        if (r.w[1] != 0) {
            D_80153C70 = a->f14;
        } else {
            D_80153C70 = a->f18;
        }
        if (r.w[1] != 0) {
            D_80153C88 = a->f18;
        } else {
            D_80153C88 = 0;
        }
        if (r.w[3] == 16) {
            D_80153CD4 = func_004140EC;
        } else if (r.w[3] == 24) {
            D_80153CD4 = func_0041413C;
        } else if (r.w[3] == 32) {
            D_80153CD4 = func_00414114;
        }
        if (r.w[2] == 4) {
            D_80153CDC = func_004142C4;
        } else if (r.w[2] == 8) {
            D_80153CDC = func_004142A0;
        }
        D_80153CA0 = r.w[5];
        D_80153CA4 = r.w[6];
        D_80153CA8 = r.w[7];
        D_80153CAC = r.w[8];
        D_80153CC0 = r.w[9];
        D_80153CC4 = r.w[10];
        D_80153CC8 = r.w[11];
        D_80153CCC = r.w[12];
    }
    if (b != 0) {
        D_80153D54 = b;
        r2 = D_800E2B20[b->fmt];
        D_80153CE0 = r2;
        if (r2.w[1] != 0) {
            D_80153C64 = b->f14;
        } else {
            D_80153C64 = b->f18;
        }
        if (r2.w[1] != 0) {
            D_80153C7C = b->f18;
        } else {
            D_80153C7C = 0;
        }
        if (r2.w[3] == 16) {
            D_80153CD0 = func_0041404C;
        } else if (r2.w[3] == 24) {
            D_80153CD0 = func_004140A4;
        } else if (r2.w[3] == 32) {
            D_80153CD0 = func_00414078;
        }
        if (r2.w[2] == 4) {
            D_80153CD8 = func_004141E8;
        } else if (r2.w[2] == 8) {
            D_80153CD8 = func_004141B8;
        } else if (r2.w[2] == 16) {
            D_80153CD8 = func_00414240;
        } else if (r2.w[2] == 24) {
            D_80153CD8 = func_00414260;
        } else if (r2.w[2] == 32) {
            D_80153CD8 = func_00414280;
        }
        D_80153C90 = r2.w[5];
        D_80153C94 = r2.w[6];
        D_80153C98 = r2.w[7];
        D_80153C9C = r2.w[8];
        D_80153CB0 = r2.w[9];
        D_80153CB4 = r2.w[10];
        D_80153CB8 = r2.w[11];
        D_80153CBC = r2.w[12];
    }
}
