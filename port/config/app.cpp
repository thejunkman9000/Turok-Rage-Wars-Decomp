// turok_controls.exe - mapping tool of the Turok: Rage Wars PC port.  Native Win32 + common controls + GDI, no libraries besides the system DLLs (static CRT).
// Reads and writes controls.ini (the same file, parser and mapping engine as the game: port\input_core.c, device layer port\input_dev.c).
//   turok_controls.exe [--config file.ini] [--player 1..4|general] [--select <N64 input>] [--capture]
//   turok_controls.exe --selftest [--out file]   |   --devices [--out file]   |   --write-default file.ini
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "diagram.h"
extern "C" {
#include "../input_core.h"
#include "../input_dev.h"
int input_core_selftest(void);
}
#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "advapi32.lib")

#define WM_WM_UI_TICK 1
static int g_dpi = 96;
static int S(int v) { return MulDiv(v, g_dpi, 96); }

// ------------------------------------------------------------------ text helpers
static const wchar_t *W(const char *s) {            // ANSI (the core's names are ASCII, DirectInput names are ANSI) -> UTF-16, rotating buffers
    static wchar_t buf[8][512]; static int n; wchar_t *b = buf[n++ & 7];
    MultiByteToWideChar(CP_ACP, 0, s, -1, b, 512); b[511] = 0; return b;
}
static void toA(const wchar_t *w, char *out, int cap) { WideCharToMultiByte(CP_ACP, 0, w, -1, out, cap, NULL, NULL); out[cap - 1] = 0; }

static const wchar_t *kInputTitle[IN_COUNT] = {
    L"A  (weapon wheel / next weapon, confirm)", L"B  (secondary fire, back)", L"Z  (primary fire)", L"Start  (pause)",
    L"D-Pad Up", L"D-Pad Down", L"D-Pad Left", L"D-Pad Right", L"L  (shoulder, unused in the Normal config)", L"R  (jump)",
    L"C-Up  (move forward)", L"C-Down  (move back)", L"C-Left  (move left)", L"C-Right  (move right)",
    L"Stick Left  (turn left)", L"Stick Right  (turn right)", L"Stick Up  (look up)", L"Stick Down  (look down)" };
static const wchar_t *kInputShort[IN_COUNT] = { L"A", L"B", L"Z", L"Start", L"D-Up", L"D-Down", L"D-Left", L"D-Right", L"L", L"R", L"C-Up", L"C-Down", L"C-Left", L"C-Right", L"Stick Left", L"Stick Right", L"Stick Up", L"Stick Down" };

// ------------------------------------------------------------------ controls
enum {
    IDC_TAB = 100, IDC_DIAGRAM, IDC_CAPTION, IDC_LV_INPUTS, IDC_LV_SOURCES, IDC_BTN_BIND, IDC_BTN_ADD, IDC_BTN_CLEAR, IDC_BTN_REMOVE, IDC_CB_CONTEXT, IDC_BTN_STICK,
    IDC_GRP_DEV, IDC_CHK_KB, IDC_CHK_MOUSE, IDC_LBL_KBL, IDC_CB_KBLAYOUT, IDC_BTN_KBAPPLY, IDC_LBL_PAD, IDC_CB_PAD, IDC_LBL_PADL, IDC_CB_PADLAYOUT, IDC_BTN_PADAPPLY,
    IDC_GRP_SENS, IDC_SL_FIRST = 200,      // 6 sliders: IDC_SL_FIRST + i, labels IDC_SLL_FIRST + i, values IDC_SLV_FIRST + i
    IDC_SLL_FIRST = 220, IDC_SLV_FIRST = 240, IDC_CHK_INVMOUSE = 260, IDC_CHK_INVSTICK,
    IDC_GRP_TEST = 270, IDC_PREVIEW, IDC_TESTTEXT, IDC_RAD_GAME, IDC_RAD_MENU, IDC_TESTNOTE,
    IDC_BTN_RESET = 300, IDC_BTN_COPY, IDC_BTN_IMPORT, IDC_BTN_EXPORT, IDC_BTN_LAUNCH, IDC_BTN_SAVE, IDC_BTN_CLOSE, IDC_STATUS, IDC_BTN_CANCELCAP,
    IDC_GEN_MCAP_L = 320, IDC_GEN_MCAP, IDC_GEN_GUARD, IDC_GEN_ESC_L, IDC_GEN_ESC, IDC_GEN_RUMBLE, IDC_GEN_RSL, IDC_GEN_RSV, IDC_GEN_BG, IDC_GEN_HOT, IDC_GEN_STATUS, IDC_GEN_DEVLBL, IDC_LV_DEVICES, IDC_GEN_HELP, IDC_GEN_G1, IDC_GEN_G2, IDC_GEN_G3,
    IDM_COPY_FIRST = 400, IDM_STICK_FIRST = 420, IDM_IMPORT_ALL = 440, IDM_IMPORT_ONE = 441
};
#define N_SLIDERS 6

struct SliderDef { const wchar_t *name; float lo, hi, step; };
static const SliderDef kSliders[N_SLIDERS] = {
    { L"Mouse sensitivity X", 0.1f, 5.0f, 0.05f }, { L"Mouse sensitivity Y", 0.1f, 5.0f, 0.05f }, { L"Stick dead zone", 0.0f, 0.8f, 0.01f },
    { L"Stick sensitivity", 0.25f, 2.5f, 0.05f }, { L"Stick response curve", 0.5f, 3.0f, 0.05f }, { L"Trigger threshold", 0.05f, 0.95f, 0.01f } };

struct Capture {
    bool active; int input; bool append; unsigned char prevKeys[256]; unsigned prevMb; PadState basePad[DEV_MAX_PADS]; float mx, my; DWORD start;
};

struct Snapshot {                       // one poll of all devices (shared by the capture and the live test)
    unsigned char keys[256]; unsigned mb; float dx, dy; int wheel[4]; PadState pad[DEV_MAX_PADS]; DevPadInfo info[DEV_MAX_PADS]; int npads;
};

struct App {
    HINSTANCE inst; HWND hwnd, tab, diagram, caption, status, preview;
    HFONT font, bold; HBRUSH capBrush;
    ControlsCfg cfg, saved; char path[MAX_PATH]; bool fileExists;
    int page;                           // 0..3 = player, 4 = general
    int sel;                            // selected N64 input
    Capture cap; Snapshot snap; MapState map[MAX_PLAYERS]; LARGE_INTEGER lastTick, qpf;
    N64Pad out; unsigned peakUntil; int peakX, peakY; unsigned gen;
    HWND lvInputs, lvSources, cbContext, cbPad, cbKbLayout, cbPadLayout, chkKb, chkMouse, chkInvMouse, chkInvStick, testText, radGame, radMenu;
    HWND slider[N_SLIDERS], sliderVal[N_SLIDERS];
    HWND gMcap, gGuard, gEsc, gRumble, gRumbleSl, gRumbleVal, gBg, gHot, gStatus, lvDevices;
    HWND pageCtl[64]; int nPageCtl; HWND genCtl[32]; int nGenCtl;
    bool updating;
    int padSel[8];                      // combo index -> pad table index (-1 none, -2 auto)
    int padCount;
    wchar_t statusText[400]; int statusLevel; DWORD start;
};
static App A;
static wchar_t g_shotPath[MAX_PATH]; static wchar_t g_shotReq[MAX_PATH]; static int g_shotDelay = 1500;      // --shot / TUROK_CONTROLS_SHOTREQ (testing aids)
static bool shotTo(const wchar_t *path);

// ------------------------------------------------------------------ small UI helpers
static HWND mk(const wchar_t *cls, const wchar_t *text, DWORD style, int id, int x, int y, int w, int h, DWORD ex = 0) {
    HWND c = CreateWindowExW(ex, cls, text, WS_CHILD | WS_VISIBLE | style, S(x), S(y), S(w), S(h), A.hwnd, (HMENU)(INT_PTR)id, A.inst, NULL);
    SendMessageW(c, WM_SETFONT, (WPARAM)A.font, TRUE);
    return c;
}
static void addPage(HWND c) { if (A.nPageCtl < 64) A.pageCtl[A.nPageCtl++] = c; }
static void addGen(HWND c) { if (A.nGenCtl < 32) A.genCtl[A.nGenCtl++] = c; }
static PlayerCfg &P() { return A.cfg.player[A.page < MAX_PLAYERS ? A.page : 0]; }
static int curPlayer() { return A.page < MAX_PLAYERS ? A.page : 0; }

static void setStatus(const wchar_t *t, int level = 0) { wcsncpy_s(A.statusText, t, _TRUNCATE); A.statusLevel = level; InvalidateRect(A.status, NULL, TRUE); SetWindowTextW(A.status, t); }
static float sliderToValue(int i, int pos) { const SliderDef &d = kSliders[i]; return d.lo + pos * d.step; }
static int valueToSlider(int i, float v) { const SliderDef &d = kSliders[i]; int p = (int)((v - d.lo) / d.step + 0.5f); int mx = (int)((d.hi - d.lo) / d.step + 0.5f); return p < 0 ? 0 : p > mx ? mx : p; }

static void formatBinding(const Binding &b, wchar_t *out, int cap) {
    out[0] = 0;
    if (!b.n) { wcsncpy_s(out, cap, L"(nothing)", _TRUNCATE); return; }
    for (int i = 0; i < b.n; i++) {
        char t[96]; src_describe(&b.s[i], t, sizeof t);
        if (i) wcsncat_s(out, cap, L",  ", _TRUNCATE);
        wcsncat_s(out, cap, W(t), _TRUNCATE);
    }
}

// ------------------------------------------------------------------ config file
static void logCfg(void *, int line, const char *msg) { (void)line; (void)msg; }
static void resolvePath(const wchar_t *argPath) {
    wchar_t env[MAX_PATH], exe[MAX_PATH], full[MAX_PATH];
    if (argPath && argPath[0]) { GetFullPathNameW(argPath, MAX_PATH, full, NULL); toA(full, A.path, MAX_PATH); return; }
    if (GetEnvironmentVariableW(L"TUROK_CONTROLS", env, MAX_PATH)) { GetFullPathNameW(env, MAX_PATH, full, NULL); toA(full, A.path, MAX_PATH); return; }
    GetModuleFileNameW(NULL, exe, MAX_PATH); wchar_t *sl = wcsrchr(exe, L'\\'); if (sl) *sl = 0;
    swprintf_s(full, L"%s\\controls.ini", exe); toA(full, A.path, MAX_PATH);
}
static void loadConfig() {
    int r = cfg_load(&A.cfg, A.path, logCfg, NULL);
    A.fileExists = (r != -2);
    if (r == -2) cfg_defaults(&A.cfg);
    A.saved = A.cfg;
}
static bool dirty() { return !cfg_equal(&A.cfg, &A.saved); }
static void updateTitle() {
    wchar_t t[600]; swprintf_s(t, L"Turok: Rage Wars - Controls%s  [%s]", dirty() ? L" *" : L"", W(A.path));
    SetWindowTextW(A.hwnd, t); EnableWindow(GetDlgItem(A.hwnd, IDC_BTN_SAVE), dirty() || !A.fileExists);
}
static bool saveConfig() {
    int r = cfg_save(&A.cfg, A.path);
    if (r != 0) { wchar_t m[300]; swprintf_s(m, L"Could not write %s (error %d)", W(A.path), r); setStatus(m, 2); return false; }
    A.saved = A.cfg; A.fileExists = true; updateTitle();
    wchar_t m[300]; swprintf_s(m, L"Saved %s - a running game picks the change up by itself (or press F2 in the game).", W(A.path)); setStatus(m, 0);
    return true;
}

// ------------------------------------------------------------------ devices
static void pollDevices(Snapshot &s) {
    memset(&s, 0, sizeof s);
    inpdev_read_kbm(s.keys, &s.mb, &s.dx, &s.dy, s.wheel);
    s.npads = inpdev_pad_slots(); if (s.npads > DEV_MAX_PADS) s.npads = DEV_MAX_PADS;
    for (int i = 0; i < s.npads; i++) {
        memset(&s.info[i], 0, sizeof s.info[i]);
        if (!inpdev_pad_info(i, &s.info[i]) || !s.info[i].connected) { s.pad[i].connected = 0; continue; }
        inpdev_pad_poll(i, &s.pad[i]);
    }
}
static void padLabel(const DevPadInfo &pi, wchar_t *out, int cap) {
    if (pi.is_xinput) swprintf_s(out, cap, L"XInput %d: %s", pi.slot + 1, W(pi.name));
    else swprintf_s(out, cap, L"DirectInput: %s", W(pi.name));
}
static void fillPadCombo() {
    ComboBox_ResetContent(A.cbPad); A.padCount = 0;
    ComboBox_AddString(A.cbPad, L"None (no gamepad for this player)"); A.padSel[A.padCount++] = -1;
    ComboBox_AddString(A.cbPad, L"Automatic (the first free gamepad)"); A.padSel[A.padCount++] = -2;
    for (int i = 0; i < inpdev_pad_slots() && A.padCount < 8; i++) {
        DevPadInfo pi; if (!inpdev_pad_info(i, &pi) || !pi.connected) continue;
        wchar_t t[160]; padLabel(pi, t, 160); ComboBox_AddString(A.cbPad, t); A.padSel[A.padCount++] = i;
    }
    // the configured pad when it is not connected right now
    PlayerCfg &p = P(); int sel = 0;
    if (p.npads == 0) sel = 0;
    else if (p.pad[0].kind == PS_AUTO) sel = 1;
    else {
        sel = -1;
        for (int k = 2; k < A.padCount; k++) {
            DevPadInfo pi; inpdev_pad_info(A.padSel[k], &pi);
            if ((p.pad[0].kind == PS_XINPUT && pi.is_xinput && pi.slot == p.pad[0].index) || ((p.pad[0].kind == PS_DI_GUID) && !_stricmp(pi.guid, p.pad[0].text))) { sel = k; break; }
        }
        if (sel < 0 && A.padCount < 8) { char t[100]; padspec_format(&p.pad[0], t, sizeof t); wchar_t w[160]; swprintf_s(w, L"(not connected) %s", W(t)); ComboBox_AddString(A.cbPad, w); A.padSel[A.padCount] = -3; sel = A.padCount++; }
        if (sel < 0) sel = 1;
    }
    ComboBox_SetCurSel(A.cbPad, sel);
}
static void fillDeviceList() {
    ListView_DeleteAllItems(A.lvDevices);
    int row = 0;
    LVITEMW it = {}; it.mask = LVIF_TEXT;
    it.iItem = row; it.pszText = const_cast<wchar_t *>(L"Keyboard"); ListView_InsertItem(A.lvDevices, &it); ListView_SetItemText(A.lvDevices, row, 1, const_cast<wchar_t *>(L"keyboard")); ListView_SetItemText(A.lvDevices, row, 2, const_cast<wchar_t *>(L"always present (Raw Input, physical key positions)")); row++;
    it.iItem = row; it.pszText = const_cast<wchar_t *>(L"Mouse"); ListView_InsertItem(A.lvDevices, &it); ListView_SetItemText(A.lvDevices, row, 1, const_cast<wchar_t *>(L"mouse")); ListView_SetItemText(A.lvDevices, row, 2, const_cast<wchar_t *>(L"always present (Raw Input, unaccelerated)")); row++;
    for (int i = 0; i < inpdev_pad_slots(); i++) {
        DevPadInfo pi; if (!inpdev_pad_info(i, &pi) || !pi.connected) continue;
        it.iItem = row; it.pszText = (LPWSTR)W(pi.name); ListView_InsertItem(A.lvDevices, &it);
        wchar_t t[200];
        ListView_SetItemText(A.lvDevices, row, 1, const_cast<wchar_t *>(pi.is_xinput ? L"XInput gamepad" : L"DirectInput gamepad"));
        if (pi.is_xinput) swprintf_s(t, L"slot %d, config name  xinput:%d%s", pi.slot + 1, pi.slot + 1, pi.has_rumble ? L", rumble" : L"");
        else swprintf_s(t, L"%s  (vid %04X pid %04X, %s layout)", W(pi.guid), pi.vid, pi.pid, pi.std_known ? L"known" : L"guessed Xbox-style");
        ListView_SetItemText(A.lvDevices, row, 2, t); row++;
    }
}

// ------------------------------------------------------------------ UI <-> config
static void refreshInputs() {
    PlayerCfg &p = P(); wchar_t t[400];
    for (int i = 0; i < IN_COUNT; i++) { formatBinding(p.bind[i], t, 400); ListView_SetItemText(A.lvInputs, i, 1, t); }
}
static void refreshSources() {
    ListView_DeleteAllItems(A.lvSources);
    if (A.sel < 0) return;
    PlayerCfg &p = P(); const Binding &b = p.bind[A.sel];
    for (int i = 0; i < b.n; i++) {
        char t[96]; src_describe(&b.s[i], t, sizeof t);
        LVITEMW it = {}; it.mask = LVIF_TEXT; it.iItem = i; it.pszText = (LPWSTR)W(t); ListView_InsertItem(A.lvSources, &it);
    }
}
static void refreshConflicts(DiagramState *ds) {
    Conflict c[64]; int n = cfg_conflicts(&P(), c, 64);
    memset(ds->conflict, 0, sizeof ds->conflict);
    wchar_t msg[400] = L"";
    for (int i = 0; i < n && i < 64; i++) { ds->conflict[c[i].in_a] = 1; ds->conflict[c[i].in_b] = 1; }
    if (n > 0) {
        char t[96]; src_describe(&c[0].src, t, sizeof t);
        swprintf_s(msg, L"Warning: %s is bound to both %s and %s%s", W(t), kInputShort[c[0].in_a], kInputShort[c[0].in_b], n > 1 ? L" (and more conflicts)" : L"");
    }
    if (A.page < MAX_PLAYERS && !n) {
        CrossConflict x[16]; int m = cfg_cross_conflicts(&A.cfg, x, 16);
        for (int i = 0; i < m && i < 16; i++) if (x[i].player_a == A.page || x[i].player_b == A.page) {
            char t[96]; src_describe(&x[i].src, t, sizeof t);
            swprintf_s(msg, L"Warning: players %d and %d share the keyboard and both use %s", x[i].player_a + 1, x[i].player_b + 1, W(t)); n = 1; break;
        }
    }
    if (n > 0) setStatus(msg, 1);
    else if (A.statusLevel == 1) setStatus(L"", 0);
}
static void refreshDiagramBounds() {
    DiagramState ds; memset(&ds, 0, sizeof ds); PlayerCfg &p = P();
    for (int i = 0; i < IN_COUNT; i++) ds.bound[i] = (unsigned char)p.bind[i].n;
    refreshConflicts(&ds);
    ds.selected = A.sel; ds.buttons = A.out.buttons; ds.stickX = A.out.x; ds.stickY = A.out.y;
    Diagram_SetState(A.diagram, ds);
}
static void fillCaption(int input) {
    wchar_t t[700];
    if (input < 0) { SetWindowTextW(A.caption, L"Click a button of the controller, or select an input in the list.  Double-click (or Bind) to assign it, Add for an extra binding."); return; }
    wchar_t b[500]; formatBinding(P().bind[input], b, 500);
    swprintf_s(t, L"%s:  %s", kInputTitle[input], b);
    SetWindowTextW(A.caption, t);
}
static void uiFromCfg() {
    if (A.page >= MAX_PLAYERS) return;
    A.updating = true;
    PlayerCfg &p = P();
    Button_SetCheck(A.chkKb, p.use_keyboard ? BST_CHECKED : BST_UNCHECKED); Button_SetCheck(A.chkMouse, p.use_mouse ? BST_CHECKED : BST_UNCHECKED);
    Button_SetCheck(A.chkInvMouse, p.mouse_invert_y ? BST_CHECKED : BST_UNCHECKED); Button_SetCheck(A.chkInvStick, p.stick_invert_y ? BST_CHECKED : BST_UNCHECKED);
    float vals[N_SLIDERS] = { p.mouse_sens_x, p.mouse_sens_y, p.stick_deadzone, p.stick_sens_x, p.stick_curve, p.trigger_threshold };
    for (int i = 0; i < N_SLIDERS; i++) {
        SendMessageW(A.slider[i], TBM_SETRANGE, TRUE, MAKELONG(0, (int)((kSliders[i].hi - kSliders[i].lo) / kSliders[i].step + 0.5f)));
        SendMessageW(A.slider[i], TBM_SETPOS, TRUE, valueToSlider(i, vals[i]));
        wchar_t t[32]; swprintf_s(t, L"%.2f", vals[i]); SetWindowTextW(A.sliderVal[i], t);
    }
    fillPadCombo();
    refreshInputs(); refreshSources();
    ListView_SetItemState(A.lvInputs, A.sel, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
    fillCaption(A.sel);
    refreshDiagramBounds();
    A.updating = false;
}
static void generalFromCfg() {
    A.updating = true;
    ComboBox_SetCurSel(A.gMcap, A.cfg.mouse_capture); ComboBox_SetCurSel(A.gEsc, A.cfg.esc_mode);
    Button_SetCheck(A.gGuard, A.cfg.mouse_menu_guard); Button_SetCheck(A.gRumble, A.cfg.rumble); Button_SetCheck(A.gBg, A.cfg.background_input); Button_SetCheck(A.gHot, A.cfg.hot_reload); Button_SetCheck(A.gStatus, A.cfg.show_status);
    SendMessageW(A.gRumbleSl, TBM_SETRANGE, TRUE, MAKELONG(0, 100)); SendMessageW(A.gRumbleSl, TBM_SETPOS, TRUE, (int)(A.cfg.rumble_strength * 100 + 0.5f));
    wchar_t t[16]; swprintf_s(t, L"%d %%", (int)(A.cfg.rumble_strength * 100 + 0.5f)); SetWindowTextW(A.gRumbleVal, t);
    fillDeviceList();
    A.updating = false;
}
static void showPage() {
    bool gen = A.page >= MAX_PLAYERS;
    for (int i = 0; i < A.nPageCtl; i++) ShowWindow(A.pageCtl[i], gen ? SW_HIDE : SW_SHOW);
    for (int i = 0; i < A.nGenCtl; i++) ShowWindow(A.genCtl[i], gen ? SW_SHOW : SW_HIDE);
    if (gen) generalFromCfg(); else uiFromCfg();
    updateTitle();
}
static void selectInput(int in, bool fromList = false) {
    if (in < -1 || in >= IN_COUNT) return;
    A.sel = in; if (!fromList && in >= 0) { A.updating = true; ListView_SetItemState(A.lvInputs, in, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED); ListView_EnsureVisible(A.lvInputs, in, FALSE); A.updating = false; }
    refreshSources(); fillCaption(in); refreshDiagramBounds();
}
static void afterBindingChange() { refreshInputs(); refreshSources(); fillCaption(A.sel); refreshDiagramBounds(); updateTitle(); }

// ------------------------------------------------------------------ capture ("press the input")
static RECT cancelScreenRect() { RECT r = {}; HWND b = GetDlgItem(A.hwnd, IDC_BTN_CANCELCAP); GetWindowRect(b, &r); return r; }
static void startCapture(int input, bool append) {
    if (input < 0) { setStatus(L"Select an input first (click it on the controller or in the list).", 1); return; }
    A.sel = input; A.cap.active = true; A.cap.input = input; A.cap.append = append; A.cap.mx = A.cap.my = 0; A.cap.start = GetTickCount();
    Snapshot s; pollDevices(s);
    memcpy(A.cap.prevKeys, s.keys, 256); A.cap.prevMb = s.mb; memcpy(A.cap.basePad, s.pad, sizeof A.cap.basePad);
    wchar_t t[300]; swprintf_s(t, L"  %s  %s:   press a key, click a mouse button, turn the wheel, %suse a gamepad button / stick / trigger        (Esc cancels)", append ? L"ADD" : L"BIND", kInputShort[input], input >= IN_STICK_LEFT ? L"move the mouse a good way, " : L"");
    SetWindowTextW(A.caption, t); ShowWindow(GetDlgItem(A.hwnd, IDC_BTN_CANCELCAP), SW_SHOW); InvalidateRect(A.caption, NULL, TRUE);
    SetFocus(A.hwnd); refreshDiagramBounds();
}
static void endCapture() {
    A.cap.active = false; ShowWindow(GetDlgItem(A.hwnd, IDC_BTN_CANCELCAP), SW_HIDE); InvalidateRect(A.caption, NULL, TRUE); fillCaption(A.sel); refreshDiagramBounds();
}
static void applyCaptured(const Source &src) {
    PlayerCfg &p = P(); Binding &b = p.bind[A.cap.input]; Source s = src; s.ctx = CTX_ANY;
    if (!A.cap.append) memset(&b, 0, sizeof b);
    int r = binding_add(&b, &s);
    char t[96]; src_describe(&s, t, sizeof t); wchar_t m[200];
    if (r < 0) swprintf_s(m, L"Cannot add %s: an input holds at most %d bindings.", W(t), MAX_SRC);
    else swprintf_s(m, L"%s is %s %s.", kInputShort[A.cap.input], r ? L"now bound to" : L"already bound to", W(t));
    setStatus(m, r < 0 ? 1 : 0);
    endCapture(); afterBindingChange();
}
static void captureTick(const Snapshot &s) {
    Source found; bool got = false;
    if (s.keys[0x01] && !A.cap.prevKeys[0x01]) { setStatus(L"Capture cancelled.", 0); endCapture(); return; }
    for (int k = 0; k < 256 && !got; k++) {
        if (!s.keys[k] || A.cap.prevKeys[k] || k == 0x01 || k == 0xDB || k == 0xDC) continue;
        memset(&found, 0, sizeof found); found.type = SRC_KEY; found.id = (unsigned short)k; got = true;
    }
    memcpy(A.cap.prevKeys, s.keys, 256);
    if (!got) {
        POINT pt; GetCursorPos(&pt); RECT cr = cancelScreenRect(); bool overCancel = PtInRect(&cr, pt) != 0;
        unsigned nb = s.mb & ~A.cap.prevMb; A.cap.prevMb = s.mb;
        for (int b = 0; b < 5 && !got && !overCancel; b++) if (nb & (1u << b)) { memset(&found, 0, sizeof found); found.type = SRC_MBTN; found.id = (unsigned short)b; got = true; }
    }
    if (!got) for (int d = 0; d < 4 && !got; d++) if (s.wheel[d]) { memset(&found, 0, sizeof found); found.type = SRC_WHEEL; found.id = (unsigned short)d; got = true; }
    if (!got && A.cap.input >= IN_STICK_LEFT) {      // mouse motion is only offered for the stick directions (a moving hand must not bind a button), after a short grace period
        if (GetTickCount() - A.cap.start > 500) {
            A.cap.mx += s.dx; A.cap.my += s.dy;
            if (fabsf(A.cap.mx) > 500 && fabsf(A.cap.mx) >= fabsf(A.cap.my)) { memset(&found, 0, sizeof found); found.type = SRC_MAXIS; found.id = 0; found.sign = (signed char)(A.cap.mx > 0 ? 1 : -1); got = true; }
            else if (fabsf(A.cap.my) > 500) { memset(&found, 0, sizeof found); found.type = SRC_MAXIS; found.id = 1; found.sign = (signed char)(A.cap.my > 0 ? 1 : -1); got = true; }
        }
    }
    if (!got) for (int i = 0; i < s.npads && !got; i++) {
        if (!s.pad[i].connected) continue;
        bool raw = !s.info[i].is_xinput && !s.info[i].std_known;
        if (pad_detect_source(&A.cap.basePad[i], &s.pad[i], raw ? 1 : 0, &found)) got = true;
    }
    if (got) applyCaptured(found);
    else if (GetTickCount() - A.cap.start > 30000) { setStatus(L"Capture timed out.", 0); endCapture(); }
}

// ------------------------------------------------------------------ live test
static void liveTick(const Snapshot &s, double dt) {
    if (A.page >= MAX_PLAYERS) return;
    PlayerCfg &p = P(); InputSample in; memset(&in, 0, sizeof in);
    in.keys = s.keys; in.mouse_buttons = s.mb; in.mouse_dx = s.dx; in.mouse_dy = s.dy; for (int d = 0; d < 4; d++) in.wheel[d] = s.wheel[d];
    in.mouse_valid = GetForegroundWindow() == A.hwnd; in.dt = dt;
    in.gameplay = Button_GetCheck(A.radMenu) == BST_CHECKED ? 0 : 1;
    // the pads this player would use: the configured one, or any free pad for "automatic"
    const PadState *pads[MAX_PADS_PER_PLAYER]; int np = 0;
    for (int k = 0; k < p.npads && np < MAX_PADS_PER_PLAYER; k++) {
        for (int i = 0; i < s.npads && np < MAX_PADS_PER_PLAYER; i++) {
            if (!s.pad[i].connected) continue;
            const DevPadInfo &pi = s.info[i]; bool match = false;
            if (p.pad[k].kind == PS_AUTO) match = true;
            else if (p.pad[k].kind == PS_XINPUT) match = pi.is_xinput && pi.slot == p.pad[k].index;
            else if (p.pad[k].kind == PS_DI_GUID) match = !_stricmp(pi.guid, p.pad[k].text);
            else if (p.pad[k].kind == PS_DI_NAME) match = strstr(pi.name, p.pad[k].text) != NULL;
            else if (p.pad[k].kind == PS_DI_INDEX) match = !pi.is_xinput;
            if (match) pads[np++] = &s.pad[i];
        }
        if (p.pad[k].kind == PS_AUTO) break;
    }
    in.npad = np; for (int i = 0; i < np; i++) in.pad[i] = pads[i];
    N64Pad o; map_eval(&p, &A.map[curPlayer()], &in, &o);
    unsigned now = GetTickCount();
    if (o.x || o.y) { A.peakX = o.x; A.peakY = o.y; A.peakUntil = now + 250; }                // short peak hold so that a mouse flick stays visible
    int shx = o.x, shy = o.y; if (!o.x && !o.y && now < A.peakUntil) { shx = A.peakX; shy = A.peakY; }
    A.out = o; A.out.x = (signed char)shx; A.out.y = (signed char)shy;
    // text
    wchar_t t[900], b[160] = L"", k[200] = L"", pd[200] = L"";
    static const wchar_t *bn[IN_BUTTONS] = { L"A", L"B", L"Z", L"Start", L"D-Up", L"D-Down", L"D-Left", L"D-Right", L"L", L"R", L"C-Up", L"C-Down", L"C-Left", L"C-Right" };
    for (int i = 0; i < IN_BUTTONS; i++) if (o.buttons & in_button_mask(i)) { if (b[0]) wcscat_s(b, L" "); wcscat_s(b, bn[i]); }
    int nk = 0; for (int i = 0; i < 256 && nk < 6; i++) if (s.keys[i]) { const char *kn = key_name(i); if (kn) { if (k[0]) wcscat_s(k, L" "); wcscat_s(k, W(kn)); nk++; } }
    if (np > 0) { const PadState *ps = pads[0]; swprintf_s(pd, L"LX %.2f  LY %.2f  RX %.2f  RY %.2f  LT %.2f  RT %.2f", ps->axis[PA_LX], ps->axis[PA_LY], ps->axis[PA_RX], ps->axis[PA_RY], ps->axis[PA_LT], ps->axis[PA_RT]); }
    else wcscpy_s(pd, L"no gamepad for this player");
    swprintf_s(t, L"N64 stick:  x = %d   y = %d\r\nN64 buttons:  %s\r\n\r\nKeys down:  %s\r\nMouse:  buttons %02X   move %+.0f %+.0f   wheel %+d\r\nGamepad:  %s", (int)A.out.x, (int)A.out.y, b[0] ? b : L"-", k[0] ? k : L"-", s.mb, s.dx, s.dy, s.wheel[0] - s.wheel[1], pd);
    wchar_t cur[900]; GetWindowTextW(A.testText, cur, 900); if (wcscmp(cur, t)) SetWindowTextW(A.testText, t);
    DiagramState ds; memset(&ds, 0, sizeof ds); for (int i = 0; i < IN_COUNT; i++) ds.bound[i] = (unsigned char)p.bind[i].n;
    Conflict c[64]; int n = cfg_conflicts(&p, c, 64); for (int i = 0; i < n && i < 64; i++) { ds.conflict[c[i].in_a] = 1; ds.conflict[c[i].in_b] = 1; }
    ds.selected = A.sel; ds.buttons = o.buttons; ds.stickX = A.out.x; ds.stickY = A.out.y;
    Diagram_SetState(A.diagram, ds);
    InvalidateRect(A.preview, NULL, FALSE);
}
static LRESULT CALLBACK previewProc(HWND h, UINT m, WPARAM w, LPARAM l) {       // the round stick preview
    if (m == WM_ERASEBKGND) return 1;
    if (m == WM_PAINT || m == WM_PRINTCLIENT) {
        PAINTSTRUCT ps; HDC wdc; RECT rc; GetClientRect(h, &rc);
        if (m == WM_PRINTCLIENT) wdc = (HDC)w; else wdc = BeginPaint(h, &ps);
        HDC dc = CreateCompatibleDC(wdc); HBITMAP bmp = CreateCompatibleBitmap(wdc, rc.right, rc.bottom); HGDIOBJ ob = SelectObject(dc, bmp);
        FillRect(dc, &rc, GetSysColorBrush(COLOR_WINDOW));
        int cx = rc.right / 2, cy = rc.bottom / 2, R = (rc.right < rc.bottom ? rc.right : rc.bottom) / 2 - S(6);
        HPEN pen = CreatePen(PS_SOLID, 1, RGB(150, 150, 158)); HGDIOBJ op = SelectObject(dc, pen); HBRUSH nb = (HBRUSH)GetStockObject(NULL_BRUSH); HGDIOBJ obr = SelectObject(dc, nb);
        Ellipse(dc, cx - R, cy - R, cx + R, cy + R);
        // the game's own thresholds: dead zone 3 and the 30 that makes the stick press a direction in the menus
        int r3 = R * 3 / 80, r30 = R * 30 / 80; Ellipse(dc, cx - r30, cy - r30, cx + r30, cy + r30); Ellipse(dc, cx - r3, cy - r3, cx + r3, cy + r3);
        MoveToEx(dc, cx - R, cy, NULL); LineTo(dc, cx + R, cy); MoveToEx(dc, cx, cy - R, NULL); LineTo(dc, cx, cy + R);
        SelectObject(dc, op); SelectObject(dc, obr); DeleteObject(pen);
        int px = cx + A.out.x * R / 80, py = cy - A.out.y * R / 80;
        HBRUSH br = CreateSolidBrush((A.out.x || A.out.y) ? RGB(60, 150, 255) : RGB(170, 170, 178)); HGDIOBJ obb = SelectObject(dc, br);
        Ellipse(dc, px - S(7), py - S(7), px + S(7), py + S(7)); SelectObject(dc, obb); DeleteObject(br);
        BitBlt(wdc, 0, 0, rc.right, rc.bottom, dc, 0, 0, SRCCOPY); SelectObject(dc, ob); DeleteObject(bmp); DeleteDC(dc); if (m == WM_PAINT) EndPaint(h, &ps); return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

// ------------------------------------------------------------------ game launch
static bool findGame(wchar_t *exeOut, wchar_t *workDir) {
    wchar_t dir[MAX_PATH], pat[MAX_PATH]; GetModuleFileNameW(NULL, dir, MAX_PATH); wchar_t *sl = wcsrchr(dir, L'\\'); if (sl) *sl = 0;
    exeOut[0] = 0;
    swprintf_s(pat, L"%s\\turok.exe", dir);
    if (GetFileAttributesW(pat) != INVALID_FILE_ATTRIBUTES) wcscpy_s(exeOut, MAX_PATH, pat);
    else {                                             // development tree: port\build\latest_exe.txt, else the newest turok_*.exe (not this tool)
        swprintf_s(pat, L"%s\\latest_exe.txt", dir); FILE *f = _wfopen(pat, L"r");
        if (f) { char line[MAX_PATH]; if (fgets(line, sizeof line, f)) { char *e = line + strlen(line); while (e > line && (e[-1] == '\n' || e[-1] == '\r' || e[-1] == ' ')) *--e = 0; wchar_t rel[MAX_PATH]; MultiByteToWideChar(CP_ACP, 0, line, -1, rel, MAX_PATH);
                 const wchar_t *base = wcsrchr(rel, L'\\'); swprintf_s(pat, L"%s\\%s", dir, base ? base + 1 : rel); if (GetFileAttributesW(pat) != INVALID_FILE_ATTRIBUTES) wcscpy_s(exeOut, MAX_PATH, pat); } fclose(f); }
        if (!exeOut[0]) {
            WIN32_FIND_DATAW fd; swprintf_s(pat, L"%s\\turok_*.exe", dir); HANDLE h = FindFirstFileW(pat, &fd); FILETIME best = {};
            if (h != INVALID_HANDLE_VALUE) { do { if (!_wcsicmp(fd.cFileName, L"turok_controls.exe")) continue; if (CompareFileTime(&fd.ftLastWriteTime, &best) > 0) { best = fd.ftLastWriteTime; swprintf_s(exeOut, MAX_PATH, L"%s\\%s", dir, fd.cFileName); } } while (FindNextFileW(h, &fd)); FindClose(h); }
        }
    }
    if (!exeOut[0]) return false;
    // the game reads baserom.us.v11.z64 from its working directory: search upwards from the exe folder
    wchar_t d[MAX_PATH]; wcscpy_s(d, dir);
    for (int up = 0; up < 5; up++) {
        wchar_t rom[MAX_PATH]; swprintf_s(rom, L"%s\\baserom.us.v11.z64", d);
        if (GetFileAttributesW(rom) != INVALID_FILE_ATTRIBUTES) { wcscpy_s(workDir, MAX_PATH, d); return true; }
        wchar_t *s2 = wcsrchr(d, L'\\'); if (!s2) break; *s2 = 0;
    }
    wcscpy_s(workDir, MAX_PATH, dir); return true;
}
static void launchGame() {
    if (dirty() || !A.fileExists) { if (!saveConfig()) return; }
    wchar_t exe[MAX_PATH], wd[MAX_PATH];
    if (!findGame(exe, wd)) { MessageBoxW(A.hwnd, L"The game executable (turok.exe) was not found next to this program.", L"Launch game", MB_ICONWARNING); return; }
    wchar_t cmd[MAX_PATH + 4]; swprintf_s(cmd, L"\"%s\"", exe);
    wchar_t env[MAX_PATH]; (void)env;
    SetEnvironmentVariableW(L"TUROK_CONTROLS", NULL);                                      // the game finds the same file next to its exe; a custom path is passed on
    if (_stricmp(A.path, "") != 0) { wchar_t pw[MAX_PATH]; MultiByteToWideChar(CP_ACP, 0, A.path, -1, pw, MAX_PATH); SetEnvironmentVariableW(L"TUROK_CONTROLS", pw); }
    STARTUPINFOW si = { sizeof si }; PROCESS_INFORMATION pi = {};
    if (CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, wd, &si, &pi)) { CloseHandle(pi.hThread); CloseHandle(pi.hProcess); setStatus(L"Game started.", 0); }
    else { wchar_t m[400]; swprintf_s(m, L"Could not start %s (error %lu)", exe, GetLastError()); setStatus(m, 2); }
}

// ------------------------------------------------------------------ commands
static void applyLayout(bool pad) {
    HWND cb = pad ? A.cbPadLayout : A.cbKbLayout; int sel = ComboBox_GetCurSel(cb);
    if (sel <= 0) { setStatus(L"Choose a layout in the list first.", 1); return; }
    // the combo lists the profiles of one family in the order of the table
    int seen = 0; const char *name = NULL;
    for (int i = 0; i < cfg_profile_count(); i++) if (cfg_profile_family(i) == (pad ? FAM_PAD : FAM_KBM)) { if (++seen == sel) { name = cfg_profile_name(i); break; } }
    if (!name) return;
    cfg_apply_profile(&P(), name, 0);
    wchar_t m[200]; swprintf_s(m, L"Applied the %s layout (%s).", W(name), pad ? L"gamepad" : L"keyboard and mouse"); setStatus(m, 0);
    afterBindingChange();
}
static void copyFrom(int from) {
    if (from == curPlayer()) return;
    PlayerCfg own = P();                                    // the devices belong to the seat, not to the layout: the destination keeps its own
    cfg_copy_player(&P(), &A.cfg.player[from], 0);
    P().use_keyboard = own.use_keyboard; P().use_mouse = own.use_mouse; P().npads = own.npads; memcpy(P().pad, own.pad, sizeof P().pad);
    wchar_t m[140]; swprintf_s(m, L"Copied the bindings and settings of player %d to player %d (its devices are unchanged).", from + 1, curPlayer() + 1); setStatus(m, 0);
    uiFromCfg(); updateTitle();
}
static bool askOpen(wchar_t *file) {
    OPENFILENAMEW o = { sizeof o }; file[0] = 0; o.hwndOwner = A.hwnd; o.lpstrFilter = L"Controls files (*.ini)\0*.ini\0All files\0*.*\0"; o.lpstrFile = file; o.nMaxFile = MAX_PATH; o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
    return GetOpenFileNameW(&o) != 0;
}
static bool askSave(wchar_t *file) {
    OPENFILENAMEW o = { sizeof o }; wcscpy_s(file, MAX_PATH, L"controls_export.ini"); o.hwndOwner = A.hwnd; o.lpstrFilter = L"Controls files (*.ini)\0*.ini\0All files\0*.*\0"; o.lpstrFile = file; o.nMaxFile = MAX_PATH; o.lpstrDefExt = L"ini"; o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
    return GetSaveFileNameW(&o) != 0;
}
static void importFile() {
    wchar_t f[MAX_PATH]; if (!askOpen(f)) return;
    char fa[MAX_PATH]; toA(f, fa, MAX_PATH); ControlsCfg in;
    int r = cfg_load(&in, fa, logCfg, NULL);
    if (r < 0) { MessageBoxW(A.hwnd, L"That file is not a usable controls file.", L"Import", MB_ICONWARNING); return; }
    HMENU m = CreatePopupMenu(); wchar_t t[120];
    AppendMenuW(m, MF_STRING, IDM_IMPORT_ALL, L"Import everything (all players and the general settings)");
    if (A.page < MAX_PLAYERS) { swprintf_s(t, L"Import only player %d of the file into player %d", curPlayer() + 1, curPlayer() + 1); AppendMenuW(m, MF_STRING, IDM_IMPORT_ONE, t); }
    RECT rc; GetWindowRect(GetDlgItem(A.hwnd, IDC_BTN_IMPORT), &rc);
    int cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_LEFTALIGN | TPM_BOTTOMALIGN, rc.left, rc.top, 0, A.hwnd, NULL); DestroyMenu(m);
    if (cmd == IDM_IMPORT_ALL) A.cfg = in; else if (cmd == IDM_IMPORT_ONE) cfg_copy_player(&P(), &in.player[curPlayer()], 0); else return;
    setStatus(L"Imported - press Save to keep it.", 0); showPage();
}
static void exportFile() {
    wchar_t f[MAX_PATH]; if (!askSave(f)) return;
    char fa[MAX_PATH]; toA(f, fa, MAX_PATH);
    if (cfg_save(&A.cfg, fa) == 0) { wchar_t m[400]; swprintf_s(m, L"Exported to %s.", f); setStatus(m, 0); } else setStatus(L"Export failed.", 2);
}
static void stickPresets() {
    HMENU m = CreatePopupMenu();
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 0, L"Mouse look");
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 1, L"Gamepad right stick");
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 2, L"Gamepad left stick");
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 3, L"Arrow keys");
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 4, L"W A S D");
    AppendMenuW(m, MF_STRING, IDM_STICK_FIRST + 5, L"I J K L");
    RECT rc; GetWindowRect(GetDlgItem(A.hwnd, IDC_BTN_STICK), &rc);
    int cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_LEFTALIGN | TPM_TOPALIGN, rc.left, rc.bottom, 0, A.hwnd, NULL); DestroyMenu(m);
    if (cmd < IDM_STICK_FIRST || cmd > IDM_STICK_FIRST + 5) return;
    static const char *const names[6][4] = {
        { "MouseX-", "MouseX+", "MouseY-", "MouseY+" }, { "Pad.RX-", "Pad.RX+", "Pad.RY+", "Pad.RY-" }, { "Pad.LX-", "Pad.LX+", "Pad.LY+", "Pad.LY-" },
        { "Left", "Right", "Up", "Down" }, { "A", "D", "W", "S" }, { "J", "L", "I", "K" } };
    const char *const *n = names[cmd - IDM_STICK_FIRST];
    PlayerCfg &p = P();
    for (int d = 0; d < 4; d++) { Source s; if (src_parse(n[d], &s)) { Binding &b = p.bind[IN_STICK_LEFT + d]; memset(&b, 0, sizeof b); binding_add(&b, &s); } }
    setStatus(L"The stick directions were set to the chosen source (each replaces the old bindings of that direction).", 0);
    afterBindingChange();
}
static void resetDefaults() {
    if (A.page >= MAX_PLAYERS) { ControlsCfg d; cfg_defaults(&d); A.cfg.mouse_capture = d.mouse_capture; A.cfg.esc_mode = d.esc_mode; A.cfg.rumble = d.rumble; A.cfg.rumble_strength = d.rumble_strength; A.cfg.background_input = d.background_input; A.cfg.hot_reload = d.hot_reload; A.cfg.mouse_menu_guard = d.mouse_menu_guard; A.cfg.show_status = d.show_status; generalFromCfg(); updateTitle(); setStatus(L"General settings reset to the defaults.", 0); return; }
    wchar_t q[200]; swprintf_s(q, L"Reset player %d to the built-in defaults (devices, bindings and sensitivity)?", curPlayer() + 1);
    if (MessageBoxW(A.hwnd, q, L"Reset to defaults", MB_YESNO | MB_ICONQUESTION) != IDYES) return;
    cfg_player_defaults(&P(), curPlayer()); uiFromCfg(); updateTitle(); setStatus(L"Reset to the defaults.", 0);
}
static void copyMenu() {
    HMENU m = CreatePopupMenu(); wchar_t t[100];
    for (int i = 0; i < MAX_PLAYERS; i++) { if (i == curPlayer()) continue; swprintf_s(t, L"Copy bindings and settings from player %d", i + 1); AppendMenuW(m, MF_STRING, IDM_COPY_FIRST + i, t); }
    RECT rc; GetWindowRect(GetDlgItem(A.hwnd, IDC_BTN_COPY), &rc);
    int cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_LEFTALIGN | TPM_BOTTOMALIGN, rc.left, rc.top, 0, A.hwnd, NULL); DestroyMenu(m);
    if (cmd >= IDM_COPY_FIRST && cmd < IDM_COPY_FIRST + MAX_PLAYERS) copyFrom(cmd - IDM_COPY_FIRST);
}
static void removeSelectedSource() {
    int row = ListView_GetNextItem(A.lvSources, -1, LVNI_SELECTED); if (row < 0 || A.sel < 0) return;
    Binding &b = P().bind[A.sel]; if (row >= b.n) return;
    for (int i = row; i < b.n - 1; i++) b.s[i] = b.s[i + 1];
    memset(&b.s[b.n - 1], 0, sizeof b.s[0]); b.n--; afterBindingChange();
}
static void setContextOfSelected() {
    int row = ListView_GetNextItem(A.lvSources, -1, LVNI_SELECTED); if (row < 0 || A.sel < 0) return;
    Binding &b = P().bind[A.sel]; if (row >= b.n) return;
    int c = ComboBox_GetCurSel(A.cbContext); if (c < 0) return; b.s[row].ctx = (unsigned char)c;
    afterBindingChange(); ListView_SetItemState(A.lvSources, row, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}

// ------------------------------------------------------------------ window
static void sliderChanged(int i) {
    if (A.updating || A.page >= MAX_PLAYERS) return;
    int pos = (int)SendMessageW(A.slider[i], TBM_GETPOS, 0, 0); float v = sliderToValue(i, pos); PlayerCfg &p = P();
    switch (i) { case 0: p.mouse_sens_x = v; break; case 1: p.mouse_sens_y = v; break; case 2: p.stick_deadzone = v; break; case 3: p.stick_sens_x = p.stick_sens_y = v; break; case 4: p.stick_curve = v; break; case 5: p.trigger_threshold = v; break; }
    wchar_t t[32]; swprintf_s(t, L"%.2f", v); SetWindowTextW(A.sliderVal[i], t); updateTitle();
}
static void createControls() {
    A.tab = mk(WC_TABCONTROLW, L"", WS_TABSTOP | WS_CLIPSIBLINGS, IDC_TAB, 8, 6, 1084, 612);
    TCITEMW ti = {}; ti.mask = TCIF_TEXT; const wchar_t *tabs[5] = { L"  Player 1  ", L"  Player 2  ", L"  Player 3  ", L"  Player 4  ", L"  General && devices  " };
    for (int i = 0; i < 5; i++) { ti.pszText = const_cast<wchar_t *>(tabs[i]); TabCtrl_InsertItem(A.tab, i, &ti); }
    // ---- player page: diagram, caption, lists
    A.diagram = Diagram_Create(A.hwnd, IDC_DIAGRAM, S(16), S(38), S(488), S(314)); addPage(A.diagram);
    A.caption = mk(L"STATIC", L"", SS_NOPREFIX | SS_LEFT, IDC_CAPTION, 16, 356, 488, 32); addPage(A.caption);
    A.lvInputs = mk(WC_LISTVIEWW, L"", LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | WS_TABSTOP, IDC_LV_INPUTS, 16, 392, 296, 222, WS_EX_CLIENTEDGE); addPage(A.lvInputs);
    ListView_SetExtendedListViewStyle(A.lvInputs, LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER);
    { LVCOLUMNW c = {}; c.mask = LVCF_TEXT | LVCF_WIDTH; c.cx = S(72); c.pszText = const_cast<wchar_t *>(L"N64 input"); ListView_InsertColumn(A.lvInputs, 0, &c); c.cx = S(206); c.pszText = const_cast<wchar_t *>(L"Bound to"); ListView_InsertColumn(A.lvInputs, 1, &c); }
    for (int i = 0; i < IN_COUNT; i++) { LVITEMW it = {}; it.mask = LVIF_TEXT; it.iItem = i; it.pszText = const_cast<wchar_t *>(kInputShort[i]); ListView_InsertItem(A.lvInputs, &it); }
    A.lvSources = mk(WC_LISTVIEWW, L"", LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | LVS_NOCOLUMNHEADER | WS_TABSTOP, IDC_LV_SOURCES, 320, 392, 184, 100, WS_EX_CLIENTEDGE); addPage(A.lvSources);
    ListView_SetExtendedListViewStyle(A.lvSources, LVS_EX_FULLROWSELECT);
    { LVCOLUMNW c = {}; c.mask = LVCF_WIDTH; c.cx = S(166); ListView_InsertColumn(A.lvSources, 0, &c); }
    addPage(mk(L"STATIC", L"Active:", 0, 0, 320, 500, 42, 18));
    A.cbContext = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_CB_CONTEXT, 364, 496, 140, 120); addPage(A.cbContext);
    ComboBox_AddString(A.cbContext, L"Always"); ComboBox_AddString(A.cbContext, L"In free play only"); ComboBox_AddString(A.cbContext, L"In menus / pause only");
    addPage(mk(L"BUTTON", L"Bind...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_BIND, 320, 526, 90, 26));
    addPage(mk(L"BUTTON", L"Add...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_ADD, 414, 526, 90, 26));
    addPage(mk(L"BUTTON", L"Clear", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_CLEAR, 320, 556, 90, 26));
    addPage(mk(L"BUTTON", L"Remove", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_REMOVE, 414, 556, 90, 26));
    addPage(mk(L"BUTTON", L"Stick presets...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_STICK, 320, 588, 184, 26));
    // ---- devices
    addPage(mk(L"BUTTON", L" Devices of this player ", BS_GROUPBOX, IDC_GRP_DEV, 516, 32, 576, 140));
    A.chkKb = mk(L"BUTTON", L"Keyboard", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_CHK_KB, 528, 52, 90, 22); addPage(A.chkKb);
    addPage(mk(L"STATIC", L"Layout:", 0, IDC_LBL_KBL, 626, 55, 50, 18));
    A.cbKbLayout = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_CB_KBLAYOUT, 680, 50, 316, 140); addPage(A.cbKbLayout);
    addPage(mk(L"BUTTON", L"Apply", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_KBAPPLY, 1004, 49, 78, 26));
    A.chkMouse = mk(L"BUTTON", L"Mouse (look = N64 stick, buttons, wheel)", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_CHK_MOUSE, 528, 80, 400, 22); addPage(A.chkMouse);
    addPage(mk(L"STATIC", L"Gamepad:", 0, IDC_LBL_PAD, 528, 112, 62, 18));
    A.cbPad = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_CB_PAD, 594, 108, 488, 160); addPage(A.cbPad);
    addPage(mk(L"STATIC", L"Layout:", 0, IDC_LBL_PADL, 528, 142, 50, 18));
    A.cbPadLayout = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_CB_PADLAYOUT, 594, 138, 400, 140); addPage(A.cbPadLayout);
    addPage(mk(L"BUTTON", L"Apply", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_PADAPPLY, 1004, 137, 78, 26));
    ComboBox_AddString(A.cbKbLayout, L"(choose a layout, then Apply)"); ComboBox_AddString(A.cbPadLayout, L"(choose a layout, then Apply)");
    for (int i = 0; i < cfg_profile_count(); i++) { wchar_t t[200]; wcsncpy_s(t, W(cfg_profile_title(i)), _TRUNCATE); ComboBox_AddString(cfg_profile_family(i) == FAM_PAD ? A.cbPadLayout : A.cbKbLayout, t); }
    ComboBox_SetCurSel(A.cbKbLayout, 0); ComboBox_SetCurSel(A.cbPadLayout, 0);
    // ---- sensitivity
    addPage(mk(L"BUTTON", L" Sensitivity and dead zones ", BS_GROUPBOX, IDC_GRP_SENS, 516, 176, 576, 178));
    for (int i = 0; i < N_SLIDERS; i++) {
        int y = 194 + i * 22;
        addPage(mk(L"STATIC", kSliders[i].name, 0, IDC_SLL_FIRST + i, 528, y + 2, 150, 18));
        A.slider[i] = mk(TRACKBAR_CLASSW, L"", TBS_HORZ | TBS_NOTICKS | WS_TABSTOP, IDC_SL_FIRST + i, 682, y, 340, 22); addPage(A.slider[i]);
        A.sliderVal[i] = mk(L"STATIC", L"", SS_RIGHT, IDC_SLV_FIRST + i, 1030, y + 2, 50, 18); addPage(A.sliderVal[i]);
    }
    A.chkInvMouse = mk(L"BUTTON", L"Invert mouse Y", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_CHK_INVMOUSE, 528, 328, 150, 20); addPage(A.chkInvMouse);
    A.chkInvStick = mk(L"BUTTON", L"Invert gamepad stick Y", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_CHK_INVSTICK, 700, 328, 200, 20); addPage(A.chkInvStick);
    // ---- live test
    addPage(mk(L"BUTTON", L" Test (live) ", BS_GROUPBOX, IDC_GRP_TEST, 516, 358, 576, 256));
    A.preview = CreateWindowExW(WS_EX_CLIENTEDGE, L"N64StickPreview", L"", WS_CHILD | WS_VISIBLE, S(528), S(378), S(150), S(150), A.hwnd, (HMENU)(INT_PTR)IDC_PREVIEW, A.inst, NULL); addPage(A.preview);
    A.testText = mk(L"STATIC", L"", SS_LEFT | SS_NOPREFIX, IDC_TESTTEXT, 690, 378, 394, 150); addPage(A.testText);
    A.radGame = mk(L"BUTTON", L"Test as: free play", BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP, IDC_RAD_GAME, 528, 534, 150, 20); addPage(A.radGame);
    A.radMenu = mk(L"BUTTON", L"menus / pause", BS_AUTORADIOBUTTON, IDC_RAD_MENU, 690, 534, 130, 20); addPage(A.radMenu);
    Button_SetCheck(A.radGame, BST_CHECKED);
    addPage(mk(L"STATIC", L"Press keys, move the mouse or use a gamepad here: the diagram, the circle (its inner rings are the game's dead zone 3 and the menu threshold 30) and the values show what the game would receive.", 0, IDC_TESTNOTE, 528, 560, 556, 48));
    // ---- general page
    addGen(mk(L"BUTTON", L" Mouse and keyboard ", BS_GROUPBOX, IDC_GEN_G1, 16, 36, 520, 150));
    addGen(mk(L"STATIC", L"Mouse capture:", 0, IDC_GEN_MCAP_L, 30, 64, 110, 18));
    A.gMcap = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_GEN_MCAP, 146, 60, 376, 120); addGen(A.gMcap);
    ComboBox_AddString(A.gMcap, L"Automatic: captured while a level runs"); ComboBox_AddString(A.gMcap, L"On click (F1 / Esc release)"); ComboBox_AddString(A.gMcap, L"Off: no mouse look");
    A.gGuard = mk(L"BUTTON", L"Mouse motion only moves the stick during free play (not in menus)", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_GEN_GUARD, 30, 92, 490, 20); addGen(A.gGuard);
    addGen(mk(L"STATIC", L"Esc key in the game:", 0, IDC_GEN_ESC_L, 30, 128, 120, 18));
    A.gEsc = mk(L"COMBOBOX", L"", CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL, IDC_GEN_ESC, 156, 124, 366, 120); addGen(A.gEsc);
    ComboBox_AddString(A.gEsc, L"Release the mouse; press twice to quit"); ComboBox_AddString(A.gEsc, L"Quit at once (the old behaviour)"); ComboBox_AddString(A.gEsc, L"Never quit");
    addGen(mk(L"BUTTON", L" Gamepads ", BS_GROUPBOX, IDC_GEN_G2, 16, 194, 520, 108));
    A.gRumble = mk(L"BUTTON", L"Rumble: vibrate XInput gamepads for the game's Rumble Pak", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_GEN_RUMBLE, 30, 216, 490, 20); addGen(A.gRumble);
    addGen(mk(L"STATIC", L"Strength:", 0, IDC_GEN_RSL, 30, 250, 70, 18));
    A.gRumbleSl = mk(TRACKBAR_CLASSW, L"", TBS_HORZ | TBS_NOTICKS | WS_TABSTOP, IDC_GEN_RSL + 1, 106, 246, 340, 24); addGen(A.gRumbleSl);
    A.gRumbleVal = mk(L"STATIC", L"", SS_RIGHT, IDC_GEN_RSV, 452, 250, 70, 18); addGen(A.gRumbleVal);
    A.gBg = mk(L"BUTTON", L"Keep reading devices while the game window is in the background", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_GEN_BG, 30, 274, 490, 20); addGen(A.gBg);
    addGen(mk(L"BUTTON", L" The game ", BS_GROUPBOX, IDC_GEN_G3, 16, 310, 520, 84));
    A.gHot = mk(L"BUTTON", L"Reload controls.ini automatically when it changes (F2 reloads at once)", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_GEN_HOT, 30, 332, 500, 20); addGen(A.gHot);
    A.gStatus = mk(L"BUTTON", L"Show short notices in the game's window title", BS_AUTOCHECKBOX | WS_TABSTOP, IDC_GEN_STATUS, 30, 358, 500, 20); addGen(A.gStatus);
    addGen(mk(L"STATIC", L"Detected input devices (updated when a gamepad is plugged in or removed):", 0, IDC_GEN_DEVLBL, 552, 40, 530, 18));
    A.lvDevices = mk(WC_LISTVIEWW, L"", LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | WS_TABSTOP, IDC_LV_DEVICES, 552, 62, 538, 332, WS_EX_CLIENTEDGE); addGen(A.lvDevices);
    ListView_SetExtendedListViewStyle(A.lvDevices, LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER);
    { LVCOLUMNW c = {}; c.mask = LVCF_TEXT | LVCF_WIDTH; c.cx = S(150); c.pszText = const_cast<wchar_t *>(L"Device"); ListView_InsertColumn(A.lvDevices, 0, &c); c.cx = S(120); c.pszText = const_cast<wchar_t *>(L"Type"); ListView_InsertColumn(A.lvDevices, 1, &c); c.cx = S(250); c.pszText = const_cast<wchar_t *>(L"Details"); ListView_InsertColumn(A.lvDevices, 2, &c); }
    addGen(mk(L"STATIC", L"Hotkeys in the game:  F1 captures / releases the mouse,  F2 reloads this file,  F3 prints the device report to the log,  Esc releases the mouse (press twice to quit).\r\n\r\nKeys are bound by their physical position on a US keyboard, so W A S D stay under the same fingers on AZERTY and QWERTZ keyboards.  Player 1 is always present; players 2-4 appear in the game while one of their devices (keyboard, mouse or gamepad) is assigned and available.  One gamepad or the mouse serves one player; the keyboard can be shared by giving each player a different layout.\r\n\r\nFor mouse aiming turn LOOK SPRING off in the game (Options > Player Options): with it on the view returns to the centre when the mouse stops.  The game's CONTROL STICK HORZ / VERT sliders set the fastest turn rate the mouse can reach.", SS_LEFT | SS_NOPREFIX, IDC_GEN_HELP, 16, 404, 1074, 206));
    // ---- bottom bar
    A.status = mk(L"STATIC", L"", SS_LEFT | SS_NOPREFIX, IDC_STATUS, 12, 624, 1076, 20);
    mk(L"BUTTON", L"Reset to defaults", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_RESET, 12, 648, 130, 28);
    mk(L"BUTTON", L"Copy from...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_COPY, 148, 648, 110, 28);
    mk(L"BUTTON", L"Import...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_IMPORT, 264, 648, 100, 28);
    mk(L"BUTTON", L"Export...", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_EXPORT, 370, 648, 100, 28);
    mk(L"BUTTON", L"Cancel capture", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_CANCELCAP, 480, 648, 110, 28);
    mk(L"BUTTON", L"Launch game", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_LAUNCH, 760, 648, 110, 28);
    mk(L"BUTTON", L"Save", BS_DEFPUSHBUTTON | WS_TABSTOP, IDC_BTN_SAVE, 880, 648, 100, 28);
    mk(L"BUTTON", L"Close", BS_PUSHBUTTON | WS_TABSTOP, IDC_BTN_CLOSE, 988, 648, 100, 28);
    ShowWindow(GetDlgItem(A.hwnd, IDC_BTN_CANCELCAP), SW_HIDE);
}

static void onCommand(int id, int code, HWND ctl) {
    (void)ctl;
    if (A.updating) return;
    switch (id) {
    case IDC_BTN_BIND: if (A.sel < 0) setStatus(L"Select an input first.", 1); else startCapture(A.sel, false); break;
    case IDC_BTN_ADD: if (A.sel < 0) setStatus(L"Select an input first.", 1); else startCapture(A.sel, true); break;
    case IDC_BTN_CANCELCAP: setStatus(L"Capture cancelled.", 0); endCapture(); break;
    case IDC_BTN_CLEAR: if (A.sel >= 0) { memset(&P().bind[A.sel], 0, sizeof P().bind[0]); afterBindingChange(); } break;
    case IDC_BTN_REMOVE: removeSelectedSource(); break;
    case IDC_CB_CONTEXT: if (code == CBN_SELCHANGE) setContextOfSelected(); break;
    case IDC_BTN_STICK: stickPresets(); break;
    case IDC_CHK_KB: P().use_keyboard = Button_GetCheck(A.chkKb) == BST_CHECKED; updateTitle(); refreshDiagramBounds(); break;
    case IDC_CHK_MOUSE: P().use_mouse = Button_GetCheck(A.chkMouse) == BST_CHECKED; updateTitle(); break;
    case IDC_CHK_INVMOUSE: P().mouse_invert_y = Button_GetCheck(A.chkInvMouse) == BST_CHECKED; updateTitle(); break;
    case IDC_CHK_INVSTICK: P().stick_invert_y = Button_GetCheck(A.chkInvStick) == BST_CHECKED; updateTitle(); break;
    case IDC_BTN_KBAPPLY: applyLayout(false); break;
    case IDC_BTN_PADAPPLY: applyLayout(true); break;
    case IDC_CB_PAD: if (code == CBN_SELCHANGE) {
            int sel = ComboBox_GetCurSel(A.cbPad); if (sel < 0 || sel >= A.padCount) break; PlayerCfg &p = P(); int k = A.padSel[sel];
            if (k == -1) p.npads = 0;
            else if (k == -2) { p.npads = 1; memset(&p.pad[0], 0, sizeof p.pad[0]); p.pad[0].kind = PS_AUTO; }
            else if (k >= 0) { DevPadInfo pi; if (inpdev_pad_info(k, &pi)) { p.npads = 1; memset(&p.pad[0], 0, sizeof p.pad[0]); if (pi.is_xinput) { p.pad[0].kind = PS_XINPUT; p.pad[0].index = pi.slot; } else { p.pad[0].kind = PS_DI_GUID; strncpy_s(p.pad[0].text, pi.guid, _TRUNCATE); } } }
            updateTitle(); } break;
    case IDC_RAD_GAME: case IDC_RAD_MENU: break;
    case IDC_BTN_RESET: resetDefaults(); break;
    case IDC_BTN_COPY: if (A.page < MAX_PLAYERS) copyMenu(); break;
    case IDC_BTN_IMPORT: importFile(); break;
    case IDC_BTN_EXPORT: exportFile(); break;
    case IDC_BTN_LAUNCH: launchGame(); break;
    case IDC_BTN_SAVE: saveConfig(); break;
    case IDC_BTN_CLOSE: PostMessageW(A.hwnd, WM_CLOSE, 0, 0); break;
    case IDC_GEN_MCAP: if (code == CBN_SELCHANGE) { A.cfg.mouse_capture = ComboBox_GetCurSel(A.gMcap); updateTitle(); } break;
    case IDC_GEN_ESC: if (code == CBN_SELCHANGE) { A.cfg.esc_mode = ComboBox_GetCurSel(A.gEsc); updateTitle(); } break;
    case IDC_GEN_GUARD: A.cfg.mouse_menu_guard = Button_GetCheck(A.gGuard) == BST_CHECKED; updateTitle(); break;
    case IDC_GEN_RUMBLE: A.cfg.rumble = Button_GetCheck(A.gRumble) == BST_CHECKED; updateTitle(); break;
    case IDC_GEN_BG: A.cfg.background_input = Button_GetCheck(A.gBg) == BST_CHECKED; updateTitle(); break;
    case IDC_GEN_HOT: A.cfg.hot_reload = Button_GetCheck(A.gHot) == BST_CHECKED; updateTitle(); break;
    case IDC_GEN_STATUS: A.cfg.show_status = Button_GetCheck(A.gStatus) == BST_CHECKED; updateTitle(); break;
    }
}

static LRESULT CALLBACK wndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    switch (m) {
    case WM_CREATE: A.hwnd = h; return 0;
    case WM_COMMAND: onCommand(LOWORD(w), HIWORD(w), (HWND)l); return 0;
    case WM_NOTIFY: {
        NMHDR *n = (NMHDR *)l;
        if (n->idFrom == IDC_TAB && n->code == TCN_SELCHANGE) { A.page = TabCtrl_GetCurSel(A.tab); if (A.cap.active) endCapture(); showPage(); }
        else if (n->idFrom == IDC_LV_INPUTS) {
            if (n->code == LVN_ITEMCHANGED) { NMLISTVIEW *nl = (NMLISTVIEW *)l; if (!A.updating && (nl->uChanged & LVIF_STATE) && (nl->uNewState & LVIS_SELECTED)) selectInput(nl->iItem, true); }
            else if (n->code == NM_DBLCLK) { NMITEMACTIVATE *ia = (NMITEMACTIVATE *)l; if (ia->iItem >= 0) startCapture(ia->iItem, false); }
        } else if (n->idFrom == IDC_LV_SOURCES && n->code == LVN_ITEMCHANGED && !A.updating) {
            NMLISTVIEW *nl = (NMLISTVIEW *)l;
            if ((nl->uChanged & LVIF_STATE) && (nl->uNewState & LVIS_SELECTED) && A.sel >= 0 && nl->iItem < P().bind[A.sel].n) { A.updating = true; ComboBox_SetCurSel(A.cbContext, P().bind[A.sel].s[nl->iItem].ctx); A.updating = false; }
        }
        return 0;
    }
    case WM_HSCROLL: {
        HWND c = (HWND)l;
        for (int i = 0; i < N_SLIDERS; i++) if (c == A.slider[i]) { sliderChanged(i); return 0; }
        if (c == A.gRumbleSl && !A.updating) { int v = (int)SendMessageW(A.gRumbleSl, TBM_GETPOS, 0, 0); A.cfg.rumble_strength = v / 100.0f; wchar_t t[16]; swprintf_s(t, L"%d %%", v); SetWindowTextW(A.gRumbleVal, t); updateTitle(); }
        return 0;
    }
    case WM_DIAGRAM_SELECT: { int v = (int)w; if (v >= 0 && v < IN_COUNT) selectInput(v); return 0; }
    case WM_DIAGRAM_BIND: { int v = (int)w; if (v >= 0 && v < IN_COUNT) { selectInput(v); startCapture(v, false); } return 0; }
    case WM_DIAGRAM_HOVER: { int v = (int)w - 1; if (!A.cap.active) { if (v >= 0) fillCaption(v); else fillCaption(A.sel); } return 0; }
    case WM_CTLCOLORSTATIC: {
        HWND c = (HWND)l; HDC dc = (HDC)w;
        if (c == A.caption && A.cap.active) { SetTextColor(dc, RGB(255, 255, 255)); SetBkColor(dc, RGB(220, 110, 0)); return (LRESULT)A.capBrush; }
        if (c == A.status) { SetBkMode(dc, TRANSPARENT); SetTextColor(dc, A.statusLevel == 2 ? RGB(200, 0, 0) : A.statusLevel == 1 ? RGB(190, 90, 0) : GetSysColor(COLOR_WINDOWTEXT)); return (LRESULT)GetSysColorBrush(COLOR_WINDOW); }
        SetBkMode(dc, TRANSPARENT); return (LRESULT)GetSysColorBrush(COLOR_WINDOW);
    }
    case WM_TIMER: {
        if (w != WM_WM_UI_TICK) break;
        LARGE_INTEGER now; QueryPerformanceCounter(&now); double dt = A.lastTick.QuadPart ? (double)(now.QuadPart - A.lastTick.QuadPart) / (double)A.qpf.QuadPart : 1.0 / 60.0; A.lastTick = now;
        unsigned g = inpdev_pad_generation(); if (g != A.gen) { A.gen = g; if (A.page < MAX_PLAYERS) { A.updating = true; fillPadCombo(); A.updating = false; } else fillDeviceList(); }
        Snapshot s; pollDevices(s);
        if (A.cap.active) captureTick(s); else liveTick(s, dt);
        { static int n; if (g_shotReq[0] && ++n % 15 == 0 && GetFileAttributesW(g_shotReq) != INVALID_FILE_ATTRIBUTES) {      // TUROK_CONTROLS_SHOTREQ=<file>: the file holds the BMP path to write (UI tests)
              FILE *f = NULL; _wfopen_s(&f, g_shotReq, L"r"); wchar_t p2[MAX_PATH] = L""; if (f) { char line[MAX_PATH] = ""; if (fgets(line, sizeof line, f)) { char *e = line + strlen(line); while (e > line && (e[-1] == 10 || e[-1] == 13)) *--e = 0; MultiByteToWideChar(CP_ACP, 0, line, -1, p2, MAX_PATH); } fclose(f); }
              DeleteFileW(g_shotReq); if (p2[0]) shotTo(p2); } }
        if (g_shotPath[0] && (int)(GetTickCount() - A.start) >= g_shotDelay) { shotTo(g_shotPath); g_shotPath[0] = 0; DestroyWindow(h); }
        return 0;
    }
    case WM_CLOSE:
        if (dirty()) {
            int r = MessageBoxW(h, L"Save the changes to the controls before closing?", L"Turok controls", MB_YESNOCANCEL | MB_ICONQUESTION);
            if (r == IDCANCEL) return 0; if (r == IDYES && !saveConfig()) return 0;
        }
        DestroyWindow(h); return 0;
    case WM_DESTROY: KillTimer(h, WM_WM_UI_TICK); PostQuitMessage(0); return 0;
    }
    return DefWindowProcW(h, m, w, l);
}

// ------------------------------------------------------------------ screenshots (testing aid): the whole window rendered with WM_PRINT into a BMP, independent of what else is on the desktop
static bool shotTo(const wchar_t *path) {
    RECT rc; GetWindowRect(A.hwnd, &rc); int w = rc.right - rc.left, h = rc.bottom - rc.top;
    HDC sdc = GetDC(NULL); HDC mem = CreateCompatibleDC(sdc); HBITMAP bmp = CreateCompatibleBitmap(sdc, w, h); HGDIOBJ old = SelectObject(mem, bmp);
    RECT full = { 0, 0, w, h }; FillRect(mem, &full, (HBRUSH)GetStockObject(WHITE_BRUSH));
    SendMessageW(A.hwnd, WM_PRINT, (WPARAM)mem, PRF_CLIENT | PRF_CHILDREN | PRF_NONCLIENT | PRF_ERASEBKGND);
    BITMAPINFO bi = {}; bi.bmiHeader.biSize = sizeof bi.bmiHeader; bi.bmiHeader.biWidth = w; bi.bmiHeader.biHeight = -h; bi.bmiHeader.biPlanes = 1; bi.bmiHeader.biBitCount = 32; bi.bmiHeader.biCompression = BI_RGB;
    unsigned char *px = (unsigned char *)malloc((size_t)w * h * 4); bool ok = false;
    if (px && GetDIBits(mem, bmp, 0, h, px, &bi, DIB_RGB_COLORS)) {
        FILE *f = NULL; _wfopen_s(&f, path, L"wb");
        if (f) {
            BITMAPFILEHEADER fh = {}; fh.bfType = 0x4D42; fh.bfOffBits = sizeof fh + sizeof bi.bmiHeader; fh.bfSize = fh.bfOffBits + w * h * 4;
            fwrite(&fh, sizeof fh, 1, f); fwrite(&bi.bmiHeader, sizeof bi.bmiHeader, 1, f); fwrite(px, 1, (size_t)w * h * 4, f); fclose(f); ok = true;
        }
    }
    free(px); SelectObject(mem, old); DeleteObject(bmp); DeleteDC(mem); ReleaseDC(NULL, sdc);
    return ok;
}
// ------------------------------------------------------------------ command line modes
static int selftest(const wchar_t *out) {
    if (out) { FILE *f = NULL; _wfreopen_s(&f, out, L"w", stdout); }
    int f1 = input_core_selftest(), f2 = inpdev_selftest();
    printf("SELFTEST %s (%d failed)\n", f1 + f2 ? "FAILED" : "PASSED", f1 + f2); fflush(stdout);
    return f1 + f2 ? 1 : 0;
}
static int listDevices(const wchar_t *out) {
    if (out) { FILE *f = NULL; _wfreopen_s(&f, out, L"w", stdout); }
    inpdev_start(NULL); Sleep(1500);
    int n = 0;
    for (int i = 0; i < inpdev_pad_slots(); i++) { DevPadInfo pi; if (!inpdev_pad_info(i, &pi) || !pi.connected) continue; n++; printf("pad %d: %s  [%s %s] vid %04X pid %04X rumble %d\n", i, pi.name, pi.is_xinput ? "XInput" : "DirectInput", pi.guid, pi.vid, pi.pid, pi.has_rumble); }
    printf("%d gamepad(s) connected\n", n); fflush(stdout); inpdev_stop(); return 0;
}

int WINAPI wWinMain(HINSTANCE inst, HINSTANCE, LPWSTR, int show) {
    int argc = 0; wchar_t **argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    const wchar_t *cfgArg = NULL, *outArg = NULL, *playerArg = NULL, *selArg = NULL; bool doSelftest = false, doDevices = false, doCapture = false; const wchar_t *writeDefault = NULL;
    for (int i = 1; i < argc; i++) {
        if (!wcscmp(argv[i], L"--selftest")) doSelftest = true; else if (!wcscmp(argv[i], L"--devices")) doDevices = true; else if (!wcscmp(argv[i], L"--capture")) doCapture = true;
        else if (!wcscmp(argv[i], L"--out") && i + 1 < argc) outArg = argv[++i]; else if (!wcscmp(argv[i], L"--config") && i + 1 < argc) cfgArg = argv[++i];
        else if (!wcscmp(argv[i], L"--player") && i + 1 < argc) playerArg = argv[++i]; else if (!wcscmp(argv[i], L"--select") && i + 1 < argc) selArg = argv[++i];
        else if (!wcscmp(argv[i], L"--write-default") && i + 1 < argc) writeDefault = argv[++i];
        else if (!wcscmp(argv[i], L"--shot") && i + 1 < argc) wcsncpy_s(g_shotPath, argv[++i], _TRUNCATE);
        else if (!wcscmp(argv[i], L"--shot-delay") && i + 1 < argc) g_shotDelay = _wtoi(argv[++i]);
    }
    if (doSelftest) return selftest(outArg);
    if (doDevices) return listDevices(outArg);
    if (writeDefault) { ControlsCfg d; cfg_defaults(&d); char p[MAX_PATH]; toA(writeDefault, p, MAX_PATH); return cfg_save(&d, p) == 0 ? 0 : 1; }
    SetProcessDPIAware();
    HDC sdc = GetDC(NULL); g_dpi = GetDeviceCaps(sdc, LOGPIXELSX); ReleaseDC(NULL, sdc);
    INITCOMMONCONTROLSEX icc = { sizeof icc, ICC_WIN95_CLASSES | ICC_TAB_CLASSES | ICC_BAR_CLASSES | ICC_LISTVIEW_CLASSES | ICC_STANDARD_CLASSES }; InitCommonControlsEx(&icc);
    memset(&A, 0, sizeof A); A.inst = inst; QueryPerformanceFrequency(&A.qpf); A.sel = IN_Z;
    NONCLIENTMETRICSW ncm = { sizeof ncm }; SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, sizeof ncm, &ncm, 0);
    A.font = CreateFontIndirectW(&ncm.lfMessageFont); LOGFONTW lf = ncm.lfMessageFont; lf.lfWeight = FW_BOLD; A.bold = CreateFontIndirectW(&lf);
    A.capBrush = CreateSolidBrush(RGB(220, 110, 0));
    resolvePath(cfgArg); loadConfig();
    Diagram_Register(inst);
    { WNDCLASSW pc = {}; pc.lpfnWndProc = previewProc; pc.hInstance = inst; pc.hCursor = LoadCursorW(NULL, IDC_ARROW); pc.lpszClassName = L"N64StickPreview"; RegisterClassW(&pc); }
    WNDCLASSW wc = {}; wc.lpfnWndProc = wndProc; wc.hInstance = inst; wc.hCursor = LoadCursorW(NULL, IDC_ARROW); wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); wc.lpszClassName = L"TurokControls"; wc.hIcon = LoadIconW(NULL, IDI_APPLICATION);
    RegisterClassW(&wc);
    RECT r = { 0, 0, S(1100), S(684) }; DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX; AdjustWindowRect(&r, style, FALSE);
    RECT wa; SystemParametersInfoW(SPI_GETWORKAREA, 0, &wa, 0);                                   // start centred in the work area, fully on screen
    int ww = r.right - r.left, wh = r.bottom - r.top, wx = wa.left + ((wa.right - wa.left) - ww) / 2, wy = wa.top + ((wa.bottom - wa.top) - wh) / 2;
    if (wx < wa.left) wx = wa.left; if (wy < wa.top) wy = wa.top;
    CreateWindowExW(0, L"TurokControls", L"Turok: Rage Wars - Controls", style | WS_VISIBLE, wx, wy, ww, wh, NULL, NULL, inst, NULL);
    if (!A.hwnd) return 1;
    createControls();
    if (playerArg) { int p = _wtoi(playerArg); if (!_wcsicmp(playerArg, L"general")) A.page = 4; else if (p >= 1 && p <= 4) A.page = p - 1; }
    if (selArg) { char t[40]; toA(selArg, t, sizeof t); int in = in_from_name(t); if (in >= 0) A.sel = in; }
    TabCtrl_SetCurSel(A.tab, A.page);
    inpdev_start(A.hwnd); inpdev_set_mouse_mode(2); A.gen = inpdev_pad_generation();
    showPage(); setStatus(A.fileExists ? L"Click a button on the controller (or an input in the list), then Bind... and press the key / button / stick you want." : L"No controls.ini yet: the built-in defaults are shown.  Change what you like and press Save.", 0);
    if (doCapture && A.page < MAX_PLAYERS) startCapture(A.sel, false);
    GetEnvironmentVariableW(L"TUROK_CONTROLS_SHOTREQ", g_shotReq, MAX_PATH);
    A.start = GetTickCount();
    SetTimer(A.hwnd, WM_WM_UI_TICK, 16, NULL);
    ShowWindow(A.hwnd, show); UpdateWindow(A.hwnd);
    MSG msg; while (GetMessageW(&msg, NULL, 0, 0) > 0) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    inpdev_stop();
    return (int)msg.wParam;
}
