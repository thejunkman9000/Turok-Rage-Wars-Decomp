#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_802BE0D0.h"
#include "types.h"
/* Runs a music player's state machine on its channel: a start request loads the song's header and sequence from the song bank, records its tempo scale and volume, sets the sequence, clears the player queue, starts the sequence through func_802C00B0_de, then sets the channel's sample rate from the sequence rate over 22050, its tempo, priority, channel volume, master volume and plays it; a playing song that has ended is stopped and returns to idle or to the start state when it loops, and a stop request stops the sequencer. The state is unsigned with an empty case 0, and the rate and tempo factors are literals so the resident rodata keeps its order. */











extern Queue_func_8025CC90_de D_80108064[];
extern func_80203E78_S1 *D_800D0D78;

extern void func_80258740_de(Bank *);
extern void func_802587A4_de(Bank *);
extern char *func_80258D40_de(Bank *);
extern void *func_8028FDB4_de(void *, s32);
extern void func_802C020C_de(void);

extern s32 func_802C00B0_de(void *, s32, s32 *);
extern void func_802B2F00_de(char *, s32);
extern s32 func_802B2620_de(char *);
extern void func_802B2E80_de(char *, f32);
extern void func_802B2F10_de(char *, s32);
extern void func_802B2E30_de(char *, s32);
extern void func_802B2ED0_de(char *, s32, s32);
extern void func_802B2DE0_de(char *, s32);
extern void func_802B2D80_de(char *);

void func_8025CC90_de(Player_func_8025CC90_de *player) {
    s32 rate;
    char *channel;
    s32 index;
    SongHeader *header;
    void *sequence;

    func_80258740_de(player->bank);
    channel = func_80258D40_de(player->bank);
    switch (player->state) {
        case 0:
            break;
        case 3:
            func_802C020C_de();
            break;
        case 2:
            func_802B2F00_de(channel, player->id);
            if (func_802B2620_de(channel) == 0) {
                func_802C021C_de();
                if (player->loop >= 0) {
                    player->state = 1;
                } else {
                    player->state = 0;
                }
            }
            break;
        case 1:
            ((s32 *)D_80108064)[0] = 0;
            ((u8 *)D_80108064)[4] = 2;
            ((s32 *)D_80108064)[2] = 0;
            index = player->song * 2;
            header = func_8028FDB4_de(player->bank->songs, index);
            player->tempoScale = header->tempo * 0.01f;
            player->volume = header->volume;
            sequence = func_8028FDB4_de(player->bank->songs, index | 1);
            ((void **)D_80108064)[-1] = sequence;
            D_800D0D78->unk4 = func_802C00B0_de(sequence, 0x5622, &rate);
            player->state = 3;
            func_802B2F00_de(channel, player->id);
            func_802B2E80_de(channel, rate * 4.5351473e-05f);
            func_802B2F10_de(channel, (s16)(player->speed * player->tempoScale));
            func_802B2E30_de(channel, player->priority);
            func_802B2ED0_de(channel, player->id, 0x7F);
            func_802B2DE0_de(channel, (u8)(u32)player->volume);
            func_802B2D80_de(channel);
            player->loop = -1;
            break;
    }
    func_802587A4_de(player->bank);
}
