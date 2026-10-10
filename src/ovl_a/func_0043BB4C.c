#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"
/* Clears the 22 owned bytes at 0x4C of each of the 4 player records (150 bytes apart) in
   D_80146398; for each active player (byte 0x78 == 1) it looks up the player's model kind (byte
   0x80) through func_8028CFA0_de and marks each of its 8 slot ids at least 0x4C3 as owned (byte 0x4C
   plus the id less 0x4C3), then refreshes the player's loadout columns through func_8043B6E8_de. */



extern s32 D_8011FE88;
extern u8 D_80146398[];
extern struct Model *func_8028CFA0_de(void *, s32, s32);
extern void func_8043B6E8_de(s32);

void func_8043B96C_de(void) {
    u8 *record;
    struct Model *model;
    s32 id;
    s32 i;
    s32 player;
    u8 *entry;

    for (player = 0; player < 4; player++) {
        record = &D_80146398[player * 150];
        i = 0x15;
        entry = record + 0x15;
        do {
            entry[0x4C] = 0;
            i -= 1;
            entry -= 1;
        } while (i >= 0);
        if (record[0x78] == 1) {
            model = func_8028CFA0_de(&D_8011FE88, 0xB, (s8) record[0x80]);
            for (i = 0; i < 8; i++) {
                id = model->slots[i];
                if (id >= 0x4C3) {
                    (record + (id - 0x4C3))[0x4C] = 1;
                }
            }
            func_8043B6E8_de(player);
        }
    }
}
