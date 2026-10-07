/* port: state 0 update.  The game normally sits on the controller-pak screen until the player confirms; TUROK_SKIPMENU=1 starts play by
   running the "continue without pak" action (func_0041C1E4) after a short delay. */
#include "p4_types.h"
extern s32 D_8014ADA0;
void func_00293808(s32 a, s32 b);
void func_002647E4(void);
void func_0041C1E4(void);
int port_skip_menu(void);
void func_00293E60(s32 a) {
    static int wait;
    if (D_8014ADA0 == 0 && port_skip_menu() && ++wait == 200) func_0041C1E4();
    if (D_8014ADA0 != 0) {
        func_00293808(a, 1);
        func_002647E4();
    }
}
