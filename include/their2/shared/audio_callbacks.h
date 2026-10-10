/* Open declarations of audio-driver callback contracts, MIT.
 * These signatures describe callers of the reconstructed Acmd builders;
 * no driver structure definitions or Nintendo SDK header text are included. */
#ifndef UNBAKE_SHARED_AUDIO_CALLBACKS_H
#define UNBAKE_SHARED_AUDIO_CALLBACKS_H
#include "acmd.h"
typedef Acmd *(*ALCmdHandler)(void *, short *, int, int, Acmd *);
typedef int (*ALDMAproc)(int addr, int len, void *state);
typedef int (*ALVoiceHandler)(void *);
typedef int (*ALSetParam)(void *, int, void *);
#endif
