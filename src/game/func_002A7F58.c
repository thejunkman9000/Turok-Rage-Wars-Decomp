/* their2: ported from the newer headers of the other decompilation (include/their2) */
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"
/* Clears a record: its four 0x38-byte entries through an inline per-entry clear, its two leading
   flag bytes and trailing words, and sets the word at 0xE6 to -5. */
static inline void clear_entry(Entry_func_802A6F68_de *e) {
    e->unk4 = 0;
    e->unk0 = 0;
    e->unkD = 0;
    e->unk18 = 0;
    e->unk1C = 0;
}
void func_802A6F68_de(Record_func_802A6F68_de *rec) {
    int i;
    for (i = 0; i < 4; i++) {
        clear_entry(&rec->entries[i]);
    }
    rec->unk0 = 0;
    rec->unk1 = 0;
    rec->unkE4 = 0;
    rec->unkE6 = -5;
    rec->unkE8 = 0;
}
/* Finds or allocates one of four records and updates its parameters. */
s32 func_802A6FB8_de(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 var_a1;
    u32 key;
    char *temp_v1;
    char *var_v1;
    char *var_v1_2;
    var_a1 = 0;
    key = arg2 & 0xFFFF;
    var_v1 = arg0;
loop_1:
    if ((((func_802A7FA8_S1 *)(var_v1))->unk4 == 0) || (((func_802A7FA8_S1 *)(var_v1))->unk10 != key)) {
        var_a1 += 1;
        var_v1 += 0x38;
        if (var_a1 >= 4) {
        } else {
            goto loop_1;
        }
    }
    if (var_a1 == 4) {
        var_a1 = 0;
        var_v1_2 = arg0;
loop_7:
        if (((func_80203E78_S1 *)(var_v1_2))->unk4 != 0) {
            var_a1 += 1;
            var_v1_2 += 0x38;
            if (var_a1 >= 4) {
            } else {
                goto loop_7;
            }
        }
        if (var_a1 == 4) {
            return 0;
        }
    }
    temp_v1 = arg0 + ((var_a1 * 0x38) + 4);
    ((func_802A7FA8_S3 *)(arg0))->unkE4 = var_a1;
    ((func_802A7FA8_S4 *)(temp_v1))->unk0 = 1;
    ((func_802A7FA8_S4 *)(temp_v1))->unk8 = arg1;
    ((func_802A7FA8_S4 *)(temp_v1))->unkC = arg2;
    ((func_802A7FA8_S4 *)(temp_v1))->unk10 = arg3;
    ((func_802A7FA8_S4 *)(temp_v1))->unk14 = arg4;
    ((func_802A7FA8_S4 *)(temp_v1))->unk28 = arg5;
    ((func_802A7FA8_S4 *)(temp_v1))->unk2C = arg6;
    ((func_802A7FA8_S4 *)(temp_v1))->unk30 = arg7;
    ((func_802A7FA8_S4 *)(temp_v1))->unkD = (u8) (((func_802A7FA8_S4 *)(temp_v1))->unkD + 1);
    ((func_802A7FA8_S4 *)(temp_v1))->unk34 = arg8;
    return 1;
}
s32 func_802A7098_de(void *arg0)
{
  s32 var_a1;
  s32 var_a2;
  s8 *new_var;
  var_a2 = 0;
  var_a1 = 3;
  do
  {
    new_var = ((s8 *) (arg0 + ((((struct Owner_func_8020388C_de *)(arg0))->id) * 0x38))) + 4;
    if ((*((s32 *) new_var)) != 0)
    {
      var_a2 += 1;
    }
    var_a1 -= 1;
  }
  while (var_a1 >= 0);
  return var_a2 != 0;
}
/* Moves a menu's cursor at 0xE4 over its four 0x38-byte entries, forward when arg1 is zero and backward otherwise, wrapping around and skipping entries whose word at 0x4 is zero; returns the entry landed on. */
s32 func_802A70D4_de(Menu_func_802A70D4_de *menu, s32 backward) {
    u16 cursor;
    if (backward == 0) {
        do {
            menu->cursor++;
            menu->cursor %= 4;
        } while (menu->entries[menu->cursor].active == 0);
        return menu->cursor;
    }
    do {
        cursor = --menu->cursor;
        if (cursor >= 4) {
            cursor = 3;
        }
        menu->cursor = cursor;
    } while (menu->entries[cursor].active == 0);
    return cursor;
}
void func_802A7168_de(void *arg0) {
    ((func_802A8158_S1 *)(arg0))->unk4 = 0;
    ((func_802A8158_S1 *)(arg0))->unk0 = 0;
    ((func_802A8158_S1 *)(arg0))->unkD = 0;
    ((func_802A8158_S1 *)(arg0))->unk18 = 0;
    ((func_802A8158_S1 *)(arg0))->unk1C = 0;
}
void func_802A7180_de(void *arg0, void *arg1) {
    s32 temp_v0;
    temp_v0 = (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_4) == 0;
    (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_4) = temp_v0;
    if (temp_v0 != 0) {
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_18) = 5;
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_1C) = (s32) (((struct State_func_8042D8C4_de *) ((s8 *) arg1))->count);
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_20) = (f32) (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_28);
        (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_24) = (s32) (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_2C);
        return;
    }
    (((struct ObjectState30_2 *) ((s8 *) arg0))->unk_18) = -5;
}
/* Soft-resets the game: checks the "systembootdone" marker (copied from D_800C5F10_de and zero-padded with the memset func_802A001C_de) through func_80293440_de (recording the result in D_801470B0 and re-arming it through func_802934C0_de), and on a cold boot copies the resident code and data back from the cartridge word by word after each PI idle wait, then clears the BSS from D_800E4000 to D_80166000, in both passes skipping the marker, its flag and, when not cold booting, the preserved save, settings and pad regions; finally reinitialises through func_802BAE40_de and func_80292F24_de. */
extern Marker_func_802A71C0_de D_800C5F10_de;
extern void func_802A001C_de(char *dst, s32 value, s32 size);
extern char D_800CDD10;
extern s32 D_801470B0;
extern char D_8010BC40;
extern char D_801462C8;
extern char D_800F91F0;
extern char D_800F41F0;
extern s32 D_800E4000;
extern s32 D_80166000;

extern void func_802934C0_de(char *marker, char *name);
static inline s32 is_restorable(u32 address) {
    if (address >= (u32)&D_800CDD10 && address < (u32)&D_800CDD10 + 0x10) {
        return 0;
    }
    if (address == (u32)&D_801470B0) {
        return 0;
    }
    if (D_801470B0 != 0) {
        return 1;
    }
    if (address >= (u32)&D_8010BC40 && address < (u32)&D_8010BC40 + 0x430) {
        return 0;
    }
    if (address >= (u32)&D_801462C8 && address < (u32)&D_801462C8 + 0x584) {
        return 0;
    }
    if (address >= (u32)&D_800F91F0 && address < (u32)&D_800F91F0 + 0x5800) {
        return 0;
    }
    if (address >= (u32)&D_800F41F0 && address < (u32)&D_800F41F0 + 0x5000) {
        return 0;
    }
    if (address >= (u32)&D_801462C8 + 0x5D8 && address <= (u32)&D_801462C8 + 0x688) {
        return 0;
    }
    return 1;
}
s32 func_802A71C0_de(void) {
    u32 *src;
    u32 *dst;
    s32 count;
    u32 status;
    u32 *piStatus;
    char name[16];
    *(Marker_func_802A71C0_de *)name = D_800C5F10_de;
    func_802A001C_de(&name[15], 0, 1);
    if (((s32 (*)(char *, char *))func_80293440_de)(&D_800CDD10, name) == 0) {
        D_801470B0 = 0;
    } else {
        D_801470B0 = 1;
        func_802934C0_de(&D_800CDD10, name);
    }
    if (D_801470B0 == 0) {
        src = (u32 *)0xB0001000;
        dst = (u32 *)0x80000400;
        piStatus = (u32 *)0xA4600010;
        count = 0x3FFFF;
        do {
            status = *piStatus & 3;
            while (status != 0) {
            }
            if (is_restorable((u32)dst | 0x80000000)) {
                *dst = *src;
            }
            dst++;
            src++;
        } while (count-- != 0);
    }
    for (dst = (u32 *)&D_800E4000; (u32)dst < (u32)&D_80166000; dst++) {
        if (is_restorable((u32)dst | 0x80000000)) {
            *dst = 0;
        }
    }
    func_802BAE40_de();
    func_80292F24_de();
    return 0;
}
void func_802A754C_de(void) {
}
/* Returns whether an address may be modified: never inside the 16-byte block D_800CDD10 or at the guard word D_801470B0, always when that guard word is set, and otherwise only outside the protected blocks D_8010BC40, D_801462C8, D_800F91F0, D_800F41F0 and D_801468A0; func_802A7654_de that follows is an empty function. */
extern char D_800CDD10;
extern s32 D_801470B0;
extern char D_8010BC40;
extern char D_801462C8;
extern char D_800F91F0;
extern char D_800F41F0;
extern char D_801468A0;
s32 func_802A7554_de(u32 address) {
    address |= 0x80000000;
    if (((address) >= (u32)&(D_800CDD10) && (address) < (u32)&(D_800CDD10) + (0x10)) || address == (u32)&D_801470B0) {
        return 0;
    }
    if (D_801470B0 != 0) {
        return 1;
    }
    if (((address) >= (u32)&(D_8010BC40) && (address) < (u32)&(D_8010BC40) + (0x430))) {
        return 0;
    }
    if (((address) >= (u32)&(D_801462C8) && (address) < (u32)&(D_801462C8) + (0x584))) {
        return 0;
    }
    if (((address) >= (u32)&(D_800F91F0) && (address) < (u32)&(D_800F91F0) + (0x5800))) {
        return 0;
    }
    if (((address) >= (u32)&(D_800F41F0) && (address) < (u32)&(D_800F41F0) + (0x5000))) {
        return 0;
    }
    if (address >= (u32)&D_801468A0 && address <= (u32)&D_801468A0 + 0xB0) {
        return 0;
    }
    return 1;
}
void func_802A7654_de(void) {
}
