#ifndef RW_ATTACHMENT_EFFECT_ARGS_H
#define RW_ATTACHMENT_EFFECT_ARGS_H

#include "types.h"

/* Eight-byte attachment effect payload. The event dispatcher writes halfwords
 * at 0/2 and bytes at 4/5/6/7, then passes the two words by value. This is the
 * bounded call payload, distinct from the larger persistent EffectParams. */
typedef struct AttachmentEffectFields {
    s16 lifeBase;
    s16 lifeRange;
    s8 chance;
    s8 modifier;
    s8 countBase;
    s8 countRange;
} AttachmentEffectFields;

/* The same payload is transported as two O32 words; this standard C union
 * gives it the measured four-byte alignment without compiler attributes. */
typedef union AttachmentEffectArgs {
    AttachmentEffectFields fields;
    s32 words[2];
} AttachmentEffectArgs;

#endif
