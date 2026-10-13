#include "o04_types.h"
typedef struct { u8 pad0[0xF]; u8 unkF; u8 pad10[0x190 - 0x10]; } O04Row190r;
extern O04Row190r D_80102B00[];
extern u8 D_auto_80152789;
extern char *D_auto_800E1DE4[4];
extern char *D_auto_800E1DF4[4];
extern char *D_auto_800E1E04[4];
extern char *D_auto_800E1E14[4];
extern char *D_auto_800E1E24[4];
extern char *D_auto_800E1E34[4];
extern char *D_auto_800E1E44[4];
extern char *D_auto_800E1E54[4];
extern char *D_auto_800E1E64[4];
extern char *D_auto_800E1E74[4];
extern char *D_auto_800E1E84[4];
extern char *D_auto_800E1E94[4];
extern char *D_auto_800E1EA4[4];
extern char *D_auto_800E1EB4[4];
extern char *D_auto_800E1EC4[4];
extern char *D_auto_800E1ED4[4];
extern char *D_auto_800E1EE4[4];
extern char *D_auto_800E1EF4[4];
extern char *D_auto_800E1F04[4];
extern char *D_auto_800E1F14[4];
extern char *D_auto_800E1F24[4];
extern char *D_rel_800E1F34[4];
extern char *D_rel_800E1F44[4];
extern char *D_auto_800E1F54[4];
extern char *D_auto_800E1F64[4];
extern char *D_auto_800E1F74[4];
extern char *D_auto_800E1F84[4];
extern char *D_auto_800E1F94[4];
extern char *D_auto_800E1FA4[4];
extern char *D_rel_800E1FB4[4];
extern char *D_auto_800E1FC4[4];
extern char *D_auto_800E1FD4[4];
extern char *D_auto_800E1FE4[4];
extern char *D_auto_800E1FF4[4];
extern char *D_auto_800E2004[4];
extern char *D_auto_800E2014[4];
extern char *D_auto_800E2024[4];
extern s32 func_0022F444(void *p, s32 a);
char *func_auto_00425CBC(s32 a) {
    O04Row190r *p = D_80102B00;
    char *r = 0;
    if (a < 0) {
        return r;
    }
    {
        switch (a) {
        case 5001:
            r = D_auto_800E1DE4[D_auto_80152789];
            break;
        case 5002:
            if (!(func_0022F444(p, p->unkF) & 1)) {
                r = D_auto_800E1E04[D_auto_80152789];
            } else {
                r = D_auto_800E1DF4[D_auto_80152789];
            }
            break;
        case 5004:
            r = D_auto_800E1E94[D_auto_80152789];
            break;
        case 5005:
            r = D_auto_800E1F94[D_auto_80152789];
            break;
        case 5006:
            r = D_auto_800E1FE4[D_auto_80152789];
            break;
        case 5007:
            r = D_auto_800E1EC4[D_auto_80152789];
            break;
        case 5008:
            r = D_auto_800E1EF4[D_auto_80152789];
            break;
        case 5009:
            r = D_auto_800E1E84[D_auto_80152789];
            break;
        case 5010:
            r = D_auto_800E1EE4[D_auto_80152789];
            break;
        case 5011:
            r = D_auto_800E1FD4[D_auto_80152789];
            break;
        case 5012:
            r = D_auto_800E1FA4[D_auto_80152789];
            break;
        case 5013:
            r = D_auto_800E1FF4[D_auto_80152789];
            break;
        case 5014:
            r = D_auto_800E1F64[D_auto_80152789];
            break;
        case 5015:
            r = D_auto_800E1EA4[D_auto_80152789];
            break;
        case 5016:
            r = D_auto_800E1E14[D_auto_80152789];
            break;
        case 5017:
            r = D_auto_800E1F54[D_auto_80152789];
            break;
        case 5018:
            r = D_rel_800E1F44[D_auto_80152789];
            break;
        case 5019:
            r = D_auto_800E1F84[D_auto_80152789];
            break;
        case 5020:
            r = D_rel_800E1F34[D_auto_80152789];
            break;
        case 5021:
            r = D_auto_800E1EB4[D_auto_80152789];
            break;
        case 5022:
            r = D_auto_800E1F74[D_auto_80152789];
            break;
        case 5023:
            r = D_auto_800E1E34[D_auto_80152789];
            break;
        case 5024:
            r = D_auto_800E1E24[D_auto_80152789];
            break;
        case 5025:
            r = D_auto_800E2004[D_auto_80152789];
            break;
        case 5026:
            r = D_auto_800E1F04[D_auto_80152789];
            break;
        case 5027:
            r = D_auto_800E1FC4[D_auto_80152789];
            break;
        case 5028:
            r = D_auto_800E1F14[D_auto_80152789];
            break;
        case 5029:
            r = D_auto_800E1ED4[D_auto_80152789];
            break;
        case 5030:
            r = D_auto_800E2014[D_auto_80152789];
            break;
        case 5031:
            r = D_auto_800E1E74[D_auto_80152789];
            break;
        case 5033:
            r = D_rel_800E1FB4[D_auto_80152789];
            break;
        case 5034:
            r = D_auto_800E2024[D_auto_80152789];
            break;
        case 5037:
            r = D_auto_800E1F24[D_auto_80152789];
            break;
        case 5057:
            r = D_auto_800E1E44[D_auto_80152789];
            break;
        case 5052:
            r = D_auto_800E1E54[D_auto_80152789];
            break;
        case 5053:
            r = D_auto_800E1E64[D_auto_80152789];
            break;
        }
    }
    return r;
}
