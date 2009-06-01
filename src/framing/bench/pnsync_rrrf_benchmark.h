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

#ifndef __LIQUID_PNSYNC_RRRF_BENCH_H__
#define __LIQUID_PNSYNC_RRRF_BENCH_H__

#include <sys/resource.h>
#include "liquid.h"

#define PNSYNC_RRRF_BENCH_API(N)        \
(   struct rusage *_start,              \
    struct rusage *_finish,             \
    unsigned long int *_num_iterations) \
{ pnsync_rrrf_bench(_start, _finish, _num_iterations, N); }

// Helper function to keep code base small
void pnsync_rrrf_bench(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations,
    unsigned int _n)
{
    // initialize modulator
    float h[_n];
    unsigned long int i;
    for (i=0; i<_n; i++)
        h[_n] = (i%2) ? 1.0f : -1.0f;
    pnsync_rrrf fs = pnsync_rrrf_create(_n,h);
    float rxy;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        pnsync_rrrf_correlate(fs,1.0f,&rxy);
        pnsync_rrrf_correlate(fs,1.0f,&rxy);
        pnsync_rrrf_correlate(fs,1.0f,&rxy);
        pnsync_rrrf_correlate(fs,1.0f,&rxy);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;

    pnsync_rrrf_destroy(fs);
}

// specific modems
void benchmark_pnsync_rrrf_16   PNSYNC_RRRF_BENCH_API(16)
void benchmark_pnsync_rrrf_32   PNSYNC_RRRF_BENCH_API(32)
void benchmark_pnsync_rrrf_64   PNSYNC_RRRF_BENCH_API(64)
void benchmark_pnsync_rrrf_128  PNSYNC_RRRF_BENCH_API(128)

#endif // __LIQUID_PNSYNC_RRRF_BENCH_H__

