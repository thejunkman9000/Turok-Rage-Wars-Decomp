/* Resource manager thread setup and loop: fills a 0x200-byte stack with a marker, creates and starts the
 * thread object at D_80103720 (entry D_0023CA24, stack top D_800FFB50), then forever receives request
 * messages and dispatches on the request type to func_8023C1F0_de, func_8023CE9C_de, func_8023CCD4_de or
 * func_8023CDD4_de. */
#include "types.h"

typedef struct {
    s16 type;
} Request;

extern char D_800FF950[];
extern char D_800FF254[];
extern char D_0023CA24[];
extern void *func_802A001C_de(void *, s32, u32);
extern void func_802BAC90_de(void *, s32, void *, void *, void *, s32);
extern void func_802BB750_de(void *);
extern s32 func_802BB2A0_de(void *, Request **, s32);
extern void func_8023C1F0_de(Request *);
extern void func_8023CE9C_de(Request *);
extern void func_8023CCD4_de(Request *);
extern void func_8023CDD4_de(Request *);

void func_8023C924_de(void) {
    Request *request;

    func_802A001C_de(D_800FF950, 0x62, 0x200);
    func_802BAC90_de(D_800FF950 - 0x230, 0x62, D_0023CA24, 0, D_800FF950 + 0x200, 0x94);
    func_802BB750_de(D_800FF950 - 0x230);
    for (;;) {
        func_802BB2A0_de(D_800FF254, &request, 1);
        switch (request->type) {
        case 0:
            func_8023C1F0_de(request);
            break;
        case 1:
            func_8023CE9C_de(request);
            break;
        case 3:
            func_8023CDD4_de(request);
            break;
        case 2:
            func_8023CCD4_de(request);
            break;
        }
    }
}

