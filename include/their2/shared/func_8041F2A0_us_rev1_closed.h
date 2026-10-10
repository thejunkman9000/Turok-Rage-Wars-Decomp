#ifndef FUNC_8041F2A0_US_REV1_CLOSED_H
#define FUNC_8041F2A0_US_REV1_CLOSED_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
/* Remaining func_8041F2A0_* types are unresolved canonical identities. */
/* Builds the four-player selection screen state, its preview models and sliding panels, then marks active players. */
struct func_8041F2A0_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};
typedef struct func_8041F2A0_Vec3 func_8041F2A0_Vec3;

struct func_8041F2A0_Item {
    char pad0[0x10];
    u8 alpha;
    char pad11[3];
    s16 x;
    s16 y;
    s16 w;
};
typedef struct func_8041F2A0_Item func_8041F2A0_Item;

struct func_8041F2A0_Player {
    func_8041F2A0_Item *highlight;
    s32 unk4;
    s32 kind;
    s32 unkC;
    s32 choice;
    char pad14[4];
    char model[0x4C0 - 0x18];
    s32 unk4C0;
    s32 pad4C4;
};
typedef struct func_8041F2A0_Player func_8041F2A0_Player;

struct SelectionScreenState {
    void *screen;
    s32 unk4;
    func_8041F2A0_Player players[4];
    func_8041F2A0_Item *header;
    s32 headerStep;
    func_8041F2A0_Item *footer;
    s32 footerStep;
    s32 phase;
    s32 timer;
    s32 prompt;
    func_8041F2A0_Item *promptItem;
    func_8041F2A0_Item *pulse;
    s32 pulseStep;
    s32 clock;
    s32 result;
};
typedef struct SelectionScreenState SelectionScreenState;

struct func_8041F2A0_Cell {
    u16 pad;
    u16 id;
};
typedef struct func_8041F2A0_Cell func_8041F2A0_Cell;

struct func_8041F2A0_Layout {
    s32 kind;
    u16 pad4[3];
    u16 title;
    func_8041F2A0_Cell cells[3];
    func_8041F2A0_Cell options[3];
};
typedef struct func_8041F2A0_Layout func_8041F2A0_Layout;

struct func_8041F2A0_Row {
    s32 pad;
    f32 scale[4];
    f32 distance[4];
    func_8041F2A0_Vec3 position[4];
    s32 light[4];
    char tail[12];
};
typedef struct func_8041F2A0_Row func_8041F2A0_Row;

struct func_8041F2A0_Config {
    char pad0[0x78];
    u8 active;
    char pad79[0x96 - 0x79];
};
typedef struct func_8041F2A0_Config func_8041F2A0_Config;









extern SelectionScreenState *D_800E42D0;
extern func_8041F2A0_Layout D_800E42D4[];


extern func_8041F2A0_Config D_80146398[];
extern SelectionScreenState *func_8025305C_de(s32);
extern s32 func_8041B610_de(s32, s32);
extern void func_8041B6E8_de(s32, s32, s32);
extern void func_8042E9A0_de(s32, s32);
extern s32 func_8041F18C_de(s32);
extern void func_8041CAD8_de(void *, s32, s32, s32, s32, Vec3, Vec3, f32, s32);
extern func_8041F2A0_Item *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(func_8041F2A0_Item *, s32);
extern s32 func_80419E54_de(s32, s32);
extern void func_80420308_de(s32);
extern void func_802A2394_de(void);

#endif
