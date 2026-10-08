/* audio output for the port: the game's AI buffers (big-endian 16-bit stereo, produced by the RSP audio microcode HLE) are
   converted to host order and played through waveOut.  A ring buffer decouples the 60 Hz game thread from the device. */
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

#define RING_BYTES (1 << 18)
#define BLK_FRAMES 1024
#define NBLK 4

static unsigned char ring[RING_BYTES];
static volatile unsigned rd, wr;          /* byte counters, power-of-two ring */
static CRITICAL_SECTION cs;
static HWAVEOUT hwo;
static WAVEHDR hdr[NBLK];
static short blk[NBLK][BLK_FRAMES * 2];
static HANDLE ev, th;
static unsigned freq = 32000;
static int started, failed, muted = -1;
static unsigned long long pushed;

static void fill(short *dst) {
    unsigned avail, want = BLK_FRAMES * 4, i; unsigned char *d = (unsigned char *)dst;
    EnterCriticalSection(&cs);
    avail = wr - rd;
    if (avail >= want) { for (i = 0; i < want; i++) d[i] = ring[(rd + i) & (RING_BYTES - 1)]; rd += want; }
    else { memset(d, 0, want); }          /* underrun: silence (keep the data for the next block) */
    LeaveCriticalSection(&cs);
}
static DWORD WINAPI feeder(LPVOID p) {
    (void)p;
    for (;;) {
        int i; WaitForSingleObject(ev, 50);
        for (i = 0; i < NBLK; i++) if (hdr[i].dwFlags & WHDR_DONE) { fill(blk[i]); waveOutWrite(hwo, &hdr[i], sizeof hdr[i]); }
    }
    return 0;
}
static void start(void) {
    WAVEFORMATEX f; int i;
    if (started || failed) return;
    if (muted < 0) { char e[8]; muted = GetEnvironmentVariableA("TUROK_MUTE", e, sizeof e) ? 1 : 0; }
    InitializeCriticalSection(&cs);
    memset(&f, 0, sizeof f); f.wFormatTag = WAVE_FORMAT_PCM; f.nChannels = 2; f.nSamplesPerSec = freq; f.wBitsPerSample = 16; f.nBlockAlign = 4; f.nAvgBytesPerSec = freq * 4;
    ev = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (waveOutOpen(&hwo, WAVE_MAPPER, &f, (DWORD_PTR)ev, 0, CALLBACK_EVENT) != MMSYSERR_NOERROR) { failed = 1; fprintf(stderr, "audio: waveOutOpen failed\n"); return; }
    for (i = 0; i < NBLK; i++) {
        memset(&hdr[i], 0, sizeof hdr[i]); hdr[i].lpData = (LPSTR)blk[i]; hdr[i].dwBufferLength = BLK_FRAMES * 4;
        waveOutPrepareHeader(hwo, &hdr[i], sizeof hdr[i]); memset(blk[i], 0, sizeof blk[i]); waveOutWrite(hwo, &hdr[i], sizeof hdr[i]);
    }
    th = CreateThread(NULL, 0, feeder, NULL, 0, NULL);
    started = 1; fprintf(stderr, "audio: waveOut open at %u Hz\n", freq);
}
void port_audio_set_freq(unsigned f) { if (f >= 8000 && f <= 48000 && !started) freq = f; }
/* queue n bytes of big-endian stereo 16-bit samples */
void port_audio_push(const unsigned char *be, unsigned n) {
    unsigned i;
    if (!started) start();
    if (failed || muted) return;
    n &= ~3u;
    EnterCriticalSection(&cs);
    if ((wr - rd) + n > RING_BYTES - 4096) rd = wr - (RING_BYTES / 4);      /* far behind: drop the old audio */
    for (i = 0; i < n; i += 2) { ring[(wr + i) & (RING_BYTES - 1)] = be[i + 1]; ring[(wr + i + 1) & (RING_BYTES - 1)] = be[i]; }
    wr += n; pushed += n;
    LeaveCriticalSection(&cs);
}
unsigned long long port_audio_pushed(void) { return pushed; }
