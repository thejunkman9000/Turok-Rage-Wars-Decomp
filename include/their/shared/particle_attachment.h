#ifndef RW_PARTICLE_ATTACHMENT_H
#define RW_PARTICLE_ATTACHMENT_H
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027A0F4.h"
/* Attachment view of the existing collision state: ROM pointer at0,
 * draw-frame selector at0x14; the scene vector begins at0x08. */
typedef struct ParticleAttachmentState {
    Shared_ParticleTarget *current;
    char reserved[0x10];
    s32 frame;
} ParticleAttachmentState;
#endif
