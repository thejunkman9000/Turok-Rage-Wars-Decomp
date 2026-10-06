# Turok: Rage Wars (US v1.1) - ROM layout notes

ROM: `NRWE` v1.1, 8 MB big-endian (.z64), SHA1 `037fb397cee2669048ed6b762a64698de4a4d88a`.
Dumped base ROM goes in `baserom.us.v11.z64` (gitignored; never commit it).

## Boot (ROM 0x1000, entry 0x80000400)
Custom Acclaim/Iguana boot stub, not stock libultra:
- wipes all 32 TLB entries, sets `$sp = 0x803FFFC0`
- maps TLB entry 0x1F: PageMask 0x1FE000 (1 MB pages), EntryHi 0x00200000,
  EntryLo0 -> phys 0x000000, EntryLo1 -> phys 0x100000
- `jalr 0x002A81B0` (game entry in the TLB-mapped space)

IPL3 copies ROM 0x1000.. to RAM phys 0x400, so **ROM 0x1000 == VA 0x00200400**
(VA = ROM + 0x1FF400). Game code is linked in the TLB-mapped space (0x002xxxxx), *not* KSEG0.
Disassembling it with a 0x80000400 vram gives wrong jal targets.

## Regions
| ROM range | VA | Content | Confidence |
|---|---|---|---|
| 0x000000-0x001000 | - | header + IPL3 | certain |
| 0x001000-0x0C7010 | 0x200400-0x2C6410 | main code (3175 funcs found by splat) | high: 9206 jal hit 0x200500-0x2C6A00 |
| 0x0C7010-~0x0E0000 | ? | RSP microcode (cop2/mtc0 seen at 0xDFF84) + data | medium |
| ~0x0E0000-0x160000 | ? | low-entropy data / rodata | low, unsplit |
| 0x160000-0x16E000 | 0x400000 (per page?) | 14 x 0x1000-stride copies of one routine (md5: pages 0=1, 3..8 identical). Jumps such as `j 0x4011F0` leave the 4 KB page, so 4 KB is NOT the true unit. Carried as raw bin. | unresolved |
| 0x16E000-0x1BCD94 | 0x400000 | overlay A code (1281 funcs) | high: 61% of internal jal targets are prologues, peak is unique |
| 0x1BCD94-0x240000 | ? | data | low |
| 0x240000-0x790000 | - | high entropy (7-7.9 bits/byte): compressed assets/levels | - |
| 0x7A0000-0x800000 | - | padding | certain |

## Method notes
`tools/jal_hist.py`, `tools/code_extent.py`: jal target statistics.
Base-address recovery: for candidate ROM base B, count how many internal `jal` targets land
on `addiu sp,sp,-N` prologues; the true base is a sharp outlier (overlay A: 61% vs <12% next best).

## Related work
Rage Wars derives from the Turok 2 engine. Drahsid's LibTEngine (github.com/Drahsid/LibTEngine)
documents Turok 2 / Turok 3 structs and function signatures - useful for naming.
No public Rage Wars decomp found.

## Open questions / next steps
1. Work out the real structure of the 0x160000 chunk (what loads it, true unit size; jumps reach 0x4011F0+).
2. Find who loads overlays (DMA/PI calls from main) -> overlay table, other overlays that share VA 0x400000?
3. Identify RSP microcode (F3DEX2 variant?) and where it ends.
4. Identify libultra version via function signatures -> choose compiler (KMC GCC 2.7.2 vs IDO).
5. Identify asset compression (high entropy region) and write extractors.

## Build / verify (WSL Ubuntu-24.04)
`bash tools/roundtrip.sh` assembles splat's asm, links with `turok_ragewars.ld` + `hardware_regs.ld`
+ `extra_syms.ld`, and compares to the base ROM. **Currently byte-identical (8,388,608 bytes).**
Notes: assembler needs `-W` (game uses odd float regs, thousands of warnings); splat needs
`subalign: 4` and `ld_align_*_vram_end: False`, and the code/data split in ovl_a sits at the
16-aligned 0x1BCDA0 so linker padding does not shift the tail.
Regenerate with: `.venv\Scripts\python -m splat split turok_ragewars.yaml` (Windows) then run the round trip in WSL.

## Compiler identification (in progress)
Evidence (tools/compiler_id.py, whole ROM code):
- 17,692 register moves, **100% `addu rd,rs,$zero`**, 0 `or` -> not IDO; GCC-family with an old assembler.
- Frame layout: `$s` regs saved low, `$ra` above them (e.g. F=0x18 ra@0x10, F=0x20 ra@0x18) -> GCC, not IDO.
- Function at ROM 0x1100 (`s32 f(){ u32 s=a(); b(s&~1); return s&1; }`) **matches byte-for-byte** with
  GCC 2.7.2 (also 2.7.2.3) default flags: `-meb -mips2 -mgp32 -mfp32 -G 0 -O2 -mno-abicalls -fno-pic`
  (GCC does `jal` delay-slot filling itself via `.set noreorder`). GCC 2.8.1 matches only with `-fno-delayed-branch`.
  So 2.7.2 default is the simplest fit; 2.7.2 vs 2.8.1 is NOT yet distinguished (needs bigger functions).
- Assembler quirks to reproduce the original `as`: `move` must become `addu rd,rs,$0`, and a
  `j $31` must keep a `nop` delay slot (modern gas would pull the `addu $sp` into it). `tools/cc_try.sh`
  post-processes the compiler's .s accordingly.
- Compilers: decompals/old-gcc release 0.17 (`tools/get_gcc.sh` -> `tools/gcc/<ver>/`, gitignored), run from WSL.
  Copy sources to /tmp before compiling (old cpp fails on /mnt/d inodes: "Value too large").

Next: find larger known-source functions (libultra: osCreateMesgQueue/osSendMesg/__osDispatchThread via
libreultra) in the ROM and compile them with each GCC version to settle the version + libultra flags.
