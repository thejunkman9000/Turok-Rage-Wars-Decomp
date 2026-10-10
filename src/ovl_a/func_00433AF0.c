#include "span_16E000/code_8042F988.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "common/types_8fd754e1e915.h"
#include "gfx.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8044ACCC.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Initializes four player-menu slots and selects the first available child node. */

#if defined(VERSION_DE)
enum { PAK_SLOT_RESOURCE_688 = 716, PAK_SLOT_RESOURCE_689 = 713, PAK_SLOT_RESOURCE_690 = 714, PAK_SLOT_RESOURCE_691 = 715, PAK_SLOT_RESOURCE_692 = 712, PAK_SLOT_RESOURCE_694 = 718 };
#elif defined(VERSION_EU)
enum { PAK_SLOT_RESOURCE_688 = 688, PAK_SLOT_RESOURCE_689 = 689, PAK_SLOT_RESOURCE_690 = 690, PAK_SLOT_RESOURCE_691 = 691, PAK_SLOT_RESOURCE_692 = 692, PAK_SLOT_RESOURCE_694 = 694 };

extern void *D_800E1394[], *D_800DD124[];

#elif defined(VERSION_EU_X)
enum { PAK_SLOT_RESOURCE_688 = 764, PAK_SLOT_RESOURCE_689 = 761, PAK_SLOT_RESOURCE_690 = 762, PAK_SLOT_RESOURCE_691 = 760, PAK_SLOT_RESOURCE_692 = 763, PAK_SLOT_RESOURCE_694 = 766 };

extern void *D_800E1394[], *D_800DD124[];

#else
enum { PAK_SLOT_RESOURCE_688 = 688, PAK_SLOT_RESOURCE_689 = 689, PAK_SLOT_RESOURCE_690 = 690, PAK_SLOT_RESOURCE_691 = 691, PAK_SLOT_RESOURCE_692 = 692, PAK_SLOT_RESOURCE_694 = 694 };

#endif
extern PakMenuController *D_800E54A4;
extern void *D_800D3250[];
extern void func_8040E8D8_de(MenuWidget *,s32),func_8040E950_de(MenuWidget *,s32),func_8041B8DC_de(s32,s32,MenuWidget *);
extern MenuWidget *func_8040EC30_de(MenuWidget *,s32),*func_8041B7FC_de(s32,s32);
extern s32 func_8040EBD0_de(MenuWidget *),func_804358C0_de(s32,s8);
void func_80433914_de(s32 player) {
 s32 i;
 MenuWidget *label,*value;
 D_800E54A4->players[player].chosen=0;
 D_800E54A4->players[player].nodes[0]=func_8040EC30_de(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_694);
 D_800E54A4->players[player].nodes[1]=func_8040EC30_de(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_691);
 D_800E54A4->players[player].nodes[2]=func_8040EC30_de(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_688);
 D_800E54A4->players[player].nodes[3]=func_8040EC30_de(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_692);
 for(i=0;i<4;i++) {
  D_800E54A4->players[player].used[i]=2;
  D_800E54A4->players[player].nodes[i]->alpha=255;
  label=func_8040EC30_de(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689);
  func_8040E950_de(D_800E54A4->players[player].nodes[i],0);
  value=func_8040EC30_de(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_690);
  if(D_800E54A4->players[player].records[i].player!=-1) {
   value->text=D_800E54A4->players[player].records[i].name;
   D_800E54A4->players[player].used[i]=1;
   if(D_800E54A4->phase==1) {
    func_8040E8D8_de(func_8040EC30_de(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689),0);
    if(func_804358C0_de(D_800E54A4->players[player].profile,D_800E54A4->players[player].records[i].owner)!=-1) {
     D_800E54A4->players[player].used[i]=0;
     func_8040E950_de(D_800E54A4->players[player].nodes[i],1);
     func_8040E8D8_de(func_8040EC30_de(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689),1);
    }
   }
#if defined(VERSION_EU)
  } else {value->text=((D_800E1394)[D_80152789]);func_8040E8D8_de(label,0);}
#elif defined(VERSION_EU_X)
  } else {value->text=((D_800DD124)[D_80152789]);func_8040E8D8_de(label,0);}
#else
  } else {value->text=(D_800D3250[0]);func_8040E8D8_de(label,0);}
#endif
 }
 label=func_8041B7FC_de(D_800E54A4->root,player);
 while(func_8040EBD0_de(label))label=label->next;
 func_8041B8DC_de(D_800E54A4->root,player,label);
}
