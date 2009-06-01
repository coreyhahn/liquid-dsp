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
// Numerically-controlled oscillator
//

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "liquid.internal.h"

nco nco_create()
{
    nco p = (nco) malloc(sizeof(struct nco_s));
    nco_init(p);
    return p;
}

void nco_destroy(nco _nco)
{
    free(_nco);
}

void nco_init(nco _nco)
{
    _nco->theta = 0.0f;
    _nco->d_theta = 0.0f;
}

void nco_set_phase(nco _nco, float _phi)
{
    _nco->theta = _phi;
    nco_constrain_phase(_nco);
}

void nco_adjust_phase(nco _nco, float _dphi)
{
    _nco->theta += _dphi;
    nco_constrain_phase(_nco);
}

void nco_step(nco _nco)
{
    _nco->theta += _nco->d_theta;
    nco_constrain_phase(_nco);
}

void nco_constrain_phase(nco _nco)
{
    if (_nco->theta > M_PI)
        _nco->theta -= 2.0f*M_PI;
    else if (_nco->theta < -M_PI)
        _nco->theta += 2.0f*M_PI;
}

float nco_sin(nco _nco) {return sinf(_nco->theta);}
float nco_cos(nco _nco) {return cosf(_nco->theta);}

void nco_sincos(nco _nco, float* _s, float* _c)
{
    *_s = sinf(_nco->theta);
    *_c = cosf(_nco->theta);
}

void nco_cexpf(nco _nco, float complex * _y)
{
    *_y = cexpf(_Complex_I*(_nco->theta));
}

// mixing functions

// Rotate input vector up by NCO angle, \f$\vec{y} = \vec{x}e^{j\theta}\f$
void nco_mix_up(nco _nco, complex float _x, complex float *_y)
{
    *_y = _x * cexpf(_Complex_I*(_nco->theta));
}

// Rotate input vector down by NCO angle, \f$\vec{y} = \vec{x}e^{-j\theta}\f$
void nco_mix_down(nco _nco, complex float _x, complex float *_y)
{
    *_y = _x * cexpf(-_Complex_I*(_nco->theta));
}


// Rotate input vector array up by NCO angle, \f$\vec{y} = \vec{x}e^{j\theta}\f$
void nco_mix_block_up(
    nco _nco,
    complex float *_x,
    complex float *_y,
    unsigned int _N)
{
    unsigned int i;

    float theta =   _nco->theta;
    float d_theta = _nco->theta;
    for (i=0; i<_N; i++) {
        //sigprocc_rotate(_xi[i], _xq[i], theta, &_yi[i], &_yq[i]);
        _y[i] = _x[i] * cexpf(I*theta);
        
        // nco_step(_nco);
        theta += d_theta;
    }

    // nco_constrain_phase(_nco);
    while (theta > M_PI)
        theta -= 2*M_PI;
    while (theta < -M_PI)
        theta += 2*M_PI;

    nco_set_phase(_nco, theta);
}

// Rotate input vector array up by NCO angle, \f$\vec{y} = \vec{x}e^{j\theta}\f$
void nco_mix_block_down(
    nco _nco,
    complex float *_x,
    complex float *_y,
    unsigned int _N)
{
    unsigned int i;

    float theta =   _nco->theta;
    float d_theta = _nco->theta;
    for (i=0; i<_N; i++) {
        //sigprocc_rotate(_xi[i], _xq[i], theta, &_yi[i], &_yq[i]);
        _y[i] = _x[i] * cexpf(-I*theta);
        
        // nco_step(_nco);
        theta += d_theta;
    }

    // nco_constrain_phase(_nco);
    while (theta > M_PI)
        theta -= 2*M_PI;
    while (theta < -M_PI)
        theta += 2*M_PI;

    nco_set_phase(_nco, theta);
}

