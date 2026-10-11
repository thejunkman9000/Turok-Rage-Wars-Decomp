/* input_core.c - names, controls.ini parser / writer, profiles, defaults and the mapping engine.  No Windows dependency (stdio + math only).
 * See input_core.h.  Unit tests: port\config\input_test.c (built and run by port\build_config.ps1 -Test). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "input_core.h"

/* ------------------------------------------------------------------ small helpers */
static int ci_eq(const char *a, const char *b) {
    for (; *a && *b; a++, b++) { char x = *a, y = *b; if (x >= 'A' && x <= 'Z') x += 32; if (y >= 'A' && y <= 'Z') y += 32; if (x != y) return 0; }
    return *a == *b;
}
static int ci_prefix(const char *s, const char *pre) {       /* s starts with pre (case-insensitive) */
    for (; *pre; s++, pre++) { char x = *s, y = *pre; if (!x) return 0; if (x >= 'A' && x <= 'Z') x += 32; if (y >= 'A' && y <= 'Z') y += 32; if (x != y) return 0; }
    return 1;
}
static void copy_str(char *dst, int cap, const char *src) { int n = (int)strlen(src); if (n >= cap) n = cap - 1; memcpy(dst, src, n); memset(dst + n, 0, cap - n); }
static char *trim(char *s) { char *e; while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++; e = s + strlen(s); while (e > s && (e[-1] == ' ' || e[-1] == '\t' || e[-1] == '\r' || e[-1] == '\n')) *--e = 0; return s; }
static int clampi(int v, int lo, int hi) { return v < lo ? lo : v > hi ? hi : v; }
static float clampf(float v, float lo, float hi) { return v < lo ? lo : v > hi ? hi : v; }

/* ------------------------------------------------------------------ N64 inputs */
static const char *const g_in_names[IN_COUNT] = { "A", "B", "Z", "Start", "DUp", "DDown", "DLeft", "DRight", "L", "R", "CUp", "CDown", "CLeft", "CRight",
                                                   "StickLeft", "StickRight", "StickUp", "StickDown" };
static const unsigned short g_in_mask[IN_BUTTONS] = { N64_BTN_A, N64_BTN_B, N64_BTN_Z, N64_BTN_START, N64_BTN_DUP, N64_BTN_DDOWN, N64_BTN_DLEFT, N64_BTN_DRIGHT,
                                                       N64_BTN_L, N64_BTN_R, N64_BTN_CUP, N64_BTN_CDOWN, N64_BTN_CLEFT, N64_BTN_CRIGHT };
const char *in_name(int in) { return in >= 0 && in < IN_COUNT ? g_in_names[in] : "?"; }
unsigned in_button_mask(int in) { return in >= 0 && in < IN_BUTTONS ? g_in_mask[in] : 0; }
int in_from_name(const char *name) {
    char b[32]; int i, n = 0;
    for (; *name && n < 31; name++) if (*name != '-' && *name != '_' && *name != ' ') b[n++] = *name;
    b[n] = 0;
    for (i = 0; i < IN_COUNT; i++) if (ci_eq(b, g_in_names[i])) return i;
    if (ci_eq(b, "Return")) return IN_START;
    return -1;
}

/* ------------------------------------------------------------------ keys (physical positions of a US keyboard: id = (extended << 7) | scancode) */
static const struct KeyName { const char *name; unsigned char id; } g_keys[] = {
    { "Esc", 0x01 }, { "1", 0x02 }, { "2", 0x03 }, { "3", 0x04 }, { "4", 0x05 }, { "5", 0x06 }, { "6", 0x07 }, { "7", 0x08 }, { "8", 0x09 }, { "9", 0x0A }, { "0", 0x0B },
    { "Minus", 0x0C }, { "Equals", 0x0D }, { "Backspace", 0x0E }, { "Tab", 0x0F },
    { "Q", 0x10 }, { "W", 0x11 }, { "E", 0x12 }, { "R", 0x13 }, { "T", 0x14 }, { "Y", 0x15 }, { "U", 0x16 }, { "I", 0x17 }, { "O", 0x18 }, { "P", 0x19 },
    { "LBracket", 0x1A }, { "RBracket", 0x1B }, { "Enter", 0x1C }, { "LCtrl", 0x1D },
    { "A", 0x1E }, { "S", 0x1F }, { "D", 0x20 }, { "F", 0x21 }, { "G", 0x22 }, { "H", 0x23 }, { "J", 0x24 }, { "K", 0x25 }, { "L", 0x26 },
    { "Semicolon", 0x27 }, { "Quote", 0x28 }, { "Backquote", 0x29 }, { "LShift", 0x2A }, { "Backslash", 0x2B },
    { "Z", 0x2C }, { "X", 0x2D }, { "C", 0x2E }, { "V", 0x2F }, { "B", 0x30 }, { "N", 0x31 }, { "M", 0x32 },
    { "Comma", 0x33 }, { "Period", 0x34 }, { "Slash", 0x35 }, { "RShift", 0x36 }, { "NumMul", 0x37 }, { "LAlt", 0x38 }, { "Space", 0x39 }, { "CapsLock", 0x3A },
    { "F1", 0x3B }, { "F2", 0x3C }, { "F3", 0x3D }, { "F4", 0x3E }, { "F5", 0x3F }, { "F6", 0x40 }, { "F7", 0x41 }, { "F8", 0x42 }, { "F9", 0x43 }, { "F10", 0x44 },
    { "NumLock", 0x45 }, { "ScrollLock", 0x46 },
    { "Num7", 0x47 }, { "Num8", 0x48 }, { "Num9", 0x49 }, { "NumMinus", 0x4A }, { "Num4", 0x4B }, { "Num5", 0x4C }, { "Num6", 0x4D }, { "NumPlus", 0x4E },
    { "Num1", 0x4F }, { "Num2", 0x50 }, { "Num3", 0x51 }, { "Num0", 0x52 }, { "NumDot", 0x53 }, { "IntlBackslash", 0x56 }, { "F11", 0x57 }, { "F12", 0x58 },
    { "NumEnter", 0x9C }, { "RCtrl", 0x9D }, { "NumDiv", 0xB5 }, { "PrintScreen", 0xB7 }, { "RAlt", 0xB8 },
    { "Home", 0xC7 }, { "Up", 0xC8 }, { "PageUp", 0xC9 }, { "Left", 0xCB }, { "Right", 0xCD }, { "End", 0xCF }, { "Down", 0xD0 }, { "PageDown", 0xD1 },
    { "Insert", 0xD2 }, { "Delete", 0xD3 }, { "LWin", 0xDB }, { "RWin", 0xDC }, { "Menu", 0xDD }
};
static const struct KeyName g_key_alias[] = {
    { "Escape", 0x01 }, { "Return", 0x1C }, { "Ctrl", 0x1D }, { "Control", 0x1D }, { "Shift", 0x2A }, { "Alt", 0x38 }, { "Spacebar", 0x39 }, { "Grave", 0x29 }, { "Tilde", 0x29 },
    { "PgUp", 0xC9 }, { "PgDn", 0xD1 }, { "Ins", 0xD2 }, { "Del", 0xD3 }, { "CapsLk", 0x3A }, { "Apostrophe", 0x28 }, { "Dash", 0x0C }, { "Plus", 0x0D },
    { "LeftBracket", 0x1A }, { "RightBracket", 0x1B }, { "Back", 0x0E }, { "NumPeriod", 0x53 }, { "NumAdd", 0x4E }, { "NumSub", 0x4A }, { "NumMultiply", 0x37 }, { "NumDivide", 0xB5 },
    { "UpArrow", 0xC8 }, { "DownArrow", 0xD0 }, { "LeftArrow", 0xCB }, { "RightArrow", 0xCD }
};
#define NKEYS ((int)(sizeof g_keys / sizeof g_keys[0]))
int key_count(void) { return NKEYS; }
int key_id_at(int i) { return i >= 0 && i < NKEYS ? g_keys[i].id : -1; }
const char *key_name(int id) { int i; for (i = 0; i < NKEYS; i++) if (g_keys[i].id == id) return g_keys[i].name; return NULL; }
int key_id_from_name(const char *name) {
    int i;
    for (i = 0; i < NKEYS; i++) if (ci_eq(name, g_keys[i].name)) return g_keys[i].id;
    for (i = 0; i < (int)(sizeof g_key_alias / sizeof g_key_alias[0]); i++) if (ci_eq(name, g_key_alias[i].name)) return g_key_alias[i].id;
    return -1;
}

/* ------------------------------------------------------------------ pad names */
static const char *const g_pb_names[PB_COUNT] = { "A", "B", "X", "Y", "LB", "RB", "Back", "Start", "LS", "RS", "DUp", "DDown", "DLeft", "DRight", "Guide" };
static const char *const g_pa_names[PA_COUNT] = { "LX", "LY", "RX", "RY", "LT", "RT" };
const char *pad_button_name(int pb) { return pb >= 0 && pb < PB_COUNT ? g_pb_names[pb] : "?"; }
const char *pad_axis_name(int pa) { return pa >= 0 && pa < PA_COUNT ? g_pa_names[pa] : "?"; }

/* ------------------------------------------------------------------ sources */
int src_family(const Source *s) { return s->type == SRC_PBTN || s->type == SRC_PAXIS || s->type == SRC_PHAT ? FAM_PAD : FAM_KBM; }
int src_equal(const Source *a, const Source *b) { return a->type == b->type && a->id == b->id && a->sign == b->sign; }
int src_ctx_overlap(const Source *a, const Source *b) { return a->ctx == CTX_ANY || b->ctx == CTX_ANY || a->ctx == b->ctx; }

static int parse_pad_source(const char *t, Source *o) {      /* t is the text after "Pad." */
    int i, n;
    o->type = SRC_PBTN;
    for (i = 0; i < PB_COUNT; i++) if (ci_eq(t, g_pb_names[i])) { o->id = (unsigned short)i; return 1; }
    for (i = 0; i < 4; i++) {                                 /* LX+ LX- LY+ ... */
        int l = (int)strlen(g_pa_names[i]);
        if (ci_prefix(t, g_pa_names[i]) && (t[l] == '+' || t[l] == '-') && t[l + 1] == 0) { o->type = SRC_PAXIS; o->id = (unsigned short)i; o->sign = (signed char)(t[l] == '+' ? 1 : -1); return 1; }
    }
    for (i = PA_LT; i <= PA_RT; i++) {
        int l = (int)strlen(g_pa_names[i]);
        if (ci_prefix(t, g_pa_names[i]) && (t[l] == 0 || (t[l] == '+' && t[l + 1] == 0))) { o->type = SRC_PAXIS; o->id = (unsigned short)i; o->sign = 1; return 1; }
    }
    if (ci_prefix(t, "Btn") && t[3] >= '0' && t[3] <= '9') { n = atoi(t + 3); if (n >= 1 && n <= RAW_BUTTONS) { o->id = (unsigned short)(32 + n - 1); return 1; } return 0; }
    if (ci_prefix(t, "Axis") && t[4] >= '1' && t[4] <= '8' && (t[5] == '+' || t[5] == '-') && t[6] == 0) { o->type = SRC_PAXIS; o->id = (unsigned short)(8 + t[4] - '1'); o->sign = (signed char)(t[5] == '+' ? 1 : -1); return 1; }
    if (ci_prefix(t, "Hat") && t[3] >= '1' && t[3] <= '4') {
        static const char *const d[4] = { "Up", "Right", "Down", "Left" };
        for (i = 0; i < 4; i++) if (ci_eq(t + 4, d[i])) { o->type = SRC_PHAT; o->id = (unsigned short)(t[3] - '1'); o->sign = (signed char)i; return 1; }
    }
    return 0;
}

int src_parse(const char *text, Source *out) {
    char buf[64]; char *t; Source o; int id;
    memset(&o, 0, sizeof o);
    copy_str(buf, sizeof buf, text); t = trim(buf);
    if (ci_prefix(t, "menu:")) { o.ctx = CTX_MENU; t = trim(t + 5); }
    else if (ci_prefix(t, "game:")) { o.ctx = CTX_GAME; t = trim(t + 5); }
    if (!*t) return 0;
    if (ci_prefix(t, "Pad.")) { if (!parse_pad_source(t + 4, &o)) return 0; *out = o; return 1; }
    if (ci_prefix(t, "Wheel")) {
        static const char *const d[4] = { "Up", "Down", "Left", "Right" }; int i;
        for (i = 0; i < 4; i++) if (ci_eq(t + 5, d[i])) { o.type = SRC_WHEEL; o.id = (unsigned short)i; *out = o; return 1; }
        return 0;
    }
    if (ci_prefix(t, "Mouse")) {
        if (t[5] >= '1' && t[5] <= '5' && t[6] == 0) { o.type = SRC_MBTN; o.id = (unsigned short)(t[5] - '1'); *out = o; return 1; }
        if ((t[5] == 'X' || t[5] == 'x' || t[5] == 'Y' || t[5] == 'y') && (t[6] == '+' || t[6] == '-') && t[7] == 0) {
            o.type = SRC_MAXIS; o.id = (unsigned short)((t[5] == 'X' || t[5] == 'x') ? 0 : 1); o.sign = (signed char)(t[6] == '+' ? 1 : -1); *out = o; return 1;
        }
        return 0;
    }
    if (ci_eq(t, "LMB")) { o.type = SRC_MBTN; o.id = 0; *out = o; return 1; }
    if (ci_eq(t, "RMB")) { o.type = SRC_MBTN; o.id = 1; *out = o; return 1; }
    if (ci_eq(t, "MMB")) { o.type = SRC_MBTN; o.id = 2; *out = o; return 1; }
    if (ci_prefix(t, "SC:")) {                                /* an unnamed key: SC:1E or SC:E048 (E0 = extended) */
        char *e; unsigned long v; const char *h = t + 3; int ext = 0;
        if ((h[0] == 'E' || h[0] == 'e') && strlen(h) == 4) { ext = 1; h += 2; }
        v = strtoul(h, &e, 16); if (*e || e == h || v > 0x7F) return 0;
        o.type = SRC_KEY; o.id = (unsigned short)((ext ? 0x80 : 0) | v); *out = o; return 1;
    }
    id = key_id_from_name(t);
    if (id < 0) return 0;
    o.type = SRC_KEY; o.id = (unsigned short)id; *out = o; return 1;
}

int src_format(const Source *s, char *buf, int cap) {
    char tmp[48]; const char *pre = s->ctx == CTX_GAME ? "game:" : s->ctx == CTX_MENU ? "menu:" : "";
    static const char *const hatd[4] = { "Up", "Right", "Down", "Left" };
    static const char *const whl[4] = { "WheelUp", "WheelDown", "WheelLeft", "WheelRight" };
    tmp[0] = 0;
    switch (s->type) {
    case SRC_KEY: { const char *n = key_name(s->id); if (n) snprintf(tmp, sizeof tmp, "%s", n); else snprintf(tmp, sizeof tmp, "SC:%s%02X", (s->id & 0x80) ? "E0" : "", s->id & 0x7F); break; }
    case SRC_MBTN: snprintf(tmp, sizeof tmp, "Mouse%d", s->id + 1); break;
    case SRC_WHEEL: snprintf(tmp, sizeof tmp, "%s", whl[s->id & 3]); break;
    case SRC_MAXIS: snprintf(tmp, sizeof tmp, "Mouse%c%c", s->id ? 'Y' : 'X', s->sign < 0 ? '-' : '+'); break;
    case SRC_PBTN: if (s->id < PB_COUNT) snprintf(tmp, sizeof tmp, "Pad.%s", g_pb_names[s->id]); else snprintf(tmp, sizeof tmp, "Pad.Btn%d", s->id - 32 + 1); break;
    case SRC_PAXIS:
        if (s->id >= PA_LT && s->id < PA_COUNT) snprintf(tmp, sizeof tmp, "Pad.%s", g_pa_names[s->id]);
        else if (s->id < PA_LT) snprintf(tmp, sizeof tmp, "Pad.%s%c", g_pa_names[s->id], s->sign < 0 ? '-' : '+');
        else snprintf(tmp, sizeof tmp, "Pad.Axis%d%c", s->id - 8 + 1, s->sign < 0 ? '-' : '+');
        break;
    case SRC_PHAT: snprintf(tmp, sizeof tmp, "Pad.Hat%d%s", s->id + 1, hatd[s->sign & 3]); break;
    default: snprintf(tmp, sizeof tmp, "none"); break;
    }
    if (snprintf(buf, (size_t)cap, "%s%s", pre, tmp) >= cap) return -1;
    return (int)strlen(buf);
}
int src_describe(const Source *s, char *buf, int cap) {
    char tmp[80]; const char *ctx = s->ctx == CTX_GAME ? " (in game)" : s->ctx == CTX_MENU ? " (menus)" : "";
    static const char *const hatd[4] = { "up", "right", "down", "left" };
    static const char *const mb[5] = { "Mouse Left", "Mouse Right", "Mouse Middle", "Mouse Button 4", "Mouse Button 5" };
    static const char *const stk[4] = { "Left stick", "Left stick", "Right stick", "Right stick" };
    static const char *const whl[4] = { "Wheel Up", "Wheel Down", "Wheel Left", "Wheel Right" };
    tmp[0] = 0;
    switch (s->type) {
    case SRC_KEY: { const char *n = key_name(s->id); if (n) snprintf(tmp, sizeof tmp, "%s", n); else snprintf(tmp, sizeof tmp, "Key %s%02X", (s->id & 0x80) ? "E0" : "", s->id & 0x7F); break; }
    case SRC_MBTN: snprintf(tmp, sizeof tmp, "%s", mb[s->id % 5]); break;
    case SRC_WHEEL: snprintf(tmp, sizeof tmp, "%s", whl[s->id & 3]); break;
    case SRC_MAXIS: snprintf(tmp, sizeof tmp, "Mouse move %s", s->id ? (s->sign < 0 ? "up" : "down") : (s->sign < 0 ? "left" : "right")); break;
    case SRC_PBTN: if (s->id < PB_COUNT) snprintf(tmp, sizeof tmp, "Pad %s", g_pb_names[s->id]); else snprintf(tmp, sizeof tmp, "Pad button %d", s->id - 32 + 1); break;
    case SRC_PAXIS:
        if (s->id >= PA_LT && s->id < PA_COUNT) snprintf(tmp, sizeof tmp, "Pad %s trigger", s->id == PA_LT ? "left" : "right");
        else if (s->id < PA_LT) { int x = (s->id == PA_LX || s->id == PA_RX); snprintf(tmp, sizeof tmp, "Pad %s %s", stk[s->id], x ? (s->sign < 0 ? "left" : "right") : (s->sign < 0 ? "down" : "up")); }
        else snprintf(tmp, sizeof tmp, "Pad axis %d%c", s->id - 8 + 1, s->sign < 0 ? '-' : '+');
        break;
    case SRC_PHAT: snprintf(tmp, sizeof tmp, "Pad hat %d %s", s->id + 1, hatd[s->sign & 3]); break;
    default: snprintf(tmp, sizeof tmp, "-"); break;
    }
    if (snprintf(buf, (size_t)cap, "%s%s", tmp, ctx) >= cap) return -1;
    return (int)strlen(buf);
}

int binding_add(Binding *b, const Source *s) {
    int i;
    for (i = 0; i < b->n; i++) if (src_equal(&b->s[i], s) && b->s[i].ctx == s->ctx) return 0;
    if (b->n >= MAX_SRC) return -1;
    b->s[b->n++] = *s; return 1;
}
void binding_remove_family(Binding *b, int family) {
    int i, k = 0;
    for (i = 0; i < b->n; i++) if (src_family(&b->s[i]) != family) b->s[k++] = b->s[i];
    for (i = k; i < MAX_SRC; i++) memset(&b->s[i], 0, sizeof b->s[i]);
    b->n = k;
}
static int binding_parse(Binding *b, const char *list, int append, char *err, int errcap) {
    char buf[512]; char *p, *tok; int ok = 1;
    copy_str(buf, sizeof buf, list); p = trim(buf);
    if (!append) memset(b, 0, sizeof *b);
    if (ci_eq(p, "none") || !*p) return 1;
    for (tok = p; tok && *tok; ) {
        char *comma = strchr(tok, ','), *t; Source s;
        char *sp; if (comma) *comma = 0;
        t = trim(tok);
        while (*t) {                                          /* tokens may also be separated by spaces (key names never contain any) */
            sp = t; while (*sp && *sp != ' ' && *sp != '\t') sp++;
            { char save = *sp; *sp = 0;
              if (*t) { if (ci_eq(t, "none")) { /* ignored */ } else if (src_parse(t, &s)) { if (binding_add(b, &s) < 0) { if (ok && err) snprintf(err, (size_t)errcap, "too many sources for one input (limit %d)", MAX_SRC); ok = 0; } } else { if (ok && err) snprintf(err, (size_t)errcap, "unknown input '%s'", t); ok = 0; } }
              *sp = save; }
            t = sp; while (*t == ' ' || *t == '\t') t++;
        }
        tok = comma ? comma + 1 : NULL;
    }
    return ok;
}

/* ------------------------------------------------------------------ pad specs */
int padspec_parse(const char *text, PadSpec *o) {
    char buf[96]; char *t;
    memset(o, 0, sizeof *o);
    copy_str(buf, sizeof buf, text); t = trim(buf);
    if (ci_eq(t, "pad") || ci_eq(t, "pad:auto") || ci_eq(t, "auto")) { o->kind = PS_AUTO; return 1; }
    if (ci_prefix(t, "xinput:") || ci_prefix(t, "xinput")) {
        const char *n = t + 6; if (*n == ':') n++;
        if (*n >= '1' && *n <= '4' && n[1] == 0) { o->kind = PS_XINPUT; o->index = *n - '1'; return 1; }
        return 0;
    }
    if (ci_prefix(t, "dinput:")) {
        const char *v = t + 7;
        if (ci_prefix(v, "name=")) { if (!v[5]) return 0; o->kind = PS_DI_NAME; copy_str(o->text, sizeof o->text, v + 5); return 1; }
        if (v[0] == '{') { o->kind = PS_DI_GUID; copy_str(o->text, sizeof o->text, v); return 1; }
        if (v[0] >= '1' && v[0] <= '9') { o->kind = PS_DI_INDEX; o->index = atoi(v); return 1; }
        return 0;
    }
    return 0;
}
int padspec_format(const PadSpec *p, char *buf, int cap) {
    int r;
    switch (p->kind) {
    case PS_XINPUT: r = snprintf(buf, (size_t)cap, "xinput:%d", p->index + 1); break;
    case PS_DI_INDEX: r = snprintf(buf, (size_t)cap, "dinput:%d", p->index); break;
    case PS_DI_GUID: r = snprintf(buf, (size_t)cap, "dinput:%s", p->text); break;
    case PS_DI_NAME: r = snprintf(buf, (size_t)cap, "dinput:name=%s", p->text); break;
    default: r = snprintf(buf, (size_t)cap, "pad:auto"); break;
    }
    return r < 0 || r >= cap ? -1 : r;
}

/* ------------------------------------------------------------------ profiles (the text is parsed with the same binding parser as the file) */
typedef struct ProfileDef { const char *name, *title; int family; const char *text; } ProfileDef;

/* keyboard + mouse, first-person style: WASD = the C buttons (move / strafe), the mouse = the stick (look), left button = Z (primary fire), right = B (secondary).
 * Keys the N64 menus need are doubled in the menu context (WASD, wheel and the left button move / confirm there); "Z X C Enter" and the arrows are the old keys. */
static const char P_KBM_FPS[] =
    "Z = game:Mouse1, Z, LCtrl\n"
    "B = Mouse2, X, Backspace\n"
    "A = E, C, Mouse3, menu:Mouse1, game:WheelUp, game:WheelDown\n"
    "R = Space, Mouse4\n"
    "L = Q, Mouse5\n"
    "Start = Enter\n"
    "CUp = game:W\nCLeft = game:A\nCDown = game:S\nCRight = game:D\n"
    "DUp = menu:W, menu:WheelUp, Num8\nDDown = menu:S, menu:WheelDown, Num2\nDLeft = menu:A, Num4\nDRight = menu:D, Num6\n"
    "StickLeft = Left, MouseX-\nStickRight = Right, MouseX+\nStickUp = Up, MouseY-\nStickDown = Down, MouseY+\n";
/* two people on one keyboard: the left hand cluster (profile for player 1 of the pair) ... */
static const char P_KB_LEFT[] =
    "Z = LShift\nB = LCtrl\nA = C\nR = Space\nL = V\nStart = 1\n"
    "CUp = game:W\nCLeft = game:A\nCDown = game:S\nCRight = game:D\n"
    "DUp = menu:W\nDDown = menu:S\nDLeft = menu:A\nDRight = menu:D\n"
    "StickLeft = Q\nStickRight = E\nStickUp = R\nStickDown = F\n";
/* ... and the right hand cluster (arrow keys move, the numpad looks) */
static const char P_KB_RIGHT[] =
    "Z = RCtrl, Num0\nB = RShift, NumDot\nA = NumEnter, Num1\nR = RAlt, NumPlus\nL = Num3\nStart = Backspace\n"
    "CUp = game:Up\nCLeft = game:Left\nCDown = game:Down\nCRight = game:Right\n"
    "DUp = menu:Up\nDDown = menu:Down\nDLeft = menu:Left\nDRight = menu:Right\n"
    "StickLeft = Num4\nStickRight = Num6\nStickUp = Num8\nStickDown = Num5, Num2\n";
/* modern dual stick: right stick = look (the N64 stick), left stick = move (C buttons), triggers = fire */
static const char P_XBOX[] =
    "A = menu:Pad.A, game:Pad.X, game:Pad.Y\nB = Pad.B, Pad.LT\nZ = Pad.RT\nStart = Pad.Start\nL = Pad.LB\nR = Pad.RB, game:Pad.A\n"
    "CUp = game:Pad.LY+\nCDown = game:Pad.LY-\nCLeft = game:Pad.LX-\nCRight = game:Pad.LX+\n"
    "DUp = Pad.DUp, menu:Pad.LY+\nDDown = Pad.DDown, menu:Pad.LY-\nDLeft = Pad.DLeft, menu:Pad.LX-\nDRight = Pad.DRight, menu:Pad.LX+\n"
    "StickLeft = Pad.RX-\nStickRight = Pad.RX+\nStickUp = Pad.RY+\nStickDown = Pad.RY-\n";
/* the classic N64 feel: left stick = the stick, right stick = the C buttons (what the port did before the mapping system existed) */
static const char P_XBOX_N64[] =
    "A = Pad.A\nB = Pad.B, Pad.X\nZ = Pad.RT, Pad.LT\nStart = Pad.Start\nL = Pad.LB\nR = Pad.RB\n"
    "CUp = Pad.RY+\nCDown = Pad.RY-\nCLeft = Pad.RX-\nCRight = Pad.RX+\n"
    "DUp = Pad.DUp\nDDown = Pad.DDown\nDLeft = Pad.DLeft\nDRight = Pad.DRight\n"
    "StickLeft = Pad.LX-\nStickRight = Pad.LX+\nStickUp = Pad.LY+\nStickDown = Pad.LY-\n";
/* a generic DirectInput pad addressed by physical button / axis numbers (PlayStation-style numbering: 1 square, 2 cross, 3 circle, 4 triangle, 5 L1, 6 R1,
 * 7 L2, 8 R2, 9 share, 10 options; axes X Y = left stick, Z Rz = right stick) - for pads whose standard layout is not recognised */
static const char P_GENERIC[] =
    "A = Pad.Btn2\nB = Pad.Btn3, Pad.Btn1\nZ = Pad.Btn8, Pad.Btn7\nStart = Pad.Btn10, Pad.Btn9\nL = Pad.Btn5\nR = Pad.Btn6, Pad.Btn4\n"
    "CUp = game:Pad.Axis2-\nCDown = game:Pad.Axis2+\nCLeft = game:Pad.Axis1-\nCRight = game:Pad.Axis1+\n"
    "DUp = Pad.Hat1Up, menu:Pad.Axis2-\nDDown = Pad.Hat1Down, menu:Pad.Axis2+\nDLeft = Pad.Hat1Left, menu:Pad.Axis1-\nDRight = Pad.Hat1Right, menu:Pad.Axis1+\n"
    "StickLeft = Pad.Axis3-\nStickRight = Pad.Axis3+\nStickUp = Pad.Axis6-\nStickDown = Pad.Axis6+\n";
static const ProfileDef g_profiles[] = {
    { "kbm_fps", "Keyboard + mouse (first-person: WASD move, mouse look)", FAM_KBM, P_KBM_FPS },
    { "kb_left", "Keyboard, left hand (shared keyboard, player A)", FAM_KBM, P_KB_LEFT },
    { "kb_right", "Keyboard, right hand (shared keyboard, player B)", FAM_KBM, P_KB_RIGHT },
    { "xbox", "Gamepad, dual stick (left stick moves, right stick looks)", FAM_PAD, P_XBOX },
    { "xbox_n64", "Gamepad, classic N64 (left stick = stick, right stick = C buttons)", FAM_PAD, P_XBOX_N64 },
    { "generic", "Generic DirectInput pad (raw button / axis numbers)", FAM_PAD, P_GENERIC }
};
#define NPROFILES ((int)(sizeof g_profiles / sizeof g_profiles[0]))
int cfg_profile_count(void) { return NPROFILES; }
const char *cfg_profile_name(int i) { return i >= 0 && i < NPROFILES ? g_profiles[i].name : NULL; }
const char *cfg_profile_title(int i) { return i >= 0 && i < NPROFILES ? g_profiles[i].title : NULL; }
int cfg_profile_family(int i) { return i >= 0 && i < NPROFILES ? g_profiles[i].family : 0; }
int cfg_profile_find(const char *name) { int i; for (i = 0; i < NPROFILES; i++) if (ci_eq(name, g_profiles[i].name)) return i; return -1; }

static void apply_profile_text(PlayerCfg *p, const char *text) {
    char line[256]; const char *s = text;
    while (*s) {
        int n = 0; char *eq, *key, *val; int in;
        while (*s && *s != '\n' && n < 255) line[n++] = *s++;
        if (*s == '\n') s++;
        line[n] = 0;
        eq = strchr(line, '='); if (!eq) continue;
        *eq = 0; key = trim(line); val = trim(eq + 1);
        in = in_from_name(key); if (in < 0) continue;
        binding_parse(&p->bind[in], val, 1, NULL, 0);
    }
}
int cfg_apply_profile(PlayerCfg *p, const char *name, int mode) {
    int i = cfg_profile_find(name), k;
    if (i < 0) return -1;
    if (mode == 0) for (k = 0; k < IN_COUNT; k++) binding_remove_family(&p->bind[k], g_profiles[i].family);
    apply_profile_text(p, g_profiles[i].text);
    return 0;
}

/* ------------------------------------------------------------------ defaults */
void cfg_player_clear_bindings(PlayerCfg *p) { memset(p->bind, 0, sizeof p->bind); }
static void player_settings_defaults(PlayerCfg *p) {
    p->mouse_sens_x = p->mouse_sens_y = 1.0f; p->mouse_smooth = 0; p->mouse_invert_y = 0; p->mouse_backlog = 30.0f;
    p->stick_deadzone = 0.20f; p->stick_sens_x = p->stick_sens_y = 1.0f; p->stick_curve = 1.0f; p->stick_invert_y = 0;
    p->trigger_threshold = 0.30f; p->axis_threshold = 0.50f; p->key_stick = N64_STICK_MAX;
}
void cfg_player_defaults(PlayerCfg *p, int index) {
    static const char *const kb[4] = { "kbm_fps", "kb_right", "kb_left", "kb_right" };
    memset(p, 0, sizeof *p);
    player_settings_defaults(p);
    p->npads = 1; p->pad[0].kind = PS_AUTO;
    if (index == 0) { p->use_keyboard = 1; p->use_mouse = 1; }
    cfg_apply_profile(p, kb[index & 3], 1);
    cfg_apply_profile(p, "xbox", 1);
}
void cfg_defaults(ControlsCfg *c) {
    int i;
    memset(c, 0, sizeof *c);
    c->version = 1; c->mouse_capture = MC_AUTO; c->esc_mode = ESC_CONFIRM; c->rumble = 1; c->rumble_strength = 0.6f; c->background_input = 0;
    c->hot_reload = 1; c->mouse_menu_guard = 1; c->show_status = 1; c->native_controls = 1;
    for (i = 0; i < MAX_PLAYERS; i++) cfg_player_defaults(&c->player[i], i);
}
void cfg_copy_player(PlayerCfg *dst, const PlayerCfg *src, int bindings_only) {
    if (bindings_only) memcpy(dst->bind, src->bind, sizeof dst->bind); else *dst = *src;
}

/* ------------------------------------------------------------------ parser */
typedef struct Parse { ControlsCfg *c; CfgLogFn log; void *user; int line; int warnings; } Parse;
static void warn(Parse *p, const char *fmt, const char *a) {
    char m[200];
    snprintf(m, sizeof m, fmt, a ? a : "");
    p->warnings++;
    if (p->log) p->log(p->user, p->line, m);
}
static int parse_bool(const char *v, int *out) {
    if (ci_eq(v, "on") || ci_eq(v, "true") || ci_eq(v, "yes") || ci_eq(v, "1")) { *out = 1; return 1; }
    if (ci_eq(v, "off") || ci_eq(v, "false") || ci_eq(v, "no") || ci_eq(v, "0")) { *out = 0; return 1; }
    return 0;
}
static int parse_float(const char *v, float lo, float hi, float *out) {
    char *e; double d = strtod(v, &e);
    if (e == v || *trim(e)) return 0;
    *out = clampf((float)d, lo, hi); return 1;
}
static void parse_devices(Parse *ps, PlayerCfg *pl, const char *val) {
    char buf[320]; char *tok, *next;
    copy_str(buf, sizeof buf, val);
    pl->use_keyboard = pl->use_mouse = 0; pl->npads = 0; memset(pl->pad, 0, sizeof pl->pad);
    for (tok = buf; tok; tok = next) {
        char *t; PadSpec sp;
        next = strchr(tok, ','); if (next) *next++ = 0;
        t = trim(tok);
        if (!*t || ci_eq(t, "none")) continue;
        if (ci_eq(t, "keyboard") || ci_eq(t, "keyboard1") || ci_eq(t, "kb")) pl->use_keyboard = 1;
        else if (ci_eq(t, "mouse")) pl->use_mouse = 1;
        else if (padspec_parse(t, &sp)) { if (pl->npads < MAX_PADS_PER_PLAYER) pl->pad[pl->npads++] = sp; else warn(ps, "too many gamepads for one player, '%s' ignored", t); }
        else warn(ps, "unknown device '%s' (use keyboard, mouse, pad:auto, xinput:1..4, dinput:N, dinput:{guid}, dinput:name=...)", t);
    }
}
static void parse_profile_list(Parse *ps, PlayerCfg *pl, const char *val) {
    char buf[200]; char *tok; int first = 1;
    copy_str(buf, sizeof buf, val);
    for (tok = strtok(buf, ", \t"); tok; tok = strtok(NULL, ", \t")) {
        if (ci_eq(tok, "none")) { if (first) cfg_player_clear_bindings(pl); first = 0; continue; }
        if (cfg_profile_find(tok) < 0) { warn(ps, "unknown profile '%s'", tok); continue; }
        if (first) { cfg_player_clear_bindings(pl); first = 0; }
        cfg_apply_profile(pl, tok, 1);
    }
}
static void parse_player_key(Parse *ps, PlayerCfg *pl, const char *key, const char *val, int append) {
    int in = in_from_name(key); float f; int b;
    char err[96] = "";
    if (in >= 0) { if (!binding_parse(&pl->bind[in], val, append, err, sizeof err)) warn(ps, "%s", err); return; }
#define FKEY(name, field, lo, hi) if (ci_eq(key, name)) { if (parse_float(val, lo, hi, &f)) pl->field = f; else warn(ps, "bad number for '%s'", key); return; }
#define BKEY(name, field) if (ci_eq(key, name)) { if (parse_bool(val, &b)) pl->field = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "devices")) { parse_devices(ps, pl, val); return; }
    if (ci_eq(key, "profile")) { parse_profile_list(ps, pl, val); return; }
    FKEY("mouse_sens_x", mouse_sens_x, 0.05f, 20.0f) FKEY("mouse_sens_y", mouse_sens_y, 0.05f, 20.0f) FKEY("mouse_smooth", mouse_smooth, 0.0f, 0.9f) FKEY("mouse_backlog", mouse_backlog, 2.0f, 180.0f)
    BKEY("mouse_invert_y", mouse_invert_y)
    FKEY("stick_deadzone", stick_deadzone, 0.0f, 0.9f) FKEY("stick_sens_x", stick_sens_x, 0.1f, 4.0f) FKEY("stick_sens_y", stick_sens_y, 0.1f, 4.0f)
    FKEY("stick_curve", stick_curve, 0.5f, 4.0f) BKEY("stick_invert_y", stick_invert_y)
    FKEY("trigger_threshold", trigger_threshold, 0.05f, 0.95f) FKEY("axis_threshold", axis_threshold, 0.1f, 0.95f)
    if (ci_eq(key, "key_stick")) { if (parse_float(val, 1, 80, &f)) pl->key_stick = (int)(f + 0.5f); else warn(ps, "bad number for '%s'", key); return; }
#undef FKEY
#undef BKEY
    warn(ps, "unknown key '%s'", key);
}
static void parse_general_key(Parse *ps, const char *key, const char *val) {
    ControlsCfg *c = ps->c; int b; float f;
    if (ci_eq(key, "version")) { c->version = atoi(val); return; }
    if (ci_eq(key, "mouse_capture")) { if (ci_eq(val, "auto")) c->mouse_capture = MC_AUTO; else if (ci_eq(val, "click")) c->mouse_capture = MC_CLICK; else if (ci_eq(val, "off")) c->mouse_capture = MC_OFF; else warn(ps, "mouse_capture must be auto, click or off (got '%s')", val); return; }
    if (ci_eq(key, "esc")) { if (ci_eq(val, "confirm")) c->esc_mode = ESC_CONFIRM; else if (ci_eq(val, "quit")) c->esc_mode = ESC_QUIT; else if (ci_eq(val, "ignore")) c->esc_mode = ESC_IGNORE; else warn(ps, "esc must be confirm, quit or ignore (got '%s')", val); return; }
    if (ci_eq(key, "rumble")) { if (parse_bool(val, &b)) c->rumble = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "rumble_strength")) { if (parse_float(val, 0.0f, 1.0f, &f)) c->rumble_strength = f; else warn(ps, "bad number for '%s'", key); return; }
    if (ci_eq(key, "background_input")) { if (parse_bool(val, &b)) c->background_input = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "hot_reload")) { if (parse_bool(val, &b)) c->hot_reload = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "mouse_menu_guard")) { if (parse_bool(val, &b)) c->mouse_menu_guard = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "show_status")) { if (parse_bool(val, &b)) c->show_status = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    if (ci_eq(key, "native_controls")) { if (parse_bool(val, &b)) c->native_controls = b; else warn(ps, "bad on/off value for '%s'", key); return; }
    warn(ps, "unknown key '%s' in [general]", key);
}

int cfg_parse(ControlsCfg *c, const char *text, int len, CfgLogFn log, void *user) {
    Parse ps; int section = 0;      /* 0 none, 1 general, 2..5 player 1..4, -1 unknown */
    int i, pos = 0, meaningful = 0, recognised = 0;
    ControlsCfg tmp;
    cfg_defaults(&tmp);
    ps.c = &tmp; ps.log = log; ps.user = user; ps.line = 0; ps.warnings = 0;
    if (len < 0) len = 0;
    if (len > 262144) { ps.line = 0; warn(&ps, "file too large (%s)", "limit 256 KB"); cfg_defaults(c); return -1; }
    for (i = 0; i < len && i < 4096; i++) if (text[i] == 0) { warn(&ps, "not a text file (%s)", "NUL byte"); cfg_defaults(c); return -1; }
    if (len >= 3 && (unsigned char)text[0] == 0xEF && (unsigned char)text[1] == 0xBB && (unsigned char)text[2] == 0xBF) pos = 3;
    while (pos < len) {
        char line[1024]; int n = 0; char *s, *eq, *key, *val; int append = 0, k;
        while (pos < len && text[pos] != '\n') { if (n < 1023) line[n++] = text[pos]; pos++; }
        pos++; line[n] = 0; ps.line++;
        for (k = 0; k < n; k++) if (line[k] == ';' || line[k] == '#') { if (k == 0 || line[k - 1] == ' ' || line[k - 1] == '\t') { line[k] = 0; break; } }
        s = trim(line);
        if (!*s) continue;
        meaningful++;
        if (*s == '[') {
            char *e = strchr(s, ']'); char name[32];
            if (!e) { warn(&ps, "missing ']' in section header '%s'", s); section = -1; continue; }
            *e = 0; copy_str(name, sizeof name, trim(s + 1));
            if (ci_eq(name, "general")) section = 1;
            else if (ci_prefix(name, "player") && name[6] >= '1' && name[6] <= '4' && !name[7]) section = 2 + (name[6] - '1');
            else { warn(&ps, "unknown section [%s]", name); section = -1; }
            if (section > 0) recognised++;
            continue;
        }
        eq = strchr(s, '=');
        if (!eq) { warn(&ps, "ignored line without '=': %s", s); continue; }
        if (eq > s && eq[-1] == '+') { append = 1; eq[-1] = 0; }
        *eq = 0; key = trim(s); val = trim(eq + 1);
        if (section == 0) { warn(&ps, "'%s' is outside of any section", key); continue; }
        if (section < 0) continue;
        recognised++;
        if (section == 1) parse_general_key(&ps, key, val);
        else parse_player_key(&ps, &tmp.player[section - 2], key, val, append);
    }
    if (meaningful > 0 && recognised == 0) { ps.line = 0; warn(&ps, "no [general] / [playerN] section found (%s)", "not a controls file"); cfg_defaults(c); return -1; }
    *c = tmp;
    return 0;
}
int cfg_load(ControlsCfg *c, const char *path, CfgLogFn log, void *user) {
    FILE *f = fopen(path, "rb"); char *buf; long n; int r;
    if (!f) return -2;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    if (n < 0 || n > 262144) { fclose(f); if (log) log(user, 0, "file too large (limit 256 KB)"); cfg_defaults(c); return -1; }
    buf = (char *)malloc((size_t)n + 1);
    if (!buf) { fclose(f); return -2; }
    if (fread(buf, 1, (size_t)n, f) != (size_t)n) { free(buf); fclose(f); return -2; }
    fclose(f);
    r = cfg_parse(c, buf, (int)n, log, user);
    free(buf);
    return r;
}

/* ------------------------------------------------------------------ writer */
typedef struct Out { char *buf; int cap, len, over; } Out;
static void out_s(Out *o, const char *s) { int n = (int)strlen(s); if (o->len + n >= o->cap) { o->over = 1; return; } memcpy(o->buf + o->len, s, (size_t)n + 1); o->len += n; }
static void out_f(Out *o, const char *fmt, ...) {
    char t[512]; va_list ap; va_start(ap, fmt); vsnprintf(t, sizeof t, fmt, ap); va_end(ap); out_s(o, t);
}
static void fmt_float(char *buf, int cap, float v) {
    char t[32]; int n;
    snprintf(t, sizeof t, "%.3f", (double)v); n = (int)strlen(t);
    while (n > 2 && t[n - 1] == '0' && t[n - 2] != '.') t[--n] = 0;
    snprintf(buf, (size_t)cap, "%s", t);
}
static void out_kv_f(Out *o, const char *k, float v) { char t[32]; fmt_float(t, sizeof t, v); out_f(o, "%s = %s\n", k, t); }
static void out_kv_b(Out *o, const char *k, int v) { out_f(o, "%s = %s\n", k, v ? "on" : "off"); }

static const char *const g_header =
    "; controls.ini - input configuration of the Turok: Rage Wars PC port (written by turok_controls.exe, hand-editable)\n"
    ";\n"
    "; The game reads this file from the folder of the exe (or the path in the TUROK_CONTROLS environment variable) when it starts, and again\n"
    "; whenever the file changes or F2 is pressed.  A missing or unusable file means the built-in defaults; a bad line only produces a log line.\n"
    "; Lines starting with ; or # are comments, so is everything after \" ;\".  Names are case-insensitive.\n"
    ";\n"
    "; [general]  mouse_capture = auto | click | off\n"
    ";               auto   the mouse is captured (hidden, kept inside the window) while a level is running and the window has the focus\n"
    ";               click  captured by a click in the window (or F1), released by Esc / F1 / losing the focus\n"
    ";               off    never captured, mouse look disabled (buttons and wheel still work over the window)\n"
    ";             esc = confirm | quit | ignore     Esc releases the mouse; with the mouse already free, confirm = press twice to quit, quit = at once\n"
    ";             rumble = on | off,  rumble_strength = 0..1      XInput vibration for the game's Rumble Pak\n"
    ";             background_input = on | off        read devices while the window is not in front (default off)\n"
    ";             hot_reload = on | off,  mouse_menu_guard = on | off,  show_status = on | off\n"
    ";             native_controls = on | off         on (default): in a level the mouse turns and tilts the view directly (no stick speed limit) and the\n"
    ";                                                C-button inputs (W A S D in kbm_fps) walk and strafe, whatever control style is chosen in the game's options\n"
    ";\n"
    "; [player1] .. [player4]   one section per N64 controller port.\n"
    ";   devices = none | keyboard, mouse, pad:auto, xinput:1..4, dinput:N, dinput:{instance guid}, dinput:name=part of the name   (comma separated)\n"
    ";             pad:auto = the first connected gamepad that no other player claims (player 1 gets the first, player 2 the second, ...).\n"
    ";             The keyboard may be shared between players (give each a different keyboard profile), the mouse and every gamepad serve one player.\n"
    ";             Player 1 is always reported as connected; players 2-4 only while one of their devices is available.\n"
    ";   settings: mouse_sens_x, mouse_sens_y (1.0 = 0.05 degrees per mouse count), mouse_smooth (0), mouse_invert_y, mouse_backlog (30 degrees), stick_deadzone (0.2),\n"
    ";             stick_sens_x, stick_sens_y (1.0),\n"
    ";             stick_curve (1.0 = linear, 2.0 = finer near the centre), stick_invert_y, trigger_threshold (0.3), axis_threshold (0.5), key_stick (80)\n"
    ";   bindings: <N64 input> = source, source, ...      (none = nothing; \"Input += source\" appends to what the profile gave)\n"
    ";             N64 inputs: A B Z Start DUp DDown DLeft DRight L R CUp CDown CLeft CRight StickLeft StickRight StickUp StickDown\n"
    ";             sources:    keys by the PHYSICAL position of a US keyboard (W is the key right of Q on every layout): Esc F1..F12 1..0 Q..P A..L Z..M Space Enter\n"
    ";                         Tab Backspace LShift RShift LCtrl RCtrl LAlt RAlt Up Down Left Right Home End PageUp PageDown Insert Delete Num0..Num9 NumEnter NumPlus\n"
    ";                         NumMinus NumMul NumDiv NumDot Comma Period Slash Semicolon Quote Minus Equals LBracket RBracket Backslash Backquote, or SC:1E / SC:E048\n"
    ";                         mouse: Mouse1 (left) Mouse2 (right) Mouse3 (middle) Mouse4 Mouse5, WheelUp WheelDown WheelLeft WheelRight, MouseX+ MouseX- MouseY+ MouseY-\n"
    ";                         gamepad: Pad.A Pad.B Pad.X Pad.Y Pad.LB Pad.RB Pad.Back Pad.Start Pad.LS Pad.RS Pad.DUp Pad.DDown Pad.DLeft Pad.DRight Pad.LT Pad.RT\n"
    ";                         Pad.LX+ Pad.LX- Pad.LY+ Pad.LY- Pad.RX+ Pad.RX- Pad.RY+ Pad.RY- (+ is right / up), raw DirectInput numbers: Pad.Btn1.. Pad.Axis1+ Pad.Hat1Up ...\n"
    ";             A source can be limited to free play or to menus / pause screens with the prefix game: or menu:  (e.g. menu:Mouse1).\n"
    ";             Analog sources (pad sticks, mouse motion) given to a StickXxx input move the stick proportionally; everything else gives key_stick units.\n"
    ";   profile = kbm_fps, kb_left, kb_right, xbox, xbox_n64, generic     start from these built-in presets instead of the defaults of this player\n"
    ";             (the lines below then override single inputs).  Hotkeys in the game: F1 capture/release the mouse, F2 reload this file, Esc release the mouse.\n";

int cfg_write(const ControlsCfg *c, char *buf, int cap) {
    Out o; int p, i;
    o.buf = buf; o.cap = cap; o.len = 0; o.over = 0; if (cap > 0) buf[0] = 0;
    out_s(&o, g_header);
    out_s(&o, "\n[general]\n");
    out_f(&o, "version = %d\n", c->version);
    out_f(&o, "mouse_capture = %s\n", c->mouse_capture == MC_CLICK ? "click" : c->mouse_capture == MC_OFF ? "off" : "auto");
    out_f(&o, "esc = %s\n", c->esc_mode == ESC_QUIT ? "quit" : c->esc_mode == ESC_IGNORE ? "ignore" : "confirm");
    out_kv_b(&o, "rumble", c->rumble); out_kv_f(&o, "rumble_strength", c->rumble_strength);
    out_kv_b(&o, "background_input", c->background_input); out_kv_b(&o, "hot_reload", c->hot_reload);
    out_kv_b(&o, "mouse_menu_guard", c->mouse_menu_guard); out_kv_b(&o, "show_status", c->show_status);
    out_kv_b(&o, "native_controls", c->native_controls);
    for (p = 0; p < MAX_PLAYERS; p++) {
        const PlayerCfg *pl = &c->player[p]; char devs[200]; int n = 0;
        out_f(&o, "\n[player%d]\n", p + 1);
        devs[0] = 0;
        if (pl->use_keyboard) n += snprintf(devs + n, sizeof devs - (size_t)n, "%skeyboard", n ? ", " : "");
        if (pl->use_mouse) n += snprintf(devs + n, sizeof devs - (size_t)n, "%smouse", n ? ", " : "");
        for (i = 0; i < pl->npads; i++) { char t[100]; padspec_format(&pl->pad[i], t, sizeof t); n += snprintf(devs + n, sizeof devs - (size_t)n, "%s%s", n ? ", " : "", t); }
        if (!n) snprintf(devs, sizeof devs, "none");
        out_f(&o, "devices = %s\n", devs);
        out_kv_f(&o, "mouse_sens_x", pl->mouse_sens_x); out_kv_f(&o, "mouse_sens_y", pl->mouse_sens_y); out_kv_f(&o, "mouse_smooth", pl->mouse_smooth); out_kv_b(&o, "mouse_invert_y", pl->mouse_invert_y); out_kv_f(&o, "mouse_backlog", pl->mouse_backlog);
        out_kv_f(&o, "stick_deadzone", pl->stick_deadzone); out_kv_f(&o, "stick_sens_x", pl->stick_sens_x); out_kv_f(&o, "stick_sens_y", pl->stick_sens_y);
        out_kv_f(&o, "stick_curve", pl->stick_curve); out_kv_b(&o, "stick_invert_y", pl->stick_invert_y);
        out_kv_f(&o, "trigger_threshold", pl->trigger_threshold); out_kv_f(&o, "axis_threshold", pl->axis_threshold);
        out_f(&o, "key_stick = %d\n", pl->key_stick);
        for (i = 0; i < IN_COUNT; i++) {
            const Binding *b = &pl->bind[i]; int k; char line[512]; int ln;
            ln = snprintf(line, sizeof line, "%-10s = ", in_name(i));
            if (!b->n) ln += snprintf(line + ln, sizeof line - (size_t)ln, "none");
            for (k = 0; k < b->n; k++) { char t[64]; src_format(&b->s[k], t, sizeof t); ln += snprintf(line + ln, sizeof line - (size_t)ln, "%s%s", k ? ", " : "", t); }
            out_s(&o, line); out_s(&o, "\n");
        }
    }
    return o.over ? -1 : o.len;
}
int cfg_save(const ControlsCfg *c, const char *path) {
    static char buf[32768]; int n = cfg_write(c, buf, sizeof buf); FILE *f; char tmp[600];
    if (n < 0) return -1;
    snprintf(tmp, sizeof tmp, "%s.tmp", path);
    f = fopen(tmp, "wb"); if (!f) return -2;
    if (fwrite(buf, 1, (size_t)n, f) != (size_t)n) { fclose(f); remove(tmp); return -3; }
    fclose(f);
    remove(path);
    if (rename(tmp, path) != 0) { remove(tmp); return -4; }
    return 0;
}
int cfg_equal(const ControlsCfg *a, const ControlsCfg *b) {
    int i, k, j;
    if (a->version != b->version || a->mouse_capture != b->mouse_capture || a->esc_mode != b->esc_mode || a->rumble != b->rumble || a->background_input != b->background_input ||
        a->hot_reload != b->hot_reload || a->mouse_menu_guard != b->mouse_menu_guard || a->show_status != b->show_status || a->native_controls != b->native_controls) return 0;
    if (fabsf(a->rumble_strength - b->rumble_strength) > 0.0005f) return 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        const PlayerCfg *x = &a->player[i], *y = &b->player[i];
        if (fabsf(x->mouse_backlog - y->mouse_backlog) > 0.0005f) return 0;
        if (x->use_keyboard != y->use_keyboard || x->use_mouse != y->use_mouse || x->npads != y->npads || x->mouse_invert_y != y->mouse_invert_y || x->stick_invert_y != y->stick_invert_y || x->key_stick != y->key_stick) return 0;
        if (fabsf(x->mouse_sens_x - y->mouse_sens_x) > 0.0005f || fabsf(x->mouse_sens_y - y->mouse_sens_y) > 0.0005f || fabsf(x->mouse_smooth - y->mouse_smooth) > 0.0005f ||
            fabsf(x->stick_deadzone - y->stick_deadzone) > 0.0005f || fabsf(x->stick_sens_x - y->stick_sens_x) > 0.0005f || fabsf(x->stick_sens_y - y->stick_sens_y) > 0.0005f ||
            fabsf(x->stick_curve - y->stick_curve) > 0.0005f || fabsf(x->trigger_threshold - y->trigger_threshold) > 0.0005f || fabsf(x->axis_threshold - y->axis_threshold) > 0.0005f) return 0;
        for (k = 0; k < x->npads; k++) if (x->pad[k].kind != y->pad[k].kind || x->pad[k].index != y->pad[k].index || strcmp(x->pad[k].text, y->pad[k].text)) return 0;
        for (k = 0; k < IN_COUNT; k++) {
            if (x->bind[k].n != y->bind[k].n) return 0;
            for (j = 0; j < x->bind[k].n; j++) if (!src_equal(&x->bind[k].s[j], &y->bind[k].s[j]) || x->bind[k].s[j].ctx != y->bind[k].s[j].ctx) return 0;
        }
    }
    return 1;
}

/* ------------------------------------------------------------------ conflicts */
int cfg_conflicts(const PlayerCfg *p, Conflict *out, int max) {
    int a, b, i, j, n = 0;
    for (a = 0; a < IN_COUNT; a++) for (b = a + 1; b < IN_COUNT; b++)
        for (i = 0; i < p->bind[a].n; i++) for (j = 0; j < p->bind[b].n; j++) {
            const Source *x = &p->bind[a].s[i], *y = &p->bind[b].s[j];
            if (src_equal(x, y) && src_ctx_overlap(x, y)) { if (out && n < max) { out[n].in_a = a; out[n].in_b = b; out[n].src = *x; } n++; }
        }
    return n;
}
int cfg_cross_conflicts(const ControlsCfg *c, CrossConflict *out, int max) {
    int pa, pb, a, b, i, j, n = 0;
    for (pa = 0; pa < MAX_PLAYERS; pa++) for (pb = pa + 1; pb < MAX_PLAYERS; pb++) {
        const PlayerCfg *x = &c->player[pa], *y = &c->player[pb];
        if (!x->use_keyboard || !y->use_keyboard) continue;
        for (a = 0; a < IN_COUNT; a++) for (b = 0; b < IN_COUNT; b++)
            for (i = 0; i < x->bind[a].n; i++) for (j = 0; j < y->bind[b].n; j++) {
                const Source *s = &x->bind[a].s[i], *t = &y->bind[b].s[j];
                if (s->type == SRC_KEY && src_equal(s, t) && src_ctx_overlap(s, t)) { if (out && n < max) { out[n].player_a = pa; out[n].player_b = pb; out[n].in_a = a; out[n].in_b = b; out[n].src = *s; } n++; }
            }
    }
    return n;
}

/* ------------------------------------------------------------------ mapping engine */
void map_reset(MapState *st) { memset(st, 0, sizeof *st); }

static int ctx_ok(const Source *s, int gameplay) {
    if (s->ctx == CTX_ANY || gameplay < 0) return 1;
    return s->ctx == CTX_GAME ? gameplay == 1 : gameplay == 0;
}
float map_pad_axis(const PlayerCfg *c, const PadState *pad, int axis) {
    float x, y, m, s, dz = c->stick_deadzone;
    int ax;
    if (axis == PA_LT || axis == PA_RT) return pad->axis[axis];
    if (axis < 0 || axis >= PA_LT) return 0;
    ax = (axis == PA_LX || axis == PA_LY) ? PA_LX : PA_RX;
    x = pad->axis[ax]; y = pad->axis[ax + 1];
    m = sqrtf(x * x + y * y);
    if (m <= dz || m < 1e-6f) return 0;
    s = (m > 1.0f ? 1.0f : m); s = (s - dz) / (1.0f - dz);
    if (c->stick_curve != 1.0f) s = powf(s, c->stick_curve);
    x = x / m * s * c->stick_sens_x; y = y / m * s * c->stick_sens_y;
    return clampf((axis == ax) ? x : y, -1.0f, 1.0f);
}
static float raw_axis_value(const PlayerCfg *c, float v) {
    float a = fabsf(v), dz = c->stick_deadzone;
    if (a <= dz) return 0;
    a = (a - dz) / (1.0f - dz); if (a > 1.0f) a = 1.0f;
    if (c->stick_curve != 1.0f) a = powf(a, c->stick_curve);
    a *= c->stick_sens_x; if (a > 1.0f) a = 1.0f;
    return v < 0 ? -a : a;
}
static int hat_active(int hat, int dir) {       /* hat 0..7 clockwise from up; dir 0 up, 1 right, 2 down, 3 left */
    if (hat < 0) return 0;
    switch (dir) { case 0: return hat == 7 || hat == 0 || hat == 1; case 1: return hat >= 1 && hat <= 3; case 2: return hat >= 3 && hat <= 5; default: return hat >= 5 && hat <= 7; }
}
static int source_is_digital(const Source *s) { return s->type != SRC_PAXIS && s->type != SRC_MAXIS; }

/* level 0..1 of one source; invert_y flips the Y axes of a pad stick (used for the stick-up / stick-down inputs) */
static float source_level(const PlayerCfg *c, const MapState *st, const InputSample *in, const Source *s, int invert_y) {
    int k; float best = 0, v;
    switch (s->type) {
    case SRC_KEY: return (c->use_keyboard && in->keys && in->keys[s->id & 0xFF]) ? 1.0f : 0.0f;
    case SRC_MBTN: return (c->use_mouse && ((in->mouse_buttons >> s->id) & 1)) ? 1.0f : 0.0f;
    case SRC_WHEEL: return (c->use_mouse && st->wheel_on[s->id & 3]) ? 1.0f : 0.0f;
    case SRC_MAXIS: {
        int o; if (!c->use_mouse) return 0;
        o = st->mouse_out[s->id ? 1 : 0] * (s->sign < 0 ? -1 : 1);
        return o > 0 ? (float)o / N64_STICK_MAX : 0.0f;
    }
    case SRC_PBTN:
        for (k = 0; k < in->npad; k++) {
            const PadState *p = in->pad[k]; if (!p || !p->connected) continue;
            if (s->id < PB_COUNT) { if ((p->buttons >> s->id) & 1) return 1.0f; }
            else { int n = s->id - 32; if (n >= 0 && n < RAW_BUTTONS && ((p->raw_buttons[n >> 5] >> (n & 31)) & 1)) return 1.0f; }
        }
        return 0.0f;
    case SRC_PAXIS:
        for (k = 0; k < in->npad; k++) {
            const PadState *p = in->pad[k]; if (!p || !p->connected) continue;
            if (s->id < PA_COUNT) {
                int sign = s->sign;
                if (invert_y && (s->id == PA_LY || s->id == PA_RY)) sign = -sign;
                v = map_pad_axis(c, p, s->id);
                if (s->id >= PA_LT) v = v > 0 ? v : 0; else v = sign < 0 ? -v : v;
            } else if (s->id >= 8 && s->id < 8 + RAW_AXES) {
                int sign = s->sign;
                if (invert_y && s->id == 9) sign = -sign;
                v = raw_axis_value(c, p->raw_axis[s->id - 8]); v = sign < 0 ? -v : v;
            } else v = 0;
            if (v > best) best = v;
        }
        return best > 1.0f ? 1.0f : best < 0 ? 0.0f : best;
    case SRC_PHAT:
        for (k = 0; k < in->npad; k++) { const PadState *p = in->pad[k]; if (p && p->connected && s->id < RAW_HATS && hat_active(p->hat[s->id], s->sign)) return 1.0f; }
        return 0.0f;
    default: return 0.0f;
    }
}
float map_source_level(const PlayerCfg *c, const MapState *st, const InputSample *in, const Source *s) { return source_level(c, st, in, s, 0); }

static int button_active(const PlayerCfg *c, float level, const Source *s) {
    if (source_is_digital(s)) return level > 0.5f;
    if (s->type == SRC_MAXIS) return level > 0.15f;
    if (s->id == PA_LT || s->id == PA_RT) return level >= c->trigger_threshold;
    return level >= c->axis_threshold;
}

/* one axis of the mouse look.  The motion is queued as degrees of turn ("pending"); every sample delivers as much of it as one poll interval of the game's turn rate
 * allows: the stick value n whose rate (k * n^3 degrees per second, see input_core.h) turns the view by the pending angle during dt.  The rest stays queued (capped by
 * the backlog, so a flick does not keep turning for seconds), rounding errors are carried over, and a sub-count motion is never lost.  The game subtracts its own dead
 * zone of 3 from the stick, so the delivered n arrives as n + 3. */
static int mouse_axis(float *pend, float *smooth, float counts, float sens, float smoothing, float dt, float k, float backlog) {
    float q = counts * sens * MOUSE_DEG_PER_COUNT, w, e, n_f; int n; int sign;
    if (smoothing > 0.0f) { *smooth += (q - *smooth) * (1.0f - smoothing); q = *smooth; } else *smooth = 0;
    *pend += q;
    if (*pend > backlog) *pend = backlog; else if (*pend < -backlog) *pend = -backlog;
    if (fabsf(*pend) < 1e-6f) { *pend = 0; return 0; }
    sign = *pend < 0 ? -1 : 1;
    w = fabsf(*pend) / dt;                                   /* degrees per second needed to deliver it within one interval */
    e = cbrtf(w / k);
    n_f = e + 0.5f; n = (int)n_f;
    if (n > N64_STICK_MAX - GAME_STICK_DEADZONE) n = N64_STICK_MAX - GAME_STICK_DEADZONE;
    if (n < 1) return 0;                                      /* below the first stick step: stays queued until more motion arrives */
    *pend -= (float)sign * k * (float)n * (float)n * (float)n * dt;
    if (*pend * (float)sign < 0 && fabsf(*pend) < 1e-3f) *pend = 0;
    return sign * (n + GAME_STICK_DEADZONE);
}
void map_eval(const PlayerCfg *c, MapState *st, const InputSample *in, N64Pad *out) {
    double dt = in->dt > 0 ? in->dt : 1.0 / 60.0; int d, i, k; float stick[4]; unsigned buttons = 0;
    if (dt < 1.0 / 120.0) dt = 1.0 / 120.0; if (dt > 0.1) dt = 0.1;
    /* mouse look */
    if (c->use_mouse && in->mouse_valid) {
        st->mouse_out[0] = mouse_axis(&st->acc[0], &st->smooth[0], in->mouse_dx, c->mouse_sens_x, c->mouse_smooth, (float)dt, GAME_YAW_RATE_PER_E3, c->mouse_backlog);
        st->mouse_out[1] = mouse_axis(&st->acc[1], &st->smooth[1], in->mouse_dy * (c->mouse_invert_y ? -1.0f : 1.0f), c->mouse_sens_y, c->mouse_smooth, (float)dt, GAME_PITCH_RATE_PER_E3, c->mouse_backlog);
    } else { st->acc[0] = st->acc[1] = st->smooth[0] = st->smooth[1] = 0; st->mouse_out[0] = st->mouse_out[1] = 0; }
    /* wheel: every tick becomes one press of one sample, followed by a release so the game sees separate presses */
    for (d = 0; d < 4; d++) {
        if (c->use_mouse) st->wheel_pend[d] += in->wheel[d];
        if (st->wheel_pend[d] > 4) st->wheel_pend[d] = 4;
        if (st->wheel_on[d]) st->wheel_on[d] = 0; else if (st->wheel_pend[d] > 0) { st->wheel_pend[d]--; st->wheel_on[d] = 1; }
    }
    for (i = 0; i < 4; i++) stick[i] = 0;
    for (i = 0; i < IN_COUNT; i++) {
        const Binding *b = &c->bind[i];
        for (k = 0; k < b->n; k++) {
            const Source *s = &b->s[k]; float lv;
            if (!ctx_ok(s, in->gameplay)) continue;
            if (i < IN_BUTTONS) {
                lv = source_level(c, st, in, s, 0);
                if (lv > 0 && button_active(c, lv, s)) { buttons |= g_in_mask[i]; break; }
            } else {
                int dir = i - IN_STICK_LEFT; float u;
                lv = source_level(c, st, in, s, (i == IN_STICK_UP || i == IN_STICK_DOWN) ? c->stick_invert_y : 0);
                if (s->type == SRC_MAXIS) u = lv * N64_STICK_MAX;
                else if (s->type == SRC_PAXIS) u = lv * N64_STICK_MAX;
                else u = lv > 0.5f ? (float)c->key_stick : 0.0f;
                if (u > stick[dir]) stick[dir] = u;
            }
        }
    }
    { int x = (int)floorf(stick[1] - stick[0] + 0.5f), y = (int)floorf(stick[2] - stick[3] + 0.5f);
      out->x = (signed char)clampi(x, -N64_STICK_MAX, N64_STICK_MAX); out->y = (signed char)clampi(y, -N64_STICK_MAX, N64_STICK_MAX); }
    out->buttons = (unsigned short)buttons;
    st->valid = 1;
}

/* ------------------------------------------------------------------ capture helper of the tool */
int pad_detect_source(const PadState *base, const PadState *cur, int raw_names, Source *out) {
    static const int order[PB_COUNT] = { PB_A, PB_B, PB_X, PB_Y, PB_LB, PB_RB, PB_START, PB_BACK, PB_LS, PB_RS, PB_DUP, PB_DDOWN, PB_DLEFT, PB_DRIGHT, PB_GUIDE };
    int i; Source s;
    memset(&s, 0, sizeof s);
    if (!cur || !cur->connected) return 0;
    if (!raw_names) {
        unsigned nb = base ? base->buttons : 0;
        for (i = 0; i < PB_COUNT; i++) { int b = order[i]; if (((cur->buttons >> b) & 1) && !((nb >> b) & 1)) { s.type = SRC_PBTN; s.id = (unsigned short)b; *out = s; return 1; } }
        for (i = PA_LT; i <= PA_RT; i++) { float d = cur->axis[i] - (base ? base->axis[i] : 0.0f); if (d > 0.55f) { s.type = SRC_PAXIS; s.id = (unsigned short)i; s.sign = 1; *out = s; return 1; } }
        for (i = 0; i < PA_LT; i++) {
            float d = cur->axis[i] - (base ? base->axis[i] : 0.0f);
            if (d > 0.6f || d < -0.6f) { s.type = SRC_PAXIS; s.id = (unsigned short)i; s.sign = (signed char)(d > 0 ? 1 : -1); *out = s; return 1; }
        }
        return 0;
    }
    for (i = 0; i < RAW_BUTTONS; i++) {
        unsigned now = (cur->raw_buttons[i >> 5] >> (i & 31)) & 1, was = base ? (base->raw_buttons[i >> 5] >> (i & 31)) & 1 : 0;
        if (now && !was) { s.type = SRC_PBTN; s.id = (unsigned short)(32 + i); *out = s; return 1; }
    }
    for (i = 0; i < RAW_HATS; i++) {
        int dir; signed char h = cur->hat[i], hb = base ? base->hat[i] : (signed char)-1;
        if (h < 0 || h == hb) continue;
        if (h == 0 || h == 7) dir = 0; else if (h == 1 || h == 2 || h == 3) dir = 1; else if (h == 4 || h == 5) dir = 2; else dir = 3;
        s.type = SRC_PHAT; s.id = (unsigned short)i; s.sign = (signed char)dir; *out = s; return 1;
    }
    for (i = 0; i < RAW_AXES; i++) {
        float d = cur->raw_axis[i] - (base ? base->raw_axis[i] : 0.0f);
        if (d > 0.6f || d < -0.6f) { s.type = SRC_PAXIS; s.id = (unsigned short)(8 + i); s.sign = (signed char)(d > 0 ? 1 : -1); *out = s; return 1; }
    }
    return 0;
}