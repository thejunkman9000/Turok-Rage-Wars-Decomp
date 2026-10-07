#include "o04_types.h"
typedef struct { u8 pad0[0xF]; u8 unkF; u8 pad10[0x190 - 0x10]; } O04Row190r;
extern O04Row190r D_80102B00[];
extern char *D_800D7510;
extern char *D_800D7514;
extern char *D_800D7518;
extern char *D_800D751C;
extern char *D_800D7520;
extern char *D_800D7524;
extern char *D_800D7528;
extern char *D_800D752C;
extern char *D_800D7530;
extern char *D_800D7534;
extern char *D_800D7538;
extern char *D_800D753C;
extern char *D_800D7540;
extern char *D_800D7544;
extern char *D_800D7548;
extern char *D_800D754C;
extern char *D_800D7550;
extern char *D_800D7554;
extern char *D_800D7558;
extern char *D_800D755C;
extern char *D_800D7560;
extern char *D_800D7564;
extern char *D_800D7568;
extern char *D_800D756C;
extern char *D_800D7570;
extern char *D_800D7574;
extern char *D_800D7578;
extern char *D_800D757C;
extern char *D_800D7580;
extern char *D_800D7584;
extern char *D_800D7588;
extern char *D_800D758C;
extern char *D_800D7590;
extern char *D_800D7594;
extern char *D_800D7598;
extern char *D_800D759C;
extern char *D_800D75A0;
extern s32 func_0022F444(void *p, s32 a);
char *func_004255A8(s32 a) {
    O04Row190r *p = D_80102B00;
    char *r = 0;
    if (a < 0) {
        return r;
    }
    {
        switch (a) {
        case 5001:
            r = D_800D7510;
            break;
        case 5002:
            if (!(func_0022F444(p, p->unkF) & 1)) {
                r = D_800D7518;
            } else {
                r = D_800D7514;
            }
            break;
        case 5004:
            r = D_800D753C;
            break;
        case 5005:
            r = D_800D757C;
            break;
        case 5006:
            r = D_800D7590;
            break;
        case 5007:
            r = D_800D7548;
            break;
        case 5008:
            r = D_800D7554;
            break;
        case 5009:
            r = D_800D7538;
            break;
        case 5010:
            r = D_800D7550;
            break;
        case 5011:
            r = D_800D758C;
            break;
        case 5012:
            r = D_800D7580;
            break;
        case 5013:
            r = D_800D7594;
            break;
        case 5014:
            r = D_800D7570;
            break;
        case 5015:
            r = D_800D7540;
            break;
        case 5016:
            r = D_800D751C;
            break;
        case 5017:
            r = D_800D756C;
            break;
        case 5018:
            r = D_800D7568;
            break;
        case 5019:
            r = D_800D7578;
            break;
        case 5020:
            r = D_800D7564;
            break;
        case 5021:
            r = D_800D7544;
            break;
        case 5022:
            r = D_800D7574;
            break;
        case 5023:
            r = D_800D7524;
            break;
        case 5024:
            r = D_800D7520;
            break;
        case 5025:
            r = D_800D7598;
            break;
        case 5026:
            r = D_800D7558;
            break;
        case 5027:
            r = D_800D7588;
            break;
        case 5028:
            r = D_800D755C;
            break;
        case 5029:
            r = D_800D754C;
            break;
        case 5030:
            r = D_800D759C;
            break;
        case 5031:
            r = D_800D7534;
            break;
        case 5033:
            r = D_800D7584;
            break;
        case 5034:
            r = D_800D75A0;
            break;
        case 5037:
            r = D_800D7560;
            break;
        case 5057:
            r = D_800D7528;
            break;
        case 5052:
            r = D_800D752C;
            break;
        case 5053:
            r = D_800D7530;
            break;
        }
    }
    return r;
}
