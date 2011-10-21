/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (int *b, int *c)
{
  long long tmp = (long long)*b * *c;
  return 10 + tmp;
}

/* { dg-final { scan-assembler "smlal" } } */
