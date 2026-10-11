/* Virtual Controller Pak for the Windows port.
 *
 * What this file is: a model of the N64's serial interface (SI) and the PIF's Joybus engine, with a controller attached to each of the four
 * ports and an optional accessory (memory pak = Controller Pak, or rumble pak) in each controller.  The game's own libultra code builds Joybus
 * command blocks in 64-byte PIF RAM images (__osPfsPifRam, __osMotorStartData ...) and "DMAs" them with __osSiRawStartDma; the shim hands every
 * such transfer to pak_si_dma(), which behaves like the real PIF:
 *   - an RDRAM->PIF transfer copies the 64 bytes in and, when the control byte (offset 63) has bit 0 set, parses the command list;
 *   - a PIF->RDRAM transfer executes the parsed command list (this is when the controllers are talked to) and copies the 64 bytes out.
 * Command list (see n64brew "PIF-NUS"): 0x00 = skip a channel, 0xFF = no-op, 0xFE = end, 0xFD = channel reset; otherwise a handshake
 *   TX RX tx[TX] rx[RX]  (TX bit 7 = skip, bit 6 = reset; the PIF writes error flags into the top bits of RX: 0x80 = no device, 0x40 = timeout).
 * Channels 0-3 are the controller ports; channel 4 (cartridge EEPROM) is not populated.
 * Controller commands implemented: 0x00 / 0xFF identify (reply 05 00 + status byte), 0x01 read buttons (zeros unless a callback is installed),
 * 0x02 read 32 bytes of accessory memory, 0x03 write 32 bytes; address = 11-bit block number << 5 | 5-bit CRC; data CRC = CRC-8 (poly 0x85).
 *   memory pak : 0x0000-0x7FFF = 32 KiB SRAM, 0x8000-0xFFFF ignores writes and reads 0 (so the SDK's bank-select writes are harmless and the
 *                rumble probe fails with PFS_ERR_DEVICE);
 *   rumble pak : 0x8000-0xBFFF = identification (reads 0x80 once 0x80 has been written there, else 0), 0xC000-0xFFFF = motor (bit 0 = on),
 *                0x0000-0x7FFF reads 0.
 * The status byte of the identify reply (OSContStatus.status): 1 = accessory present, 2 = no accessory, 3 = a new accessory was inserted since the
 * last identify (cleared by the next identify), +4 = address CRC error in the previous command.  A freshly inserted accessory ignores reads and
 * writes (as if absent) until an identify has been seen, which is what makes libultra report PFS_ERR_NEW_PACK after a hot swap.
 *
 * The memory pak images live in files (Project64 compatible, see below) and are written back atomically by a low-priority thread.
 *
 * Configuration (environment variables win over the ini file, which wins over the defaults; see docs/PORT_STATUS.md "Controller Pak"):
 *   TUROK_PAK=0|1          master switch (default 1; 0 = no accessory anywhere, the pre-pak behaviour)
 *   TUROK_SAVEDIR=<dir>    folder of the pak images (default <exe folder>\saves)
 *   TUROK_PAK1..4=<file>   explicit image file for a port (raw .mpk/.mem, DexDrive .n64, 4-in-1 .mpk, ...; "file#k" selects slice k of a multi-pak file)
 *   TUROK_PJ64_SAVE=<dir>  a Project64 Save folder to search for "<game>_Cont_<n>.mpk" (and "<game>.mpk" for port 1)
 *   TUROK_PAK1_TYPE..4=none|memory|rumble   accessory in the port at start-up (default memory)
 *   TUROK_PAK_INI=<file>   ini file (default <exe folder>\turok_pak.ini)
 *   TUROK_PAK_DELAY=<ms>   write-back debounce (default 300)
 *   TUROK_PAKLOG=1         log every accessory transaction
 * Runtime: Ctrl+F5..F8 toggle a memory pak in port 1..4, Ctrl+Shift+F5..F8 a rumble pak; a file port_pak.txt in the working directory is
 * polled for scripted commands ("insert 2 memory", "insert 1 rumble", "remove 3", "flush", "reload 1", "format 1", "status").
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <wchar.h>
#include <wctype.h>

#ifdef PAK_STANDALONE_TEST
int g_test_conn = 15;                                     /* bit n = controller n answers */
static int port_pad_connected(int p) { return (g_test_conn >> p) & 1; }
static int oracle_enabled(void) { return 0; }
static unsigned char *port_rom(unsigned *size) { if (size) *size = 0; return NULL; }
#else
extern int port_pad_connected(int port);                  /* os_shim.c */
extern int oracle_enabled(void);                          /* oracle.c */
extern unsigned char *port_rom(unsigned *size);           /* game_glue.c */
#endif

#define PAK_SIZE 0x8000u
#define PAK_NONE 0
#define PAK_MEMORY 1
#define PAK_RUMBLE 2
#define MAX_FILES 8
#define MAX_FILE_BYTES (16u * 1024u * 1024u)

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* log                                                                                                                                   */
static int g_trace;                                        /* TUROK_PAKLOG=1 */
static volatile LONG g_last_dma_tick, g_active, g_sync;      /* TUROK_PAKSYNC=1: "pak: idle" is logged when the SI has been quiet for 250 ms after activity (test scripts wait for it) */
static void pak_log(const char *fmt, ...) {
    char b[700]; va_list ap; int n;
    va_start(ap, fmt); n = _vsnprintf(b, sizeof b - 1, fmt, ap); va_end(ap);
    if (n < 0 || n > (int)sizeof b - 1) n = (int)sizeof b - 1;
    b[n] = 0;
    fprintf(stderr, "pak: %s\n", b);
}
#define PTRACE(...) do { if (g_trace) pak_log(__VA_ARGS__); } while (0)

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* CRCs and the pak file system layout (pure functions; tools/pak_tool.py implements the same formulas independently)                    */

/* 5-bit address CRC of the 11-bit block number (libultra __osContAddressCrc: polynomial x^5+x^4+x^2+1, 16 shifts) */
unsigned char pak_crc5(unsigned blk) {
    unsigned crc = 0, a = blk, i;
    for (i = 0; i < 16; i++) {
        unsigned bit = (a >> 10) & 1, tap = (crc & 0x10) ? 0x15 : 0;
        a <<= 1;
        crc = (((crc << 1) & 0xFF) | bit) ^ tap;
    }
    return (unsigned char)(crc & 0x1F);
}
/* CRC-8 of a 32-byte block (libultra __osContDataCrc: polynomial 0x85, seed 0, 33 byte times: the last one shifts in zeros) */
unsigned char pak_crc8(const unsigned char *d) {
    unsigned crc = 0, i; int b;
    for (i = 0; i <= 32; i++)
        for (b = 7; b >= 0; b--) {
            unsigned tap = (crc & 0x80) ? 0x85 : 0, bit = (i < 32) ? ((d[i] >> b) & 1u) : 0;
            crc = (((crc << 1) & 0xFF) | bit) ^ tap;
        }
    return (unsigned char)crc;
}

static unsigned long long g_rng;
static unsigned rnd32(void) {                              /* splitmix64: only used for the serial numbers of new pak images */
    unsigned long long z;
    if (!g_rng) { LARGE_INTEGER q; FILETIME ft; QueryPerformanceCounter(&q); GetSystemTimeAsFileTime(&ft); g_rng = (unsigned long long)q.QuadPart * 0x9E3779B97F4A7C15ull ^ (((unsigned long long)ft.dwHighDateTime << 32) | ft.dwLowDateTime) ^ ((unsigned long long)GetCurrentProcessId() << 40) ^ (unsigned long long)GetTickCount(); }
    z = (g_rng += 0x9E3779B97F4A7C15ull);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ull; z = (z ^ (z >> 27)) * 0x94D049BB133111EBull; z ^= z >> 31;
    return (unsigned)(z >> 16);
}

/* id block checksums: sum of the first 14 big-endian words, and 0xFFF2 minus that (== sum of the inverted words) */
static void id_sums(const unsigned char *b, unsigned *s1, unsigned *s2) {
    unsigned s = 0, i;
    for (i = 0; i < 28; i += 2) s += ((unsigned)b[i] << 8) | b[i + 1];
    *s1 = s & 0xFFFF; *s2 = (0xFFF2u - s) & 0xFFFF;
}
static unsigned fat_sum(const unsigned char *page) {       /* byte sum of entries 5..127 (libultra __osSumcalc over the free entries), the value stored in byte 1 */
    unsigned s = 0, i;
    for (i = 10; i < 256; i++) s += page[i];
    return s & 0xFF;
}
/* A factory-formatted, empty one-bank pak: label area, four copies of the id block (0x20,0x60,0x80,0xC0), the two index tables
 * (pages 1 and 2: byte 1 = checksum 0x71, entries 1-4 = 0 (reserved), entries 5-127 = 3 (free)), an empty note table (pages 3-4), free data pages. */
void pak_format_image(unsigned char *img, const unsigned char serial[24]) {
    static const int idpos[4] = { 0x20, 0x60, 0x80, 0xC0 };
    unsigned char id[32]; unsigned s1, s2, i; int k;
    memset(img, 0, PAK_SIZE);
    img[0] = 0x81; for (i = 1; i < 32; i++) img[i] = (unsigned char)i;              /* label area: 81 01 02 .. 1F, as Project64's template (never used by libultra) */
    memcpy(id, serial, 24); id[24] = 0; id[25] = 1; id[26] = 1; id[27] = 0;          /* device id 0x0001 (bit 0 = controller pak), 1 bank, version 0 */
    id_sums(id, &s1, &s2);
    id[28] = (unsigned char)(s1 >> 8); id[29] = (unsigned char)s1; id[30] = (unsigned char)(s2 >> 8); id[31] = (unsigned char)s2;
    for (k = 0; k < 4; k++) memcpy(img + idpos[k], id, 32);
    for (i = 5; i < 128; i++) { img[0x100 + i * 2] = 0; img[0x100 + i * 2 + 1] = 3; }
    img[0x101] = (unsigned char)fat_sum(img + 0x100);                                 /* 123 * 3 = 369 -> 0x71 */
    memcpy(img + 0x200, img + 0x100, 0x100);
}
static void new_serial(unsigned char s[24]) { int i; for (i = 0; i < 24; i += 4) { unsigned r = rnd32(); s[i] = (unsigned char)r; s[i + 1] = (unsigned char)(r >> 8); s[i + 2] = (unsigned char)(r >> 16); s[i + 3] = (unsigned char)(r >> 24); } }
static int is_blank(const unsigned char *img) {
    unsigned i; unsigned char a = img[0];
    if (a != 0x00 && a != 0xFF) return 0;
    for (i = 1; i < PAK_SIZE; i++) if (img[i] != a) return 0;
    return 1;
}
/* quick structural check for the log: id block copies and the index table checksums */
static int image_check(const unsigned char *img, char *why, size_t cap) {
    unsigned s1, s2; int ok = 0, k;
    static const int idpos[4] = { 0x20, 0x60, 0x80, 0xC0 };
    for (k = 0; k < 4; k++) { const unsigned char *b = img + idpos[k]; id_sums(b, &s1, &s2); if ((((unsigned)b[28] << 8) | b[29]) == s1 && (((unsigned)b[30] << 8) | b[31]) == s2) ok++; }
    if (!ok) { _snprintf(why, cap, "no valid id block"); return 0; }
    for (k = 1; k <= 2; k++) if (fat_sum(img + k * 0x100) != img[k * 0x100 + 1]) { _snprintf(why, cap, "index table %d checksum", k); return 0; }
    _snprintf(why, cap, "%d of 4 id blocks valid", ok);
    return 1;
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* wide-string path helpers                                                                                                              */
static int envw(const wchar_t *name, wchar_t *out, DWORD cap) {
    DWORD n = GetEnvironmentVariableW(name, out, cap);
    if (!(n > 0 && n < cap)) return 0;
    if (n >= 2 && out[0] == L'"' && out[n - 1] == L'"') { memmove(out, out + 1, (n - 2) * sizeof(wchar_t)); out[n - 2] = 0; }      /* cmd's  set X="a b"  keeps the quotes */
    return out[0] != 0;
}
static void wset(wchar_t *dst, size_t cap, const wchar_t *src) { wcsncpy(dst, src, cap - 1); dst[cap - 1] = 0; }
static void wjoin(wchar_t *dst, size_t cap, const wchar_t *dir, const wchar_t *leaf) {
    wchar_t tmp[MAX_PATH * 2]; size_t n;
    wset(tmp, MAX_PATH * 2, dir); n = wcslen(tmp);
    if (n && tmp[n - 1] != L'\\' && tmp[n - 1] != L'/' && n + 1 < MAX_PATH * 2) { tmp[n++] = L'\\'; tmp[n] = 0; }
    wcsncat(tmp, leaf, MAX_PATH * 2 - 1 - n);
    wset(dst, cap, tmp);
}
static void wfull(const wchar_t *in, wchar_t *out, size_t cap) { DWORD n = GetFullPathNameW(in, (DWORD)cap, out, NULL); if (!n || n >= cap) wset(out, cap, in); }
static int path_isdir(const wchar_t *p) { DWORD a = GetFileAttributesW(p); return a != INVALID_FILE_ATTRIBUTES && (a & FILE_ATTRIBUTE_DIRECTORY); }
static int dir_create_all(const wchar_t *dir) {
    wchar_t t[MAX_PATH]; size_t i, n;
    if (path_isdir(dir)) return 1;
    wset(t, MAX_PATH, dir); n = wcslen(t);
    while (n > 0 && (t[n - 1] == L'\\' || t[n - 1] == L'/')) t[--n] = 0;
    for (i = 3; i < n; i++) if (t[i] == L'\\' || t[i] == L'/') { wchar_t c = t[i]; t[i] = 0; if (!path_isdir(t)) CreateDirectoryW(t, NULL); t[i] = c; }
    if (!path_isdir(t)) CreateDirectoryW(t, NULL);
    return path_isdir(dir);
}
static void wnorm(const wchar_t *s, wchar_t *out, size_t cap) {          /* lower-case alphanumerics only: compares game names across the file name sanitising of the various emulators */
    size_t n = 0;
    for (; *s && n + 1 < cap; s++) if (iswalnum(*s)) out[n++] = (wchar_t)towlower(*s);
    out[n] = 0;
}
static void wnarrow(const wchar_t *w, char *out, size_t cap) { if (!WideCharToMultiByte(CP_ACP, 0, w, -1, out, (int)cap, "?", NULL)) out[0] = 0; out[cap - 1] = 0; }

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* configuration                                                                                                                         */
typedef struct {
    int enabled, log, hotkeys, delay_ms, maxdelay_ms;
    wchar_t savedir[MAX_PATH], pj64[MAX_PATH], name[96], pakpath[4][MAX_PATH], ini[MAX_PATH];
    int type[4];
} PakConfig;
static PakConfig g_cfg;

#define INI_MAX 64
static struct { char key[40]; wchar_t val[MAX_PATH]; } g_ini[INI_MAX]; static int g_nini;
static void ini_load(const wchar_t *path) {
    HANDLE h = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, 0, NULL);
    char *buf; DWORD n, got = 0, start; size_t i; wchar_t *w; int wn;
    if (h == INVALID_HANDLE_VALUE) return;
    n = GetFileSize(h, NULL);
    if (n == INVALID_FILE_SIZE || n > 65536) { CloseHandle(h); return; }
    buf = (char *)malloc(n + 2); if (!buf) { CloseHandle(h); return; }
    if (!ReadFile(h, buf, n, &got, NULL)) got = 0;
    CloseHandle(h); buf[got] = 0;
    start = (got >= 3 && (unsigned char)buf[0] == 0xEF && (unsigned char)buf[1] == 0xBB && (unsigned char)buf[2] == 0xBF) ? 3 : 0;
    wn = MultiByteToWideChar(CP_UTF8, 0, buf + start, -1, NULL, 0);
    w = (wchar_t *)malloc(((size_t)wn + 2) * sizeof(wchar_t));
    if (w && wn > 0 && MultiByteToWideChar(CP_UTF8, 0, buf + start, -1, w, wn)) {
        wchar_t *p = w;
        while (*p && g_nini < INI_MAX) {
            wchar_t *line = p, *eq, *e; size_t kl;
            while (*p && *p != L'\n') p++;
            if (*p) *p++ = 0;
            while (*line == L' ' || *line == L'\t' || *line == L'\r') line++;
            if (!*line || *line == L';' || *line == L'#' || *line == L'[') continue;      /* comments are whole lines only: ';' is legal inside values (file names) */
            eq = wcschr(line, L'='); if (!eq) continue;
            *eq = 0; e = eq; while (e > line && (e[-1] == L' ' || e[-1] == L'\t')) *--e = 0;
            eq++; while (*eq == L' ' || *eq == L'\t') eq++;
            e = eq + wcslen(eq); while (e > eq && (e[-1] == L' ' || e[-1] == L'\t' || e[-1] == L'\r')) *--e = 0;
            if (*eq == L'"' && e > eq + 1 && e[-1] == L'"') { *--e = 0; eq++; }
            kl = wcslen(line); if (kl >= sizeof g_ini[0].key) continue;
            for (i = 0; i < kl; i++) g_ini[g_nini].key[i] = (char)towlower(line[i]);
            g_ini[g_nini].key[kl] = 0; wset(g_ini[g_nini].val, MAX_PATH, eq); g_nini++;
        }
    }
    free(w); free(buf);
}
static const wchar_t *ini_get(const char *key) { int i; for (i = 0; i < g_nini; i++) if (!_stricmp(g_ini[i].key, key)) return g_ini[i].val; return NULL; }

static int type_from_ascii(const char *s, int def) {
    if (!s || !*s) return def;
    if (!_stricmp(s, "none") || !_stricmp(s, "off") || !_stricmp(s, "0") || !_stricmp(s, "empty") || !_stricmp(s, "remove")) return PAK_NONE;
    if (!_stricmp(s, "memory") || !_stricmp(s, "mem") || !_stricmp(s, "controller") || !_stricmp(s, "mempak") || !_stricmp(s, "1")) return PAK_MEMORY;
    if (!_stricmp(s, "rumble") || !_stricmp(s, "2")) return PAK_RUMBLE;
    return def;
}
static int parse_type(const wchar_t *w, int def) { char a[32]; if (!w) return def; wnarrow(w, a, sizeof a); return type_from_ascii(a, def); }
static int parse_bool(const wchar_t *s, int def) {
    if (!s || !*s) return def;
    if (!_wcsicmp(s, L"0") || !_wcsicmp(s, L"off") || !_wcsicmp(s, L"no") || !_wcsicmp(s, L"false")) return 0;
    return 1;
}
/* game name used in file names: the 20-byte internal ROM title, trailing blanks removed, / and \ -> '-', ':' -> ';' (Project64 2.x/3.x rule) */
static void rom_title(wchar_t *out, size_t cap) {
    unsigned sz = 0; unsigned char *rom = port_rom(&sz); char t[24]; int i, n = 20;
    memset(t, 0, sizeof t);
    if (rom && sz > 0x34) memcpy(t, rom + 0x20, 20); else strcpy(t, "Turok: Rage Wars");
    while (n > 0 && (t[n - 1] == ' ' || t[n - 1] == 0)) n--;
    t[n] = 0;
    for (i = 0; i < n; i++) { if (t[i] == '/' || t[i] == '\\') t[i] = '-'; else if (t[i] == ':') t[i] = ';'; else if ((unsigned char)t[i] < 32) t[i] = '_'; }
    if (!n) strcpy(t, "Turok Rage Wars");
    MultiByteToWideChar(CP_ACP, 0, t, -1, out, (int)cap);
    out[cap - 1] = 0;
}
extern int port_data_dir(wchar_t *out, int n);                         /* port/settings.c: %LOCALAPPDATA%\TurokRageWars */
static int dir_writable(const wchar_t *dir) {                          /* can a file be created in it (the folder is created when missing)? */
    wchar_t t[MAX_PATH]; HANDLE h;
    if (!dir_create_all(dir)) return 0;
    wjoin(t, MAX_PATH, dir, L"~probe.tmp");
    h = CreateFileW(t, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY | FILE_FLAG_DELETE_ON_CLOSE, NULL);
    if (h == INVALID_HANDLE_VALUE) return 0;
    CloseHandle(h);
    return 1;
}
static int under_program_files(const wchar_t *p) {                     /* Windows would silently redirect a 32-bit program's writes there into a VirtualStore the player cannot find */
    static const wchar_t *vars[] = { L"ProgramFiles", L"ProgramFiles(x86)", L"ProgramW6432" };
    int i;
    for (i = 0; i < 3; i++) {
        wchar_t pf[MAX_PATH]; DWORD n = GetEnvironmentVariableW(vars[i], pf, MAX_PATH);
        if (n && n < MAX_PATH && !_wcsnicmp(p, pf, n) && (p[n] == L'\\' || p[n] == 0)) return 1;
    }
    return 0;
}
static void config_load(void) {
    wchar_t exe[MAX_PATH], exedir[MAX_PATH], v[MAX_PATH], key[48]; wchar_t *sl; int i; const wchar_t *iv; char k8[48];
    memset(&g_cfg, 0, sizeof g_cfg);
    GetModuleFileNameW(NULL, exe, MAX_PATH); wset(exedir, MAX_PATH, exe);
    sl = wcsrchr(exedir, L'\\'); if (sl) *sl = 0;
    if (envw(L"TUROK_PAK_INI", v, MAX_PATH)) wfull(v, g_cfg.ini, MAX_PATH); else wjoin(g_cfg.ini, MAX_PATH, exedir, L"turok_pak.ini");
    ini_load(g_cfg.ini);
    g_cfg.enabled = oracle_enabled() ? 0 : 1;                                            /* the oracle reference runs have no pak (their traces predate it) */
    iv = ini_get("enabled"); if (iv) g_cfg.enabled = parse_bool(iv, g_cfg.enabled);
    if (envw(L"TUROK_PAK", v, MAX_PATH)) g_cfg.enabled = parse_bool(v, g_cfg.enabled);
    g_cfg.hotkeys = 1; iv = ini_get("hotkeys"); if (iv) g_cfg.hotkeys = parse_bool(iv, 1);
    g_cfg.delay_ms = 300; iv = ini_get("writeback_ms"); if (iv) g_cfg.delay_ms = _wtoi(iv);
    if (envw(L"TUROK_PAK_DELAY", v, MAX_PATH)) g_cfg.delay_ms = _wtoi(v);
    if (g_cfg.delay_ms < 0) g_cfg.delay_ms = 0;
    if (g_cfg.delay_ms > 60000) g_cfg.delay_ms = 60000;
    g_cfg.maxdelay_ms = g_cfg.delay_ms * 8 + 1000;                                         /* a pak that is written continuously still reaches the disk */
    g_cfg.log = 0; iv = ini_get("log"); if (iv) g_cfg.log = parse_bool(iv, 0);
    if (envw(L"TUROK_PAKLOG", v, MAX_PATH)) g_cfg.log = parse_bool(v, 0);
    g_trace = g_cfg.log;
    if (envw(L"TUROK_PAKSYNC", v, MAX_PATH)) g_sync = parse_bool(v, 0);
    iv = ini_get("savedir");
    if (envw(L"TUROK_SAVEDIR", v, MAX_PATH)) wfull(v, g_cfg.savedir, MAX_PATH);
    else if (iv && *iv) { if ((iv[0] && iv[1] == L':') || iv[0] == L'\\') wfull(iv, g_cfg.savedir, MAX_PATH); else { wjoin(v, MAX_PATH, exedir, iv); wfull(v, g_cfg.savedir, MAX_PATH); } }
    else {
        wjoin(g_cfg.savedir, MAX_PATH, exedir, L"saves");              /* default: next to the exe (portable); when that place is not for the user's files (Program Files, read-only media) the per-user data folder takes over */
        if (under_program_files(exedir) || !dir_writable(g_cfg.savedir)) { wchar_t dd[MAX_PATH]; if (port_data_dir(dd, MAX_PATH)) wjoin(g_cfg.savedir, MAX_PATH, dd, L"saves"); }
    }
    iv = ini_get("name");
    if (iv && *iv) wset(g_cfg.name, 96, iv); else rom_title(g_cfg.name, 96);
    iv = ini_get("pj64_save"); if (iv && *iv) wset(g_cfg.pj64, MAX_PATH, iv);
    if (envw(L"TUROK_PJ64_SAVE", v, MAX_PATH)) wset(g_cfg.pj64, MAX_PATH, v);
    for (i = 0; i < 4; i++) {
        g_cfg.type[i] = g_cfg.enabled ? PAK_MEMORY : PAK_NONE;
        _snprintf(k8, sizeof k8, "port%d", i + 1); iv = ini_get(k8); if (iv && g_cfg.enabled) g_cfg.type[i] = parse_type(iv, g_cfg.type[i]);
        swprintf(key, 48, L"TUROK_PAK%d_TYPE", i + 1); if (envw(key, v, MAX_PATH) && g_cfg.enabled) g_cfg.type[i] = parse_type(v, g_cfg.type[i]);
        _snprintf(k8, sizeof k8, "pak%d", i + 1); iv = ini_get(k8); if (iv && *iv) wset(g_cfg.pakpath[i], MAX_PATH, iv);
        swprintf(key, 48, L"TUROK_PAK%d", i + 1); if (envw(key, v, MAX_PATH)) wset(g_cfg.pakpath[i], MAX_PATH, v);
    }
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* backing files: a PakFile holds a whole file in memory; each port's pak is a 32 KiB window into one (so DexDrive headers, the other three */
/* paks of a 4-in-1 file, appended comments ... are carried along untouched when the file is written back)                              */
typedef struct {
    wchar_t path[MAX_PATH];                                /* absolute; empty = memory only */
    unsigned char *data; size_t size, disk_size;
    int persist; const char *nopersist_why;
    int dirty, written_gen, gen, need_backup, backed_up, fails;
    DWORD t_first, t_last, t_retry;
    FILETIME mtime; int have_mtime;
    char fmt[64];
} PakFile;
static PakFile g_files[MAX_FILES]; static int g_nfiles;

typedef struct {
    int type;                                              /* accessory plugged into the controller right now */
    int changed, fresh, crc_err;                           /* identify status flags (see the header) */
    int unlocked, motor; unsigned char motor_byte;         /* rumble pak registers */
    PakFile *file; size_t off; int loaded;                 /* memory pak image = file->data + off */
    int slice;                                             /* requested slice of a multi-pak file */
    unsigned long reads, writes, idents, crc_errs, motor_events;
    int vib_sent;
} PakPort;
static PakPort g_port[4];

static CRITICAL_SECTION g_lock;
static volatile LONG g_init_state;                         /* 0 = not started, 1 = running, 2 = ready */
static HANDLE g_thread, g_stop_evt;
static volatile LONG g_shutdown;
static unsigned long g_si_calls; static unsigned long long g_si_ticks, g_si_max;      /* SI transfer statistics (QueryPerformanceCounter ticks) */

static void mark_dirty(PakFile *f) {
    DWORD now = GetTickCount();
    if (!f->persist) return;
    if (!f->dirty) { f->dirty = 1; f->t_first = now; }
    f->t_last = now; f->gen++;
}

static int is_dexdrive(const unsigned char *b, size_t n) { return n >= 12 && !memcmp(b, "123-456-STD", 11) && b[11] == 0; }
/* where does the pak of port `port` live inside a file of `size` bytes?  returns the byte offset, sets *fmt to a name */
static size_t pak_offset(const unsigned char *b, size_t size, int slice, char *fmt) {
    if (size == PAK_SIZE) { strcpy(fmt, "raw 32 KiB (.mpk/.mem)"); return 0; }
    if (size == 0x9040 && is_dexdrive(b, size)) { strcpy(fmt, "DexDrive .n64"); return 0x1040; }
    if (size >= 0x9040 && is_dexdrive(b, size)) { strcpy(fmt, "DexDrive .n64 (oversized)"); return 0x1040; }
    if (size == 0x48800) { strcpy(fmt, "mupen64plus-next .srm (4 paks at 0x800)"); return 0x800 + (size_t)(slice & 3) * PAK_SIZE; }
    if (size > PAK_SIZE && (size % PAK_SIZE) == 0) {
        unsigned n = (unsigned)(size / PAK_SIZE); unsigned s = (unsigned)slice < n ? (unsigned)slice : 0;
        _snprintf(fmt, 40, "%u-in-1 .mpk (slice %u)", n, s + 1); fmt[39] = 0; return (size_t)s * PAK_SIZE;
    }
    if (size > PAK_SIZE) { strcpy(fmt, "raw + appended data"); return 0; }
    strcpy(fmt, "short (padded)");
    return 0;
}

static void file_stat(PakFile *f) {
    WIN32_FILE_ATTRIBUTE_DATA d;
    f->have_mtime = 0;
    if (f->path[0] && GetFileAttributesExW(f->path, GetFileExInfoStandard, &d)) { f->mtime = d.ftLastWriteTime; f->have_mtime = 1; f->disk_size = d.nFileSizeLow; }
}
static void file_read(PakFile *f) {                        /* (re)load f->path; creates a formatted 32 KiB image when the file is absent or empty */
    HANDLE h; DWORD err = 0, got = 0, size = 0; unsigned char *buf = NULL; char path8[MAX_PATH];
    wnarrow(f->path, path8, sizeof path8);
    f->persist = f->path[0] ? 1 : 0; f->nopersist_why = f->persist ? NULL : "memory only"; f->need_backup = 0; f->fmt[0] = 0; f->dirty = 0; f->fails = 0; f->t_retry = 0;
    h = f->path[0] ? CreateFileW(f->path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL) : INVALID_HANDLE_VALUE;
    err = f->path[0] ? GetLastError() : 0;
    if (h != INVALID_HANDLE_VALUE) {
        DWORD hi = 0; size = GetFileSize(h, &hi);
        if (hi || size == INVALID_FILE_SIZE || size > MAX_FILE_BYTES) {
            CloseHandle(h); pak_log("%s: file too large (%lu bytes) to be a pak image, using a session-only pak", path8, (unsigned long)size);
            f->persist = 0; f->nopersist_why = "oversized file left alone"; size = 0; goto fresh;
        }
        buf = (unsigned char *)malloc(size ? size : 1);
        if (!buf || (size && !ReadFile(h, buf, size, &got, NULL)) || got != size) { err = GetLastError(); free(buf); buf = NULL; CloseHandle(h); pak_log("%s: read failed (error %lu), using a session-only pak", path8, err); f->persist = 0; f->nopersist_why = "unreadable file left alone"; goto fresh; }
        CloseHandle(h);
        {   DWORD a = GetFileAttributesW(f->path);
            if (a != INVALID_FILE_ATTRIBUTES && (a & FILE_ATTRIBUTE_READONLY)) { f->persist = 0; f->nopersist_why = "file is read-only"; pak_log("%s: file is read-only - changes are kept for this session only", path8); } }
        if (size == 0) { free(buf); buf = NULL; goto fresh; }          /* an empty file: treat like a missing one (but keep the path) */
        f->data = buf; f->size = size; f->disk_size = size;
        if (size < PAK_SIZE) {                                           /* short: pad with zeros, keep a copy of the original on the first write */
            unsigned char *n = (unsigned char *)calloc(1, PAK_SIZE);
            if (n) { memcpy(n, buf, size); free(buf); f->data = n; f->size = PAK_SIZE; f->need_backup = 1; }
            pak_log("%s: short file (%lu bytes), padded to 32768 - the game's checker will see a damaged pak", path8, (unsigned long)size);
        }
        file_stat(f);
        return;
    }
    if (f->path[0] && err != ERROR_FILE_NOT_FOUND && err != ERROR_PATH_NOT_FOUND) {
        pak_log("%s: cannot open (error %lu) - using a session-only pak, the file is not touched", path8, err);
        f->persist = 0; f->nopersist_why = "file could not be opened";
    }
fresh:
    {   unsigned char serial[24];
        f->data = (unsigned char *)calloc(1, PAK_SIZE); f->size = PAK_SIZE; f->disk_size = 0;
        new_serial(serial); pak_format_image(f->data, serial);
        if (f->persist) { mark_dirty(f); pak_log("%s: new factory-formatted pak image", path8); }
        strcpy(f->fmt, "new");
    }
}
static PakFile *file_open(const wchar_t *path) {
    int i; wchar_t full[MAX_PATH]; PakFile *f;
    if (path && path[0]) { wfull(path, full, MAX_PATH); for (i = 0; i < g_nfiles; i++) if (!_wcsicmp(g_files[i].path, full)) return &g_files[i]; }
    if (g_nfiles >= MAX_FILES) return NULL;
    f = &g_files[g_nfiles++]; memset(f, 0, sizeof *f);
    if (path && path[0]) wset(f->path, MAX_PATH, full);
    file_read(f);
    return f;
}

/* name of the file for port i (index 0..3): explicit path > Project64 folder search > <savedir>\<name>_Cont_<n>.mpk */
static int find_pj64(int i, wchar_t *out) {
    wchar_t game[96], pat[MAX_PATH], dirs[8][MAX_PATH], bestpath[MAX_PATH]; int nd = 0, d, best = 99; WIN32_FIND_DATAW fd; HANDLE h;
    if (!g_cfg.pj64[0] || !path_isdir(g_cfg.pj64)) return 0;
    wnorm(g_cfg.name, game, 96); wset(dirs[nd++], MAX_PATH, g_cfg.pj64);
    wjoin(pat, MAX_PATH, g_cfg.pj64, L"*");
    h = FindFirstFileW(pat, &fd);                                   /* per-game "unique save folders" (<name>-<md5>) */
    if (h != INVALID_HANDLE_VALUE) {
        do if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && fd.cFileName[0] != L'.' && nd < 8) {
            wchar_t nm[MAX_PATH], leaf[MAX_PATH], *dash; wset(leaf, MAX_PATH, fd.cFileName); dash = wcsrchr(leaf, L'-');
            if (!dash) continue;
            *dash = 0; wnorm(leaf, nm, MAX_PATH);
            if (!wcscmp(nm, game)) wjoin(dirs[nd++], MAX_PATH, g_cfg.pj64, fd.cFileName);
        } while (FindNextFileW(h, &fd));
        FindClose(h);
    }
    bestpath[0] = 0;
    for (d = 0; d < nd; d++) {
        wjoin(pat, MAX_PATH, dirs[d], L"*.mpk"); h = FindFirstFileW(pat, &fd);
        if (h == INVALID_HANDLE_VALUE) continue;
        do if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            wchar_t base[MAX_PATH], nm[MAX_PATH], *dot; int rank = 99; size_t bl;
            wset(base, MAX_PATH, fd.cFileName); dot = wcsrchr(base, L'.'); if (dot) *dot = 0;
            bl = wcslen(base);
            if (bl > 7 && !_wcsnicmp(base + bl - 7, L"_Cont_", 6) && base[bl - 1] == (wchar_t)(L'1' + i)) {      /* Project64 2.x / 3.x: "<game>_Cont_<n>.mpk" */
                base[bl - 7] = 0; wnorm(base, nm, MAX_PATH); if (!wcscmp(nm, game)) rank = d == 0 ? 0 : 1;
            } else {                                                                                              /* "<game>.mpk" (Project64 1.6 plugins, mupen64plus: <game>[-md5].mpk): the first pak, or slice n of a 4-in-1 file */
                int usable = (i == 0) || (fd.nFileSizeHigh == 0 && fd.nFileSizeLow > PAK_SIZE && fd.nFileSizeLow % PAK_SIZE == 0 && fd.nFileSizeLow / PAK_SIZE > (unsigned)i);
                wnorm(base, nm, MAX_PATH);
                if (usable) { size_t gl = wcslen(game); if (!wcscmp(nm, game)) rank = d == 0 ? 2 : 3; else if (gl > 4 && !wcsncmp(nm, game, gl)) rank = d == 0 ? 4 : 5; }
            }
            if (rank < best) { best = rank; wjoin(bestpath, MAX_PATH, dirs[d], fd.cFileName); }
        } while (FindNextFileW(h, &fd));
        FindClose(h);
    }
    if (bestpath[0]) { wset(out, MAX_PATH, bestpath); return 1; }
    return 0;
}
static void resolve_path(int i, wchar_t *out, int *slice) {
    *slice = i;
    if (g_cfg.pakpath[i][0]) {
        wchar_t *hash; wset(out, MAX_PATH, g_cfg.pakpath[i]);
        hash = wcsrchr(out, L'#'); if (hash && hash[1] >= L'1' && hash[1] <= L'9' && !hash[2]) { *slice = hash[1] - L'1'; *hash = 0; }
        return;
    }
    if (find_pj64(i, out)) return;
    { wchar_t leaf[160]; swprintf(leaf, 160, L"%ls_Cont_%d.mpk", g_cfg.name, i + 1); wjoin(out, MAX_PATH, g_cfg.savedir, leaf); }
}
/* make sure the port's memory pak image is loaded (lock held) */
static void port_load(int i) {
    PakPort *p = &g_port[i]; wchar_t path[MAX_PATH]; char path8[MAX_PATH], fmt[64]; int slice; PakFile *f;
    if (p->loaded) return;
    p->loaded = 1;
    resolve_path(i, path, &slice);
    if (!g_cfg.pakpath[i][0] && !path_isdir(g_cfg.savedir) && !dir_create_all(g_cfg.savedir)) {
        char sd[MAX_PATH]; wnarrow(g_cfg.savedir, sd, sizeof sd);
        pak_log("cannot create the save folder %s - this session's paks are kept in memory only", sd); path[0] = 0;
    } else if (g_cfg.pakpath[i][0] && path[0]) {                 /* an explicit pak file in a folder that does not exist yet: create the folder like the save folder */
        wchar_t dir[MAX_PATH], *sl; wset(dir, MAX_PATH, path); sl = wcsrchr(dir, L'\\'); if (!sl) sl = wcsrchr(dir, L'/');
        if (sl && sl > dir && !(sl == dir + 2 && dir[1] == L':')) {      /* (not "C:\file": the drive root) */
            *sl = 0;
            if (!path_isdir(dir) && !dir_create_all(dir)) { char d8[MAX_PATH]; wnarrow(dir, d8, sizeof d8); pak_log("port %d: cannot create the folder %s of the pak file - this pak is kept in memory only", i + 1, d8); path[0] = 0; }
        }
    }
    p->file = file_open(path); p->slice = slice;
    f = p->file;
    if (!f) { pak_log("port %d: out of pak file slots", i + 1); return; }
    p->off = pak_offset(f->data, f->size, slice, fmt);
    if (!f->fmt[0] || !strcmp(f->fmt, "new")) { if (strcmp(f->fmt, "new")) { strncpy(f->fmt, fmt, sizeof f->fmt - 1); f->fmt[sizeof f->fmt - 1] = 0; } }
    if (p->off + PAK_SIZE > f->size) {                          /* container shorter than the window: grow it */
        unsigned char *n = (unsigned char *)calloc(1, p->off + PAK_SIZE);
        if (n) { memcpy(n, f->data, f->size); free(f->data); f->data = n; f->size = p->off + PAK_SIZE; f->need_backup = 1; }
    }
    wnarrow(f->path, path8, sizeof path8);
    if (strcmp(f->fmt, "new") && is_blank(f->data + p->off)) {   /* an all-zero / all-FF image is an unformatted card: format it (nothing to lose) */
        unsigned char serial[24]; new_serial(serial); pak_format_image(f->data + p->off, serial); mark_dirty(f);
        pak_log("port %d: %s is blank - formatted", i + 1, path8);
    }
    {   char why[80]; int ok = image_check(f->data + p->off, why, sizeof why);
        if (!ok && f->disk_size && f->persist) f->need_backup = 1;      /* a damaged file that exists: keep the original once before the game's own repair / checker rewrites it */
        pak_log("port %d: %s [%s%s%s] %s: %s", i + 1, f->path[0] ? path8 : "(memory only)", f->fmt, f->persist ? "" : ", NOT SAVED - ", f->persist ? "" : (f->nopersist_why ? f->nopersist_why : ""), ok ? "valid" : "DAMAGED", why);
    }
}

/* write-back --------------------------------------------------------------------------------------------------------------------------- */
static int write_atomic(const wchar_t *path, const unsigned char *data, size_t size, DWORD *err) {
    wchar_t tmp[MAX_PATH + 24]; HANDLE h; DWORD n = 0; BOOL ok;
    _snwprintf(tmp, MAX_PATH + 24, L"%ls.tmp%lu", path, GetCurrentProcessId()); tmp[MAX_PATH + 23] = 0;
    h = CreateFileW(tmp, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) { *err = GetLastError(); return 0; }
    ok = WriteFile(h, data, (DWORD)size, &n, NULL) && n == size && FlushFileBuffers(h);
    if (!ok) *err = GetLastError();
    CloseHandle(h);
    if (!ok) { DeleteFileW(tmp); return 0; }
    if (!MoveFileExW(tmp, path, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) { *err = GetLastError(); DeleteFileW(tmp); return 0; }
    return 1;
}
/* write one dirty file now (lock NOT held on entry).  returns 1 when the file is clean afterwards */
static int file_flush(PakFile *f, int final) {
    unsigned char *copy; size_t size; int gen; wchar_t path[MAX_PATH]; DWORD err = 0; int ok; char path8[MAX_PATH]; int backup;
    EnterCriticalSection(&g_lock);
    if (!f->dirty || !f->persist) { LeaveCriticalSection(&g_lock); return 1; }
    if (!final && f->t_retry && (int)(GetTickCount() - f->t_retry) < 0) { LeaveCriticalSection(&g_lock); return 0; }
    size = f->size; gen = f->gen; wset(path, MAX_PATH, f->path); backup = f->need_backup && !f->backed_up && f->disk_size;
    copy = (unsigned char *)malloc(size);
    if (!copy) { LeaveCriticalSection(&g_lock); return 0; }
    memcpy(copy, f->data, size);
    LeaveCriticalSection(&g_lock);
    wnarrow(path, path8, sizeof path8);
    if (backup) {                                          /* a damaged / short / oversized original is kept once as <file>.orig before we replace it */
        wchar_t bak[MAX_PATH + 8]; _snwprintf(bak, MAX_PATH + 8, L"%ls.orig", path); bak[MAX_PATH + 7] = 0;
        if (!CopyFileW(path, bak, TRUE) && GetLastError() != ERROR_FILE_EXISTS) pak_log("%s: could not back up the original (error %lu)", path8, GetLastError());
        else pak_log("%s: original kept as .orig", path8);
    }
    ok = write_atomic(path, copy, size, &err);
    free(copy);
    EnterCriticalSection(&g_lock);
    if (ok) {
        f->fails = 0; f->t_retry = 0; f->written_gen = gen; f->disk_size = size; if (backup) f->backed_up = 1;
        if (f->gen == gen) f->dirty = 0;
        file_stat(f);
        PTRACE("wrote %s (%lu bytes)", path8, (unsigned long)size);
    } else {
        f->fails++;
        if (f->fails == 1 || f->fails % 20 == 0) pak_log("%s: write failed (error %lu), will retry", path8, err);
        f->t_retry = GetTickCount() + (DWORD)(f->fails < 6 ? 500u << f->fails : 16000u);
        if (!f->t_retry) f->t_retry = 1;
    }
    ok = !f->dirty;
    LeaveCriticalSection(&g_lock);
    return ok;
}
void pak_flush_all(int final) {
    int i, n;
    if (g_init_state != 2) return;
    EnterCriticalSection(&g_lock); n = g_nfiles; LeaveCriticalSection(&g_lock);
    for (i = 0; i < n; i++) file_flush(&g_files[i], final);
}
static void flush_due(void) {
    int i, n; DWORD now = GetTickCount();
    EnterCriticalSection(&g_lock); n = g_nfiles; LeaveCriticalSection(&g_lock);
    for (i = 0; i < n; i++) {
        PakFile *f = &g_files[i]; int due;
        EnterCriticalSection(&g_lock);
        due = f->dirty && f->persist && ((int)(now - f->t_last) >= g_cfg.delay_ms || (int)(now - f->t_first) >= g_cfg.maxdelay_ms);
        LeaveCriticalSection(&g_lock);
        if (due) file_flush(f, 0);
    }
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* the accessories                                                                                                                       */
static unsigned char *port_img(PakPort *p) { return p->file ? p->file->data + p->off : NULL; }

/* set what is plugged into a port (lock held) */
static void port_set_type(int i, int type, const char *why) {
    PakPort *p = &g_port[i]; static const char *nm[3] = { "empty", "memory pak", "rumble pak" };
    if (p->type == type) return;
    p->type = type; p->changed = 1; p->fresh = (type != PAK_NONE); p->unlocked = 0; p->motor = 0; p->motor_byte = 0; p->crc_err = 0;
    if (type == PAK_MEMORY) {
        if (p->loaded && p->file && !p->file->dirty && p->file->path[0] && p->file->persist) {          /* inserted again: pick up edits made to the file meanwhile */
            WIN32_FILE_ATTRIBUTE_DATA d;
            if (GetFileAttributesExW(p->file->path, GetFileExInfoStandard, &d) && p->file->have_mtime && (CompareFileTime(&d.ftLastWriteTime, &p->file->mtime) != 0 || d.nFileSizeLow != p->file->disk_size)) {
                PakFile *f = p->file; char fmt[64]; free(f->data); f->data = NULL; file_read(f); p->off = pak_offset(f->data, f->size, p->slice, fmt);
                if (strcmp(f->fmt, "new")) { strncpy(f->fmt, fmt, sizeof f->fmt - 1); f->fmt[sizeof f->fmt - 1] = 0; }
                if (p->off + PAK_SIZE > f->size) p->off = 0;
                pak_log("port %d: image file changed on disk - reloaded", i + 1);
            }
        }
        port_load(i);
    }
    pak_log("port %d: %s (%s)", i + 1, nm[type], why);
}

/* identify reply status byte (lock held) */
static unsigned char ident_status(PakPort *p) {
    unsigned char st = p->type == PAK_NONE ? 2 : (p->changed ? 3 : 1);
    if (p->crc_err) st |= 4;
    p->changed = 0; p->fresh = 0; p->crc_err = 0; p->idents++;
    return st;
}
static void rd_block(PakPort *p, unsigned blk, unsigned char *out) {
    memset(out, 0, 32);
    if (p->type == PAK_MEMORY) {
        if (blk < 0x400) { port_load((int)(p - g_port)); if (port_img(p)) memcpy(out, port_img(p) + blk * 32, 32); }
    } else if (p->type == PAK_RUMBLE) {
        if (blk >= 0x400 && blk < 0x600) memset(out, p->unlocked ? 0x80 : 0x00, 32);
        else if (blk >= 0x600) memset(out, p->motor_byte, 32);
    }
}
static void wr_block(PakPort *p, unsigned blk, const unsigned char *d) {
    if (p->type == PAK_MEMORY) {
        if (blk < 0x400) {
            unsigned char *dst; port_load((int)(p - g_port)); dst = port_img(p);
            if (dst) { dst += blk * 32; if (memcmp(dst, d, 32)) { memcpy(dst, d, 32); mark_dirty(p->file); } }
        }
    } else if (p->type == PAK_RUMBLE) {
        if (blk >= 0x400 && blk < 0x600) { int u = (d[31] == 0x80); if (u != p->unlocked) PTRACE("port %d: rumble pak %s", (int)(p - g_port) + 1, u ? "unlocked" : "locked"); p->unlocked = u; }
        else if (blk >= 0x600) {
            int m = d[31] & 1; p->motor_byte = d[31];
            if (m != p->motor) { p->motor_events++; if (p->motor_events <= 2) pak_log("port %d: rumble motor %s%s", (int)(p - g_port) + 1, m ? "ON" : "off", p->motor_events == 2 ? " (further changes are only logged with TUROK_PAKLOG=1)" : ""); else PTRACE("port %d: rumble motor %s", (int)(p - g_port) + 1, m ? "ON" : "off"); }
            p->motor = m;
        }
    }
}

/* Joybus ------------------------------------------------------------------------------------------------------------------------------ */
int (*pak_buttons_cb)(int port, unsigned char out[4]);     /* optional: 4 bytes of a button-read reply (hi, lo, stick x, stick y) */

static unsigned reply(unsigned char *rx, int rxlen, const unsigned char *resp, int n) {
    int k = rxlen < n ? rxlen : n;
    if (k > 0) memcpy(rx, resp, (size_t)k);
    return rxlen > n ? 0x40 : 0;                           /* asking for more than the device sends = receive timeout */
}
static unsigned dev_command(int chan, const unsigned char *tx, int txlen, unsigned char *rx, int rxlen) {
    PakPort *p; unsigned cmd;
    if (chan >= 4) return 0x80;                            /* channel 4 = cartridge EEPROM: not populated */
    if (!port_pad_connected(chan)) return 0x80;
    if (txlen < 1) return 0x40;
    p = &g_port[chan]; cmd = tx[0];
    switch (cmd) {
    case 0x00: case 0xFF: {                                /* identify / reset */
        unsigned char r[3];
        if (txlen != 1) return 0x40;
        r[0] = 0x05; r[1] = 0x00; r[2] = ident_status(p);
        PTRACE("port %d: identify -> status %d", chan + 1, r[2]);
        return reply(rx, rxlen, r, 3);
    }
    case 0x01: {                                           /* read buttons */
        unsigned char r[4] = { 0, 0, 0, 0 };
        if (txlen != 1) return 0x40;
        if (pak_buttons_cb) pak_buttons_cb(chan, r);
        return reply(rx, rxlen, r, 4);
    }
    case 0x02: {                                           /* read accessory */
        unsigned char r[33]; unsigned a16, blk; int ok, present;
        if (txlen != 3) return 0x40;
        a16 = ((unsigned)tx[1] << 8) | tx[2]; blk = a16 >> 5; ok = (a16 & 31) == pak_crc5(blk);
        if (!ok) { p->crc_err = 1; p->crc_errs++; }
        present = p->type != PAK_NONE && !p->fresh && ok;
        if (present) { rd_block(p, blk, r); r[32] = pak_crc8(r); p->reads++; } else { memset(r, 0, 32); r[32] = 0xFF; }
        PTRACE("port %d: read blk %03X %s%s", chan + 1, blk, ok ? "" : "ADDR-CRC-ERR ", present ? "" : "(no accessory)");
        return reply(rx, rxlen, r, 33);
    }
    case 0x03: {                                           /* write accessory */
        unsigned char crc; unsigned a16, blk; int ok, present;
        if (txlen != 35) return 0x40;
        a16 = ((unsigned)tx[1] << 8) | tx[2]; blk = a16 >> 5; ok = (a16 & 31) == pak_crc5(blk);
        if (!ok) { p->crc_err = 1; p->crc_errs++; }
        present = p->type != PAK_NONE && !p->fresh && ok;
        if (present) { wr_block(p, blk, tx + 3); crc = pak_crc8(tx + 3); p->writes++; } else crc = (unsigned char)~pak_crc8(tx + 3);
        PTRACE("port %d: write blk %03X %s%s", chan + 1, blk, ok ? "" : "ADDR-CRC-ERR ", present ? "" : "(no accessory)");
        if (g_trace && blk >= 0x18 && blk < 0x28) {
            char hx[80]; int q;
            for (q = 0; q < 32; q++) sprintf(hx + q * 2, "%02X", tx[3 + q]);
            PTRACE("        note-table block data %s", hx);
#ifndef PAK_STANDALONE_TEST
            { extern void port_bt(void); port_bt(); }          /* who is writing the directory? (return addresses on the stack, symbolise with turok.map) */
#endif
        }
        return reply(rx, rxlen, &crc, 1);
    }
    default:
        return 0x40;                                       /* unknown command: the controller does not answer */
    }
}

/* PIF RAM and its command list -------------------------------------------------------------------------------------------------------- */
static unsigned char g_pif[64];
static struct { int chan, pos, tx, rx; unsigned flags; } g_hs[8]; static int g_nhs;

static void pif_parse(void) {
    int chan = 0, pos = 0;
    g_nhs = 0;
    while (pos < 63 && chan < 5) {
        unsigned char b = g_pif[pos];
        if (b == 0xFE) break;                              /* end of list */
        if (b == 0xFF) { pos++; continue; }                /* no-op / padding */
        if (b == 0x00 || b == 0xFD) { chan++; pos++; continue; }   /* skip (or reset) this channel */
        {   int tx = b & 0x3F, rx, nx;
            if (pos + 1 >= 63) break;
            rx = g_pif[pos + 1] & 0x3F; nx = pos + 2 + tx + rx;
            if (nx > 63) break;                            /* incomplete handshake at the end: ignored */
            g_hs[g_nhs].chan = chan; g_hs[g_nhs].pos = pos; g_hs[g_nhs].tx = tx; g_hs[g_nhs].rx = rx; g_hs[g_nhs].flags = b & 0xC0; g_nhs++;
            pos = nx; chan++;
        }
    }
}
static void pif_execute(void) {
    int i;
    for (i = g_nhs - 1; i >= 0; i--) {                     /* the real PIF talks to channel 4 first and channel 0 last */
        unsigned char *rxb = &g_pif[g_hs[i].pos + 1], *tx = &g_pif[g_hs[i].pos + 2], *rx = tx + g_hs[i].tx;
        *rxb &= 0x3F;
        if (g_hs[i].flags & 0x80) continue;                /* TX bit 7: skip this handshake */
        if (g_hs[i].flags & 0x40) continue;                /* TX bit 6: reset the device (no reply) */
        *rxb |= (unsigned char)dev_command(g_hs[i].chan, tx, g_hs[i].tx, rx, g_hs[i].rx);
    }
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* control file, hot keys, XInput vibration (all on the pak thread)                                                                      */
static void cmd_status(void) {
    int i; static const char *nm[3] = { "empty", "memory", "rumble" };
    for (i = 0; i < 4; i++) {
        PakPort *p = &g_port[i]; char path8[MAX_PATH] = "-";
        if (p->file && p->file->path[0]) wnarrow(p->file->path, path8, sizeof path8);
        if (i == 0 && g_si_calls) { LARGE_INTEGER fq; QueryPerformanceFrequency(&fq); pak_log("status: %lu SI transfers so far, average %.1f us each", g_si_calls, 1e6 * (double)g_si_ticks / (double)fq.QuadPart / (double)g_si_calls); }
        pak_log("status port %d: %s%s%s reads=%lu writes=%lu idents=%lu crcerr=%lu motor=%d file=%s%s", i + 1, nm[p->type], p->changed ? " changed" : "", p->fresh ? " fresh" : "", p->reads, p->writes, p->idents, p->crc_errs, p->motor, path8, p->file && p->file->dirty ? " (dirty)" : "");
    }
}
static void port_reload_file(int i) {                      /* "reload": swap in whatever the file holds now (lock held); the accessory looks freshly inserted */
    PakPort *p = &g_port[i];
    if (!p->loaded || !p->file) { pak_log("port %d: nothing loaded yet", i + 1); return; }
    {   PakFile *f = p->file; char fmt[64];
        if (f->dirty) { LeaveCriticalSection(&g_lock); file_flush(f, 1); EnterCriticalSection(&g_lock); }
        free(f->data); f->data = NULL; file_read(f); p->off = pak_offset(f->data, f->size, p->slice, fmt);
        if (strcmp(f->fmt, "new")) { strncpy(f->fmt, fmt, sizeof f->fmt - 1); f->fmt[sizeof f->fmt - 1] = 0; }
        if (p->off + PAK_SIZE > f->size) p->off = 0;
    }
    p->changed = 1; p->fresh = (p->type != PAK_NONE);
    pak_log("port %d: image file reloaded", i + 1);
}
static void run_command(char *line) {
    char w[16] = "", t[16] = ""; int port = 0, n;
    n = sscanf(line, "%15s %d %15s", w, &port, t);
    if (n < 1) return;
    if (!_stricmp(w, "flush")) { pak_flush_all(1); pak_log("flushed"); return; }
    if (!_stricmp(w, "status")) { EnterCriticalSection(&g_lock); cmd_status(); LeaveCriticalSection(&g_lock); return; }
    if (n < 2 || port < 1 || port > 4) { pak_log("control file: bad command '%s'", line); return; }
    port--;
    if (!g_cfg.enabled && !_stricmp(w, "insert")) { pak_log("virtual pak is disabled (TUROK_PAK=0): insert ignored"); return; }
    EnterCriticalSection(&g_lock);
    if (!_stricmp(w, "insert")) port_set_type(port, type_from_ascii(t, PAK_MEMORY) == PAK_NONE ? PAK_MEMORY : type_from_ascii(t, PAK_MEMORY), "control file");
    else if (!_stricmp(w, "remove")) port_set_type(port, PAK_NONE, "control file");
    else if (!_stricmp(w, "reload")) port_reload_file(port);
    else if (!_stricmp(w, "format")) {
        PakPort *p = &g_port[port];
        if (p->type == PAK_MEMORY) { unsigned char serial[24]; port_load(port); if (port_img(p)) { new_serial(serial); pak_format_image(port_img(p), serial); mark_dirty(p->file); p->changed = 1; p->fresh = 1; pak_log("port %d: pak re-formatted (control file)", port + 1); } }
        else pak_log("port %d: no memory pak to format", port + 1);
    } else pak_log("control file: unknown command '%s'", line);
    LeaveCriticalSection(&g_lock);
}
static void poll_control_file(void) {
    static DWORD first_seen; HANDLE h; DWORD n, got = 0; char buf[1024], *p, *e;
    h = CreateFileA("port_pak.txt", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) { first_seen = 0; return; }
    n = GetFileSize(h, NULL);
    if (n == 0 || n >= sizeof buf) { CloseHandle(h); if (n >= sizeof buf) DeleteFileA("port_pak.txt"); return; }
    if (!ReadFile(h, buf, n, &got, NULL)) got = 0;
    CloseHandle(h);
    if (!got) return;
    buf[got] = 0;
    if (buf[got - 1] != '\n') { DWORD now = GetTickCount(); if (!first_seen) first_seen = now; if ((int)(now - first_seen) < 400) return; }   /* the writer may not have finished the line */
    first_seen = 0;
    if (!DeleteFileA("port_pak.txt")) return;              /* someone holds it open: run it on the next poll */
    for (p = buf; *p; p = e) {
        e = p; while (*e && *e != '\n') e++;
        if (*e) *e++ = 0;
        while (*p == ' ' || *p == '\t' || *p == '\r') p++;
        { char *q = p + strlen(p); while (q > p && (q[-1] == '\r' || q[-1] == ' ' || q[-1] == '\t')) *--q = 0; }
        if (*p && *p != '#' && *p != ';') run_command(p);
    }
}
static int our_window_foreground(void) {
    HWND h = GetForegroundWindow(); DWORD pid = 0;
    if (!h) return 0;
    GetWindowThreadProcessId(h, &pid);
    return pid == GetCurrentProcessId();
}
static void poll_hotkeys(void) {
    static int prev[4]; int i, ctrl, shift;
    if (!g_cfg.hotkeys || !g_cfg.enabled) return;
    ctrl = (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0; shift = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
    for (i = 0; i < 4; i++) {
        int down = ctrl && (GetAsyncKeyState(VK_F5 + i) & 0x8000) != 0;
        if (down && !prev[i] && our_window_foreground()) {
            EnterCriticalSection(&g_lock);
            if (shift) port_set_type(i, g_port[i].type == PAK_RUMBLE ? PAK_NONE : PAK_RUMBLE, "hot key");
            else port_set_type(i, g_port[i].type == PAK_MEMORY ? PAK_NONE : PAK_MEMORY, "hot key");
            LeaveCriticalSection(&g_lock);
        }
        prev[i] = down;
    }
}
/* vibration: the motor state of the rumble pak (g_port[i].motor, set by the real osMotorStart/Stop running over the virtual PIF) is delivered by the input layer (port/input.c, called from os_shim.c)
   to the gamepad that is assigned to the port, not to XInput slot i: with keyboard and gamepad players mixed, a slot number and a port number are different things */
static void poll_vibration(int force_off) { (void)force_off; }
static DWORD WINAPI pak_thread(LPVOID arg) {
    (void)arg;
    while (WaitForSingleObject(g_stop_evt, 40) == WAIT_TIMEOUT) {
        poll_hotkeys(); poll_control_file(); poll_vibration(0); flush_due();
        if (g_active && (int)(GetTickCount() - (DWORD)g_last_dma_tick) >= 250) { g_active = 0; if (g_sync || g_trace) pak_log("idle"); }
    }
    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* start-up and shut-down                                                                                                                */
/* a fatal exception that nobody resolved: write what is pending before the process goes down (never blocks: try-lock only) */
static LONG WINAPI pak_veh(EXCEPTION_POINTERS *ep) {
    static volatile LONG busy; DWORD c = ep->ExceptionRecord->ExceptionCode; int i;
    if (c != 0xC0000005 && c != 0xC000001D && c != 0xC00000FD && c != 0xC0000094 && c != 0xC0000096 && c != 0xC000008C && c != 0xC0000409) return EXCEPTION_CONTINUE_SEARCH;
    if (g_init_state != 2 || InterlockedCompareExchange(&busy, 1, 0) != 0) return EXCEPTION_CONTINUE_SEARCH;
    if (TryEnterCriticalSection(&g_lock)) {
        for (i = 0; i < g_nfiles; i++) { PakFile *f = &g_files[i]; DWORD e; if (f->dirty && f->persist && f->data && write_atomic(f->path, f->data, f->size, &e)) { f->dirty = 0; PTRACE("crash flush wrote file %d", i); } }
        LeaveCriticalSection(&g_lock);
    }
    InterlockedExchange(&busy, 0);
    return EXCEPTION_CONTINUE_SEARCH;
}
static void pak_atexit(void) {
    if (g_init_state != 2 || InterlockedExchange(&g_shutdown, 1)) return;
    if (g_stop_evt) SetEvent(g_stop_evt);
    if (g_thread) WaitForSingleObject(g_thread, 2000);
    poll_vibration(1);
    pak_flush_all(1);
    {   int i; unsigned long r = 0, w = 0; for (i = 0; i < 4; i++) { r += g_port[i].reads; w += g_port[i].writes; }
        if (g_si_calls) { LARGE_INTEGER fq; QueryPerformanceFrequency(&fq); pak_log("exit: %lu SI transfers (average %.1f us, longest %.1f us), %lu accessory block reads, %lu block writes", g_si_calls, 1e6 * (double)g_si_ticks / (double)fq.QuadPart / (double)g_si_calls, 1e6 * (double)g_si_max / (double)fq.QuadPart, r, w); } }
}
static void pak_init(void) {
    int i; char sd[MAX_PATH], nm[128], ini[MAX_PATH];
    config_load();
    for (i = 0; i < 4; i++) { g_port[i].type = g_cfg.type[i]; g_port[i].changed = g_port[i].fresh = (g_cfg.type[i] != PAK_NONE); g_port[i].slice = i; }
    wnarrow(g_cfg.savedir, sd, sizeof sd); wnarrow(g_cfg.name, nm, sizeof nm); wnarrow(g_cfg.ini, ini, sizeof ini);
    pak_log("%s: ports %c%c%c%c (m = memory pak, r = rumble pak, - = empty), save folder %s, name '%s', ini %s%s", g_cfg.enabled ? "virtual controller pak" : "virtual controller pak DISABLED (TUROK_PAK=0)",
            "-mr"[g_cfg.type[0]], "-mr"[g_cfg.type[1]], "-mr"[g_cfg.type[2]], "-mr"[g_cfg.type[3]], sd, nm, ini, g_nini ? "" : " (not found)");
    if (g_cfg.pj64[0]) { wnarrow(g_cfg.pj64, sd, sizeof sd); pak_log("Project64 save folder: %s", sd); }
#ifndef PAK_STANDALONE_TEST
    { extern void pak_os_init(void); pak_os_init(); }
    g_stop_evt = CreateEventA(NULL, TRUE, FALSE, NULL);
    g_thread = CreateThread(NULL, 0, pak_thread, NULL, 0, NULL);
    if (g_thread) SetThreadPriority(g_thread, THREAD_PRIORITY_BELOW_NORMAL);
    atexit(pak_atexit);
    AddVectoredExceptionHandler(0, pak_veh);                           /* last in the chain: only sees what the game's own handlers did not resolve */
#endif
}
static void pak_ensure_init(void) {
    if (g_init_state == 2) return;
    if (InterlockedCompareExchange(&g_init_state, 1, 0) == 0) {
        InitializeCriticalSection(&g_lock);
        pak_init();
        MemoryBarrier();
        g_init_state = 2;
    } else while (g_init_state != 2) Sleep(1);
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
/* interface used by the OS shim (port/os_shim.c, port/pak_os.c)                                                                          */

/* One SI DMA of the 64-byte PIF RAM image.  dir: 1 = RDRAM -> PIF (OS_WRITE), 0 = PIF -> RDRAM (OS_READ).  `ram` is a host pointer. */
void pak_si_dma(int dir, void *ram) {
    LARGE_INTEGER t0, t1;
    pak_ensure_init();
    if (!ram) return;
    g_last_dma_tick = (LONG)GetTickCount(); g_active = 1;
    QueryPerformanceCounter(&t0);
    EnterCriticalSection(&g_lock);
    if (dir == 1) {
        memcpy(g_pif, ram, 64);
        if (g_pif[63] & 1) { pif_parse(); g_pif[63] &= (unsigned char)~1u; }      /* the PIF consumes the "run the command list" bit */
    } else {
        pif_execute();
        memcpy(ram, g_pif, 64);
    }
    QueryPerformanceCounter(&t1);
    g_si_calls++; g_si_ticks += (unsigned long long)(t1.QuadPart - t0.QuadPart); if ((unsigned long long)(t1.QuadPart - t0.QuadPart) > g_si_max) g_si_max = (unsigned long long)(t1.QuadPart - t0.QuadPart);
    LeaveCriticalSection(&g_lock);
}
/* OSContStatus.status for a controller query (osContInit / osContGetQuery): same bits and the same "new accessory" latch as the identify command */
unsigned char pak_cont_status(int port, int connected) {
    unsigned char st;
    if (!connected || port < 0 || port > 3) return 0;
    pak_ensure_init();
    EnterCriticalSection(&g_lock); st = ident_status(&g_port[port]); LeaveCriticalSection(&g_lock);
    PTRACE("port %d: osContInit/osContGetQuery -> status %d", port + 1, st);
    return st;
}
int pak_rumble_get(int port) { int r; if (port < 0 || port > 3 || g_init_state != 2) return 0; EnterCriticalSection(&g_lock); r = g_port[port].type == PAK_RUMBLE && g_port[port].motor; LeaveCriticalSection(&g_lock); return r; }
int pak_accessory(int port) { int r; if (port < 0 || port > 3) return 0; pak_ensure_init(); EnterCriticalSection(&g_lock); r = g_port[port].type; LeaveCriticalSection(&g_lock); return r; }
