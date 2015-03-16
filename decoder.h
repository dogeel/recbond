/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _DECODER_H_
#define _DECODER_H_

#include <stdint.h>
#include "config.h"

#ifdef HAVE_LIBARIB25

#include <arib25/arib_std_b25.h>
#include <arib25/b_cas_card.h>

typedef struct _decoder {
    ARIB_STD_B25 *b25;
    B_CAS_CARD *bcas;
} DECODER;

typedef struct _decoder_options {
    int round;
    int strip;
    int emm;
} decoder_options;

#else

typedef struct {
    uint8_t *data;
    int32_t  size;
} ARIB_STD_B25_BUFFER;

typedef struct _decoder {
    void *dummy;
} DECODER;

typedef struct _decoder_options {
    int round;
    int strip;
    int emm;
} decoder_options;

#endif

/* prototypes */
DECODER *b25_startup(decoder_options *opt);
int b25_shutdown(DECODER *dec);
int b25_decode(DECODER *dec,
               ARIB_STD_B25_BUFFER *sbuf,
               ARIB_STD_B25_BUFFER *dbuf);
int b25_finish(DECODER *dec,
               ARIB_STD_B25_BUFFER *sbuf,
               ARIB_STD_B25_BUFFER *dbuf);


#endif
