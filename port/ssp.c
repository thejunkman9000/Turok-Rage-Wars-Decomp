/* Diagnostic stack-smash detector (PORT_SSP=1 build, see port/ssp_ir.py): the IR of every guest function gets a canary word as its first stack object,
 * checked before each return; port_stack_smash(fn) is called when it was overwritten, i.e. when a callee wrote past a local of that function
 * (typically a pointer to a small local that the callee treats as a larger buffer - the MIPS frame had padding there).  Logs
 *     STACKSMASH fn=<rva of the function>
 * once per function in run.log (symbolize with port/where.py or port/crashsum.py) and carries on, so one run lists every offender. */
#include <windows.h>

extern HANDLE port_log_handle(void);          /* game_glue.c: OS handle of run.log (no CRT calls inside a fault path) */

void port_stack_smash(unsigned fn) {
    static unsigned long seen[512]; static int n; static char b[64];
    unsigned long site = (unsigned long)fn - (unsigned long)GetModuleHandleA(NULL);
    int i; DWORD w; HANDLE h; int l;
    for (i = 0; i < n; i++) if (seen[i] == site) return;
    if (n >= 512) return;
    seen[n++] = site;
    h = port_log_handle();
    l = wsprintfA(b, "STACKSMASH fn=%lX
", site);
    if (h != INVALID_HANDLE_VALUE) WriteFile(h, b, l, &w, NULL);
}
