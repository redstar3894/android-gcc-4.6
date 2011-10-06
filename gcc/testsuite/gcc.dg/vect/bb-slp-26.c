/* { dg-require-effective-target vect_int } */

#include <stdarg.h>
#include "tree-vect.h"

#define A 3
#define B 4
#define N 256

char src[N], dst[N];

void foo (char * __restrict__ dst, char * __restrict__ src, int h,
          int stride, int dummy)
{
  int i;
  h /= 16;
  for (i = 0; i < h; i++)
    {
      dst[0] += A*src[0];
      dst[1] += A*src[1];
      dst[2] += A*src[2];
      dst[3] += A*src[3];
      dst[4] += A*src[4];
      dst[5] += A*src[5];
      dst[6] += A*src[6];
      dst[7] += A*src[7];
      dst += 8;
      src += 8;
      if (dummy == 32)
        abort ();
   }
}


int main (void)
{
  int i;

  check_vect ();

  for (i = 0; i < N; i++)
    {
       dst[i] = 0;
       src[i] = i/8;
    }

  foo (dst, src, N, 8, 0);

  for (i = 0; i < N/2; i++)
    {
      if (dst[i] != A * src[i])
        abort ();
    }

  return 0;
}

/* { dg-final { scan-tree-dump-times "basic block vectorized using SLP" 1 "slp" { target vect64 } } } */
/* { dg-final { cleanup-tree-dump "slp" } } */

