#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "shared/func_80214624_de_closed.h"

s32 func_00214624(Actor_func_80214624_de *arg0, Plan *arg1, Actor_func_80214624_de *arg2) {
    Vec3 pos,hit;
    s32 room;
    f32 temp_f20;
    Actor_func_80214624_de *temp_a2;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v0;
    ApproachLocation *temp_v0;
    Runtime *temp_v1;

    if (arg1->unk4 == 0) {
        var_s1 = 6;
    } else if (arg2 == 0) {
        var_s1 = 3;
        if (arg1->unk94 != 0) {
            var_s1 = 4;
        }
    } else {
        var_s1 = 2;
        if (arg2 != arg1->unk68) {
            if (*arg2->unk18 == 5) var_s1=5;
            else if(arg2->unkE4==0x64F) var_s1=7;
            else {
                var_s1=0;
                if(!D_8013B290) {
                    if((!(arg2->unk100&0x300000) || arg2->unk1D8->unk794!=arg0 || (var_s1=1,arg2->unk1D8->unk788!=2)) && (!(arg0->unk2E0&2) || (var_s1=1,arg0->unkE4==0xCA))) var_s1=0;
                }
            }
        }
    }
    switch (var_s1) {
    case 6:
        pos = arg0->pos;
        room = arg0->unk14;
        break;
    case 4:
        temp_v0 = func_80219408_de(&arg1->unk94);
        pos = temp_v0->pos;
        room = temp_v0->unkC;
        break;
    case 3:
        pos = arg1->pos;
        room = arg1->unkBC;
        break;
    case 7:
        approach(arg0,arg2,arg1->unk80,&pos,&room);
        break;
    case 1:
        temp_v0_2 = func_80240698_de(arg0, arg1->unk84, arg2->pos, arg2->unk14, arg1->unk30->unkC, &pos);
        room = temp_v0_2;
        if (temp_v0_2 == 0) {
        default:
            pos = arg2->pos;
            room = arg2->unk14;
        }
        break;
    }
    if (func_80240660_de(arg0, pos, room, arg1->unk30->unkC, &hit) != 0) {
        if (func_80275B10_de(arg0->unk14, hit.x, hit.z) != 0) {
            arg1->unk90 = hit.y;
        } else {
            arg1->unk90 = (f32) (hit.y + D_800C2160_de[0]);
        }
        func_80271F68_de(&hit, &hit, &arg0->pos);
        arg1->unk8C = (f32) (func_80271AA8_de(&hit) + D_800C2160_de[1]);
        return 1;
    }
    if (var_s1 == 1) {
        arg1->unk90 = pos.y;
        arg1->unk8C = (f32) (arg0->unk6C + func_80216F44_de(arg0, pos));
        return 1;
    }
    return 0;
}
