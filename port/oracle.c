/* Oracle mode: makes the port a reproducible reference for the C# rewrite.  Everything here is inert unless an env var is set.
 *
 *   TUROK_ORACLE=1        virtual time: the libultra counter advances 1/60 s per game frame instead of following the wall clock
 *   TUROK_REPLAY=<file>   controller input from a file: one line per frame "<frame> <buttons hex> <stick_x> <stick_y>"; holds the last value
 *   TUROK_RECORD=<file>   write the controller input the game actually read, in the same format (only frames where it changed)
 *   TUROK_FRAMES=<n>      headless: run n frames without drawing or pacing, then exit
 *   TUROK_TRACE=<file>    per-frame state trace: "<frame> <crc32 of the 8 MB guest RAM>"
 *   TUROK_TRACE_PAGES=1   also add the CRC of every 4 KB page whose content changed since the previous frame (find the first divergence)
 *
 * Implies TUROK_ORACLE when REPLAY, FRAMES or TRACE is used.  Replaying the same input file twice must give identical traces.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define RAM_BASE 0x80000000u
#define RAM_SIZE 0x800000u
#define TICKS_PER_FRAME 781250ull           /* 46.875 MHz / 60 */

static int g_on = -1, g_headless, g_pages;
static long g_frames_limit;
static unsigned g_frame;
static FILE *g_trace, *g_record;

typedef struct { unsigned frame; unsigned short buttons; signed char sx, sy; } PadEvent;
static PadEvent *g_replay; static int g_replay_n, g_replay_i;
static int g_have_replay;
static unsigned short g_rb; static signed char g_rsx, g_rsy;            /* replay state */
static int g_lb = -1, g_lsx, g_lsy;                                     /* last recorded state */

static unsigned g_crc_tab[256];
static unsigned crc32(const unsigned char *p, size_t n, unsigned crc) {
    if (!g_crc_tab[1]) for (unsigned i = 0; i < 256; i++) { unsigned c = i; for (int k = 0; k < 8; k++) c = c & 1 ? 0xEDB88320u ^ (c >> 1) : c >> 1; g_crc_tab[i] = c; }
    crc = ~crc;
    while (n--) crc = g_crc_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);
    return ~crc;
}

static unsigned *g_prev_pages;
static unsigned char *g_scratch;

/* Guest RAM holds a few host pointers (they move with ASLR).  Words in the host-only range 0x04000000-0x2FFFFFFF are never valid
   guest addresses, so they are zeroed before hashing.  (A genuine integer in that range that changes between runs is masked too.) */
static void masked_copy(unsigned char *dst, const unsigned char *src, size_t n) {
    memcpy(dst, src, n);
    for (size_t i = 0; i + 4 <= n; i += 4) {
        unsigned w = ((unsigned)dst[i] << 24) | (dst[i + 1] << 16) | (dst[i + 2] << 8) | dst[i + 3];
        if (w >= 0x04000000u && w < 0x30000000u) memset(dst + i, 0, 4);
    }
}

static void oracle_init(void) {
    char v[MAX_PATH];
    g_on = 0;
    if (GetEnvironmentVariableA("TUROK_ORACLE", v, sizeof v)) g_on = 1;
    if (GetEnvironmentVariableA("TUROK_FRAMES", v, sizeof v)) { g_frames_limit = atol(v); g_headless = 1; g_on = 1; }
    if (GetEnvironmentVariableA("TUROK_TRACE_PAGES", v, sizeof v)) g_pages = 1;
    if (GetEnvironmentVariableA("TUROK_TRACE", v, sizeof v)) { g_trace = fopen(v, "w"); g_on = 1; }
    if (GetEnvironmentVariableA("TUROK_RECORD", v, sizeof v)) g_record = fopen(v, "w");
    if (GetEnvironmentVariableA("TUROK_REPLAY", v, sizeof v)) {
        FILE *f = fopen(v, "r"); int cap = 0;
        if (f) {
            char line[128]; unsigned fr, b; int sx, sy;
            while (fgets(line, sizeof line, f)) {
                if (line[0] == '#' || sscanf(line, "%u %x %d %d", &fr, &b, &sx, &sy) != 4) continue;
                if (g_replay_n == cap) { cap = cap ? cap * 2 : 256; g_replay = (PadEvent *)realloc(g_replay, cap * sizeof *g_replay); }
                g_replay[g_replay_n].frame = fr; g_replay[g_replay_n].buttons = (unsigned short)b;
                g_replay[g_replay_n].sx = (signed char)sx; g_replay[g_replay_n].sy = (signed char)sy; g_replay_n++;
            }
            fclose(f);
        } else fprintf(stderr, "oracle: cannot open replay file %s\n", v);
        g_have_replay = 1; g_on = 1;
    }
    if (g_on) fprintf(stderr, "oracle: on (headless=%d frames=%ld replay=%d record=%d trace=%d)\n", g_headless, g_frames_limit, g_have_replay, g_record != NULL, g_trace != NULL);
}

int oracle_enabled(void) { if (g_on < 0) oracle_init(); return g_on; }
int oracle_headless(void) { oracle_enabled(); return g_headless; }

/* virtual libultra counter (46.875 MHz) */
unsigned long long oracle_counter(void) { return (unsigned long long)g_frame * TICKS_PER_FRAME; }

/* Called by osContGetReadData with the host-side pad array (OSContPad: u16 button BE, s8 stick_x, s8 stick_y, u8 errno). */
void oracle_filter_pad(unsigned char *pad) {
    if (!oracle_enabled()) return;
    if (g_have_replay) {
        while (g_replay_i < g_replay_n && g_replay[g_replay_i].frame <= g_frame) {
            g_rb = g_replay[g_replay_i].buttons; g_rsx = g_replay[g_replay_i].sx; g_rsy = g_replay[g_replay_i].sy; g_replay_i++;
        }
        pad[0] = (unsigned char)(g_rb >> 8); pad[1] = (unsigned char)g_rb; pad[2] = (unsigned char)g_rsx; pad[3] = (unsigned char)g_rsy;
    }
    if (g_record) {
        int b = (pad[0] << 8) | pad[1], sx = (signed char)pad[2], sy = (signed char)pad[3];
        if (b != g_lb || sx != g_lsx || sy != g_lsy) {
            fprintf(g_record, "%u %04X %d %d\n", g_frame, b, sx, sy); fflush(g_record);
            g_lb = b; g_lsx = sx; g_lsy = sy;
        }
    }
}

/* Called after every game frame by the platform loop. */
void oracle_frame_end(void) {
    if (!oracle_enabled()) return;
    if (g_trace) {
        const unsigned char *ram = (const unsigned char *)(size_t)RAM_BASE;
        unsigned all = 0, pages = RAM_SIZE / 4096;
        __try {
            if (g_pages && !g_prev_pages) g_prev_pages = (unsigned *)calloc(pages, sizeof(unsigned));
            if (!g_scratch) g_scratch = (unsigned char *)malloc(RAM_SIZE);
            masked_copy(g_scratch, ram, RAM_SIZE);
            all = crc32(g_scratch, RAM_SIZE, 0);
            fprintf(g_trace, "%u %08X", g_frame, all);
            if (g_pages) for (unsigned i = 0; i < pages; i++) {
                unsigned c = crc32(g_scratch + i * 4096, 4096, 0);
                if (c != g_prev_pages[i]) { fprintf(g_trace, " %X:%08X", i, c); g_prev_pages[i] = c; }
            }
            fputc('\n', g_trace);
        } __except (EXCEPTION_EXECUTE_HANDLER) { fprintf(g_trace, "%u unreadable-ram\n", g_frame); }
        fflush(g_trace);
    }
    g_frame++;
    if (g_frames_limit && (long)g_frame >= g_frames_limit) {
        fprintf(stderr, "oracle: %u frames done\n", g_frame);
        { char v[MAX_PATH]; if (GetEnvironmentVariableA("TUROK_DUMPRAM", v, sizeof v)) { FILE *f = fopen(v, "wb"); if (f) { fwrite((void *)(size_t)RAM_BASE, 1, RAM_SIZE, f); fclose(f); } } }   /* TUROK_DUMPRAM=<file>: guest RAM at exit */
        if (g_trace) fclose(g_trace);
        if (g_record) fclose(g_record);
        fflush(NULL);
        ExitProcess(0);
    }
}
