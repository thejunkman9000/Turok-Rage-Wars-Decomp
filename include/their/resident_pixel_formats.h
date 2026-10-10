#ifndef RESIDENT_PIXEL_FORMATS_H
#define RESIDENT_PIXEL_FORMATS_H

/* The native format descriptor is thirteen32-bit words. Signed shifts
 * describe channel movement when converting to or from0xAARRGGBB. */
typedef struct ResidentPixelFormat {
    int format_id;
    int indexed;
    int pixel_bits;
    int stored_color_bits;
    int meaningful_color_bits;
    unsigned int mask[4];
    int shift[4];
} ResidentPixelFormat;

#endif
