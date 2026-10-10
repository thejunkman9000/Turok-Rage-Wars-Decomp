# Other versions of the game

**Status: on hold.**  Building the other releases from our code (US v1.0, Europe, Germany) waits until US v1.1 is completely done; only the
analysis below exists (`tools/ver_diff.py`, `tools/ver_cover.py`, the "other releases" panel of `tools/progress_chart.py`).  The prompt for the
per-release workers is `docs/VERSION_PROMPT.txt`.

ROMs (project root, gitignored, never commit them):

| file | game | sha1 | melalawi name |
|---|---|---|---|
| baserom.us.v11.z64 | Turok: Rage Wars (US v1.1) - the version this repo matches | 037fb397... | us-rev1 |
| baserom.us.v10.z64 | Turok: Rage Wars (US v1.0) | 9f8cb190... | us |
| baserom.eu.z64 | Turok: Rage Wars (Europe) | 46b474fa... | eu |
| baserom.de.z64 | Turok: Legenden des Verlorenen Landes (Germany, censored) | a6daacbd... | de |
| baserom.us.v10.palfix1.z64 / palfix2.z64 | US v1.0 patched to run on PAL consoles (232 / 15 words differ from v1.0) | e8f68992... / 9941a0d2... | (not in their list) |

(their eu-x = PAL multi-language release: not available here.)

## How much code is shared with us-rev1 (`python tools/ver_diff.py`)
Per version about 2,800 functions (~160k instructions) are byte-identical or identical up to relocations (j/jal targets, symbol
addresses), 165-190 functions (~30k instructions) exist only in us-rev1 / have no counterpart, and only a few dozen differ in length or
code (eu: 52 functions with another size, de: 12 plus 5 real code differences, us v1.0: 8).  So a version build = our matched C compiled with
that version's addresses + the version-specific functions.

Data for the other versions' addresses: melalawi/ragewars-decomp `versions/<ver>/{slices.mk,symbol_addrs.txt,symbols.ld,RageWars.yaml,report.json}`
(CC0; clone in D:\Projects\ext\ragewars-decomp).  Unit names are shared across versions, so a function of ours has a counterpart in version v
iff its unit name appears in `versions/v/slices.mk`.
