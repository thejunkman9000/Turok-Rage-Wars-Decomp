#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022A274.h"
#include "common/data.h"
#include "common/unused.h"
#include "span_1000/code_80225D10.h"

#include "shared/gameplay_round_rules.h"

/* Updates round state, player health and round-start presentation. */

typedef struct Shared_func_80227014_S1 func_80227014_S1;
typedef struct Shared_func_80227014_S2 func_80227014_S2;
typedef struct Shared_func_80227014_S3 func_80227014_S3;
typedef struct Shared_func_80227014_S4 func_80227014_S4;
typedef struct Shared_func_80227014_S5 func_80227014_S5;
typedef struct Shared_func_80227014_S6 func_80227014_S6;
typedef struct Shared_func_80227014_S7 func_80227014_S7;
typedef struct Shared_func_80227014_S8 func_80227014_S8;
typedef struct Shared_func_80227014_S9 func_80227014_S9;
typedef struct Shared_func_80227014_S10 func_80227014_S10;
typedef struct Shared_func_80227014_S11 func_80227014_S11;
typedef struct Shared_func_80227014_S7 func_80227014_S12;
typedef struct Shared_func_80227014_S13 func_80227014_S13;
typedef struct Shared_func_80227014_S14 func_80227014_S14;
typedef struct Shared_func_80227014_S10 func_80227014_S15;
typedef struct Shared_func_80227014_S16 func_80227014_S16;
typedef struct Shared_func_80227014_S7 func_80227014_S17;
typedef struct Shared_func_80227014_S18 func_80227014_S18;
typedef struct Shared_func_80227014_S19 func_80227014_S19;
typedef struct Shared_func_80227014_S20 func_80227014_S20;
typedef struct Shared_func_80227014_S10 func_80227014_S21;
typedef struct Shared_func_80227014_S22 func_80227014_S22;
typedef struct Shared_func_80227014_S7 func_80227014_S23;

s32 func_80214178_de(void *, void *, s32);
void func_80218464_de(void *);
void func_80226708_de(void *);
s32 func_802281F0_de(void *);
void * func_8022A5F4_de(void *, u32);
void func_8022A748_de(void *);
void * func_8022C55C_de(void *, u32);
void func_8022C5AC_de(char *);
void func_8022C5DC_de(void *);
s32 func_8022C620_de(char *);
int func_80245784_de(void);
int func_80245798_de(void);

s32 func_802744D4_de(void);
void func_802A9234_de(s32);
s32 func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);
void func_8021B1E4_de(void *, s32, s32, s32); /* extern */
/* Provider passes the position identity as a 32-bit address; see func_8025DE54_de
 * and the published func_80230630_de caller. */
s32 func_8025DE54_de(s16, Vec3, s32, s32);

extern f32 D_800C2BA0_de;
extern f32 D_800C2BA4_de;
extern f32 D_800C2BA8_de;
extern f32 D_800C2BAC_de;
extern f32 D_800C2BB0_de;
extern f32 D_800C2BB4_de;
extern f32 D_800C2BB8_de;
extern f32 D_800C2BBC_de;
extern s32 D_800C91B8_de;
extern s32 D_800E28D0;
extern s32 D_800E28D4;




extern u8 D_801462DE;
extern func_80227014_S1 D_801468A0;
extern u8 D_801462D5;











void func_80227038_de(s8 *arg0) {
    func_80227014_S1 *initial_rules; 
    func_80227014_S1 *select_rules; 
    func_80227014_S1 *case2_rules; 
    func_80227014_S1 *case3_entry; 
    func_80227014_S1 *case3_loop; 
    func_80227014_S1 *case4_entry; 
    func_80227014_S1 *case6_entry; 
    func_80227014_S1 *case4_loop; 
    func_80227014_S1 *case6_active_rules; 
    func_80227014_S1 *rules;
    u32 state;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_5;
    s32 var_a0_7;
    f32 scaled6x;
    f32 scaled6y;
    f32 scaled5x;
    f32 scaled5y;
    f32 scaled_x4;
    f32 scaled_y4;
    f32 scaled_x;
    f32 scaled_y;
    f32 banner_half;
    f32 banner_size;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_2; /* Reused for each initialized rule and actor-kind result in the health loops. */
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_v1;
    s8 temp_v0_7;
    s8 temp_v0_9;
    s8 temp_v1_2;
    s8 temp_v1_5;
    s32 var_s2;
    func_80227014_S11 *temp_a1;
    func_80227014_S16 *temp_a1_2;
    func_80227014_S4 *temp_s1_2;
    func_80227014_S9 *temp_s1_3;
    func_80227014_S14 *temp_s1_4;
    func_80227014_S20 *temp_s1_5;
    func_80227014_S18 *temp_v0_11;
    func_80227014_S2 *temp_v0_5;
    func_80227014_S8 *temp_v0_6;
    func_80227014_S13 *temp_v0_8;
    func_80227014_S3 *temp_v1;
    func_80227014_S19 *temp_v1_3;
    func_80227014_S22 *temp_v1_4;

    if ((func_80245784_de() == 0) && (func_80245798_de() == 0) && ((initial_rules = &D_801468A0)->unk54 != 0)) {
        if ((func_802281F0_de(arg0) != 0) && (initial_rules->unk1C == 0)) {
            func_8022A748_de(arg0);
            return;
        }
        temp_v0 = func_8022C620_de(arg0);
        if (temp_v0 > 0) {
            state = D_80146914;
            switch (state) {
            case 0:
            default:
                func_8022C5AC_de(arg0);
                func_8022C5DC_de(arg0);
                D_80146914 = 1;
                return;
            case 1:
                func_8022C5DC_de(arg0);
                if (temp_v0 > 0) {
                    temp_s1 = (select_rules = &D_801468A0)->unk64;
                    if (temp_s1 == 3) {
                        temp_v0_2 = func_802744D4_de();
                        temp_v0_3 = temp_v0_2 / temp_v0;
                        if (temp_v0 == 0) {

                        }
                        if ((temp_v0 == -1) && (temp_v0_3 == 0x80000000)) {

                        }
                        var_v1 = temp_v0_2 % temp_v0;
                        select_rules->unk74 = temp_s1;
                        select_rules->unk60 = var_v1;
                        select_rules->unk5C = var_v1;
                        return;
                    } else {
                        temp_v0_4 = select_rules->unk60 + 1;
                        if (temp_v0 == 0) {

                        }
                        if ((temp_v0 == -1) && ((temp_v0_4 / temp_v0) == 0x80000000)) {

                        }
                        var_v1 = temp_v0_4 % temp_v0;
                        select_rules->unk74 = 4;
                        select_rules->unk60 = var_v1;
                        select_rules->unk5C = var_v1;
                        return;
                    }
                }
                goto state_end;
            case 2:
                if (temp_v0 > 0) {
                    (case2_rules = &D_801468A0)->unk74 = 5;
                    case2_rules->unk68 = 0xE1;
                    case2_rules->unk5C = (s32) case2_rules->unk60;
                }
                func_8022C5DC_de(arg0);
                return;
            case 5:                                 /* switch 1 */
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    banner_half = D_800C2BA0_de;
                    banner_size = D_800C2BA4_de;
                    do {
                        temp_v0_5 = func_8022A5F4_de(arg0, var_s2);
                        if (temp_v0_5 != 0) {
                            temp_v1 = temp_v0_5->unk5D8;
                            if (temp_v1->unk90 == 0) {
                                temp_s1_2 = temp_v0_5->unk5DC;
                                if ((temp_s1_2 != 0) && (temp_s1_2->unk564 == 0)) {
                                    func_802A9234_de((s32) D_801462DE);
                                    temp_f2 = temp_s1_2->unk29C;
                                    temp_f3 = temp_s1_2->unk2A0;
                                    scaled5x = temp_f2 * banner_half;
                                    scaled5y = temp_f3 * banner_half;
                                    temp_f2_2 = temp_f2 / (f32) D_800E28D0;
                                    temp_f3_2 = temp_f3 / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_2->unk2A4 + scaled5x) - (temp_f2_2 * banner_size)), (s16) (s32) ((temp_s1_2->unk2A8 + scaled5y) - (temp_f3_2 * banner_size)), temp_f2_2, temp_f3_2, 1);
                                }
                                temp_v0_5->unk5D8->unk8F = 1;
                                switch (D_80142850) {
                                case 0:
                                    func_8025DE54_de(0x18A1, temp_v0_5->position, (s32)&temp_v0_5->position, -1);
                                    break;
                                case 1:
                                    func_8025DE54_de(0x1969, temp_v0_5->position, (s32)&temp_v0_5->position, -1);
                                    break;
                                case 2:
                                    func_8025DE54_de(0x1905, temp_v0_5->position, (s32)&temp_v0_5->position, -1);
                                    break;
                                }
                                func_80218464_de(&temp_v0_5->unk938);
                                temp_v0_5->unk11B4 = 0;
                                func_80214178_de(&temp_v0_5->unk2E8, &temp_v0_5->unk458, 1);
                                func_8021B1E4_de(temp_v0_5, temp_v0_5->unk5EC, 0, 1);
                                func_80226708_de(temp_v0_5);
                                temp_v0_5->unk5E4 = (s32) D_8014284C;
                            } else {
                                if ((D_80146938 != 0) && (temp_v1->unk94 != 0)) {
                                    temp_v1_2 = temp_v1->unk80;
                                    if (temp_v1_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v1_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_5->unk18->unk18 << 8;
                                    }
                                } else {
                                    var_a0 = temp_v0_5->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (temp_v0_5->unk1450 == 0)) {
                                    var_a0 += D_800FEB10[temp_v0_5->unk5D4].value;
                                }
                                temp_v0_5->unk5E4 = var_a0;
                                temp_v0_5->unk174 = var_a0;
                            }
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= (s32) var_s2);
                }
                func_8022C5AC_de(arg0);
                D_80146914 = 6;
                return;
            case 3:
                case3_entry = &D_801468A0;
                if (temp_v0 == 0) {

                }
                if ((temp_v0 == -1) && (((s32) case3_entry->unk5C / temp_v0) == 0x80000000)) {

                }
                case3_entry->unk68 = 0;
                temp_v0_6 = func_8022C55C_de(arg0, (u32) ((s32) case3_entry->unk5C % temp_v0));
                temp_s1_3 = temp_v0_6->unk5DC;
                if ((temp_s1_3 != 0) && (temp_s1_3->unk564 == 0)) {
                    func_802A9234_de((s32) D_801462DE);
                    temp_f3_3 = temp_s1_3->unk29C;
                    temp_f2_3 = temp_s1_3->unk2A0;
                    scaled_x = temp_f3_3 * D_800C2BA8_de;
                    scaled_y = temp_f2_3 * D_800C2BA8_de;
                    temp_f2_4 = temp_f2_3 / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_3->unk2A4 + scaled_x) - ((temp_f3_3 / (f32) D_800E28D0) * D_800C2BAC_de)), (s16) (s32) ((temp_s1_3->unk2A8 + scaled_y) - (temp_f2_4 * D_800C2BAC_de)), (temp_f3_3 / (f32) D_800E28D0), temp_f2_4, 1);
                }
                rules = &D_801468A0;
                temp_a0 = rules->unk5C + 1;
                rules->unk5C = temp_a0;
                if (temp_a0 >= (((5 - temp_v0) * 0x14) - rules->unk60)) {
                    func_8022C5AC_de(arg0);
                    rules->unk74 = 7;
                    temp_v0_6->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        func_8025DE54_de(0x18A1, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    case 1:
                        func_8025DE54_de(0x1969, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    case 2:
                        func_8025DE54_de(0x1905, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    }
                    func_80218464_de(&temp_v0_6->unk938);
                    temp_v0_6->unk11B4 = 0;
                    func_80214178_de(&temp_v0_6->unk2E8, &temp_v0_6->unk458, 1);
                    func_8021B1E4_de(temp_v0_6, temp_v0_6->unk5EC, 0, 1);
                    func_80226708_de(temp_v0_6);
                }
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    temp_a1 = temp_v0_6->unk5D8;
                    case3_loop = &D_801468A0;
                    do {
                        if (temp_a1->unk8F != 0) {
                            temp_v0_6->unk5E4 = (s32) case3_loop->unk6C;
                        } else {
                            temp_v0_2 = D_80146938;
                            if ((temp_v0_2 != 0) && (temp_a1->unk94 != 0)) {
                                temp_v0_2 = temp_a1->unk80;
                                if (temp_v0_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v0_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_6->unk18->unk18 << 8;
                                    }
                            } else {
                                var_a0 = temp_v0_6->unk18->unk18 << 8;
                            }
                            temp_v0_2 = D_801462D5;
                            if ((temp_v0_2 == 1) && (temp_v0_6->unk1450 == 0)) {
                                var_a0 += D_800FEB10[temp_v0_6->unk5D4].value;
                            }
                            temp_v0_6->unk5E4 = var_a0;
                            temp_v0_6->unk174 = var_a0;
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= var_s2);
                    return;
                }
                goto state_end;
            case 4:
                case4_entry = &D_801468A0;
                if (temp_v0 == 0) {

                }
                if ((temp_v0 == -1) && (((s32) case4_entry->unk5C / temp_v0) == 0x80000000)) {

                }
                case4_entry->unk68 = 0;
                temp_v0_8 = func_8022C55C_de(arg0, (u32) ((s32) case4_entry->unk5C % temp_v0));
                temp_s1_4 = temp_v0_8->unk5DC;
                if ((temp_s1_4 != 0) && (temp_s1_4->unk564 == 0)) {
                    func_802A9234_de((s32) D_801462DE);
                    temp_f3_4 = temp_s1_4->unk29C;
                    temp_f2_5 = temp_s1_4->unk2A0;
                    scaled_x4 = temp_f3_4 * D_800C2BB0_de;
                    scaled_y4 = temp_f2_5 * D_800C2BB0_de;
                    temp_f2_6 = temp_f2_5 / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_4->unk2A4 + scaled_x4) - ((temp_f3_4 / (f32) D_800E28D0) * D_800C2BB4_de)), (s16) (s32) ((temp_s1_4->unk2A8 + scaled_y4) - (temp_f2_6 * D_800C2BB4_de)), (temp_f3_4 / (f32) D_800E28D0), temp_f2_6, 1);
                }
                rules = &D_801468A0;
                temp_a0_2 = rules->unk5C + 1;
                rules->unk5C = temp_a0_2;
                if (temp_a0_2 >= (((5 - temp_v0) * 0x14) - rules->unk60)) {
                    func_8022C5AC_de(arg0);
                    rules->unk74 = 7;
                    temp_v0_8->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        func_8025DE54_de(0x18A1, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    case 1:
                        func_8025DE54_de(0x1969, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    case 2:
                        func_8025DE54_de(0x1905, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    }
                    func_80218464_de(&temp_v0_8->unk938);
                    temp_v0_8->unk11B4 = 0;
                    func_80214178_de(&temp_v0_8->unk2E8, &temp_v0_8->unk458, 1);
                    func_8021B1E4_de(temp_v0_8, temp_v0_8->unk5EC, 0, 1);
                    func_80226708_de(temp_v0_8);
                }
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    temp_a1_2 = temp_v0_8->unk5D8;
                    case4_loop = &D_801468A0;
                    do {
                        if (temp_a1_2->unk8F != 0) {
                            temp_v0_8->unk5E4 = (s32) case4_loop->unk6C;
                        } else {
                            temp_v0_2 = D_80146938;
                            if ((temp_v0_2 != 0) && (temp_a1_2->unk94 != 0)) {
                                temp_v0_2 = temp_a1_2->unk80;
                                if (temp_v0_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v0_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_8->unk18->unk18 << 8;
                                    }
                            } else {
                                var_a0 = temp_v0_8->unk18->unk18 << 8;
                            }
                            temp_v0_2 = D_801462D5;
                            if ((temp_v0_2 == 1) && (temp_v0_8->unk1450 == 0)) {
                                var_a0 += D_800FEB10[temp_v0_8->unk5D4].value;
                            }
                            temp_v0_8->unk5E4 = var_a0;
                            temp_v0_8->unk174 = var_a0;
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= var_s2);
                    return;
                }
                goto state_end;
            case 6:
                case6_entry = &D_801468A0;
                temp_v0_10 = case6_entry->unk68 - 1;
                case6_entry->unk68 = temp_v0_10;
                if (temp_v0_10 <= 0) {
                    case6_entry->unk68 = 0;
                    if (D_800C91B8_de != 0) {
                        func_8025E2D4_de(D_800C91B8_de);
                    }
                    var_s2 = 0;
                    banner_half = D_800C2BB8_de;
                    banner_size = D_800C2BBC_de;
                    do {
                        temp_v0_11 = func_8022A5F4_de(arg0, var_s2);
                        if (temp_v0_11 != 0) {
                            temp_v1_3 = temp_v0_11->unk5D8;
                            if (temp_v1_3->unk8F == 0) {
                                temp_s1_5 = temp_v0_11->unk5DC;
                                if ((temp_s1_5 != 0) && (temp_s1_5->unk564 == 0)) {
                                    func_802A9234_de((s32) D_801462DE);
                                    temp_f2_7 = temp_s1_5->unk29C;
                                    temp_f3_5 = temp_s1_5->unk2A0;
                                    scaled6x = temp_f2_7 * banner_half;
                                    scaled6y = temp_f3_5 * banner_half;
                                    temp_f2_8 = temp_f2_7 / (f32) D_800E28D0;
                                    temp_f3_6 = temp_f3_5 / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_5->unk2A4 + scaled6x) - (temp_f2_8 * banner_size)), (s16) (s32) ((temp_s1_5->unk2A8 + scaled6y) - (temp_f3_6 * banner_size)), temp_f2_8, temp_f3_6, 1);
                                }
                                temp_v0_11->unk5D8->unk8F = 1U;
                                switch (D_80142850) {
                                case 0:
                                    func_8025DE54_de(0x18A1, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                case 1:
                                    func_8025DE54_de(0x1969, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                case 2:
                                    func_8025DE54_de(0x1905, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                }
                                func_80218464_de(&temp_v0_11->unk938);
                                temp_v0_11->unk11B4 = 0;
                                func_80214178_de(&temp_v0_11->unk2E8, &temp_v0_11->unk458, 1);
                                func_8021B1E4_de(temp_v0_11, temp_v0_11->unk5EC, 0, 1);
                                func_80226708_de(temp_v0_11);
                            } else {
                                temp_v1_3->unk90 = 0;
                                temp_v0_11->unk5D8->unk8F = 0U;
                                func_8021B1E4_de(temp_v0_11, temp_v0_11->unk5EC, 0, 1);
                            }
                            temp_v1_4 = temp_v0_11->unk5D8;
                            if (temp_v1_4->unk8F != 0) {
                                case6_active_rules = &D_801468A0;
                                temp_v0_11->unk5E4 = (s32) case6_active_rules->unk6C;
                                temp_v0_11->unk174 = (s32) case6_active_rules->unk6C;
                            } else {
                                if ((D_80146938 != 0) && (temp_v1_4->unk94 != 0)) {
                                    temp_v1_5 = temp_v1_4->unk80;
                                    if (temp_v1_5 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_5 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_5 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v1_5 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_11->unk18->unk18 << 8;
                                    }
                                } else {
                                    var_a0 = temp_v0_11->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (temp_v0_11->unk1450 == 0)) {
                                    var_a0 += D_800FEB10[temp_v0_11->unk5D4].value;
                                }
                                temp_v0_11->unk5E4 = var_a0;
                                temp_v0_11->unk174 = var_a0;
                            }
                        }
                        var_s2 += 1;
                    } while ((s32) var_s2 < 8);
                    D_80146914 = 7;
                    return;
                }
                goto state_end;
            case 7:
                D_80142848 = 0;
                goto state_end;
            }
state_end:;
        }
    }
}

