/* input_dev.c - Windows device layer: Raw Input keyboard + mouse, XInput and DirectInput gamepads, hot-plug scan, rumble.  See input_dev.h.
 * Everything Win32 here uses the explicit ANSI entry points so the file builds the same in the game (no UNICODE) and in the tool (UNICODE). */
#define WIN32_LEAN_AND_MEAN
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>
#include <intrin.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dinput.h>
#include "input_dev.h"

#ifndef DIDFT_OPTIONAL
#define DIDFT_OPTIONAL 0x80000000
#endif

/* ------------------------------------------------------------------ logging */
static InpDevLog g_log;
void inpdev_set_log(InpDevLog fn) { g_log = fn; }
static void logf_(const char *fmt, ...) {
    char m[300]; va_list ap;
    if (!g_log) return;
    va_start(ap, fmt); vsnprintf(m, sizeof m, fmt, ap); va_end(ap);
    g_log(m);
}

/* ------------------------------------------------------------------ keyboard / mouse state (written by the input thread) */
static HWND g_focus_hwnd;
static volatile LONG g_background;
static volatile LONG g_mouse_mode;
static volatile unsigned char g_key[256], g_key_supp[256];
static volatile LONG g_mx, g_my, g_whl[4], g_mb, g_mb_supp, g_mb_latch;
static volatile unsigned char g_key_latch[256];                /* pressed since the previous read: a tap shorter than the game's poll interval is still seen once */
static volatile LONG g_act_prev;
static int g_abs_valid; static LONG g_abs_x, g_abs_y;

static HANDLE g_thread, g_ready; static HWND g_sink;
static CRITICAL_SECTION g_lock; static volatile LONG g_lock_ready;
static volatile LONG g_stop, g_rescan;

void inpdev_set_focus_window(void *hwnd) { g_focus_hwnd = (HWND)hwnd; }
void inpdev_set_background(int on) { g_background = on ? 1 : 0; }
int inpdev_active(void) {
    if (g_background || !g_focus_hwnd) return 1;
    return GetForegroundWindow() == g_focus_hwnd;
}
void inpdev_set_mouse_mode(int mode) {
    if (mode == 2 && g_mouse_mode != 2) { _InterlockedExchange(&g_mx, 0); _InterlockedExchange(&g_my, 0); }
    _InterlockedExchange(&g_mouse_mode, mode);
}
int inpdev_get_mouse_mode(void) { return (int)g_mouse_mode; }
void inpdev_suppress_mouse(void) { _InterlockedOr(&g_mb_supp, g_mb); }                       /* the click that just captured the mouse is not game input */
int inpdev_key_down_raw(int id) { return id >= 0 && id < 256 && g_key[id] ? 1 : 0; }

static int cursor_over_client(void) {
    POINT pt; RECT r; HWND w = g_focus_hwnd;
    if (!w) return 1;
    if (!GetCursorPos(&pt)) return 0;
    if (WindowFromPoint(pt) != w) return 0;
    ScreenToClient(w, &pt); GetClientRect(w, &r);
    return PtInRect(&r, pt);
}

/* The window got the focus: whatever is held right now must be released before it counts (a key held while alt-tabbing in).  Detected on the input thread at
 * every raw event and by a 25 ms timer, so a key pressed right after the focus change is not mistaken for one that was already held. */
static void focus_tick(void) {
    int a = inpdev_active(), k;
    if (a && !g_act_prev) {
        for (k = 0; k < 256; k++) { g_key_supp[k] = g_key[k]; g_key_latch[k] = 0; }
        g_mb_supp = g_mb; g_mb_latch = 0; _InterlockedExchange(&g_mx, 0); _InterlockedExchange(&g_my, 0); for (k = 0; k < 4; k++) _InterlockedExchange(&g_whl[k], 0);
    }
    g_act_prev = a;
}
static void on_key(const RAWKEYBOARD *k) {
    focus_tick();
    unsigned sc = k->MakeCode & 0x7F, ext = (k->Flags & RI_KEY_E0) ? 1u : 0u; int down = !(k->Flags & RI_KEY_BREAK), id;
    if (k->VKey == 0xFF || (k->Flags & RI_KEY_E1)) return;                 /* overrun / Pause */
    if (k->MakeCode == 0) {                                                 /* injected input without a scancode: derive it from the virtual key */
        UINT r = MapVirtualKeyA(k->VKey, MAPVK_VK_TO_VSC_EX);
        if (!r) return;
        sc = r & 0x7F; ext = ((r >> 8) == 0xE0) ? 1u : 0u;
    }
    if (ext && (sc == 0x2A || sc == 0x36)) return;                          /* the "fake shift" that accompanies numpad navigation keys */
    if (sc == 0x45) ext = 0;                                                /* NumLock arrives with or without E0 depending on the driver */
    id = (int)((ext << 7) | sc);
    if (down && id == 0x1C && (g_key[0x1D] || g_key[0x9D] || g_key[0x38] || g_key[0xB8])) {      /* Ctrl+Enter / Alt+Enter toggles full screen (win32_main.cpp): that Enter is not game input */
        g_key[id] = 1; g_key_supp[id] = 1;
        return;
    }
    g_key[id] = (unsigned char)(down ? 1 : 0);
    if (down && inpdev_active()) g_key_latch[id] = 1;
    if (!down) g_key_supp[id] = 0;
}
static void mouse_button(int idx, int down) {
    LONG bit = 1L << idx;
    if (down) {
        _InterlockedOr(&g_mb, bit);
        if (!inpdev_active() || (g_mouse_mode == 1 && !cursor_over_client())) _InterlockedOr(&g_mb_supp, bit);   /* a click that only activates the window or lands elsewhere is not game input */
        else _InterlockedOr(&g_mb_latch, bit);
    } else { _InterlockedAnd(&g_mb, ~bit); _InterlockedAnd(&g_mb_supp, ~bit); }
}
static void on_mouse(const RAWMOUSE *m) {
    USHORT bf = m->usButtonFlags;
    focus_tick();
    static const struct { USHORT down, up; } bt[5] = { { 0x0001, 0x0002 }, { 0x0004, 0x0008 }, { 0x0010, 0x0020 }, { 0x0040, 0x0080 }, { 0x0100, 0x0200 } };
    int i;
    for (i = 0; i < 5; i++) { if (bf & bt[i].down) mouse_button(i, 1); if (bf & bt[i].up) mouse_button(i, 0); }
    if ((bf & 0x0C00) && g_mouse_mode >= 1 && inpdev_active() && (g_mouse_mode == 2 || cursor_over_client())) {
        SHORT d = (SHORT)m->usButtonData;                                    /* in 1/120 ticks */
        if (bf & 0x0400) { if (d > 0) _InterlockedExchangeAdd(&g_whl[0], d); else _InterlockedExchangeAdd(&g_whl[1], -d); }      /* RI_MOUSE_WHEEL: up / down */
        if (bf & 0x0800) { if (d > 0) _InterlockedExchangeAdd(&g_whl[3], d); else _InterlockedExchangeAdd(&g_whl[2], -d); }      /* RI_MOUSE_HWHEEL: right / left */
    }
    if (g_mouse_mode == 2) {
        if (m->usFlags & MOUSE_MOVE_ABSOLUTE) {                              /* remote desktop / virtual machines report absolute positions: use the differences */
            if (g_abs_valid) { _InterlockedExchangeAdd(&g_mx, (m->lLastX - g_abs_x) * GetSystemMetrics(SM_CXSCREEN) / 65535); _InterlockedExchangeAdd(&g_my, (m->lLastY - g_abs_y) * GetSystemMetrics(SM_CYSCREEN) / 65535); }
            g_abs_x = m->lLastX; g_abs_y = m->lLastY; g_abs_valid = 1;
        } else if (m->lLastX || m->lLastY) { _InterlockedExchangeAdd(&g_mx, m->lLastX); _InterlockedExchangeAdd(&g_my, m->lLastY); }
    } else g_abs_valid = 0;
}

void inpdev_read_kbm(unsigned char keys[256], unsigned *mouse_buttons, float *dx, float *dy, int wheel[4]) {
    int active = inpdev_active(), k, d; LONG mode = g_mouse_mode;
    static LONG rem[4];
    memset(keys, 0, 256); *mouse_buttons = 0; *dx = *dy = 0; for (d = 0; d < 4; d++) wheel[d] = 0;
    if (!active) { _InterlockedExchange(&g_mx, 0); _InterlockedExchange(&g_my, 0); _InterlockedExchange(&g_mb_latch, 0); for (d = 0; d < 4; d++) _InterlockedExchange(&g_whl[d], 0); for (k = 0; k < 256; k++) g_key_latch[k] = 0; return; }
    for (k = 0; k < 256; k++) { keys[k] = (unsigned char)(((g_key[k] || g_key_latch[k]) && !g_key_supp[k]) ? 1 : 0); g_key_latch[k] = 0; }
    if (mode >= 1) *mouse_buttons = (unsigned)((g_mb & ~g_mb_supp) | _InterlockedExchange(&g_mb_latch, 0)) & 31u; else _InterlockedExchange(&g_mb_latch, 0);
    if (mode == 2) { *dx = (float)_InterlockedExchange(&g_mx, 0); *dy = (float)_InterlockedExchange(&g_my, 0); }
    else { _InterlockedExchange(&g_mx, 0); _InterlockedExchange(&g_my, 0); }
    for (d = 0; d < 4; d++) {
        LONG acc = _InterlockedExchange(&g_whl[d], 0) + rem[d];
        if (mode >= 1) { wheel[d] = acc / 120; rem[d] = acc % 120; } else rem[d] = 0;
    }
}

/* ------------------------------------------------------------------ gamepads */
typedef struct { WORD wButtons; BYTE bLeftTrigger, bRightTrigger; SHORT sThumbLX, sThumbLY, sThumbRX, sThumbRY; } XI_GAMEPAD;
typedef struct { DWORD dwPacketNumber; XI_GAMEPAD Gamepad; } XI_STATE;
typedef struct { WORD wLeftMotorSpeed, wRightMotorSpeed; } XI_VIB;
typedef struct { BYTE Type, SubType; WORD Flags; XI_GAMEPAD Gamepad; XI_VIB Vibration; } XI_CAPS;
static DWORD (WINAPI *pXGetState)(DWORD, XI_STATE *);
static DWORD (WINAPI *pXSetState)(DWORD, XI_VIB *);
static DWORD (WINAPI *pXGetCaps)(DWORD, DWORD, XI_CAPS *);
static int g_xi_tried;
/* TUROK_FAKEPADS=1: virtual XInput pads for tests without hardware.  Slot k (0..3) is connected while the file port_fakepad<k+1>.txt exists; its content is
 * "buttons lx ly rx ry lt rt" = XINPUT_GAMEPAD wButtons (hex), thumbs -32768..32767, triggers 0..255.  Rumble commands are logged instead of sent. */
static int g_fake = -1;
static int fake_on(void) { if (g_fake < 0) { char e[8]; g_fake = GetEnvironmentVariableA("TUROK_FAKEPADS", e, sizeof e) ? 1 : 0; } return g_fake; }
static DWORD fake_get_state(DWORD slot, void *vst);

typedef struct MyJoyState { LONG axis[8]; DWORD pov[4]; BYTE btn[128]; } MyJoyState;
typedef struct DiMap { unsigned short vid, pid; const char *name; signed char btn[PB_COUNT]; signed char ax[PA_COUNT]; signed char tbtn[2]; int trig_signed; } DiMap;
/* DirectInput object order is X Y Z Rx Ry Rz slider0 slider1 = raw axes 0..7.  Standard slots: button index per PB_*, axis index per PA_* (-1 = none). */
static const DiMap g_dimap_ps = { 0, 0, "PlayStation 4/5 layout",
    { 1, 2, 0, 3, 4, 5, 8, 9, 10, 11, -1, -1, -1, -1, 12 }, { 0, 1, 2, 5, 3, 4 }, { 6, 7 }, 1 };                  /* Cross Circle Square Triangle L1 R1 Share Options L3 R3 PS; sticks X Y / Z Rz, triggers Rx Ry */
static const DiMap g_dimap_logi = { 0, 0, "Logitech F310/F710 (D mode) layout",
    { 1, 2, 0, 3, 4, 5, 8, 9, 10, 11, -1, -1, -1, -1, -1 }, { 0, 1, 2, 5, -1, -1 }, { 6, 7 }, 0 };               /* A B X Y LB RB Back Start LS RS; sticks X Y / Z Rz; LT RT are buttons 7 8 */
static const DiMap g_dimap_default = { 0, 0, "generic Xbox-order layout",
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1 }, { 0, 1, -2, -2, -1, -1 }, { -1, -1 }, 0 };              /* right stick: Rx Ry when present, else Z Rz (-2 = decided from the axes the device has) */
static const struct { unsigned short vid, pid; const DiMap *map; } g_dimaps[] = {
    { 0x054C, 0x05C4, &g_dimap_ps }, { 0x054C, 0x09CC, &g_dimap_ps }, { 0x054C, 0x0CE6, &g_dimap_ps }, { 0x054C, 0x0DF2, &g_dimap_ps }, { 0x054C, 0x05C5, &g_dimap_ps },
    { 0x046D, 0xC216, &g_dimap_logi }, { 0x046D, 0xC219, &g_dimap_logi }, { 0x046D, 0xC218, &g_dimap_logi }, { 0x046D, 0xC21A, &g_dimap_logi }
};

typedef struct PadEntry {
    DevPadInfo info; int used, seen;
    IDirectInputDevice8A *dev; GUID inst; int std_axes_decided;
    unsigned char axis_present[8]; LONG amin[8], amax[8]; int nbuttons; const DiMap *map; DiMap dynmap;
    WORD last_l, last_r;
} PadEntry;
static PadEntry g_pad[DEV_MAX_PADS];
static int g_pad_slots = 4;
static volatile LONG g_pad_gen = 1;
static IDirectInput8A *g_di; static HMODULE g_dinput_dll;
static HRESULT (WINAPI *pDirectInput8Create)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN);

static const GUID k_IID_IDirectInput8A = { 0xBF798030, 0x483A, 0x4DA2, { 0xAA, 0x99, 0x5D, 0x64, 0xED, 0x36, 0x97, 0x00 } };
static const GUID k_GUID_XAxis  = { 0xA36D02E0, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_YAxis  = { 0xA36D02E1, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_ZAxis  = { 0xA36D02E2, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_RxAxis = { 0xA36D02F4, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_RyAxis = { 0xA36D02F5, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_RzAxis = { 0xA36D02E3, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_Slider = { 0xA36D02E4, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static const GUID k_GUID_POV    = { 0xA36D02F2, 0xC9F3, 0x11CF, { 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } };
static DIOBJECTDATAFORMAT g_odf[8 + 4 + 128]; static DIDATAFORMAT g_joyfmt; static int g_fmt_ready;

static void build_format(void) {
    int i, n = 0;
    const GUID *ag[8];
    if (g_fmt_ready) return;
    ag[0] = &k_GUID_XAxis; ag[1] = &k_GUID_YAxis; ag[2] = &k_GUID_ZAxis; ag[3] = &k_GUID_RxAxis; ag[4] = &k_GUID_RyAxis; ag[5] = &k_GUID_RzAxis; ag[6] = &k_GUID_Slider; ag[7] = &k_GUID_Slider;
    for (i = 0; i < 8; i++, n++) { g_odf[n].pguid = ag[i]; g_odf[n].dwOfs = (DWORD)(i * 4); g_odf[n].dwType = DIDFT_OPTIONAL | DIDFT_AXIS | DIDFT_ANYINSTANCE; g_odf[n].dwFlags = 0; }
    for (i = 0; i < 4; i++, n++) { g_odf[n].pguid = &k_GUID_POV; g_odf[n].dwOfs = (DWORD)(32 + i * 4); g_odf[n].dwType = DIDFT_OPTIONAL | DIDFT_POV | DIDFT_ANYINSTANCE; g_odf[n].dwFlags = 0; }
    for (i = 0; i < 128; i++, n++) { g_odf[n].pguid = NULL; g_odf[n].dwOfs = (DWORD)(48 + i); g_odf[n].dwType = DIDFT_OPTIONAL | DIDFT_BUTTON | DIDFT_ANYINSTANCE; g_odf[n].dwFlags = 0; }
    g_joyfmt.dwSize = sizeof g_joyfmt; g_joyfmt.dwObjSize = sizeof g_odf[0]; g_joyfmt.dwFlags = DIDF_ABSAXIS; g_joyfmt.dwDataSize = sizeof(MyJoyState); g_joyfmt.dwNumObjs = (DWORD)n; g_joyfmt.rgodf = g_odf;
    g_fmt_ready = 1;
}

/* ---- XInput ---- */
static void xi_load(void) {
    HMODULE m;
    if (g_xi_tried) return;
    g_xi_tried = 1;
    m = LoadLibraryA("xinput1_4.dll"); if (!m) m = LoadLibraryA("xinput1_3.dll"); if (!m) m = LoadLibraryA("xinput9_1_0.dll");
    if (!m) { logf_("input: no XInput DLL found, Xbox pads unavailable"); return; }
    pXGetState = (DWORD (WINAPI *)(DWORD, XI_STATE *))GetProcAddress(m, "XInputGetState");
    pXSetState = (DWORD (WINAPI *)(DWORD, XI_VIB *))GetProcAddress(m, "XInputSetState");
    pXGetCaps = (DWORD (WINAPI *)(DWORD, DWORD, XI_CAPS *))GetProcAddress(m, "XInputGetCapabilities");
}
static DWORD xi_get_state(DWORD slot, XI_STATE *st) {
    if (fake_on()) return fake_get_state(slot, st);
    return pXGetState ? pXGetState(slot, st) : 1167;
}
static DWORD fake_get_state(DWORD slot, void *vst) {
    XI_STATE *st = (XI_STATE *)vst; char fn[48]; FILE *f; unsigned w = 0; int v[6] = { 0, 0, 0, 0, 0, 0 };
    snprintf(fn, sizeof fn, "port_fakepad%lu.txt", (unsigned long)slot + 1);
    static XI_STATE last[4]; static DWORD seen[4];                              /* a file that is being rewritten may fail to open for a moment: keep the last state for 400 ms */
    f = fopen(fn, "r");
    if (!f) { if (slot < 4 && seen[slot] && GetTickCount() - seen[slot] < 400) { *st = last[slot]; return 0; } return 1167; }          /* ERROR_DEVICE_NOT_CONNECTED */
    if (fscanf(f, "%x %d %d %d %d %d %d", &w, &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]) < 1) { fclose(f); if (slot < 4 && seen[slot]) { *st = last[slot]; return 0; } w = 0; f = NULL; }
    if (f) fclose(f);
    memset(st, 0, sizeof *st); st->Gamepad.wButtons = (WORD)w; st->Gamepad.sThumbLX = (SHORT)v[0]; st->Gamepad.sThumbLY = (SHORT)v[1]; st->Gamepad.sThumbRX = (SHORT)v[2]; st->Gamepad.sThumbRY = (SHORT)v[3];
    st->Gamepad.bLeftTrigger = (BYTE)v[4]; st->Gamepad.bRightTrigger = (BYTE)v[5];
    if (slot < 4) { last[slot] = *st; seen[slot] = GetTickCount(); }
    return 0;
}
static float norm16(SHORT v) { float f = (float)v / 32767.0f; return f < -1.0f ? -1.0f : f > 1.0f ? 1.0f : f; }
static void xi_fill(const XI_STATE *s, PadState *o) {
    unsigned w = s->Gamepad.wButtons, b = 0;
    memset(o, 0, sizeof *o); memset(o->hat, -1, sizeof o->hat); o->connected = 1;
    if (w & 0x1000) b |= 1u << PB_A; if (w & 0x2000) b |= 1u << PB_B; if (w & 0x4000) b |= 1u << PB_X; if (w & 0x8000) b |= 1u << PB_Y;
    if (w & 0x0100) b |= 1u << PB_LB; if (w & 0x0200) b |= 1u << PB_RB; if (w & 0x0020) b |= 1u << PB_BACK; if (w & 0x0010) b |= 1u << PB_START;
    if (w & 0x0040) b |= 1u << PB_LS; if (w & 0x0080) b |= 1u << PB_RS;
    if (w & 0x0001) b |= 1u << PB_DUP; if (w & 0x0002) b |= 1u << PB_DDOWN; if (w & 0x0004) b |= 1u << PB_DLEFT; if (w & 0x0008) b |= 1u << PB_DRIGHT;
    o->buttons = b;
    o->axis[PA_LX] = norm16(s->Gamepad.sThumbLX); o->axis[PA_LY] = norm16(s->Gamepad.sThumbLY);
    o->axis[PA_RX] = norm16(s->Gamepad.sThumbRX); o->axis[PA_RY] = norm16(s->Gamepad.sThumbRY);
    o->axis[PA_LT] = (float)s->Gamepad.bLeftTrigger / 255.0f; o->axis[PA_RT] = (float)s->Gamepad.bRightTrigger / 255.0f;
}
static void xi_scan(void) {
    int slot;
    xi_load();
    if (!pXGetState && !fake_on()) return;
    for (slot = 0; slot < 4; slot++) {
        XI_STATE st; int conn = xi_get_state((DWORD)slot, &st) == ERROR_SUCCESS; PadEntry *e = &g_pad[slot];
        EnterCriticalSection(&g_lock);
        if (conn != e->info.connected) {
            XI_CAPS caps;
            e->info.index = slot; e->info.is_xinput = 1; e->info.slot = slot; e->used = 1; e->info.connected = conn;
            snprintf(e->info.name, sizeof e->info.name, "Xbox / XInput controller %d", slot + 1);
            e->info.has_rumble = 1;
            if (conn && !fake_on() && pXGetCaps && pXGetCaps((DWORD)slot, 0, &caps) == ERROR_SUCCESS) e->info.has_rumble = (caps.Flags & 0x0001) ? 1 : 0;
            _InterlockedIncrement(&g_pad_gen);
            logf_("input: XInput controller %d %s", slot + 1, conn ? "connected" : "disconnected");
        }
        LeaveCriticalSection(&g_lock);
    }
}

/* ---- DirectInput ---- */
static const char *stristr_(const char *h, const char *n) {
    size_t l = strlen(n), i;
    for (; *h; h++) { for (i = 0; i < l; i++) { char a = h[i], b = n[i]; if (!a) return NULL; if (a >= 'A' && a <= 'Z') a += 32; if (b >= 'A' && b <= 'Z') b += 32; if (a != b) break; } if (i == l) return h; }
    return NULL;
}
static int is_xinput_device(const GUID *prod, const char *name) {          /* the documented IG_ test: XInput devices are also listed by DirectInput */
    UINT n = 0, i; RAWINPUTDEVICELIST *list; int found = 0;
    if (name && (stristr_(name, "xbox") || stristr_(name, "xinput"))) return 1;
    if (GetRawInputDeviceList(NULL, &n, sizeof *list) != 0 || !n) return 0;
    list = (RAWINPUTDEVICELIST *)malloc(n * sizeof *list);
    if (!list) return 0;
    if (GetRawInputDeviceList(list, &n, sizeof *list) == (UINT)-1) { free(list); return 0; }
    for (i = 0; i < n && !found; i++) {
        RID_DEVICE_INFO info; UINT sz = sizeof info, nsz = 0; char *dn;
        if (list[i].dwType != RIM_TYPEHID) continue;
        info.cbSize = sizeof info;
        if (GetRawInputDeviceInfoA(list[i].hDevice, RIDI_DEVICEINFO, &info, &sz) == (UINT)-1) continue;
        if (MAKELONG(info.hid.dwVendorId, info.hid.dwProductId) != (LONG)prod->Data1) continue;
        if (GetRawInputDeviceInfoA(list[i].hDevice, RIDI_DEVICENAME, NULL, &nsz) == (UINT)-1 || !nsz) continue;
        dn = (char *)malloc(nsz + 1);
        if (dn && GetRawInputDeviceInfoA(list[i].hDevice, RIDI_DEVICENAME, dn, &nsz) != (UINT)-1 && strstr(dn, "IG_")) found = 1;
        free(dn);
    }
    free(list);
    return found;
}
static void guid_text(const GUID *g, char *o, int cap) {
    snprintf(o, (size_t)cap, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", g->Data1, g->Data2, g->Data3, g->Data4[0], g->Data4[1], g->Data4[2], g->Data4[3], g->Data4[4], g->Data4[5], g->Data4[6], g->Data4[7]);
}
typedef struct DiCand { GUID inst, prod; char name[96]; } DiCand;
static DiCand g_cand[DEV_MAX_PADS]; static int g_ncand;
static BOOL CALLBACK di_enum_cb(const DIDEVICEINSTANCEA *d, void *ctx) {
    (void)ctx;
    if (g_ncand < DEV_MAX_PADS && !is_xinput_device(&d->guidProduct, d->tszProductName)) {
        g_cand[g_ncand].inst = d->guidInstance; g_cand[g_ncand].prod = d->guidProduct;
        snprintf(g_cand[g_ncand].name, sizeof g_cand[g_ncand].name, "%s", d->tszProductName[0] ? d->tszProductName : d->tszInstanceName);
        g_ncand++;
    }
    return DIENUM_CONTINUE;
}
static int axis_index_from_guid(const GUID *g, int *slider_count) {
    if (IsEqualGUID(g, &k_GUID_XAxis)) return 0; if (IsEqualGUID(g, &k_GUID_YAxis)) return 1; if (IsEqualGUID(g, &k_GUID_ZAxis)) return 2;
    if (IsEqualGUID(g, &k_GUID_RxAxis)) return 3; if (IsEqualGUID(g, &k_GUID_RyAxis)) return 4; if (IsEqualGUID(g, &k_GUID_RzAxis)) return 5;
    if (IsEqualGUID(g, &k_GUID_Slider)) { int s = (*slider_count)++; return s < 2 ? 6 + s : -1; }
    return -1;
}
typedef struct ObjCtx { PadEntry *e; int sliders; } ObjCtx;
static BOOL CALLBACK di_obj_cb(const DIDEVICEOBJECTINSTANCEA *o, void *vctx) {
    ObjCtx *c = (ObjCtx *)vctx; int ai = axis_index_from_guid(&o->guidType, &c->sliders);
    if (ai >= 0) {
        DIPROPRANGE r; DIPROPDWORD dz;
        c->e->axis_present[ai] = 1;
        r.diph.dwSize = sizeof r; r.diph.dwHeaderSize = sizeof r.diph; r.diph.dwHow = DIPH_BYID; r.diph.dwObj = o->dwType; r.lMin = -1000; r.lMax = 1000;
        IDirectInputDevice8_SetProperty(c->e->dev, DIPROP_RANGE, &r.diph);
        dz.diph.dwSize = sizeof dz; dz.diph.dwHeaderSize = sizeof dz.diph; dz.diph.dwHow = DIPH_BYID; dz.diph.dwObj = o->dwType; dz.dwData = 0;
        IDirectInputDevice8_SetProperty(c->e->dev, DIPROP_DEADZONE, &dz.diph);
        if (SUCCEEDED(IDirectInputDevice8_GetProperty(c->e->dev, DIPROP_RANGE, &r.diph)) && r.lMax > r.lMin) { c->e->amin[ai] = r.lMin; c->e->amax[ai] = r.lMax; }
        else { c->e->amin[ai] = -1000; c->e->amax[ai] = 1000; }
    }
    return DIENUM_CONTINUE;
}
static void di_choose_map(PadEntry *e, const GUID *prod) {
    unsigned short vid = LOWORD(prod->Data1), pid = HIWORD(prod->Data1); size_t i;
    e->info.vid = vid; e->info.pid = pid; e->info.std_known = 0; e->map = &g_dimap_default;
    for (i = 0; i < sizeof g_dimaps / sizeof g_dimaps[0]; i++) if (g_dimaps[i].vid == vid && g_dimaps[i].pid == pid) { e->map = g_dimaps[i].map; e->info.std_known = 1; break; }
    e->dynmap = *e->map;
    if (e->dynmap.ax[PA_RX] == -2) {                                          /* unknown device: right stick on Rx Ry if the device has them, else Z Rz */
        if (e->axis_present[3] && e->axis_present[4]) { e->dynmap.ax[PA_RX] = 3; e->dynmap.ax[PA_RY] = 4; }
        else if (e->axis_present[2] && e->axis_present[5]) { e->dynmap.ax[PA_RX] = 2; e->dynmap.ax[PA_RY] = 5; }
        else { e->dynmap.ax[PA_RX] = -1; e->dynmap.ax[PA_RY] = -1; }
    }
}
static int di_open(PadEntry *e, const DiCand *c) {                          /* called without g_lock held; the entry is not visible yet */
    IDirectInputDevice8A *dev = NULL; ObjCtx oc; DIDEVCAPS caps;
    if (FAILED(IDirectInput8_CreateDevice(g_di, &c->inst, &dev, NULL)) || !dev) return 0;
    build_format();
    if (FAILED(IDirectInputDevice8_SetDataFormat(dev, &g_joyfmt))) { IDirectInputDevice8_Release(dev); return 0; }
    IDirectInputDevice8_SetCooperativeLevel(dev, g_sink, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
    memset(e->axis_present, 0, sizeof e->axis_present);
    e->dev = dev; oc.e = e; oc.sliders = 0;
    IDirectInputDevice8_EnumObjects(dev, di_obj_cb, &oc, DIDFT_AXIS);
    caps.dwSize = sizeof caps; e->nbuttons = 0;
    if (SUCCEEDED(IDirectInputDevice8_GetCapabilities(dev, &caps))) e->nbuttons = (int)caps.dwButtons;
    e->inst = c->inst; di_choose_map(e, &c->prod);
    IDirectInputDevice8_Acquire(dev);
    return 1;
}
static void di_scan(void) {
    int i, k, f;
    if (!g_di) {
        if (!g_dinput_dll) { g_dinput_dll = LoadLibraryA("dinput8.dll"); if (g_dinput_dll) pDirectInput8Create = (HRESULT (WINAPI *)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN))GetProcAddress(g_dinput_dll, "DirectInput8Create"); }
        if (!pDirectInput8Create || FAILED(pDirectInput8Create(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, &k_IID_IDirectInput8A, (void **)&g_di, NULL)) || !g_di) { g_di = NULL; return; }
    }
    g_ncand = 0;
    IDirectInput8_EnumDevices(g_di, DI8DEVCLASS_GAMECTRL, di_enum_cb, NULL, DIEDFL_ATTACHEDONLY);
    EnterCriticalSection(&g_lock);
    for (i = 4; i < g_pad_slots; i++) g_pad[i].seen = 0;
    LeaveCriticalSection(&g_lock);
    for (k = 0; k < g_ncand; k++) {
        DiCand *c = &g_cand[k]; char gt[48]; PadEntry *found = NULL;
        guid_text(&c->inst, gt, sizeof gt);
        EnterCriticalSection(&g_lock);
        for (i = 4; i < g_pad_slots; i++) if (g_pad[i].used && !strcmp(g_pad[i].info.guid, gt)) { found = &g_pad[i]; break; }
        if (found && found->info.connected) { found->seen = 1; LeaveCriticalSection(&g_lock); continue; }
        LeaveCriticalSection(&g_lock);
        {   /* new or returning device: open it outside the lock, publish under the lock */
            PadEntry tmp; memset(&tmp, 0, sizeof tmp);
            if (!di_open(&tmp, c)) continue;
            EnterCriticalSection(&g_lock);
            if (found) f = (int)(found - g_pad);
            else { for (f = 4; f < g_pad_slots; f++) if (!g_pad[f].used) break; if (f == g_pad_slots) { if (g_pad_slots >= DEV_MAX_PADS) { LeaveCriticalSection(&g_lock); IDirectInputDevice8_Release(tmp.dev); continue; } g_pad_slots++; } }
            g_pad[f] = tmp; g_pad[f].used = 1; g_pad[f].seen = 1;
            g_pad[f].info.index = f; g_pad[f].info.connected = 1; g_pad[f].info.is_xinput = 0; g_pad[f].info.has_rumble = 0; g_pad[f].info.slot = -1;
            snprintf(g_pad[f].info.name, sizeof g_pad[f].info.name, "%s", c->name); snprintf(g_pad[f].info.guid, sizeof g_pad[f].info.guid, "%s", gt);
            _InterlockedIncrement(&g_pad_gen);
            LeaveCriticalSection(&g_lock);
            logf_("input: DirectInput pad %d connected: %s %s (vid %04X pid %04X, %d buttons, %s)", f, c->name, gt, g_pad[f].info.vid, g_pad[f].info.pid, g_pad[f].nbuttons, g_pad[f].info.std_known ? g_pad[f].map->name : "heuristic standard layout");
        }
    }
    EnterCriticalSection(&g_lock);                                          /* devices that were not listed any more are gone */
    for (i = 4; i < g_pad_slots; i++) if (g_pad[i].used && g_pad[i].info.connected && !g_pad[i].seen) {
        if (g_pad[i].dev) { IDirectInputDevice8_Unacquire(g_pad[i].dev); IDirectInputDevice8_Release(g_pad[i].dev); g_pad[i].dev = NULL; }
        g_pad[i].info.connected = 0; _InterlockedIncrement(&g_pad_gen);
        logf_("input: DirectInput pad %d disconnected: %s", i, g_pad[i].info.name);
    }
    LeaveCriticalSection(&g_lock);
}
static float di_axis(const PadEntry *e, const MyJoyState *js, int a) {
    double r;
    if (a < 0 || a > 7 || !e->axis_present[a]) return 0;
    r = (double)(e->amax[a] - e->amin[a]); if (r <= 0) return 0;
    r = ((double)(js->axis[a] - e->amin[a]) / r) * 2.0 - 1.0;
    return (float)(r < -1.0 ? -1.0 : r > 1.0 ? 1.0 : r);
}
static void di_fill(const PadEntry *e, const MyJoyState *js, PadState *o) {
    const DiMap *m = &e->dynmap; int i; unsigned b = 0; float v;
    memset(o, 0, sizeof *o); memset(o->hat, -1, sizeof o->hat); o->connected = 1;
    for (i = 0; i < 8; i++) o->raw_axis[i] = di_axis(e, js, i);
    for (i = 0; i < 128; i++) if (js->btn[i] & 0x80) o->raw_buttons[i >> 5] |= 1u << (i & 31);
    for (i = 0; i < 4; i++) { DWORD p = js->pov[i]; o->hat[i] = (LOWORD(p) == 0xFFFF) ? (signed char)-1 : (signed char)(((p + 2250) / 4500) & 7); }
    for (i = 0; i < PB_COUNT; i++) if (m->btn[i] >= 0 && (js->btn[m->btn[i]] & 0x80)) b |= 1u << i;
    if (o->hat[0] >= 0) {
        int h = o->hat[0];
        if (h == 7 || h == 0 || h == 1) b |= 1u << PB_DUP; if (h >= 1 && h <= 3) b |= 1u << PB_DRIGHT; if (h >= 3 && h <= 5) b |= 1u << PB_DDOWN; if (h >= 5 && h <= 7) b |= 1u << PB_DLEFT;
    }
    o->buttons = b;
    o->axis[PA_LX] = di_axis(e, js, m->ax[PA_LX]); o->axis[PA_LY] = -di_axis(e, js, m->ax[PA_LY]);                  /* DirectInput Y grows downwards */
    o->axis[PA_RX] = di_axis(e, js, m->ax[PA_RX]); o->axis[PA_RY] = -di_axis(e, js, m->ax[PA_RY]);
    for (i = PA_LT; i <= PA_RT; i++) {
        v = 0;
        if (m->ax[i] >= 0) { float r = di_axis(e, js, m->ax[i]); v = m->trig_signed ? (r + 1.0f) * 0.5f : (r > 0 ? r : 0); }
        if (m->tbtn[i - PA_LT] >= 0 && (js->btn[m->tbtn[i - PA_LT]] & 0x80)) v = 1.0f;
        o->axis[i] = v;
    }
}

/* ---- public pad API ---- */
unsigned inpdev_pad_generation(void) { return (unsigned)g_pad_gen; }
int inpdev_pad_slots(void) { return g_pad_slots; }
int inpdev_pad_info(int i, DevPadInfo *out) {
    int ok = 0;
    if (i < 0 || i >= DEV_MAX_PADS || !g_lock_ready) return 0;
    EnterCriticalSection(&g_lock);
    if (g_pad[i].used) { *out = g_pad[i].info; ok = 1; }
    LeaveCriticalSection(&g_lock);
    return ok;
}
int inpdev_pad_poll(int i, PadState *out) {
    PadEntry *e; int ok = 0;
    memset(out, 0, sizeof *out); memset(out->hat, -1, sizeof out->hat);
    if (i < 0 || i >= DEV_MAX_PADS || !g_lock_ready) return 0;
    e = &g_pad[i];
    EnterCriticalSection(&g_lock);
    if (e->used && e->info.connected) {
        if (e->info.is_xinput) {
            XI_STATE st;
            if (xi_get_state((DWORD)e->info.slot, &st) == ERROR_SUCCESS) { xi_fill(&st, out); ok = 1; }
            else { e->info.connected = 0; _InterlockedIncrement(&g_pad_gen); logf_("input: XInput controller %d disconnected", e->info.slot + 1); }
        } else if (e->dev) {
            MyJoyState js; HRESULT hr;
            IDirectInputDevice8_Poll(e->dev);
            hr = IDirectInputDevice8_GetDeviceState(e->dev, sizeof js, &js);
            if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) { IDirectInputDevice8_Acquire(e->dev); IDirectInputDevice8_Poll(e->dev); hr = IDirectInputDevice8_GetDeviceState(e->dev, sizeof js, &js); }
            if (SUCCEEDED(hr)) { di_fill(e, &js, out); ok = 1; }
        }
    }
    LeaveCriticalSection(&g_lock);
    return ok;
}
void inpdev_rumble(int i, float low, float high) {
    PadEntry *e; XI_VIB v; WORD l, h;
    if (i < 0 || i >= 4 || (!pXSetState && !fake_on()) || !g_lock_ready) return;
    e = &g_pad[i];
    l = (WORD)(low < 0 ? 0 : low > 1 ? 65535 : low * 65535.0f); h = (WORD)(high < 0 ? 0 : high > 1 ? 65535 : high * 65535.0f);
    if (!e->info.connected || (l == e->last_l && h == e->last_r)) return;
    v.wLeftMotorSpeed = l; v.wRightMotorSpeed = h; e->last_l = l; e->last_r = h;
    if (fake_on()) { logf_("input: fake pad %d rumble %u %u", i + 1, (unsigned)l, (unsigned)h); return; }
    pXSetState((DWORD)i, &v);
}
void inpdev_rescan(void) { _InterlockedExchange(&g_rescan, 1); if (g_sink) PostMessageA(g_sink, WM_TIMER, 1, 0); }

/* ------------------------------------------------------------------ the input thread: raw input window + periodic device scan */
static LRESULT CALLBACK sink_proc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (m == WM_INPUT) {
        BYTE buf[128]; UINT sz = sizeof buf;
        if (GetRawInputData((HRAWINPUT)l, RID_INPUT, buf, &sz, sizeof(RAWINPUTHEADER)) != (UINT)-1) {
            const RAWINPUT *ri = (const RAWINPUT *)buf;
            if (ri->header.dwType == RIM_TYPEKEYBOARD) on_key(&ri->data.keyboard);
            else if (ri->header.dwType == RIM_TYPEMOUSE) on_mouse(&ri->data.mouse);
        }
        return DefWindowProcA(h, m, w, l);                                   /* required so the system can clean up the raw input buffer */
    }
    if (m == WM_TIMER) { if (w == 2) focus_tick(); else { xi_scan(); di_scan(); } return 0; }
    return DefWindowProcA(h, m, w, l);
}
static DWORD WINAPI input_thread(LPVOID p) {
    WNDCLASSA wc; RAWINPUTDEVICE rid[2]; MSG msg; (void)p;
    memset(&wc, 0, sizeof wc); wc.lpfnWndProc = sink_proc; wc.hInstance = GetModuleHandleA(NULL); wc.lpszClassName = "TurokInputSink";
    RegisterClassA(&wc);
    /* a hidden top-level window (DirectInput wants one for the cooperative level); never shown, never activated */
    g_sink = CreateWindowExA(WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, "TurokInputSink", "", WS_POPUP, 0, 0, 1, 1, NULL, NULL, wc.hInstance, NULL);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
    rid[0].usUsagePage = 1; rid[0].usUsage = 6; rid[0].dwFlags = RIDEV_INPUTSINK; rid[0].hwndTarget = g_sink;      /* keyboard */
    rid[1].usUsagePage = 1; rid[1].usUsage = 2; rid[1].dwFlags = RIDEV_INPUTSINK; rid[1].hwndTarget = g_sink;      /* mouse */
    if (!g_sink || !RegisterRawInputDevices(rid, 2, sizeof rid[0])) logf_("input: RegisterRawInputDevices failed (%lu)", GetLastError());
    xi_scan(); di_scan();
    SetTimer(g_sink, 1, 1000, NULL);                                         /* hot-plug scan once a second */
    SetTimer(g_sink, 2, 25, NULL);                                           /* focus tracking */
    SetEvent(g_ready);
    while (!g_stop && GetMessageA(&msg, NULL, 0, 0) > 0) { TranslateMessage(&msg); DispatchMessageA(&msg); }
    {   int i;                                                               /* shut down: stop motors, release devices */
        for (i = 0; i < 4; i++) if (g_pad[i].info.connected && pXSetState) { XI_VIB v; v.wLeftMotorSpeed = v.wRightMotorSpeed = 0; pXSetState((DWORD)i, &v); }
        EnterCriticalSection(&g_lock);
        for (i = 4; i < g_pad_slots; i++) if (g_pad[i].dev) { IDirectInputDevice8_Unacquire(g_pad[i].dev); IDirectInputDevice8_Release(g_pad[i].dev); g_pad[i].dev = NULL; }
        LeaveCriticalSection(&g_lock);
        if (g_di) { IDirectInput8_Release(g_di); g_di = NULL; }
    }
    if (g_sink) DestroyWindow(g_sink);
    g_sink = NULL;
    return 0;
}
int inpdev_start(void *hwnd) {
    if (hwnd) g_focus_hwnd = (HWND)hwnd;
    if (g_thread) return 1;
    if (!g_lock_ready) { int s; InitializeCriticalSection(&g_lock); g_lock_ready = 1;
        for (s = 0; s < 4; s++) { g_pad[s].used = 1; g_pad[s].info.index = s; g_pad[s].info.is_xinput = 1; g_pad[s].info.slot = s; g_pad[s].info.has_rumble = 1; snprintf(g_pad[s].info.name, sizeof g_pad[s].info.name, "Xbox / XInput controller %d", s + 1); } }
    g_stop = 0; g_ready = CreateEventA(NULL, TRUE, FALSE, NULL);
    g_thread = CreateThread(NULL, 0, input_thread, NULL, 0, NULL);
    if (!g_thread) return 0;
    WaitForSingleObject(g_ready, 3000);
    return 1;
}
void inpdev_stop(void) {
    if (!g_thread) return;
    g_stop = 1; if (g_sink) PostMessageA(g_sink, WM_QUIT, 0, 0);
    if (WaitForSingleObject(g_thread, 2000) != WAIT_OBJECT_0) TerminateThread(g_thread, 0);
    CloseHandle(g_thread); g_thread = NULL;
}

/* ------------------------------------------------------------------ self test (no hardware): raw input event translation and the pad translations with synthetic data */
static int g_tf, g_tc;
#define T(c) do { g_tc++; if (!(c)) { g_tf++; printf("  FAIL input_dev.c:%d: %s\n", __LINE__, #c); } } while (0)
static void t_key(unsigned mk, unsigned fl, unsigned vk) { RAWKEYBOARD k; memset(&k, 0, sizeof k); k.MakeCode = (USHORT)mk; k.Flags = (USHORT)fl; k.VKey = (USHORT)vk; on_key(&k); }
static void t_mouse(unsigned flags, unsigned bf, int data, int x, int y) { RAWMOUSE m; memset(&m, 0, sizeof m); m.usFlags = (USHORT)flags; m.usButtonFlags = (USHORT)bf; m.usButtonData = (USHORT)data; m.lLastX = x; m.lLastY = y; on_mouse(&m); }
static void t_clear(void) { int k; for (k = 0; k < 256; k++) { g_key[k] = 0; g_key_supp[k] = 0; g_key_latch[k] = 0; } g_mb = g_mb_supp = g_mb_latch = 0; g_mx = g_my = 0; for (k = 0; k < 4; k++) g_whl[k] = 0; g_act_prev = 1; }
int inpdev_selftest(void) {
    unsigned char keys[256]; unsigned mb; float dx, dy; int wh[4]; PadState ps; XI_STATE xs; PadEntry e; MyJoyState js; int i; HWND save_focus = g_focus_hwnd; LONG save_mode = g_mouse_mode;
    char gt[48]; GUID g = { 0x0AB1C2D3, 0x1234, 0x5678, { 0x9A, 0xBC, 0xDE, 0xF0, 0x11, 0x22, 0x33, 0x44 } };
    g_tf = g_tc = 0; printf("device layer\n");
    g_focus_hwnd = NULL; g_background = 0; t_clear(); inpdev_set_mouse_mode(2);
    /* keyboard: physical keys, extended keys, the quirks */
    t_key(0x11, 0, 'W'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x11] == 1);
    t_key(0x11, 1, 'W'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x11] == 0);
    t_key(0x1E, 0, 'A'); t_key(0x1E, 1, 'A'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x1E] == 1);     /* a tap between two polls is still seen once ... */
    inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x1E] == 0);                                              /* ... and only once */
    t_key(0x48, 2, VK_UP); t_key(0x48, 0, VK_NUMPAD8); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0xC8] == 1 && keys[0x48] == 1);   /* Up arrow (E0) and numpad 8 are different keys */
    t_key(0x48, 3, VK_UP); t_key(0x48, 1, VK_NUMPAD8); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0xC8] == 0 && keys[0x48] == 0);
    t_key(0x2A, 2, VK_SHIFT); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x2A] == 0 && keys[0xAA & 0xFF] == 0);        /* fake shift of the numpad navigation keys is ignored */
    t_key(0x45, 2, VK_NUMLOCK); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x45] == 1); t_key(0x45, 3, VK_NUMLOCK);
    t_key(0x1D, 4, VK_PAUSE); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x1D] == 0);                            /* the E1 prefix of Pause is ignored */
    t_key(0, 0, VK_SPACE); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x39] == 1); t_key(0, 1, VK_SPACE);      /* injected input without a scancode: derived from the virtual key */
    t_key(0x1C, 2, VK_RETURN); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x9C] == 1 && keys[0x1C] == 0); t_key(0x1C, 3, VK_RETURN);   /* numpad Enter */
    t_clear();
    /* focus: a key held while the window gets the focus is ignored until released; a key pressed after the change counts; nothing is read while unfocused */
    g_focus_hwnd = GetDesktopWindow(); g_act_prev = 0;                                                          /* "not the foreground window" (the desktop window is never foreground) */
    t_key(0x10, 0, 'Q'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x10] == 0);
    g_focus_hwnd = NULL; focus_tick(); t_key(0x12, 0, 'E'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x10] == 0 && keys[0x12] == 1);
    t_key(0x10, 1, 'Q'); t_key(0x10, 0, 'Q'); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(keys[0x10] == 1);       /* released and pressed again: counts */
    t_key(0x12, 1, 'E'); t_key(0x10, 1, 'Q'); t_clear();
    /* mouse: buttons, wheel, motion by mode */
    t_mouse(0, 0x0001, 0, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T((mb & 1) == 1); t_mouse(0, 0x0002, 0, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(mb == 0);
    t_mouse(0, 0x0040, 0, 0, 0); t_mouse(0, 0x0100, 0, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(mb == 0x18); t_mouse(0, 0x0080 | 0x0200, 0, 0, 0);
    t_mouse(0, 0, 0, 5, -3); t_mouse(0, 0, 0, 2, 1); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(dx == 7 && dy == -2);
    inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(dx == 0 && dy == 0);                                            /* consumed */
    t_mouse(0, 0x0400, 120, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(wh[0] == 1 && wh[1] == 0);
    t_mouse(0, 0x0400, (unsigned short)-240, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(wh[1] == 2);
    t_mouse(0, 0x0800, 120, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(wh[3] == 1);
    t_mouse(0, 0x0400, 60, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(wh[0] == 0); t_mouse(0, 0x0400, 60, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(wh[0] == 1);   /* high resolution wheels */
    inpdev_set_mouse_mode(1); t_mouse(0, 0, 0, 9, 9); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(dx == 0 && dy == 0);                    /* mode 1: no motion */
    inpdev_set_mouse_mode(0); t_mouse(0, 0x0001, 0, 0, 0); inpdev_read_kbm(keys, &mb, &dx, &dy, wh); T(mb == 0); t_mouse(0, 0x0002, 0, 0, 0);   /* mode 0: no buttons */
    inpdev_set_mouse_mode(2); t_clear();
    t_mouse(MOUSE_MOVE_ABSOLUTE, 0, 0, 1000, 2000); t_mouse(MOUSE_MOVE_ABSOLUTE, 0, 0, 1000 + 655, 2000); inpdev_read_kbm(keys, &mb, &dx, &dy, wh);       /* absolute devices: differences */
    T(dx > 0 && dy == 0); g_abs_valid = 0;
    /* XInput translation */
    memset(&xs, 0, sizeof xs); xs.Gamepad.wButtons = 0x1000 | 0x0100 | 0x0001 | 0x0010 | 0x0040; xs.Gamepad.sThumbLX = 32767; xs.Gamepad.sThumbLY = -32768; xs.Gamepad.sThumbRX = -16384; xs.Gamepad.bRightTrigger = 255;
    xi_fill(&xs, &ps);
    T(ps.connected && ps.buttons == ((1u << PB_A) | (1u << PB_LB) | (1u << PB_DUP) | (1u << PB_START) | (1u << PB_LS)));
    T(ps.axis[PA_LX] > 0.999f && ps.axis[PA_LY] <= -0.999f && fabsf(ps.axis[PA_RX] + 0.5f) < 0.01f && ps.axis[PA_RT] > 0.999f && ps.axis[PA_LT] == 0);
    xs.Gamepad.wButtons = 0x2000 | 0x4000 | 0x8000 | 0x0200 | 0x0020 | 0x0080 | 0x0002 | 0x0004 | 0x0008; xi_fill(&xs, &ps);
    T(ps.buttons == ((1u << PB_B) | (1u << PB_X) | (1u << PB_Y) | (1u << PB_RB) | (1u << PB_BACK) | (1u << PB_RS) | (1u << PB_DDOWN) | (1u << PB_DLEFT) | (1u << PB_DRIGHT)));
    /* DirectInput translation, PlayStation layout (X Y = left stick, Z Rz = right stick, Rx Ry = triggers, hat = d-pad) */
    memset(&e, 0, sizeof e); e.dynmap = g_dimap_ps; for (i = 0; i < 8; i++) { e.axis_present[i] = 1; e.amin[i] = -1000; e.amax[i] = 1000; }
    memset(&js, 0, sizeof js); for (i = 0; i < 4; i++) js.pov[i] = 0xFFFFFFFFu;
    js.axis[0] = 1000; js.axis[1] = -1000; js.axis[2] = -500; js.axis[5] = 1000; js.axis[3] = 1000; js.axis[4] = -1000;
    js.btn[1] = 0x80; js.btn[0] = 0x80; js.btn[4] = 0x80; js.btn[9] = 0x80; js.btn[12] = 0x80; js.pov[0] = 9000;
    di_fill(&e, &js, &ps);
    T(ps.axis[PA_LX] > 0.999f && ps.axis[PA_LY] > 0.999f);                                                       /* raw Y -1 = stick pushed up = +1 */
    T(fabsf(ps.axis[PA_RX] + 0.5f) < 0.01f && ps.axis[PA_RY] < -0.999f);
    T(ps.axis[PA_LT] > 0.999f && ps.axis[PA_RT] < 0.001f);                                                       /* triggers rest at -1000 */
    T(ps.buttons == ((1u << PB_A) | (1u << PB_X) | (1u << PB_LB) | (1u << PB_START) | (1u << PB_GUIDE) | (1u << PB_DRIGHT)));
    T(ps.hat[0] == 2 && ps.hat[1] == -1 && (ps.raw_buttons[0] & 3u) == 3u && ps.raw_axis[0] > 0.999f && ps.raw_axis[1] < -0.999f);
    js.pov[0] = 0; di_fill(&e, &js, &ps); T(ps.hat[0] == 0 && (ps.buttons & (1u << PB_DUP)) && !(ps.buttons & (1u << PB_DRIGHT)));
    js.pov[0] = 4500; di_fill(&e, &js, &ps); T(ps.hat[0] == 1 && (ps.buttons & (1u << PB_DUP)) && (ps.buttons & (1u << PB_DRIGHT)));
    js.pov[0] = 31500; di_fill(&e, &js, &ps); T(ps.hat[0] == 7 && (ps.buttons & (1u << PB_DUP)) && (ps.buttons & (1u << PB_DLEFT)));
    js.pov[0] = 18000; di_fill(&e, &js, &ps); T(ps.hat[0] == 4 && (ps.buttons & (1u << PB_DDOWN)));
    js.pov[0] = 0xFFFF; di_fill(&e, &js, &ps); T(ps.hat[0] == -1 && !(ps.buttons & ((1u << PB_DUP) | (1u << PB_DDOWN) | (1u << PB_DLEFT) | (1u << PB_DRIGHT))));
    /* an unknown device: Xbox-order buttons, right stick on Rx Ry when the device has them, else on Z Rz */
    memset(&e, 0, sizeof e); e.axis_present[0] = e.axis_present[1] = e.axis_present[2] = e.axis_present[5] = 1; for (i = 0; i < 8; i++) { e.amin[i] = 0; e.amax[i] = 65535; }
    { GUID prod; memset(&prod, 0, sizeof prod); prod.Data1 = MAKELONG(0x1234, 0x5678); di_choose_map(&e, &prod); }
    T(!e.info.std_known && e.dynmap.ax[PA_RX] == 2 && e.dynmap.ax[PA_RY] == 5);
    memset(&js, 0, sizeof js); js.axis[0] = 32768; js.axis[1] = 32768; js.axis[2] = 65535; js.axis[5] = 0; js.btn[7] = 0x80; for (i = 0; i < 4; i++) js.pov[i] = 0xFFFFFFFFu;
    di_fill(&e, &js, &ps); T(fabsf(ps.axis[PA_LX]) < 0.01f && ps.axis[PA_RX] > 0.99f && ps.axis[PA_RY] > 0.99f && (ps.buttons & (1u << PB_START)));
    memset(&e, 0, sizeof e); for (i = 0; i < 6; i++) { e.axis_present[i] = 1; } { GUID prod; memset(&prod, 0, sizeof prod); prod.Data1 = MAKELONG(0x1234, 0x5678); di_choose_map(&e, &prod); } T(e.dynmap.ax[PA_RX] == 3 && e.dynmap.ax[PA_RY] == 4);
    { GUID prod; memset(&prod, 0, sizeof prod); prod.Data1 = MAKELONG(0x054C, 0x09CC); di_choose_map(&e, &prod); T(e.info.std_known && e.info.vid == 0x054C && e.info.pid == 0x09CC && e.map == &g_dimap_ps); }
    guid_text(&g, gt, sizeof gt); T(!strcmp(gt, "{0AB1C2D3-1234-5678-9ABC-DEF011223344}"));
    g_focus_hwnd = save_focus; inpdev_set_mouse_mode((int)save_mode); t_clear();
    printf("device layer: %d checks, %d failed\n", g_tc, g_tf);
    return g_tf;
}