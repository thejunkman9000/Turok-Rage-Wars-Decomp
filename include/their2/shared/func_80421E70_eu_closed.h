#ifndef FUNC_80421E70_EU_CLOSED_H
#define FUNC_80421E70_EU_CLOSED_H
#include "types.h"
#include "span_16E000/code_80420E90.h"

/* After func_8029973C_de, opens screen D_800E4400 through func_8042177C_de while its word at 0x34 is
   zero; otherwise handles the menu message func_80299A08_de reports: 0x3AC closes the screen's first
   word through func_8041A430_de with 2 and calls func_804210E8_de, and 0x3B6 calls func_804213DC_de.
   Returns zero. */

extern struct Screen_func_80421884_de *D_800E4400;
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_8042177C_de(void);
extern void func_8041A430_de(s32, s32);
extern void func_804210E8_de(void);
extern void func_804213DC_de(void);


#endif
