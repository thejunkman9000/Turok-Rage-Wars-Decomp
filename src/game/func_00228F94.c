#include "span_1000/code_80225D10.h"
#include "abi.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80225D10.h"
#include "span_1000/code_802A0888.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"

/* Draws an actor's player model with its status tint: sets the other-mode lighting command and render
   mode 2, gives the model the team colour byte (the match rule D_801468A0's colour at 0x73 when team
   colours apply to the player, else the model's own at 0xE), and by the player's tint mode at 0x1238
   sets a colour override (flag D_800D15E0, colour D_800D15E4) that fades with the tint time at 0x1230:
   mode 0 draws through func_8024A3B0_de in yellow fading from full alpha and then draws the second pass
   through func_8026CBA4_de with 255 less twice that alpha, mode 1 draws only the second pass in fading
   yellow starting at alpha 128, and mode 3 draws through func_8024A3B0_de with an alpha rising with the
   time; the override is switched off afterwards. */
extern Gfx *D_80110634;
extern Rules_func_80228FB8_de D_801468A0[];
extern s32 D_800D15E0;
extern Vector4f D_800D15E4;
extern s32 D_800D297C;
extern void func_80268CE0_de(s32);
extern void func_8024A3B0_de(Actor_func_80228FB8_de *, Player_func_80228FB8_de *, s32, Draw *);
extern void func_8026CBA4_de(void *, Player_func_80228FB8_de *, s32, s32, char *, s32, s32);

void func_80228FB8_de(Actor_func_80228FB8_de *actor, s32 arg1, Draw *draw) {
    Player_func_80228FB8_de *player;
    Gfx *gfx;

    if (actor != 0) {
        player = actor->player;
        if (player != 0) {
            gDPSetRenderMode(D_80110634++, 0xC4404B50, 0);
            func_80268CE0_de(2);
            if (D_801468A0->teams != 0 && player->controls->unk8F != 0) {
                actor->colour = D_801468A0->colour;
            } else {
                actor->colour = actor->def->colour;
            }
            if (player->tintMode == 0) {
                Vector4f *colour;

                D_800D15E0 = 1;
                colour = &D_800D15E4;
                colour->x = ((255.0f - player->tintTime * 17.0f) < 0.0f ? 0.0f : (255.0f - player->tintTime * 17.0f));
                colour->y = ((255.0f - player->tintTime * 17.0f) < 0.0f ? 0.0f : (255.0f - player->tintTime * 17.0f));
                colour->z = 0.0f;
                colour->w = ((255.0f - player->tintTime * 8.533334f) < 0.0f ? 0.0f : (255.0f - player->tintTime * 8.533334f));
                func_8024A3B0_de(actor, player, arg1, draw);
                colour->w = ((255.0f - colour->w * 2.0f) < 0.0f ? 0.0f : (255.0f - colour->w * 2.0f));
                func_8026CBA4_de(draw->model, player, actor->animation, 1,
                              &actor->views[D_800D297C * 0x18], 0, -1);
            } else if (player->tintMode == 1) {
                Vector4f *colour;

                D_800D15E0 = 1;
                colour = &D_800D15E4;
                colour->x = ((255.0f - player->tintTime * 17.0f) < 0.0f ? 0.0f : (255.0f - player->tintTime * 17.0f));
                colour->y = ((255.0f - player->tintTime * 17.0f) < 0.0f ? 0.0f : (255.0f - player->tintTime * 17.0f));
                colour->z = 0.0f;
                colour->w = ((128.0f - player->tintTime * 8.533334f) < 0.0f ? 0.0f : (128.0f - player->tintTime * 8.533334f));
                func_8026CBA4_de(draw->model, player, actor->animation, 1,
                              &actor->views[D_800D297C * 0x18], 0, -1);
            } else if (player->tintMode == 3) {
                D_800D15E0 = 1;
                D_800D15E4.w = ((player->tintTime * 0.425f) < 0.0f ? 0.0f : (player->tintTime * 0.425f));
                func_8024A3B0_de(actor, player, arg1, draw);
            }
            D_800D15E0 = 0;
        }
    }
}

extern void func_8022B60C_de(void *arg0, f32 arg1, void *arg2);
extern void func_80216488_de(void *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);
extern void func_80219A40_de(void *arg0, void *arg1, void *arg2);
extern f32 D_800C2C40_de[2];

extern func_8020CA10_G1 D_800C2C48_de;

extern func_8020CA10_G1 D_800C2C4C_de;

extern func_8020CA10_G1 D_800D2988;
void func_802292B8_de(void *arg0) {
    Slot sp18;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f20;
    f32 zero;
    s32 var_s2;
    s32 var_s3;
    void *temp_a0;
    void *temp_s0;

    zero = 0.0f;
    temp_f21 = D_800C2C40_de[1];
    var_s3 = 0;
    var_s2 = 0x1248;
    do {
        temp_s0 = (char *)arg0 + var_s2;
        temp_f2 = ((ObjectLinks18_3 *)(temp_s0))->unk_4;
        if (temp_f2 > zero) {
            temp_f1 = D_800D2988.unk0;
            var_f20 = *(f32 *)temp_s0 * temp_f1;
            temp_f1 = temp_f2 - temp_f1;
            var_f20 *= temp_f21;
            ((ObjectLinks18_3 *)(temp_s0))->unk_4 = temp_f1;
            temp_f1 = ((ObjectLinks18_3 *)(temp_s0))->unk_10 + (f32)(s32)var_f20;
            ((ObjectLinks18_3 *)(temp_s0))->unk_10 = temp_f1;
            if (((ObjectLinks18_3 *)(temp_s0))->unk_4 <= zero) {
                temp_f0 = ((ObjectLinks18_3 *)(temp_s0))->unk_C * temp_f21;
                if (temp_f1 < temp_f0) {
                    var_f20 += temp_f0 - temp_f1;
                }
            }
            temp_a0 = ((ObjectLinks18_3 *)(temp_s0))->unk_8;
            if (temp_a0 != 0 && *(u8 *)temp_a0 == 1 &&
                (((IntegerState1230 *)(temp_a0))->unk_100 & 0x300000) &&
                (((IntegerState1230 *)(temp_a0))->unk_122C & 0x200)) {
                var_f20 *= D_800C2C48_de.unk0;
            }
            if (((ObjectLinks18_3 *)(temp_s0))->unk_14 != 0) {
                func_8022B60C_de(arg0, 0.0933333337f, ((ObjectLinks18_3 *)(temp_s0))->unk_8);
                if ((f32)((ObjectState5E8 *)(arg0))->unk_5E4 <= var_f20) {
                    var_f20 = D_800C2C4C_de.unk0;
                }
            }
            func_80216488_de((void *)&sp18, (s32)((ObjectLinks18_3 *)(temp_s0))->unk_8,
                          (s32)var_f20, 25.599998f, 0x100080, 0);
            func_80219A40_de(arg0, &((ObjectState5E8 *)(arg0))->unk_170, (void *)&sp18);
        }
        var_s3++;
        var_s2 += 0x18;
    } while (var_s3 < 5);
}

/* Transfers a randomly selected inventory quantity into an empty recipient slot. */

s32 func_802744D4_de(); /* extern */

void func_80229468_de(Inventory *arg0, Receiver *arg1) {
 s32 amount;
 s32 index;
 s32 value;
 void *scan;
 if (arg1->amount == 0) {
  amount=15;
  index=func_802744D4_de()%3;
  value=arg0->items[index];
  if(value<16) amount=value;
  if(amount==0) {
   func_802744D4_de();
   scan=arg0;
   for(index=0;index<3;index++) {
    s16 item=arg0->items[index];
    if(item>0) { s32 v=item; if(amount<v) v=amount; amount=v; }
   }
   index=2;
  }
  if(amount!=0) {
   arg0->items[index]-=amount;
   arg1->index=index;
   arg1->amount=amount;
  }
 }
}

/* Gives a player an amount of one ammunition type and announces it: the count at 0x5F4 of that type
   rises by the amount up to the type's maximum (none for type -1, the character's table at 0x108 in
   multiplayer, otherwise D_800CE3E8 plus the profile's bonus bytes in D_80102B00 unless ammunition is
   unlimited at 0x1450), and the message "<amount> <type name>" with a plural suffix for more than one
   is built and shown through func_8022B75C_de. */
extern s32 D_800CE3E8[];
extern Profile_func_80229554_de D_80102B00[];
extern u8 D_801462D5;
extern char D_800C2C50_de[];
extern char D_800C2C54_de[];

extern void func_802A025C_de(char *, char *);
extern void func_802A02E8_de(char *, char *);
extern char *func_80232764_de(s32);
extern void func_8022B75C_de(SharedPlayer_func_80229554_de *, char *, f32);

static inline s32 max_ammo(SharedPlayer_func_80229554_de *player, s32 type) {
    s32 max;

    if (type == -1) {
        return 0;
    }
    if (D_801462D5 != 1) {
        max = player->views18.view18_4.character->caps[type];
    } else {
        max = D_800CE3E8[type];
        if (player->views1450.view1450_3.unlimited == 0) {
            if (type == 0) {
                max += D_80102B00[player->views1C.view5D4_47.profile].bonus0;
            } else if (type == 1) {
                max += D_80102B00[player->views1C.view5D4_47.profile].bonus1;
            } else if (type == 2) {
                max += D_80102B00[player->views1C.view5D4_47.profile].bonus2;
            }
        }
    }
    return max;
}

void func_80229554_de(SharedPlayer_func_80229554_de *player, s32 type, s32 amount) {
    char number[8];
    char message[32];

    if (amount != 0) {
        player->views5E8.view5F4_12.ammo[type] = ((player->views5E8.view5F4_12.ammo[type] + amount) < (max_ammo(player, type)) ? (player->views5E8.view5F4_12.ammo[type] + amount) : (max_ammo(player, type)));
        func_802A066C_de(amount, number);
        func_802A025C_de(message, number);
        func_802A02E8_de(message, D_800C2C50_de);
        func_802A02E8_de(message, func_80232764_de(type));
        if (amount >= 2) {
            func_802A02E8_de(message, D_800C2C54_de);
        }
        func_8022B75C_de(player, message, 1.0f);
    }
}
