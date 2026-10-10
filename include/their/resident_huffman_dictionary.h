#ifndef RESIDENT_HUFFMAN_DICTIONARY_H
#define RESIDENT_HUFFMAN_DICTIONARY_H
#include "resident_huffman.h"

/* Resident dictionaries consumed by the decoder at USrev1 802C4074.
 * The leading words are retained as decoder parameters; only the escape
 * width and the two pointee fields have direct consumer evidence here.
 * The decoder reads the escape width's low halfword at offset 14 and
 * follows zero_runs at 28 and nodes at 32. */
struct ResidentHuffmanDictionary {
    int parameter_0;
    int parameter_1;
    int parameter_2;
    int escape_bits;
    int parameter_4;
    int parameter_5;
    int zero_run_count;
    const ResidentHuffmanZeroRun *zero_runs;
    const ResidentHuffmanNode *nodes;
};
typedef char resident_huffman_dictionary_size_check[
    (sizeof(struct ResidentHuffmanDictionary) == 36) ? 1 : -1];
#endif
