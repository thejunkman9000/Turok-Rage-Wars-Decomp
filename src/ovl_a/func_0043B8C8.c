#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Fills player p's column values on the screen D_800E59E0 from what the player owns: unless the
   entry's mode word (0x4D4) is 0, it scans the 4 rows of D_800E5BC4 for column 1, the 3 rows of
   D_800E5B14 for column 4 and the 8 rows of D_800E5B44 for column 5, and writes the index of each
   row whose item is marked owned at 0x4C of the player's 150-byte record in D_80146398 into the
   entry's next value slot (0x4B8 plus four per slot), starting at slot 0, 4 and 2, or at 0, 2 and
   1 in mode 1. */







extern struct Screen_func_8043B6E8_de *D_800E59E0;
extern u8 D_80146398[];
extern struct Shape_typemap_165 D_800E5BC4[];
extern struct Shape_typemap_165 D_800E5B14[];
extern struct Shape_typemap_165 D_800E5B44[];

void func_8043B6E8_de(s32 player) {
    struct Shape_typemap_165 *source;
    u8 *record;
    s32 column;
    s32 count;
    s32 slot;
    s32 i;

    if (D_800E59E0->entries[player].mode == 0) {
        return;
    }
    record = &D_80146398[player * 150];
    for (column = 0; column < 8; column++) {
        if (D_800E59E0->entries[player].mode == 1) {
            switch (column) {
            case 1:
                source = D_800E5BC4;
                count = 4;
                slot = 0;
                break;
            case 4:
                source = D_800E5B14;
                count = 3;
                slot = 2;
                break;
            case 5:
                source = D_800E5B44;
                count = 8;
                slot = 1;
                break;
            default:
                continue;
            }
        } else {
            switch (column) {
            case 1:
                source = D_800E5BC4;
                count = 4;
                slot = 0;
                break;
            case 4:
                source = D_800E5B14;
                count = 3;
                slot = 4;
                break;
            case 5:
                source = D_800E5B44;
                count = 8;
                slot = 2;
                break;
            default:
                continue;
            }
        }
        for (i = 0; i < count; i++) {
            if ((record + source[i].field_8)[0x4C] == 1) {
                D_800E59E0->entries[player].values[slot++] = i;
            }
        }
    }
}
