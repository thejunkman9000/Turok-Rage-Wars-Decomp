#ifndef UNBAKE_SPAN_16E000_CODE_80444030_H
#define UNBAKE_SPAN_16E000_CODE_80444030_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Settings_func_80444988_de;
/* unbake published declaration: published_00a22f8a6502bbd118e9090f */
struct Settings_func_80444988_de {
    char pad[0x79];
    u8 value;
};

struct Settings_func_80444BE8_de;
/* unbake published declaration: published_06a454e488f58ed8b841f363 */
struct Settings_func_80444BE8_de {
    char pad[0x82];
    u8 flag;
};

struct Settings_func_80444AB8_de;
/* unbake published declaration: published_08fdbd15e5825416e5e6029e */
struct Settings_func_80444AB8_de {
    char pad[0x7A];
    u8 value;
};

struct Owner_func_80444BE8_de;
struct Settings_func_80444BE8_de;
struct Owner_func_80444BE8_de {
    char pad[0x5D8];
    struct Settings_func_80444BE8_de *settings;
};
struct Holder_func_80444BE8_de;
struct Owner_func_80444BE8_de;
/* unbake published declaration: published_1c6fa256be485c1bd45db243 */
struct Holder_func_80444BE8_de {
    char pad[0x1C];
    struct Owner_func_80444BE8_de *owner;
};

struct Owner_func_80444988_de;
struct Settings_func_80444988_de;
struct Owner_func_80444988_de {
    char pad[0x5D8];
    struct Settings_func_80444988_de *settings;
};
struct Holder_func_80444988_de;
struct Owner_func_80444988_de;
/* unbake published declaration: published_261a7584d4d5ba5f7ad5c16a */
struct Holder_func_80444988_de {
    char pad[0x1C];
    struct Owner_func_80444988_de *owner;
};

struct Actor_func_804441F4_de;
struct Owner_func_804441F4_de;
/* unbake published declaration: published_de32402682eb7498c114f4ad */
struct Actor_func_804441F4_de {
    char pad[0x1C];
    struct Owner_func_804441F4_de *owner;
};

struct Actor_func_804441F4_de;
/* unbake published declaration: published_269687394d2747376542616c */
extern char *func_804441F4_de(struct Actor_func_804441F4_de *actor);

struct Settings_func_80444610_de;
/* unbake published declaration: published_af3e320c4d88baef110d623c */
struct Settings_func_80444610_de {
    char pad[0x7E];
    u8 value;
};

struct Owner_func_80444610_de;
struct Settings_func_80444610_de;
struct Owner_func_80444610_de {
    char pad[0x5D8];
    struct Settings_func_80444610_de *settings;
};
struct Holder_func_80444610_de;
struct Owner_func_80444610_de;
/* unbake published declaration: published_280c0dcbbbc29068afc0289b */
struct Holder_func_80444610_de {
    char pad[0x1C];
    struct Owner_func_80444610_de *owner;
};

/* unbake published declaration: published_3513bd04d34dc5edfefcce4c */
extern void func_804441E4_de(void);

struct Settings_func_80444548_de;
/* unbake published declaration: published_3d0b663d04105843038a3d00 */
struct Settings_func_80444548_de {
    char pad[0x7D];
    u8 value;
};

struct Owner_func_80444548_de;
struct Settings_func_80444548_de;
struct Owner_func_80444548_de {
    char pad[0x5D8];
    struct Settings_func_80444548_de *settings;
};
struct Holder_func_80444548_de;
struct Owner_func_80444548_de;
/* unbake published declaration: published_5a0e1b5749d532d0cca72f4f */
struct Holder_func_80444548_de {
    char pad[0x1C];
    struct Owner_func_80444548_de *owner;
};

struct Record_func_8043E494_de;
/* unbake published declaration: published_5d6ceb5e66644782dfb7e52a */
typedef struct Record_func_8043E494_de Record_func_8043E494_de;

struct Settings_func_80444488_de;
/* unbake published declaration: published_8ee0ec1dc06933ea957ed17c */
struct Settings_func_80444488_de {
    char pad[0x7C];
    u8 value;
};

struct Owner_func_80444AB8_de;
struct Settings_func_80444AB8_de;
struct Owner_func_80444AB8_de {
    char pad[0x5D8];
    struct Settings_func_80444AB8_de *settings;
};
struct Holder_func_80444AB8_de;
struct Owner_func_80444AB8_de;
/* unbake published declaration: published_9eb27d5d697c8462a6762f3f */
struct Holder_func_80444AB8_de {
    char pad[0x1C];
    struct Owner_func_80444AB8_de *owner;
};

/* unbake published declaration: published_a9fa0a3dfb25614e5439b181 */
extern void func_80444094_de(u8 *record, u8 value);

struct Owner_func_80444488_de;
struct Settings_func_80444488_de;
struct Owner_func_80444488_de {
    char pad[0x5D8];
    struct Settings_func_80444488_de *settings;
};
struct Holder_func_80444488_de;
struct Owner_func_80444488_de;
/* unbake published declaration: published_bd685b2ac56165732292203d */
struct Holder_func_80444488_de {
    char pad[0x1C];
    struct Owner_func_80444488_de *owner;
};

struct MenuItem_func_80444314_de;
/* unbake published declaration: published_eec9aec5dff2b2555c970073 */
struct MenuItem_func_80444314_de {
    char pad0[8];
    u32 flags;
    char padC[8];
    void *table;
};

struct MenuItem_func_80444314_de;
/* unbake published declaration: published_fb2959dbf051752e89ddb05e */
typedef struct MenuItem_func_80444314_de MenuItem_func_80444314_de;

struct Item_func_80441FE8_de;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8044488C_de(struct Item_func_80441FE8_de *field);
#endif

#endif
