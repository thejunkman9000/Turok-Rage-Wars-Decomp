/* Locating the game's ROM image.
 *
 * The port needs a ROM image of the original game (Turok: Rage Wars, USA, version 1.1) for the game code and all assets; it is not part of this
 * program and is never distributed with it.  rom_find() looks, in this order, at
 *     TUROK_ROM=<file>                      (an explicit choice)
 *     baserom.us.v11.z64 in the working directory, then next to the exe, then in the data folder (the copy made by an earlier start)
 *     any *.z64 / *.n64 / *.v64 of exactly 8 MiB in the working directory and next to the exe (names like "Turok - Rage Wars (USA) (Rev 1).z64")
 * Every candidate is checked by its SHA-1 (after converting a byte-swapped .v64 / little-endian .n64 image to the big-endian layout the game uses).
 * When nothing fits, the player is asked: an explanation, then a file dialog; a wrong file (another release, another game) is explained and the
 * dialog opens again.  The ROM that was accepted is copied into the data folder (%LOCALAPPDATA%\TurokRageWars) in .z64 form, so the next start
 * does not ask again, wherever the original lives.  Cancelling ends the program quietly.
 *
 * TUROK_NOPROMPT=1 never opens a dialog (automated runs): the result is then simply "not found".
 */
#include <windows.h>
#include <commdlg.h>
#include <wincrypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "comdlg32.lib")

extern int port_data_dir(wchar_t *out, int n);
extern int port_setting_str(const wchar_t *sec, const wchar_t *key, wchar_t *out, int n);
extern void port_set_setting_str(const wchar_t *sec, const wchar_t *key, const wchar_t *v);

#define ROM_NAME L"baserom.us.v11.z64"
#define ROM_BYTES 0x800000u

static const struct { const char *sha1; const wchar_t *name; int supported; } KNOWN[] = {
    { "037fb397cee2669048ed6b762a64698de4a4d88a", L"Turok: Rage Wars (USA) version 1.1", 1 },
    { "9f8cb190831945f6f707aa8c2b20e04fa4276795", L"Turok: Rage Wars (USA) version 1.0", 0 },
    { "46b474fac79a4b21535bb6c78ce3039a2c202359", L"Turok: Rage Wars (Europe)", 0 },
    { "a6daacbd0e7f77c73208cf494aefc24703060b17", L"Turok: Rage Wars (Germany)", 0 },
};

/* ------------------------------------------------------------------ pieces (also used by port/tests/rom_selftest.c) */
int rom_sha1_hex(const void *data, unsigned n, char out[41]) {
    HCRYPTPROV prov; HCRYPTHASH h; BYTE d[20]; DWORD len = 20; int ok = 0, i;
    if (!CryptAcquireContextA(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) return 0;
    if (CryptCreateHash(prov, CALG_SHA1, 0, 0, &h)) {
        if (CryptHashData(h, (const BYTE *)data, n, 0) && CryptGetHashParam(h, HP_HASHVAL, d, &len, 0) && len == 20) ok = 1;
        CryptDestroyHash(h);
    }
    CryptReleaseContext(prov, 0);
    if (ok) for (i = 0; i < 20; i++) sprintf(out + 2 * i, "%02x", d[i]);
    return ok;
}

/* 1 when the image is an N64 ROM; it is then converted in place to the big-endian (.z64) byte order.  2 = it was converted. */
int rom_normalize(unsigned char *d, unsigned n) {
    unsigned i;
    if (n < 0x1000 || (n & 3)) return 0;
    if (d[0] == 0x80 && d[1] == 0x37 && d[2] == 0x12 && d[3] == 0x40) return 1;                               /* .z64: big-endian */
    if (d[0] == 0x37 && d[1] == 0x80 && d[2] == 0x40 && d[3] == 0x12) {                                       /* .v64: every 16-bit half swapped */
        for (i = 0; i < n; i += 2) { unsigned char t = d[i]; d[i] = d[i + 1]; d[i + 1] = t; }
        return 2;
    }
    if (d[0] == 0x40 && d[1] == 0x12 && d[2] == 0x37 && d[3] == 0x80) {                                       /* .n64: little-endian words */
        for (i = 0; i < n; i += 4) { unsigned char a = d[i], b = d[i + 1]; d[i] = d[i + 3]; d[i + 1] = d[i + 2]; d[i + 2] = b; d[i + 3] = a; }
        return 2;
    }
    return 0;
}

static unsigned char *read_file(const wchar_t *path, unsigned *size) {
    HANDLE f = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    LARGE_INTEGER sz; unsigned char *b; DWORD got = 0;
    if (f == INVALID_HANDLE_VALUE) return NULL;
    if (!GetFileSizeEx(f, &sz) || sz.QuadPart <= 0 || sz.QuadPart > 64 * 1024 * 1024) { CloseHandle(f); return NULL; }
    b = (unsigned char *)malloc((size_t)sz.QuadPart);
    if (!b || !ReadFile(f, b, (DWORD)sz.QuadPart, &got, NULL) || got != (DWORD)sz.QuadPart) { free(b); CloseHandle(f); return NULL; }
    CloseHandle(f);
    *size = (unsigned)sz.QuadPart;
    return b;
}

/* Loads and checks one file.  Returns the big-endian image when it is the supported release, else NULL and *why says what it is:
 *   0 not readable   1 not an N64 ROM   2 wrong size   3 a release this port does not support (*which = KNOWN index)   4 an N64 ROM of something else */
unsigned char *rom_load_checked(const wchar_t *path, unsigned *size, int *why, int *which) {
    unsigned n = 0; unsigned char *b = read_file(path, &n); char hex[41]; int i;
    *why = 0; *which = -1;
    if (!b) return NULL;
    if (!rom_normalize(b, n)) { *why = 1; free(b); return NULL; }
    if (n != ROM_BYTES) { *why = 2; free(b); return NULL; }
    if (!rom_sha1_hex(b, n, hex)) { *why = 4; free(b); return NULL; }
    for (i = 0; i < (int)(sizeof KNOWN / sizeof KNOWN[0]); i++)
        if (!strcmp(hex, KNOWN[i].sha1)) {
            if (KNOWN[i].supported) { *size = n; return b; }
            *why = 3; *which = i; free(b); return NULL;
        }
    *why = 4; free(b);
    return NULL;
}

/* ------------------------------------------------------------------ the search */
static unsigned char *g_img; static unsigned g_img_size; static int g_done;

static unsigned char *try_path(const wchar_t *p, unsigned *size, const char *how) {
    int why, which; unsigned char *b = rom_load_checked(p, size, &why, &which);
    if (b) { fprintf(stderr, "rom: %ls (%s)\n", p, how); return b; }
    if (why) fprintf(stderr, "rom: %ls is not usable (%s)\n", p, how);
    return NULL;
}
static void exe_dir(wchar_t *d) {
    wchar_t *s; GetModuleFileNameW(NULL, d, MAX_PATH);
    s = wcsrchr(d, L'\\'); if (s) *s = 0;
}
static unsigned char *scan_dir(const wchar_t *dir, unsigned *size) {
    static const wchar_t *pat[] = { L"*.z64", L"*.n64", L"*.v64" };
    int k, tried = 0;
    for (k = 0; k < 3; k++) {
        wchar_t q[MAX_PATH]; WIN32_FIND_DATAW fd; HANDLE h;
        if (wcslen(dir) + 8 >= MAX_PATH) return NULL;
        swprintf(q, MAX_PATH, L"%ls\\%ls", dir, pat[k]);
        h = FindFirstFileW(q, &fd);
        if (h == INVALID_HANDLE_VALUE) continue;
        do {
            wchar_t f[MAX_PATH]; unsigned char *b;
            if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || fd.nFileSizeHigh || fd.nFileSizeLow != ROM_BYTES) continue;
            if (++tried > 16) break;
            if (wcslen(dir) + wcslen(fd.cFileName) + 2 >= MAX_PATH) continue;
            swprintf(f, MAX_PATH, L"%ls\\%ls", dir, fd.cFileName);
            b = try_path(f, size, "found by its contents");
            if (b) { FindClose(h); return b; }
        } while (FindNextFileW(h, &fd));
        FindClose(h);
    }
    return NULL;
}

static unsigned char *silent_search(unsigned *size) {
    wchar_t t[MAX_PATH], ed[MAX_PATH], cwd[MAX_PATH], dd[MAX_PATH]; unsigned char *b; DWORD k;
    k = GetEnvironmentVariableW(L"TUROK_ROM", t, MAX_PATH);
    if (k && k < MAX_PATH && (b = try_path(t, size, "TUROK_ROM"))) return b;
    if ((b = try_path(ROM_NAME, size, "working directory"))) return b;
    exe_dir(ed);
    swprintf(t, MAX_PATH, L"%ls\\%ls", ed, ROM_NAME);
    if ((b = try_path(t, size, "next to the exe"))) return b;
    if (port_data_dir(dd, MAX_PATH)) {
        swprintf(t, MAX_PATH, L"%ls\\%ls", dd, ROM_NAME);
        if ((b = try_path(t, size, "data folder"))) return b;
    }
    if (GetCurrentDirectoryW(MAX_PATH, cwd) && (b = scan_dir(cwd, size))) return b;
    if ((b = scan_dir(ed, size))) return b;
    return NULL;
}

/* ------------------------------------------------------------------ asking the player */
static int install_copy(const unsigned char *img, unsigned n) {
    wchar_t dd[MAX_PATH], dst[MAX_PATH], tmp[MAX_PATH]; HANDLE f; DWORD put = 0; int ok;
    if (!port_data_dir(dd, MAX_PATH) || wcslen(dd) + 32 >= MAX_PATH) return 0;
    swprintf(dst, MAX_PATH, L"%ls\\%ls", dd, ROM_NAME);
    swprintf(tmp, MAX_PATH, L"%ls\\%ls.tmp", dd, ROM_NAME);
    f = CreateFileW(tmp, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f == INVALID_HANDLE_VALUE) return 0;
    ok = WriteFile(f, img, n, &put, NULL) && put == n;
    CloseHandle(f);
    if (ok) ok = MoveFileExW(tmp, dst, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH);
    if (!ok) DeleteFileW(tmp);
    return ok;
}

static void say_wrong(int why, int which, const wchar_t *file) {
    wchar_t m[1400], what[400];
    switch (why) {
    case 0: swprintf(what, 400, L"The file could not be read."); break;
    case 1: swprintf(what, 400, L"This is not an N64 ROM image."); break;
    case 2: swprintf(what, 400, L"This is not a complete 8 MB N64 ROM image."); break;
    case 3: swprintf(what, 400, L"This is %ls.\n\nThe port currently runs the USA version 1.1 only.", KNOWN[which].name); break;
    default: swprintf(what, 400, L"This N64 ROM is not Turok: Rage Wars (USA) version 1.1."); break;
    }
    swprintf(m, 1400, L"%ls\n\n%ls\n\nWanted: %ls (SHA-1 %hs).", file, what, KNOWN[0].name, KNOWN[0].sha1);
    MessageBoxW(NULL, m, L"Turok: Rage Wars - wrong ROM", MB_OK | MB_ICONWARNING | MB_SETFOREGROUND);
}

static unsigned char *ask_player(unsigned *size) {
    wchar_t dd[MAX_PATH], msg[1200], last[MAX_PATH], file[MAX_PATH]; OPENFILENAMEW ofn; unsigned char *b;
    int have_dd = port_data_dir(dd, MAX_PATH);
    swprintf(msg, 1200, L"Turok: Rage Wars needs the game's ROM image to run.\n\nThe ROM is not included with this program. Please pick your own copy of "
                        L"Turok: Rage Wars (USA, version 1.1) in the next window (.z64, .n64 or .v64 file).\n\nThe file is checked and copied to\n%ls\nso that this "
                        L"question is asked only once.", have_dd ? dd : L"(no data folder is available: you will be asked again next time)");
    if (MessageBoxW(NULL, msg, L"Turok: Rage Wars", MB_OKCANCEL | MB_ICONINFORMATION | MB_SETFOREGROUND) != IDOK) return NULL;
    for (;;) {
        int why, which;
        memset(&ofn, 0, sizeof ofn); file[0] = 0; last[0] = 0;
        port_setting_str(L"rom", L"lastdir", last, MAX_PATH);
        ofn.lStructSize = sizeof ofn; ofn.lpstrFile = file; ofn.nMaxFile = MAX_PATH;
        ofn.lpstrFilter = L"N64 ROM images (*.z64;*.n64;*.v64;*.rom;*.bin)\0*.z64;*.n64;*.v64;*.rom;*.bin\0All files (*.*)\0*.*\0";
        ofn.lpstrTitle = L"Select the Turok: Rage Wars (USA) v1.1 ROM";
        ofn.lpstrInitialDir = last[0] ? last : NULL;
        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER | OFN_NOCHANGEDIR;
        if (!GetOpenFileNameW(&ofn)) return NULL;
        b = rom_load_checked(file, size, &why, &which);
        if (b) {
            wchar_t *s = wcsrchr(file, L'\\');
            if (s) { *s = 0; port_set_setting_str(L"rom", L"lastdir", file); }
            if (!install_copy(b, *size)) fprintf(stderr, "rom: could not copy the ROM into the data folder (it will be asked for again next time)\n");
            else fprintf(stderr, "rom: copied into the data folder\n");
            return b;
        }
        say_wrong(why, which, file);
    }
}

/* ------------------------------------------------------------------ entry points */
unsigned char *rom_find(unsigned *size) {
    if (!g_done) {
        char e[8];
        g_done = 1;
        g_img = silent_search(&g_img_size);
        if (!g_img && !GetEnvironmentVariableA("TUROK_NOPROMPT", e, sizeof e)) g_img = ask_player(&g_img_size);
        if (!g_img) fprintf(stderr, "rom: no usable ROM (%ls)\n", ROM_NAME);
    }
    if (size) *size = g_img_size;
    return g_img;
}

/* WinMain: 1 = a ROM is available (the player may have been asked), 0 = none: the program should just end */
int rom_ensure(void) { return rom_find(NULL) != NULL; }
