/* input.c - the port's input system as the game sees it: device assignment, the per-port N64 pad state, mouse capture, hotkeys, controls.ini
 * (loading + hot reload) and the rumble pak shims.  The device layer is port\input_dev.c, the mapping engine and the file format port\input_core.c.
 *
 * Hooks used by os_shim.c:   input_port_connected(i)  input_poll_begin()  input_poll_port(i, &buttons, &x, &y)  input_motor_init/start/stop(pfs)
 * Hook used by win32_main.cpp: input_attach(hwnd)   (subclasses the window: hotkeys, mouse capture, config hot reload; one line in WinMain)
 *
 * Scripted test input (port_input*.txt, TUROK_AUTOPRESS, TUROK_REPLAY) is merged by os_shim.c exactly as before and wins: real devices are only read for a
 * port while no scripted input is active on it. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <intrin.h>
#include "input_core.h"
#include "input_dev.h"

extern int oracle_enabled(void);
extern volatile long g_frames;                          /* game_glue.c: game frames run so far */
extern unsigned int osGetCount(void);                  /* os_shim.c: the game clock (real time at 1x, frame based under TUROK_SPEED / TUROK_FF) */

/* ------------------------------------------------------------------ state */
#define TIMER_ID 0x7711
static CRITICAL_SECTION g_cs; static volatile LONG g_cs_ready;
static ControlsCfg g_cfg;
static MapState g_map[MAX_PLAYERS];
static unsigned g_last_count[MAX_PLAYERS]; static int g_have_count[MAX_PLAYERS];      /* osGetCount() of the previous poll: the game clock (46.875 MHz), also right under TUROK_SPEED */
static int g_inited, g_attached, g_off;                 /* g_off: real devices disabled (TUROK_INPUT=0, oracle mode) */
static int g_env_pads = -1, g_inputlog = -1;
static HWND g_hwnd; static WNDPROC g_old_proc;
static char g_cfg_path[MAX_PATH]; static int g_cfg_have, g_cfg_good; static FILETIME g_cfg_time; static DWORD g_cfg_size;      /* g_cfg_good: a usable file (or the defaults of a missing one) has been applied */
static char g_title_base[160];

/* assignment: pad table indices per player */
static int g_assign[MAX_PLAYERS][MAX_PADS_PER_PLAYER], g_nassign[MAX_PLAYERS], g_prev_auto[MAX_PLAYERS][MAX_PADS_PER_PLAYER];
static unsigned g_assign_gen = 0xFFFFFFFFu; static int g_assign_dirty = 1;
static int g_mouse_player = -1;

/* snapshot taken by input_poll_begin() */
static unsigned char g_keys[256]; static unsigned g_mbtn; static float g_dx, g_dy; static int g_wheel[4];
static PadState g_padst[DEV_MAX_PADS]; static int g_snap_valid, g_ctx = -1;

/* mouse capture */
static int g_captured, g_user_released, g_click_captured, g_modal, g_esc_armed; static DWORD g_esc_tick;
/* rumble */
static struct { int ch; float level, target; } g_motor[MAX_PLAYERS]; static DWORD g_motor_tick;
static char g_notice[160]; static volatile LONG g_notice_pending; static DWORD g_notice_until;

static char g_logbuf[16384]; static int g_loglen;       /* a GUI process has no stderr until game_glue.c re-opens it onto the log file (after input_attach): keep the early lines */
#include <io.h>
static void log_flush(void) { if (g_loglen && _fileno(stderr) >= 0) { fwrite(g_logbuf, 1, (size_t)g_loglen, stderr); fflush(stderr); g_loglen = 0; } }
static void log_line(const char *m) {
    size_t n = strlen(m);
    if (_fileno(stderr) < 0) { if (g_loglen + n + 2 < sizeof g_logbuf) { memcpy(g_logbuf + g_loglen, m, n); g_loglen += (int)n; g_logbuf[g_loglen++] = 10; } return; }
    log_flush(); fprintf(stderr, "%s\n", m); fflush(stderr);
}
static void devlog(const char *m) { log_line(m); }
static void notice(const char *fmt, ...);
static void cfg_log(void *u, int line, const char *msg) { char b[300]; (void)u; snprintf(b, sizeof b, "input: %s:%d: %s", g_cfg_path[0] ? g_cfg_path : "controls.ini", line, msg); log_line(b); }

static int pads_wanted(void) {
    if (g_env_pads < 0) { char e[8]; g_env_pads = GetEnvironmentVariableA("TUROK_PADS", e, sizeof e) ? atoi(e) : 0; if (g_env_pads < 0) g_env_pads = 0; if (g_env_pads > 4) g_env_pads = 4; }
    return g_env_pads;
}

/* ------------------------------------------------------------------ game context: free play or menu (guest memory of the US v1.1 build) */
static unsigned be32(unsigned v) { return _byteswap_ulong(v); }
/* "free play" = game state 13 (the main loop that also hosts the attract demos) with only the in-game HUD layer on the UI stack, in a session the player started
 * through the menus.  The attract demos look the same from the inside (state 13, UI stack depth 0) but never pass a menu screen: the session flag is set when a
 * screen other than the base ones is on the stack (main menu, loadout, options, ...) and cleared when the title (29) or the demo screen (24) is on top again. */
static int g_session;
static double g_req_yaw, g_del_yaw, g_req_pitch, g_del_pitch;     /* TUROK_INPUTLOG statistics of the mouse look (degrees) */
static int game_context(void) {
    static int broken;
    if (broken) return -1;
    __try {
        unsigned st = be32(*(volatile unsigned *)0x80146878u);          /* game state (see docs\PORT_STATUS.md, game state machine) */
        unsigned mgr = be32(*(volatile unsigned *)0x8014D080u);         /* UI manager (SndMgr in include\b22_types.h): top = index of the topmost screen, stk = screen stack */
        int top = -1, id = -1;
        if (mgr >= 0x80000000u && mgr < 0x807FFF00u) {
            unsigned stk = be32(*(volatile unsigned *)(size_t)(mgr + 12));
            top = (int)be32(*(volatile unsigned *)(size_t)(mgr + 4));
            if (top >= 0 && top < 32 && stk >= 0x80000000u && stk < 0x807FFC00u) id = (int)be32(*(volatile unsigned *)(size_t)(stk + (unsigned)top * 0x1C + 4));     /* SndStkEnt.id */
        }
        if (id == 29 || id == 24) g_session = 0; else if (top >= 2 && id > 0 && id != 2) g_session = 1;
        return (st == 13 && top <= 0 && g_session) ? 1 : 0;
    } __except (EXCEPTION_EXECUTE_HANDLER) { broken = 1; return -1; }
}

/* ------------------------------------------------------------------ config file */
static void resolve_cfg_path(void) {
    char env[MAX_PATH], exe[MAX_PATH], cand[MAX_PATH]; char *slash;
    g_cfg_path[0] = 0;
    if (GetEnvironmentVariableA("TUROK_CONTROLS", env, sizeof env)) { snprintf(g_cfg_path, sizeof g_cfg_path, "%s", env); return; }
    GetModuleFileNameA(NULL, exe, sizeof exe); slash = strrchr(exe, '\\'); if (slash) *slash = 0;
    snprintf(cand, sizeof cand, "%s\\controls.ini", exe);
    if (GetFileAttributesA(cand) != INVALID_FILE_ATTRIBUTES) { snprintf(g_cfg_path, sizeof g_cfg_path, "%s", cand); return; }
    if (GetFileAttributesA("controls.ini") != INVALID_FILE_ATTRIBUTES) { GetFullPathNameA("controls.ini", sizeof g_cfg_path, g_cfg_path, NULL); return; }
    snprintf(g_cfg_path, sizeof g_cfg_path, "%s", cand);              /* where the tool will create it */
}
static int stat_cfg(FILETIME *t, DWORD *size) {
    WIN32_FILE_ATTRIBUTE_DATA fad;
    if (!GetFileAttributesExA(g_cfg_path, GetFileExInfoStandard, &fad)) return 0;
    *t = fad.ftLastWriteTime; *size = fad.nFileSizeLow; return 1;
}
static void apply_config(const ControlsCfg *nc) {
    int i;
    EnterCriticalSection(&g_cs);
    g_cfg = *nc;
    for (i = 0; i < MAX_PLAYERS; i++) map_reset(&g_map[i]);
    g_assign_dirty = 1;
    LeaveCriticalSection(&g_cs);
    inpdev_set_background(g_cfg.background_input);
}
/* force: reload even if the file did not change (F2).  Returns 1 when new settings were applied. */
static int reload_config(int force) {
    FILETIME t; DWORD size; int have = stat_cfg(&t, &size); ControlsCfg nc; int r;
    if (!force && have == g_cfg_have && (!have || (CompareFileTime(&t, &g_cfg_time) == 0 && size == g_cfg_size))) return 0;
    if (!have) {
        g_cfg_have = 0; g_cfg_good = 1;
        cfg_defaults(&nc); apply_config(&nc);
        log_line("input: controls file not found, built-in defaults in use");
        notice("Controls: built-in defaults");
        return 1;
    }
    r = cfg_load(&nc, g_cfg_path, cfg_log, NULL);
    if (r == -2) { if (force) notice("Controls file cannot be read"); return 0; }          /* maybe being written right now: try again at the next change check */
    g_cfg_have = 1; g_cfg_time = t; g_cfg_size = size;
    if (r < 0) {
        char b[300];
        if (!g_cfg_good) { snprintf(b, sizeof b, "input: %s is not a usable controls file, built-in defaults in use", g_cfg_path); log_line(b); notice("Controls file unusable: built-in defaults"); }      /* start: g_cfg still holds the defaults */
        else { snprintf(b, sizeof b, "input: %s is not a usable controls file, keeping the previous settings", g_cfg_path); log_line(b); notice("Controls file unusable: settings unchanged"); }   /* hot reload: a half-written file must not reset the controls */
        return 0;
    }
    g_cfg_good = 1;
    apply_config(&nc);
    { char b[300]; snprintf(b, sizeof b, "input: controls loaded from %s", g_cfg_path); log_line(b); }
    notice("Controls reloaded");
    return 1;
}

/* ------------------------------------------------------------------ device assignment */
static int pad_ok(const DevPadInfo *pi) { return pi->connected; }
static int di_nth(int n) {                                    /* n-th (1-based) connected DirectInput pad in table order */
    int i, k = 0; DevPadInfo pi;
    for (i = 4; i < inpdev_pad_slots(); i++) if (inpdev_pad_info(i, &pi) && pi.connected && ++k == n) return i;
    return -1;
}
static int ci_contains(const char *h, const char *n) {
    size_t l = strlen(n), i; if (!l) return 0;
    for (; *h; h++) { for (i = 0; i < l; i++) { char a = h[i], b = n[i]; if (!a) return 0; if (a >= 'A' && a <= 'Z') a += 32; if (b >= 'A' && b <= 'Z') b += 32; if (a != b) break; } if (i == l) return 1; }
    return 0;
}
static void refresh_assign(void) {            /* caller holds g_cs */
    unsigned gen = inpdev_pad_generation();
    int used[DEV_MAX_PADS], want[MAX_PLAYERS][MAX_PADS_PER_PLAYER], p, k, i, slots;
    DevPadInfo pi;
    if (!g_assign_dirty && gen == g_assign_gen) return;
    g_assign_gen = gen; g_assign_dirty = 0;
    memset(used, 0, sizeof used);
    slots = inpdev_pad_slots();
    for (p = 0; p < MAX_PLAYERS; p++) for (k = 0; k < MAX_PADS_PER_PLAYER; k++) want[p][k] = -1;
    /* explicit specs first */
    for (p = 0; p < MAX_PLAYERS; p++) for (k = 0; k < g_cfg.player[p].npads; k++) {
        const PadSpec *s = &g_cfg.player[p].pad[k]; int dev = -1;
        if (s->kind == PS_XINPUT) { if (s->index >= 0 && s->index < 4 && inpdev_pad_info(s->index, &pi) && pad_ok(&pi)) dev = s->index; }
        else if (s->kind == PS_DI_INDEX) dev = di_nth(s->index);
        else if (s->kind == PS_DI_GUID) { for (i = 4; i < slots; i++) if (inpdev_pad_info(i, &pi) && pi.connected && !_stricmp(pi.guid, s->text)) { dev = i; break; } }
        else if (s->kind == PS_DI_NAME) { for (i = 0; i < slots; i++) if (inpdev_pad_info(i, &pi) && pi.connected && !used[i] && ci_contains(pi.name, s->text)) { dev = i; break; } }
        if (dev >= 0 && !used[dev]) { used[dev] = 1; want[p][k] = dev; }
    }
    /* automatic specs: keep the pad a slot had when it is still there, then hand out the free pads in player order */
    for (p = 0; p < MAX_PLAYERS; p++) for (k = 0; k < g_cfg.player[p].npads; k++) {
        int d = g_prev_auto[p][k];
        if (g_cfg.player[p].pad[k].kind == PS_AUTO && d >= 0 && !used[d] && inpdev_pad_info(d, &pi) && pi.connected) { used[d] = 1; want[p][k] = d; }
    }
    for (p = 0; p < MAX_PLAYERS; p++) for (k = 0; k < g_cfg.player[p].npads; k++) {
        if (g_cfg.player[p].pad[k].kind != PS_AUTO || want[p][k] >= 0) continue;
        for (i = 0; i < slots; i++) if (!used[i] && inpdev_pad_info(i, &pi) && pi.connected) { used[i] = 1; want[p][k] = i; break; }
    }
    g_mouse_player = -1;
    for (p = 0; p < MAX_PLAYERS; p++) {
        int n = 0;
        for (k = 0; k < g_cfg.player[p].npads; k++) {
            if (g_cfg.player[p].pad[k].kind == PS_AUTO) g_prev_auto[p][k] = want[p][k];
            if (want[p][k] >= 0) {
                if (n < MAX_PADS_PER_PLAYER) g_assign[p][n++] = want[p][k];
            }
        }
        g_nassign[p] = n;
        if (g_mouse_player < 0 && g_cfg.player[p].use_mouse) g_mouse_player = p;
    }
    {   static int logged[MAX_PLAYERS][MAX_PADS_PER_PLAYER + 1]; static int first = 1;       /* log the assignment whenever it changes */
        for (p = 0; p < MAX_PLAYERS; p++) {
            int same = !first && logged[p][MAX_PADS_PER_PLAYER] == g_nassign[p];
            for (k = 0; k < g_nassign[p]; k++) if (logged[p][k] != g_assign[p][k]) same = 0;
            if (same) continue;
            for (k = 0; k < g_nassign[p]; k++) {
                char b[260]; DevPadInfo q; logged[p][k] = g_assign[p][k];
                if (inpdev_pad_info(g_assign[p][k], &q)) { snprintf(b, sizeof b, "input: player %d <- gamepad %d (%s)", p + 1, g_assign[p][k], q.name); log_line(b); }
            }
            if (!g_nassign[p] && !first && logged[p][MAX_PADS_PER_PLAYER] > 0) { char b[100]; snprintf(b, sizeof b, "input: player %d has no gamepad", p + 1); log_line(b); }
            logged[p][MAX_PADS_PER_PLAYER] = g_nassign[p];
        }
        first = 0;
    }
}

/* ------------------------------------------------------------------ init */
static void ensure_init(void) {
    int i;
    if (g_inited) return;
    if (!g_cs_ready) { InitializeCriticalSection(&g_cs); g_cs_ready = 1; }
    g_inited = 1;
    cfg_defaults(&g_cfg);
    for (i = 0; i < MAX_PLAYERS; i++) { int k; map_reset(&g_map[i]); for (k = 0; k < MAX_PADS_PER_PLAYER; k++) g_prev_auto[i][k] = -1; g_motor[i].ch = -1; }
    { char e[8]; if (GetEnvironmentVariableA("TUROK_INPUT", e, sizeof e) && atoi(e) == 0) g_off = 1; }
    if (oracle_enabled()) g_off = 1;
    inpdev_set_log(devlog);
    resolve_cfg_path();
    reload_config(1);
    if (g_off) log_line("input: real devices disabled (TUROK_INPUT=0 or oracle mode); scripted input only");
}

/* ------------------------------------------------------------------ hooks for os_shim.c */
int input_port_connected(int i) {
    int r = 0;
    ensure_init(); log_flush();
    if (i == 0) return 1;                                         /* player 1 is always there (as before) */
    if (i < pads_wanted()) return 1;                              /* TUROK_PADS=n: ports below n report a controller (scripted tests) */
    if (i < 0 || i >= MAX_PLAYERS || g_off) return 0;
    EnterCriticalSection(&g_cs);
    refresh_assign();
    r = g_cfg.player[i].use_keyboard || g_nassign[i] > 0 || (g_cfg.player[i].use_mouse && g_mouse_player == i);
    LeaveCriticalSection(&g_cs);
    return r;
}

void input_poll_begin(void) {
    int p, k, i;
    ensure_init(); log_flush();
    g_snap_valid = 0;
    if (g_off || !g_attached) return;
    EnterCriticalSection(&g_cs);
    refresh_assign();
    g_ctx = game_context();
    inpdev_read_kbm(g_keys, &g_mbtn, &g_dx, &g_dy, g_wheel);
    for (i = 0; i < DEV_MAX_PADS; i++) g_padst[i].connected = 0;
    if (inpdev_active())                                                                    /* gamepads, like keyboard and mouse, only count while the window is in front (background_input = on lifts that) */
        for (p = 0; p < MAX_PLAYERS; p++) for (k = 0; k < g_nassign[p]; k++) { int d = g_assign[p][k]; if (!g_padst[d].connected) inpdev_pad_poll(d, &g_padst[d]); }
    g_snap_valid = 1;
    LeaveCriticalSection(&g_cs);
    if (g_inputlog < 0) { char e[8]; g_inputlog = GetEnvironmentVariableA("TUROK_INPUTLOG", e, sizeof e) ? 1 : 0; }
    if (g_inputlog) {                                                                      /* poll statistics: how often does the game read the pads? */
        static unsigned long polls, f0; static unsigned t0;
        if (!t0) { t0 = osGetCount(); f0 = (unsigned long)g_frames; }
        if (++polls % 400 == 0) { unsigned t = osGetCount(); fprintf(stderr, "input: %lu polls, %lu game frames in %.2f game-s -> %.2f polls per frame; mouse look yaw asked %.2f delivered %.2f deg, pitch asked %.2f delivered %.2f deg\n", 400ul, (unsigned long)g_frames - f0, (double)(t - t0) / 46875000.0, 400.0 / (double)((unsigned long)g_frames - f0 ? (unsigned long)g_frames - f0 : 1), g_req_yaw, g_del_yaw, g_req_pitch, g_del_pitch); fflush(stderr); t0 = t; f0 = (unsigned long)g_frames; }
    }
}

void input_poll_port(int i, unsigned *b, int *x, int *y) {
    InputSample in; N64Pad out; unsigned now; int k;
    if (!g_snap_valid || i < 0 || i >= MAX_PLAYERS) return;
    EnterCriticalSection(&g_cs);
    memset(&in, 0, sizeof in);
    in.keys = g_keys; in.gameplay = g_ctx;
    if (g_mouse_player == i) {
        in.mouse_buttons = g_mbtn; in.mouse_dx = g_dx; in.mouse_dy = g_dy;
        for (k = 0; k < 4; k++) in.wheel[k] = g_wheel[k];
        in.mouse_valid = (inpdev_get_mouse_mode() == 2) && (g_ctx != 0 || !g_cfg.mouse_menu_guard);
    }
    for (k = 0; k < g_nassign[i]; k++) { const PadState *ps = &g_padst[g_assign[i][k]]; if (ps->connected) in.pad[in.npad++] = ps; }
    now = osGetCount();
    in.dt = g_have_count[i] ? (double)(unsigned)(now - g_last_count[i]) / 46875000.0 : 1.0 / 60.0;
    g_last_count[i] = now; g_have_count[i] = 1;
    map_eval(&g_cfg.player[i], &g_map[i], &in, &out);
    if (g_inputlog > 0 && in.mouse_valid) {                                                 /* TUROK_INPUTLOG: how much turn was asked for and how much the stick value delivers (see the stats line) */
        int sx = g_map[i].mouse_out[0], sy = g_map[i].mouse_out[1], nx = (sx < 0 ? -sx : sx) - (sx ? 3 : 0), ny = (sy < 0 ? -sy : sy) - (sy ? 3 : 0);
        g_req_yaw += in.mouse_dx * g_cfg.player[i].mouse_sens_x * MOUSE_DEG_PER_COUNT; g_del_yaw += (sx < 0 ? -1.0 : 1.0) * GAME_YAW_RATE_PER_E3 * nx * nx * nx * in.dt;
        g_req_pitch += in.mouse_dy * g_cfg.player[i].mouse_sens_y * MOUSE_DEG_PER_COUNT; g_del_pitch += (sy < 0 ? 1.0 : -1.0) * GAME_PITCH_RATE_PER_E3 * ny * ny * ny * in.dt;
    }
    LeaveCriticalSection(&g_cs);
    *b |= out.buttons; *x += out.x; *y += out.y;
    if (g_inputlog < 0) { char e[8]; g_inputlog = GetEnvironmentVariableA("TUROK_INPUTLOG", e, sizeof e) ? 1 : 0; }
    if (g_inputlog) {                                                                     /* TUROK_INPUTLOG=1: every change of a port's state from the real devices */
        static unsigned lb[MAX_PLAYERS]; static int lx[MAX_PLAYERS], ly[MAX_PLAYERS], n[MAX_PLAYERS];
        if ((out.buttons != lb[i] || out.x != lx[i] || out.y != ly[i]) && n[i]++ < 4000) { { char kb[80]; int q, nk = 0; kb[0] = 0; for (q = 0; q < 256 && nk < 6; q++) if (g_keys[q]) nk += snprintf(kb + nk, sizeof kb - (size_t)nk, " %02X", q); fprintf(stderr, "input: P%d buttons=%04X stick=%d,%d ctx=%d (mouse %02X, wheel %d%d, keys%s)%s\n", i + 1, out.buttons, out.x, out.y, g_ctx, g_mouse_player == i ? g_mbtn : 0, g_wheel[0], g_wheel[1], kb, in.npad ? (in.pad[0]->buttons ? " pad" : " pad-idle") : ""); fflush(stderr); } }
        lb[i] = out.buttons; lx[i] = out.x; ly[i] = out.y;
    }
}

/* ---- rumble pak: osMotorInit/Start/Stop of the shim ---- */
static unsigned *xl(void *p) { unsigned a = (unsigned)(size_t)p; return (unsigned *)(size_t)((a - 0x200000u) < 0x1E00000u ? a + 0x30000000u : a); }
static int port_rumble_pad(int ch) {                          /* the XInput pad (with a motor) that belongs to port ch, or -1 */
    int k; DevPadInfo pi;
    if (!g_cfg.rumble || g_off || ch < 0 || ch >= MAX_PLAYERS) return -1;
    for (k = 0; k < g_nassign[ch]; k++) if (inpdev_pad_info(g_assign[ch][k], &pi) && pi.connected && pi.is_xinput && pi.has_rumble) return g_assign[ch][k];
    return -1;
}
static void motor_apply(int ch) {
    int pad = port_rumble_pad(ch); float v;
    if (pad < 0) return;
    v = g_motor[ch].level * g_cfg.rumble_strength;
    inpdev_rumble(pad, v, v * 0.7f);
}
int input_motor_set(void *pfs, int on);
int input_motor_attach(void *pfs, int ch) {                   /* the virtual Controller Pak (port/pak_os.c) found a rumble pak on this port and initialised pfs: osMotorStart/Stop now shake the gamepad assigned to the port (none with a motor: the motor stays silent) */
    int pad;
    if (ch < 0 || ch >= MAX_PLAYERS || !pfs) return 1;
    ensure_init();
    EnterCriticalSection(&g_cs); refresh_assign(); pad = port_rumble_pad(ch); LeaveCriticalSection(&g_cs);
    g_motor[ch].ch = ch; g_motor[ch].level = g_motor[ch].target = 0;
    { static int logged[MAX_PLAYERS]; if (!logged[ch]++) { char b[140]; if (pad >= 0) snprintf(b, sizeof b, "input: rumble pak on port %d shakes gamepad %d", ch + 1, pad); else snprintf(b, sizeof b, "input: rumble pak on port %d, but no gamepad with a motor is assigned to it", ch + 1); log_line(b); } }
    {   /* TUROK_RUMBLETEST=1: pulse the motor once when the game has initialised it (5 frames on, 10 off), to check the path without gameplay events */
        static int rtest = -1, done[MAX_PLAYERS]; int k;
        if (rtest < 0) { char e[4]; rtest = GetEnvironmentVariableA("TUROK_RUMBLETEST", e, sizeof e) ? 1 : 0; }
        if (rtest && !done[ch]++) { for (k = 0; k < 5; k++) input_motor_set(pfs, 1); for (k = 0; k < 10; k++) input_motor_set(pfs, 0); }
    }
    return 0;
}
static int motor_channel(void *pfs) { unsigned *f; if (!pfs) return -1; f = xl(pfs); return (int)_byteswap_ulong(f[2]); }
int input_motor_set(void *pfs, int on) {
    int ch = motor_channel(pfs);
    if (ch < 0 || ch >= MAX_PLAYERS || g_motor[ch].ch != ch) return 0;
    g_motor[ch].target = on ? 1.0f : 0.0f;
    { static int calls[MAX_PLAYERS][2]; if (g_inputlog > 0 && calls[ch][on ? 1 : 0]++ < 3) { fprintf(stderr, "input: osMotor%s called for port %d\n", on ? "Start" : "Stop", ch + 1); fflush(stderr); } }
    g_motor[ch].level = g_motor[ch].level * 0.55f + g_motor[ch].target * 0.45f;           /* the game pulse-width modulates the motor once per frame: smooth it into a steady vibration */
    if (g_motor[ch].level < 0.03f) g_motor[ch].level = 0;
    g_motor_tick = GetTickCount();
    motor_apply(ch);
    return 0;
}

/* ------------------------------------------------------------------ window: mouse capture, hotkeys, hot reload (main thread) */
static void notice(const char *fmt, ...) {
    char m[200], l[240]; va_list ap;
    va_start(ap, fmt); vsnprintf(m, sizeof m, fmt, ap); va_end(ap);
    snprintf(l, sizeof l, "input: %s", m); log_line(l);
    if (!g_cfg.show_status || !g_attached) return;
    EnterCriticalSection(&g_cs);
    snprintf(g_notice, sizeof g_notice, "%s", m); g_notice_pending = 1;
    LeaveCriticalSection(&g_cs);
}
static void apply_notice(void) {
    if (g_notice_pending && g_hwnd) {
        char t[300];
        EnterCriticalSection(&g_cs); snprintf(t, sizeof t, "%s - %s", g_title_base, g_notice); g_notice_pending = 0; LeaveCriticalSection(&g_cs);
        SetWindowTextA(g_hwnd, t); g_notice_until = GetTickCount() + 3500;
    } else if (g_notice_until && (int)(GetTickCount() - g_notice_until) > 0) { SetWindowTextA(g_hwnd, g_title_base); g_notice_until = 0; }
}
static void clip_to_client(void) {
    RECT r; POINT a, b;
    GetClientRect(g_hwnd, &r); a.x = r.left; a.y = r.top; b.x = r.right; b.y = r.bottom;
    ClientToScreen(g_hwnd, &a); ClientToScreen(g_hwnd, &b);
    r.left = a.x; r.top = a.y; r.right = b.x; r.bottom = b.y;
    ClipCursor(&r);
}
static void do_capture(void) {
    if (g_captured || !g_hwnd || IsIconic(g_hwnd)) return;
    g_captured = 1; clip_to_client(); SetCursor(NULL);
    inpdev_set_mouse_mode(2);
    notice("Mouse captured (Esc or F1 releases it)");
}
static void do_release(int say) {
    if (!g_captured) return;
    g_captured = 0; ClipCursor(NULL); SetCursor(LoadCursorA(NULL, MAKEINTRESOURCEA(32512)));
    inpdev_set_mouse_mode(g_mouse_player >= 0 && g_cfg.mouse_capture != MC_OFF ? 1 : 0);
    if (say) notice("Mouse released (click or F1 captures it again)");
}
static void capture_update(void) {
    int focused, want = 0, mode;
    if (!g_hwnd) return;
    focused = (GetForegroundWindow() == g_hwnd) && !IsIconic(g_hwnd) && !g_modal;
    if (g_mouse_player >= 0 && g_cfg.mouse_capture != MC_OFF && focused && !g_off) {
        int ctx = game_context();
        if (g_cfg.mouse_capture == MC_AUTO) want = !g_user_released && (ctx != 0);       /* captured while a level runs (or when the context cannot be told) */
        else want = g_click_captured;
    }
    if (want && !g_captured) do_capture(); else if (!want && g_captured) do_release(0);
    if (g_captured) clip_to_client();                                                      /* follows moves and resizes */
    mode = g_captured ? 2 : ((g_mouse_player >= 0 && g_cfg.mouse_capture != MC_OFF && !g_off) ? 1 : 0);
    inpdev_set_mouse_mode(mode);
    if (!focused && g_cfg.mouse_capture == MC_CLICK) g_click_captured = 0;
}
static void toggle_capture(void) {
    if (g_mouse_player < 0 || g_cfg.mouse_capture == MC_OFF) { notice("No mouse assigned to a player"); return; }
    if (g_captured) { g_user_released = 1; g_click_captured = 0; do_release(1); }
    else { g_user_released = 0; g_click_captured = 1; capture_update(); if (!g_captured && g_cfg.mouse_capture == MC_AUTO) notice("The mouse is captured while a level is running"); }
}
static int on_escape(void) {                       /* returns 1 when the key was consumed */
    if (g_captured) { g_user_released = 1; g_click_captured = 0; do_release(1); return 1; }
    if (g_cfg.esc_mode == ESC_QUIT) return 0;
    if (g_cfg.esc_mode == ESC_IGNORE) return 1;
    if (g_esc_armed && (int)(GetTickCount() - g_esc_tick) < 2500) return 0;               /* second press: let the window procedure quit */
    g_esc_armed = 1; g_esc_tick = GetTickCount(); notice("Press Esc again to quit");
    return 1;
}
static void report_devices(void) {
    int i, p; DevPadInfo pi; char b[300];
    snprintf(b, sizeof b, "input: config %s (%s), mouse player %d, captured=%d, context=%d", g_cfg_path, g_cfg_have ? "loaded" : "defaults", g_mouse_player + 1, g_captured, game_context()); log_line(b);
    for (i = 0; i < inpdev_pad_slots(); i++) if (inpdev_pad_info(i, &pi) && pi.connected) { snprintf(b, sizeof b, "input: pad %d: %s%s%s", i, pi.name, pi.guid[0] ? " " : "", pi.guid); log_line(b); }
    for (p = 0; p < MAX_PLAYERS; p++) {
        const PlayerCfg *pc = &g_cfg.player[p];
        snprintf(b, sizeof b, "input: player %d: keyboard=%d mouse=%d pads=%d connected=%d", p + 1, pc->use_keyboard, pc->use_mouse, g_nassign[p], input_port_connected(p)); log_line(b);
    }
    notice("Device report written to the log");
}

static LRESULT CALLBACK main_proc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
    case WM_KEYDOWN: case WM_KEYUP:
        if (w == VK_ESCAPE || w == VK_F1 || w == VK_F2 || w == VK_F3) {
            if (m == WM_KEYDOWN && !(l & 0x40000000)) {
                if (w == VK_ESCAPE) { if (!on_escape()) break; }
                else if (w == VK_F1) toggle_capture();
                else if (w == VK_F2) reload_config(1);
                else report_devices();
            }
            return 0;
        }
        break;
    case WM_SETCURSOR:
        if (g_captured && LOWORD(l) == HTCLIENT) { SetCursor(NULL); return TRUE; }
        break;
    case WM_ACTIVATE:
        if (LOWORD(w) == WA_INACTIVE) { do_release(0); g_click_captured = 0; }
        break;
    case WM_KILLFOCUS: do_release(0); break;
    case WM_SIZE: case WM_MOVE: if (g_captured) clip_to_client(); break;
    case WM_ENTERSIZEMOVE: case WM_ENTERMENULOOP: g_modal = 1; capture_update(); break;
    case WM_EXITSIZEMOVE: case WM_EXITMENULOOP: g_modal = 0; capture_update(); break;
    case WM_LBUTTONDOWN: case WM_RBUTTONDOWN: case WM_MBUTTONDOWN: case WM_XBUTTONDOWN:
        if (!g_captured && g_mouse_player >= 0 && g_cfg.mouse_capture != MC_OFF) {            /* a click captures the mouse (and is not game input) */
            int wasfree = g_cfg.mouse_capture == MC_CLICK || g_user_released;
            if (wasfree) { g_user_released = 0; g_click_captured = 1; capture_update(); if (g_captured) inpdev_suppress_mouse(); }
        }
        break;
    case WM_TIMER:
        if (w == TIMER_ID) {
            static int n, ginit; static unsigned gen;
            if (!ginit) { ginit = 1; gen = inpdev_pad_generation(); }
            capture_update();
            if (++n % 10 == 0 && g_cfg.hot_reload) reload_config(0);
            if (gen != inpdev_pad_generation()) { gen = inpdev_pad_generation(); EnterCriticalSection(&g_cs); refresh_assign(); LeaveCriticalSection(&g_cs); notice("Gamepads changed"); }
            if (g_motor_tick && (int)(GetTickCount() - g_motor_tick) > 500) { int c; g_motor_tick = 0; for (c = 0; c < MAX_PLAYERS; c++) if (g_motor[c].ch == c) { g_motor[c].level = g_motor[c].target = 0; motor_apply(c); } }
            apply_notice();
            return 0;
        }
        break;
    case WM_DESTROY:
        do_release(0); KillTimer(h, TIMER_ID);
        { int c; for (c = 0; c < MAX_PLAYERS; c++) if (g_motor[c].ch == c) { g_motor[c].level = 0; motor_apply(c); } }
        break;
    }
    return CallWindowProcA(g_old_proc, h, m, w, l);
}
static void at_exit_release(void) { ClipCursor(NULL); }

void input_attach(void *hwnd) {
    ensure_init();
    if (g_attached || !hwnd) return;
    g_hwnd = (HWND)hwnd; g_attached = 1;
    GetWindowTextA(g_hwnd, g_title_base, sizeof g_title_base);
    g_old_proc = (WNDPROC)SetWindowLongPtrA(g_hwnd, GWLP_WNDPROC, (LONG_PTR)main_proc);
    SetTimer(g_hwnd, TIMER_ID, 50, NULL);
    atexit(at_exit_release);
    inpdev_set_background(g_cfg.background_input);
    if (!g_off) { inpdev_start(g_hwnd); inpdev_set_mouse_mode(g_mouse_player >= 0 ? 1 : 0); }
    { char b[200]; snprintf(b, sizeof b, "input: attached to the window (config %s; hotkeys F1 mouse, F2 reload, F3 report, Esc release/quit)", g_cfg_path); log_line(b); }
}
