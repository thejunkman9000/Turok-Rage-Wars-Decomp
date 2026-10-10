#ifndef MENU_ABBDC_VERSIONS_H
#define MENU_ABBDC_VERSIONS_H
/* PAL menu text tables select the current language; constant and table bases follow each cartridge. */
#if defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#define MENU_LANGUAGE D_80152789
#else
#define MENU_LANGUAGE 0
#endif


#endif
