# audio_hle (libultra aspMain / ABI1 HLE)

Files: `audio_hle.h`, `audio_hle.c`, `audio_hle_test.c`. Plain C, depends only on libc + `floor`.

## API
```c
audio_hle_init(translate);             // translate(addr) -> host ptr into BIG-ENDIAN game memory (or NULL)
audio_hle_run(cmd_list_addr, bytes);   // runs bytes/8 commands; returns count (-1 if list not translatable)
audio_hle_run_ptr(ptr, bytes);         // same with a direct pointer to BE command words
audio_hle_last_save(&addr,&bytes);     // where the last A_SAVEBUFF wrote
audio_hle_reset(); audio_hle_unknown_count(); audio_hle_dmem();
```
The HLE has no PCM output buffer of its own: like the real RSP it DMAs results back
into game memory via `A_SAVEBUFF`. After `audio_hle_run`, take `last_save` addr/len,
translate it, and hand those bytes to the audio device. With `A_INTERLEAVE` before the
save the data is interleaved L,R int16 **big-endian** (byte-swap per sample for a LE device).

Addresses: each command address is resolved as `seg[(a>>24)&15] + (a&0xFFFFFF)` and the
24-bit result passed to `translate` (so `0x80xxxxxx` -> physical offset with segment 0;
the translator should treat it as a physical RDRAM offset). The command list address
itself is passed as `addr & 0x1FFFFFFF`. DMEM is a 4096-byte big-endian byte array, so
loads/saves are plain copies and no endian juggling is needed; all DMEM accesses wrap at 4096.

## Commands (w0>>24; flags = bits 16..23 of w0)
| op | name | layout used |
|---|---|---|
|0|SPNOOP| |
|1|ADPCM| flags A_INIT(1)=zero state, A_LOOP(2)=state from SETLOOP address, else from w1; w1=state addr (32 bytes, 16 BE int16, written back). in/out/count from SETBUFF (count = OUTPUT bytes, 32 per 9-byte frame) |
|2|CLEARBUFF| addr=w0&0xFFFF, count=w1&0xFFFF |
|3|ENVMIXER| flags A_INIT: take vol/target/rate/dry/wet from SETVOL, else load 32-byte state at w1 (own layout). Saved back always |
|4|LOADBUFF| DMEM[in] <- w1, SETBUFF count bytes |
|5|RESAMPLE| pitch=w0&0xFFFF (0x8000 = ratio 1.0, 0x4000 = 0.5), state at w1 (16 bytes: 4 history samples + 16-bit phase), count = output bytes |
|6|SAVEBUFF| DMEM[out] -> w1, SETBUFF count bytes |
|7|SEGMENT| seg[(w1>>24)&15] = w1&0xFFFFFF |
|8|SETBUFF| normal: in=w0&0xFFFF, out=w1>>16, count=w1&0xFFFF. A_AUX(8): dry_right=w0&0xFFFF, wet_left=w1>>16, wet_right=w1&0xFFFF |
|9|SETVOL| A_AUX: dry=int16(w1>>16), wet=int16(w1); A_VOL(4): vol[lr]=int16(w0); else target[lr]=int16(w0), rate[lr]=int32(w1). lr: A_LEFT(2)=left else right |
|10|DMEMMOVE| src=w0&0xFFFF, dst=w1>>16, count=w1&0xFFFF |
|11|LOADADPCM| w0&0xFFFFFF bytes of BE int16 codebook from w1 (max 512 bytes); predictor p uses entries [16p..16p+15] (8 coefs for the "t-2" sample, 8 for "t-1") |
|12|MIXER| gain=int16(w0), in=w1>>16, out=w1&0xFFFF; out += in*gain>>15 (saturating) |
|13|INTERLEAVE| left=w1>>16, right=w1&0xFFFF -> out, count/4 stereo pairs (count = output bytes) |
|14|POLEF| NOT implemented (counted in `unknown_count`) |
|15|SETLOOP| loop addr = w1 (resolved when ADPCM runs) |

Envmixer: ramp value is 32-bit (vol<<16); each sample value += rate/8, clamped at
target<<16; sample vol = value>>16; `l = s*vol>>15` (`AUDIO_HLE_VOL_SHIFT`), then
dry output `+= l*dry>>15` into `out` (left) / `dry_right`, wet into `wet_left`/`wet_right`.

## Verified by `audio_hle_test.c` (16 checks pass; built with zig cc -target x86-windows-msvc)
- ADPCM: 8 random frames with random codebook equal an independently written matrix-form
  decoder bit-exactly; also two 4-frame calls with saved state == one call.
- Resample: ratio 1.0 identity; ratio 0.5 (even outputs = inputs, odd = midpoint on a ramp);
  split into two calls with state carry equals one call.
- Envmixer ramp: matches the formula above exactly; plateau, silent right channel at vol 0,
  re-load of saved state without A_INIT, wet mixing.
- End to end via `audio_hle_run` with segment addressing, KSEG0 addresses,
  LOADADPCM/SETLOOP/ADPCM/RESAMPLE/CLEARBUFF/ENVMIXER/INTERLEAVE/SAVEBUFF.

These tests check self-consistency with my own reading of the algorithm. They do NOT
prove bit-exactness against real hardware: the reference decoder is the same formula
(recalled from mupen64plus-rsp-hle / VADPCM) written separately.

## Unverified / known gaps (written from memory)
- Exact field packing of SETVOL (esp. AUX dry/wet and rate), SETBUFF aux, LOADBUFF/SAVEBUFF
  using SETBUFF count, INTERLEAVE order/count, LOADADPCM size: from memory of abi.h and
  mupen64plus; if audio is wrong in the real game, check these against a command-list dump first.
- Overall envmixer gain (shift 15 vs 16 is a possible 6 dB difference) and ramp step semantics (rate/8 per sample).
- Resampler uses a Catmull-Rom 64-phase 4-tap table, not the original ucode table, and no
  fixed 2-sample delay; it reads 2 samples of lookahead from DMEM beyond `count`.
- ADPCM header: high nibble = shift, low nibble = predictor (clamped to loaded codebook); no
  ABI2 gain, no 5-bit-per-sample (A_ADPCM2) mode.
- Not implemented: POLEF, ENVSETUP/ADDMIXER/other ABI2/later opcodes, A_LOOP edge cases beyond
  loading the state, DMEM byte-swap quirks of real RSP (irrelevant with BE DMEM).
- State layouts for ENVMIXER differ from real ucode (fine as long as the same HLE saves and
  reloads them; games that inspect or initialise them by hand would break).
