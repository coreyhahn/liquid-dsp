/*
 * Copyright (c) 2007, 2009 Joseph Gaeddert
 * Copyright (c) 2007, 2009 Virginia Polytechnic Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// Finite impulse response filter
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "channel_internal.h"

ricek_channel ricek_channel_create(unsigned int _h_len, float _K, float _fd, float _theta)
{
    ricek_channel q = (ricek_channel) malloc(sizeof(struct ricek_channel_s));

    if (_K < 0) {
        printf("error: ricek_channel_create(), K (%f) is negative\n", _K);
        exit(0);
    } else if (_fd < 0) {
        printf("error: ricek_channel_create()< fd (%f) is negative\n", _fd);
        exit(0);
    } else {
        q->K = _K;
        q->fd = _fd;
    }

    q->theta = _theta;

    q->omega = 1.0f;
    q->s = sqrtf((q->omega)*(q->K)/(q->K+1));
    q->sig = sqrtf(0.5f*(q->omega)/(q->K+1));

    q->h_len = _h_len;
    q->h_len = (q->h_len < 5) ? 5 : q->h_len;
    //q->h_len += (q->h_len) % 2 ? 1 : 0;

    // create filter
    float h[q->h_len];
    fir_design_doppler(q->h_len, q->fd, q->K, q->theta, h);

    // normalize filter
    unsigned int i;
    float t=0.0f;
    for (i=0; i<q->h_len; i++)
        t += h[i]*h[i];
    t = sqrtf(t);
    for (i=0; i<q->h_len; i++)
        h[i] /= t;

    // copy to complex array
    float complex hc[q->h_len];
    for (i=0; i<q->h_len; i++)
        hc[i] = h[i];

    // create filter
    q->f = fir_filter_cccf_create(hc, q->h_len);

    // load with complex values
    for (i=0; i<q->h_len; i++)
        fir_filter_cccf_push(q->f, icrandnf());

    return q;
}

void ricek_channel_destroy(ricek_channel _q)
{
    fir_filter_cccf_destroy(_q->f);
    free(_q);
}

void ricek_channel_print(ricek_channel _q)
{
    printf("Rice-K channel:\n");
}

void ricek_channel_execute(ricek_channel _q, float complex _x, float complex *_y)
{
    float complex r, z;

    // advance fading filter
    fir_filter_cccf_push(_q->f, icrandnf());
    fir_filter_cccf_execute(_q->f, &r);

    // generate complex fading envelope
    z = ( crealf(r)*(_q->sig) + _q->s ) +
        ( cimagf(r)*(_q->sig)         ) * _Complex_I;

    // set return value
    *_y = _x * z;
}

