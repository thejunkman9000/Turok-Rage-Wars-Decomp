#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Places the models of the first two active players on the screen D_800E4690: calls
   func_802A23C4_de(1) and func_802A2394_de, clears the word at 0xA58, and for each player whose 150-byte
   status record in D_80146398 has byte 0x78 equal to one maps its kind byte at 0x80 to a 0x70-byte
   row of D_800E3A58 through func_8041F140_de and shows object 0x38F plus the kind through
   func_8041CAD8_de in the next 0x4A8-byte view from 0x20 of the screen, using layout 0 of the row
   (uniform scale, position, float and word) for the first model and layout 2 for the second.
   Returns zero. */









extern struct Screen_func_80426788_de *D_800E4690;
extern struct Status D_80146398[];
extern struct Row_func_80426788_de D_800E3A58[];

extern void func_802A2394_de();

extern void func_8041CAD8_de(void *, s32, s32, s32, s32, Vec3, Vec3, f32, s32);

s32 func_80426788_de(void) {
    s32 shown;
    s32 layout;
    s32 view;
    s32 row;
    s32 i;
    Vec3 scale;
    struct Status *status;
    s32 offset;

    func_802A23C4_de(1);
    func_802A2394_de();
    shown = 0;
    layout = 0;
    i = 0;
    offset = 0;
    view = 0x20;
    D_800E4690->wordA58 = 0;
next:
    status = (struct Status *)((char *)D_80146398 + offset);
    if (status->active == 1) {
        shown++;
        row = func_8041F140_de(status->kind);
        scale.x = D_800E3A58[row].scale[layout];
        scale.y = D_800E3A58[row].scale[layout];
        scale.z = D_800E3A58[row].scale[layout];
        func_8041CAD8_de((char *)D_800E4690 + view, 9, status->kind + 0x38F, 0x4B, 0x5DC0, scale,
                      D_800E3A58[row].position[layout], D_800E3A58[row].distance[layout],
                      D_800E3A58[row].light[layout]);
        view += 0x4A8;
        layout = 2;
        if (shown >= layout) {
            goto done;
        }
    }
    i++;
    offset += 150;
    if (i < 4) {
        goto next;
    }
done:
    return 0;
}
