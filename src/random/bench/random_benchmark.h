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

#ifndef __LIQUID_RANDOM_BENCHMARK_H__
#define __LIQUID_RANDOM_BENCHMARK_H__

#include <sys/resource.h>
#include "liquid.h"

// 
// BENCHMARK: uniform
//
void benchmark_random_uniform(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations)
{
    float x;
    unsigned long int i;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        x = randf();
        x = randf();
        x = randf();
        x = randf();
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;
}

// 
// BENCHMARK: normal
//
void benchmark_random_normal(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations)
{
    float x;
    unsigned long int i;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        x = randnf();
        x = randnf();
        x = randnf();
        x = randnf();
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;
}

// 
// BENCHMARK: complex normal
//
void benchmark_random_complex_normal(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations)
{
    float complex x;
    unsigned long int i;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        crandnf(&x);
        crandnf(&x);
        crandnf(&x);
        crandnf(&x);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;
}

// 
// BENCHMARK: Weibull
//
void benchmark_random_weibull(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations)
{
    float x, alpha=1.0f, beta=2.0f, gamma=6.0f;
    unsigned long int i;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        x = rand_weibullf(alpha,beta,gamma);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;
}

// 
// BENCHMARK: Rice-K
//
void benchmark_random_ricek(
    struct rusage *_start,
    struct rusage *_finish,
    unsigned long int *_num_iterations)
{
    float x, K=2.0f, omega=1.0f;
    unsigned long int i;

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        x = rand_ricekf(K,omega);
        x = rand_ricekf(K,omega);
        x = rand_ricekf(K,omega);
        x = rand_ricekf(K,omega);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;
}


#endif // __LIQUID_RANDOM_BENCHMARK_H__

