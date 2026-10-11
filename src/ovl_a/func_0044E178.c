/* their2 */
/* Port of func_8044D528_de.c of the other decompilation (CC0): func_0044E178 + func_0044E1D0 + func_0044E214, symbols renamed to US v1.1 names. */
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Sets the resource transition state and sound, while its adjacent helper refreshes the controller-option bit.
   (func_0044E1D0 passes its argument on to func_0044CA54 explicitly; the other decompilation calls
   func_0044CA54 with no argument and relies on $a0 still holding it, the code is identical.) */

extern int D_800D15D0;
extern void func_0025DF54(int),func_0044CA54(void *);
void func_0044E178(State_func_8044D528_de *state,int selection,int mode) {
 state->active=1;
 state->mode=mode;
 state->selection=selection;
 if(mode==2 && selection!=999)func_0025DF54(0x21C);
}
void func_0044E1D0(State_func_8044D528_de *state) {
 func_0044CA54(state);
 D_800D15D0=(state->input->value>>2)&1;
}

/* Processes both pending object lists between update barriers. */

void func_002458B4();                                  /* extern */
void func_002458C8();                                  /* extern */
void func_0028784C(void *, s32);                       /* extern */

void func_0044E214(State_func_8044D5C4_de *arg0) {
 s32 i,n;
 func_002458C8();
 n=arg0->unk11C0;
 for(i=0;i<n;i++) func_0028784C(arg0,arg0->unk11D0+i*20);
 n=arg0->unk11C4;
 for(i=0;i<n;i++) func_0028784C(arg0,arg0->unk11D4+i*20);
 func_002458B4();
}
