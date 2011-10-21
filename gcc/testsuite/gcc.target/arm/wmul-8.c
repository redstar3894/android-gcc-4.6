/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (long long a, int *b, int *c)
{
  return a + (long long)*b * *c;
}

/* { dg-final { scan-assembler "smlal" } } */
