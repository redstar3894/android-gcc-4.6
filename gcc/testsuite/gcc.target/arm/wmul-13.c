/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (int *a, int *b)
{
  return *a + (long long)*b * 10;
}

/* { dg-final { scan-assembler "smlal" } } */
