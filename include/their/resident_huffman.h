#ifndef RESIDENT_HUFFMAN_H
#define RESIDENT_HUFFMAN_H
/* The decoder at USrev1 0x802C4074 indexes 4-byte nodes. A bit selects
 * the halfword at offset 0 or 2. A node whose first halfword is 0x0800
 * is a terminal; its second halfword is a signed literal or a control code. */
typedef struct ResidentHuffmanNode {
    unsigned short left_or_leaf;
    short right_or_symbol;
} ResidentHuffmanNode;
enum ResidentHuffmanSymbol {
    HUFFMAN_LEAF = 0x0800,
    HUFFMAN_BITS_ESCAPE = 0x0900,
    HUFFMAN_ZERO_RUN_BASE = 0x0A00,
    HUFFMAN_END_BLOCK = 0x0B00
};
#define HUFFMAN_ZERO_RUN(index) (HUFFMAN_ZERO_RUN_BASE + (index))
/* Zero-run templates selected by control symbols 0x0A00 + index.
 * The decoder reads decoded_count at 0x1A0 and signed values at
 * 0xA2 + 4*i. Unused storage is explicitly separated from those fields;
 * the initialized template emits decoded_count zero coefficients. */
typedef struct ResidentHuffmanZeroRun {
    char description[16];
    unsigned int reserved_header[36];
    ResidentHuffmanNode coefficient_slots[64];
    int decoded_count;
    unsigned int reserved_tail[3];
    int sentinel0;
    int sentinel1;
} ResidentHuffmanZeroRun;
/* The pointed-to 36-byte dictionaries are imported from the preceding
 * resident extent. No definition of that separately owned storage is here. */
typedef struct ResidentHuffmanDictionary ResidentHuffmanDictionary;
typedef struct ResidentHuffmanBlockRange {
    int enabled;
    int first_sample;
    int sample_count;
    int bit_cursor;
    const ResidentHuffmanDictionary *dictionary;
} ResidentHuffmanBlockRange;
#endif
