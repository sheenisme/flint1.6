/******************************************************************************

 flint.h
 Main header file for FLINT.

 (C) 2006 William Hart and David Harvey

******************************************************************************/

#include <limits.h>

#ifndef FLINT_H
#define FLINT_H


// todo: need to select which version based on some kind of debug compile flag?
#if 0
#define FLINT_ASSERT assert
#else
#define FLINT_ASSERT if
#endif



#define FLINT_MAX(zzz1, zzz2) ((zzz1) > (zzz2) ? (zzz1) : (zzz2))
#define FLINT_MIN(zzz1, zzz2) ((zzz1) > (zzz2) ? (zzz2) : (zzz1))



/*
 FLINT_BITS_PER_LIMB is the number of bits per limb.

 todo: shouldn't we be checking this is the same as GMP's limb size?
*/

#if ULONG_MAX == 4294967295U
#define FLINT_BITS_PER_LIMB 32
#define FLINT_BYTES_PER_LIMB 4
#define FLINT_LG_BYTES_PER_LIMB 2
#elif ULONG_MAX == 18446744073709551615U
#define FLINT_BITS_PER_LIMB 64
#define FLINT_BYTES_PER_LIMB 8
#define FLINT_LG_BYTES_PER_LIMB 3
#else
// only 32 and 64 bits are supported
#error FLINT requires that unsigned long is 32 bits or 64 bits
#endif

/* 
FLINT cache hints to speed up reads from data in memory
*/
#if defined(__GNUC__) && __GNUC__ >= 3
#define FLINT_PREFETCH(addr,n) __builtin_prefetch((unsigned long*)addr+n,0,1) 
#elif defined(_MSC_VER) && _MSC_VER >= 1400
#define FLINT_PREFETCH(addr,n) PreFetchCacheLine(PF_TEMPORAL_LEVEL_1, (unsigned long*)addr+n)
#else
#define FLINT_PREFETCH(addr,n) /* nothing */
#endif

/*
Cache size in bytes.

todo: determine this constant at build time

todo: we really need one of these for a hierarchy of caches. e.g. the
cache-friendly FFT code only really takes into account the L1 cache.

*/
#define FLINT_CACHE_SIZE 65536


/*
If this flag is set, we are strictly only using GMP's documented interface.

If not set, we sometimes use hacks to speed things up (for example accessing
the mpz_t::_mp_d member directly).
 */
#define FLINT_GMP_COMPLIANT 0


/*
Returns ceil(log2(x)).
If x == 0, returns 0.
*/
static inline unsigned long ceil_log2(unsigned long x)
{
   unsigned long result = 0;
   if (x)
   {
      x--;
      while (x)
      {
         x >>= 1;
         result++;
      }
   }
   return result;
}



#endif


// end of file ****************************************************************
