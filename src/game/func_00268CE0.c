#include "b15_types.h"
#include "p4_types.h"

extern u32 D_800D15B0;
extern P4Gfx *D_80110634;

/* sets the RDP combine mode: emits one G_SETCOMBINE command for the requested mode */
void func_00268CE0(u32 mode) {
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

    if (D_800D15B0 == mode) {
        return;
    }
    D_800D15B0 = mode;
    switch (mode) {
    case 0:
        g0 = D_80110634++;
        g0->words.w0 = 0xFC30C3FF;
        g0->words.w1 = 0x5FFEFE38;
        break;
    case 1:
        g1 = D_80110634++;
        g1->words.w0 = 0xFC30C3FF;
        g1->words.w1 = 0x5F16FE3F;
        break;
    case 2:
        g2 = D_80110634++;
        g2->words.w0 = 0xFC3097FF;
        g2->words.w1 = 0x5FFEFE38;
        break;
    case 3:
        g3 = D_80110634++;
        g3->words.w0 = 0xFC30C204;
        g3->words.w1 = 0x5FFEFFF8;
        break;
    case 4:
        g4 = D_80110634++;
        g4->words.w0 = 0xFC309604;
        g4->words.w1 = 0x5FFEFFF8;
        break;
    case 5:
        g5 = D_80110634++;
        g5->words.w0 = 0xFC26A1FF;
        g5->words.w1 = 0x1FFC923C;
        break;
    case 6:
        g6 = D_80110634++;
        g6->words.w0 = 0xFCFF97FF;
        g6->words.w1 = 0xFFFCFE38;
        break;
    case 7:
        g7 = D_80110634++;
        g7->words.w0 = 0xFCFF97FF;
        g7->words.w1 = 0xFF14FE3F;
        break;
    case 8:
        g8 = D_80110634++;
        g8->words.w0 = 0xFCFF96AC;
        g8->words.w1 = 0xF0FCFE38;
        break;
    case 9:
        g9 = D_80110634++;
        g9->words.w0 = 0xFCFF96A4;
        g9->words.w1 = 0xF0FCFE38;
        break;
    case 10:
        g10 = D_80110634++;
        g10->words.w0 = 0xFCFF97FF;
        g10->words.w1 = 0xFF14FF7F;
        break;
    case 11:
        g11 = D_80110634++;
        g11->words.w0 = 0xFCFF96AC;
        g11->words.w1 = 0xF00CFE3F;
        break;
    case 12:
        g12 = D_80110634++;
        g12->words.w0 = 0xFC26A004;
        g12->words.w1 = 0x1FFC93FC;
        break;
    case 13:
        g13 = D_80110634++;
        g13->words.w0 = 0xFC1217FF;
        g13->words.w1 = 0xFFFFFE38;
        break;
    case 14:
        g14 = D_80110634++;
        g14->words.w0 = 0xFC1217FF;
        g14->words.w1 = 0xFF17FE3F;
        break;
    case 15:
        g15 = D_80110634++;
        g15->words.w0 = 0xFC1216AC;
        g15->words.w1 = 0xF0FFFE38;
        break;
    case 16:
        g16 = D_80110634++;
        g16->words.w0 = 0xFC1217FF;
        g16->words.w1 = 0xFF17FF7F;
        break;
    case 17:
        g17 = D_80110634++;
        g17->words.w0 = 0xFC1216AC;
        g17->words.w1 = 0xF00FFE3F;
        break;
    case 18:
        g18 = D_80110634++;
        g18->words.w0 = 0xFCFFFFFF;
        g18->words.w1 = 0xFFFDF638;
        break;
    case 19:
        g19 = D_80110634++;
        g19->words.w0 = 0xFC327FFF;
        g19->words.w1 = 0xFFFFF638;
        break;
    case 20:
        g20 = D_80110634++;
        g20->words.w0 = 0xFC327FFF;
        g20->words.w1 = 0xFF17F63F;
        break;
    case 21:
        g21 = D_80110634++;
        g21->words.w0 = 0xFC327EAC;
        g21->words.w1 = 0xF0FFF638;
        break;
    case 22:
        g22 = D_80110634++;
        g22->words.w0 = 0xFCFFFEA4;
        g22->words.w1 = 0xF0FDF638;
        break;
    case 23:
        g23 = D_80110634++;
        g23->words.w0 = 0xFC327FFF;
        g23->words.w1 = 0xFF17F77F;
        break;
    case 24:
        g24 = D_80110634++;
        g24->words.w0 = 0xFCFF97FF;
        g24->words.w1 = 0xFF2CFE7F;
        break;
    case 25:
        g25 = D_80110634++;
        g25->words.w0 = 0xFCFFFFFF;
        g25->words.w1 = 0xFFFDF6FB;
        break;
    case 26:
        g26 = D_80110634++;
        g26->words.w0 = 0xFC511BFF;
        g26->words.w1 = 0x3FFDFE38;
        break;
    case 27:
        g27 = D_80110634++;
        g27->words.w0 = 0xFC12ABFF;
        g27->words.w1 = 0xFFFFFE38;
        break;
    case 28:
        g28 = D_80110634++;
        g28->words.w0 = 0xFCFFFFFF;
        g28->words.w1 = 0xFFFE793C;
        break;
    case 29:
        g29 = D_80110634++;
        g29->words.w0 = 0xFC309661;
        g29->words.w1 = 0x552EFF7F;
        break;
    case 30:
        g30 = D_80110634++;
        g30->words.w0 = 0xFCFFFFFF;
        g30->words.w1 = 0xFFFDFCFE;
    case 31:
        g31 = D_80110634++;
        g31->words.w0 = 0xFCFFFFFF;
        g31->words.w1 = 0xFFFEFD7E;
        break;
    case 32:
        g32 = D_80110634++;
        g32->words.w0 = 0xFC50C2A1;
        g32->words.w1 = 0x44867F3F;
        break;
    case 33:
        g33 = D_80110634++;
        g33->words.w0 = 0xFC127E24;
        g33->words.w1 = 0xFFFFF9FC;
        break;
    case 34:
        g34 = D_80110634++;
        g34->words.w0 = 0xFCFF97FF;
        g34->words.w1 = 0xFFFFFE38;
        break;
    case 35:
        g35 = D_80110634++;
        g35->words.w0 = 0xFC26FE60;
        g35->words.w1 = 0x15FCF778;
        break;
    case 36:
        g36 = D_80110634++;
        g36->words.w0 = 0xFC322007;
        g36->words.w1 = 0xF5FF937B;
        break;
    case 37:
        g37 = D_80110634++;
        g37->words.w0 = 0xFC522067;
        g37->words.w1 = 0xF0FF923B;
        break;
    case 38:
        g38 = D_80110634++;
        g38->words.w0 = 0xFCFF97FF;
        g38->words.w1 = 0xFFFF7E38;
        break;
    case 39:
        g39 = D_80110634++;
        g39->words.w0 = 0xFCFF99FF;
        g39->words.w1 = 0xFFFF7E38;
        break;
    case 40:
        g40 = D_80110634++;
        g40->words.w0 = 0xFC121824;
        g40->words.w1 = 0xFF33FFFF;
        break;
    case 41:
        g41 = D_80110634++;
        g41->words.w0 = 0xFC30C261;
        g41->words.w1 = 0x5586FF7F;
        break;
    }
}
