/* Per-user data folder and settings of the port.
 *
 *   <data folder>   %LOCALAPPDATA%\TurokRageWars       (TUROK_DATADIR=<dir> overrides it: tests, portable set-ups)
 *   settings.ini    in the data folder:   [window] fullscreen=0|1      [rom] lastdir=<folder of the last ROM that was picked>
 *
 * The ROM copy made by the first-run dialog (port/rom_find.c) also lives there; the controller pak images stay where port/pak.c puts them.
 * Everything here is best effort: a read-only profile only means that nothing is remembered.
 */
#include <windows.h>
#include <wchar.h>

static wchar_t g_dir[MAX_PATH]; static int g_dir_state;          /* 0 = not looked at yet, 1 = usable, -1 = not available */

static int mkdirs(wchar_t *p) {                                  /* creates every missing level of an absolute path */
    wchar_t *s; DWORD a = GetFileAttributesW(p);
    if (a != INVALID_FILE_ATTRIBUTES) return (a & FILE_ATTRIBUTE_DIRECTORY) != 0;
    for (s = p + 3; *s; s++) if (*s == L'\\' || *s == L'/') { wchar_t c = *s; *s = 0; CreateDirectoryW(p, NULL); *s = c; }
    CreateDirectoryW(p, NULL);
    a = GetFileAttributesW(p);
    return a != INVALID_FILE_ATTRIBUTES && (a & FILE_ATTRIBUTE_DIRECTORY);
}

int port_data_dir(wchar_t *out, int n) {                         /* 1 and the folder (created on first use), or 0 */
    if (!g_dir_state) {
        wchar_t t[MAX_PATH]; DWORD k = GetEnvironmentVariableW(L"TUROK_DATADIR", t, MAX_PATH);
        if (!k || k >= MAX_PATH) {
            k = GetEnvironmentVariableW(L"LOCALAPPDATA", t, MAX_PATH);
            if (!k || k + 16 >= MAX_PATH) { g_dir_state = -1; return 0; }
            wcscat(t, L"\\TurokRageWars");
        }
        g_dir_state = mkdirs(t) ? 1 : -1;
        if (g_dir_state > 0) wcscpy(g_dir, t);
    }
    if (g_dir_state < 0 || (int)wcslen(g_dir) >= n) return 0;
    wcscpy(out, g_dir);
    return 1;
}

static int ini_path(wchar_t *p) {
    wchar_t d[MAX_PATH];
    if (!port_data_dir(d, MAX_PATH) || wcslen(d) + 14 >= MAX_PATH) return 0;
    wcscpy(p, d); wcscat(p, L"\\settings.ini");
    return 1;
}

int port_setting_int(const wchar_t *sec, const wchar_t *key, int def) {
    wchar_t p[MAX_PATH];
    if (!ini_path(p)) return def;
    return (int)GetPrivateProfileIntW(sec, key, def, p);
}
void port_set_setting_int(const wchar_t *sec, const wchar_t *key, int v) {
    wchar_t p[MAX_PATH], s[16];
    if (!ini_path(p)) return;
    swprintf(s, 16, L"%d", v);
    WritePrivateProfileStringW(sec, key, s, p);
}
int port_setting_str(const wchar_t *sec, const wchar_t *key, wchar_t *out, int n) {      /* 1 when the key exists */
    wchar_t p[MAX_PATH];
    out[0] = 0;
    if (!ini_path(p)) return 0;
    GetPrivateProfileStringW(sec, key, L"", out, (DWORD)n, p);
    return out[0] != 0;
}
void port_set_setting_str(const wchar_t *sec, const wchar_t *key, const wchar_t *v) {
    wchar_t p[MAX_PATH];
    if (ini_path(p)) WritePrivateProfileStringW(sec, key, v, p);
}
