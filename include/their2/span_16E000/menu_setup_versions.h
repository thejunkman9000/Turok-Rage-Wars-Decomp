#ifndef MENU_SETUP_VERSIONS_H
#define MENU_SETUP_VERSIONS_H
#if defined(VERSION_US_REV1)
#endif

/* Versioned setup strings and control identifiers from the native menu tables. */
#if defined(VERSION_US)
extern int jtbl_800DDDD0;
extern int jtbl_800DDE48;
extern s8 D_800DDDC8[8];
#elif defined(VERSION_EU)
extern int jtbl_800DDDD0;
extern int jtbl_800DDE48;
extern s8 D_800DDDC8[8];
#elif defined(VERSION_EU_X)
extern int jtbl_800DDDD0;
extern int jtbl_800DDE48;
extern s8 D_800DDDC8[8];
#elif defined(VERSION_DE)
extern int jtbl_800DDDD0;
extern int jtbl_800DDE48;
extern s8 D_800DDDC8[8];
#else
extern int jtbl_800DDDD0;
extern int jtbl_800DDE48;
extern s8 D_800DDDC8[8];
#endif
#if defined(VERSION_DE)
extern s32 D_800DF4C4;
#elif defined(VERSION_US)
extern s32 D_800DE174;
#elif defined(VERSION_EU)
extern s32 D_800EFB34;
#elif defined(VERSION_EU_X)
extern s32 D_800EACF4;
#else
extern s32 D_800E3514;
#endif
#if defined(VERSION_DE)
enum { SETUP_LABEL_ID = 0x281 };
enum { PANEL_ROOT_ID = 0x2E1 };
enum { PANEL_TEXT_ID = 0x2E3 };
enum { MODE_DEFAULT_ID = 0x35E };
enum { MODE_17_ID = 0x362 };
enum { MODE_2_ID = 0x360 };
enum { MODE_3_ID = 0x361 };
enum { MODE_46_ID = 0x363 };
enum { MODE_5_ID = 0x35F };
enum { MODE_HIDE_ID = 0x2E2 };
enum { SLOT_DEFAULT_ID = 0x28C };
enum { SLOT_1_ID = 0x28E };
enum { SLOT_2_ID = 0x290 };
enum { SLOT_3_ID = 0x292 };
enum { CHECK_0_ID = 0x296 };
enum { CHECK_1_ID = 0x298 };
enum { CHECK_2_ID = 0x29A };
enum { CHECK_DEFAULT_ID = 0x29C };
#elif defined(VERSION_EU_X)
enum { SETUP_LABEL_ID = 0x28A };
enum { PANEL_ROOT_ID = 0x2D1 };
enum { PANEL_TEXT_ID = 0x2D3 };
enum { MODE_DEFAULT_ID = 0x36D };
enum { MODE_17_ID = 0x371 };
enum { MODE_2_ID = 0x36F };
enum { MODE_3_ID = 0x370 };
enum { MODE_46_ID = 0x372 };
enum { MODE_5_ID = 0x36E };
enum { MODE_HIDE_ID = 0x2D2 };
enum { SLOT_DEFAULT_ID = 0x294 };
enum { SLOT_1_ID = 0x296 };
enum { SLOT_2_ID = 0x298 };
enum { SLOT_3_ID = 0x29A };
enum { CHECK_0_ID = 0x29F };
enum { CHECK_1_ID = 0x2A1 };
enum { CHECK_2_ID = 0x2A3 };
enum { CHECK_DEFAULT_ID = 0x2A5 };
#else
enum { SETUP_LABEL_ID = 0x285 };
enum { PANEL_ROOT_ID = 0x2C1 };
enum { PANEL_TEXT_ID = 0x2C5 };
enum { MODE_DEFAULT_ID = 0x344 };
enum { MODE_17_ID = 0x348 };
enum { MODE_2_ID = 0x346 };
enum { MODE_3_ID = 0x347 };
enum { MODE_46_ID = 0x349 };
enum { MODE_5_ID = 0x345 };
enum { MODE_HIDE_ID = 0x2C4 };
enum { SLOT_DEFAULT_ID = 0x28B };
enum { SLOT_1_ID = 0x28D };
enum { SLOT_2_ID = 0x28F };
enum { SLOT_3_ID = 0x291 };
enum { CHECK_0_ID = 0x299 };
enum { CHECK_1_ID = 0x29B };
enum { CHECK_2_ID = 0x29D };
enum { CHECK_DEFAULT_ID = 0x29F };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_1_2EC = 0x2CF };
enum { UI_CASE_1_2EE = 0x2D1 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_1_2EC = 0x2E8 };
enum { UI_CASE_1_2EE = 0x2EA };
#else
enum { UI_CASE_1_2EC = 0x2EC };
enum { UI_CASE_1_2EE = 0x2EE };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_2_2D4 = 0x2A0 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_2_2D4 = 0x2D0 };
#else
enum { UI_CASE_2_2D4 = 0x2D4 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_3_2BB = 0x2D5 };
enum { UI_CASE_3_2BC = 0x2D7 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_3_2BB = 0x2DC };
enum { UI_CASE_3_2BC = 0x2DD };
#else
enum { UI_CASE_3_2BB = 0x2BB };
enum { UI_CASE_3_2BC = 0x2BC };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_4_2D5 = 0x2E6 };
enum { UI_CASE_4_2DA = 0x2E8 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_4_2D5 = 0x2EE };
enum { UI_CASE_4_2DA = 0x2F5 };
#else
enum { UI_CASE_4_2D5 = 0x2D5 };
enum { UI_CASE_4_2DA = 0x2DA };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_6_2E4 = 0x2A9 };
enum { UI_CASE_6_2E8 = 0x2AF };
#elif defined(VERSION_EU_X)
enum { UI_CASE_6_2E4 = 0x2C5 };
enum { UI_CASE_6_2E8 = 0x2C9 };
#else
enum { UI_CASE_6_2E4 = 0x2E4 };
enum { UI_CASE_6_2E8 = 0x2E8 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_7_2CA = 0x2EF };
enum { UI_CASE_7_2CC = 0x2F1 };
enum { UI_CASE_7_2CB = 0x2F2 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_7_2CA = 0x2E4 };
enum { UI_CASE_7_2CC = 0x2E5 };
enum { UI_CASE_7_2CB = 0x2E3 };
#else
enum { UI_CASE_7_2CA = 0x2CA };
enum { UI_CASE_7_2CC = 0x2CC };
enum { UI_CASE_7_2CB = 0x2CB };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_8_2CE = 0x2F3 };
enum { UI_CASE_8_2CF = 0x2F5 };
enum { UI_CASE_8_2CB = 0x2F2 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_8_2CE = 0x2E0 };
enum { UI_CASE_8_2CF = 0x2E1 };
enum { UI_CASE_8_2CB = 0x2E3 };
#else
enum { UI_CASE_8_2CE = 0x2CE };
enum { UI_CASE_8_2CF = 0x2CF };
enum { UI_CASE_8_2CB = 0x2CB };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_9_2C6 = 0x2B0 };
enum { UI_CASE_9_2C8 = 0x2B2 };
enum { UI_CASE_9_2C7 = 0x2B3 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_9_2C6 = 0x2A9 };
enum { UI_CASE_9_2C8 = 0x2AC };
enum { UI_CASE_9_2C7 = 0x2AA };
#else
enum { UI_CASE_9_2C6 = 0x2C6 };
enum { UI_CASE_9_2C8 = 0x2C8 };
enum { UI_CASE_9_2C7 = 0x2C7 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_10_2A4 = 0x2C6 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_10_2A4 = 0x2AD };
#else
enum { UI_CASE_10_2A4 = 0x2A4 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_11_2D1 = 0x2D2 };
enum { UI_CASE_11_2D2 = 0x2D3 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_11_2D1 = 0x2D6 };
enum { UI_CASE_11_2D2 = 0x2D8 };
#else
enum { UI_CASE_11_2D1 = 0x2D1 };
enum { UI_CASE_11_2D2 = 0x2D2 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_12_2F2 = 0x2D9 };
enum { UI_CASE_12_2F3 = 0x2DA };
#elif defined(VERSION_EU_X)
enum { UI_CASE_12_2F2 = 0x2B1 };
enum { UI_CASE_12_2F3 = 0x2B2 };
#else
enum { UI_CASE_12_2F2 = 0x2F2 };
enum { UI_CASE_12_2F3 = 0x2F3 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_13_2AF = 0x2C7 };
enum { UI_CASE_13_2B6 = 0x2CE };
#elif defined(VERSION_EU_X)
enum { UI_CASE_13_2AF = 0x2F7 };
enum { UI_CASE_13_2B6 = 0x2FE };
#else
enum { UI_CASE_13_2AF = 0x2AF };
enum { UI_CASE_13_2B6 = 0x2B6 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_17_2A5 = 0x2C2 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_17_2A5 = 0x2E7 };
#else
enum { UI_CASE_17_2A5 = 0x2A5 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_15_2EF = 0x2C3 };
enum { UI_CASE_15_2F1 = 0x2C5 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_15_2EF = 0x2EB };
enum { UI_CASE_15_2F1 = 0x2ED };
#else
enum { UI_CASE_15_2EF = 0x2EF };
enum { UI_CASE_15_2F1 = 0x2F1 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_16_2B7 = 0x2B4 };
enum { UI_CASE_16_2B9 = 0x2B5 };
enum { UI_CASE_16_2BA = 0x2AA };
#elif defined(VERSION_EU_X)
enum { UI_CASE_16_2B7 = 0x2C1 };
enum { UI_CASE_16_2B9 = 0x2C3 };
enum { UI_CASE_16_2BA = 0x2C2 };
#else
enum { UI_CASE_16_2B7 = 0x2B7 };
enum { UI_CASE_16_2B9 = 0x2B9 };
enum { UI_CASE_16_2BA = 0x2BA };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_21_2E1 = 0x2A6 };
enum { UI_CASE_21_2E2 = 0x2A8 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_21_2E1 = 0x2D9 };
enum { UI_CASE_21_2E2 = 0x2DB };
#else
enum { UI_CASE_21_2E1 = 0x2E1 };
enum { UI_CASE_21_2E2 = 0x2E2 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_23_2AC = 0x2B7 };
enum { UI_CASE_23_2AE = 0x2B9 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_23_2AC = 0x2BE };
enum { UI_CASE_23_2AE = 0x2C0 };
#else
enum { UI_CASE_23_2AC = 0x2AC };
enum { UI_CASE_23_2AE = 0x2AE };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_24_2A9 = 0x2BC };
enum { UI_CASE_24_2AA = 0x2BD };
#elif defined(VERSION_EU_X)
enum { UI_CASE_24_2A9 = 0x2AE };
enum { UI_CASE_24_2AA = 0x2AF };
#else
enum { UI_CASE_24_2A9 = 0x2A9 };
enum { UI_CASE_24_2AA = 0x2AA };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_25_2EA = 0x2BA };
enum { UI_CASE_25_2EB = 0x2BB };
#elif defined(VERSION_EU_X)
enum { UI_CASE_25_2EA = 0x2BC };
enum { UI_CASE_25_2EB = 0x2BD };
#else
enum { UI_CASE_25_2EA = 0x2EA };
enum { UI_CASE_25_2EB = 0x2EB };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_26_2A6 = 0x2BF };
enum { UI_CASE_26_2A7 = 0x2C0 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_26_2A6 = 0x2B9 };
enum { UI_CASE_26_2A7 = 0x2BA };
#else
enum { UI_CASE_26_2A6 = 0x2A6 };
enum { UI_CASE_26_2A7 = 0x2A7 };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_28_2DE = 0x2A1 };
enum { UI_CASE_28_2DF = 0x2A2 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_28_2DE = 0x2CD };
enum { UI_CASE_28_2DF = 0x2CF };
#else
enum { UI_CASE_28_2DE = 0x2DE };
enum { UI_CASE_28_2DF = 0x2DF };
#endif
#if defined(VERSION_DE)
enum { UI_CASE_29_2BF = 0x2A4 };
enum { UI_CASE_29_2C0 = 0x2A5 };
#elif defined(VERSION_EU_X)
enum { UI_CASE_29_2BF = 0x2CB };
enum { UI_CASE_29_2C0 = 0x2CC };
#else
enum { UI_CASE_29_2BF = 0x2BF };
enum { UI_CASE_29_2C0 = 0x2C0 };
#endif

#endif
