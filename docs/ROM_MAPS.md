# Map data in the ROM (US v1.1)

`python tools/dump_maps.py` writes the raw, unpacked data to `assets/maps`, `assets/meshes`, `assets/slots` (gitignored).
`tools/rnc.py` is the Rob Northen (RNC1) unpacker; `tools/extract_assets.py` decodes the texture banks to PNG.

## Resource directory (found by tracing the game's own PI DMA reads)
ROM `0x50F768`: root table, `u32 count (24)` + 24 `u32` offsets relative to `0x50F768`.
A slot is a lone RNC chunk, or a table (`u32 count` + offsets relative to the table start).
A *container* is `u32 n`, `n+1` offsets relative to the container (the last is the end), parts in between.
A part starting with `RNC\x01` is compressed; raw parts can themselves be sub-containers holding RNC chunks.

| slot | ROM | content |
|---|---|---|
| 0 | 0x50F7D0 | 347 mesh containers (header container + RNC mesh; e.g. mesh 0 = 4-vertex quad, 168 B) |
| 1 | 0x5F8720 | object/actor type index (169 records of 0x28 bytes) |
| 3 | 0x5F90E8 | 507 texture banks (`tools/extract_assets.py` decodes them) |
| 5 | 0x734000 | **37 map records**, 13 parts each (below) |
| 16 | 0x769C98 | 69 images/sprites (tiled full-screen pictures etc.) |
| 21 | 0x79CC78 | 36 records of 3382 B |
| 2,4,6-15,17-20,22-23 | | single chunks / small tables |

## Map record (slot 5, container of 13 parts); part 8 holds the name
Maps (index: name): 0 PROVING GROUNDS, 1 BASIC TRAINING, 2 CROSSROADS, 3 GRIM RETREAT, 4 CATHEDRAL, 5 FALLOUT, 6 BOXED SET,
7 DIRE STRAIGHT, 8 PREY, 9 WAREHOUSE, 10 WATER TEMPLE, 11 BOMB SHELTER, 12 TEMPERED, 13 EARTH TEMPLE, 14 FIRE TEMPLE, 15 MYSTIC,
16 BOTTLENECK, 17 TIGHTROPE, 18 THE PIT, 19 LEAP OF FAITH, 20 WICKED DANCE, 21 BUNKER, 22 AMPHITHEATER, 23 FIRE WALKER, 24 CRYPTS,
25 BREAKDOWN, 26 RETALIATION, 27 HOPELESS, 28 MATRIX, 29 FATHOM, 30 THE PEDESTAL, 31 DEFCON 5, 32 SPIRIT TEMPLE, 33 STRONGHOLD,
34 COURTYARD, 35 STARLIGHT, 36 "37_scrap" (empty placeholder).

| part | kind | meaning (what is verified / guessed) |
|---|---|---|
| 0 | raw 24 B | float 25.6 + colour bytes (ambient/fog?) - guess |
| 1 | RNC | settings block (floats: 0x45300000 = 2816.0, 74.0, 1536.0, 47.5 ...) |
| 2 | RNC 8 B | |
| 3 | RNC | byte table, 0xFF-filled (nav / AI cells?) |
| 4 | RNC | list of `{type, 2, x, z}` entries (floats) |
| 5 | raw sub-container | 4 RNC chunks (`partNN_rncXX.bin`); first has the form `u32 5, offsets, 0x1C, 0x5B, ...` |
| 6 | RNC 712 B | identical in every map |
| 7 | RNC | small table |
| 8 | raw 16 B | map name, ASCII |
| 9 | RNC | object list: `u32 count, u32 0x29, count x {x, y, z, ?, u16 id, u16 flags}` (spawn points / pickups) |
| 10 | RNC | link table |
| 11 | RNC | square 0/1 matrix: `u32 1, u32 N, N bytes`, N = K*K (K = 41 in PROVING GROUNDS ... 100 in STARLIGHT; every map's N is a perfect square). Banded around the diagonal, so it looks like a sector-to-sector visibility table (the game has `m_bLevelHasVisibilityInfo`, "level nav vision"): K = number of sectors/rooms.  `tools/map_grids.py` draws them. |
| 12 | raw 40 B | |

The floor/wall geometry is NOT decoded yet.  What is known: the game draws each wall panel as `matrix + vertex buffer + call of a static 4-vertex quad list` (see PORT_STATUS.md).  The meanings in the table
for parts other than 8 and 11 are inferred from the data layout, not from the game code; part 11 being a visibility matrix is a reading of its shape.

## Placement chunk (separate from the 36 maps)
RNC chunk `0x768DB8` (root slot 8) holds 321 instances `{x, y, z, yaw, u16 modelIndex, 0xFFFF}` (20 B records, header `0x14, 0x141`)
with positions on a 51.2-unit grid; these match the panel matrices the renderer sees in the 1-player trial level.
