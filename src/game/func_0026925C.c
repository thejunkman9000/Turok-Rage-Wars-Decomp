#include "b15_types.h"
#include "p4_types.h"

extern s32 D_800D15B4;
extern s32 D_800D15C0;
extern u32 D_800D15D8;
extern u32 D_800D15DC;
extern P4Gfx *D_80110634;

/* sets the RDP other-mode word (G_SETOTHERMODE_L) for the requested mode; returns 0 if unchanged */
s32 func_0026925C(u32 mode) {
    P4Gfx *g0;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *g3;
    P4Gfx *g4;
    P4Gfx *g5;
    P4Gfx *g6;
    P4Gfx *g7;
    P4Gfx *g8;
    P4Gfx *g9;
    P4Gfx *g10;
    P4Gfx *g11;
    P4Gfx *g12;
    P4Gfx *g13;
    P4Gfx *g14;
    P4Gfx *g15;
    P4Gfx *g16;
    P4Gfx *g17;
    P4Gfx *g18;
    P4Gfx *g19;
    P4Gfx *g20;
    P4Gfx *g21;
    P4Gfx *g22;
    P4Gfx *g23;
    P4Gfx *g24;
    P4Gfx *g25;
    P4Gfx *g26;
    P4Gfx *g27;
    P4Gfx *g28;
    P4Gfx *g29;
    P4Gfx *g30;
    P4Gfx *g31;
    P4Gfx *g32;
    P4Gfx *g33;
    P4Gfx *g34;
    P4Gfx *g35;
    P4Gfx *g36;
    P4Gfx *g37;
    P4Gfx *g38;
    P4Gfx *g39;
    P4Gfx *g40;
    P4Gfx *g41;
    P4Gfx *g42;

    if (D_800D15B4 == mode) {
        return 0;
    }
    D_800D15B4 = mode;
    switch (mode) {
    case 0:
        if (D_800D15C0) {
            g0 = D_80110634++;
            g0->words.w0 = 0xE200001C;
            g0->words.w1 = 0x0C1849D8;
        } else {
            g1 = D_80110634++;
            g1->words.w0 = 0xE200001C;
            g1->words.w1 = 0x0C184A50;
        }
        break;
    case 1:
        if (D_800D15C0) {
            g2 = D_80110634++;
            g2->words.w0 = 0xE200001C;
            g2->words.w1 = D_800D15DC | 0x1049D8;
        } else {
            g3 = D_80110634++;
            g3->words.w0 = 0xE200001C;
            g3->words.w1 = D_800D15DC | 0x104A50;
        }
        break;
    case 2:
        g4 = D_80110634++;
        g4->words.w0 = 0xE200001C;
        g4->words.w1 = 0x0C184A50;
        break;
    case 3:
        g5 = D_80110634++;
        g5->words.w0 = 0xE200001C;
        g5->words.w1 = 0x0C184B50;
        break;
    case 4:
        if (D_800D15C0) {
            g6 = D_80110634++;
            g6->words.w0 = 0xE200001C;
            g6->words.w1 = D_800D15DC | 0x104DD8;
        } else {
            g7 = D_80110634++;
            g7->words.w0 = 0xE200001C;
            g7->words.w1 = D_800D15DC | 0x104E50;
        }
        break;
    case 5:
        if (D_800D15C0) {
            g8 = D_80110634++;
            g8->words.w0 = 0xE200001C;
            g8->words.w1 = D_800D15DC | 0x1041F8;
        } else {
            g9 = D_80110634++;
            g9->words.w0 = 0xE200001C;
            g9->words.w1 = D_800D15DC | 0x1041F0;
        }
        break;
    case 6:
        if (D_800D15C0) {
            g10 = D_80110634++;
            g10->words.w0 = 0xE200001C;
            g10->words.w1 = D_800D15DC | 0x113078;
        } else {
            g11 = D_80110634++;
            g11->words.w0 = 0xE200001C;
            g11->words.w1 = D_800D15DC | 0x113078;
        }
        break;
    case 7:
        g12 = D_80110634++;
        g12->words.w0 = 0xE200001C;
        g12->words.w1 = D_800D15DC | 0x112E10;
        break;
    case 8:
        if (D_800D15C0) {
            g13 = D_80110634++;
            g13->words.w0 = 0xE200001C;
            g13->words.w1 = D_800D15DC | 0x112478;
        } else {
            g14 = D_80110634++;
            g14->words.w0 = 0xE200001C;
            g14->words.w1 = D_800D15DC | 0x112478;
        }
        break;
    case 9:
        g15 = D_80110634++;
        g15->words.w0 = 0xE200001C;
        g15->words.w1 = D_800D15DC | 0x112438;
        break;
    case 10:
        if (D_800D15C0) {
            g16 = D_80110634++;
            g16->words.w0 = 0xE200001C;
            g16->words.w1 = D_800D15DC | 0x112078;
        } else {
            g17 = D_80110634++;
            g17->words.w0 = 0xE200001C;
            g17->words.w1 = D_800D15DC | 0x112230;
        }
        break;
    case 11:
        g18 = D_80110634++;
        g18->words.w0 = 0xE200001C;
        g18->words.w1 = D_800D15DC | 0x112038;
        break;
    case 12:
        if (D_800D15C0) {
            g19 = D_80110634++;
            g19->words.w0 = 0xE200001C;
            g19->words.w1 = 0x005045D8;
        } else {
            g20 = D_80110634++;
            g20->words.w0 = 0xE200001C;
            g20->words.w1 = 0x004045D0;
        }
        break;
    case 13:
        g21 = D_80110634++;
        g21->words.w0 = 0xE200001C;
        g21->words.w1 = 0x00504B50;
        break;
    case 14:
        if (D_800D15C0) {
            g22 = D_80110634++;
            g22->words.w0 = 0xE200001C;
            g22->words.w1 = 0x005049D8;
        } else {
            g23 = D_80110634++;
            g23->words.w0 = 0xE200001C;
            g23->words.w1 = 0x00504A50;
        }
        break;
    case 15:
        g24 = D_80110634++;
        g24->words.w0 = 0xE200001C;
        g24->words.w1 = 0x00504E50;
        break;
    case 16:
        g25 = D_80110634++;
        g25->words.w0 = 0xE200001C;
        g25->words.w1 = 0x00504B53;
        break;
    case 17:
        if (D_800D15C0) {
            g26 = D_80110634++;
            g26->words.w0 = 0xE200001C;
            g26->words.w1 = 0x00553078;
        } else {
            g27 = D_80110634++;
            g27->words.w0 = 0xE200001C;
            g27->words.w1 = 0x00553078;
        }
        break;
    case 18:
        if (D_800D15C0) {
            g28 = D_80110634++;
            g28->words.w0 = 0xE200001C;
            g28->words.w1 = 0x00553048;
        } else {
            g29 = D_80110634++;
            g29->words.w0 = 0xE200001C;
            g29->words.w1 = 0x0F0A7008;
        }
        break;
    case 19:
        g30 = D_80110634++;
        g30->words.w0 = 0xE200001C;
        g30->words.w1 = 0x00504340;
        break;
    case 20:
        g31 = D_80110634++;
        g31->words.w0 = 0xE200001C;
        g31->words.w1 = 0;
        break;
    case 21:
        g32 = D_80110634++;
        g32->words.w0 = 0xE200001C;
        g32->words.w1 = 0x00504240;
        break;
    case 22:
        g33 = D_80110634++;
        g33->words.w0 = 0xE200001C;
        g33->words.w1 = 0x0FA54040;
        break;
    case 23:
        g34 = D_80110634++;
        g34->words.w0 = 0xE200001C;
        g34->words.w1 = D_800D15DC | 0x104B50;
        break;
    case 24:
        g35 = D_80110634++;
        g35->words.w0 = 0xE200001C;
        g35->words.w1 = D_800D15DC | 0x104E50;
        break;
    case 25:
        g36 = D_80110634++;
        g36->words.w0 = 0xE200001C;
        g36->words.w1 = 0x0C184240;
        break;
    case 26:
        g37 = D_80110634++;
        g37->words.w0 = 0xE200001C;
        g37->words.w1 = 0x0C184340;
        break;
    case 27:
        g38 = D_80110634++;
        g38->words.w0 = 0xE200001C;
        g38->words.w1 = 0x0F0A4000;
        break;
    case 28:
        if (D_800D15C0) {
            g39 = D_80110634++;
            g39->words.w0 = 0xE200001C;
            g39->words.w1 = 0x00507048;
        } else {
            g40 = D_80110634++;
            g40->words.w0 = 0xE200001C;
            g40->words.w1 = 0x00507040;
        }
        break;
    case 29:
        g41 = D_80110634++;
        g41->words.w0 = 0xE200001C;
        g41->words.w1 = D_800D15DC | 0x104F50;
        break;
    case 30:
        g42 = D_80110634++;
        g42->words.w0 = 0xE200001C;
        g42->words.w1 = D_800D15D8 | 0x104F50;
        break;
    }
    return 1;
}
