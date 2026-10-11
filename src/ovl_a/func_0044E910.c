/* their2 */
/* Port of func_8044DCC0_de.c of the other decompilation (CC0): func_0044E910 + func_0044E9A0, symbols renamed to US v1.1 names. */
#include "span_1000/code_802A25C4.h"
#include "span_16E000/code_8044E2B8.h"
#include "types.h"

extern struct State_func_8044DD50_de D_801468A0;
extern char D_801469A0;
extern void func_00264874(s32 a);

s32 func_0044E910(void) {
    Vtx *vertices = (Vtx *)&D_801469A0;
    s32 i = 0;
    s32 more;

    vertices[0].x = -1;
    vertices[0].z = 1;
    vertices[0].s = 0;
    vertices[0].t = 0;
    vertices[1].x = 1;
    vertices[1].z = 1;
    vertices[1].s = 1024;
    vertices[1].t = 0;
    vertices[2].x = 1;
    vertices[2].z = -1;
    vertices[2].s = 1024;
    vertices[2].t = 1024;
    vertices[3].x = -1;
    vertices[3].z = -1;
    vertices[3].s = 0;
    vertices[3].t = 1024;
    do {
        vertices[i].y = 0;
        vertices[i].flag = 0;
        vertices[i].r = 255;
        vertices[i].g = 255;
        vertices[i].b = 255;
        vertices[i].a = 255;
        i++;
        more = i < 4;
    } while (more);
    return more;
}

/* Resets a match: calls func_00264874 with zero, func_00285D00 on D_8010EC90 and func_0022A870 on
   D_80145040, clears five state words of D_801468A0, and sets the byte at offset 0x26DC1 of the
   match block to 2 and its word at 0x26DBC to one. */

extern char D_8010EC90[];
extern char D_80145040[];

extern void func_00285D00(void *);
extern void func_0022A870(void *);

void func_0044E9A0(char *match) {
    struct State_func_8044DD50_de *state;

    func_00264874(0);
    func_00285D00(D_8010EC90);
    func_0022A870(D_80145040);
    state = &D_801468A0;
    state->a = 0;
    state->b = 0;
    state->c = 0;
    state->d = 0;
    state->e = 0;
    ((func_8044E9A0_S1 *)(match))->unk26DC1 = 2;
    ((func_8044E9A0_S1 *)(match))->unk26DBC = 1;
}
