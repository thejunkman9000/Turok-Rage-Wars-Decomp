#include "types.h"
typedef struct Shared_MenuDefinition Shared_MenuDefinition;
struct Shared_MenuDefinition {
    u32 unknown00[3];
    s16 unkC;
    u16 unknown0E;
    u16 unknown10;
    u16 unk12;
    u32 unknown14[11];
    s32 unk40;
    Shared_MenuDefinition *unk44;
};
typedef struct Shared_MenuEntry Shared_MenuEntry;
struct Shared_MenuEntry {
    Shared_MenuDefinition *object;
    s32 id;
    Shared_MenuDefinition *focus;
    s32 data;
    s32 data10;
    s32 data14;
    s32 data18;
};
typedef struct Shared_MenuCache Shared_MenuCache;
struct Shared_MenuCache {
    u32 unknown00;
    u32 unknown04;
    s32 state;
    u32 unknown0C;
    u32 unknown10;
};
typedef struct Shared_MenuManager Shared_MenuManager;
struct Shared_MenuManager {
    s32 (*callback)(s32, s32, s32, s32);
    s32 unk4;
    s32 unk8;
    Shared_MenuEntry *unkC;
    s32 (*callback2)(s32);
    u32 unknown14[2];
    Shared_MenuCache cache[64];
    u32 unknown51C;
    s32 unk520;
    s32 unk524;
    s32 unk528;
    u32 unknown52C;
    s32 unk530;
    u32 unknown534[3];
    s32 unk540;
};

void func_00298DBC(void);
void func_00299ECC(void);
s32 func_0029A958(void);
void func_0029AC80(void *);
void func_0029ACC4(void);
f64 func_002A28CC(void);
void func_0041174C(s32);
void *func_00411E4C(s32);
s32 func_00411E70(s32);
void func_00411E98(s32);

s32 func_00298310(s32, s32, s32, s32, s32);
 

extern Shared_MenuManager *D_8014D080;

extern Shared_MenuDefinition *D_8014D090;

void func_00299368(s32 arg0) {
    s32 (*temp_v0_10)(s32, s32, s32, s32);
    s32 (*temp_v0_11)(s32, s32, s32, s32);
    s32 (*temp_v0_14)(s32, s32, s32, s32);
    s32 (*temp_v0_15)(s32, s32, s32, s32);
    s32 (*temp_v0_16)(s32, s32, s32, s32);
    s32 (*temp_v0_17)(s32, s32, s32, s32);
    s32 (*temp_v0_4)(s32, s32, s32, s32);
    s32 (*temp_v0_5)(s32, s32, s32, s32);
    s32 (*temp_v0_8)(s32, s32, s32, s32);
    s32 (*temp_v0_9)(s32, s32, s32, s32);
    s32 temp_s1;
    s32 temp_s1_2;
    s32 (*temp_a2)(s32);
    s32 (*temp_v0_7)(s32);
    s32 temp_a1;
    Shared_MenuDefinition *temp_a1_2;
    s32 temp_f2;
    s32 e03_arg_copy; 
    s32 focus_index_final; 
    s32 focus_index; 
    s32 callback_status; 
    s32 callback_status_5; 
    s32 temp_s0_10;
    s32 temp_s0_11;
    s32 temp_s0_12;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 temp_s2;
    s32 load_flag;
    s32 *transition_state;
    s32 temp_s4;
    s32 temp_v0_2;
    Shared_MenuDefinition *regpart_temp_v0_2; 
    s32 temp_v1;
    s32 search_bound; 
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_s1_2;
    s32 var_s2;
    Shared_MenuEntry *search_entries;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1_3;
    Shared_MenuManager *temp_a0;
    Shared_MenuEntry *temp_a0_2;
    Shared_MenuEntry *temp_a0_3;
    Shared_MenuDefinition *temp_a0_4;
    Shared_MenuEntry *temp_a0_5;
    Shared_MenuEntry *temp_a0_6;
    Shared_MenuDefinition *temp_a0_7;
    void *temp_s0;
    Shared_MenuDefinition *temp_v0;
    Shared_MenuDefinition *temp_v0_13;
    Shared_MenuDefinition *temp_v0_3;
    Shared_MenuDefinition *temp_v0_6;
    Shared_MenuManager *temp_v1_2;
    Shared_MenuDefinition *var_s1;
    Shared_MenuCache *var_v0_2;
    Shared_MenuEntry *var_v1;
    Shared_MenuEntry *var_v1_2;

    func_0029ACC4();
    var_s2 = 0;
    var_s5 = 1;
    if (D_8014D080->unk4 >= 0) {
        func_0029A958();
    }
    temp_v1 = D_8014D080->unk4;
    temp_s0 = D_8014D080->unkC;
    var_a0 = 0;
    if (temp_v1 >= 0) {
        search_bound = temp_v1;
        var_v1 = (void *)temp_s0;
loop_4:
        var_a0 += 1;
        if (var_v1->id == arg0) {
            goto block_found_trampoline;
        }
        var_v1++;
        if (search_bound >= var_a0) {
            goto loop_4;
        }
    }
    var_v0 = 0;
block_search_check:
    if (var_v0 == 0) {
        goto block_not_found;
    }
    {
        temp_s4 = func_0029A958();
        var_a0_2 = D_8014D080->unk8;
        temp_a1 = D_8014D080->unk4;
        if (temp_a1 >= var_a0_2) {
            search_entries = D_8014D080->unkC;
            do {
                if (search_entries[var_a0_2].id == arg0) {
                    var_s2 = 1;
                }
                var_a0_2 += 1;
            } while (temp_a1 >= var_a0_2);
        }
        temp_a0 = D_8014D080;
        if (((Shared_MenuEntry *)temp_s0)[temp_a0->unk4].id != arg0) {
            do {
                temp_a0->unk530 = 1;
                func_00299ECC();
                
                temp_a0 = D_8014D080;
            } while (((Shared_MenuEntry *)temp_s0)[D_8014D080->unk4].id != arg0);
        }
        D_8014D080->unk540 = 0;
        D_8014D080->unk528 = temp_s4;
        if (var_s2 == 0) {
            func_0041174C(arg0);
            temp_v0 = func_00411E4C(arg0);
            temp_a0_2 = ((void *)&D_8014D080->unkC[D_8014D080->unk4]);
            temp_a0_2->object = temp_v0;
            temp_a0_2->id = arg0;
            temp_a0_2->focus = temp_v0->unk44;
            D_8014D090 = temp_v0->unk44;
            var_s1 = temp_v0;
            func_00298DBC();
            if (((u16) var_s1->unk12 >> 0xC) & 1) {
                
                load_flag = 1;
                temp_s2 = D_8014D080->unk4;
loop_18:
                if ((((u16) var_s1->unk12 >> 0xC) & 1) == load_flag) {
                    temp_v0_2 = --D_8014D080->unk4;
                    D_8014D080->unk8 = temp_v0_2;
                    
                    var_a0 = D_8014D080->unk4;
                    func_0041174C(D_8014D080->unkC[var_a0].id);
                    temp_s0_2 = D_8014D080->unkC[D_8014D080->unk4].id;
                    temp_v0_3 = func_00411E4C(temp_s0_2);
                    temp_a0_3 = ((void *)&D_8014D080->unkC[D_8014D080->unk4]);
                    temp_a0_3->object = temp_v0_3;
                    temp_a0_3->id = temp_s0_2;
                    temp_a0_3->focus = temp_v0_3->unk44;
                    D_8014D090 = temp_v0_3->unk44;
                    D_8014D080->unk540 = 0;
                    var_s1 = temp_v0_3;
                    func_00298DBC();
                    goto loop_18;
                }
                D_8014D080->unk4 = temp_s2;
            }
            goto block_78;
block_found_trampoline:
            var_v0 = 1;
            goto block_search_check;
        } else {
            var_s1 = D_8014D080->unkC[D_8014D080->unk4].object;
            D_8014D080->unk540 = 0;
            if (((Shared_MenuManager *)D_8014D080)->unk4 != -1) {
                temp_v0_4 = D_8014D080->callback;
                if (temp_v0_4 != 0) {
                    temp_s0_3 = D_8014D080->unk520;
                    D_8014D080->unk520 = 0;
                    temp_v0_4(0xE07, 0, 0, 0);
                    callback_status = D_8014D080->unk520;
                    if (callback_status == 1) {
                        var_s5 = 0;
                        D_8014D080->unk520 = temp_s0_3;
                        goto after_found_callback;
                    }
                    D_8014D080->unk520 = temp_s0_3;
                }
                func_00298310(1, 0xE07, 0, 0, 0);
                goto block_27;
            } else {
block_27:
                var_s5 = 0;
            }
        }
after_found_callback:
        goto block_78;
    }
block_not_found:
    func_0041174C(arg0);
    if (((u16) (((Shared_MenuDefinition *)(func_00411E4C(arg0)))->unk12) >> 0xC) & 1) {
        temp_a0_4 = D_8014D080->unkC[D_8014D080->unk4].focus;
        if ((temp_a0_4 != 0) && ((temp_s1 = temp_a0_4->unkC, (func_00411E70((s32) temp_s1) == 0)) || (temp_s1 == D_8014D080->unkC[D_8014D080->unk4].id)) && ((focus_index = D_8014D080->unk4), (temp_s1 != D_8014D080->unk528)) && ((temp_a1 = -1), (focus_index != temp_a1))) {
            temp_v0_5 = D_8014D080->callback;
            if (temp_v0_5 != 0) {
                temp_s0_4 = D_8014D080->unk520;
                D_8014D080->unk520 = 0;
                temp_v0_5(0x10, 0, 0, 0);
                callback_status = D_8014D080->unk520;
                if (callback_status == 1) {
                    D_8014D080->unk520 = temp_s0_4;
                    goto after_focus10;
                }
                D_8014D080->unk520 = temp_s0_4;
            }
            if (temp_s1 == (((Shared_MenuDefinition *)(D_8014D080->unkC[D_8014D080->unk4].object))->unkC)) {
                func_00298A34(0x10, 0, 0, 0);
            } else {
                func_00297E3C(temp_s1, 0x10, 0, 0, 0);
            }
        }
after_focus10:
        D_8014D080->unk528 = func_0029A958();
        D_8014D080->unk4 = (s32) (D_8014D080->unk4 + 1);
        temp_v0_6 = func_00411E4C(arg0);
        temp_a0_5 = ((void *)&D_8014D080->unkC[D_8014D080->unk4]);
        temp_a0_5->object = temp_v0_6;
        temp_a0_5->id = arg0;
        temp_a0_5->focus = temp_v0_6->unk44;
        var_s1 = temp_v0_6;
        D_8014D090 = var_s1->unk44;
        func_0029AC80((void *)&D_8014D080->unkC[D_8014D080->unk4].data);
        temp_v0_7 = D_8014D080->callback2;
        if (temp_v0_7 != 0) {
            (((Shared_MenuDefinition *)(D_8014D080->unkC[D_8014D080->unk4].object))->unk40) = temp_v0_7(arg0);
        }
        D_8014D080->unk540 = 0;
        if (D_8014D080->unk4 != -1) {
            temp_v0_8 = D_8014D080->callback;
            if (temp_v0_8 != 0) {
                temp_s0_5 = D_8014D080->unk520;
                D_8014D080->unk520 = 0;
                temp_v0_8(0xE06, 0, 0, 0);
                callback_status_5 = D_8014D080->unk520;
                if (callback_status_5 == 1) {
                    D_8014D080->unk520 = temp_s0_5;
                    goto after_e06;
                }
                D_8014D080->unk520 = temp_s0_5;
            }
            func_00298310(1, 0xE06, 0, 0, 0);
        }
after_e06:
        if (((Shared_MenuManager *)D_8014D080)->unk4 != -1) {
            temp_v0_9 = D_8014D080->callback;
            if (temp_v0_9 != 0) {
                temp_s0_6 = D_8014D080->unk520;
                D_8014D080->unk520 = 0;
                temp_v0_9(0xE07, 0, 0, 0);
                callback_status = D_8014D080->unk520;
                if (callback_status == 1) {
                    D_8014D080->unk520 = temp_s0_6;
                    goto block_78;
                }
                D_8014D080->unk520 = temp_s0_6;
            }
            func_00298310(1, 0xE07, 0, 0, 0);
        }
        goto block_78;
    }
    if (D_8014D080->unk4 != -1) {
        temp_v0_10 = D_8014D080->callback;
        if (temp_v0_10 != 0) {
            temp_s0_7 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_10(0xE01, 0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_7;
                goto after_e01;
            }
            D_8014D080->unk520 = temp_s0_7;
        }
        func_00298A34(0xE01, 0, 0, 0);
    }
after_e01:
    func_0029ACC4();
    e03_arg_copy = arg0;
    if (D_8014D080->unk4 != -1) {
        temp_v0_11 = D_8014D080->callback;
        if (temp_v0_11 != 0) {
            temp_s0_8 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_11(0xE03, arg0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_8;
                goto after_e03;
            }
            D_8014D080->unk520 = temp_s0_8;
        }
        func_00298A34(0xE03, e03_arg_copy, 0, 0);
    }
after_e03:
    temp_v1_2 = D_8014D080;
    temp_v0_2 = temp_v1_2->unk4;
    var_s1_2 = temp_v1_2->unk8;
    if (temp_v0_2 >= 0) {
        if (temp_v0_2 >= var_s1_2) {
            var_s0 = var_s1_2;
            do {
                var_s1_2 += 1;
                func_00411E98(temp_v1_2->unkC[var_s0].id);
                temp_v1_2 = D_8014D080;
                D_8014D080->unkC[var_s0].object = 0;
                D_8014D080->unkC[var_s0].focus = 0;
                var_s0 += 1;
            } while (D_8014D080->unk4 >= var_s1_2);
        }
        var_v1_3 = 0x3F;
        var_v0_2 = D_8014D080->cache;
        do {
            var_v0_2->state = 0;
            var_v1_3 -= 1;
            var_v0_2++;
        } while (var_v1_3 >= 0);
        
        temp_v1_2 = D_8014D080;
    }
    temp_v1_2->unk8 = temp_v1_2->unk4;
    D_8014D080->unk528 = func_0029A958();
    D_8014D080->unk4 = (s32) (D_8014D080->unk4 + 1);
    temp_v0_13 = func_00411E4C(arg0);
    temp_a0_6 = ((void *)&D_8014D080->unkC[D_8014D080->unk4]);
    temp_a0_6->object = temp_v0_13;
    temp_a0_6->id = arg0;
    temp_a0_6->focus = temp_v0_13->unk44;
    D_8014D090 = temp_v0_13->unk44;
    D_8014D080->unk8 = (s32) D_8014D080->unk4;
    temp_a2 = D_8014D080->callback2;
    var_s1 = temp_v0_13;
    if (temp_a2 != 0) {
        (((Shared_MenuDefinition *)(D_8014D080->unkC[D_8014D080->unk4].object))->unk40) = temp_a2(arg0);
    }
    D_8014D080->unk540 = 0;
    if (D_8014D080->unk4 != -1) {
        temp_v0_14 = D_8014D080->callback;
        if (temp_v0_14 != 0) {
            temp_s0_9 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_14(0xE06, 0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_9;
                goto after_e06_second;
            }
            D_8014D080->unk520 = temp_s0_9;
        }
        func_00298310(1, 0xE06, 0, 0, 0);
    }
after_e06_second:
    if (((Shared_MenuManager *)D_8014D080)->unk4 != -1) {
        temp_v0_15 = D_8014D080->callback;
        if (temp_v0_15 != 0) {
            temp_s0_10 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_15(0xE07, 0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_10;
                goto after_e07_second;
            }
            D_8014D080->unk520 = temp_s0_10;
        }
        func_00298310(1, 0xE07, 0, 0, 0);
    }
after_e07_second:
    if (func_0029A958() != arg0) {
        D_8014D080->unk540 = 0;
        return;
    }
block_78:
    transition_state = &D_8014D080->unk530;
    *transition_state = 1;
    while (var_s5 != 0) {
        var_s5 = 0;
        regpart_temp_v0_2 = D_8014D090;
        temp_a1_2 = var_s1->unk44;
        if (regpart_temp_v0_2 != temp_a1_2) {
            
            temp_a0 = D_8014D080;
            temp_v1 = temp_a0->unk4;
            temp_a0->unkC[temp_v1].focus = temp_a1_2;
        }
    }
    temp_a0_7 = D_8014D080->unkC[D_8014D080->unk4].focus;
    if ((temp_a0_7 != 0) && ((temp_s1_2 = temp_a0_7->unkC, (func_00411E70((s32) temp_s1_2) == 0)) || (temp_s1_2 == D_8014D080->unkC[D_8014D080->unk4].id)) && ((focus_index_final = D_8014D080->unk4), (temp_s1_2 != D_8014D080->unk528)) && ((temp_a1 = -1), (focus_index_final != temp_a1))) {
        temp_v0_16 = D_8014D080->callback;
        if (temp_v0_16 != 0) {
            temp_s0_11 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_16(0xF, 0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_11;
                goto after_focus;
            }
            D_8014D080->unk520 = temp_s0_11;
        }
        if (temp_s1_2 == (((Shared_MenuDefinition *)(D_8014D080->unkC[D_8014D080->unk4].object))->unkC)) {
            func_00298A34(0xF, 0, 0, 0);
        } else {
            func_00297E3C(temp_s1_2, 0xF, 0, 0, 0);
        }
    }
after_focus:
    if (D_8014D080->unk4 != -1) {
        temp_v0_17 = D_8014D080->callback;
        if (temp_v0_17 != 0) {
            temp_s0_12 = D_8014D080->unk520;
            D_8014D080->unk520 = 0;
            temp_v0_17(0xE08, 0, 0, 0);
            callback_status = D_8014D080->unk520;
            if (callback_status == 1) {
                D_8014D080->unk520 = temp_s0_12;
                goto after_e08;
            }
            D_8014D080->unk520 = temp_s0_12;
        }
        temp_f2 = (s32)(func_002A28CC() * 1000.0);
        func_00298310(1, 0xE08, temp_f2 - D_8014D080->unk524, temp_f2, 0);
    }
after_e08:
}
