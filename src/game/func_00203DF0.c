#include "b01_types.h"

void func_00273930(void *mtx, f32 angle);
void func_00273CD8(void *mtx, f32 angle);

void func_00203DF0(void *mtx, B01Hit *hit) {
    B01Info *info = B01_INFO(hit->actor->def);
    if (hit->unk4 == info->unk3C) {
        func_00273930(mtx, hit->actor->unk294);
    }
    if (hit->unk4 == info->unk40.i) {
        func_00273CD8(mtx, hit->actor->unk20C - hit->actor->unk6C);
    }
}
