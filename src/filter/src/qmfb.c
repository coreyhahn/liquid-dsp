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
// quadrature mirror filterbank (QMFB)
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// defined:
//  QMFB()          name-mangling macro
//  TO              output data type
//  TC              coefficient data type
//  TI              input data type
//  WINDOW()        window macro
//  DOTPROD()       dotprod macro
//  PRINTVAL()      print macro

struct QMFB(_s) {
    float * h;          // filter prototype
    unsigned int m;     // primitive filter length
    unsigned int h_len; // actual filter length: h_len = 4*m+1
    float beta;         // filter bandwidth/sidelobe suppression

    // lower branch (filter)
    TC * h1;
    WINDOW() w1;
    unsigned int h1_len;

    // upper branch (delay line)
    TI * w0;
    unsigned int w0_index;
};

QMFB() QMFB(_create)(unsigned int _m, float _slsl)
{
    QMFB() f = (QMFB()) malloc(sizeof(struct QMFB(_s)));

    // compute filter length
    // h_len = 2*(2*m) + 1
    f->m = _m;
    f->beta = -fabsf(_slsl);

    f->h_len = 4*(f->m) + 1;
    f->h = (float*) malloc((f->h_len)*sizeof(float));

    f->h1_len = 2*(f->m);
    f->h1 = (TC *) malloc((f->h1_len)*sizeof(TC));

    // design filter prototype
    fir_kaiser_window(f->h_len, 0.5f, f->beta, 0, f->h);

    // resample, reverse direction
    unsigned int i, j=0;
    for (i=1; i<f->h_len; i+=2)
        f->h1[j++] = f->h[f->h_len - i - 1];

    f->w1 = WINDOW(_create)(2*(f->m));
    WINDOW(_clear)(f->w1);

    f->w0 = (TI*)malloc((f->m)*sizeof(TI));
    for (i=0; i<f->m; i++)
        f->w0[i] = 0;
    f->w0_index = 0;

    return f;
}

QMFB() QMFB(_recreate)(QMFB() _f, unsigned int _h_len)
{
    // TODO implement this method
    printf("error: qmfb_xxxt_recreate(), method not supported yet\n");
    exit(1);
    return NULL;
}

void QMFB(_destroy)(QMFB() _f)
{
    WINDOW(_destroy)(_f->w1);
    free(_f->w0);
    free(_f->h);
    free(_f->h1);
    free(_f);
}

void QMFB(_print)(QMFB() _f)
{
    printf("quadrature mirror filterbank: [%u taps]\n", _f->h_len);
    unsigned int i;
    for (i=0; i<_f->h_len; i++) {
        printf("  h(%4u) = ", i+1);
        //PRINTVAL(_f->h[i]);
        printf("%8.4f", _f->h[i]);
        printf(";\n");
    }
    printf("---\n");
    for (i=0; i<_f->h1_len; i++) {
        printf("  h1(%4u) = ", i+1);
        //PRINTVAL(_f->h1[i]);
        printf("%8.4f", _f->h1[i]);
        printf(";\n");
    }
}

void QMFB(_clear)(QMFB() _f)
{
    WINDOW(_clear)(_f->w1);
    unsigned int i;
    for (i=0; i<_f->m; i++)
        _f->w0[i] = 0;
    _f->w0_index = 0;
}

#if 0
void QMFB(_decim_execute)(QMFB() _f, TI * _x, TO *_y)
{
    TI * r;
    TO y0, y1;

    // compute filter branch
    WINDOW(_push)(_f->w1, _x[0]);
    WINDOW(_read)(_f->w1, &r);
    // TODO yq = DOTPROD(_execute)(_f->dpq, r);
    DOTPROD(_run4)(_f->h1, r, _f->h1_len, &y1);

    // compute delay branch
    y0 = _f->w0[_f->w0_index];
    _f->w0[_f->w0_index] = _x[1];
    _f->w0_index = (_f->w0_index+1) % (_f->m);

    // set return value
    *_y = y0 + y1;
}

void QMFB(_interp_execute)(QMFB() _f, TI _x, TO *_y)
{
    TI * r;  // read pointer

    // TODO macro for crealf, cimagf?
    
    // compute first branch (delay)
    _y[0] = _f->w0[_f->w0_index];
    _f->w0[_f->w0_index] = _x;
    _f->w0_index = (_f->w0_index+1) % (_f->m);

    // compute second branch (filter)
    WINDOW(_push)(_f->w1, _x);
    WINDOW(_read)(_f->w1, &r);
    //yq = DOTPROD(_execute)(_f->dpq, r);
    DOTPROD(_run4)(_f->h1, r, _f->h1_len, &_y[1]);

}
#endif

void QMFB(_analysis_execute)(QMFB() _q,
                             TI   _x0,
                             TI   _x1,
                             TO * _y0,
                             TO * _y1)
{
    TI * r; // read pointer
    TO z0, z1;

    // compute lower branch (filter component)
    WINDOW(_push)(_q->w1, _x0);
    WINDOW(_read)(_q->w1, &r);
    // TODO yq = DOTPROD(_execute)(_f->dpq, r);
    //DOTPROD(_run)(_q->h1, r, _q->h1_len, _y1);
    DOTPROD(_run)(_q->h1, r, _q->h1_len, &z1);

    // compute upper branch (delay component)
    z0 = _q->w0[_q->w0_index];
    _q->w0[_q->w0_index] = _x1;
    _q->w0_index = (_q->w0_index+1) % (_q->m);

    *_y0 = z0 + z1;
    *_y1 = z0 - z1;
}

void QMFB(_synthesis_execute)(QMFB() _q,
                              TI   _x0,
                              TI   _x1,
                              TO * _y0,
                              TO * _y1)
{
    TI * r; // read pointer

    // NOTE: ifft([_x0 _x1]) = [(_x0+_x1)/2 (_x0-_x1)/2]
    
    // compute upper branch (delay component)
    *_y0 = _q->w0[_q->w0_index];
    _q->w0[_q->w0_index] = (_x0 + _x1)/2;
    _q->w0_index = (_q->w0_index+1) % (_q->m);

    // compute lower branch (filter component)
    WINDOW(_push)(_q->w1, (_x0 - _x1)/2);
    WINDOW(_read)(_q->w1, &r);
    //yq = DOTPROD(_execute)(_f->dpq, r);
    //DOTPROD(_run)(_q->h1, r, _q->h1_len, _y1);
    DOTPROD(_run)(_q->h1, r, _q->h1_len, _y1);
}

