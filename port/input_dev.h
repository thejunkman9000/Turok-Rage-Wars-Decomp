/* input_dev.h - the Windows device layer of the input system (shared by the game and the mapping tool).
 *
 *   keyboard + mouse: Raw Input on a private thread (physical scancodes, unaccelerated relative motion, every key transition is seen, no dependence on the
 *                     game's message loop, so the input is as fresh as the moment the game polls it)
 *   gamepads:         XInput (slots 0-3, vibration) + DirectInput 8 (every other HID game controller), both loaded dynamically from system DLLs;
 *                     hot-plug by a periodic scan on the input thread.  DirectInput devices are translated into the standard Xbox layout (PadState).
 * No library besides the system DLLs; no input libraries are linked. */
#ifndef INPUT_DEV_H
#define INPUT_DEV_H
#include "input_core.h"
#ifdef __cplusplus
extern "C" {
#endif

#define DEV_MAX_PADS 16        /* table entries: 0..3 = XInput slots, 4.. = DirectInput devices */

typedef struct DevPadInfo {
    int index;                 /* position in the table, stable while the program runs */
    int connected;
    int is_xinput, slot;       /* XInput slot 0..3 */
    int has_rumble;
    int std_known;             /* DirectInput: the standard layout translation comes from a table (otherwise a heuristic) */
    unsigned short vid, pid;
    char name[96];
    char guid[48];             /* DirectInput instance guid "{...}", empty for XInput */
} DevPadInfo;

/* starts the input thread (idempotent).  hwnd: the window whose focus gates the input (NULL = always live).  Returns 1 when running. */
int  inpdev_start(void *hwnd);
void inpdev_stop(void);
void inpdev_set_focus_window(void *hwnd);
void inpdev_set_background(int on);          /* read the devices while the window is not in front */
int  inpdev_active(void);                    /* the focus window is in front (or background input is on / no window set) */
/* 0 = no mouse input, 1 = buttons + wheel while the cursor is over the window, 2 = captured: motion too */
void inpdev_set_mouse_mode(int mode);
int  inpdev_get_mouse_mode(void);
void inpdev_suppress_mouse(void);               /* ignore the mouse buttons held right now until they are released */

/* one consistent sample of keyboard + mouse.  keys[256] indexed by (extended << 7) | scancode.  Mouse motion and wheel ticks are consumed (accumulated since the previous call).
 * Keys and buttons that were already held when the window got the focus are ignored until released.  Not active -> everything zero. */
void inpdev_read_kbm(unsigned char keys[256], unsigned *mouse_buttons, float *dx, float *dy, int wheel[4]);
int  inpdev_key_down_raw(int id);            /* physical state regardless of focus (hotkeys, the tool) */

unsigned inpdev_pad_generation(void);        /* increments whenever a pad connects or disconnects */
int  inpdev_pad_slots(void);                 /* table entries in use (connected or not) */
int  inpdev_pad_info(int i, DevPadInfo *out);
int  inpdev_pad_poll(int i, PadState *out);  /* reads the pad now; 0 when it is not connected */
void inpdev_rumble(int i, float low, float high);   /* XInput motors 0..1; DirectInput pads have none */
void inpdev_rescan(void);                    /* ask the thread to scan for devices now */

/* unit tests of the event / pad translation with synthetic data (no hardware); returns the number of failed checks */
int  inpdev_selftest(void);

/* log hook (the game routes it to stderr) */
typedef void (*InpDevLog)(const char *msg);
void inpdev_set_log(InpDevLog fn);

#ifdef __cplusplus
}
#endif
#endif
