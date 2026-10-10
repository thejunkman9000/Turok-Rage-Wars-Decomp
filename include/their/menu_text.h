#ifndef RAGEWARS_MENU_TEXT_H
#define RAGEWARS_MENU_TEXT_H

#if defined(VERSION_EU_X)
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_x_table)[language])
#elif defined(VERSION_EU)
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) ((eu_table)[language])
#else
#define RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, language) (fixed)
#endif
#define RW_MENU_TEXT(fixed, eu_table, eu_x_table, settings) RW_LOCALIZED_TEXT(fixed, eu_table, eu_x_table, (settings)[0x581])

#endif
