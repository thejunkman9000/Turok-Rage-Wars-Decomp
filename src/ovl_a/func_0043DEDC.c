#include "o05_types.h"

typedef struct { u8 pad[0x78]; u8 b78; u8 pad79[6]; u8 b7F; u8 pad80[0x96 - 0x80]; } Q4Pl;
typedef struct { u8 pad[0x20]; void *f20; } Q4A;
extern O05GameState D_801462C8[];
extern Q4Pl D_80146302[];
extern u8 D_8010F328[];
s32 func_0026439C(void *p);
void func_0025E3A4(void);

void func_0043DEDC(Q4A *a) {
    s32 i;
    u8 *p;
    for (i = 0; i < 8; i++) {
        D_801462C8->rec[i].b0 = 0;
    }
    for (i = 0; i < 4; i++) {
        p = &D_8010F328[i * 0x224];
        if (func_0026439C(p) != 0) {
            D_80146302->b78 = 1;
            D_80146302->b7F = i;
            a->f20 = p;
            break;
        }
    }
    func_0025E3A4();
}
