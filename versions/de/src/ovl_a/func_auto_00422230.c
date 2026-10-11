typedef int s32;
typedef unsigned char u8;
typedef struct { u8 pad[0x1C]; s32 f1C; s32 f20; } O3Q24;
extern O3Q24 *D_auto_800E0450;
void *func_00252FFC(s32 size);
void func_auto_0043C210(void *p, s32 a, s32 b, s32 c, s32 d);

s32 func_auto_00422230(void) {
    O3Q24 *p = func_00252FFC(0x24);
    D_auto_800E0450 = p;
    p->f1C = 0;
    p->f20 = 0;
    func_auto_0043C210(p, 0x67, 0, 0, 0);
    return 0;
}
