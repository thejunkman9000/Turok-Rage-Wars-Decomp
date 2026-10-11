typedef struct { unsigned char pad[0x581]; unsigned char val; } OptBlk;
extern OptBlk D_auto_80152208;
extern int func_0044252C(void *b, int v, int step, int min, int max, int round);

int func_auto_00445F60(int a, void *b) {
    OptBlk *s = &D_auto_80152208;
    s->val = func_0044252C(b, s->val, 1, 0, 3, 1);
    return 0;
}
