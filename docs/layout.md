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
| 0x160000-0x16E000 | **unknown** | code, 56 jr ra; calls main (0x24-0x2B xxxxx) and ovl A | VA base unresolved |
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
1. Resolve the VA base of the 0x160000 chunk (same brute-force against targets it exports).
2. Find who loads overlays (DMA/PI calls from main) -> overlay table, other overlays that share VA 0x400000?
3. Identify RSP microcode (F3DEX2 variant?) and where it ends.
4. Identify libultra version via function signatures -> choose compiler (KMC GCC 2.7.2 vs IDO).
5. Identify asset compression (high entropy region) and write extractors.
