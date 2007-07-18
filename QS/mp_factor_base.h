/******************************************************************************

 mp_factor_base.h
 Header file for factor_base.c.

 (C) 2006 William Hart

******************************************************************************/

#ifndef MP_FACTORBASE_H
#define MP_FACTORBASE_H

#include <gmp.h>

#include "mpQS.h"
#include "common.h"

#define KSMAX 100

static const unsigned long prime_tab[][2] =
{
   {32, 30},
   {40, 50},
   {50, 80},
   {60, 100},
   {70, 150},
   {80, 200},
   {90, 200},
   {100, 250},
   {110, 300},
   {120, 500},
   {130, 550}, // 37 digits
   {140, 800}, // 40 digits
   {150, 1000},
   {160, 2000}, 
   {170, 2200}, // 50 digits 
   {180, 2400},
   {190, 2700}, 
   {200, 3000} // 60 digits
};

#define PTABSIZE (sizeof(prime_tab)/(2*sizeof(unsigned long)))

unsigned long num_FB_primes(unsigned long bits);

void sqrts_init(QS_t * qs_inf);

void sqrts_clear(void);

void compute_sizes(QS_t * qs_inf);

void sizes_clear(void);

//Knuth-Schroeppel multipliers and a macro to count them

static const unsigned long multipliers[] = {1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 
                                            15, 17, 19, 21, 22, 23, 26, 29, 
                                            30, 31, 33, 34, 35, 37, 38, 41, 
                                            42, 43, 47};

#define NUMMULTS (sizeof(multipliers)/sizeof(unsigned long))
#define max_mult_size 6 // number of bits of maximum multiplier

void primes_clear(void);

void primes_init(QS_t * qs_inf);

unsigned long knuth_schroeppel(QS_t * qs_inf);

unsigned long compute_factor_base(QS_t * qs_inf);

#endif
