#include "shared/sceneactorstride.h"
#include "shared/sceneglobal.h"
#include "shared/scenefontresources.h"
#include "shared/sceneactorresources.h"
#include "shared/sceneresources.h"
#include "shared/sceneprimaryactors.h"
#include "shared/sceneactorprefix.h"
#include "shared/sceneactorkind.h"
#include "shared/sceneactortables.h"
#include "shared/func_80286a78_s1.h"
#include "shared/func_80286a78_s2.h"
#include "shared/func_80286a78_s3.h"
#include "shared/func_80286a78_s4.h"
#include "shared/func_80286a78_s5.h"
#include "shared/func_80286a78_s6.h"
#include "shared/func_80286a78_s7.h"
#include "shared/func_80286a78_s8.h"
#include "shared/func_80286a78_s9.h"
#include "shared/func_80286a78_s10.h"
#include "shared/func_80286a78_s11.h"
#include "shared/func_80286a78_s12.h"
#include "shared/func_80286a78_s13.h"
#include "shared/func_80286a78_s14.h"
#include "shared/func_80286a78_s15.h"
#include "shared/func_80286a78_s16.h"
#include "shared/func_80286a78_s17.h"
#include "shared/func_80286a78_s18.h"
#include "shared/func_80286a78_s19.h"
#include "shared/func_80286a78_s20.h"
#include "shared/func_80286a78_s21.h"
#include "span_1000/code_8023D370.h"
#include "span_1000/code_8020AF9C.h"
#include "span_1000/code_80209AE8.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "span_C76B0/data.h"

#include "types.h"
#include "common/types_8a8189af7b05.h"


/* Unknown data types are explicit unresolved contracts, never guessed s32. */

extern void func_80208000_de();
extern void func_8020ABF0_de();
extern s32 func_8020CB3C_de();
extern void * func_8022A5F4_de();
extern void func_80236874_de();
extern int func_80245784_de();
extern void func_80246E44_de();
extern void func_8024B2D0_de();
extern void func_8024BE3C_de();
extern Record * func_8025305C_de();
extern struct Shape_typemap_165 * func_8025343C_de();
extern void func_80253838_de();
extern void func_80253908_de();
extern s32 func_80254284_de();
extern void ** func_80254408_de();
extern void func_8025476C_de();
extern s32 func_80255228_de();
extern void func_80255CA0_de();
extern s32 func_80255D14_de();
extern void func_8025C8D8_de();
extern void func_80286950_de();
extern void func_8028A948_de();
extern s32 func_8028B25C_de();
extern void func_8028D380_de();
extern void func_8028D64C_de();
extern void func_8028D888_de();
extern void func_8028D90C_de();
extern void func_8028DA74_de();
extern int func_8028FE28_de();
extern s32 func_802A01E8_de();
extern s32 func_802AA730_de();
extern void func_802AA760_de();
extern void func_804037E8_de();
extern void func_80449E18_de();
extern void func_8044A6CC_de();
extern void func_8044ADF0_de();
extern void func_8044B0E0_de();
extern void func_8044BFD0();
extern void func_8044C050();
extern void func_8044BE04_de();
extern void func_8044BF90_de();
extern void func_8044D5C4_de();
extern void func_8044D668_de();
extern void func_8044D794_de(arg0);
extern void func_8044DB70_de();
extern void func_8044EBB0();
extern void func_8044ED24();


extern unsigned char D_00285160[];
extern unsigned char D_0044C108[];
extern unsigned char D_0044C3D4[];
extern unsigned char D_0044C7B8[];
extern unsigned char D_0044DA54[];
extern unsigned char D_80106248[];
extern unsigned char D_8011AFC0[];


extern unsigned char D_8011FE88[];


extern struct Shared_SceneGlobal D_80145040;
extern struct Shared_SceneResources D_801376F8;
extern void *D_80145060;
extern u8 D_801462E5;
extern unsigned char D_801468A0[];






extern unsigned char D_800C5104_de[];                          /* unable to generate initializer: unknown type; const */

                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C511C_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5128_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5134_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5148_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5154_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5160_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5168_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5174_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5180_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C5190_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51A0_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51B4_de[];                          /* unable to generate initializer: unknown type; const */
extern unsigned char D_800C51C0_de[];                          /* unable to generate initializer: unknown type; const */
extern s32 D_800CC380;                          /* const */
extern s32 D_800CD730;                          /* const */

       /* const */
extern struct Shared_SceneActorTables D_800F3CD0; /* const */






















/* const */

/* Initializes scene resources, actors, and game mode state. */
void func_80286AA8_de(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_a0;
    struct Shape_typemap_165 *temp_v0_4;
    s32 temp_s4; 
    s32 temp_s4_2;
    s32 temp_v0;
    s32 resource_count; 
    s32 temp_v0_16;
    s32 temp_v0_20;
    s32 temp_v0_21;
    s32 temp_v0_5;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a2;
    s32 var_a3;
    s32 var_s0;
    s32 kind_actor; 
    s32 kind_654;
    s32 kind_653;
    s32 kind_655;
    s32 second_type3; 
    s32 second_type10;
    s32 second_kind_bd6;
    s32 second_kind_64e;
    s32 header_copy0; 
    s32 header_copy1;
    s32 header_copy2;
    s32 header_copy3;
    s32 header_copy4;
    s32 header_copy5;
    Record *var_s0_2;
    s32 loop_buffer; 
    s32 var_s0_4;
    s32 var_s1_3;
    s32 var_s1_5;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_4;
    s32 var_s5;
    s32 var_s6;
    s32 kind_656; 
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 actor_kind_bd7; 
    s32 first_actor_kind; 
    s32 actor_type3; 
    s32 var_v1_2;
    s32 temp_v1_8;
    u8 temp_v0_3;
    void **temp_v0_10;
    void **temp_v0_11;
    void **temp_v0_12;
    void **temp_v0_14;
    void **temp_v0_17;
    void **temp_v0_19;
    void **temp_v0_6;
    void **temp_v0_7;
    void *temp_a2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    struct func_80203E78_S1 *temp_v0_13;
    struct func_80203E78_S1 *temp_v0_15;
    struct func_80203E78_S1 *temp_v0_18;
    struct Shared_SceneActorKind *var_s2_3;
    void *temp_v0_2;
    struct Shared_func_80286A78_S2 *scene_actor_ptr;
    void *temp_v1;
    struct Shared_func_80286A78_S7 *temp_v1_5;
    void *temp_v1_6;
    struct Shared_func_80286A78_S17 *temp_v1_7;
    struct Shared_func_80286A78_S19 *temp_v1_9;
    void *var_a0;
    void *var_a1;
    struct Shared_SceneActorKind *var_a1_2;
    void *var_a2_2;
    void *var_s0_5;
    struct Shared_func_80286A78_S2 *var_s1_4; 
    void *var_v0;

    var_s6 = arg1;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B2FC) = D_800C51D4;
    var_s5 = arg2;
    if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk1B40C) != -1) {
        func_8044D794_de(arg0);
    }
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B6AC) = 0;
    if ((func_80245784_de() == 0) && (var_s5 != 0) && ((((struct Shared_func_80286A78_S1 *)(arg0))->unk1B41C) != 0) && (D_8014288C == 0)) {
        func_8028D90C_de();
        temp_v0 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B434);
        if ((u32) (temp_v0 - 0xBC2) < 0x15FU) {
            func_804037E8_de(((temp_v0 - 0xBC2) / 10) + 0x259);
        }
        func_8028A948_de();
    }
    func_8028D888_de(arg0);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk0) = 0;
    func_80255228_de(&D_80106248);
    func_8028DA74_de(arg0);
    func_80253908_de(0);
    if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk1B40C) != -1) {
        func_8044BF90_de(arg0);
    }
    func_80253908_de(0);
    D_800CD730 = 0;
    func_8025476C_de(8);
    func_8028D64C_de(arg0);
    func_8044C050(&((struct Shared_func_80286A78_S1 *)arg0)->address1B08, *(((struct Shared_func_80286A78_S1 *)(arg0))->unkB4));
    var_s2 = 0;
    func_8044DB70_de(&((struct Shared_func_80286A78_S1 *)arg0)->address11778);
    func_8044ADF0_de(&((struct Shared_func_80286A78_S1 *)arg0)->address15388);
    func_8044EBB0(&D_801376F8.actors);
    func_8023EE00_de();
    func_8044B0E0_de(&((struct Shared_func_80286A78_S1 *)arg0)->address1B320);
    func_8025C8D8_de(&D_8011F260, &D_8011AFC0, 0xF);
    func_8044ED24(&D_801376F8);
    do {
        var_s1_4 = func_8022A5F4_de(&D_80145040, var_s2);
        if (var_s1_4 != 0) {
            temp_v1 = var_s1_4->unk5D8;
            if ((((struct Shared_func_80286A78_S3 *)temp_v1)->unk78 == 1) && (((struct Shared_func_80286A78_S3 *)temp_v1)->unk91 == 1)) {
                func_80208000_de(var_s1_4->unk1454);
            }
            if ((((struct Shared_func_80286A78_S4 *)(&D_801468A0))->unk98) != 0) {
                temp_a2 = var_s1_4->unk5D8;
                temp_v0_3 = (((struct Shared_func_80286A78_S5 *)(temp_a2))->unk94);
                if (temp_v0_3 != 0) {
                    if (temp_v0_3 == 1) {
                        func_802AA730_de(&D_801376F8, var_s1_4, &((struct Shared_func_80286A78_S5 *)temp_a2)->address84);
                    } else if (temp_v0_3 == 2) {
                        func_802AA760_de(&D_801376F8, var_s1_4, &((struct Shared_func_80286A78_S5 *)temp_a2)->address84);
                    }
                    if (var_s1_4->unk5D8->unk80 == 0xB) {
                        func_802AA730_de(&D_801376F8, var_s1_4, D_800D3164);
                    }
                }
            }
        }
        var_s2 += 1;
    } while (var_s2 < 8);
    temp_v1_2 = *(((struct Shared_func_80286A78_S1 *)(arg0))->unk4C);
    if (temp_v1_2 < var_s6) {
        var_s6 = temp_v1_2 - 1;
        var_s5 = 0;
    }
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B40C) = var_s6;
    if (var_s5 == 0) {
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B41C) = 0;
    }
    func_8028D380_de(arg0, var_s6, &((struct Shared_func_80286A78_S1 *)arg0)->address1B2BC, 0x3F);
    temp_v1_3 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B434);
    if (temp_v1_3 < 0x1CEA) {
        if (temp_v1_3 < 0x1CE8) {
            if (temp_v1_3 != 0x1BBC) {
                if (temp_v1_3 < 0x1BBD) {
                    if (temp_v1_3 == 0x123A) {
                        goto scene_flag_on;
                    }
                    goto scene_flag_off;
                } else if (temp_v1_3 != 0x1C20) {
                    if (temp_v1_3 == 0x1C84) {
                        goto scene_flag_on;
                    }
                    goto scene_flag_off;
                }
            }
        }
    } else {
        if (temp_v1_3 < 0x1D4C) {
            goto scene_flag_off;
        }
        if (temp_v1_3 >= 0x1D4E) {
            if (temp_v1_3 >= 0x1DB3) {
                goto scene_flag_off;
            }
            if (temp_v1_3 < 0x1DB1) {
                goto scene_flag_off;
            }
        }
    }
scene_flag_on:
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B408) = 1;
    goto scene_flag_done;
scene_flag_off:
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B408) = 0;
scene_flag_done:
    temp_v1_4 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B434);
    if (temp_v1_4 < 0x1CEA) {
        if (temp_v1_4 < 0x1CE8) {
            if (temp_v1_4 != 0x1BBC) {
                if (temp_v1_4 < 0x1BBD) {
                    var_s0 = 0x320;
                    if (temp_v1_4 == 0x123A) {
                        goto scene_size_c80;
                    }
                    goto scene_size_done;
                }
                if (temp_v1_4 == 0x1C20) {
                    goto scene_size_c80;
                }
                var_s0 = 0x320;
                if (temp_v1_4 == 0x1C84) {
                    goto scene_size_c80;
                }
                goto scene_size_done;
            }
        }
        goto scene_size_c80;
    }
    if (temp_v1_4 == 0x1DB1) {
        goto scene_size_4b0;
    }
    if (temp_v1_4 < 0x1DB2) {
        if (temp_v1_4 < 0x1D4E) {
            var_s0 = 0x320;
            if (temp_v1_4 < 0x1D4C) {
                goto scene_size_done;
            }
            goto scene_size_c80;
        }
        goto scene_size_320;
    }
    var_s0 = 0x320;
    if (temp_v1_4 == 0x1DB2) {
        goto scene_size_c80;
    }
    goto scene_size_done;
scene_size_c80:
    var_s0 = 0xC80;
    goto scene_size_done;
scene_size_4b0:
    var_s0 = 0x4B0;
    goto scene_size_done;
scene_size_320:
    var_s0 = 0x320;
scene_size_done:
    if (D_801462E5 != 0) {
        var_s0 += 0x200;
    }
    func_80253908_de(0);
    temp_v0_4 = func_8025343C_de(0, var_s0 << 6, 3, &D_800C5104_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkE8) = (void *)temp_v0_4;
    func_8044BFD0(&((struct Shared_func_80286A78_S1 *)arg0)->address128, temp_v0_4->field_0, var_s0);
    temp_v0_5 = func_8028FE28_de((((struct Shared_func_80286A78_S1 *)(arg0))->unk4C), (((struct Shared_func_80286A78_S1 *)(arg0))->unk1C), var_s6);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkB8) = func_80254284_de(0, &((struct Shared_func_80286A78_S1 *)arg0)->unk60, temp_v0_5, &D_800C5110_de);
    temp_v0_6 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 1, temp_v0_5, arg0, &D_0044C3D4, &D_800C511C_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkBC) = temp_v0_6;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk6C) = (void *) *temp_v0_6;
    temp_v0_7 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 4, temp_v0_5, arg0, &D_00285160, &D_800C5128_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkC0) = temp_v0_7;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk68) = (void *) *temp_v0_7;
    temp_v0_8 = func_8028FE28_de((((struct Shared_func_80286A78_S1 *)(arg0))->unk60), temp_v0_5, 5);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk30) = temp_v0_8;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkC4) = func_80254284_de(0, &((struct Shared_func_80286A78_S1 *)arg0)->address64, temp_v0_8, &D_800C5134_de);
    if (*(((struct Shared_func_80286A78_S1 *)(arg0))->unk60) >= 0xD) {
        temp_v0_9 = func_8028FE28_de((((struct Shared_func_80286A78_S1 *)(arg0))->unk60), temp_v0_5, 0xC);
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk40) = temp_v0_9;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk100) = func_80254284_de(0, &((struct Shared_func_80286A78_S1 *)arg0)->unk8C, temp_v0_9, &D_800C5148_de);
        temp_v0_10 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk8C), 0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk40), arg0, 0, &D_800C5154_de);
        temp_v1_5 = *temp_v0_10;
        *(struct Shared_func_80286A78_S7 *)&((struct Shared_func_80286A78_S1 *)arg0)->unk1B910 = *temp_v1_5;
        func_80253838_de(0, temp_v0_10);
        if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk1B920) != 0 || (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B924) != 0) {
            (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B92C) = 1;
        } else {
            (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B92C) = 0;
        }
    } else {
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B92C) = 0;
    }
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkD4) = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 7, temp_v0_5, arg0, &D_0044C108, &D_800C5160_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkEC) = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 2, temp_v0_5, arg0, &D_0044DA54, &D_800C5168_de);
    temp_v0_11 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 0, temp_v0_5, arg0, 0, &D_800C5174_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkC8) = temp_v0_11;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B2B0) = (void *) *temp_v0_11;
    func_8044BE04_de(arg0);
    resource_count = *(((struct Shared_func_80286A78_S1 *)(arg0))->unk60);
    D_800CC380 = ((u8) (((struct Shared_func_80286A78_S8 *)(((struct Shared_func_80286A78_S1 *)(arg0))->unk1B2B0))->unk10) >> 2) & 1;
    if (resource_count >= 9) {
        temp_v0_12 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 9, temp_v0_5, arg0, &D_00285160, &D_800C5180_de);
        (((struct Shared_func_80286A78_S1 *)(arg0))->unkF0) = temp_v0_12;
        temp_v0_13 = *temp_v0_12;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4DC) = temp_v0_13;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4E0) = (s32) temp_v0_13->unk4;
        temp_v0_14 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 0xA, temp_v0_5, arg0, &D_00285160, &D_800C5190_de);
        (((struct Shared_func_80286A78_S1 *)(arg0))->unkF4) = temp_v0_14;
        temp_v0_15 = *temp_v0_14;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4E4) = temp_v0_15;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4E8) = (s32) temp_v0_15->unk4;
        func_80255CA0_de(&((struct Shared_func_80286A78_S1 *)arg0)->address1B500, 0xC, 0x10);
        temp_v0_16 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4E0);
        if (temp_v0_16 > 0) {
            var_s0_2 = func_8025305C_de(temp_v0_16 * 0x50);
            
            var_s2 = 0;
            if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4E0) > 0) {
                do {
                    func_8020CA10_de(var_s0_2, var_s2);
                    func_80255D14_de(&((struct Shared_func_80286A78_S1 *)arg0)->address1B500, var_s0_2);
                    var_s0_2 = (void *)((char *)var_s0_2 + 0x50);
                } while ((((struct Shared_func_80286A78_S1 *)arg0)->unk1B4E0) > ++var_s2);
            }
        }
    }
    if (*(((struct Shared_func_80286A78_S1 *)(arg0))->unk60) >= 0xC) {
        temp_v0_17 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 0xB, temp_v0_5, arg0, &D_00285160, &D_800C51A0_de);
        (((struct Shared_func_80286A78_S1 *)(arg0))->unkFC) = temp_v0_17;
        temp_v0_18 = *temp_v0_17;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4EC) = temp_v0_18;
        (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B4F0) = (s32) temp_v0_18->unk4;
    }
    temp_v0_19 = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 6, temp_v0_5, arg0, &D_00285160, &D_800C51B4_de);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkCC) = temp_v0_19;
    temp_v1_6 = *temp_v0_19;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B300) = (void *) (&((struct Shared_func_80286A78_S12 *)temp_v1_6)->address8);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B304) = (s32) (((struct Shared_func_80286A78_S12 *)(temp_v1_6))->unk4);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk0) = 1;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk138) = 0;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk140) = 0;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unkD0) = func_80254408_de(0, (((struct Shared_func_80286A78_S1 *)(arg0))->unk60), 3, temp_v0_5, arg0, &D_0044C7B8, &D_800C51C0_de);
    func_80286950_de(arg0);
    
    var_a2 = 0;
    var_v1 = 0xF;
    
    var_a0_3 = (s32)(((struct Shared_func_80286A78_S1 *)(arg0))->unk138);
    var_v0 = &((struct Shared_func_80286A78_S1 *)arg0)->address3C;
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B6A4) = 0;
    do {
        (((struct Shared_func_80286A78_S13 *)(var_v0))->unk1B664) = 0;
        var_v1 -= 1;
        var_v0 -= 4;
    } while (var_v1 >= 0);
    
    var_v1 = 0;
    
    if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk140) > 0) {
        first_actor_kind = 0xE;
        var_a1 = (void *)(var_a2 * sizeof(void *) + (u32)arg0);
loop_81:
        if (*(((struct func_8024C654_S1 *)((void *)var_a0_3))->unk18) == first_actor_kind) {
            (((struct Shared_func_80286A78_S15 *)(var_a1))->unk1B664) = (void *)var_a0_3;
            var_a1 += 4;
            var_a2 += 1;
            var_v0_2 = var_a2 < 0x10;
        } else {
            var_v0_2 = var_a2 < 0x10;
        }
        if (var_v0_2 != 0) {
            var_a0_3 = (s32)NEXT_SCENE_ACTOR((void *)var_a0_3);
            var_v1 += 1;
            if (var_v1 < (((struct Shared_func_80286A78_S1 *)(arg0))->unk140)) {
                goto loop_81;
            }
        }
    }
    
    var_s1_3 = 3;
    scene_actor_ptr = (((struct Shared_func_80286A78_S1 *)(arg0))->unk138);
    actor_type3 = 3;
    actor_kind_bd7 = 0xBD7;
    var_v0_3 = 3 * sizeof(void *);
    
    
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk1B6A4) = var_a2;
    D_800F3CD0.primary.kindBd7 = 0;
    do {
        *(void **)((char *)D_800F3CD0.primary.actors + var_v0_3) = 0;
        var_s1_3 -= 1;
        var_v0_3 -= sizeof(void *);
    } while (var_s1_3 >= 0);
    var_s1_3 = 0;
    if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk140) > 0) {
        kind_actor = 0xA;
        kind_654 = 0x654;
        kind_653 = 0x653;
        kind_655 = 0x655;
        kind_656 = 0x656;
        var_s2_3 = &((struct Shared_func_80286A78_S16 *)scene_actor_ptr)->kind;
loop_89:
        temp_v1_7 = ((struct Shared_SceneActorPrefix *)var_s2_3)[-1].definition;
        temp_v0_20 = temp_v1_7->unk0;
        if (temp_v0_20 == actor_type3) {
            if (func_8028B25C_de(&D_8011FE88, temp_v1_7->unk28) != actor_kind_bd7) {
                goto block_108;
            }
            D_800F3CD0.primary.kindBd7 = scene_actor_ptr;
            goto block_109;
        } else {
            if (temp_v0_20 == kind_actor) {
                temp_v1_8 = var_s2_3->kind;
                if (temp_v1_8 == kind_654) {
                    goto actor_kind_654;
                }
                if (temp_v1_8 < 0x655) {
                    if (temp_v1_8 == kind_653) {
                        goto actor_kind_653;
                    }
                        goto block_108;
                }
                if (temp_v1_8 == kind_655) {
                    goto actor_kind_655;
                }
                if (temp_v1_8 == kind_656) {
                        goto actor_kind_656;
                }
                goto block_108;
actor_kind_653:
                D_800F3CD0.primary.actors[0] = scene_actor_ptr;
                goto block_108;
actor_kind_654:
                D_800F3CD0.primary.actors[1] = scene_actor_ptr;
                goto block_108;
actor_kind_655:
                D_800F3CD0.primary.actors[2] = scene_actor_ptr;
                goto block_108;
actor_kind_656:
                D_800F3CD0.primary.actors[3] = scene_actor_ptr;
            }
block_108:
            var_s2_3 = NEXT_SCENE_ACTOR(var_s2_3);
            scene_actor_ptr = NEXT_SCENE_ACTOR(scene_actor_ptr);
            var_s1_3 += 1;
            if (var_s1_3 >= (((struct Shared_func_80286A78_S1 *)(arg0))->unk140)) {
                goto block_109;
            }
            goto loop_89;
        }
    } else {
block_109:
        var_a3 = 0;
    }
    
    var_a0_3 = 9;
    var_a2_2 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk138);
    var_v0_4 = 9 * sizeof(void *);
    
    
    D_800F3CD0.kindBd6 = 0;
    do {
        *(void **)((char *)D_800F3CD0.kind64e + var_v0_4) = 0;
        var_a0_3 -= 1;
        var_v0_4 -= sizeof(void *);
    } while (var_a0_3 >= 0);
    var_a0_3 = 0;
    if ((((struct Shared_func_80286A78_S1 *)(arg0))->unk140) > 0) {
        second_type3 = 3;
        second_kind_bd6 = 0xBD6;
        second_type10 = 0xA;
        second_kind_64e = 0x64E;
        var_a1_2 = &((struct Shared_func_80286A78_S18 *)var_a2_2)->kind;
loop_114:
        temp_v1_9 = ((struct Shared_SceneActorPrefix *)var_a1_2)[-1].definition;
        temp_v0_21 = temp_v1_9->unk0;
        if (temp_v0_21 == second_type3) {
            if (temp_v1_9->unk28 == second_kind_bd6) {
                D_800F3CD0.kindBd6 = var_a2_2;
            }
        } else if (temp_v0_21 == second_type10) {
            if (var_a1_2->kind == second_kind_64e) {
                D_800F3CD0.kind64e[var_a3] = var_a2_2;
                var_a3 += 1;
            }
        }
        var_v0_5 = var_a3 < 0xA;
        if (var_v0_5 != 0) {
            var_a1_2 = NEXT_SCENE_ACTOR(var_a1_2);
            var_a2_2 = NEXT_SCENE_ACTOR(var_a2_2);
            var_a0_3 += 1;
            if (var_a0_3 >= (((struct Shared_func_80286A78_S1 *)(arg0))->unk140)) {
                goto block_122;
            }
            goto loop_114;
        }
    } else {
block_122:
        D_80142850 = func_802A01E8_de(var_a0_3) % 3;
    }
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk0) = 2;
    func_8044D5C4_de(arg0);
    temp_s4 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk140);
    var_s1_3 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk13C);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk0) = 3;
    if (var_s1_3 < temp_s4) {
        var_s0_4 = var_s1_3 * sizeof(struct Shared_SceneActorStride);
        do {
            var_s1_3 += 1;
            func_8024B2D0_de((((struct Shared_func_80286A78_S1 *)(arg0))->unk138) + var_s0_4);
            var_s0_4 += sizeof(struct Shared_SceneActorStride);
        } while (var_s1_3 < temp_s4);
    }
    var_s1_4 = D_80145060;
    if (var_s1_4 != 0) {
        
        temp_v0_2 = var_s1_4;
        do {
            func_8024B2D0_de(temp_v0_2);
            func_8024B2D0_de(NEXT_SCENE_ACTOR(temp_v0_2));
            (((struct func_80203E78_S1 *)(((struct Shared_func_80286A78_S20 *)(var_s1_4))->unk1454))->unk4) = func_8020CB3C_de(&((struct Shared_func_80286A78_S1 *)arg0)->unk1B4DC, &((struct Shared_func_80286A78_S20 *)var_s1_4)->address8);
            var_s1_4 = (((struct Shared_func_80286A78_S20 *)(var_s1_4))->unk16E0);
            if (var_s1_4 == 0) {
                break;
            }
            temp_v0_2 = var_s1_4;
        } while (1);
    }
    func_8044D668_de(arg0);
    temp_s4 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk140);
    var_s1_5 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk13C);
    if (var_s1_5 < temp_s4) {
        var_s2_4 = var_s1_5 * sizeof(struct Shared_SceneActorStride);
        do {
            var_s1_5 += 1;
            
            temp_v0_2 = (((struct Shared_func_80286A78_S1 *)(arg0))->unk138) + var_s2_4;
            func_8024BE3C_de(temp_v0_2);
            func_80246E44_de(temp_v0_2);
            var_s2_4 += sizeof(struct Shared_SceneActorStride);
        } while (var_s1_5 < temp_s4);
    }
    
    
    var_s0 = (char *)&((struct Shared_func_80286A78_S1 *)arg0)->unk1B4DC - (char *)arg0;
    temp_v0_2 = (char *)arg0 + var_s0;
    func_8020AA40_de(temp_v0_2);
    func_8020ABF0_de(temp_v0_2);
    (((struct Shared_func_80286A78_S1 *)(arg0))->unk0) = 4;
    func_80449E18_de(&D_80145040);
    temp_s0_3 = &D_80145040.address48;
    func_8044A6CC_de(temp_s0_3);
    func_80236874_de(temp_s0_3);
}

/* Native resident constant storage; absolute access symbols retain their addresses. */

