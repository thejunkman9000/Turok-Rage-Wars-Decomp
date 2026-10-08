/* High-level emulation of the libultra "aspMain" (ABI1) RSP audio microcode.
 * See AUDIO_HLE.md for layout assumptions and what is verified. Plain C89-ish. */
#ifndef AUDIO_HLE_H
#define AUDIO_HLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Acmd opcodes (w0 >> 24) */
enum {
    A_SPNOOP = 0, A_ADPCM = 1, A_CLEARBUFF = 2, A_ENVMIXER = 3, A_LOADBUFF = 4,
    A_RESAMPLE = 5, A_SAVEBUFF = 6, A_SEGMENT = 7, A_SETBUFF = 8, A_SETVOL = 9,
    A_DMEMMOVE = 10, A_LOADADPCM = 11, A_MIXER = 12, A_INTERLEAVE = 13,
    A_POLEF = 14, A_SETLOOP = 15
};

/* flag bits (bits 16..23 of w0) */
#define A_INIT  0x01   /* ADPCM/RESAMPLE/ENVMIXER: start from zero/initial state */
#define A_LOOP  0x02   /* ADPCM: load state from the loop address */
#define A_LEFT  0x02   /* SETVOL: left channel (clear = right) */
#define A_VOL   0x04   /* SETVOL: set current volume (clear = set ramp target/rate) */
#define A_AUX   0x08   /* SETBUFF/SETVOL: aux (wet/dry-right) variant */

#define AUDIO_HLE_DMEM_SIZE 4096

/* translate(addr): addr is the command's address after segment resolution
 * ((segment_base[(a>>24)&15] + (a & 0xFFFFFF)), i.e. a 24-bit offset; for
 * KSEG0 addresses such as 0x80xxxxxx segment 0 gives the physical offset).
 * Must return a host pointer to BIG-ENDIAN game memory, or NULL if invalid. */
typedef uint8_t *(*audio_hle_translate_fn)(uint32_t addr);

/* Install the address translator and reset all state (DMEM, segments, volumes). */
void audio_hle_init(audio_hle_translate_fn translate);

/* Clear DMEM, segment table and mixer state (keeps the translator). */
void audio_hle_reset(void);

/* Execute a command list at guest address cmd_list_addr (translated through the
 * callback) of byte_len bytes (8 bytes per command). Returns number of commands
 * executed, or -1 if the list address could not be translated. */
int audio_hle_run(uint32_t cmd_list_addr, uint32_t byte_len);

/* Same, with a direct pointer to big-endian command words. */
int audio_hle_run_ptr(const uint8_t *cmds, uint32_t byte_len);

/* Where the most recent A_SAVEBUFF wrote (resolved address and byte count);
 * returns 0 if none since reset. The PCM (interleaved L,R int16 BE if the list
 * used A_INTERLEAVE) has already been written to game memory at that address. */
int audio_hle_last_save(uint32_t *addr, uint32_t *bytes);

/* Number of unknown / unimplemented opcodes seen since reset (diagnostics). */
uint32_t audio_hle_unknown_count(void);

/* Test/debug access to DMEM (big-endian byte layout, 4096 bytes). */
uint8_t *audio_hle_dmem(void);

#ifdef __cplusplus
}
#endif
#endif
