#ifndef MENU_ROM_RECORDS_H
#define MENU_ROM_RECORDS_H
#include "types.h"
/* The ROM keeps TLB virtual code addresses (004xxxxx). The incomplete tag
 * represents an address label only: it defines no storage or callable ABI.
 * 8023C084 maps these pages to resident buffers; 80440F10 and 80441384 load
 * and call the stored words directly. KSEG0 function pointers are different. */
typedef struct MenuPagedCodeAddress MenuPagedCodeAddress;
typedef struct MenuStoredCodeAddress {
    const MenuPagedCodeAddress *address;
} MenuStoredCodeAddress;
typedef struct MenuRomColor { u8 red, green, blue, alpha; } MenuRomColor;
/* 80440F10 copies offsets00..10, steps descriptors by36, and creates40-byte
 * runtime items. Rendering/update/selection read14/18/1C. Inventory drawing
 * at8043EFD0 reads signed item_kind/index at20/22 of the same descriptor. */
typedef struct MenuRomDescriptor {
    s16 type;
    u16 reserved;
    u32 flags;
    u16 x, y;
    MenuRomColor color;
    u32 value;
    MenuStoredCodeAddress draw, update, select;
    s16 item_kind, item_index;
} MenuRomDescriptor;
/* List consumers read signed count at04, invoke08/0C/10/14 and copy three
 * halfwords at18/1A/1C. The word20 links the fallback list; no ABI inferred. */
typedef struct MenuRomList {
    u32 entries;
    s16 count, reserved;
    MenuStoredCodeAddress initialize, destroy, draw, update;
    s16 cursor, mode, field_1c, field_1e;
    u32 fallback;
} MenuRomList;
typedef struct MenuRomDescriptorPrefix {
    s16 type;
    u16 reserved;
    u32 flags;
    u16 x, y;
} MenuRomDescriptorPrefix;
typedef struct MenuRomDescriptorTail {
    MenuRomColor color;
    u32 value;
    MenuStoredCodeAddress draw, update, select;
    s16 item_kind, item_index;
} MenuRomDescriptorTail;
/* Actual16-byte cheat entries consumed by8043CDF8 and8043CF44. */
typedef struct MenuRomCheat {
    u32 code, display_text;
    u32 flags;
    s32 sound;
} MenuRomCheat;
#define RW_MENU_RESIDENT_ADDRESS(symbol, addend) ((u32)&(symbol) + (addend))
typedef char menu_rom_descriptor_size[(sizeof(MenuRomDescriptor)==36)?1:-1];
typedef char menu_rom_list_size[(sizeof(MenuRomList)==36)?1:-1];
typedef char menu_rom_code_word_size[(sizeof(MenuStoredCodeAddress)==4)?1:-1];
#endif
