# Readable C for the hand-written assembly units

The units listed in `docs/hand_asm.txt` that the original authors wrote in assembler stay `.s`
files in the byte-identical build (gcc 2.8.1 cannot reproduce their hand-scheduled delay slots,
register-passing conventions, cop0 access, jumps into the middle of other routines).  This
directory holds *functionally equivalent*, documented C for a group of them.  It is **not**
used by the build and does not try to match bytes.

| file | contents |
| --- | --- |
| `rnc.c` | the Rob Northen "RNC" (Propack) decompressor: `rncUnpackMethod1`, `rncUnpackMethod1Body`, `rncReadHuffCode`, `rncInputBits`, `rncRefillBitBuf`, `rncMakeHuffTable`, `rncUnpackMethod2`, `rncUnpackMethod2Body` |
| `thread.c` | `__osEnqueueThread`, `__osPopThread`, `__osCleanupThread`, `__osEnqueueAndYield`, `dbgSetWatchpoint` |
| `test/` | differential test harness (see "Verification") |

Both files are plain C99 with fixed-width types; they compile with any host compiler
(`python -m ziglang cc -std=c99 -c rnc.c`).  Compressed bytes are read byte-wise, so the code is
endian agnostic (`thread.c` models the N64 structure layout, which is only meaningful on a
32-bit-pointer target, but its logic is host independent).

## RNC (`rnc.c`)

Header of an RNC file (18 bytes): `"RNC" method`, `u32 unpacked` (BE), `u32 packed` (BE),
`u16 crc(unpacked)`, `u16 crc(packed)` (CRC16, poly 0xA001), `u8 leeway`, `u8 chunks`.  The game
(`func_00285150`) calls `rncUnpackMethod1(hdr + 0x12, dst, packed, unpacked)` and
`rncUnpackMethod2(hdr, dst, packed, unpacked)`.  The ROM contains 2050 method 1 blobs and no method 2
blob; method 2 is therefore only reached by files not shipped in this ROM (the decoder is linked in
for completeness of the Propack library).

### Method 1 - Huffman + LZ77 over a 16 bit little-endian bit window

The original passes state between its seven routines in registers.  They become the
`Rnc1Bits` structure:

| register | meaning | C |
| --- | --- | --- |
| `$t6` | bit window; low part = unread bits of the current 16 bit word, above it the next word (pre-loaded) | `window` |
| `$t7` | bits left in the current word (0..16); the window holds `left + 16` valid bits | `left` |
| `$s3` | input pointer: next word to load, *also the source of literal bytes* | `p` |
| `$t0`/`$t1` | mask / bit count argument of `rncInputBits`; result also in `$t0` | parameters / return value |
| `$s0` | pointer into a Huffman table (clobbered by the routines) | local |
| `$s4`/`$s2` | output pointer / the three tables on the stack | `dst`, `tables[]` |
| `$ra` parked in `$t8`/`$t9` | hand-saved return addresses | n/a |

* `rncRefillBitBuf` = `rnc1_refill`: when a read needs more bits than are left in the current word, drop the
  rest of it, move the pre-loaded word down and load the next 16 bit word on top.
* `rncInputBits` = `rnc1_input_bits(mask, n)`: `window & mask`, then consume `n` bits.  Callers pass odd masks
  (2 for the initial 2 bit skip, `0xFFFFFFFF` for the 16 bit chunk count) which are kept verbatim.
* `rncMakeHuffTable` = `rnc1_make_huff_table`: 5 bit symbol count (max 16), `count` 4 bit code lengths, then
  canonical codes are assigned (shortest first, symbol order within a length) and stored bit-reversed in a
  `0x80` byte table: 16 x `{u16 mask, u16 code}` at +0, 16 x `{u8 len, u8 symbol, u16 extra_mask}` at +0x40.
  A symbol `s >= 2` stands for the value `(1 << (s-1)) | (s-1 extra bits)`; 0 and 1 stand for themselves.
* `rncReadHuffCode` = `rnc1_read_huff`: linear scan of the `(mask, code)` pairs (no terminator: a
  zeroed pair matches everything), consume the code, then the extra bits.
* `rncUnpackMethod1Body` = `rnc_unpack_method1`: skip 2 bits; per chunk read three tables (literal
  run length, match distance, match length) and a 16 bit sub-block count `N`; then
  `literal-run, N x (distance, length, literal-run)`.  Literal bytes come straight from the byte stream at
  `p`, after which the window is re-primed from `p`.  A match copies `length + 2` bytes from
  `dst - distance - 1`.  The chunk loop ends when `p` reaches `in + packed`.
* `rncUnpackMethod1` = `rncUnpackMethod1()`: only saves `$s0-$s7`, `$ra` and moves `a0-a3` into
  `$s0-$s3`.  The original returns an accidental `$v0` (last byte loaded, shifted left 24); the C returns
  the same value from `rnc_unpack_method1` only so that the test can compare it.

### Method 2 - bytewise LZ with flag bits, no Huffman

`rncUnpackMethod2` (wrapper, saves `$a0-$a3 $t0-$t7 $s0-$s3 $ra`, then reaches the body with
`jalr $t4` to the *delay-slot word* of its own `jr $ra`, `D_002B2AB8` - the first instruction of the
body) and `rncUnpackMethod2Body` (`rnc2_unpack`).  The body is ~100 jumps because the bit-fetch is
unrolled in ~20 copies with `j` back to the continuation; `$t2` is an 8 bit shift register with a
sentinel (`byte << 1 | 1`), `$t7` the bit just shifted out, `$t0` match length, `$t1` distance high
byte, `$v1` input, `$a1` output.  Decoded structure:

```
skip 2 bits
loop:
  while next bit == 0: copy 1 literal byte
  bits  1 0            : length 2, distance = 1 byte
        1 1 0          : length 3, then distance code
        1 1 1 B        : length B+8 (B != 0), then distance code
                         B == 0: end marker; next bit 1 = go on with literals, 0 = finished
        0 a 0          : length 4+a
        0 a 1 b        : length 2*(3+a)+b = 6..8; the value 9 (a=1,b=1) is an escape: 4 bits n, then
                         4*(n+3) raw bytes are copied
  distance code: bit 0 -> high byte 0; else a short prefix code giving a 4 bit value 1..15 that becomes the
                 high byte; the low byte is the next input byte.  Source = out - distance - 1, copied forward.
```
Side effects: `D_8014D420` (= `rnc_last_unpacked_size`) receives the unpacked size from the header;
`D_8014D41E` (= `rnc_tail_count`) is zeroed and read back, so the "append tail halfwords" loop at the end
(`D_002B30B4`) never runs.  The error exits (`$v0 = -1 / -2`) are unreachable; the routine returns 0.

### Deliberate differences (corrupt streams only)

The original has no bounds checks at all.  The C checks every input read (in + packed + 16),
output write (`out + unpacked`) and back reference (`>= out`), aborts Huffman tables of more than 16
symbols (original: overruns a 16 byte scratch area and overwrites its saved `$ra`) and returns `-1`/status
instead of running off.  For every stream where the original stays inside these bounds the results are
identical, which is what the test checks.

## Thread / scheduler assembly (`thread.c`)

These are `exceptasm.s` leaf routines of the N64 SDK.

* `__osEnqueueThread(queue, t)` - insert in a priority-ordered singly linked list, after all threads of
  priority `>= t->priority`; the list ends in a sentinel of priority -1 (`__osThreadTail`).  `$t9` =
  predecessor, `$t8` = successor.  Sets `t->queue`.
* `__osPopThread(queue)` - unlink and return the head; clears the popped thread's `next`.
* `__osCleanupThread` - return address of every thread's initial frame: `osDestroyThread(NULL)`.  In the ROM
  it has no `jr $ra` (it falls into the next object, which is never reached).
* `__osEnqueueAndYield(queue)` - saves the running thread: `sr | EXL`, `s0-s7 gp sp fp ra`, `pc = ra`; if
  `t->fp` also `FCSR` and `$f0,$f2,$f4,$f8..$f30` (and the odd registers when `SR_FR` is set; `$f6` is a
  caller-saved temporary and is skipped); widens the saved interrupt mask with the globally masked bits,
  merges the MI interrupt mask (`MI_INTR_MASK_REG`) with `__OSGlobalIntMask` and the thread's `rcp` image,
  optionally enqueues the thread on `queue`, then `j __osDispatchThread`.  The live-register and cop0
  accesses are the `hw_*` stub functions.
* `dbgSetWatchpoint(addr, mode)` - `mtc0 WatchLo`: `(addr & 0x0FFFFFF8) | (mode & 3)` (bit 0 = write,
  bit 1 = read), followed by a hazard-clearing read of WatchHi into `$zero`.

`__osDispatchThread` is also hand-written assembly but was not part of this task; it is declared extern.

## Verification

Run from the repository root with a Python that has `ziglang` installed (`py -m pip install ziglang`):

```
py docs/hand_asm_c/test/run_tests.py [--seed N]  # RNC: ~1 minute (interpreter is slow); --quick for ~1 min less
py docs/hand_asm_c/test/run_thread_tests.py     # thread units, seconds
```

* `test/mips_interp.py` is a small big-endian MIPS interpreter.  It executes the *encoded words* printed
  in the comments of `src/libultra/*.s` (so exactly the ROM bytes, no re-assembly), including the trapping
  `add/addi/sub` instructions and the extra opcodes the thread units use.  It is the oracle.
  (The statically recompiled twins in `port/native` are not needed.)
* **RNC**: (1) all 2050 method 1 blobs of `baserom.us.v11.z64` are unpacked by the C and the CRC16 and size
  in each blob's header are verified (independent of the interpreter); (2) a sample of blobs, bit-flipped
  and truncated blobs, random garbage, and valid method 2 streams made by a test encoder written from the
  reverse engineered format are run through the original code and the C: the whole output region
  (`MARGIN` bytes before, the buffer and `SLACK` bytes after), the leftover `$v0` (method 1) and
  `D_8014D420` (method 2) must be byte-identical.  The encoder is self-checked: the original code must decode
  its streams to exactly the encoder input.  Corrupt cases in which the original goes out of bounds, traps
  or loops are skipped and counted; cases in which the C refuses but the original ran on are reported
  separately (see the results at the end of this file).
* **Threads**: random priority queues (insert / pop), random register / CP0 / FPU / interrupt-mask state for
  `__osEnqueueAndYield` (every saved field compared), `dbgSetWatchpoint` with random arguments, and the
  argument passed to `osDestroyThread` by `__osCleanupThread`.  `test_thread.c` `#include`s `thread.c` and
  supplies the `hw_*` stubs.  A deliberately mutated `thread.c` (`>=` to `>` in the queue walk, inverted mask)
  is detected by 144 of 401 scenarios, so the test is sensitive.

## Status per unit

| unit | status |
| --- | --- |
| rncUnpackMethod1, rncUnpackMethod1Body, rncReadHuffCode, rncInputBits, rncRefillBitBuf, rncMakeHuffTable | verified equivalent (ROM CRC of 2050 blobs + differential vs original code) |
| rncUnpackMethod2, rncUnpackMethod2Body | verified equivalent against the original code on encoder-made valid streams and mutated / random streams; no method 2 blob exists in the ROM, so there is no ROM-data check |
| __osEnqueueThread, __osPopThread, __osEnqueueAndYield, dbgSetWatchpoint | verified equivalent (differential, random scenarios) |
| __osCleanupThread | verified for the call it makes (`osDestroyThread(NULL)`); its fall-through into the next object is not modelled |

Not covered: the `hw_*` stubs are host stand-ins (the real thing is a single instruction each);
exception/interrupt timing, `eret` and anything after the jump to `__osDispatchThread`.

## Results of the last run (seeds 1-4)

* ROM check: 2050 / 2050 method 1 blobs unpacked by the C with matching size and CRC16.
* Differential, per seed 214-232 usable cases of 470 (90 ROM blobs, 14-17 bit-flipped and 6-12 truncated
  ROM blobs, 80 valid method 2 streams, 15-21 flipped and 4-6 truncated method 2 streams): 0 mismatches,
  0 refused-by-hardening.  The remainder is skipped: the original loops (step limit, mostly truncated
  streams and random garbage that never reaches the end test), writes or reads outside the buffers, or
  traps on `add`/`addi`.  Purely random byte streams almost never decode to something the original finishes,
  so corrupt-stream coverage comes mainly from the flipped / truncated real streams.
* Thread units: 401 scenarios, 0 mismatches.
* `RNC_DUMP="<label>" RNC_DUMP_FILE=out.bin py run_tests.py --seed N` writes one generated case to a
  file for debugging.
