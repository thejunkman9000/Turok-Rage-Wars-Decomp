/* Independently reconstructed eight-byte audio command storage, MIT.
 * Encoding provenance is recorded in abi.h. */
#ifndef UNBAKE_SHARED_ACMD_H
#define UNBAKE_SHARED_ACMD_H
typedef struct {
    unsigned int w0;
    unsigned int w1;
} Awords;
typedef union {
    Awords words;
    long long int force_union_align;
} Acmd;
#endif
