/* { dg-require-effective-target vect_condition } */

#include "tree-vect.h"

#define N 1024
int a[N], b[N], c[N];
char d[N], e[N], f[N];
unsigned char k[N];

__attribute__((noinline, noclone)) void
f1 (void)
{
  int i;
  for (i = 0; i < N; ++i)
    k[i] = a[i] < b[i] ? 17 : 0;
}

__attribute__((noinline, noclone)) void
f2 (void)
{
  int i;
  for (i = 0; i < N; ++i)
    k[i] = a[i] < b[i] ? 0 : 24;
}

__attribute__((noinline, noclone)) void
f3 (void)
{
  int i;
  for (i = 0; i < N; ++i)
    k[i] = a[i] < b[i] ? 51 : 12;
}

int
main ()
{
  int i;

  check_vect ();

  for (i = 0; i < N; i++)
    {
      switch (i % 9)
	{
	case 0: asm (""); a[i] = - i - 1; b[i] = i + 1; break;
	case 1: a[i] = 0; b[i] = 0; break;
	case 2: a[i] = i + 1; b[i] = - i - 1; break;
	case 3: a[i] = i; b[i] = i + 7; break;
	case 4: a[i] = i; b[i] = i; break;
	case 5: a[i] = i + 16; b[i] = i + 3; break;
	case 6: a[i] = - i - 5; b[i] = - i; break;
	case 7: a[i] = - i; b[i] = - i; break;
	case 8: a[i] = - i; b[i] = - i - 7; break;
	}
      d[i] = i;
      e[i] = 2 * i;
    }
  f1 ();
  for (i = 0; i < N; i++)
    if (k[i] != ((i % 3) == 0 ? 17 : 0))
      abort ();
  f2 ();
  for (i = 0; i < N; i++)
    if (k[i] != ((i % 3) == 0 ? 0 : 24))
      abort ();
  f3 ();
  for (i = 0; i < N; i++)
    if (k[i] != ((i % 3) == 0 ? 51 : 12))
      abort ();

  return 0;
}

/* { dg-final { scan-tree-dump-times "note: vectorized 1 loops" 3 "vect" } } */
/* { dg-final { cleanup-tree-dump "vect" } } */
