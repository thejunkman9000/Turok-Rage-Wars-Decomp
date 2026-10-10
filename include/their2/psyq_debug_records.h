#ifndef PSYQ_DEBUG_RECORDS_H
#define PSYQ_DEBUG_RECORDS_H
/* Serialized SN/PsyQ .sym definition records. The stream is little endian,
 * independent of the VR4300 CPU byte order. Pascal strings exclude terminators.
 * Definition(0x94): address, opcode, COFF class/type, size, Pascal name.
 * Definition2(0x96): additionally dimensions and a Pascal type-tag name.
 * Format: https://gist.github.com/boricj/2304312a00d22f765276e9695bb7d7fd
 */
typedef struct { unsigned char low, high; } PsyqLE16;
typedef struct { unsigned char byte0, byte1, byte2, byte3; } PsyqLE32;
#define PSYQ_LE16(v) { (v) & 255, ((v) >> 8) & 255 }
#define PSYQ_LE32(v) { (v) & 255, ((v) >> 8) & 255, ((v) >> 16) & 255, ((v) >> 24) & 255 }
typedef struct {
    PsyqLE32 address;
    unsigned char opcode;
    PsyqLE16 storage_class;
    PsyqLE16 coff_type;
    PsyqLE32 byte_size;
} PsyqDefinitionHeader;
enum PsyqStorageClass {
    PSYQ_NULL = 0,
    PSYQ_AUTO = 1,
    PSYQ_EXT = 2,
    PSYQ_STAT = 3,
    PSYQ_REG = 4,
    PSYQ_EXTDEF = 5,
    PSYQ_LABEL = 6,
    PSYQ_ULABEL = 7,
    PSYQ_MOS = 8,
    PSYQ_ARG = 9,
    PSYQ_STRTAG = 10,
    PSYQ_MOU = 11,
    PSYQ_UNTAG = 12,
    PSYQ_TPDEF = 13,
    PSYQ_USTATIC = 14,
    PSYQ_ENTAG = 15,
    PSYQ_MOE = 16,
    PSYQ_REGPARM = 17,
    PSYQ_FIELD = 18,
    PSYQ_BLOCK = 19,
    PSYQ_FCN = 20,
    PSYQ_FUNCTION = 101,
    PSYQ_EOS = 102,
    PSYQ_FILE = 103,
    PSYQ_LINE = 104,
    PSYQ_ALIAS = 105,
    PSYQ_HIDDEN = 106
};
#endif
