#ifndef SN64_TYPE_RECORDS_H
#define SN64_TYPE_RECORDS_H

/* SN64's serialized .def/.def2 records retain the PC tool's little-endian
 * integer encoding, even in a big-endian MIPS resident segment. Names are
 * length-prefixed, without a terminating NUL. Each wrapper has alignment 1. */
typedef struct Sn64Le16 { unsigned char low, high; } Sn64Le16;
typedef struct Sn64Le32 { unsigned char low, byte1, byte2, high; } Sn64Le32;
typedef struct Sn64ValueTail24 { unsigned char byte1, byte2, high; } Sn64ValueTail24;
#define SN64_LE16(n) { (n) & 255, ((n) >> 8) & 255 }
#define SN64_LE32(n) { (n) & 255, ((n) >> 8) & 255, ((n) >> 16) & 255, ((n) >> 24) & 255 }
#define SN64_VALUE_TAIL24(n) { ((n) >> 8) & 255, ((n) >> 16) & 255, ((n) >> 24) & 255 }

enum Sn64DefinitionKind { SN64_DEF = 0x94, SN64_DEF2 = 0x96 };
enum Sn64StorageClass {
    SN64_MEMBER = 8, SN64_STRUCT_TAG = 10, SN64_TYPEDEF = 13,
    SN64_ENUM_TAG = 15, SN64_ENUM_MEMBER = 16, SN64_END_STRUCT = 102
};
typedef struct Sn64DefinitionHeader {
    Sn64Le32 value;
    unsigned char kind;
    Sn64Le16 storage_class;
    Sn64Le16 type;
    Sn64Le32 size;
} Sn64DefinitionHeader;
typedef struct Sn64DefinitionHeaderTail {
    Sn64ValueTail24 value_tail;
    unsigned char kind;
    Sn64Le16 storage_class;
    Sn64Le16 type;
    Sn64Le32 size;
} Sn64DefinitionHeaderTail;
#endif
