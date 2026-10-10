#include "span_16E000/code_80429C10.h"
#include "types.h"
#include "common/unused.h"

/* Advances the menu transition state and updates its visual effects. */










/* The values func_8042AE60_eu loads by address:
 * 0x800E1AF4 = 0.0033333334 (float, D_800EE144 in this cartridge's tables)
 * 0x800E1AF8 = 100.0 (float, D_800EE148 in this cartridge's tables)
 * 0x800E1AFC = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B00 = 2147483600.0 (float, D_800EE150 in this cartridge's tables)
 * 0x800E1B04 = 0.0033333334 (float, D_800EE154 in this cartridge's tables)
 * 0x800E1B08 = 100.0 (float, D_800EE158 in this cartridge's tables)
 * 0x800E1B0C = 150.0 (float, unnamed in this cartridge's tables)
 * 0x800E1B10 = 2147483600.0 (float, D_800EE160 in this cartridge's tables)
 */
s32 func_8025DF34_de(s32);
void func_8029973C_de(void);
void func_802A2360_de(void);

void func_8040E8D8_de(void *, int);
void * func_8040EC30_de(void *, unsigned short);
void func_80419F24_de(void *);
s32 func_80419F38_de(void *);
void func_80419F58_de(void *, int);
void func_8042A7B4_de(s32);

void func_8042E988_de(s32);
void func_80298368_de(s32);

#include "shared/func_8042AE60_eu_layout.h"
extern MenuTransitionSignal D_80154020;

















extern ListScreenScreen *D_800E4F60;

s32 func_8042AE60_eu(void *arg0, s32 arg1, s32 arg2) {
    ListScreenScreen *countdown;
    f32 var_f0;
    s32 temp_a2;
    s32 temp_s0; 
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    ListScreenItem *temp_a0;
    ListScreenItem *temp_a0_2;
    ListScreenItem *temp_a1;
    ListScreenItem *temp_a1_2;
    void *var_a0;
    ListScreenItem *var_a0_2;
    void *var_a0_3;

    if (D_80154020.trigger == 1) {
        D_80154020.trigger = 0;
        if (D_80154020.selection != -1) {
            D_800E4F60->unk_44C->alpha = 0x5A;
            func_8029973C_de();
            func_80298368_de(D_80154020.selection);
            return 0;
        }
        D_800E4F60->unk_44C->alpha = 0xFF;
        D_800E4F60->unk_3DC = 9;
        if (D_800E4F60->selection == 0) {
            func_8040E8D8_de(D_800E4F60->unk_440, 1);
            var_a0 = D_800E4F60->unk_448;
        } else {
            var_a0 = D_800E4F60->unk_444;
        }
        func_8040E8D8_de(var_a0, 1);
        func_8040E8D8_de(D_800E4F60->label, 1);
        func_8040E8D8_de(D_800E4F60->unk_3F0, 1);
        goto block_7;
    }
block_7:
    temp_v0 = D_800E4F60->unk_3DC;
    switch (temp_v0) {
    case 1:
        temp_a1 = D_800E4F60->left;
        temp_a1->x = (u16) (temp_a1->x + (u16)D_800E4F60->leftCount);
        temp_a1_2 = D_800E4F60->right;
        temp_a1_2->x = (u16) (temp_a1_2->x - (u16)D_800E4F60->rightCount);
        temp_v0_2 = D_800E4F60->unk_3E0 - 1;
        D_800E4F60->unk_3E0 = temp_v0_2;
        if (temp_v0_2 <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E4F60->unk_3E8, 1);
            func_80419F58_de(D_800E4F60->text3E4, 4);
            D_800E4F60->unk_3DC = 4;
            D_800E4F60->unk_3E0 = 4;
        }
        break;
    case 2:
        temp_a0 = D_800E4F60->left;
        temp_a0->x = (u16) (temp_a0->x - (u16)D_800E4F60->leftCount);
        temp_a0_2 = D_800E4F60->right;
        temp_a0_2->x = (u16) (temp_a0_2->x + (u16)D_800E4F60->rightCount);
        temp_v0_3 = D_800E4F60->unk_3E0 - 1;
        D_800E4F60->unk_3E0 = temp_v0_3;
        if (temp_v0_3 <= 0) {
            D_800E4F60->unk_3DC = 3;
            func_8029973C_de();
            func_80298368_de(8);
            return 0;
        }
        break;
    case 3:
        if (D_800E4F60->unk_460 == 0) {
            func_802A2360_de();
            var_a1 = 0;
            var_a0_3 = D_800E4F60->unk_458;
            D_800E4F60->unk_460 = 1;
            func_8040E8D8_de(var_a0_3, var_a1);
        }
        break;
    case 4:
        countdown = D_800E4F60;
        temp_v1 = countdown->unk_3E0;
        temp_v0_4 = temp_v1 - 1;
        if (temp_v0_4 >= 0) {
            var_v0 = temp_v1 - (temp_v1 >= temp_v0_4);
        } else {
            var_v0 = 0;
        }
        countdown->unk_3E0 = var_v0;
        
        if ((((ListScreenScreen *) D_800E4F60)->unk_3E0 <= 0) && (func_80419F38_de(D_800E4F60->text3E4) != 0)) {
            func_80419F24_de(D_800E4F60->text3E4);
            func_8042A7B4_de(0xA);
            D_800E4F60->unk_3DC = 9;
        }
        break;
    case 5:
        func_8040E8D8_de(D_800E4F60->unk_458, 1);
        func_8040E8D8_de(D_800E4F60->unk_3E8, 0);
        func_8042B2E4_de();
        func_8042A7B4_de(0);
        D_800E4F60->unk_3DC = 2;
        D_800E4F60->unk_3E0 = 4;
        func_8040E8D8_de(D_800E4F60->unk_448, 0);
        func_8025DF34_de(0xE78);
        break;
    case 8:
        temp_v0 = ((ListScreenItem *)func_8040EC30_de(arg0, 0x316U))->alpha;
        temp_s0 = temp_v0 >> 1;
        func_8042A7B4_de(temp_s0);
        if (temp_s0 < 0xA) {
            D_800E4F60->unk_3DC = 3;
            func_8042E988_de(0xB);
            return 0;
        }
        break;
    case 9:
        temp_s0 = ((ListScreenItem *)func_8040EC30_de(arg0, 0x316U))->alpha;
        temp_s0 = (temp_s0 + 1) * 2;
        if (temp_s0 >= 0x42) {
            temp_s0 = 0x41;
            D_800E4F60->unk_3DC = 3;
        }
        func_8042A7B4_de(temp_s0);
        var_a1 = 1;
        if (D_800E4F60->selection == 0) {
            var_a0_3 = D_800E4F60->unk_448;
            func_8040E8D8_de(var_a0_3, var_a1);
        }
        break;
    default:
        break;
    }
    if (D_800E4F60->unk_3DC == 3) {
            temp_a2 = D_800E4F60->unk_45C + arg2;
            D_800E4F60->unk_45C = temp_a2;
            if (D_80154020.selection == -1) {
                if (D_800E4F60->selection == 0) {
                    var_f0 = (func_802B6560_de((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->unk_448;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                } else {
                    var_f0 = (func_802B6560_de((f32) temp_a2 * 0.0033333334f) * 100.0f) + 150.0f;
                    var_a0_2 = D_800E4F60->item;
                    var_a0_2->alpha = (u8) (u32) var_f0;
                }
            }
        }
        return 0;
}

